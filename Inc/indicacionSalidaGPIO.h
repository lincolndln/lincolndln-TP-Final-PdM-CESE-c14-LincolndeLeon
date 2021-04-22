/*
 * indicacionSalidaGPIO.h
 *
 *  Created on: Apr 2021
 *      Author: lincoln
 */

#ifndef INC_INDICACIONSALIDAGPIO_H_
#define INC_INDICACIONSALIDAGPIO_H_

#include "main.h"

/*Definimos los pines a utilizar para cada señal*/
/*nivel BAJO*/
#define led_bajo_port	GPIOA
#define led_bajo_pin	GPIO_PIN_8

/*nivel MEDIO*/
#define led_medio_port	GPIOB
#define led_medio_pin	GPIO_PIN_10

/*nivel ALTO*/
#define led_alto_port	GPIOB
#define led_alto_pin	GPIO_PIN_4

/*nivel MUY ALTO*/
#define led_muy_alto_port	GPIOB
#define led_muy_alto_pin	GPIO_PIN_5


void indicar_nivel_en_Leds(uint8_t valor_actual);


#endif /* INC_INDICACIONSALIDAGPIO_H_ */
