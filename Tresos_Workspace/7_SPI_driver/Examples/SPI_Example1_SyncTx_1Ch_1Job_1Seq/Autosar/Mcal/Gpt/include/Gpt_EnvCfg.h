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
* Build Version : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
* Copyright 2020-2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef GPT_ENVCFG_H
#define GPT_ENVCFG_H

/**
*   @file       Gpt_EnvCfg.h
*
*   @addtogroup gpt Gpt Driver
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

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define GPT_ENVCFG_VENDOR_ID                      43
#define GPT_ENVCFG_AR_RELEASE_MAJOR_VERSION       4
#define GPT_ENVCFG_AR_RELEASE_MINOR_VERSION       7
#define GPT_ENVCFG_AR_RELEASE_REVISION_VERSION    0
#define GPT_ENVCFG_SW_MAJOR_VERSION               2
#define GPT_ENVCFG_SW_MINOR_VERSION               0
#define GPT_ENVCFG_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANT-LIKE DEFINES
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION-LIKE DEFINES(MACROS)
==================================================================================================*/
/**
* @brief    GPT_VALIDATE_GLOBAL_CALL
* @details  Validates the global call uses all the channels - Gpt_Init, Gpt_DeInit, Gpt_SetMode.
*/
#define GPT_VALIDATE_GLOBAL_CALL    (GPT_DEV_ERROR_DETECT)
/*================================================================================================*/
/**
* @brief    GPT_VALIDATE_CHANNEL_CALL
* @details  Validates the call for a specific channel.
*/
#define GPT_VALIDATE_CHANNEL_CALL   (GPT_DEV_ERROR_DETECT)
/*================================================================================================*/
/**
* @brief    GPT_VALIDATE_STATE
* @details  Validates the channel status.
*/
#define GPT_VALIDATE_STATE          (GPT_DEV_ERROR_DETECT)
/*================================================================================================*/
/**
* @brief    GPT_VALIDATE_PARAM
* @details  Validates the time value parameter.
*/
#define GPT_VALIDATE_PARAM          (GPT_DEV_ERROR_DETECT)

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */
#endif /* GPT_ENVCFG_H */
