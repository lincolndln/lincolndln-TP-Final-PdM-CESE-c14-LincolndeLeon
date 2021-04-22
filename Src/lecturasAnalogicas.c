/*
 * lecturasAnalogicas.c
 *
 *  Created on: Apr, 2021
 *      Author: lincoln
 */

#include "lecturasAnalogicas.h"

static uint16_t miLecturaADC;
static double porcentajeNivel;


/*
 * --Se realiza la lectura analogica
 * */
static void leer_Valor_Analogico(ADC_HandleTypeDef * hadc_pt){
	/*Empezamos la conversion ADC*/
	HAL_ADC_Start(hadc_pt);
	 /*Espera a que se complete la conversion*/
	HAL_ADC_PollForConversion(hadc_pt, HAL_MAX_DELAY);
	 /*Obtenemos el resultado de la conversion ADC*/
	miLecturaADC = HAL_ADC_GetValue(hadc_pt);
}

/* Devuelve un valor entero entre 1 y 100 que representa el nivel del tanque*/
uint8_t get_Porcentaje_Nivel(ADC_HandleTypeDef * hadc_pt){

	/*Obtenemos la resolucion usada para por el ADC*/
	const uint32_t valorMaximoADC = 4095;

	/*Se realiza la lectura analogica que sera un valor entre 0 y 4095 (ADC a 12 bits)*/
	leer_Valor_Analogico(hadc_pt);

	/*Obtenemos porcentaje*/
	/*Se usa un ADC de 12 bits donde el valor maximo es 4095 */
	porcentajeNivel = ( ((float) miLecturaADC) / valorMaximoADC) * 100;

	/* Se convierte el nivel a un valor de 8 bits*/
	//porcentajeNivel = round(porcentajeNivel);
	return ((uint8_t) porcentajeNivel);
}



