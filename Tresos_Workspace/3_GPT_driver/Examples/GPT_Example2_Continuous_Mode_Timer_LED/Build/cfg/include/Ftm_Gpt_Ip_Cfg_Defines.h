/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : Ftm_Srtc_Lptmr_LPit
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 2.0.0
* Build Version : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
* Copyright 2020-2024 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef FTM_GPT_IP_CFG_DEFINES_H
#define FTM_GPT_IP_CFG_DEFINES_H

/**
*   @file           Ftm_Gpt_Ip_Cfg_Defines.h
*
*   @addtogroup     Ftm_Gpt_Ip Ftm_Gpt_Ip IPL
*
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
#include "Std_Types.h"
#include "S32K144_FTM.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_GPT_IP_DEFINES_VENDOR_ID_CFG                    43
#define FTM_GPT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG     4
#define FTM_GPT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG     7
#define FTM_GPT_IP_DEFINES_AR_RELEASE_REVISION_VERSION_CFG  0
#define FTM_GPT_IP_DEFINES_SW_MAJOR_VERSION_CFG             2
#define FTM_GPT_IP_DEFINES_SW_MINOR_VERSION_CFG             0
#define FTM_GPT_IP_DEFINES_SW_PATCH_VERSION_CFG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FTM_GPT_IP_DEFINES_AR_RELEASE_MAJOR_VERSION_CFG != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_GPT_IP_DEFINES_AR_RELEASE_MINOR_VERSION_CFG != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Ftm_Gpt_Ip_Cfg_Defines.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief These defines indicate that at least one channel from each module is used in all configurations.
*/
#define FTM_GPT_IP_USED (STD_ON)
/*================================================================================================*/

/**
* @brief This define is used to select between interrupt on each channel and source interrupt
*        on entire module sources hardware implementations.
*
*/
#define FTM_GPT_IP_MODULE_SINGLE_INTERRUPT (STD_OFF)

/*================================================================================================*/
/**
* @brief    FTN_GPT_IP_SET_CLOCK_MODE switch
* @details  Enable/disable API for Dual Mode support.
*/
#define FTM_GPT_IP_SET_CLOCK_MODE           (STD_OFF)

/*================================================================================================*/
/**
*
* @brief IRQ Defines for each channel used
*/

    /* Channel per instance*/
                                                                                                                                                        /* Generate ISR when check in GptHwConfiguration*/
        
#define FTM_0_CH_0_CH_1_ISR_USED

#ifndef FTM_0_CH_0_USED
    #define FTM_0_CH_0_USED
#else
    #error "FTM_0_CH_0 cannot be used by GPT. Instance locked by another driver!"
#endif

#ifndef FTM_0_CH_1_USED
    #define FTM_0_CH_1_USED
#else
    #error "FTM_0_CH_1 cannot be used by GPT. Instance locked by another driver!"
#endif
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Generate ISR when check in GptHwConfiguration*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Generate ISR when check in GptHwConfiguration*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Generate ISR when check in GptHwConfiguration*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Generate ISR when check in GptHwConfiguration*/
                /* Channel per instance*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* Generate ISR when check in GptHwConfiguration*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Generate ISR when check in GptHwConfiguration*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Generate ISR when check in GptHwConfiguration*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Generate ISR when check in GptHwConfiguration*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Generate ISR when check in GptHwConfiguration*/
                /* Channel per instance*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* Generate ISR when check in GptHwConfiguration*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Generate ISR when check in GptHwConfiguration*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Generate ISR when check in GptHwConfiguration*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Generate ISR when check in GptHwConfiguration*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Generate ISR when check in GptHwConfiguration*/
                /* Channel per instance*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    /* Generate ISR when check in GptHwConfiguration*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Generate ISR when check in GptHwConfiguration*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Generate ISR when check in GptHwConfiguration*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Generate ISR when check in GptHwConfiguration*/
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Generate ISR when check in GptHwConfiguration*/
            
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */

#endif  /* FTM_GPT_IP_CFG_DEFINES_H */
