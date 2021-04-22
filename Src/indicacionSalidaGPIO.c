/*
 * indicacionSalidaGPIO.c
 *
 *  Created on: Apr 2021
 *      Author: lincoln
 */

#include "indicacionSalidaGPIO.h"

static void apagar_Led(uint8_t valor_previo){
	switch(valor_previo){
	case 1:
		HAL_GPIO_WritePin(led_bajo_port, led_bajo_pin, GPIO_PIN_RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(led_medio_port, led_medio_pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(led_alto_port, led_alto_pin, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(led_muy_alto_port, led_muy_alto_pin, GPIO_PIN_RESET);
		break;
	default:
		break;

	}
}

static void encencer_Led(uint8_t valor_actual){

	switch(valor_actual){
	case 1:
		HAL_GPIO_WritePin(led_bajo_port, led_bajo_pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(led_medio_port, led_medio_pin, GPIO_PIN_SET);
		break;
	case 3:
		HAL_GPIO_WritePin(led_alto_port, led_alto_pin, GPIO_PIN_SET);
		break;
	case 4:
		HAL_GPIO_WritePin(led_muy_alto_port, led_muy_alto_pin, GPIO_PIN_SET);
		break;
	default:
		break;

	}
}
void indicar_nivel_en_Leds(uint8_t valor_actual){
	/*Se inicia con todo los leds apadados*/
	static uint8_t valor_previo = 0;
	if(valor_previo != valor_actual){

		apagar_Led(valor_previo);
		encencer_Led(valor_actual);

		valor_previo = valor_actual;
	}
}


