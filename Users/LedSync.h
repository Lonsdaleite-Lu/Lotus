/**
  ******************************************************************************
  * @file    LedSync.h
  * @author  Albert
  * @version V0.0.0
  * @date    2021-4
  * @brief   This file is used to synchronize LEDs and audio.
  ******************************************************************************
**/

#ifndef __LED_SYNC__
#define __LED_SYNC__

#include "stm8s.h"

#define MAX_LED_NUMBER  5U


void LS_Init(void);
void LS_UpdateColor(const uint32_t ulColor);
void LS_HandleColorCycle(void);
void ColorWave(void);


bool LS_StartColorCycle(void);







#endif // __LED_SYNC__