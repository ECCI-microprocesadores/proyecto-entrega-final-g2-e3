#pragma config FOSC     = INTIO67   // Oscilador interno, RA6/RA7 como GPIO
#pragma config PLLCFG   = OFF       // PLL deshabilitado
#pragma config PRICLKEN = ON        // Habilita reloj primario
#pragma config WDTEN    = OFF       // Watchdog apagado
#pragma config PWRTEN   = OFF       // Power?up timer apagado
#pragma config BOREN    = OFF       // Brown?out apagado
#pragma config MCLRE    = EXTMCLR   // MCLR externo
#pragma config PBADEN   = OFF       // PORTB<4:0> digital

#define _XTAL_FREQ 48000000UL
#include <xc.h>
#include "i2c.h"
#include "i2c_lcd.h"
#include "adc.h"
#include "uart.h"
#include <stdio.h>
// LEDs en RB0?RB3
#define LED_20   LATBbits.LATB0   // umbral 20?°C
#define LED_30   LATBbits.LATB1   // umbral 30?°C
#define LED_40   LATBbits.LATB2   // umbral 40?°C
#define LED_OVER LATBbits.LATB3   // >?40?°C
#define SALIDA_B4 LATBbits.LATB4  // salida con histéresis

void main(void) {
    unsigned int  adc;
    unsigned long mV;
    unsigned int  temp_tenths;
    unsigned char T_int, T_dec;
    char          tbuf[6];
    char          salidaB4_activa = 0;
    const char *msg_cold   = "Frio    ";  
    const char *msg_warm   = "Normal  ";  
    const char *msg_hot    = "Caliente";  
    const char *msg_danger = "Peligro!";  

    // Inicializa ADC en AN0
    ADC_Init();

    // Inicializa I²C y LCD
    I2C_init();
    lcd_init();
    lcd_clear();

    // Configura RB0?RB3 como salidas digitales para los LEDs
    ANSELBbits.ANSB0 = 0;
    ANSELBbits.ANSB1 = 0;
    ANSELBbits.ANSB2 = 0;
    ANSELBbits.ANSB3 = 0;
    ANSELBbits.ANSB4 = 0;
    TRISBbits.TRISB0 = 0;
    TRISBbits.TRISB1 = 0;
    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB3 = 0;
    TRISBbits.TRISB4 = 0;

    // Apaga todos al inicio
    LATB = 0;

    while (1) {
        
        // 1) Leer ADC (0?1023) de AN0
        adc = ADC_Read();

        // 2) Convertir a mV (Vdd ? 3.1?V ? 3100?mV)
        mV = (adc * 4600UL) / 1023;

        // 3) LM35: 10?mV/°C ? temp en décimas
        temp_tenths = mV;

        // 4) Partes entera y decimal
        T_int = temp_tenths / 10;
        T_dec = temp_tenths % 10;

        // 5) Formatear "XX.XC"
        tbuf[0] = '0' + (T_int / 10);
        tbuf[1] = '0' + (T_int % 10);
        tbuf[2] = '.';
        tbuf[3] = '0' + T_dec;
        tbuf[4] = 'C';
        tbuf[5] = '\0';

        // 6) Mostrar en LCD I²C
        lcd_set_cursor(0,0);
        lcd_write_string("Estado: ");
        lcd_set_cursor(1,2);
        lcd_write_string("Temp: ");
        lcd_write_string(tbuf);
        lcd_set_cursor(0,7);
        if (T_int < 30) {
        lcd_write_string(msg_cold);
        } else if (T_int < 40) {
            lcd_write_string(msg_warm);
        } else if (T_int < 48) {
            lcd_write_string(msg_hot);
        } else {
            lcd_write_string(msg_danger);
        }


        // 7) Control de LEDs según umbrales
        LED_20   = (T_int >= 20) ? 1 : 0;
        LED_30   = (T_int >= 30) ? 1 : 0;
        LED_40   = (T_int >= 40) ? 1 : 0;
        LED_OVER = (T_int  > 50) ? 1 : 0;
        
        if (!salidaB4_activa && T_int >= 50) {
            salidaB4_activa = 1;
            SALIDA_B4 = 1;
        } else if (salidaB4_activa && T_int <= 30) {
            salidaB4_activa = 0;
            SALIDA_B4 = 0;
        }
        __delay_ms(20);
    }
}
