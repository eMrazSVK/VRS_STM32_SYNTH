/*
 * periph_config.h
 *
 *  Created on: 7. 1. 2018
 *      Author: EDO
 */

#ifndef PERIPH_CONFIG_H_
#define PERIPH_CONFIG_H_

#include "common.h"

void basic_init(void);

void TIM6_Config(uint16_t timer_period);

void TIM7_Config(uint16_t timer_period);

/* Config DAC1 and corresponding DMA channel */
void DAC1_Config(uint16_t *waveform);

/* Config DAC2 and corresponding DMA channel */
void DAC2_Config(uint16_t *waveform);

/* Config for USART2 and corresponding DMA channel */
void USART2_Config(void);

void NVIC_Config(void);

/* Main ticks */
void timer_init(void);

/* Start Oscillators */
void osc_start(void);

/* Stop Oscilaltors */
void osc_stop(void);

#endif /* PERIPH_CONFIG_H_ */
