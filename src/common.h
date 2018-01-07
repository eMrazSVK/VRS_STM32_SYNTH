/*
 * common.h
 *
 *  Created on: 7. 1. 2018
 *      Author: EDO
 */

#ifndef COMMON_H_
#define COMMON_H_

#define WAVEFORM_RES 			128
#define DAC_DHR12R1_Address     0x40007408       // DMA writes into this reg on every request
#define CNT_FREQ          	   	42000000         // TIM6 counter clock (prescaled APB1)

#include <stddef.h>
#include "stm32l1xx.h"
#include <string.h>

/* Fixed buffer for desired waveform - passed to DMA channel used for DAC */
uint16_t current_waveform[WAVEFORM_RES];

GPIO_InitTypeDef gpio_a;

/* Basic WaveForms */

extern const uint16_t sine_function[WAVEFORM_RES];

extern const uint16_t square_function[WAVEFORM_RES];

extern const uint16_t sawtooth_function[WAVEFORM_RES];


typedef enum {
	SINE = 0,
	SQUARE = 1,
	SAWTOOTH = 2
} WAVEFORMS;

#endif /* COMMON_H_ */
