/*
 * utility.c
 *
 *  Created on: 7. 1. 2018
 *      Author: EDO
 */

#include "synth_utility.h"


void set_waveform(WAVEFORMS wave_type, int osc) {

	if (osc == 1) {
		switch (wave_type) {
			case SINE :
				memcpy(&current_waveform_osc_1,
					   &sine_function,
					   sizeof(uint16_t)*WAVEFORM_RES);
				break;

			case SQUARE :
				memcpy(&current_waveform_osc_1,
					   &square_function,
					   sizeof(uint16_t)*WAVEFORM_RES);
				break;

			case SAWTOOTH :
				memcpy(&current_waveform_osc_1,
					   &sawtooth_function,
					   sizeof(uint16_t)*WAVEFORM_RES);
				break;
		}
	}

	if (osc == 2) {
			switch (wave_type) {
				case SINE :
					memcpy(&current_waveform_osc_2,
						   &sine_function,
						   sizeof(uint16_t)*WAVEFORM_RES);
					break;

				case SQUARE :
					memcpy(&current_waveform_osc_2,
						   &square_function,
						   sizeof(uint16_t)*WAVEFORM_RES);
					break;

				case SAWTOOTH :
					memcpy(&current_waveform_osc_2,
						   &sawtooth_function,
						   sizeof(uint16_t)*WAVEFORM_RES);
					break;
			}
		}
}

uint16_t calc_timer_period(uint32_t signal_frequency) {
	return ((CNT_FREQ)/((WAVEFORM_RES)*(signal_frequency)));
}


