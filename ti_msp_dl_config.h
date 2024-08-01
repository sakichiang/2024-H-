/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0L130X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0L130X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for PWM */
#define PWM_INST                                                           TIMG1
#define PWM_INST_IRQHandler                                     TIMG1_IRQHandler
#define PWM_INST_INT_IRQN                                       (TIMG1_INT_IRQn)
#define PWM_INST_CLK_FREQ                                                 800000
/* GPIO defines for channel 0 */
#define GPIO_PWM_C0_PORT                                                   GPIOA
#define GPIO_PWM_C0_PIN                                           DL_GPIO_PIN_14
#define GPIO_PWM_C0_IOMUX                                        (IOMUX_PINCM15)
#define GPIO_PWM_C0_IOMUX_FUNC                       IOMUX_PINCM15_PF_TIMG1_CCP0
#define GPIO_PWM_C0_IDX                                      DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_C1_PORT                                                   GPIOA
#define GPIO_PWM_C1_PIN                                           DL_GPIO_PIN_27
#define GPIO_PWM_C1_IOMUX                                        (IOMUX_PINCM28)
#define GPIO_PWM_C1_IOMUX_FUNC                       IOMUX_PINCM28_PF_TIMG1_CCP1
#define GPIO_PWM_C1_IDX                                      DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG0)
#define TIMER_0_INST_IRQHandler                                 TIMG0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                            (39U)



/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_22
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_23
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM23)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM24)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM23_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM24_PF_UART0_TX
#define UART_0_BAUD_RATE                                                  (9600)
#define UART_0_IBRD_4_MHZ_9600_BAUD                                         (26)
#define UART_0_FBRD_4_MHZ_9600_BAUD                                          (3)





/* Defines for ADC_VOLTAGE */
#define ADC_VOLTAGE_INST                                                    ADC0
#define ADC_VOLTAGE_INST_IRQHandler                              ADC0_IRQHandler
#define ADC_VOLTAGE_INST_INT_IRQN                                (ADC0_INT_IRQn)
#define ADC_VOLTAGE_ADCMEM_ADC_CH1                            DL_ADC12_MEM_IDX_0
#define ADC_VOLTAGE_ADCMEM_ADC_CH1_REF           DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC_VOLTAGE_ADCMEM_ADC_CH1_REF_VOLTAGE                                      -1 // VDDA cannot be determined
#define ADC_VOLTAGE_ADCMEM_ADC_CH2                            DL_ADC12_MEM_IDX_1
#define ADC_VOLTAGE_ADCMEM_ADC_CH2_REF           DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC_VOLTAGE_ADCMEM_ADC_CH2_REF_VOLTAGE                                      -1 // VDDA cannot be determined
#define ADC_VOLTAGE_ADCMEM_ADC_CH3                            DL_ADC12_MEM_IDX_2
#define ADC_VOLTAGE_ADCMEM_ADC_CH3_REF           DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC_VOLTAGE_ADCMEM_ADC_CH3_REF_VOLTAGE                                      -1 // VDDA cannot be determined
#define ADC_VOLTAGE_ADCMEM_ADC_CH5                            DL_ADC12_MEM_IDX_3
#define ADC_VOLTAGE_ADCMEM_ADC_CH5_REF           DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC_VOLTAGE_ADCMEM_ADC_CH5_REF_VOLTAGE                                      -1 // VDDA cannot be determined
#define GPIO_ADC_VOLTAGE_C1_PORT                                           GPIOA
#define GPIO_ADC_VOLTAGE_C1_PIN                                   DL_GPIO_PIN_26
#define GPIO_ADC_VOLTAGE_C2_PORT                                           GPIOA
#define GPIO_ADC_VOLTAGE_C2_PIN                                   DL_GPIO_PIN_25
#define GPIO_ADC_VOLTAGE_C3_PORT                                           GPIOA
#define GPIO_ADC_VOLTAGE_C3_PIN                                   DL_GPIO_PIN_24
#define GPIO_ADC_VOLTAGE_C5_PORT                                           GPIOA
#define GPIO_ADC_VOLTAGE_C5_PIN                                   DL_GPIO_PIN_21



/* Port definition for Pin Group KEY */
#define KEY_PORT                                                         (GPIOA)

/* Defines for PIN_18: GPIOA.18 with pinCMx 19 on package pin 22 */
// pins affected by this interrupt request:["PIN_18"]
#define KEY_INT_IRQN                                            (GPIOA_INT_IRQn)
#define KEY_INT_IIDX                            (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define KEY_PIN_18_IIDX                                     (DL_GPIO_IIDX_DIO18)
#define KEY_PIN_18_PIN                                          (DL_GPIO_PIN_18)
#define KEY_PIN_18_IOMUX                                         (IOMUX_PINCM19)
/* Port definition for Pin Group AIN1 */
#define AIN1_PORT                                                        (GPIOA)

/* Defines for PIN_5: GPIOA.5 with pinCMx 6 on package pin 9 */
#define AIN1_PIN_5_PIN                                           (DL_GPIO_PIN_5)
#define AIN1_PIN_5_IOMUX                                          (IOMUX_PINCM6)
/* Port definition for Pin Group AIN2 */
#define AIN2_PORT                                                        (GPIOA)

/* Defines for PIN_6: GPIOA.6 with pinCMx 7 on package pin 10 */
#define AIN2_PIN_6_PIN                                           (DL_GPIO_PIN_6)
#define AIN2_PIN_6_IOMUX                                          (IOMUX_PINCM7)
/* Port definition for Pin Group BIN1 */
#define BIN1_PORT                                                        (GPIOA)

/* Defines for PIN_3: GPIOA.3 with pinCMx 4 on package pin 7 */
#define BIN1_PIN_3_PIN                                           (DL_GPIO_PIN_3)
#define BIN1_PIN_3_IOMUX                                          (IOMUX_PINCM4)
/* Port definition for Pin Group BIN2 */
#define BIN2_PORT                                                        (GPIOA)

/* Defines for PIN_4: GPIOA.4 with pinCMx 5 on package pin 8 */
#define BIN2_PIN_4_PIN                                           (DL_GPIO_PIN_4)
#define BIN2_PIN_4_IOMUX                                          (IOMUX_PINCM5)
/* Port definition for Pin Group start */
#define start_PORT                                                       (GPIOA)

/* Defines for PIN_15: GPIOA.15 with pinCMx 16 on package pin 19 */
#define start_PIN_15_PIN                                        (DL_GPIO_PIN_15)
#define start_PIN_15_IOMUX                                       (IOMUX_PINCM16)
/* Port definition for Pin Group LED */
#define LED_PORT                                                         (GPIOA)

/* Defines for PIN_17: GPIOA.17 with pinCMx 18 on package pin 21 */
#define LED_PIN_17_PIN                                          (DL_GPIO_PIN_17)
#define LED_PIN_17_IOMUX                                         (IOMUX_PINCM18)
/* Port definition for Pin Group MODE1 */
#define MODE1_PORT                                                       (GPIOA)

/* Defines for PIN_13: GPIOA.13 with pinCMx 14 on package pin 17 */
#define MODE1_PIN_13_PIN                                        (DL_GPIO_PIN_13)
#define MODE1_PIN_13_IOMUX                                       (IOMUX_PINCM14)
/* Port definition for Pin Group MODE2 */
#define MODE2_PORT                                                       (GPIOA)

/* Defines for PIN_16: GPIOA.16 with pinCMx 17 on package pin 20 */
#define MODE2_PIN_16_PIN                                        (DL_GPIO_PIN_16)
#define MODE2_PIN_16_IOMUX                                       (IOMUX_PINCM17)
/* Port definition for Pin Group OLED */
#define OLED_PORT                                                        (GPIOA)

/* Defines for SCL: GPIOA.0 with pinCMx 1 on package pin 1 */
#define OLED_SCL_PIN                                             (DL_GPIO_PIN_0)
#define OLED_SCL_IOMUX                                            (IOMUX_PINCM1)
/* Defines for SDA: GPIOA.1 with pinCMx 2 on package pin 2 */
#define OLED_SDA_PIN                                             (DL_GPIO_PIN_1)
#define OLED_SDA_IOMUX                                            (IOMUX_PINCM2)
/* Port definition for Pin Group WAY */
#define WAY_PORT                                                         (GPIOA)

/* Defines for PIN_12: GPIOA.12 with pinCMx 13 on package pin 16 */
#define WAY_PIN_12_PIN                                          (DL_GPIO_PIN_12)
#define WAY_PIN_12_IOMUX                                         (IOMUX_PINCM13)
/* Defines for PIN_10: GPIOA.10 with pinCMx 11 on package pin 14 */
#define WAY_PIN_10_PIN                                          (DL_GPIO_PIN_10)
#define WAY_PIN_10_IOMUX                                         (IOMUX_PINCM11)
/* Defines for PIN_9: GPIOA.9 with pinCMx 10 on package pin 13 */
#define WAY_PIN_9_PIN                                            (DL_GPIO_PIN_9)
#define WAY_PIN_9_IOMUX                                          (IOMUX_PINCM10)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_ADC_VOLTAGE_init(void);

void SYSCFG_DL_SYSTICK_init(void);


#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
