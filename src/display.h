/*
 * display.h
 *
 *  Created on: 22. 1. 2018
 *      Author: EDO
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#define bufferSize 4

#include <stddef.h>
#include "stm32l1xx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "spi.h"
#include "ssd1306.h"
#include "ili9163.h"

char message_buffer[bufferSize];


void DrawSineWave(int16_t x, int16_t y);

void DrawSquare(int16_t x, int16_t y);

void DrawSawtooth(int16_t x, int16_t y);

void WriteFreqLFO1(int number);

void WriteFreqLFO2(int number);

void WriteFreqOSC1(int number);

void WriteFreqOSC2(int number);

void InitDisplay();

void DisplayScreen1();

void DisplayScreen2();

void DrawAllParams();



#endif /* DISPLAY_H_ */
