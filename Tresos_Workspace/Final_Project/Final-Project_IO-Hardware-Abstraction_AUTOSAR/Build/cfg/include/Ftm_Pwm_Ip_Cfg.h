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

#ifndef FTM_PWM_IP_CFG_H
#define FTM_PWM_IP_CFG_H

/**
*   @file       Ftm_Pwm_Ip_Cfg.h
*
*   @addtogroup ftm_pwm_ip Ftm Pwm IPL
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* Standard Types */
#include "Std_Types.h"
/* DevAssert implementation */
#include "Devassert.h"

/* Register definitions */
#include "S32K144_FTM.h"
#include "S32K144_SIM.h"

/* Include all variants header files. */

#include "Ftm_Pwm_Ip_PBcfg.h"

/* Include Feature Defines */
#include "Ftm_Pwm_Ip_CfgDefines.h"
#include "Reg_eSys.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_PWM_IP_CFG_VENDOR_ID                    43
#define FTM_PWM_IP_CFG_MODULE_ID                    121
#define FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION     4
#define FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION     7
#define FTM_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION  0
#define FTM_PWM_IP_CFG_SW_MAJOR_VERSION             2
#define FTM_PWM_IP_CFG_SW_MINOR_VERSION             0
#define FTM_PWM_IP_CFG_SW_PATCH_VERSION             0

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Std_Types.h are of the same AUTOSAR version */
    #if ((FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Cfg.h and Std_Types.h are different."
    #endif
    
    /* Check if source file and Devassert.h are of the same AUTOSAR version */
    #if ((FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION != DEVASSERT_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Cfg.h and Devassert.h are different."
    #endif
    
    /* Check if source file and Reg_eSys.h are of the same AUTOSAR version */
    #if ((FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Cfg.h and Reg_eSys.h are different."
    #endif
#endif

/* Check if header file and Ftm_Pwm_Ip_CfgDefines.h header file are of the same vendor */
#if (FTM_PWM_IP_CFG_VENDOR_ID != FTM_PWM_IP_CFGDEFINES_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip_Cfg.h and Ftm_Pwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_CfgDefines.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != FTM_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION    != FTM_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION != FTM_PWM_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Cfg.h and Ftm_Pwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_CfgDefines.h header file are of the same software version */
#if ((FTM_PWM_IP_CFG_SW_MAJOR_VERSION != FTM_PWM_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_CFG_SW_MINOR_VERSION != FTM_PWM_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_CFG_SW_PATCH_VERSION != FTM_PWM_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip_Cfg.h and Ftm_Pwm_Ip_CfgDefines.h are different."
#endif


/* Check if header file and Pwm_EnvCfg header file are of the same vendor */
#if (FTM_PWM_IP_CFG_VENDOR_ID != FTM_PWM_IP_PB_CFG_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip_Cfg.h and Ftm_Pwm_Ip_PBcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION    != FTM_PWM_IP_PB_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION    != FTM_PWM_IP_PB_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION != FTM_PWM_IP_PB_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Cfg.h and Ftm_Pwm_Ip_PBcfg.h are different."
#endif

/* Check if header file and Pwm_EnvCfg header file are of the same software version */
#if ((FTM_PWM_IP_CFG_SW_MAJOR_VERSION != FTM_PWM_IP_PB_CFG_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_CFG_SW_MINOR_VERSION != FTM_PWM_IP_PB_CFG_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_CFG_SW_PATCH_VERSION != FTM_PWM_IP_PB_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip_Cfg.h and Ftm_Pwm_Ip_PBcfg.h are different."
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @brief      Switch to enable the development error detection. */
#define FTM_PWM_IP_DEV_ERROR_DETECT           (STD_OFF)

/** @brief        Switch to enable the notifications feature */
#define FTM_PWM_IP_NOTIFICATION_SUPPORTED     (STD_OFF)

/** @brief        Switch to enable the reload point notifications feature */
#define FTM_PWM_IP_RELOAD_NOTIFICATION_SUPPORTED     (STD_OFF)

/** @brief    Support for User mode */
#define FTM_PWM_IP_ENABLE_USER_MODE_SUPPORT   (STD_OFF)

/** @brief    Support for Sim module is available */
#define FTM_PWM_IP_SIM_AVAILABLE              (STD_ON)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #if (STD_ON == FTM_PWM_IP_ENABLE_USER_MODE_SUPPORT)
        #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running FTM in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
    #endif
#endif

#if ((STD_ON == FTM_PWM_IP_ENABLE_USER_MODE_SUPPORT) && defined(MCAL_FTM_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_FTM_REG_PROT_AVAILABLE)
        #define  FTM_PWM_IP_USER_ACCESS_ALLOWED_AVAILABLE     (STD_ON)
    #else
        #define  FTM_PWM_IP_USER_ACCESS_ALLOWED_AVAILABLE     (STD_OFF)
    #endif
#else
#define  FTM_PWM_IP_USER_ACCESS_ALLOWED_AVAILABLE     (STD_OFF)
#endif

/* Macros that indicate FTM instances used by Pwm */
#ifndef FTM_1_USED
    #define FTM_1_USED
#else
    #error "FTM_1 instance cannot be used by Pwm. Instance locked by another driver!"
#endif
/* FTM module features */

/* @brief Number of PWM channels */
#define FTM_PWM_IP_CHANNEL_COUNT                       (FTM_CONTROLS_COUNT)
#define FTM_PWM_IP_PAIR_COUNT                          (FTM_CONTROLS_COUNT >> 1U)

/** Number of interrupt vector arrays for the FTM module. */
#define FTM_PWM_IP_IRQS_ARR_COUNT                      (FTM_INSTANCE_COUNT)
/** Number of interrupt channels for the FTM module. */
#define FTM_PWM_IP_CHANNEL_IRQ_COUNT                   (FTM_CONTROLS_COUNT)

/** Interrupt vectors for the FTM peripheral type */
#define FTM_PWM_IP_IRQS                                {\
                                                        { FTM0_IRQn, FTM0_IRQn, FTM0_IRQn, FTM0_IRQn, FTM0_IRQn, FTM0_IRQn },\
                                                        { FTM1_IRQn, FTM1_IRQn, FTM1_IRQn, FTM1_IRQn, FTM1_IRQn, FTM1_IRQn }\
                                                    }
#define FTM_PWM_IP_OVERFLOW_IRQS                       { FTM0_IRQn, FTM1_IRQn }
#define FTM_PWM_IP_RELOAD_IRQS                         { FTM0_IRQn, FTM1_IRQn }

/* Mask for Software Output Control Value of all channel bits */
#define FTM_PWM_IP_SWOCTRL_CHOC_MASK                  (0x000000FFU)
/* Mask for Software Output Control Value of all channel bits */
#define FTM_PWM_IP_SWOCTRL_CHOCV_MASK                 (0x0000FF00U)

/* @brief Width of control channel */
#define FTM_PWM_IP_COMBINE_CHAN_CTRL_WIDTH             (8U)

/** Number of instances of the SIM module. */
#define FTM_PWM_IP_SIM_INSTANCE_COUNT                  (SIM_INSTANCE_COUNT)


#define FTM_PWM_IP_FAULT_NUMBER_CHANNELS                   (4U)
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* Redefine FTM_Type from header file to comply with coding guidelines */
typedef FTM_Type Ftm_Pwm_Ip_HwAddrType;

/* Redefine SIM_Type from header file to comply with coding guidelines */
typedef SIM_Type Ftm_Pwm_Ip_SimType;

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTM_PWM_IP_CFG_H */

