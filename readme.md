# Librerías y Soporte para Arduino / ESP8266

Repositorio que centraliza **librerías, drivers y archivos de apoyo** para proyectos con **Arduino Uno** y **NodeMCU (ESP8266)**. Todo listo para copiar y usar.

[![Descargar Arduino IDE](https://img.shields.io/badge/Descargar-Arduino%20IDE-00878F?style=for-the-badge&logo=arduino)](https://www.arduino.cc/en/software/)
[![Descargar driver CH340](https://img.shields.io/badge/Descargar-Driver%20CH340%20(Arduino%20Uno)-blue?style=for-the-badge&logo=arduino)](https://github.com/BrunoOtarola/Librerias-Arduino/raw/main/drivers/CH340%20-%20WINDOWS%20-%20ARDUINO%20UNO.rar)
[![Drivers CP210x](https://img.shields.io/badge/Ver-Drivers%20ESP%20(CP210x)-00979D?style=for-the-badge&logo=espressif)](drivers/ESP%20-%20CP210x%20USB%20to%20UART%20Bridge%20VCP%20Drivers)

## Índice

1. [Contenido del repositorio](#contenido-del-repositorio)
2. [Drivers USB (CH340 y ESP / CP210x)](#drivers-usb-ch340-y-esp--cp210x)
3. [Soporte de placa ESP8266 (NodeMCU)](#soporte-de-placa-esp8266-nodemcu)
4. [Instalación de librerías](#instalación-de-librerías)
5. [Códigos de ejemplo (para estudiantes)](#códigos-de-ejemplo-para-estudiantes)
6. [Carga de código](#carga-de-código)
7. [Solución de problemas](#solución-de-problemas)

## Contenido del repositorio

| Carpeta | Descripción |
| --- | --- |
| [`libraries/`](libraries) | Librerías de Arduino listas para copiar. |
| [`drivers/`](drivers) | Driver CH340 para Arduino Uno (`CH340 - WINDOWS - ARDUINO UNO.rar`), drivers VCP CP210x (`ESP - CP210x USB to UART Bridge VCP Drivers/`) y archivos auxiliares de placa (`ESP8266MOD/`). |
| [`IDE/`](IDE) | Enlace oficial de descarga de Arduino IDE (`descargar_ide.txt`) y URL para el gestor de tarjetas (`link_adicional_tarjeta.txt`). |
| [`examples codes/`](examples%20codes) | Códigos de ejemplo comentados paso a paso para estudiantes (`Arduino_Uno/` y `ESP32-ESP8266MOD/`). |

### Librerías incluidas

| Categoría | Librerías |
| --- | --- |
| Pantallas | Adafruit_GFX_Library, Adafruit_SSD1306, Adafruit_SH1106-master, LiquidCrystal_I2C |
| Sensores | DHT22, DHT_sensor_library, Adafruit_BMP085_Unified, Adafruit_L3GD20_U, Adafruit_LSM303DLHC, Adafruit_Unified_Sensor, SparkFun_MAX3010x |
| RFID | MFRC522, Easy_MFRC522 |
| Comunicación / Nube | WiFi, Firebase, ArduinoJson |
| Otros | IRremote, Adafruit_BusIO, Adafruit_PCF8574 |

## Drivers USB (CH340 y ESP / CP210x)

### 1. Driver CH340 (Arduino Uno)

Si tu placa (Arduino Uno compatible / clon) usa el chip **CH340**, instala este driver para Windows:

--> **[Descargar CH340 - WINDOWS - ARDUINO UNO.rar directamente](https://github.com/BrunoOtarola/Librerias-Arduino/raw/main/drivers/CH340%20-%20WINDOWS%20-%20ARDUINO%20UNO.rar)** <--

Pasos:

1. Descarga y descomprime `CH340 - WINDOWS - ARDUINO UNO.rar`.
2. Ejecuta el instalador.
3. Reconecta la placa y verifica que aparezca un puerto **COM** en Arduino IDE (**Herramientas > Puerto**).

### 2. Drivers ESP - CP210x USB to UART Bridge VCP

En la carpeta [`drivers/ESP - CP210x USB to UART Bridge VCP Drivers/`](drivers/ESP%20-%20CP210x%20USB%20to%20UART%20Bridge%20VCP%20Drivers) se encuentran los drivers **CP210x (Silicon Labs)** necesarios para módulos **ESP8266MOD / NodeMCU**:

| Archivo | Sistema / Uso |
| --- | --- |
| [`CP210x_Universal_Windows_Driver.zip`](drivers/ESP%20-%20CP210x%20USB%20to%20UART%20Bridge%20VCP%20Drivers/CP210x_Universal_Windows_Driver.zip) | Driver universal para Windows 10 / 11 (recomendado). |
| [`CP210x_Windows_Drivers.zip`](drivers/ESP%20-%20CP210x%20USB%20to%20UART%20Bridge%20VCP%20Drivers/CP210x_Windows_Drivers.zip) | Driver estándar para Windows. |
| [`CP210x_VCP_Windows.zip`](drivers/ESP%20-%20CP210x%20USB%20to%20UART%20Bridge%20VCP%20Drivers/CP210x_VCP_Windows.zip) | Driver Virtual COM Port (VCP) para Windows. |
| [`CP210x_Windows_Drivers_with_Serial_Enumeration.zip`](drivers/ESP%20-%20CP210x%20USB%20to%20UART%20Bridge%20VCP%20Drivers/CP210x_Windows_Drivers_with_Serial_Enumeration.zip) | Driver para Windows con enumeración serial. |
| [`Mac_OSX_VCP_Driver.zip`](drivers/ESP%20-%20CP210x%20USB%20to%20UART%20Bridge%20VCP%20Drivers/Mac_OSX_VCP_Driver.zip) | Driver VCP para macOS. |
| [`CP210x_VCP_Win2K.exe`](drivers/ESP%20-%20CP210x%20USB%20to%20UART%20Bridge%20VCP%20Drivers/CP210x_VCP_Win2K.exe) / `VCP_WinCE*.zip` / `CP210x_5x_AppNote_Archive.zip` | Versiones legacy y documentación técnica. |

## Soporte de placa ESP8266 (NodeMCU)

1. Abre Arduino IDE (si no lo tienes, puedes descargarlo desde el enlace en [`IDE/descargar_ide.txt`](IDE/descargar_ide.txt): https://www.arduino.cc/en/software/).
2. Ve a **Archivo > Preferencias** (Windows) o **Arduino IDE > Settings** (macOS).
3. En **Gestor de URLs Adicionales de Tarjetas**, copia y pega el enlace incluido en [`IDE/link_adicional_tarjeta.txt`](IDE/link_adicional_tarjeta.txt) o [`drivers/ESP8266MOD/link.txt`](drivers/ESP8266MOD/link.txt):
   ```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```
4. Ve a **Herramientas > Placa > Gestor de Tarjetas**.
5. Busca `esp8266` e instala el paquete de la comunidad ESP8266 (definición auxiliar en [`drivers/ESP8266MOD/board.json`](drivers/ESP8266MOD/board.json)).

## Instalación de librerías

Copia las carpetas dentro de `libraries/` a tu carpeta local de librerías de Arduino.

| Sistema | Ruta de destino |
| --- | --- |
| Windows | `Documentos\Arduino\libraries` |
| macOS | `~/Documents/Arduino/libraries` |

Luego reinicia Arduino IDE.

## Códigos de ejemplo (para estudiantes)

En la carpeta [`examples codes/`](examples%20codes) encontrarás códigos `.ino` limpios y documentados paso a paso para aprender a programar cada placa:

### 1. Arduino Uno ([`examples codes/Arduino_Uno/`](examples%20codes/Arduino_Uno))

| Archivo | Nivel | Qué aprenderás |
| --- | --- | --- |
| [`encender_leds.ino`](examples%20codes/Arduino_Uno/encender_leds.ino) | Principiante | Cómo conectar un LED con resistencia en la protoboard y usar `pinMode()`, `digitalWrite()` y `delay()`. |
| [`semaforo.ino`](examples%20codes/Arduino_Uno/semaforo.ino) | Principiante | Secuencia de semáforo (Verde, Amarillo parpadeante con ciclo `for` y Rojo) controlando múltiples salidas digitales. |

### 2. ESP32 y NodeMCU / ESP8266MOD ([`examples codes/ESP32-ESP8266MOD/`](examples%20codes/ESP32-ESP8266MOD))

Ambos ejemplos detectan automáticamente si estás compilando para **ESP8266** o **ESP32** (`#if defined(ESP8266)` / `#elif defined(ESP32)`):

| Archivo | Nivel | Qué aprenderás |
| --- | --- | --- |
| [`conexion_wifi.ino`](examples%20codes/ESP32-ESP8266MOD/conexion_wifi.ino) | Intermedio | Conectarse a una red Wi-Fi (2.4 GHz), verificar el estado de la red, obtener la dirección IP local y medir la señal (`RSSI`). |
| [`conexion_mqtt.ino`](examples%20codes/ESP32-ESP8266MOD/conexion_mqtt.ino) | Intermedio / IoT | Conectarse a un **Broker MQTT** con `PubSubClient`, **publicar** mensajes periódicamente sin bloquear (`millis()`) y **suscribirse** a un tópico para encender/apagar un LED en tiempo real (`ON` / `OFF`). |

## Carga de código

| Placa | Selección en el IDE | Recomendación |
| --- | --- | --- |
| **Arduino Uno** | Arduino Uno | Desconecta módulos de los pines **0 (RX)** y **1 (TX)** antes de subir. |
| **NodeMCU** | NodeMCU 1.0 (ESP-12E Module) | Evita conexiones en RX/TX durante la subida para prevenir errores. |

## Solución de problemas

- **No aparece el puerto serial:** revisa el cable USB (que sea de datos), el driver y el puerto seleccionado.
- **Una librería no se reconoce:** reinicia Arduino IDE después de copiarla.
- **Error al subir el código:** desconecta RX/TX y verifica la placa seleccionada.

---

Actualizado: 24-11-2026 - Bruno Otárola