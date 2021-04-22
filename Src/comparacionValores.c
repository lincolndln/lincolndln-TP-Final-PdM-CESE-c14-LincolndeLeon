/*
 * comparacionValores.c
 *
 *  Created on: Apr, 2021
 *      Author: lincoln
 */

#include "comparacionValores.h"

/*Usado para representar los 5 estados*/
typedef enum{
	VACIO,
	BAJO,
	MEDIO,
	ALTO,
	MUYALTO
} indicacion_Nivel;


static indicacion_Nivel indicacion_tanque;

/* Devuelve un valor entre 0 y 4 que representa VACIO, BAJO, MEDIO, ALTO y MUYALTO
 * Se reciben valores enteros entre 1 y 100  que representan
 * el nivel, y  valores correspondientes a BAJO, MEDIO, ALTO y MUY ALTO
 * */
uint8_t get_indicacion(uint8_t porcentaje_Nivel,
		uint8_t vBajo, uint8_t vMedio, uint8_t vAlto, uint8_t vMuyAlto){

	/*Se evalue que los valores esten ingresado correctamente*/
	if( (vBajo < vMedio) && (vMedio < vAlto) && (vAlto < vMuyAlto)){
		if (vMuyAlto <= porcentaje_Nivel){
			indicacion_tanque = MUYALTO;
		}else if(vAlto <= porcentaje_Nivel){
			indicacion_tanque = ALTO;
		}else if(vMedio <= porcentaje_Nivel){
			indicacion_tanque = MEDIO;
		}else if(vBajo <= porcentaje_Nivel){
			indicacion_tanque = BAJO;
		}else{
			indicacion_tanque = VACIO;
		}
	}else{
		indicacion_tanque = VACIO;
	}

	return indicacion_tanque;
}






