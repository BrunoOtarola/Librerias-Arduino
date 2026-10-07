# Librerías y Soporte para Arduino / ESP8266

Repositorio que centraliza **librerías, drivers y archivos de apoyo** para proyectos con **Arduino Uno** y **NodeMCU (ESP8266)**. Todo listo para copiar y usar.

[![Descargar driver CH340](https://img.shields.io/badge/Descargar-Driver%20CH340-blue?style=for-the-badge&logo=arduino)](https://github.com/BrunoOtarola/Librerias-Arduino/raw/main/drivers/CH340.rar)

## Índice

1. [Contenido del repositorio](#-contenido-del-repositorio)
2. [Driver CH340](#-driver-ch340)
3. [Soporte de placa ESP8266 (NodeMCU)](#-soporte-de-placa-esp8266-nodemcu)
4. [Instalación de librerías](#-instalación-de-librerías)
5. [Carga de código](#-carga-de-código)
6. [Solución de problemas](#-solución-de-problemas)

## Contenido del repositorio

| Carpeta | Descripción |
| --- | --- |
| [`libraries/`](libraries) | Librerías de Arduino listas para copiar. |
| [`drivers/`](drivers) | Drivers USB para placas compatibles (CH340). |
| [`esp8266/`](esp8266) | Archivos auxiliares de ESP8266 (`board.json` y `link.txt`). |

### Librerías incluidas

| Categoría | Librerías |
| --- | --- |
| Pantallas | Adafruit_GFX_Library, Adafruit_SSD1306, Adafruit_SH1106-master, LiquidCrystal_I2C |
| Sensores | DHT22, DHT_sensor_library, Adafruit_BMP085_Unified, Adafruit_L3GD20_U, Adafruit_LSM303DLHC, Adafruit_Unified_Sensor, SparkFun_MAX3010x |
| RFID | MFRC522, Easy_MFRC522 |
| Comunicación / Nube | WiFi, Firebase, ArduinoJson |
| Otros | IRremote, Adafruit_BusIO, Adafruit_PCF8574 |

## Driver CH340

Si tu placa (Arduino Uno compatible / clon) usa el chip **CH340**, necesitas instalar su driver.

--> **[Descargar CH340.rar directamente](https://github.com/BrunoOtarola/Librerias-Arduino/raw/main/drivers/CH340.rar)** <--

Pasos:

1. Descarga y descomprime `CH340.rar`.
2. Ejecuta el instalador correspondiente a tu sistema operativo.
3. Reconecta la placa y verifica que aparezca un puerto **COM** en Arduino IDE (**Herramientas > Puerto**).

## Soporte de placa ESP8266 (NodeMCU)

1. Abre Arduino IDE.
2. Ve a **Archivo > Preferencias** (Windows) o **Arduino IDE > Settings** (macOS).
3. En **Gestor de URLs Adicionales de Tarjetas**, agrega:
   ```
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
   ```
4. Ve a **Herramientas > Placa > Gestor de Tarjetas**.
5. Busca `esp8266` e instala el paquete de la comunidad ESP8266.

## Instalación de librerías

Copia las carpetas dentro de `libraries/` a tu carpeta local de librerías de Arduino.

| Sistema | Ruta de destino |
| --- | --- |
| Windows | `Documentos\Arduino\libraries` |
| macOS | `~/Documents/Arduino/libraries` |

Luego reinicia Arduino IDE.

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

Actualizado: 13-05-2026 - Bruno Otárola