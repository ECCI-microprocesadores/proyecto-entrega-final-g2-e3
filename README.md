[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=19631495&assignment_repo_type=AssignmentRepo)
# Proyecto final

## Integrantes
[Juan David Rojas Diaz](https://github.com/JuanRojas15)

[Carlos Andres Rojas Diaz](https://github.com/CarlosRojas05)

## Nombre del proyecto: Sistema de Detección de Sobrecalentamiento con Indicadores LED y Relevador


## Documentación
### LM35 – El sensor de temperatura más popular
El LM35 es un circuito electrónico sensor que puede medir temperatura. Su salida es analógica, es decir, te proporciona un voltaje proporcional a la temperatura. El sensor tiene un rango desde −55°C a 150°C. Su popularidad se debe a la facilidad con la que se puede medir la temperatura. Incluso no es necesario de un microprocesador o microcontrolador para medir la temperatura. Dado que el sensor LM35 es analógico, basta con medir con un multímetro, el voltaje a salida del sensor.

Para convertir el voltaje a la temperatura, el LM35 proporciona 10mV por cada grado centígrado. También cabe señalar que ese sensor se puede usar sin offset, es decir que si medimos 20mV a la salida, estaremos midiendo 2°C.

<p align="center"><strong>Figura 1.</strong> LM35.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/f0317be9-2a2e-426e-8cdd-4d2c20e9d706" alt="Mi imagen">
</p>
<p align="center">
(Fuente: E-Marmolejo, R. (2018, enero 17). LM35 - El sensor de temperatura más popular. HeTPro-Tutoriales. https://hetpro-store.com/TUTORIALES/lm35/?srsltid=AfmBOooKGkOOA8b8sjG9Gf04AgnLDLdNxe5k9gBwqz73UlEODDEc3D3J#google_vignette)
</p>

### LM35 y sus características principales
* Resolución: 10mV por cada grado centígrado.
* Voltaje de alimentación. Por ejemplo, este sensor se puede alimentar desde 4Vdc hasta 20Vdc.
* Tipo de medición: Salida analógica.
* Número de pines: 3 pines, GND, VCC y VSalida.
* No requiere calibración.
* Tiene una precisión de ±¼°C.
* Está calibrado para medir °C.
* Consumo de corriente: 60 μA
* Empaquetados comunes:
  - TO-CAN.
  - TO-220.
  - TO-92.
  - SOIC8.
### Los pines del sensor LM35
El pinout del sensor de temperatura son tres: GND, VCC y VSalida. Entonces dependiendo del empaquetado será el orden de conexión de los pines. Por ejemplo, el empaquetado TO-220 tiene la siguiente distribución:

<p align="center"><strong>Figura 2.</strong> Conexiones LM35.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/d4f0ed55-b48c-4c6e-956c-362e6e0444a6" alt="Mi imagen">
</p>
<p align="center">
(Fuente: E-Marmolejo, R. (2018, enero 17). LM35 - El sensor de temperatura más popular. HeTPro-Tutoriales. https://hetpro-store.com/TUTORIALES/lm35/?srsltid=AfmBOooKGkOOA8b8sjG9Gf04AgnLDLdNxe5k9gBwqz73UlEODDEc3D3J#google_vignette)
</p>

<p align="center"><strong>Figura 3.</strong> Conexiones LM35.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/056182f0-5c37-4ee8-a474-ec88072505e2" alt="Mi imagen">
</p>
<p align="center">
(Fuente: E-Marmolejo, R. (2018, enero 17). LM35 - El sensor de temperatura más popular. HeTPro-Tutoriales. https://hetpro-store.com/TUTORIALES/lm35/?srsltid=AfmBOooKGkOOA8b8sjG9Gf04AgnLDLdNxe5k9gBwqz73UlEODDEc3D3J#google_vignette)
</p>

La simples del circuito hace que sea muy fácil ser utilizado en alguna aplicación embebida. Entonces sólo basta alimentarlo con digamos 5VDC, conectar la tierra GND a la tierra del circuito digital y la salida de voltaje a la entrada del ADC.

<p align="center"><strong>Figura 4.</strong> Conexion LM35 con un PIC.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/2b7f98f9-079b-4426-a085-611d30e2e231" alt="Mi imagen">
</p>
<p align="center">
(Fuente: E-Marmolejo, R. (2018, enero 17). LM35 - El sensor de temperatura más popular. HeTPro-Tutoriales. https://hetpro-store.com/TUTORIALES/lm35/?srsltid=AfmBOooKGkOOA8b8sjG9Gf04AgnLDLdNxe5k9gBwqz73UlEODDEc3D3J#google_vignette)
</p>

### ¿Qué es el Protocolo I2C y por Qué Usarlo con un PIC?
El protocolo I2C (Inter-Integrated Circuit) es una tecnología de comunicación serie que permite conectar múltiples dispositivos a un microcontrolador usando solo dos líneas: SDA (Serial Data Line) y SCL (Serial Clock Line). En lugar de ocupar varios pines para conectar periféricos, como es el caso de un LCD sin I2C, este protocolo te permite manejar múltiples dispositivos con solo dos hilos de comunicación, lo que es extremadamente útil cuando trabajas con microcontroladores como el PIC18F45K22.

### Funcionamiento Básico del I2C:
En un bus I2C, siempre hay un dispositivo maestro (en este caso, tu microcontrolador PIC) y uno o más dispositivos esclavos (como un LCD, un sensor de temperatura, etc.). El maestro controla el bus, enviando una señal de reloj a través de la línea SCL y transmitiendo datos a través de la línea SDA. Cada dispositivo esclavo tiene una dirección única en el bus, lo que permite al maestro comunicarse específicamente con el dispositivo deseado.

Por ejemplo, al utilizar un LCD 16×2 I2C con un PIC, el microcontrolador envía la dirección del LCD seguida de comandos específicos para mostrar caracteres en la pantalla. Este proceso es similar sin importar si estás trabajando con un PIC, un Arduino, o incluso una Raspberry Pi.

Ventajas de Usar I2C en Proyectos con PIC:

* **Ahorro de Pines:** Usar I2C reduce el número de pines necesarios en el microcontrolador. Esto es crucial en proyectos donde el espacio es limitado o cuando necesitas conectar muchos dispositivos.
* **Simplicidad en el Cableado:** Al utilizar solo dos líneas para la comunicación, el cableado se simplifica considerablemente, reduciendo la posibilidad de errores.
* **Facilidad para Escalar:** Puedes conectar múltiples dispositivos I2C al mismo bus sin complicaciones adicionales, permitiendo la expansión fácil de tus proyectos.
### Interfaz LCD I2C PIC

<p align="center"><strong>Figura 5.</strong> Conexiones.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/5ed64783-6975-4196-84ce-29ed9dd4a508" alt="Mi imagen">
</p>
<p align="center">
(Fuente: Giraldo, S. A. C. (2024, 14 agosto). LCD I2C PIC. Control Automático Educación. https://controlautomaticoeducacion.com/sistemas-embebidos/microcontroladores-pic/lcd-i2c-pic/#google_vignette)
</p>

Para evitar ocupar múltiples pines del microcontrolador PIC, podemos utilizar dispositivos como el PCF8574T, un expansor de entradas y salidas digitales que se conecta mediante el protocolo I2C. Este módulo permite manejar un LCD usando solo dos pines del microcontrolador, SDA y SCL, simplificando enormemente el diseño de tu circuito.

<p align="center"><strong>Figura 6.</strong> Placa I2C adaptadora LCD1602 – PCF8574.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/9eb6c34c-10b0-4212-8b6c-055fbf300579" alt="Mi imagen">
</p>
<p align="center">
(Fuente: Giraldo, S. A. C. (2024, 14 agosto). LCD I2C PIC. Control Automático Educación. https://controlautomaticoeducacion.com/sistemas-embebidos/microcontroladores-pic/lcd-i2c-pic/#google_vignette)
</p>

# Entrega Final del Proyecto

### IDEA DEL PROYECTO

La idea principal del proyecto es diseñar un **sistema de monitoreo y alerta de temperatura** que permita:

- Visualizar el valor de la temperatura en un display LCD conectado por I2C.  
- Encender secuencialmente varios LEDs para indicar el incremento de temperatura.  
- Al alcanzar un umbral crítico, **activar un ventilador** para refrigerar el sistema.  

De esta manera, el usuario cuenta con:  
1. **Indicaciones visuales**: LCD e indicadores LED.  
2. **Acción correctiva**: ventilador de enfriamiento automático.



### Introducción

Tras validar la lectura del sensor LM35 y su despliegue en un módulo LCD 16×2, culminamos el proyecto con una versión optimizada que:

- Utiliza un adaptador I2C (PCF8574 o similar) para controlar el LCD con solo dos líneas (SDA/SCL), liberando pines GPIO.  
- Enciende LEDs de colores según rangos térmicos definidos.  
- Activa automáticamente un ventilador cuando la temperatura supera el umbral crítico.  

Este diseño compacto y eficiente mejora la escalabilidad y el uso de recursos del microcontrolador.



### Objetivos

1. **Monitoreo en LCD vía I2C**  
   - Configurar el bus I2C en el PIC y adaptar las rutinas para comunicación con el expansor de pines.  
   - Mostrar “Temp: XX.X°C”.

2. **Indicadores LED secuenciales**  
   - LED verde: temperatura < 20 °C.  
   - LED amarillo: 20 °C ≤ temperatura < 30 °C.  
   - LED rojo: 30 °C ≤ temperatura < 40 °C.  
   - LED rojo: temperatura > 50 °C.

3. **Control del ventilador**  
   - Conmutar un relé de 5 V para alimentar el ventilador al superar el umbral crítico.  
   - Mantenerlo activo hasta que la temperatura baje por debajo del nivel de histéresis.

4. **Optimización de recursos**  
   - Reducir conexiones directas al PIC usando I2C para el LCD.  
   - Simplificar el cableado y maximizar pines disponibles para futuras ampliaciones.



### Elementos

- **Microcontrolador PIC18F45K22**  
- **Sensor de temperatura LM35**  
- **Display LCD 16×2** con adaptador I2C (PCF8574 o similar)  
- **LEDs de cuatro colores** (verde, amarillo, rojo, umbral > 50 °C)  
- **Resistencias limitadoras de corriente** para LEDs  
- **Ventilador de 5 V** y **relé de 5 V**  
- **Cables, protoboard o PCB**  
- **Fuente regulada de 5 V**  
- **Archivos de código**:  
  - `i2c.c` / `i2c.h`  
  - `i2c_lcd.c` / `i2c_lcd.h`  
  - `adc.c` / `adc.h`  

### Descripción del Código Principal

1. **Configuración de fuses**

- Se establece el oscilador interno a 48 MHz y se deshabilita el PLL.  
- Se habilita el reloj primario, se desactiva el Watchdog y el Power-up Timer.  
- Se configura el pin MCLR como entrada externa de reset y PORTB<4:0> como digital.

2. **Inicialización de módulos**

- **ADC**: se habilita AN0 como entrada analógica y se configura para lecturas de 10 bits.  
- **I²C**: se inicializa el módulo maestro a la frecuencia adecuada para la comunicación con el expansor del LCD.  
- **LCD I²C**: se envía la secuencia de inicialización, se limpia la pantalla con `lcd_clear()` al inicio y se posiciona el cursor.

3. **Mensajes en LCD**

En la **primera línea** se muestra el prefijo:  
- Posición (0,0): `"Estado: "`  

En la **segunda línea** (columna 2) se muestra la lectura:  
- `"Temp: XX.XC"`  

Después, en la **misma primera línea** (columna 7) se escribe un mensaje de **8 caracteres** para indicar el estado de temperatura, evitando que queden caracteres sobrantes:  
- `“Frio    ”` para temperatura < 30 °C.  
- `“Normal  ”` para 30 °C ≤ temperatura < 40 °C.  
- `“Caliente”` para 40 °C ≤ temperatura < 48 °C.  
- `“Peligro!”` para temperatura ≥ 48 °C.

4. **Configuración de LEDs**

Se deshabilita la función analógica en RB0–RB3 y se configuran como salidas digitales.  
Al inicio se apagan todos los LEDs.

5. **Bucle de medición y control**

- **Lectura ADC**: se lee AN0 (0–1023) y se escala a milivoltios considerando VDD ≈ 3.1 V.  
- **Cálculo de temperatura**: 10 mV = 1 décima de °C. Se obtiene parte entera y decimal.  
- **Formateo de cadena**: se genera `"XX.XC"` en el buffer `tbuf`.  
- **Despliegue en LCD**:  
  - Línea 1, col 0: `"Estado: "`.  
  - Línea 2, col 2: `"Temp: "` + `tbuf`.  
  - Línea 1, col 7: mensaje de estado de 8 caracteres.  
- **Control de LEDs**:  
  - `LED_20` (RB0): verde si ≥ 20 °C.  
  - `LED_30` (RB1): amarillo si ≥ 30 °C.  
  - `LED_40` (RB2): rojo si ≥ 40 °C.  
  - `LED_OVER` (RB3): si > 50 °C.  
- **Histéresis para salida B4** (RB4):  
  - Se activa al alcanzar ≥ 50 °C.  
  - Se desactiva al bajar ≤ 30 °C.  
- **Retardo** de 500 ms antes de la siguiente lectura (`__delay_ms(500)`).


## Implementación

# Conexiones del circuito – Sensor LM35, PIC18F45K22, LCD I2C, LEDs y relevador

## 1. Sensor de Temperatura LM35 (U2)
| Pin del LM35 | Conexión             | Descripción                     |
|--------------|----------------------|---------------------------------|
| 1 (VCC)      | +5V                  | Alimentación                    |
| 2 (VOUT)     | RA0/AN0 (pin 2 PIC)  | Señal analógica de temperatura  |
| 3 (GND)      | GND                  | Tierra común                    |

---

## 2. Microcontrolador PIC18F45K22 (U1)
| Pin del PIC | Nombre     | Conexión/Función                          |
|-------------|------------|------------------------------------------|
| 1           | MCLR       | +5V (reset)                               |
| 2           | RA0/AN0    | Entrada de sensor LM35                   |
| 14          | VSS        | GND                                       |
| 32          | VDD        | +5V                                       |
| 33          | RB0        | LED D1 (umbral ≥ 20 °C)                   |
| 34          | RB1        | LED D2 (umbral ≥ 30 °C)                   |
| 35          | RB2        | LED D3 (umbral ≥ 40 °C)                   |
| 36          | RB3        | LED D4 (umbral > 50 °C)                   |
| 37          | RB4        | **Relevador (relay) – Control de carga** |
| 18          | RC3        | SCL del módulo LCD I2C                   |
| 23          | RC4        | SDA del módulo LCD I2C                   |

---

## 3. Módulo LCD 16x2 con I2C (LCD1)
| Pin LCD I2C | Conexión al PIC | Función             |
|-------------|------------------|---------------------|
| VDD         | +5V              | Alimentación        |
| VSS         | GND              | Tierra              |
| SCL         | RC3 (pin 18)     | Señal de reloj I2C  |
| SDA         | RC4 (pin 23)     | Datos I2C           |

---

## 4. LEDs (D1 a D4) – con resistencias de 1kΩ
| LED | Pin PIC | Umbral de temperatura | Conexión         |
|-----|---------|------------------------|------------------|
| D1  | RB0     | ≥ 20 °C                | Ánodo a RB0      |
| D2  | RB1     | ≥ 30 °C                | Ánodo a RB1      |
| D3  | RB2     | ≥ 40 °C                | Ánodo a RB2      |
| D4  | RB3     | > 50 °C                | Ánodo a RB3      |
|     |         |                        | Cátodo a GND     |

---
<p align="center"><strong>Figura 7.</strong>Esquemático</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/5642c238-3315-4894-a1d9-641b26f41325" alt="Mi imagen">
</p>
<p align="center">
(Fuente propia)
</p>

En la figura podemos observar el primer montaje que se realizó en Proteus para verificar el correcto cableado de todos los componentes:

- **Sensor LM35**: conectado a la entrada analógica AN0 (RA0) del PIC18F45K22 (U1).  
- **Microcontrolador PIC18F45K22** (U1): alimentado a +5 V, con RA6/RA7 como GPIO y MCLR configurado como reset externo.  
- **LCD I²C** (JHD-2X16-I2C): conectado al bus I²C del PIC (SCL en RC3, SDA en RC4), con sus pines VDD y VSS a +5 V y GND.  
- **LEDs D1–D4**: cada uno con resistencia de 1 kΩ, conectados a RB0–RB3 para indicar umbrales de temperatura (≥ 20 °C, ≥ 30 °C, ≥ 40 °C y > 50 °C).  
- **Salida RB4** (SALIDA_B4): reservada para control de relé o ventilador con histéresis entre 50 °C y 30 °C.

Este montaje en Proteus permite simular:

1. La lectura analógica del LM35.  
2. La conversión y despliegue en la LCD vía I²C.  
3. El encendido secuencial de LEDs según umbrales definidos.  

Antes de pasar al prototipo físico, confirmamos que todas las conexiones y la lógica de activación funcionan correctamente.  

<p align="center"><strong>Figura 8.</strong>Esquemático</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/88bab25f-548b-461e-9caa-91722a181646" alt="Mi imagen">
</p>
<p align="center">
(Fuente propia)
</p>


Debo conectar la interfaz I2C del LCD en los pines SDA y SCL correspondientes del microcontrolador PIC que estoy usando.

Es importante verificar en el datasheet de cada microcontrolador cuáles son los pines específicos para la comunicación I2C, ya que pueden variar según el modelo.

<p align="center"><strong>Figura 9.</strong> Conexiones.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/c97682bf-fe99-4e32-97e8-75054ea39b78" alt="Mi imagen">
</p>
<p align="center">
(Fuente propia)
</p>

## 5. Relevador (Relay)

| Pin del PIC | Conexión            | Descripción                                                  |
|-------------|---------------------|--------------------------------------------------------------|
| RB4         | Entrada de relevador| Se activa cuando la temperatura ≥ 50 °C y se desactiva < 30 °C |
  
---

<p align="center"><strong>Figura 10.</strong>Esquematico Parte 2.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/552cd8d0-966b-4861-a099-4867b8ceaa68" alt="Mi imagen">
</p>
<p align="center">
(Fuente propia)
</p>

En este esquematico se integra el Relay para poder activar el Ventilador

<p align="center"><strong>Figura 11.</strong>Montaje Final.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/dfed493c-73a8-44eb-b358-d8fa5e560620" alt="Mi imagen">
</p>
<p align="center">
(Fuente propia)
</p>

## Diagramas

<p align="center"><strong>Figura 12.</strong> ADC.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/09768a97-e410-4d87-950e-a0dabdb0772e" alt="Mi imagen">
</p>
<p align="center">
(Fuente propia)
</p>

<p align="center"><strong>Figura 13.</strong> i2C.C.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/14477e47-8701-4d7f-8017-dff02e005871" alt="Mi imagen">
</p>
<p align="center">
(Fuente propia)
</p>

<p align="center"><strong>Figura 14.</strong> I2C_LCD.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/44376a51-4362-4c2d-a7fd-b2811de5536b" alt="Mi imagen">
</p>
<p align="center">
(Fuente propia)
</p>


<p align="center"><strong>Figura 15.</strong> MAIN.C</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/71d71bee-ffd3-4391-8a2b-da3568aca656" alt="Mi imagen">
</p>
<p align="center">
(Fuente propia)
</p>

## Explicación de Código

## i2c.c  
Este codigo se encarga de todo lo relacionado con enviar y recibir datos por el bus I²C usando el módulo MSSP del PIC. Básicamente:

- **I2C__Init():** Inicializa el I2C del PIC
- **I2C__Start(), I2C__RepeatedStart(), I2C__Stop():** Inician, reinician o cierran la charla en el bus.
- **I2C__Write(data):** Manda un byte y devuelve si el esclavo dijo “OK, lo recibí” (ACK) o no.  
- **I2C_Read_Byte():** Pone el módulo a modo lectura, espera y luego saca el dato que llegó.  
- **I2C_ACK() / I2C_NACK():** Sirven para avisar al otro lado si seguimos leyendo más bytes (ACK) o si ya no queremos nada más (NACK).

Lo importante está en `I2C__Wait()`, que se encarga de no pisarse con otras operaciones y evita que se envien datos antes de tiempo.

---

## i2c.h  
Aquí van todas las configuraciones para que i2c.c funcione:

- Definición de la frecuencia del cristal (`_XTAL_FREQ`) y la velocidad I²C (`I2C_BaudRate`).  
- Macros para marcar cuáles pines son SCL y SDA.  
- Las declaraciones de todas las funciones de i2c.c.
---
## i2c_lcd.c  
Este archivo usa lo de i2c.c para controlar un LCD con modulo I²C. En vez de andar pensando en pulsos y registros, te da funciones fáciles:

- **LCD_Init(address):** Guarda la dirección del expansor y manda la secuencia típica de comandos para arrancar el LCD en modo 4 bits, limpiar pantalla y ponerlo listo.  
- **IO_Expander_Write(data):** Envía un byte al expansor; es el corazón de toda la comunicación con el LCD.  
- **LCD_Write_4Bit(nibble):** Manda 4 bits al LCD, combina el nibble con el estado de RS (dato o comando) y del backlight, hace el pulso de “Enable” y listo.  
- **LCD_CMD(cmd) / LCD_Write_Char(data):** Dividen el byte en dos mitades y llaman dos veces a Write_4Bit para mandar comandos o caracteres.  
- **LCD_Write_String(str):** Recorre la cadena y va escribiendo carácter por carácter.  
- **LCD_Set_Cursor(row, col):** Calcula la dirección en la memoria del LCD y la manda para mover el cursor.  
- **Backlight() / noBacklight():** Prenden o apagan la luz de fondo del LCD.  
- **LCD_SL() / LCD_SR():** Desplazan toda la pantalla a la izquierda o a la derecha.  
- **LCD_Clear():** Borra la pantalla y espera a que termine.
---
## i2c_lcd.h  
Este archivo contiene todo lo que se necesita para usar las funciones de i2c_lcd.c:

- Macros con las direcciones iniciales de cada fila del LCD (`LCD_FIRST_ROW`, `LCD_SECOND_ROW`, etc.).  
- Códigos de comando comunes (`LCD_CLEAR`, `LCD_RETURN_HOME`, `LCD_CURSOR_OFF`, etc.).  
- Declaración de todas las funciones de i2c_lcd.c.  
- Guardar contra inclusiones dobles y el include a `<xc.h>` y a `i2c.h`.
  

## Evidencia en vídeo

1. **Arranque del sistema**  
   - LCD inicializando vía I2C y mostrando la temperatura ambiente.  
   - LEDs en verde.
   
   https://github.com/user-attachments/assets/98782020-4ebf-49ef-b6c1-de5e9d3b41c8

2. **Variación de temperatura**  
   - Cambio de LEDs a amarillo y luego rojo al aproximar el encendedor al sensor LM35.  
   - Actualización simultánea en la pantalla LCD.
   
   https://github.com/user-attachments/assets/bff0e00e-1873-42a4-9ca1-90dfa10cd483
  
3. **Umbral crítico**  
   - Activación del ventilador para enfriamiento.  
   - Retorno a estado normal cuando la temperatura disminuye, con LEDs regresando a verde y mensaje “NORMAL” en la LCD.

https://github.com/user-attachments/assets/d57423f9-3d0d-49f8-8ed8-9fd2c31506ba

## Conclusiones

1. **Validación mediante simulación**  
   La utilización de Proteus permitió comprobar el correcto conexionado y la lógica de funcionamiento antes de implementar el prototipo físico, ahorrando tiempo y reduciendo errores de cableado.

2. **Fiabilidad en la lectura de temperatura**  
   El sensor LM35, con su salida lineal de 10 mV/°C, y la conversión en el PIC18F45K22 proporcionan una resolución de 0.1 °C, cumpliendo con los requisitos de precisión para aplicaciones de monitoreo climático.

3. **Interfaz intuitiva**  
   - El módulo LCD I²C muestra simultáneamente la temperatura (“Temp: XX.XC”) y un mensaje de estado codificado en 8 caracteres (“Frio”, “Normal”, “Caliente”, “Peligro!”) sin dejar residuos de texto.  
   - Los LEDs en RB0–RB3 refuerzan visualmente los rangos críticos, facilitando la lectura rápida.

4. **Control de actuadores con histéresis**  
   La salida RB4, diseñada para accionar un ventilador o relé, incorpora histéresis (activa a ≥ 50 °C y desactiva a ≤ 30 °C), evitando oscilaciones y desgaste mecánico por conmutaciones frecuentes.

5. **Optimización de recursos**  
   - Se aprovechan los periféricos integrados (ADC, MSSP/I²C) del PIC para minimizar componentes externos.  
   - El código en C resulta legible y portable a otros microcontroladores de la familia PIC.

 

