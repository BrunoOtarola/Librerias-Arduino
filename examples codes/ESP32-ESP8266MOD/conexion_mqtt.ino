/*
 * ============================================================================
 *  PROYECTO: Conexión MQTT (Publicar datos y recibir comandos en tiempo real)
 *  PLACA:    NodeMCU (ESP8266MOD) o ESP32
 *  NIVEL:    Intermedio / IoT (Guía para estudiantes)
 * ============================================================================
 *
 *  ¿QUÉ ES MQTT?
 *  -------------
 *  MQTT es un protocolo de mensajería ligero ideal para Internet de las Cosas
 *  (IoT). Funciona mediante un servidor central llamado "Broker" y canales de
 *  comunicación llamados "Tópicos" (Topics):
 *    - PUBLICAR (Publish)   : Tu ESP envía información (ej. un sensor).
 *    - SUSCRIBIR (Subscribe): Tu ESP escucha órdenes (ej. encender un LED).
 *
 *  REQUISITO DE LIBRERÍA:
 *  ----------------------
 *  Instala "PubSubClient" (de Nick O'Leary) desde el Gestor de Librerías de
 *  Arduino IDE (Programa > Incluir Librería > Administrar Bibliotecas).
 * ============================================================================
 */

// 1. LIBRERÍAS WI-FI Y MQTT
#if defined(ESP8266)
  #include <ESP8266WiFi.h>
#elif defined(ESP32)
  #include <WiFi.h>
#endif
#include <PubSubClient.h>

// 2. CONFIGURACIÓN WI-FI (Cambia por los datos de tu red)
const char* WIFI_SSID     = "NOMBRE_DE_TU_WIFI";
const char* WIFI_PASSWORD = "CLAVE_DE_TU_WIFI";

// 3. CONFIGURACIÓN DEL BROKER MQTT
// Usamos un broker público gratuito de prueba (puedes usar HiveMQ, EMQX o Mosquitto)
const char* MQTT_BROKER   = "broker.hivemq.com";
const int   MQTT_PORT     = 1883;

// Tópicos (Canales de comunicación). ¡Cámbialos por tu nombre para no cruzarte con otros!
const char* TOPICO_PUBLICAR  = "clase/estudiante1/estado";
const char* TOPICO_SUSCRIBIR = "clase/estudiante1/led";

// 4. OBJETOS DE CONEXIÓN Y VARIABLES
WiFiClient espClient;
PubSubClient mqttClient(espClient);

// Usamos el LED integrado en la placa para probar comandos ("ON" / "OFF")
#ifndef LED_BUILTIN
  #define LED_BUILTIN 2
#endif

unsigned long ultimoEnvio = 0;
const unsigned long INTERVALO_ENVIO = 5000; // Enviar mensaje cada 5 segundos
int contadorMensajes = 0;

// ============================================================================
// FUNCIÓN 1: Conectar a la red Wi-Fi
// ============================================================================
void conectarWiFi() {
  Serial.println();
  Serial.print("Conectando a Wi-Fi: ");
  Serial.println(WIFI_SSID);

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n¡Wi-Fi conectado!");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());
}

// ============================================================================
// FUNCIÓN 2: Callback (Se ejecuta automáticamente cuando llega un mensaje MQTT)
// ============================================================================
void alRecibirMensajeMQTT(char* topic, byte* payload, unsigned int length) {
  // Convertimos los bytes recibidos en un texto (String) fácil de usar
  String mensaje = "";
  for (unsigned int i = 0; i < length; i++) {
    mensaje += (char)payload[i];
  }

  Serial.print("\n[MQTT RECIBIDO] Tópico: ");
  Serial.print(topic);
  Serial.print(" | Mensaje: ");
  Serial.println(mensaje);

  // Si recibimos "ON", encendemos el LED; si recibimos "OFF", lo apagamos
  if (mensaje == "ON") {
    digitalWrite(LED_BUILTIN, LOW);  // En NodeMCU el LED integrado enciende con LOW
    Serial.println("--> Acción: LED ENCENDIDO");
  } else if (mensaje == "OFF") {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("--> Acción: LED APAGADO");
  }
}

// ============================================================================
// FUNCIÓN 3: Reconectar al Broker MQTT si se pierde la conexión
// ============================================================================
void reconectarMQTT() {
  while (!mqttClient.connected()) {
    Serial.print("Conectando al Broker MQTT (");
    Serial.print(MQTT_BROKER);
    Serial.print(")... ");

    // Generamos un ID único para que el broker no rechace nuestra placa
    String clientId = "ESP-Estudiante-" + String(random(0xffff), HEX);

    if (mqttClient.connect(clientId.c_str())) {
      Serial.println("¡Conectado al Broker!");

      // Nos suscribimos al tópico para escuchar órdenes
      mqttClient.subscribe(TOPICO_SUSCRIBIR);
      Serial.print("Suscrito al tópico: ");
      Serial.println(TOPICO_SUSCRIBIR);
    } else {
      Serial.print("Fallo (código ");
      Serial.print(mqttClient.state());
      Serial.println("). Reintentando en 5 segundos...");
      delay(5000);
    }
  }
}

// ============================================================================
// CONFIGURACIÓN INICIAL (setup)
// ============================================================================
void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); // Inicia apagado

  conectarWiFi();

  // Configuramos el servidor MQTT y la función que procesará los mensajes entrantes
  mqttClient.setServer(MQTT_BROKER, MQTT_PORT);
  mqttClient.setCallback(alRecibirMensajeMQTT);
}

// ============================================================================
// BUCLE PRINCIPAL (loop)
// ============================================================================
void loop() {
  // 1. Verificamos que la conexión MQTT siga activa
  if (!mqttClient.connected()) {
    reconectarMQTT();
  }
  // Procesa mensajes entrantes y mantiene viva la sesión con el Broker
  mqttClient.loop();

  // 2. Publicamos un mensaje cada 5 segundos sin bloquear el programa (usando millis)
  unsigned long ahora = millis();
  if (ahora - ultimoEnvio >= INTERVALO_ENVIO) {
    ultimoEnvio = ahora;
    contadorMensajes++;

    String datos = "Hola desde ESP! Mensaje #" + String(contadorMensajes);
    mqttClient.publish(TOPICO_PUBLICAR, datos.c_str());

    Serial.print("[MQTT ENVIADO] Tópico: ");
    Serial.print(TOPICO_PUBLICAR);
    Serial.print(" | Datos: ");
    Serial.println(datos);
  }
}
