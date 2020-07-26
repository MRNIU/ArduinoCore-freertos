/* SYS_WKUP */
#ifdef PWR_WAKEUP_PIN1
  SYS_WKUP1 = PA_0, /* SYS_WKUP0 */
#endif
#ifdef PWR_WAKEUP_PIN2
  SYS_WKUP2 = PA_2, /* SYS_WKUP1 */
#endif
#ifdef PWR_WAKEUP_PIN3
  SYS_WKUP3 = PC_13, /* SYS_WKUP2 */
#endif
#ifdef PWR_WAKEUP_PIN4
  SYS_WKUP4 = PI_8, /* SYS_WKUP3 */
#endif
#ifdef PWR_WAKEUP_PIN5
  SYS_WKUP5 = PI_11, /* SYS_WKUP4 */
#endif
#ifdef PWR_WAKEUP_PIN6
  SYS_WKUP6 = PC_1, /* SYS_WKUP5 */
#endif
#ifdef PWR_WAKEUP_PIN7
  SYS_WKUP7 = NC,
#endif
#ifdef PWR_WAKEUP_PIN8
  SYS_WKUP8 = NC,
#endif

  // STDIO for console print
#ifdef MBED_CONF_TARGET_STDIO_UART_TX
  STDIO_UART_TX = MBED_CONF_TARGET_STDIO_UART_TX,
#else
  STDIO_UART_TX = PA_9,
#endif
#ifdef MBED_CONF_TARGET_STDIO_UART_RX
  STDIO_UART_RX = MBED_CONF_TARGET_STDIO_UART_RX,
#else
  STDIO_UART_RX = PA_10,
#endif

  USBTX = STDIO_UART_TX, // used for greentea tests
  USBRX = STDIO_UART_RX, // used for greentea tests

  // I2C signals aliases
  I2C_SDA = D14,
  I2C_SCL = D15,

  // SPI signals aliases
  SPI_CS   = D10,
  SPI_MOSI = D11,
  SPI_MISO = D12,
  SPI_SCK  = D13,

  // Standardized LED and button names
  LED1  = PI_12, // LED1  // Green
  LED2  = PI_13, // LED2  // Orange
  LED3  = PI_14, // LED3  // Red
  LED4  = PI_15, // LED4  // Blue
  BUTTON1 = PC_13, // B2 [Wakeup Button]

  // Backward legacy names
  USER_BUTTON = BUTTON1,
  PWM_OUT = D3,

  /**** USB FS pins ****/
  USB_OTG_FS_DM = PA_11,
  USB_OTG_FS_DP = PA_12,
  USB_OTG_FS_ID = PA_10,
  USB_OTG_FS_SOF = PA_8,
  USB_OTG_FS_VBUS = PA_9,

  /**** USB HS pins ****/
  USB_OTG_HS_DM = PB_14,
  USB_OTG_HS_DP = PB_15,
  USB_OTG_HS_ID = PB_12,
  USB_OTG_HS_SOF = PA_4,
  USB_OTG_HS_ULPI_CK = PA_5,
  USB_OTG_HS_ULPI_D0 = PA_3,
  USB_OTG_HS_ULPI_D1 = PB_0,
  USB_OTG_HS_ULPI_D2 = PB_1,
  USB_OTG_HS_ULPI_D3 = PB_10,
  USB_OTG_HS_ULPI_D4 = PB_11,
  USB_OTG_HS_ULPI_D5 = PB_12,
  USB_OTG_HS_ULPI_D6 = PB_13,
  USB_OTG_HS_ULPI_D7 = PB_5,
  USB_OTG_HS_ULPI_DIR = PC_2,
  USB_OTG_HS_ULPI_DIR_ALT0 = PI_11,
  USB_OTG_HS_ULPI_NXT = PC_3,
  USB_OTG_HS_ULPI_NXT_ALT0 = PH_4,
  USB_OTG_HS_ULPI_STP = PC_0,
  USB_OTG_HS_VBUS = PB_13,

  /**** ETHERNET pins ****/
  ETH_COL = PH_3,
  ETH_COL_ALT0 = PA_3,
  ETH_CRS = PH_2,
  ETH_CRS_ALT0 = PA_0,
  ETH_CRS_DV = PA_7,
  ETH_MDC = PC_1, /* not default HW - need SB8 on/SB21 off */
  ETH_MDIO = PA_2,
  ETH_PPS_OUT = PB_5,
  ETH_PPS_OUT_ALT0 = PG_8,
  ETH_REF_CLK = PA_1,
  ETH_RXD0 = PC_4,
  ETH_RXD1 = PC_5,
  ETH_RXD2 = PH_6,
  ETH_RXD2_ALT0 = PB_0,
  ETH_RXD3 = PB_1,
  ETH_RXD3_ALT0 = PH_7,
  ETH_RX_CLK = PA_1,
  ETH_RX_DV = PA_7,
  ETH_RX_ER = PI_10,
  ETH_RX_ER_ALT0 = PB_10,
  ETH_TXD0 = PG_13,
  ETH_TXD0_ALT0 = PB_12,
  ETH_TXD1 = PG_12,
  ETH_TXD1_ALT0 = PG_14,
  ETH_TXD1_ALT1 = PB_13,
  ETH_TXD2 = PC_2,
  ETH_TXD3 = PE_2,
  ETH_TXD3_ALT0 = PB_8,
  ETH_TX_CLK = PC_3,
  ETH_TX_EN = PG_11,
  ETH_TX_EN_ALT0 = PB_11,

  /**** QSPI FLASH pins ****/
  QSPI_FLASH1_IO0 = PD_11,
  QSPI_FLASH1_IO1 = PF_9,
  QSPI_FLASH1_IO2 = PF_7,
  QSPI_FLASH1_IO3 = PF_6,
  QSPI_FLASH1_SCK = PB_2,
  QSPI_FLASH1_CSN = PG_6,

  /**** OSCILLATOR pins ****/
  RCC_OSC32_IN = PC_14,
  RCC_OSC32_OUT = PC_15,
  RCC_OSC_IN = PH_0,
  RCC_OSC_OUT = PH_1,

  /**** DEBUG pins ****/
  DEBUG_JTCK_SWCLK = PA_14,
  DEBUG_JTDI = PA_15,
  DEBUG_JTDO_SWO = PB_3,
  DEBUG_JTMS_SWDIO = PA_13,
  DEBUG_JTRST = PB_4,
  DEBUG_TRACECLK = PE_2,
  DEBUG_TRACED0 = PE_3,
  DEBUG_TRACED0_ALT0 = PG_13,
  DEBUG_TRACED0_ALT1 = PC_1,
  DEBUG_TRACED1 = PE_4,
  DEBUG_TRACED1_ALT0 = PG_14,
  DEBUG_TRACED1_ALT1 = PC_8,
  DEBUG_TRACED2 = PE_5,
  DEBUG_TRACED2_ALT0 = PD_2,
  DEBUG_TRACED3 = PC_12,
  DEBUG_TRACED3_ALT0 = PE_6,
  DEBUG_TRGIN = PJ_7,
  DEBUG_TRGIO = PC_7,
  DEBUG_TRGOUT = PJ_12,
  PWR_PVD_IN = PB_7,
  PWR_WKUP0 = PA_0,
  PWR_WKUP1 = PA_2,
  PWR_WKUP2 = PC_13,
  PWR_WKUP3 = PI_8,
  PWR_WKUP4 = PI_11,
  PWR_WKUP5 = PC_1,

  /**** STMOD+ pins ****/
#ifdef STMOD_UART_SOLDERBRIDGE
  STMOD_1  = PA_0,
  STMOD_2  = PD_5,
  STMOD_3  = PD_6,
  STMOD_4  = PD_4,
#else /* default HW configuration */
  STMOD_1  = PA_11,
  STMOD_2  = PC_3,
  STMOD_3  = PC_2,
  STMOD_4  = PA_12,
#endif /* STMOD_UART_SOLDERBRIDGE */
//  STMOD_5 is connected to GND
//  STMOD_6 is connected to +5V
  STMOD_7  = PD_12,
  STMOD_8  = PB_15,
  STMOD_9  = PB_14,
  STMOD_10 = PD_13,
  STMOD_11 = PC_6,
  STMOD_12 = PJ_13,
  STMOD_13 = PA_4,
  STMOD_14 = PF_8,
//  STMOD_15 is connected to +5V
//  STMOD_16 is connected to GND
  STMOD_17 = PC_7,
  STMOD_18 = PD_3,
  STMOD_19 = PB_9,
  STMOD_20 = PB_8,

  /**** PMOD pins ****/
  PMOD_1  = STMOD_1,
  PMOD_2  = STMOD_2,
  PMOD_3  = STMOD_3,
  PMOD_4  = STMOD_4,
//  PMOD_5 is connected to GND
//  PMOD_6 is connected to +3V3
  PMOD_7  = STMOD_11,
  PMOD_8  = STMOD_12,
//  PMOD_9 is not connected
//  PMOD_10 is not connected
//  PMOD_11 is connected to GND
//  PMOD_12 is connected to +3V3

#endif
