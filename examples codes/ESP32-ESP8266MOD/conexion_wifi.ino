/*
 * ============================================================================
 *  PROYECTO: Conexión a Red Wi-Fi (Compatible con ESP8266 y ESP32)
 *  PLACA:    NodeMCU (ESP8266MOD) o ESP32
 *  NIVEL:    Intermedio (Guía para estudiantes)
 * ============================================================================
 *
 *  IMPORTANTE ANTES DE SUBIR EL CÓDIGO:
 *  ------------------------------------
 *  1. Las placas ESP8266 y ESP32 trabajan principalmente con redes Wi-Fi de
 *     2.4 GHz (no se conectarán si tu red es exclusivamente de 5 GHz).
 *  2. Abre el Monitor Serial en Arduino IDE y selecciona la velocidad:
 *     --> 115200 baudios <--
 * ============================================================================
 */

// 1. IMPORTACIÓN AUTOMÁTICA DE LIBRERÍA SEGÚN LA PLACA SELECCIONADA
#if defined(ESP8266)
  #include <ESP8266WiFi.h> // Librería oficial para NodeMCU / ESP8266MOD
#elif defined(ESP32)
  #include <WiFi.h>        // Librería oficial para ESP32
#endif

// 2. CREDENCIALES DE TU RED WI-FI
// Reemplaza los textos entre comillas con los datos reales de tu Wi-Fi
const char* WIFI_SSID     = "NOMBRE_DE_TU_WIFI";
const char* WIFI_PASSWORD = "CLAVE_DE_TU_WIFI";

// 3. CONFIGURACIÓN INICIAL
void setup() {
  // En placas ESP usamos 115200 baudios para una comunicación rápida y clara
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println("==========================================");
  Serial.print("Conectando a la red Wi-Fi: ");
  Serial.println(WIFI_SSID);

  // Configuramos la placa en modo Estación (Cliente Wi-Fi)
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  // Esperamos hasta que el estado sea WL_CONNECTED (Conectado)
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // ¡Conexión exitosa! Mostramos los datos de red en el Monitor Serial
  Serial.println();
  Serial.println("¡Conexión Wi-Fi establecida con éxito!");
  Serial.print("Dirección IP asignada : ");
  Serial.println(WiFi.localIP());
  Serial.print("Intensidad de señal   : ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");
  Serial.println("==========================================");
}

// 4. BUCLE PRINCIPAL
void loop() {
  // Verificamos cada 10 segundos si la conexión sigue activa
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("[OK] Conectado a Wi-Fi | IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("[ALERTA] Se perdió la conexión Wi-Fi. Intentando reconectar...");
    WiFi.reconnect();
  }

  delay(10000); // Pausa de 10 segundos
}
