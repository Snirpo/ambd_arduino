/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/* u-blox NORA-W30 (RTL8720DF) */

#ifndef _VARIANT_ARDUINO_AMEBA_
#define _VARIANT_ARDUINO_AMEBA_

#include "Arduino.h"
#include <stdarg.h>

#ifdef __cplusplus
extern "C"{
#include "PinNames.h"

#define portOutputRegister(P) ((volatile uint32_t *)(0x48014000 + (P) * 0x400))
#define portInputRegister(P)  ((volatile uint32_t *)(0x48014050 + (P) * 0x400))
#define portModeRegister(P)   ((volatile uint32_t *)(0x48014004 + (P) * 0x400))

/*
 * Wait until enter debug mode
 *
 * Check DHCSR(0xE000EDF0) register and hold until bit C_DEBUGEN is set.
 * Use this function along with J-LINK or other debug tool
 **/
extern void wait_for_debug(void);
}
#endif

#define MAIN_THREAD_STACK_SIZE                  (4096 * 4)

#define TOTAL_GPIO_PIN_NUM                      (20)
#define TOTAL_PWM_PIN_NUM                       (12)

/* Digital pin mapping refer to g_APinDescription */
//               index into g_APinDescription --v     AMEBA   NORA      Function
#define EVK_D0                                  17 // PB_18   NORA_G9   UART_RXD
#define EVK_D1                                  16 // PB_19   NORA_G8   UART_TXD
#define EVK_D2                                  19 // PB_20   NORA_F9   I2C_SCL / UART_CTS
#define EVK_D3                                  18 // PB_21   NORA_F8   I2C_SDA / UART_RTS
//      EVK_D4 .. D8                            NC
#define EVK_D9                                  5  // PA_28   NORA_B3   SPI_CS
#define EVK_D10                                 7  // PA_25   NORA_C2   SPI_MOSI
#define EVK_D11                                 6  // PA_26   NORA_C1   SPI_MISO
#define EVK_D12                                 4  // PA_30   NORA_B1   SPI_SCLK
//      EVK_D13                                 NC
#define EVK_D14                                 12 // PA_7    NORA_A5   DBG_TX 
#define EVK_D15                                 13 // PA_8    NORA_A6   DBG_RX
#define EVK_D16                                 1  // PA_14   NORA_H9   LED_BLUE
#define EVK_D17                                 0  // PA_15   NORA_H8   LED_GREEN
#define EVK_D18                                 3  // PA_12   NORA_J9
#define EVK_D19                                 2  // PA_13   NORA_J8   LED_RED
// Analog pin mapping
#define A0                                      9  // PB_3    NORA_J2
#define A1                                      11 // PB_1    NORA_D8   SW1
#define A2                                      8  // PA_27   NORA_H2
#define A3                                      14 // PB_23   NORA_C8   SW2
#define A4                                      15 // PB_22   NORA_E9   UART_DSR
#define A5                                      10 // PB_2    NORA_E8   UART_DTR

// NORA-W30 module pad names
#define NORA_A5                                 12 // PA_7    NORA_A5   DBG_TX 
#define NORA_A6                                 13 // PA_8    NORA_A6   DBG_RX
#define NORA_B1                                 4  // PA_30   NORA_B1   SPI_SCLK
#define NORA_B3                                 5  // PA_28   NORA_B3   SPI_CS
#define NORA_C1                                 6  // PA_26   NORA_C1   SPI_MISO
#define NORA_C2                                 7  // PA_25   NORA_C2   SPI_MOSI
#define NORA_C8                                 14 // PB_23   NORA_C8   SW2
#define NORA_D8                                 11 // PB_1    NORA_D8   SW1
#define NORA_E8                                 10 // PB_2    NORA_E8   UART_DTR
#define NORA_E9                                 15 // PB_22   NORA_E9   UART_DSR
#define NORA_F8                                 18 // PB_21   NORA_F8   I2C_SDA / UART_RTS
#define NORA_F9                                 19 // PB_20   NORA_F9   I2C_SCL / UART_CTS
#define NORA_G8                                 16 // PB_19   NORA_G8   UART_TXD
#define NORA_G9                                 17 // PB_18   NORA_G9   UART_RXD
#define NORA_H2                                 8  // PA_27   NORA_H2
#define NORA_H8                                 0  // PA_15   NORA_H8   LED_GREEN
#define NORA_H9                                 1  // PA_14   NORA_H9   LED_BLUE
#define NORA_J2                                 9  // PB_3    NORA_J2
#define NORA_J8                                 2  // PA_13   NORA_J8   LED_RED
#define NORA_J9                                 3  // PA_12   NORA_J9

/* LED pin mapping */
#define LED_BUILTIN                             1  // PA_14
#define LED_RED                                 2  // PA_13
#define LED_GREEN                               0  // PA_15
#define LED_BLUE                                1  // PA_14

/* ADC/DAC pin mapping */
#define FEATURE_ADC
//#define FEATURE_DAC

/* SPI pin mapping */
#define SPI_SS                                  5  // PA_28
#define SPI_MOSI                                7  // PA_25
#define SPI_MISO                                6  // PA_26
#define SPI_SCLK                                4  // PA_30

/* TwoWire/I2C pin mapping */
#define I2C_SDA                                 18 // PB_21
#define I2C_SCL                                 19 // PB_20

/* UART pin mapping */
#define LOG_UART_MODIFIABLE_BAUD_RATE           1
#define SERIAL_ONE_UART_MODIFIABLE_BAUD_RATE    1
#define SERIAL_TWO_UART_MODIFIABLE_BAUD_RATE    1
#define LOG_TX                                  12 // PA_7
#define LOG_RX                                  13 // PA_8
#define SERIAL1_TX                              16 // PB_19
#define SERIAL1_RX                              17 // PB_18
#define SERIAL2_TX                              3  // PA_12
#define SERIAL2_RX                              2  // PA_13

#endif /* _VARIANT_ARDUINO_AMEBA_ */
