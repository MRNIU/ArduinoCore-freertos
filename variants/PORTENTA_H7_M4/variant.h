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

#ifndef _VARIANT_ARDUINO_STM32_
#define _VARIANT_ARDUINO_STM32_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/
#define PH15 0
#define PK1  1
#define PJ11 2
#define PG7  3
#define PC7  4
#define PC6  5
#define PA8  6
#define PI0  7
#define PC3  8
#define PI1  9
#define PC2  10
#define PH8  11
#define PH7  12
#define PA10 13
#define PA9  14
#define PA0CALT2  15
#define PA1CALT0  16
#define PC2CALT0  17
#define PC3C       18
#define PC2ALT0    19
#define PC3ALT2    20
#define PA4        21
#define PK5  22
#define PK6  23
#define PK7  24

// This must be a literal
#define NUM_DIGITAL_PINS        22
// This must be a literal
#define NUM_ANALOG_INPUTS       7

// On-board LED pin number
#define LED_BUILTIN             23

// SPI Definitions
#define PIN_SPI_SS              7
#define PIN_SPI_MOSI            8
#define PIN_SPI_MISO            10
#define PIN_SPI_SCK             9

// I2C Definitions
#define PIN_WIRE_SDA            11
#define PIN_WIRE_SCL            12

// I2C timing definitions (optional), avoid time spent to compute if defined
#define I2C_TIMING_SM           0x30E0628A
#define I2C_TIMING_FM           0x20D01132
#define I2C_TIMING_FMP          0x1080091A

// Timer Definitions
// Use TIM6/TIM7 when possible as servo and tone don't need GPIO output pin
#define TIMER_TONE              TIM6
#define TIMER_SERVO             TIM7

// UART Definitions
#define SERIAL_UART_INSTANCE    1

// Serial pin used for console
// Required by Firmata
#define PIN_SERIAL_RX           13
#define PIN_SERIAL_TX           14

// HSE is 16MHz on Daisy Seed.
#define HSE_VALUE 16000000

/* Extra HAL modules */
#define HAL_DAC_MODULE_ENABLED

#ifdef __cplusplus
} // extern "C"
#endif
/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus
  // These serial port names are intended to allow libraries and architecture-neutral
  // sketches to automatically default to the correct port name for a particular type
  // of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
  // the first hardware serial port whose RX/TX pins are not dedicated to another use.
  //
  // SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
  //
  // SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
  //
  // SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
  //
  // SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
  //
  // SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
  //                            pins are NOT connected to anything by default.
  #define SERIAL_PORT_MONITOR     Serial
  #define SERIAL_PORT_HARDWARE    Serial
#endif

#endif /* _VARIANT_ARDUINO_STM32_ */
