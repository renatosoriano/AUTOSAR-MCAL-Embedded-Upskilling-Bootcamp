/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : I2S
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

#ifndef FLEXIO_I2S_IP_CFGDEFINES_H
#define FLEXIO_I2S_IP_CFGDEFINES_H

/**
*   @file
*
*   @addtogroup flexio_i2s_config Flexio_I2s IPL Configuration
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "OsIf.h"
#include "S32K144_FLEXIO.h"


/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_I2S_IP_CFGDEFINES_VENDOR_ID                    43
#define FLEXIO_I2S_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_I2S_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_I2S_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_I2S_IP_CFGDEFINES_SW_MAJOR_VERSION             2
#define FLEXIO_I2S_IP_CFGDEFINES_SW_MINOR_VERSION             0
#define FLEXIO_I2S_IP_CFGDEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if current file and StandardTypes header file are of the same Autosar version */
#if ((FLEXIO_I2S_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_I2S_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Flexio_I2s_Ip_CfgDefines.h and StandardTypes.h are different"
#endif

/* Check if current file and OsIf header file are of the same Autosar version */
#if ((FLEXIO_I2S_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_I2S_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
#error "AutoSar Version Numbers of Flexio_I2s_Ip_CfgDefines.h and OsIf.h are different"
#endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

#define FLEXIO_I2S_IP_ENABLE                     (STD_ON)
#define FLEXIO_I2S_IP_DEV_ERROR_DETECT           (STD_ON)
#define FLEXIO_I2S_IP_TIMEOUT_TYPE               (OSIF_COUNTER_DUMMY)
#define FLEXIO_I2S_IP_INTERNAL_TIMEOUT_VALUE     (50000U)
#define FLEXIO_I2S_IP_INSTANCE_COUNT             (1U)
#define FLEXIO_I2S_IP_DMA_FEATURE_AVAILABLE      (STD_OFF)
#define FLEXIO_I2S_IP_MAX_CHANNEL_COUNT          (4U)
#define FLEXIO_I2S_IP_NUMBER_OF_CHANNEL          (1U)


/* Macros that indicate FLEXIO channels used by I2S */
#ifndef FLEXIO_0_CH_0_USED
    #define FLEXIO_0_CH_0_USED
#else
    #error "CHANNEL_0 cannot be used by I2S driver. Channel locked by another driver"
#endif

#ifdef FLEXIO_0_CH_0_USED
    #define I2S_CHANNEL_0_USED
#else
    #error "CHANNEL_0 cannot be used by I2S driver. Channel locked by another driver"
#endif

#ifndef FLEXIO_0_CH_1_USED
    #define FLEXIO_0_CH_1_USED
#else
    #error "CHANNEL_1 cannot be used by I2S driver. Channel locked by another driver"
#endif

#ifdef FLEXIO_0_CH_1_USED
    #define I2S_CHANNEL_1_USED
#else
    #error "CHANNEL_1 cannot be used by I2S driver. Channel locked by another driver"
#endif

#ifndef FLEXIO_0_CH_2_USED
    #define FLEXIO_0_CH_2_USED
#else
    #error "CHANNEL_2 cannot be used by I2S driver. Channel locked by another driver"
#endif

#ifdef FLEXIO_0_CH_2_USED
    #define I2S_CHANNEL_2_USED
#else
    #error "CHANNEL_2 cannot be used by I2S driver. Channel locked by another driver"
#endif


/* Macros that indicate FLEXIO pins used by I2S */
#ifndef FLEXIO_0_PIN_5_USED
    #define FLEXIO_0_PIN_5_USED
#else
    #error "PIN_5 cannot be used by I2S driver. Pin used by another driver!"
#endif

#ifndef FLEXIO_0_PIN_1_USED
    #define FLEXIO_0_PIN_1_USED
#else
    #error "PIN_1 cannot be used by I2S driver. Pin used by another driver!"
#endif

#ifndef FLEXIO_0_PIN_6_USED
    #define FLEXIO_0_PIN_6_USED
#else
    #error "PIN_6 cannot be used by I2S driver. Pin used by another driver!"
#endif

#ifndef FLEXIO_0_PIN_7_USED
    #define FLEXIO_0_PIN_7_USED
#else
    #error "PIN_7 cannot be used by I2S driver. Pin used by another driver!"
#endif


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_I2S_IP_CFGDEFINES_H */

