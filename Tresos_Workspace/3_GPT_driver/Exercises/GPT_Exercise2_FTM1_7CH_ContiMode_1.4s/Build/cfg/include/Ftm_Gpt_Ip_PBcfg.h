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
#ifndef FTM_GPT_IP_PBCFG_H
#define FTM_GPT_IP_PBCFG_H

/**
*   @file          Ftm_Gpt_Ip_PBcfg.h
*
*   @addtogroup    Ftm_Gpt_Ip Ftm_Gpt_Ip IPL
*
*   @{
*/


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
#include "Ftm_Gpt_Ip_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* Inclusion of incompatible header files shall be avoided */


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#define FTM_GPT_IP_VENDOR_ID_PBCFG_H                    43
#define FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_H     4
#define FTM_GPT_IP_AR_RELEASE_MINOR_VERSION_PBCFG_H     7
#define FTM_GPT_IP_AR_RELEASE_REVISION_VERSION_PBCFG_H  0
#define FTM_GPT_IP_SW_MAJOR_VERSION_PBCFG_H             2
#define FTM_GPT_IP_SW_MINOR_VERSION_PBCFG_H             0
#define FTM_GPT_IP_SW_PATCH_VERSION_PBCFG_H             0
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (FTM_GPT_IP_VENDOR_ID_PBCFG_H != FTM_GPT_IP_TYPES_VENDOR_ID)
    #error "Ftm_Gpt_Ip_PBcfg.h and Ftm_Gpt_Ip_Types.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((FTM_GPT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_H != FTM_GPT_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_GPT_IP_AR_RELEASE_MINOR_VERSION_PBCFG_H != FTM_GPT_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FTM_GPT_IP_AR_RELEASE_REVISION_VERSION_PBCFG_H != FTM_GPT_IP_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Ftm_Gpt_Ip_PBcfg.h and Ftm_Gpt_Ip_Types.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((FTM_GPT_IP_SW_MAJOR_VERSION_PBCFG_H != FTM_GPT_IP_TYPES_SW_MAJOR_VERSION) || \
     (FTM_GPT_IP_SW_MINOR_VERSION_PBCFG_H != FTM_GPT_IP_TYPES_SW_MINOR_VERSION) || \
     (FTM_GPT_IP_SW_PATCH_VERSION_PBCFG_H != FTM_GPT_IP_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Ftm_Gpt_Ip_PBcfg.h and Ftm_Gpt_Ip_Types.h are different"
#endif
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"

extern const Ftm_Gpt_Ip_InstanceConfigType FTM_1_InitConfig_PB;
extern const Ftm_Gpt_Ip_ChannelConfigType FTM_1_ChannelConfig_PB[7U];


#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif
/** @} */

#endif  /* Ftm_Gpt_Ip_CFG_H */
