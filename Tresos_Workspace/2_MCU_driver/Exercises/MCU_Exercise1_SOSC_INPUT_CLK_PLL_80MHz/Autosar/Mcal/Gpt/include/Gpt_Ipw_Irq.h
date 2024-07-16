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

#ifndef GPT_IPW_IRQ_H
#define GPT_IPW_IRQ_H

/**
*   @file       Gpt_Ipw_Irq.h
*
*   @internal
*   @addtogroup gpt gpt_ipw
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
#include "Gpt_Irq.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define GPT_IPW_IRQ_VENDOR_ID                      43
#define GPT_IPW_IRQ_AR_RELEASE_MAJOR_VERSION       4
#define GPT_IPW_IRQ_AR_RELEASE_MINOR_VERSION       7
#define GPT_IPW_IRQ_AR_RELEASE_REVISION_VERSION    0
#define GPT_IPW_IRQ_SW_MAJOR_VERSION               2
#define GPT_IPW_IRQ_SW_MINOR_VERSION               0
#define GPT_IPW_IRQ_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and GPT header file are of the same vendor */
#if (GPT_IPW_IRQ_VENDOR_ID != GPT_IRQ_VENDOR_ID)
    #error "Gpt_Ipw_Irq.h and Gpt_Irq.h have different vendor ids"
#endif
/* Check if source file and GPT header file are of the same Autosar version */
#if ((GPT_IPW_IRQ_AR_RELEASE_MAJOR_VERSION != GPT_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_IRQ_AR_RELEASE_MINOR_VERSION != GPT_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_IRQ_AR_RELEASE_REVISION_VERSION != GPT_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Ipw_Irq.h and Gpt_Irq.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_IPW_IRQ_SW_MAJOR_VERSION != GPT_IRQ_SW_MAJOR_VERSION) || \
     (GPT_IPW_IRQ_SW_MINOR_VERSION != GPT_IRQ_SW_MINOR_VERSION) || \
     (GPT_IPW_IRQ_SW_PATCH_VERSION != GPT_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Ipw_Irq.h and Gpt_Irq.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

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
#endif /*GPT_IPW_IRQ_H*/
