# Librerías y Soporte para Arduino / ESP8266

Repositorio que centraliza **librerías, drivers y archivos de apoyo** para proyectos con **Arduino Uno** y **NodeMCU (ESP8266)**. Todo listo para copiar y usar.

[![Descargar driver CH340](https://img.shields.io/badge/Descargar-Driver%20CH340%20(Arduino%20Uno)-blue?style=for-the-badge&logo=arduino)](https://github.com/BrunoOtarola/Librerias-Arduino/raw/main/drivers/CH340%20-%20WINDOWS%20-%20ARDUINO%20UNO.rar)
[![Drivers ESP8266MOD](https://img.shields.io/badge/Ver-Drivers%20ESP8266MOD%20(CP210x)-00979D?style=for-the-badge&logo=espressif)](drivers/ESP8266MOD_DRIVERS)

## Índice

1. [Contenido del repositorio](#contenido-del-repositorio)
2. [Drivers USB (CH340 y ESP8266MOD / CP210x)](#drivers-usb-ch340-y-esp8266mod--cp210x)
3. [Soporte de placa ESP8266 (NodeMCU)](#soporte-de-placa-esp8266-nodemcu)
4. [Instalación de librerías](#instalación-de-librerías)
5. [Carga de código](#carga-de-código)
6. [Solución de problemas](#solución-de-problemas)

## Contenido del repositorio

| Carpeta | Descripción |
| --- | --- |
| [`libraries/`](libraries) | Librerías de Arduino listas para copiar. |
| [`drivers/`](drivers) | Drivers USB para Arduino Uno (`CH340 - WINDOWS - ARDUINO UNO.rar`) y NodeMCU / ESP8266MOD (`ESP8266MOD_DRIVERS/`). |
| [`IDE/`](IDE) | Configuraciones para Arduino IDE (`link_adicional_tarjeta.txt` con la URL del gestor de tarjetas). |
| [`esp8266/`](esp8266) | Archivos auxiliares de ESP8266 (`board.json` y `link.txt`). |

### Librerías incluidas

| Categoría | Librerías |
| --- | --- |
| Pantallas | Adafruit_GFX_Library, Adafruit_SSD1306, Adafruit_SH1106-master, LiquidCrystal_I2C |
| Sensores | DHT22, DHT_sensor_library, Adafruit_BMP085_Unified, Adafruit_L3GD20_U, Adafruit_LSM303DLHC, Adafruit_Unified_Sensor, SparkFun_MAX3010x |
| RFID | MFRC522, Easy_MFRC522 |
| Comunicación / Nube | WiFi, Firebase, ArduinoJson |
| Otros | IRremote, Adafruit_BusIO, Adafruit_PCF8574 |

## Drivers USB (CH340 y ESP8266MOD / CP210x)

### 1. Driver CH340 (Arduino Uno)

Si tu placa (Arduino Uno compatible / clon) usa el chip **CH340**, instala este driver para Windows:

--> **[Descargar CH340 - WINDOWS - ARDUINO UNO.rar directamente](https://github.com/BrunoOtarola/Librerias-Arduino/raw/main/drivers/CH340%20-%20WINDOWS%20-%20ARDUINO%20UNO.rar)** <--

Pasos:

1. Descarga y descomprime `CH340 - WINDOWS - ARDUINO UNO.rar`.
2. Ejecuta el instalador.
3. Reconecta la placa y verifica que aparezca un puerto **COM** en Arduino IDE (**Herramientas > Puerto**).

### 2. Drivers ESP8266MOD / NodeMCU (CP210x)

En la carpeta [`drivers/ESP8266MOD_DRIVERS/`](drivers/ESP8266MOD_DRIVERS) se encuentran los drivers **CP210x (Silicon Labs)** necesarios para módulos **ESP8266MOD / NodeMCU**:

| Archivo | Sistema / Uso |
| --- | --- |
| [`CP210x_Universal_Windows_Driver.zip`](drivers/ESP8266MOD_DRIVERS/CP210x_Universal_Windows_Driver.zip) | Driver universal para Windows 10 / 11 (recomendado). |
| [`CP210x_Windows_Drivers.zip`](drivers/ESP8266MOD_DRIVERS/CP210x_Windows_Drivers.zip) | Driver estándar para Windows. |
| [`CP210x_VCP_Windows.zip`](drivers/ESP8266MOD_DRIVERS/CP210x_VCP_Windows.zip) | Driver Virtual COM Port (VCP) para Windows. |
| [`CP210x_Windows_Drivers_with_Serial_Enumeration.zip`](drivers/ESP8266MOD_DRIVERS/CP210x_Windows_Drivers_with_Serial_Enumeration.zip) | Driver para Windows con enumeración serial. |
| [`Mac_OSX_VCP_Driver.zip`](drivers/ESP8266MOD_DRIVERS/Mac_OSX_VCP_Driver.zip) | Driver VCP para macOS. |
| [`CP210x_VCP_Win2K.exe`](drivers/ESP8266MOD_DRIVERS/CP210x_VCP_Win2K.exe) / `VCP_WinCE*.zip` / `CP210x_5x_AppNote_Archive.zip` | Versiones legacy y documentación técnica. |

## Soporte de placa ESP8266 (NodeMCU)

1. Abre Arduino IDE.
2. Ve a **Archivo > Preferencias** (Windows) o **Arduino IDE > Settings** (macOS).
3. En **Gestor de URLs Adicionales de Tarjetas**, copia y pega el enlace incluido en [`IDE/link_adicional_tarjeta.txt`](IDE/link_adicional_tarjeta.txt) (también disponible en [`esp8266/link.txt`](esp8266/link.txt)):
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

Actualizado: 24-11-2026 - Bruno Otárola