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
#define CNT_FREQ          	   	32000000         // TIM6 counter clock (prescaled APB1)
#define UART_DMA_BUFFER_SIZE	25
#define USART_BAUD				115200
#define TICK_PERIOD_US			10
#define LFO_WAVEFORM_RES		100
#define ADSR_WAVEFORM_RES		100

#include <stddef.h>
#include "stm32l1xx.h"
#include <string.h>


/* Fixed buffer for desired waveform - passed to DMA channel used for DAC */
uint16_t current_waveform_osc_1[WAVEFORM_RES];
uint16_t current_waveform_osc_2[WAVEFORM_RES];

/* LFO Frequencies in Hz */
uint8_t LFO1_Freq;
uint8_t LFO2_Freq;
uint32_t OSC1_Freq;
uint32_t OSC2_Freq;
int decide_wave;


GPIO_InitTypeDef  gpio_a;
GPIO_InitTypeDef  gpio_c;
NVIC_InitTypeDef NVIC_InitStructure;

USART_InitTypeDef USART_InitStructure;

uint8_t uart_dma_buffer[UART_DMA_BUFFER_SIZE];

uint8_t tim6_period[1];

/* Basic WaveForms */
extern const uint16_t sine_function[WAVEFORM_RES];
extern const uint16_t square_function[WAVEFORM_RES];
extern const uint16_t sawtooth_function[WAVEFORM_RES];
extern const uint8_t  LFO_sine_function[LFO_WAVEFORM_RES];
extern const float 	  ramp_function[ADSR_WAVEFORM_RES];

/* tick counter for SysTick */
__IO uint32_t ticks;


typedef enum {
	SINE = 0,
	SQUARE = 1,
	SAWTOOTH = 2
} WAVEFORMS;

typedef struct {
	uint16_t osc1_freq;
	WAVEFORMS osc1_waveform;
	uint16_t osc2_freq;
	WAVEFORMS osc2_waveform;
} osc_params;

/* flag to start oscillators */
int make_sound;

/* structure to hold all osc related params */
osc_params params;

/* Edge Detector for Button */
void edgeDetector(void);

/* Array multiply element-by-element for ADSR processing */
void array_multiply();

/* Set all parameters received from WIN APP */
void set_params();

/* Uart Handler, parsing incoming message */

void DMA1_Channel6_IRQHandler(void);

#endif /* COMMON_H_ */
