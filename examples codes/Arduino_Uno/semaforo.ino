/*
 * ============================================================================
 *  PROYECTO 2: Semáforo Inteligente con 3 LEDs
 *  PLACA:      Arduino Uno
 *  NIVEL:      Principiante (Guía para estudiantes)
 * ============================================================================
 *
 *  CONEXIÓN EN LA PROTOBOARD:
 *  --------------------------
 *  - LED VERDE    (Ánodo +) --> Resistencia 220Ω --> Pin Digital 8
 *  - LED AMARILLO (Ánodo +) --> Resistencia 220Ω --> Pin Digital 9
 *  - LED ROJO     (Ánodo +) --> Resistencia 220Ω --> Pin Digital 10
 *  - Todos los Cátodos (-) de los LEDs van conectados a GND (Tierra).
 *
 *  SECUENCIA DEL SEMÁFORO:
 *  -----------------------
 *  1. VERDE encendido    (4 segundos) -> Los autos avanzan.
 *  2. AMARILLO parpadea  (2 segundos) -> Precaución, va a cambiar a rojo.
 *  3. ROJO encendido     (4 segundos) -> Los autos se detienen.
 * ============================================================================
 */

// 1. DEFINICIÓN DE PINES Y TIEMPOS
const int LED_VERDE    = 8;
const int LED_AMARILLO = 9;
const int LED_ROJO     = 10;

const int TIEMPO_VERDE = 4000; // 4000 ms = 4 segundos
const int TIEMPO_ROJO  = 4000; // 4000 ms = 4 segundos

// 2. CONFIGURACIÓN INICIAL (Se ejecuta una sola vez)
void setup() {
  Serial.begin(9600);
  Serial.println("=== Semáforo Arduino Uno Iniciado ===");

  // Configuramos los 3 pines como SALIDAS (OUTPUT)
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);

  // Nos aseguramos de que todos los LEDs comiencen apagados
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_ROJO, LOW);
}

// 3. BUCLE PRINCIPAL (Se repite continuamente)
void loop() {
  // --- FASE 1: LUZ VERDE (AVANZAR) ---
  Serial.println("[VERDE]    Avanzar");
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_ROJO, LOW);
  delay(TIEMPO_VERDE);

  // --- FASE 2: LUZ AMARILLA (PRECAUCIÓN CON PARPADEO) ---
  Serial.println("[AMARILLO] Precaución");
  digitalWrite(LED_VERDE, LOW);

  // Hacemos parpadear el LED amarillo 3 veces antes de pasar a rojo
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_AMARILLO, HIGH);
    delay(400);
    digitalWrite(LED_AMARILLO, LOW);
    delay(400);
  }

  // --- FASE 3: LUZ ROJA (DETENERSE) ---
  Serial.println("[ROJO]     Detenerse");
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARILLO, LOW);
  digitalWrite(LED_ROJO, HIGH);
  delay(TIEMPO_ROJO);
}
