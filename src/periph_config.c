/*
 * periph_config.c
 *
 *  Created on: 7. 1. 2018
 *      Author: EDO
 */

#include "periph_config.h"

void TIM6_Config(uint16_t timer_period)
{
  TIM_TimeBaseInitTypeDef TIM6_TimeBase;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);

  TIM_TimeBaseStructInit(&TIM6_TimeBase);
  TIM6_TimeBase.TIM_Period        = timer_period;
  TIM6_TimeBase.TIM_Prescaler     = 0;
  TIM6_TimeBase.TIM_ClockDivision = 0;
  TIM6_TimeBase.TIM_CounterMode   = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM6, &TIM6_TimeBase);
  TIM_SelectOutputTrigger(TIM6, TIM_TRGOSource_Update);

  TIM_Cmd(TIM6, ENABLE);
}

void DAC1_Config(uint16_t *waveform)
{
  DAC_InitTypeDef DAC_INIT;
  DMA_InitTypeDef DMA_INIT;

  DAC_INIT.DAC_Trigger        = DAC_Trigger_T6_TRGO;
  DAC_INIT.DAC_WaveGeneration = DAC_WaveGeneration_None;
  DAC_INIT.DAC_OutputBuffer   = DAC_OutputBuffer_Enable;
  DAC_Init(DAC_Channel_1, &DAC_INIT);

  DMA_DeInit(DMA1_Channel2);
  DMA_INIT.DMA_PeripheralBaseAddr = DAC_DHR12R1_Address;
  DMA_INIT.DMA_MemoryBaseAddr    = (uint32_t)waveform;
  DMA_INIT.DMA_DIR                = DMA_DIR_PeripheralDST;
  DMA_INIT.DMA_BufferSize         = WAVEFORM_RES;
  DMA_INIT.DMA_PeripheralInc      = DMA_PeripheralInc_Disable;
  DMA_INIT.DMA_MemoryInc          = DMA_MemoryInc_Enable;
  DMA_INIT.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_INIT.DMA_MemoryDataSize     = DMA_MemoryDataSize_HalfWord;
  DMA_INIT.DMA_Mode               = DMA_Mode_Circular;
  DMA_INIT.DMA_Priority           = DMA_Priority_High;

  DMA_Init(DMA1_Channel2, &DMA_INIT);

  DMA_Cmd(DMA1_Channel2, ENABLE);
  DAC_Cmd(DAC_Channel_1, ENABLE);
  DAC_DMACmd(DAC_Channel_1, ENABLE);
}

void basic_init(void) {
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

	gpio_a.GPIO_Pin  = GPIO_Pin_4 | GPIO_Pin_5;
	gpio_a.GPIO_Mode = GPIO_Mode_AN;
	gpio_a.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &gpio_a);
}
