#include "Arduino.h"
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
  RTCHandle.Instance = RTC;
  // Turn off LED from bootloader
  pinMode(PK_6, OUTPUT);
  digitalWrite(PK_6, HIGH);

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
  RCC_OscInitTypeDef       RCC_OscInitStruct = {};
  RCC_ClkInitTypeDef       RCC_ClkInitStruct = {};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {};

  /* Supply configuration update enable */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
  /* Configure the main internal regulator output voltage */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0); // 480MHz

  while (!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
  /* Macro to configure the PLL clock source */
  __HAL_RCC_PLL_PLLSOURCE_CONFIG(RCC_PLLSOURCE_HSE);
  /* Initializes the CPU, AHB and APB busses clocks */
  RCC_OscInitStruct.OscillatorType
    = RCC_OSCILLATORTYPE_HSI48 | RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 200; // 400MHz Mode
  //RCC_OscInitStruct.PLL.PLLN = 240; // 480MHz Mode
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 5;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }
  /* Initializes the CPU, AHB and APB busses clocks */
  RCC_ClkInitStruct.ClockType
    = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1
      | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_D3PCLK1 | RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection
    = RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_RNG | RCC_PERIPHCLK_SPI1
      | RCC_PERIPHCLK_SAI2 | RCC_PERIPHCLK_SAI1 | RCC_PERIPHCLK_SDMMC
      | RCC_PERIPHCLK_I2C2 | RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_I2C1
      | RCC_PERIPHCLK_USB | RCC_PERIPHCLK_QSPI | RCC_PERIPHCLK_FMC;
  // PLL 2
  PeriphClkInitStruct.PLL2.PLL2M = 4;
  //  PeriphClkInitStruct.PLL2.PLL2N = 115; // Max Freq @ 3v3 (overclocked SDRAM)
  PeriphClkInitStruct.PLL2.PLL2N = 100;  // 100Mhz -> FMC
  PeriphClkInitStruct.PLL2.PLL2P = 8;  // 57.5
  PeriphClkInitStruct.PLL2.PLL2Q = 10; // 46
  PeriphClkInitStruct.PLL2.PLL2R = 2;  // 115Mhz
  PeriphClkInitStruct.PLL2.PLL2RGE = RCC_PLL2VCIRANGE_2;
  PeriphClkInitStruct.PLL2.PLL2VCOSEL = RCC_PLL2VCOWIDE;
  PeriphClkInitStruct.PLL2.PLL2FRACN = 0;
  // PLL 3
  PeriphClkInitStruct.PLL3.PLL3M = 6;
  PeriphClkInitStruct.PLL3.PLL3N = 295;
  PeriphClkInitStruct.PLL3.PLL3P = 64; // 12.29Mhz
  PeriphClkInitStruct.PLL3.PLL3Q = 4;
  PeriphClkInitStruct.PLL3.PLL3R = 32; // 24.xMhz
  PeriphClkInitStruct.PLL3.PLL3RGE = RCC_PLL3VCIRANGE_1;
  PeriphClkInitStruct.PLL3.PLL3VCOSEL = RCC_PLL3VCOWIDE;
  PeriphClkInitStruct.PLL3.PLL3FRACN = 0;
  PeriphClkInitStruct.FmcClockSelection = RCC_FMCCLKSOURCE_PLL2;
  PeriphClkInitStruct.QspiClockSelection = RCC_QSPICLKSOURCE_D1HCLK;
  PeriphClkInitStruct.SdmmcClockSelection = RCC_SDMMCCLKSOURCE_PLL;
  PeriphClkInitStruct.Sai1ClockSelection = RCC_SAI1CLKSOURCE_PLL3;
  PeriphClkInitStruct.Sai23ClockSelection = RCC_SAI23CLKSOURCE_PLL3;
  PeriphClkInitStruct.Spi123ClockSelection = RCC_SPI123CLKSOURCE_PLL2;
  PeriphClkInitStruct.Usart234578ClockSelection
    = RCC_USART234578CLKSOURCE_D2PCLK1;
  PeriphClkInitStruct.Usart16ClockSelection = RCC_USART16CLKSOURCE_D2PCLK2;
  PeriphClkInitStruct.I2c123ClockSelection = RCC_I2C123CLKSOURCE_D2PCLK1;
  PeriphClkInitStruct.I2c4ClockSelection = RCC_I2C4CLKSOURCE_PLL3;
  PeriphClkInitStruct.UsbClockSelection = RCC_USBCLKSOURCE_HSI48;
  PeriphClkInitStruct.AdcClockSelection = RCC_ADCCLKSOURCE_PLL3;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK) {
    Error_Handler();
  }
  /* Enable USB Voltage detector */
  HAL_PWREx_EnableUSBVoltageDetector();
}

#ifdef __cplusplus
}
#endif
