/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm Flexio
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

#ifndef FLEXIO_PWM_IP_CFG_H
#define FLEXIO_PWM_IP_CFG_H

/**
*   @file Flexio_Pwm_Ip_Cfg.h
*
*   @addtogroup flexio_pwm_ip FlexIO Pwm IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Devassert.h"

/* Register definitions */

#include "S32K144_FLEXIO.h"

#include "Flexio_Pwm_Ip_CfgDefines.h"

/* Include all variants header files. */

#include "Flexio_Pwm_Ip_PBcfg.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_PWM_IP_CFG_VENDOR_ID                    43
#define FLEXIO_PWM_IP_CFG_MODULE_ID                    121
#define FLEXIO_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_PWM_IP_CFG_SW_MAJOR_VERSION             2
#define FLEXIO_PWM_IP_CFG_SW_MINOR_VERSION             0
#define FLEXIO_PWM_IP_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((FLEXIO_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Flexio_Pwm_Ip_Cfg.h and Std_Types.h are different"
    #endif

    /* Check if header file and Devassert.h are of the same AUTOSAR version */
    #if ((FLEXIO_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Flexio_Pwm_Ip_Cfg.h and Devassert.h are different"
    #endif
#endif

/* Check if header file and Flexio_Pwm_Ip_CfgDefines.h header file are of the same vendor */
#if (FLEXIO_PWM_IP_CFG_VENDOR_ID != FLEXIO_PWM_IP_CFGDEFINES_VENDOR_ID)
    #error "Vendor IDs of Flexio_Pwm_Ip_Cfg.h and Flexio_Pwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_CfgDefines.h header file are of the same AUTOSAR version */
#if ((FLEXIO_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION    != FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION != FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Flexio_Pwm_Ip_Cfg.h and Flexio_Pwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_CfgDefines.h header file are of the same software version */
#if ((FLEXIO_PWM_IP_CFG_SW_MAJOR_VERSION != FLEXIO_PWM_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_CFG_SW_MINOR_VERSION != FLEXIO_PWM_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_CFG_SW_PATCH_VERSION != FLEXIO_PWM_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software version numbers of Flexio_Pwm_Ip_Cfg.h and Flexio_Pwm_Ip_CfgDefines.h are different."
#endif


/* Check if header file and Flexio_Pwm_Ip_PBcfg header file are of the same vendor */
#if (FLEXIO_PWM_IP_CFG_VENDOR_ID != FLEXIO_PWM_IP_PBCFG_VENDOR_ID)
    #error "Vendor IDs of Flexio_Pwm_Ip_Cfg.h and Flexio_Pwm_Ip_PBcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same AUTOSAR version */
#if ((FLEXIO_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != FLEXIO_PWM_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION    != FLEXIO_PWM_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION != FLEXIO_PWM_IP_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Flexio_Pwm_Ip_Cfg.h and Flexio_Pwm_Ip_PBcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same software version */
#if ((FLEXIO_PWM_IP_CFG_SW_MAJOR_VERSION != FLEXIO_PWM_IP_PBCFG_SW_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_CFG_SW_MINOR_VERSION != FLEXIO_PWM_IP_PBCFG_SW_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_CFG_SW_PATCH_VERSION != FLEXIO_PWM_IP_PBCFG_SW_PATCH_VERSION))
    #error "Software version numbers of Flexio_Pwm_Ip_Cfg.h and Flexio_Pwm_Ip_PBcfg.h are different."
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief      Check to use the Flexio_Mcl driver */
#define FLEXIO_PWM_IP_USED_MCL                  (STD_OFF)
/** @brief      Check to use the Flexio Ip driver */
#define FLEXIO_PWM_IP_USED                      (STD_OFF)
/** @brief      Switch to enable the development error detection. */
#define FLEXIO_PWM_IP_DEV_ERROR_DETECT          (STD_OFF)
/** @brief      Number of instances for Flexio */
#define FLEXIO_PWM_IP_INSTANCE_COUNT            (FLEXIO_INSTANCE_COUNT)
/** @brief      Number of channels available for PWM on Flexio */
#define FLEXIO_PWM_IP_CHANNEL_COUNT             (FLEXIO_TIMCMP_COUNT)
/** @brief      Number of pins available for PWM on Flexio */
#define FLEXIO_PWM_IP_PIN_COUNT                 (8U)

/** @brief      Value of Timer Ouput bitfield for 8bit PWM Low and High modes */
#define FLEXIO_PWM_IP_TIMER_START_HIGH_MODE     (0U)
#define FLEXIO_PWM_IP_TIMER_START_LOW_MODE      (1U)
/** @brief      Value of Timer Ouput bitfield for 8bit PWM Low and High modes */
#define FLEXIO_PWM_IP_TIMER_CMP_MAX_VALUE       (0x0100U)
/** @brief      Timer comparator upper 8 bit mask*/
#define FLEXIO_PWM_IP_TIMCMP_CMP_UPPER_MASK     (0x0000FF00UL)
#define FLEXIO_PWM_IP_TIMCMP_CMP_UPPER_SHIFT    (0x8U)
#define FLEXIO_PWM_IP_TIMCMP_CMP_UPPER(x)       (((uint32_t)(((uint32_t)(x)) << FLEXIO_PWM_IP_TIMCMP_CMP_UPPER_SHIFT)) & FLEXIO_PWM_IP_TIMCMP_CMP_UPPER_MASK)
/** @brief      Timer comparator lower 8 bit mask*/
#define FLEXIO_PWM_IP_TIMCMP_CMP_LOWER_MASK     (0x000000FFUL)
#define FLEXIO_PWM_IP_TIMCMP_CMP_LOWER_SHIFT    (0x0U)
#define FLEXIO_PWM_IP_TIMCMP_CMP_LOWER(x)       (((uint32_t)(((uint32_t)(x)) << FLEXIO_PWM_IP_TIMCMP_CMP_LOWER_SHIFT)) & FLEXIO_PWM_IP_TIMCMP_CMP_LOWER_MASK)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* Redefine FLEXTIMER_Type from header file to comply with coding guidelines */
typedef FLEXIO_Type Flexio_Pwm_Ip_HwAddrType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_PWM_IP_CFG_H */

