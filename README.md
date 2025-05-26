[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=19631495&assignment_repo_type=AssignmentRepo)
# Proyecto final

## Integrantes
[Juan David Rojas Diaz](https://github.com/JuanRojas15)

[Carlos Andres Rojas Diaz](https://github.com/CarlosRojas05)

## Nombre del proyecto: 


## Documentación
### LM35 – El sensor de temperatura más popular
El LM35 es un circuito electrónico sensor que puede medir temperatura. Su salida es analógica, es decir, te proporciona un voltaje proporcional a la temperatura. El sensor tiene un rango desde −55°C a 150°C. Su popularidad se debe a la facilidad con la que se puede medir la temperatura. Incluso no es necesario de un microprocesador o microcontrolador para medir la temperatura. Dado que el sensor LM35 es analógico, basta con medir con un multímetro, el voltaje a salida del sensor.

Para convertir el voltaje a la temperatura, el LM35 proporciona 10mV por cada grado centígrado. También cabe señalar que ese sensor se puede usar sin offset, es decir que si medimos 20mV a la salida, estaremos midiendo 2°C.

<p align="center"><strong>Figura 1.</strong> Conexiones.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/f0317be9-2a2e-426e-8cdd-4d2c20e9d706" alt="Mi imagen">
</p>
<p align="center">
(Fuente: Maldonado Ramírez, D. N. (2025, 12 de mayo). Lab04: Comunicación UART en PIC18F45K22 [Archivo de GitHub]. https://github.com/DianaNatali/ECCI-Microprocesadores-2025-I-/blob/main/laboratorios/4_lab04/README.md)
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

<p align="center"><strong>Figura 2.</strong> Conexiones.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/d4f0ed55-b48c-4c6e-956c-362e6e0444a6" alt="Mi imagen">
</p>
<p align="center">
(Fuente: Maldonado Ramírez, D. N. (2025, 12 de mayo). Lab04: Comunicación UART en PIC18F45K22 [Archivo de GitHub]. https://github.com/DianaNatali/ECCI-Microprocesadores-2025-I-/blob/main/laboratorios/4_lab04/README.md)
</p>

<p align="center"><strong>Figura 2.</strong> Conexiones.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/056182f0-5c37-4ee8-a474-ec88072505e2" alt="Mi imagen">
</p>
<p align="center">
(Fuente: Maldonado Ramírez, D. N. (2025, 12 de mayo). Lab04: Comunicación UART en PIC18F45K22 [Archivo de GitHub]. https://github.com/DianaNatali/ECCI-Microprocesadores-2025-I-/blob/main/laboratorios/4_lab04/README.md)
</p>

La simples del circuito hace que sea muy fácil ser utilizado en alguna aplicación embebida. Entonces sólo basta alimentarlo con digamos 5VDC, conectar la tierra GND a la tierra del circuito digital y la salida de voltaje a la entrada del ADC.

<p align="center"><strong>Figura 2.</strong> Conexiones.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/2b7f98f9-079b-4426-a085-611d30e2e231" alt="Mi imagen">
</p>
<p align="center">
(Fuente: Maldonado Ramírez, D. N. (2025, 12 de mayo). Lab04: Comunicación UART en PIC18F45K22 [Archivo de GitHub]. https://github.com/DianaNatali/ECCI-Microprocesadores-2025-I-/blob/main/laboratorios/4_lab04/README.md)
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

<p align="center"><strong>Figura 2.</strong> Conexiones.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/5ed64783-6975-4196-84ce-29ed9dd4a508" alt="Mi imagen">
</p>
<p align="center">
(Fuente: Maldonado Ramírez, D. N. (2025, 12 de mayo). Lab04: Comunicación UART en PIC18F45K22 [Archivo de GitHub]. https://github.com/DianaNatali/ECCI-Microprocesadores-2025-I-/blob/main/laboratorios/4_lab04/README.md)
</p>

Para evitar ocupar múltiples pines del microcontrolador PIC, podemos utilizar dispositivos como el PCF8574T, un expansor de entradas y salidas digitales que se conecta mediante el protocolo I2C. Este módulo permite manejar un LCD usando solo dos pines del microcontrolador, SDA y SCL, simplificando enormemente el diseño de tu circuito.

<p align="center"><strong>Figura 2.</strong> Conexiones.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/9eb6c34c-10b0-4212-8b6c-055fbf300579" alt="Mi imagen">
</p>
<p align="center">
(Fuente: Maldonado Ramírez, D. N. (2025, 12 de mayo). Lab04: Comunicación UART en PIC18F45K22 [Archivo de GitHub]. https://github.com/DianaNatali/ECCI-Microprocesadores-2025-I-/blob/main/laboratorios/4_lab04/README.md)
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
   - Mostrar “Temp: XX.X°C” y un mensaje de estado (“NORMAL”, “PRECAUCIÓN”, “ENFRIANDO”).

2. **Indicadores LED secuenciales**  
   - LED verde: temperatura < 20 °C.  
   - LED amarillo: 20 °C ≤ temperatura < 30 °C.  
   - LED rojo: 30 °C ≤ temperatura < 40 °C.  
   - LED adicional: temperatura > 50 °C.

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
   - **LCD I²C**: se envía la secuencia de inicialización al expansor, se limpia la pantalla y se posiciona el cursor.

3. **Configuración de LEDs**  
   - Se deshabilita la función analógica en RB0–RB3 y se configuran como salidas digitales.  
   - Al inicio se apagan todos los LEDs.

4. **Bucle de medición y control**  
   - **Lectura ADC**: se lee el valor de AN0 (0–1023) y se escala a milivoltios considerando V<sub>DD</sub> ≈ 3.1 V.  
   - **Cálculo de temperatura**: se convierte la lectura en décimas de grado (10 mV = 1 décima).  
   - **Formateo de cadena**: se transforma la parte entera y decimal en caracteres ASCII para mostrar “XX.XC”.  
   - **Despliegue en LCD**: se posiciona el cursor en la primera línea y se imprime la cadena de temperatura.  
   - **Control de LEDs**:  
     - Verde si ≥ 20 °C.  
     - Amarillo si ≥ 30 °C.  
     - Rojo si ≥ 40 °C.  
     - Umbral adicional (LED_OVER) si > 50 °C.  
   - **Activación de ventilador**: se conmutan los contactos del relé cuando la temperatura supera 40 °C, manteniéndolo hasta que baje bajo el nivel de histéresis.  
   - Se introduce un breve retardo (~20 ms) antes de la siguiente lectura.


## Implementación
Debo conectar la interfaz I2C del LCD en los pines SDA y SCL correspondientes del microcontrolador PIC que estoy usando.

Es importante verificar en el datasheet de cada microcontrolador cuáles son los pines específicos para la comunicación I2C, ya que pueden variar según el modelo.

<p align="center"><strong>Figura 2.</strong> Conexiones.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/c97682bf-fe99-4e32-97e8-75054ea39b78" alt="Mi imagen">
</p>
<p align="center">
(Fuente: Maldonado Ramírez, D. N. (2025, 12 de mayo). Lab04: Comunicación UART en PIC18F45K22 [Archivo de GitHub]. https://github.com/DianaNatali/ECCI-Microprocesadores-2025-I-/blob/main/laboratorios/4_lab04/README.md)
</p>


## Diagramas

<p align="center"><strong>Figura 3.</strong> ADC.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/09768a97-e410-4d87-950e-a0dabdb0772e" alt="Mi imagen">
</p>
<p align="center">
(Fuente propia)
</p>

<p align="center"><strong>Figura 4.</strong> i2C.C.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/14477e47-8701-4d7f-8017-dff02e005871" alt="Mi imagen">
</p>
<p align="center">
(Fuente propia)
</p>

<p align="center"><strong>Figura 5.</strong> I2C_LCD.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/7174ca9c-a184-4d25-9da2-a8ca078e7bfb" alt="Mi imagen">
</p>
<p align="center">
(Fuente propia)
</p>

<p align="center"><strong>Figura 6.</strong> MAIN.C PARTE 1.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/83866311-9af5-457f-902d-9604b622b6e8" alt="Mi imagen">
</p>
<p align="center">
(Fuente propia)
</p>

 <p align="center"><strong>Figura 7.</strong> MAIN.C PARTE 2.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/3b298af0-7215-41bb-b4db-63b8e542b1e6" alt="Mi imagen">
</p>
<p align="center">
(Fuente propia)
</p>

  <p align="center"><strong>Figura 8.</strong> MAIN.C PARTE 3.</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/61ac40c6-28e5-45e3-b628-b7319919adb9" alt="Mi imagen">
</p>
<p align="center">
(Fuente propia)
</p>

<p align="center"><strong>Figura 9.</strong>Esquemático</p>
<p align="center">
  <img src="https://github.com/user-attachments/assets/5642c238-3315-4894-a1d9-641b26f41325" alt="Mi imagen">
</p>
<p align="center">
(Fuente propia)
</p>

## Explicación de Código

## i2c.c

Este archivo implementa las rutinas de comunicación I²C (Inter-Integrated Circuit) usando el módulo MSSP (Master Synchronous Serial Port) del PIC. Su función principal es permitir la transmisión y recepción de datos a través del bus I2C, que se utiliza para comunicarse con dispositivos externos (como un expansor I/O para el LCD). El código establece el módulo I2C en modo maestro, configurando los registros `SSPCON`, `SSPCON2` y `SSPSTAT` con los valores adecuados para habilitar I2C y fijar la velocidad de transmisión según una frecuencia de cristal predefinida (`_XTAL_FREQ`) y la tasa de baudios deseada (`I2C_BaudRate`).

El archivo ofrece varias funciones clave:

* **I2C__Init():** Inicializa el hardware I2C, ajustando el reloj y habilitando los pines SCL/SDA como entradas para la línea abierta.
* **I2C__Start() / I2C__RepeatedStart() / I2C__Stop():** Inician, re-inician o finalizan una comunicación I2C. Estas funciones activan los bits `SEN`, `RSEN` o `PEN` tras asegurarse (mediante `I2C__Wait()`) de que el bus esté libre.
* **I2C__Write(data):** Envía un byte al bus. Esta función pone el dato en el registro `SSPBUF`, espera a que se complete la transmisión (`SSPIF`), limpia la bandera y devuelve el estado de ACK (si el dispositivo esclavo reconoció la transmisión).
* **I2C_Read_Byte():** Lee un byte del bus I2C. Activa el bit `RCEN` para habilitar la recepción, espera la señal de interrupción, luego retorna el dato recibido del registro `SSPBUF`.
* **I2C_ACK() / I2C_NACK():** Envían una señal de ACK o NACK después de recibir datos, controlando los bits `ACKDT` y `ACKEN`.

En el código interno de `i2c.c` es fundamental la rutina `I2C__Wait()`, que monitorea los flags del módulo I2C para asegurar que la línea esté lista antes de cada operación. Así, se evita iniciar una nueva transmisión antes de que la anterior haya concluido. En conjunto, `i2c.c` provee una capa de abstracción que simplifica el uso de I2C en el resto del programa, sin que otros módulos necesiten manipular directamente los registros de hardware.

## i2c.h

En este encabezado se definen los parámetros y prototipos relacionados con la interfaz I²C. Contiene constantes como la frecuencia del cristal (`_XTAL_FREQ`), la tasa de baudios de I2C (`I2C_BaudRate`) y macros para indicar los pines de datos (por ejemplo, `SCL_D` y `SDA_D` apuntan a los registros TRIS de los pines SCL y SDA). Estas macros ayudan a configurar y controlar la dirección de los pines usados por el bus I2C.

Además, `i2c.h` declara los prototipos de las funciones implementadas en `i2c.c`: `void I2C__Init(void);`, `void I2C__Start(void);`, `void I2C__Stop(void);`, `unsigned char I2C__Write(unsigned char data);`, `unsigned char I2C_Read_Byte(void);`, etc. De esta forma, otros archivos (como el módulo LCD) pueden invocar estas rutinas sin definición interna. El archivo suele incluir protecciones contra inclusión doble y la inclusión de encabezados estándar del compilador (por ejemplo `<xc.h>`). En conjunto, `i2c.h` define la interfaz pública de la capa I2C, marcando configuraciones clave y exponiendo las funciones de comunicación.

## i2c_lcd.c

Este archivo implementa las funciones de alto nivel para controlar una pantalla LCD mediante un expansor I²C (como el PCF8574). Aprovecha las rutinas de `i2c.c` para enviar comandos y datos al LCD utilizando la comunicación I2C. Internamente, mantiene variables globales que representan el estado de la señal RS (para seleccionar registro de datos o comando) y el backlight (retroiluminación) del LCD.

El contenido típico de `i2c_lcd.c` incluye:

* **LCD_Init(address):** Inicializa el LCD enviando una secuencia de comandos estándar para ponerlo en modo 4 bits, encender la pantalla, borrar, y establecer el modo de entrada. Primero guarda la dirección I2C del expander (por ejemplo `0x4E`) en una variable interna, luego escribe ceros en el expansor para preparar la línea. A continuación ejecuta varias llamadas a `LCD_CMD(...)` con retardos (`__delay_ms`) para completar la configuración (método similar a lo indicado en la hoja de datos del LCD).
* **IO_Expander_Write(data):** Envía un byte completo al expansor I2C. Utiliza `I2C__Start()`, luego escribe la dirección del dispositivo (`i2c_add`), seguida del dato con la bit de backlight, y finalmente `I2C__Stop()`. Esta función es la base para comunicar cualquier cambio al puerto de salida del expansor (que controla las patillas del LCD).
* **LCD_Write_4Bit(nibble):** Envía 4 bits al LCD por medio del expansor. Combina el nibble con el valor actual de RS (para indicar si es comando o dato) y el backlight. Luego realiza un pulso de habilitación (Enable) poniendo alto un bit específico (`E`) con `IO_Expander_Write(nibble | 0x04)`, seguido de bajarlo (`IO_Expander_Write(nibble & 0xFB)`) y esperando unos microsegundos para completar la escritura.
* **LCD_CMD(cmd):** Para enviar un comando al LCD, la rutina ajusta RS=0 y divide el byte de comando en dos nibbles (alto y bajo). Llama dos veces a `LCD_Write_4Bit`: primero con `cmd & 0xF0` (los 4 bits más significativos), luego con `(cmd << 4) & 0xF0` (los 4 bits menos significativos). Esto obedece el protocolo de funcionamiento en 4 bits del LCD.
* **LCD_Write_Char(data):** Similar a `LCD_CMD`, pero con RS=1 (seleccionando el registro de datos). También descompone el byte del caracter en dos nibbles e invoca `LCD_Write_4Bit` dos veces para transmitirlo.
* **LCD_Write_String(str):** Recorre un arreglo de caracteres nulos (`'\0'`) y llama repetidamente a `LCD_Write_Char` para desplegar cada caracter en secuencia. Esto simplifica escribir texto completo en pantalla.
* **LCD_Set_Cursor(row, col):** Mueve el cursor del LCD a la fila y columna indicadas. Internamente calcula la dirección DDRAM correspondiente (por ejemplo, `0x80` para la primera fila, `0xC0` para la segunda, etc.) sumando el desplazamiento de columna (`col-1`), y envía este valor con `LCD_CMD` para posicionar el cursor.
* **Backlight() / noBacklight():** Enciende o apaga la retroiluminación del LCD modificando la variable `BackLight_State`. Luego llama a `IO_Expander_Write(0)` para que el cambio surta efecto (pone el bit correspondiente del expansor).
* **LCD_SL() / LCD_SR():** Ordenan al LCD desplazar la pantalla completa a la izquierda (`0x18`) o a la derecha (`0x1C`), usando `LCD_CMD` con retardos cortos.
* **LCD_Clear():** Envía el comando de borrado de pantalla (`0x01`) y espera unos microsegundos para que concluya la operación.

En resumen, `i2c_lcd.c` oculta los detalles de bajo nivel (como pulsos de señal Enable y gestiones del expansor) tras funciones fáciles de usar. Cualquier parte del programa puede inicializar la pantalla y escribir texto llamando a estas funciones, sin preocuparse por los aspectos eléctricos.

## i2c_lcd.h

Este encabezado define las constantes y prototipos relacionadas con el manejo del LCD vía I2C. Contiene definiciones de macros útiles, como el formato de líneas del LCD: por ejemplo `LCD_FIRST_ROW 0x80`, `LCD_SECOND_ROW 0xC0`, etc., que representan las direcciones iniciales de cada fila. También incluye los códigos de comando típicos del LCD (como `LCD_CLEAR 0x01`, `LCD_RETURN_HOME 0x02`, `LCD_ENTRY_MODE_SET 0x04`, `LCD_CURSOR_OFF 0x0C`, entre otros) para facilitar su uso en el código.

Además, `i2c_lcd.h` declara las funciones que `i2c_lcd.c` implementa: `void LCD_Init(unsigned char addr);`, `void LCD_Write_Char(char c);`, `void LCD_Write_String(char *s);`, `void LCD_Set_Cursor(unsigned char row, unsigned char col);`, `void Backlight(void);`, `void noBacklight(void);`, `void LCD_Clear(void);`, etc. Incluye también guardas de inclusión múltiple y los includes necesarios (`<xc.h>` o de `i2c.h` para usar las rutinas I2C). Al centralizar estos prototipos y definiciones, cualquier archivo que desee controlar el LCD puede simplemente incluir `i2c_lcd.h` y usar sus funciones y macros, manteniendo el código limpio y fácil de leer.

## Evidencia en vídeo

1. **Arranque del sistema**  
   - LCD inicializando vía I2C y mostrando la temperatura ambiente.  
   - LEDs en verde.

2. **Variación de temperatura**  
   - Cambio de LEDs a amarillo y luego rojo al aproximar la mano al sensor LM35.  
   - Actualización simultánea en la pantalla LCD.

3. **Umbral crítico**  
   - Activación del ventilador para enfriamiento.  
   - Retorno a estado normal cuando la temperatura disminuye, con LEDs regresando a verde y mensaje “NORMAL” en la LCD.

[Video de demostración de la entrega final disponible]  

## Conclusiones


<!-- Crear una carpeta src e incluir en ella los códigos y/o el proyecto de mplab-->
