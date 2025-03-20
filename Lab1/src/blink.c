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

    TRISIO = 0b00100000; //Poner todos los pines como salidas
	GPIO = 0x00; //Poner pines en bajo
    //ANSEL = 0;
 
    unsigned int time = 100;
 
    //Loop forever
    while ( 1 )
    {
        // Número 1
            GP0 = 1;
            delay(time);

            // Apagar los pines, pero no todos
            GP0 = 0;  // Apagar solo GP0
            delay(time);

        // Número 2
            GP1 = 1;
            delay(time);

            // Apagar los pines
            GP1 = 0;  // Apagar solo GP1
            delay(time);

        // Número 3
            GPIO = 0b00000011;  // Enciende GP0 y GP1 al mismo tiempo
            delay(time);

            // Apagar los pines
            GP0 = 0; GP1 = 0;  // Apagar GP0 y GP1
            delay(time);
        
        // Número 4
            GPIO = 0b00000110;  // Enciende GP0 y GP1 al mismo tiempo
            delay(time);

            // Apagar los pines
            GP1 = 0; GP2 = 0;  // Apagar GP0 y GP1
            delay(time);
        
        // Número 5
            GPIO = 0b00000111;  // Enciende GP0 y GP1 al mismo tiempo
            delay(time);

            // Apagar los pines
            GP0 = 0; GP1 = 0; GP2 = 0;  // Apagar GP0 y GP1
            delay(time);
        
        // Número 6
            GPIO = 0b00001110;  // Enciende GP0 y GP1 al mismo tiempo
            delay(time);

            // Apagar los pines
            GP0 = 0; GP1 = 0; GP2 = 0; GP3 = 0;  // Apagar GP0 y GP1
            delay(time);
    }
        
}
 


void delay(unsigned int tiempo)
{
	unsigned int i;
	unsigned int j;

	for(i=0;i<tiempo;i++)
	  for(j=0;j<1275;j++);
}