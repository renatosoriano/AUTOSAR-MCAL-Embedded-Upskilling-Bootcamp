/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : DMA,CACHE,TRGMUX,FLEXIO
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
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef FLEXIO_MCL_IP_CFG_DEFINES_H_
#define FLEXIO_MCL_IP_CFG_DEFINES_H_

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "BasicTypes.h"

#include "Flexio_Uart_Ip_CfgDefines.h"
#if defined(UART_CHANNEL_0_USED) || defined(UART_CHANNEL_1_USED) || defined(UART_CHANNEL_2_USED) || defined(UART_CHANNEL_3_USED)|| defined(UART_CHANNEL_4_USED) || defined(UART_CHANNEL_5_USED) || defined(UART_CHANNEL_6_USED) || defined(UART_CHANNEL_7_USED)
    #define USE_UART_MODULE
#endif

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_MCL_IP_CFG_DEFINES_VENDOR_ID                    43
#define FLEXIO_MCL_IP_CFG_DEFINES_MODULE_ID                    255
#define FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_MCL_IP_CFG_DEFINES_SW_MAJOR_VERSION             2
#define FLEXIO_MCL_IP_CFG_DEFINES_SW_MINOR_VERSION             0
#define FLEXIO_MCL_IP_CFG_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if header file and StandardTypes header file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Cfg_Defines.h and StandardTypes.h are different"
#endif

#ifdef USE_I2C_MODULE
/* Check if header file and Flexio_I2c_Ip_CfgDefines header file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != FLEXIO_I2C_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != FLEXIO_I2C_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Cfg_Defines.h and Flexio_I2c_Ip_CfgDefines.h are different"
#endif
#endif /* USE_I2C_MODULE */

#ifdef USE_I2S_MODULE
/* Check if header file and Flexio_I2s_Ip_CfgDefines header file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != FLEXIO_I2S_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != FLEXIO_I2S_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Cfg_Defines.h and Flexio_I2s_Ip_CfgDefines.h are different"
#endif
#endif /* USE_I2S_MODULE */

#ifdef USE_SPI_MODULE
/* Check if header file and Flexio_Spi_Ip_CfgDefines header file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != FLEXIO_SPI_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != FLEXIO_SPI_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Cfg_Defines.h and Flexio_Spi_Ip_CfgDefines.h are different"
#endif
#endif /* USE_SPI_MODULE */

#ifdef USE_UART_MODULE
/* Check if header file and Flexio_Uart_Ip_CfgDefines header file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != FLEXIO_UART_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != FLEXIO_UART_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Cfg_Defines.h and Flexio_Uart_Ip_CfgDefines.h are different"
#endif
#endif /* USE_UART_MODULE */

#ifdef USE_PWM_MODULE
/* Check if header file and Flexio_Pwm_Ip_CfgDefines header file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Cfg_Defines.h and Flexio_Pwm_Ip_CfgDefines.h are different"
#endif
#endif /* USE_PWM_MODULE */

#ifdef USE_LIN_MODULE
/* Check if header file and Flexio_Lin_Ip_CfgDefines header file are of the same Autosar version */
#if ((FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION != FLEXIO_LIN_IP_CFG_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_MCL_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION != FLEXIO_LIN_IP_CFG_DEFINES_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Flexio_Mcl_Ip_Cfg_Defines.h and Flexio_Lin_Ip_CfgDefines.h are different"
#endif
#endif /* USE_LIN_MODULE */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/* Enable/Disable Flexio support from MCL. */
#define FLEXIO_IP_IS_AVAILABLE                      STD_ON

#define FLEXIO_MCL_IP_DEV_ERROR_DETECT        STD_OFF
#define FLEXIO_MCL_IP_TIMERSDEN_IS_AVAILABLE  STD_OFF
#define FLEXIO_MCL_IP_PIN_STS_IS_AVAILABLE    STD_OFF

/*-----------------------------------------------/
/  FLEXIO HARDWARE INSTANCES                        /
/-----------------------------------------------*/
#define FLEXIO_0                        ((uint8)(0U))

/*-----------------------------------------------/
/  FLEXIO HARDWARE CHANNELS                         /
/-----------------------------------------------*/
#define CHANNEL_0                       ((uint8)(0U))
#define CHANNEL_1                       ((uint8)(1U))
#define CHANNEL_2                       ((uint8)(2U))
#define CHANNEL_3                       ((uint8)(3U))

/*-----------------------------------------------/
/  FLEXIO PINS                                   /
/-----------------------------------------------*/
#define PIN_0                           ((uint8)(0U))
#define PIN_1                           ((uint8)(1U))
#define PIN_2                           ((uint8)(2U))
#define PIN_3                           ((uint8)(3U))
#define PIN_4                           ((uint8)(4U))
#define PIN_5                           ((uint8)(5U))
#define PIN_6                           ((uint8)(6U))
#define PIN_7                           ((uint8)(7U))


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* FLEXIO_MCL_IP_CFG_DEFINES_H_ */
