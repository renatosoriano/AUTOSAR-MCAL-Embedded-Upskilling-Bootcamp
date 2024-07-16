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

#ifndef GPT_IRQ_H
#define GPT_IRQ_H

/**
*   @file       Gpt_Irq.h
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

#define GPT_IRQ_VENDOR_ID                      43
#define GPT_IRQ_AR_RELEASE_MAJOR_VERSION       4
#define GPT_IRQ_AR_RELEASE_MINOR_VERSION       7
#define GPT_IRQ_AR_RELEASE_REVISION_VERSION    0
#define GPT_IRQ_SW_MAJOR_VERSION               2
#define GPT_IRQ_SW_MINOR_VERSION               0
#define GPT_IRQ_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                     CONSTANT-LIKE DEFINES
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION-LIKE DEFINES(MACROS)
==================================================================================================*/

/*==================================================================================================
*                                     ENUMS
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
#define GPT_START_SEC_CODE

#include "Gpt_MemMap.h"

/*==================================================================================================*/
/**
* @brief        Gpt common handler to implements generic part of the ISR.
* @details      Generic function used by all interrupt service routines to call notification
*               functions  and wakeup the EcuM
*
* @param[in]    channel     logic channel number
* @return       void
* @pre          The driver needs to be initialized.
* @implements   Gpt_ProcessCommonInterrupt_Activity
*/
void Gpt_ProcessCommonInterrupt(uint8 channel);

/*==================================================================================================*/
#define GPT_STOP_SEC_CODE

#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
#endif /*GPT_IRQ_H*/
