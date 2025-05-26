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
## Evidencia en vídeo

1. **Arranque del sistema**  
   - LCD inicializando vía I2C y mostrando la temperatura ambiente y el estado “NORMAL”.  
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
