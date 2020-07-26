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
  PA_0_C_ALT2,    // A0    ADC2_INP0
  PA_1_C_ALT0,    // A1    ADC2_INP1
  PC_2_C_ALT0,    // A2    ADC3_INP0
  PC_3_C,         // A3    ADC3_INP1
  PC_2_ALT0,     // A4    ADC1_INP12
  PC_3_ALT2,     // A5    ADC2_INP13
  PA_4,          // A6    ADC1_INP18

  // LEDS
  PK_5,    // LEDR
  PK_6,    // LEDG
  PK_7,    // LEDB
};

const uint32_t analogInputPin[] = {
  PA_0_C_ALT2,   // A0    ADC2_INP0
  PA_1_C_ALT0,   // A1    ADC2_INP1
  PC_2_C_ALT0,   // A2    ADC3_INP0
  PC_3_C,        // A3    ADC3_INP1
  PC_2_ALT0,     // A4    ADC1_INP12
  PC_3_ALT2,     // A5    ADC2_INP13
  PA_4,          // A6    ADC1_INP18
};

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------

void initVariant() {
  // configure analog mux to split Pxy and Pxy_C
  HAL_SYSCFG_AnalogSwitchConfig(SYSCFG_SWITCH_PA0, SYSCFG_SWITCH_PA0_OPEN);
  HAL_SYSCFG_AnalogSwitchConfig(SYSCFG_SWITCH_PA1, SYSCFG_SWITCH_PA1_OPEN);
  HAL_SYSCFG_AnalogSwitchConfig(SYSCFG_SWITCH_PC2, SYSCFG_SWITCH_PC2_OPEN);
  HAL_SYSCFG_AnalogSwitchConfig(SYSCFG_SWITCH_PC3, SYSCFG_SWITCH_PC3_OPEN);
}

#ifdef __cplusplus
extern "C" {
#endif

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
