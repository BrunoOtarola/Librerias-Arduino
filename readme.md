# Librerías y Soporte para Arduino / ESP8266

Este repositorio centraliza librerías y archivos de apoyo para proyectos con **Arduino Uno** y **NodeMCU (ESP8266)**.

## Contenido del repositorio

- `libraries/`: librerías de Arduino listas para copiar.
- `drivers/`: drivers USB para placas compatibles (incluye CH340).
- `esp8266/`: archivos auxiliares relacionados con ESP8266 (`board.json` y `link.txt`).

## 1) Instalación de soporte de placa ESP8266 (NodeMCU)

1. Abre Arduino IDE.
2. Ve a **Archivo > Preferencias** (Windows) o **Arduino IDE > Settings** (macOS).
3. En **Gestor de URLs Adicionales de Tarjetas**, agrega:
   `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
4. Ve a **Herramientas > Placa > Gestor de Tarjetas**.
5. Busca `esp8266` e instala el paquete de la comunidad ESP8266.

## 2) Instalación de driver CH340 (Arduino Uno compatible/chino)

Si tu placa usa chip **CH340**, instala el driver incluido en:

- `drivers/CH340.rar`

Pasos sugeridos:

1. Descomprime `CH340.rar`.
2. Ejecuta el instalador correspondiente a tu sistema operativo.
3. Reconecta la placa y verifica que aparezca un puerto COM en Arduino IDE.

## 3) Instalación de librerías

Para que los proyectos compilen, copia las carpetas dentro de `libraries/` a tu carpeta local de librerías de Arduino.

### Windows

1. Copia el contenido de `libraries/` de este repositorio.
2. Pégalo en: `Documentos\Arduino\libraries`

### macOS

1. Copia el contenido de `libraries/` de este repositorio.
2. Pégalo en: `~/Documents/Arduino/libraries`

## 4) Carga de código (recomendaciones)

1. **Arduino Uno**:
   - Selecciona la placa **Arduino Uno**.
   - Antes de subir, revisa los pines **0 (RX)** y **1 (TX)**: evita tener módulos conectados a esos pines durante la carga.
2. **NodeMCU (ESP12-E Module)**:
   - Selecciona la placa **NodeMCU 1.0 (ESP-12E Module)**.
   - Evita conexiones en RX/TX durante la subida para prevenir errores de carga.

## Notas

- Si no aparece el puerto serial, revisa cable USB, driver y puerto seleccionado.
- Si una librería no se reconoce, reinicia Arduino IDE después de copiarla.

Actualizado: 13-05-2026 - Bruno Otárola