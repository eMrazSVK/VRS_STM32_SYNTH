/*
 * utility.h
 *
 *  Created on: 7. 1. 2018
 *      Author: EDO
 */

#ifndef SYNTH_UTILITY_H_
#define SYNTH_UTILITY_H_

#include "common.h"

uint16_t calc_timer_period(uint32_t signal_frequency);

void set_waveform(WAVEFORMS wave_type, int osc);

#endif /* SYNTH_UTILITY_H_ */
