/*
 * common.c
 *
 *  Created on: 7. 1. 2018
 *      Author: EDO
 */

#include "common.h"
#include "periph_config.h"

/*Basic WaveForms definitions - points gathered from MATLAB*/

const uint16_t sine_function[WAVEFORM_RES] = {	  	2048, 2145, 2242, 2339, 2435, 2530, 2624, 2717, 2808, 2897,
													2984, 3069, 3151, 3230, 3307, 3381, 3451, 3518, 3581, 3640,
													3696, 3748, 3795, 3838, 3877, 3911, 3941, 3966, 3986, 4002,
													4013, 4019, 4020, 4016, 4008, 3995, 3977, 3954, 3926, 3894,
													3858, 3817, 3772, 3722, 3669, 3611, 3550, 3485, 3416, 3344,
													3269, 3191, 3110, 3027, 2941, 2853, 2763, 2671, 2578, 2483,
													2387, 2291, 2194, 2096, 1999, 1901, 1804, 1708, 1612, 1517,
													1424, 1332, 1242, 1154, 1068, 985, 904, 826, 751, 679,
													610, 545, 484, 426, 373, 323, 278, 237, 201, 169,
													141, 118, 100, 87, 79, 75, 76, 82, 93, 109,
													129, 154, 184, 218, 257, 300, 347, 399, 455, 514,
													577, 644, 714, 788, 865, 944, 1026, 1111, 1198, 1287,
													1378, 1471, 1565, 1660, 1756, 1853, 1950, 2047 };

const uint16_t square_function[WAVEFORM_RES] = {	4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020,
													4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020,
													4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020,
													4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020,
													4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020,
													4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020, 4020,
													4020, 4020, 4020, 4020, 75, 75, 75, 75, 75, 75,
													75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
													75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
													75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
													75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
													75, 75, 75, 75, 75, 75, 75, 75, 75, 75,
													75, 75, 75, 75, 75, 75, 75, 4020 };

const uint16_t sawtooth_function[WAVEFORM_RES] = { 	75, 106, 137, 168, 199, 230, 261, 292, 324, 355,
													386, 417, 448, 479, 510, 541, 572, 603, 634, 665,
													696, 727, 758, 789, 821, 852, 883, 914, 945, 976,
													1007, 1038, 1069, 1100, 1131, 1162, 1193, 1224, 1255, 1286,
													1318, 1349, 1380, 1411, 1442, 1473, 1504, 1535, 1566, 1597,
													1628, 1659, 1690, 1721, 1752, 1783, 1815, 1846, 1877, 1908,
													1939, 1970, 2001, 2032, 2063, 2094, 2125, 2156, 2187, 2218,
													2249, 2280, 2312, 2343, 2374, 2405, 2436, 2467, 2498, 2529,
													2560, 2591, 2622, 2653, 2684, 2715, 2746, 2777, 2809, 2840,
													2871, 2902, 2933, 2964, 2995, 3026, 3057, 3088, 3119, 3150,
													3181, 3212, 3243, 3274, 3306, 3337, 3368, 3399, 3430, 3461,
													3492, 3523, 3554, 3585, 3616, 3647, 3678, 3709, 3740, 3771,
													3803, 3834, 3865, 3896, 3927, 3958, 3989, 75 };

const uint8_t LFO_sine_function[LFO_WAVEFORM_RES] = { 	0, 1, 3, 4, 5, 6, 7, 9, 10, 11,
														12, 13, 14, 15, 16, 16, 17, 18, 18, 19,
														19, 19, 20, 20, 20, 20, 20, 20, 20, 19,
														19, 18, 18, 17, 17, 16, 15, 14, 13, 12,
														11, 10, 9, 8, 7, 6, 4, 3, 2, 1,
														-1, -2, -3, -4, -6, -7, -8, -9, -10, -11,
														-12, -13, -14, -15, -16, -17, -17, -18, -18, -19,
														-19, -20, -20, -20, -20, -20, -20, -20, -19, -19,
														-19, -18, -18, -17, -16, -16, -15, -14, -13, -12,
														-11, -10, -9, -7, -6, -5, -4, -3, -1, 0  };

const float ramp_function[ADSR_WAVEFORM_RES] = { 	0.010000, 0.020000, 0.030000, 0.040000, 0.050000, 0.060000, 0.070000, 0.080000, 0.090000,
													0.100000, 0.110000, 0.120000, 0.130000, 0.140000, 0.150000, 0.160000, 0.170000, 0.180000, 0.190000,
													0.200000, 0.210000, 0.220000, 0.230000, 0.240000, 0.250000, 0.260000, 0.270000, 0.280000, 0.290000,
													0.300000, 0.310000, 0.320000, 0.330000, 0.340000, 0.350000, 0.360000, 0.370000, 0.380000, 0.390000,
													0.400000, 0.410000, 0.420000, 0.430000, 0.440000, 0.450000, 0.460000, 0.470000, 0.480000, 0.490000,
													0.500000, 0.510000, 0.520000, 0.530000, 0.540000, 0.550000, 0.560000, 0.570000, 0.580000, 0.590000,
													0.600000, 0.610000, 0.620000, 0.630000, 0.640000, 0.650000, 0.660000, 0.670000, 0.680000, 0.690000,
													0.700000, 0.710000, 0.720000, 0.730000, 0.740000, 0.750000, 0.760000, 0.770000, 0.780000, 0.790000,
													0.800000, 0.810000, 0.820000, 0.830000, 0.840000, 0.850000, 0.860000, 0.870000, 0.880000, 0.890000,
													0.900000, 0.910000, 0.920000, 0.930000, 0.940000, 0.950000, 0.960000, 0.970000, 0.980000, 0.990000,
													1.000000 };

/* Rising and falling edge detector for nucleo button */
void edgeDetector(void) {
	static uint8_t previous_state;
	int actual_state;
	actual_state = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13);

	/*
	if (((actual_state == 1) && (previous_state == 1)) || ((actual_state == 0) && (previous_state == 0))){
			previous_state = actual_state;
	}
	*/

	if (((actual_state == 1) && (previous_state == 0))){
			previous_state = actual_state;
			make_sound = 0;
		}

	if (((actual_state == 0) && (previous_state == 1))){
			previous_state = actual_state;
			make_sound = 1;
		}

}

void array_multiply() {
	uint16_t i;
	uint16_t copied_array[WAVEFORM_RES];
	static int adsr_count;

	if (adsr_count < ADSR_WAVEFORM_RES) {
		for (i = 0; i < WAVEFORM_RES; i++) {
			//current_waveform[i] = current_waveform[i]*ramp_function[adsr_count];
			//copied_array[i] = current_waveform[i]*multiply;
		}
	}

	adsr_count++;
	if (adsr_count == ADSR_WAVEFORM_RES) adsr_count = 0;
	//memcpy(&current_waveform,&copied_array,sizeof(uint16_t)*WAVEFORM_RES);
}

void set_params() {
	TIM6_Config(calc_timer_period(params.osc1_freq));
	TIM7_Config(calc_timer_period(params.osc2_freq));

	set_waveform(params.osc1_waveform, 1);
	set_waveform(params.osc2_waveform, 2);

}

void DMA1_Channel6_IRQHandler(void) {
  /* Test on DMA Stream Transfer Complete interrupt */
  if (DMA_GetITStatus(DMA1_IT_TC6))
  {
    /* Clear DMA Stream Transfer Complete interrupt pending bit */
    DMA_ClearITPendingBit(DMA1_IT_TC6);

    if (uart_dma_buffer[0] == 0x0e) { // && (uart_dma_buffer[UART_DMA_BUFFER_SIZE-1] == 0x0f)) {

    	/* Set OSC1 waveform */
    	switch (uart_dma_buffer[2]) {
    		case 0x01:
    			params.osc1_waveform = SINE;
    			break;
    		case 0x02:
    			params.osc1_waveform = SQUARE;
    			break;
    		case 0x03:
    			params.osc1_waveform = SAWTOOTH;
    			break;
    	}

    	/* Set OSC2 waveform */
		switch (uart_dma_buffer[6]) {
			case 0x01:
				params.osc2_waveform = SINE;
				break;
			case 0x02:
				params.osc2_waveform = SQUARE;
				break;
			case 0x03:
				params.osc2_waveform = SAWTOOTH;
				break;
		}

		/* Set OSC1 Frequency */
		params.osc1_freq = uart_dma_buffer[3] | uart_dma_buffer[4] << 8;

		/* Set OSC2 Frequency */
		params.osc2_freq = uart_dma_buffer[7] | uart_dma_buffer[8] << 8;

		set_params();
    }
  }
}

