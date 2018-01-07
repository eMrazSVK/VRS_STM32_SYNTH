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
void DAC1_Config(uint16_t *waveform);

#endif /* PERIPH_CONFIG_H_ */
