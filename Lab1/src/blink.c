/*
Autor: Alexa Lopez Marcos.
Carne: B94353.
Fecha: 25 de marzo 2025.
Título: Laboratorio 01.
----------------------------------------------------------------
Descripción:
Desarrollar un simulador de dado simplificado utilizando leds, un boton, el microcontrolador PIC12f683 y cualquier otro componente que considere necesario.
*/

#include <pic14/pic12f683.h>
#include <stdio.h>

//To compile:
//sdcc -mpic14 -p16f675 blink.c
 
//To program the chip using picp:
//Assuming /dev/ttyUSB0 is the serial port.
 
//Erase the chip:
//picp /dev/ttyUSB0 16f887 -ef
 
//Write the program:
//picp /dev/ttyUSB0 16f887 -wp blink.hex
 
//Write the configuration words (optional):
//picp /dev/ttyUSB0 16f887 -wc 0x2ff4 0x3fff
 
//Doing it all at once: erasing, programming, and reading back config words:
//picp /dev/ttyUSB0 16f887 -ef -wp blink.hex -rc
 
//To program the chip using pk2cmd:
//pk2cmd -M -PPIC16f887 -Fblink.hex

__code unsigned int __at (_CONFIG) configword = _INTOSCIO & _WDTE_OFF & _PWRTE_OFF & _MCLRE_OFF & _CP_ON & _CPD_ON;
// Función para retraso
void delay(unsigned int tiempo);
 
 
void main(void)
{

    TRISIO = 0b00101000; //Poner todos los pines como salidas
	GPIO = 0x00; //Poner pines en bajo
 
    unsigned int time = 100;
    unsigned int contador = 0;
    unsigned int numero_random;
 
    //Loop forever
    while ( 1 )
    {
        // Incrementar el contador de forma continua
        contador++;

        // Desincronización
        delay(10);

        if (GP5 == 1){
            // Rebote del boton
            while(GP5 == 1);
            delay(10);

            // Generar un número aleatorio con el valor actual del contador
            numero_random= contador % 6 + 1;

            // Configurar LEDs según el número aleatorio generado
            switch(numero_random){
                case 1: // Número 1
                
                    GP0 = 1;
                    delay(time);

                    // Apagar los pines, pero no todos
                    GP0 = 0;  // Apagar solo GP0
                    delay(time);
                break;

                case 2: // Número 2
                    GP1 = 1;
                    delay(time);

                    // Apagar los pines
                    GP1 = 0;  // Apagar solo GP1
                    delay(time);
                break;

                case 3:// Número 3
                    GPIO = 0b00000011;  // Enciende GP0 y GP1 al mismo tiempo
                    delay(time);

                    // Apagar los pines
                    GP0 = 0; GP1 = 0;  // Apagar GP0 y GP1
                    delay(time);

                break;

                case 4:// Número 4
                    GPIO = 0b00000110;  // Enciende GP0 y GP1 al mismo tiempo
                    delay(time);

                    // Apagar los pines
                    GP1 = 0; GP2 = 0;  // Apagar GP0 y GP1
                    delay(time);

                break;

                case 5:// Número 5
                    GPIO = 0b00000111;  // Enciende GP0 y GP1 al mismo tiempo
                    delay(time);

                    // Apagar los pines
                    GP0 = 0; GP1 = 0; GP2 = 0;  // Apagar GP0 y GP1
                    delay(time);

                break;

                case 6:// Número 6
                    GPIO = 0b00010110;  // Enciende GP0 y GP1 al mismo tiempo
                    delay(time);

                    // Apagar los pines
                    GP0 = 0; GP1 = 0; GP2 = 0; GP4 = 0;  // Apagar GP0 y GP1
                    delay(time);

                break;

            }
        }
    }
}
 


void delay(unsigned int tiempo)
{
	unsigned int i;
	unsigned int j;

	for(i=0;i<tiempo;i++)
	  for(j=0;j<1275;j++);
}
