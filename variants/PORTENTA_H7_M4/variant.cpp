/*
 *******************************************************************************
 * Copyright (c) 2019, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */

#include "pins_arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

// Pin number
const PinName digitalPin[] = {
  // D0 - D7
  PH_15,    // D0
  PK_1,     // D1
  PJ_11,    // D2
  PG_7,     // D3
  PC_7,     // D4
  PC_6,     // D5
  PA_8,     // D6
  PI_0,     // D7

  // D8 - D14
  PC_3,     // D8
  PI_1,     // D9
  PC_2,     // D10
  PH_8,     // D11
  PH_7,     // D12
  PA_10,    // D13
  PA_9,     // D14

  // A0 - A7
  PA_0,    // A0    ADC2_INP0
  PA_1,    // A1    ADC2_INP1
  PC_2,    // A2    ADC3_INP0
  PC_3,         // A3    ADC3_INP1
  PC_2,     // A4    ADC1_INP12
  PC_3,     // A5    ADC2_INP13
  PA_4,          // A6    ADC1_INP18

  // LEDS
  PK_5,    // LEDR
  PK_6,    // LEDG
  PK_7,    // LEDB
};

const uint32_t analogInputPin[] = {
  PA_0,   // A0    ADC2_INP0
  PA_1,   // A1    ADC2_INP1
  PC_2,   // A2    ADC3_INP0
  PC_3,        // A3    ADC3_INP1
  PC_2,     // A4    ADC1_INP12
  PC_3,     // A5    ADC2_INP13
  PA_4,          // A6    ADC1_INP18
};

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------
#include "Arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

osThreadId_t cm4_task_handle;
const osThreadAttr_t cm4_task_attributes = {
  .name = "cm4_task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal
};

void StartM4DefaultTask(void *argument);

void StartM4DefaultTask(void *argument) {
  /* Infinite loop */
  while(1) {
  }
}

void initVariant() {
  cm4_task_handle = osThreadNew(StartM4DefaultTask, NULL, &cm4_task_attributes);
  return;
}

/**
  * @brief  System Clock Configuration
  * @param  None
  * @retval None
  */
WEAK void SystemClock_Config(void)
{
}

#ifdef __cplusplus
}
#endif
