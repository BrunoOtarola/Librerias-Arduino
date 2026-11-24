/*
 * ============================================================================
 *  PROYECTO 1: Encender y Hacer Parpadear un LED (Blink)
 *  PLACA:      Arduino Uno
 *  NIVEL:      Principiante (Guía para estudiantes)
 * ============================================================================
 *
 *  CONEXIÓN EN LA PROTOBOARD:
 *  --------------------------
 *  - Pata larga del LED  (Ánodo / +)  --> Resistencia de 220Ω --> Pin Digital 8
 *  - Pata corta del LED  (Cátodo / -) --> Pin GND (Tierra) del Arduino
 *
 *  CONCEPTOS QUE APRENDERÁS:
 *  -------------------------
 *  1. pinMode()      : Configura un pin como entrada (INPUT) o salida (OUTPUT).
 *  2. digitalWrite() : Envía voltaje (HIGH = 5V) o lo apaga (LOW = 0V).
 *  3. delay()        : Pausa el programa durante un tiempo en milisegundos
 *                      (1000 ms = 1 segundo).
 * ============================================================================
 */

// 1. DEFINICIÓN DE PINES
// Usamos 'const int' para darle un nombre fácil de recordar al pin número 8.
const int PIN_LED = 8;

// 2. CONFIGURACIÓN INICIAL (Se ejecuta UNA SOLA VEZ al encender el Arduino)
void setup() {
  // Iniciamos el Monitor Serial para ver mensajes en la computadora (9600 baudios)
  Serial.begin(9600);
  Serial.println("=== Iniciando programa: Encender LED ===");

  // Configuramos el pin del LED como SALIDA porque el Arduino enviará energía
  pinMode(PIN_LED, OUTPUT);
}

// 3. BUCLE PRINCIPAL (Se repite INFINITAMENTE mientras el Arduino tenga energía)
void loop() {
  // Encendemos el LED (enviamos 5V al pin)
  digitalWrite(PIN_LED, HIGH);
  Serial.println("LED: ENCENDIDO");
  delay(1000); // Esperamos 1 segundo (1000 milisegundos)

  // Apagamos el LED (cortamos el voltaje a 0V)
  digitalWrite(PIN_LED, LOW);
  Serial.println("LED: APAGADO");
  delay(1000); // Esperamos 1 segundo antes de repetir el ciclo
}
