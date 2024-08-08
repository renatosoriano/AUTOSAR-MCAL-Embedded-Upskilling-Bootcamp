/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : PORT_CI
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   Copyright 2020-2024 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

/**
*   @file    Port_Cfg.c
*
*   @addtogroup Port_CFG
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/
#include "Port.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module's description file
* @details      The integration of incompatible files shall be avoided.
*
*/
#define PORT_VENDOR_ID_CFG_C                       43
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG_C        4
#define PORT_AR_RELEASE_MINOR_VERSION_CFG_C        7
#define PORT_AR_RELEASE_REVISION_VERSION_CFG_C     0
#define PORT_SW_MAJOR_VERSION_CFG_C                2
#define PORT_SW_MINOR_VERSION_CFG_C                0
#define PORT_SW_PATCH_VERSION_CFG_C                0

/*=================================================================================================
*                                      FILE VERSION CHECKS
=================================================================================================*/
/* Check if the files Port_Cfg.c and Port.h are of the same vendor */
#if (PORT_VENDOR_ID_CFG_C != PORT_VENDOR_ID)
    #error "Port_Cfg.c and Port.h have different vendor ids"
#endif
/* Check if the files Port_Cfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_C    != PORT_AR_RELEASE_MAJOR_VERSION)  || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_C    != PORT_AR_RELEASE_MINOR_VERSION)  || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_C != PORT_AR_RELEASE_REVISION_VERSION)  \
    )
    #error "AutoSar Version Numbers of Port_Cfg.c and Port.h are different"
#endif
/* Check if the files Port_Cfg.c and Port.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_CFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_CFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_Cfg.c and Port.h are different"
#endif

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/

#define PORT_START_SEC_CONST_16
#include "Port_MemMap.h"

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief Port Pin description data
*/
const uint16 Port_au16PinDescription[8][9] =
{
            

    /*  Mode PORT_ALT0_FUNC_MODE: */
    {
        /* Pads   0 ...  15 : PORT0_ADC0_SE0_CMP0_IN0 |
         PORT1_ADC0_SE1_CMP0_IN1 |
         PORT2_ADC1_SE0 |
         PORT3_ADC1_SE1 |
         PORT4_DISABLED |
         PORT5_DISABLED |
         PORT7_ADC0_SE3 |
         PORT10_DISABLED |
         PORT11_DISABLED |
         PORT12_DISABLED |
         PORT13_DISABLED */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(4) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(7) |
                  SHL_PAD_U16(10) |
                  SHL_PAD_U16(11) |
                  SHL_PAD_U16(12) |
                  SHL_PAD_U16(13)
                ),
        /* Pads 16 ... 31 */
        (uint16)0x0000,
        /* Pads  32 ...  47 : PORT32_ADC0_SE4_ADC1_SE14 |
         PORT33_ADC0_SE5_ADC1_SE15 |
         PORT34_ADC0_SE6 |
         PORT35_ADC0_SE7 |
         PORT36_DISABLED |
         PORT37_DISABLED |
         PORT38_XTAL |
         PORT39_EXTAL |
         PORT45_ADC1_SE8_ADC0_SE8 */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(4) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(6) |
                  SHL_PAD_U16(7) |
                  SHL_PAD_U16(13)
                ),
        /* Pads 48 ... 63 */
        (uint16)0x0000,
        /* Pads  64 ...  79 : PORT65_ADC0_SE9 |
         PORT66_ADC0_SE10_CMP0_IN5 |
         PORT67_ADC0_SE11_CMP0_IN4 |
         PORT68_CMP0_IN2 |
         PORT69_DISABLED |
         PORT70_ADC1_SE4 |
         PORT71_ADC1_SE5 |
         PORT72_DISABLED |
         PORT73_DISABLED |
         PORT78_ADC0_SE12 |
         PORT79_ADC0_SE13 */

        (uint16)( SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(4) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(6) |
                  SHL_PAD_U16(7) |
                  SHL_PAD_U16(8) |
                  SHL_PAD_U16(9) |
                  SHL_PAD_U16(14) |
                  SHL_PAD_U16(15)
                ),
        /* Pads  80 ...  95 : PORT80_ADC0_SE14 */

        (uint16)( SHL_PAD_U16(0)
                ),
        /* Pads  96 ... 111 : PORT96_DISABLED |
         PORT97_DISABLED |
         PORT98_ADC1_SE2 |
         PORT99_ADC1_SE3 |
         PORT101_DISABLED |
         PORT111_DISABLED */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(15)
                ),
        /* Pads 112 ... 127 : PORT112_DISABLED */

        (uint16)( SHL_PAD_U16(0)
                ),
        /* Pads 128 ... 143 : PORT132_DISABLED |
         PORT133_DISABLED |
         PORT136_CMP0_IN3 |
         PORT137_DISABLED */

        (uint16)( SHL_PAD_U16(4) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(8) |
                  SHL_PAD_U16(9)
                )
    }
    ,
    /*  Mode PORT_GPIO_MODE: */
    {
        /* Pads   0 ...  15 : PORT0_GPIO |
        PORT1_GPIO |
        PORT2_GPIO |
        PORT3_GPIO |
        PORT4_GPIO |
        PORT5_GPIO |
        PORT7_GPIO |
        PORT10_GPIO |
        PORT11_GPIO |
        PORT12_GPIO |
        PORT13_GPIO */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(4) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(7) |
                  SHL_PAD_U16(10) |
                  SHL_PAD_U16(11) |
                  SHL_PAD_U16(12) |
                  SHL_PAD_U16(13)
                ),
        /* Pads 16 ... 31 */
        (uint16)0x0000,
        /* Pads  32 ...  47 : PORT32_GPIO |
        PORT33_GPIO |
        PORT34_GPIO |
        PORT35_GPIO |
        PORT36_GPIO |
        PORT37_GPIO |
        PORT38_GPIO |
        PORT39_GPIO |
        PORT45_GPIO */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(4) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(6) |
                  SHL_PAD_U16(7) |
                  SHL_PAD_U16(13)
                ),
        /* Pads 48 ... 63 */
        (uint16)0x0000,
        /* Pads  64 ...  79 : PORT65_GPIO |
        PORT66_GPIO |
        PORT67_GPIO |
        PORT68_GPIO |
        PORT69_GPIO |
        PORT70_GPIO |
        PORT71_GPIO |
        PORT72_GPIO |
        PORT73_GPIO |
        PORT78_GPIO |
        PORT79_GPIO */

        (uint16)( SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(4) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(6) |
                  SHL_PAD_U16(7) |
                  SHL_PAD_U16(8) |
                  SHL_PAD_U16(9) |
                  SHL_PAD_U16(14) |
                  SHL_PAD_U16(15)
                ),
        /* Pads  80 ...  95 : PORT80_GPIO */

        (uint16)( SHL_PAD_U16(0)
                ),
        /* Pads  96 ... 111 : PORT96_GPIO |
        PORT97_GPIO |
        PORT98_GPIO |
        PORT99_GPIO |
        PORT101_GPIO |
        PORT111_GPIO */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(15)
                ),
        /* Pads 112 ... 127 : PORT112_GPIO */

        (uint16)( SHL_PAD_U16(0)
                ),
        /* Pads 128 ... 143 : PORT132_GPIO |
        PORT133_GPIO |
        PORT136_GPIO |
        PORT137_GPIO */

        (uint16)( SHL_PAD_U16(4) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(8) |
                  SHL_PAD_U16(9)
                )
    }
    ,
    /*  Mode PORT_ALT2_FUNC_MODE: */
    {
        /* Pads   0 ...  15 : PORT0_FTM2_CH1 |
         PORT1_FTM1_CH1 |
         PORT2_FTM3_CH0 |
         PORT3_FTM3_CH1 |
         PORT7_FTM0_FLT2 |
         PORT10_FTM1_CH4 |
         PORT11_FTM1_CH5 |
         PORT12_FTM1_CH6 |
         PORT13_FTM1_CH7 */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(7) |
                  SHL_PAD_U16(10) |
                  SHL_PAD_U16(11) |
                  SHL_PAD_U16(12) |
                  SHL_PAD_U16(13)
                ),
        /* Pads 16 ... 31 */
        (uint16)0x0000,
        /* Pads  32 ...  47 : PORT32_LPUART0_RX |
         PORT33_LPUART0_TX |
         PORT34_FTM1_CH0 |
         PORT35_FTM1_CH1 |
         PORT36_FTM0_CH4 |
         PORT37_FTM0_CH5 |
         PORT38_LPI2C0_SDA |
         PORT39_LPI2C0_SCL |
         PORT45_FTM0_CH1 */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(4) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(6) |
                  SHL_PAD_U16(7) |
                  SHL_PAD_U16(13)
                ),
        /* Pads 48 ... 63 */
        (uint16)0x0000,
        /* Pads  64 ...  79 : PORT65_FTM0_CH1 |
         PORT66_FTM0_CH2 |
         PORT67_FTM0_CH3 |
         PORT68_FTM1_CH0 |
         PORT69_FTM2_CH0 |
         PORT70_LPUART1_RX |
         PORT71_LPUART1_TX |
         PORT72_LPUART1_RX |
         PORT73_LPUART1_TX |
         PORT78_FTM1_CH2 |
         PORT79_FTM1_CH3 */

        (uint16)( SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(4) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(6) |
                  SHL_PAD_U16(7) |
                  SHL_PAD_U16(8) |
                  SHL_PAD_U16(9) |
                  SHL_PAD_U16(14) |
                  SHL_PAD_U16(15)
                ),
        /* Pads  80 ...  95 : PORT80_FTM1_FLT2 */

        (uint16)( SHL_PAD_U16(0)
                ),
        /* Pads  96 ... 111 : PORT96_FTM0_CH2 |
         PORT97_FTM0_CH3 |
         PORT98_FTM3_CH4 |
         PORT99_FTM3_CH5 |
         PORT101_FTM2_CH3 |
         PORT111_FTM0_CH0 */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(15)
                ),
        /* Pads 112 ... 127 : PORT112_FTM0_CH1 */

        (uint16)( SHL_PAD_U16(0)
                ),
        /* Pads 128 ... 143 : PORT133_TCLK2 |
         PORT136_FTM0_CH6 |
         PORT137_FTM0_CH7 */

        (uint16)( SHL_PAD_U16(5) |
                  SHL_PAD_U16(8) |
                  SHL_PAD_U16(9)
                )
    }
    ,
    /*  Mode PORT_ALT3_FUNC_MODE: */
    {
        /* Pads   0 ...  15 : PORT0_LPI2C0_SCLS |
         PORT1_LPI2C0_SDAS |
         PORT2_LPI2C0_SDA |
         PORT3_LPI2C0_SCL |
         PORT5_TCLK1 |
         PORT12_CAN1_RX |
         PORT13_CAN1_TX */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(12) |
                  SHL_PAD_U16(13)
                ),
        /* Pads 16 ... 31 */
        (uint16)0x0000,
        /* Pads  32 ...  47 : PORT32_LPSPI0_PCS0 |
         PORT33_LPSPI0_SOUT |
         PORT34_LPSPI0_SCK |
         PORT35_LPSPI0_SIN |
         PORT36_LPSPI0_SOUT |
         PORT37_LPSPI0_PCS1 |
         PORT45_FTM3_FLT1 */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(4) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(13)
                ),
        /* Pads 48 ... 63 */
        (uint16)0x0000,
        /* Pads  64 ...  79 : PORT65_LPSPI2_SOUT |
         PORT66_CAN0_RX |
         PORT67_CAN0_TX |
         PORT68_RTC_CLKOUT |
         PORT69_RTC_CLKOUT |
         PORT70_CAN1_RX |
         PORT71_CAN1_TX |
         PORT72_FTM1_FLT0 |
         PORT73_FTM1_FLT1 |
         PORT78_LPSPI2_PCS0 |
         PORT79_LPSPI2_SCK */

        (uint16)( SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(4) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(6) |
                  SHL_PAD_U16(7) |
                  SHL_PAD_U16(8) |
                  SHL_PAD_U16(9) |
                  SHL_PAD_U16(14) |
                  SHL_PAD_U16(15)
                ),
        /* Pads  80 ...  95 : PORT80_CAN2_RX */

        (uint16)( SHL_PAD_U16(0)
                ),
        /* Pads  96 ... 111 : PORT96_LPSPI1_SCK |
         PORT97_LPSPI1_SIN |
         PORT98_LPSPI1_SOUT |
         PORT99_LPSPI1_PCS0 |
         PORT101_LPTMR0_ALT2 */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(5)
                ),
        /* Pads 112 ... 127 */
        (uint16)0x0000,
        /* Pads 128 ... 143 : PORT132_FTM2_QD_PHB |
         PORT133_FTM2_QD_PHA |
         PORT137_LPUART2_CTS */

        (uint16)( SHL_PAD_U16(4) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(9)
                )
    }
    ,
    /*  Mode PORT_ALT4_FUNC_MODE: */
    {
        /* Pads   0 ...  15 : PORT0_FXIO_D2 |
         PORT1_FXIO_D3 |
         PORT2_EWM_OUT_B |
         PORT3_EWM_IN |
         PORT4_CMP0_OUT |
         PORT7_RTC_CLKIN |
         PORT10_FXIO_D0 |
         PORT11_FXIO_D1 */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(4) |
                  SHL_PAD_U16(7) |
                  SHL_PAD_U16(10) |
                  SHL_PAD_U16(11)
                ),
        /* Pads 16 ... 31 */
        (uint16)0x0000,
        /* Pads  32 ...  47 : PORT32_LPTMR0_ALT3 |
         PORT33_TCLK0 |
         PORT34_FTM1_QD_PHB |
         PORT35_FTM1_QD_PHA |
         PORT37_LPSPI0_PCS0 |
         PORT45_CAN2_TX */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(13)
                ),
        /* Pads 48 ... 63 */
        (uint16)0x0000,
        /* Pads  64 ...  79 : PORT66_LPUART0_RX |
         PORT67_LPUART0_TX |
         PORT70_FTM3_CH2 |
         PORT71_FTM3_CH3 */

        (uint16)( SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(6) |
                  SHL_PAD_U16(7)
                ),
        /* Pads 80 ... 95 */
        (uint16)0x0000,
        /* Pads  96 ... 111 : PORT96_FTM2_CH0 |
         PORT97_FTM2_CH1 |
         PORT98_FXIO_D4 |
         PORT99_FXIO_D5 |
         PORT101_FTM2_FLT1 |
         PORT111_LPSPI0_SCK */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(15)
                ),
        /* Pads 112 ... 127 : PORT112_LPSPI0_SIN */

        (uint16)( SHL_PAD_U16(0)
                ),
        /* Pads 128 ... 143 : PORT132_FTM2_CH2 |
         PORT133_FTM2_CH3 */

        (uint16)( SHL_PAD_U16(4) |
                  SHL_PAD_U16(5)
                )
    }
    ,
    /*  Mode PORT_ALT5_FUNC_MODE: */
    {
        /* Pads   0 ...  15 : PORT0_FTM2_QD_PHA |
         PORT1_FTM1_QD_PHA |
         PORT2_FXIO_D4 |
         PORT3_FXIO_D5 |
         PORT4_EWM_OUT_B |
         PORT11_CMP0_RRT */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(4) |
                  SHL_PAD_U16(11)
                ),
        /* Pads 16 ... 31 */
        (uint16)0x0000,
        /* Pads  32 ...  47 : PORT32_CAN0_RX |
         PORT33_CAN0_TX |
         PORT37_CLKOUT */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(5)
                ),
        /* Pads 48 ... 63 */
        (uint16)0x0000,
        /* Pads  64 ...  79 : PORT68_EWM_IN */

        (uint16)( SHL_PAD_U16(4)
                ),
        /* Pads 80 ... 95 */
        (uint16)0x0000,
        /* Pads  96 ... 111 : PORT98_FXIO_D6 |
         PORT99_FXIO_D7 */

        (uint16)( SHL_PAD_U16(2) |
                  SHL_PAD_U16(3)
                ),
        /* Pads 112 ... 127 : PORT112_CMP0_RRT */

        (uint16)( SHL_PAD_U16(0)
                ),
        /* Pads 128 ... 143 : PORT132_CAN0_RX |
         PORT133_CAN0_TX */

        (uint16)( SHL_PAD_U16(4) |
                  SHL_PAD_U16(5)
                )
    }
    ,
    /*  Mode PORT_ALT6_FUNC_MODE: */
    {
        /* Pads   0 ...  15 : PORT0_LPUART0_CTS |
         PORT1_LPUART0_RTS |
         PORT2_LPUART0_RX |
         PORT3_LPUART0_TX |
         PORT7_LPUART1_RTS |
         PORT12_FTM2_QD_PHB |
         PORT13_FTM2_QD_PHA */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(7) |
                  SHL_PAD_U16(12) |
                  SHL_PAD_U16(13)
                ),
        /* Pads 16 ... 31 */
        (uint16)0x0000,
        /* Pads  32 ...  47 : PORT34_TRGMUX_IN3 |
         PORT35_TRGMUX_IN2 |
         PORT36_TRGMUX_IN1 |
         PORT37_TRGMUX_IN0 */

        (uint16)( SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(4) |
                  SHL_PAD_U16(5)
                ),
        /* Pads 48 ... 63 */
        (uint16)0x0000,
        /* Pads  64 ...  79 : PORT65_FTM1_CH7 |
         PORT68_FTM1_QD_PHB |
         PORT69_FTM2_QD_PHB |
         PORT70_FTM1_QD_PHB |
         PORT71_FTM1_QD_PHA |
         PORT72_LPUART0_CTS |
         PORT73_LPUART0_RTS |
         PORT78_TRGMUX_IN9 |
         PORT79_TRGMUX_IN8 */

        (uint16)( SHL_PAD_U16(1) |
                  SHL_PAD_U16(4) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(6) |
                  SHL_PAD_U16(7) |
                  SHL_PAD_U16(8) |
                  SHL_PAD_U16(9) |
                  SHL_PAD_U16(14) |
                  SHL_PAD_U16(15)
                ),
        /* Pads 80 ... 95 */
        (uint16)0x0000,
        /* Pads  96 ... 111 : PORT96_FXIO_D0 |
         PORT97_FXIO_D1 |
         PORT98_TRGMUX_IN5 |
         PORT99_TRGMUX_IN4 |
         PORT101_TRGMUX_IN7 */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(2) |
                  SHL_PAD_U16(3) |
                  SHL_PAD_U16(5)
                ),
        /* Pads 112 ... 127 */
        (uint16)0x0000,
        /* Pads 128 ... 143 : PORT132_FXIO_D6 |
         PORT133_FXIO_D7 */

        (uint16)( SHL_PAD_U16(4) |
                  SHL_PAD_U16(5)
                )
    }
    ,
    /*  Mode PORT_ALT7_FUNC_MODE: */
    {
        /* Pads   0 ...  15 : PORT0_TRGMUX_OUT3 |
         PORT1_TRGMUX_OUT0 |
         PORT4_JTAG_TMS_SWD_DIO |
         PORT5_RESET_B |
         PORT10_JTAG_TDO_NOETM_TRACE_SWO */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(4) |
                  SHL_PAD_U16(5) |
                  SHL_PAD_U16(10)
                ),
        /* Pads 16 ... 31 */
        (uint16)0x0000,
        /* Pads 32 ... 47 */
        (uint16)0x0000,
        /* Pads 48 ... 63 */
        (uint16)0x0000,
        /* Pads  64 ...  79 : PORT68_JTAG_TCLK_SWD_CLK |
         PORT69_JTAG_TDI */

        (uint16)( SHL_PAD_U16(4) |
                  SHL_PAD_U16(5)
                ),
        /* Pads 80 ... 95 */
        (uint16)0x0000,
        /* Pads  96 ... 111 : PORT96_TRGMUX_OUT1 |
         PORT97_TRGMUX_OUT2 |
         PORT99_NMI_B */

        (uint16)( SHL_PAD_U16(0) |
                  SHL_PAD_U16(1) |
                  SHL_PAD_U16(3)
                ),
        /* Pads 112 ... 127 */
        (uint16)0x0000,
        /* Pads 128 ... 143 : PORT132_EWM_OUT_B |
         PORT133_EWM_IN */

        (uint16)( SHL_PAD_U16(4) |
                  SHL_PAD_U16(5)
                )
    }


    };
#endif

#define PORT_STOP_SEC_CONST_16
#include "Port_MemMap.h"
/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/

/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

/* End of File */
