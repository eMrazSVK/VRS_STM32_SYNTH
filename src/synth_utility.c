/*
 * utility.c
 *
 *  Created on: 7. 1. 2018
 *      Author: EDO
 */

#include "synth_utility.h"


void set_waveform(WAVEFORMS wave_type) {

	switch (wave_type) {
		case SINE :
			memcpy(&current_waveform,
				   &sine_function,
				   sizeof(uint16_t)*WAVEFORM_RES);
			break;

		case SQUARE :
			memcpy(&current_waveform,
				   &square_function,
				   sizeof(uint16_t)*WAVEFORM_RES);
			break;

		case SAWTOOTH :
			memcpy(&current_waveform,
				   &sawtooth_function,
				   sizeof(uint16_t)*WAVEFORM_RES);
			break;
	}
}

uint16_t calc_timer_period(uint32_t signal_frequency) {
	return ((CNT_FREQ)/((WAVEFORM_RES)*(signal_frequency)));
}


