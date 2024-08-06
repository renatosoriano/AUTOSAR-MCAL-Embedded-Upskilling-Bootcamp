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


/**
 *   @file          LPit_Gpt_Ip_VS_0_PBcfg.c
 *
 *   @addtogroup    lpit_ip LPit IPL
 *
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
 *================================================================================================*/
#include "LPit_Gpt_Ip_VS_0_PBcfg.h"
#include "Gpt_Irq.h"
/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define LPIT_GPT_IP_VENDOR_ID_VS_0_PBCFG_C                    43
#define LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_C     4
#define LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_C     7
#define LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_C  0
#define LPIT_GPT_IP_SW_MAJOR_VERSION_VS_0_PBCFG_C             2
#define LPIT_GPT_IP_SW_MINOR_VERSION_VS_0_PBCFG_C             0
#define LPIT_GPT_IP_SW_PATCH_VERSION_VS_0_PBCFG_C             0
/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
#if (LPIT_GPT_IP_VENDOR_ID_VS_0_PBCFG_C != LPIT_GPT_IP_VENDOR_ID_VS_0_PBCFG_H)
    #error "LPit_Gpt_Ip_VS_0_PBcfg.c and LPit_Gpt_Ip_Types.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_C != LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_H) || \
     (LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_C != LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_H) || \
     (LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_C != LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of LPit_Gpt_Ip_VS_0_PBcfg.c and LPit_Gpt_Ip_Types.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((LPIT_GPT_IP_SW_MAJOR_VERSION_VS_0_PBCFG_C != LPIT_GPT_IP_SW_MAJOR_VERSION_VS_0_PBCFG_H) || \
     (LPIT_GPT_IP_SW_MINOR_VERSION_VS_0_PBCFG_C != LPIT_GPT_IP_SW_MINOR_VERSION_VS_0_PBCFG_H) || \
     (LPIT_GPT_IP_SW_PATCH_VERSION_VS_0_PBCFG_C != LPIT_GPT_IP_SW_PATCH_VERSION_VS_0_PBCFG_H) \
    )
    #error "Software Version Numbers of LPit_Gpt_Ip_VS_0_PBcfg.c and LPit_Gpt_Ip_Types.h are different"
#endif

#if (LPIT_GPT_IP_VENDOR_ID_VS_0_PBCFG_C != GPT_IRQ_VENDOR_ID)
    #error "LPit_Gpt_Ip_VS_0_PBcfg.c and Gpt_Irq.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION_VS_0_PBCFG_C != GPT_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION_VS_0_PBCFG_C != GPT_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION_VS_0_PBCFG_C != GPT_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of LPit_Gpt_Ip_VS_0_PBcfg.c and Gpt_Irq.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((LPIT_GPT_IP_SW_MAJOR_VERSION_VS_0_PBCFG_C != GPT_IRQ_SW_MAJOR_VERSION) || \
     (LPIT_GPT_IP_SW_MINOR_VERSION_VS_0_PBCFG_C != GPT_IRQ_SW_MINOR_VERSION) || \
     (LPIT_GPT_IP_SW_PATCH_VERSION_VS_0_PBCFG_C != GPT_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of LPit_Gpt_Ip_VS_0_PBcfg.c and Gpt_Irq.h are different"
#endif
/*================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/
#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
const Lpit_Gpt_Ip_InstanceConfigType LPIT_0_InitConfig_PB_VS_0 = 
{
#if (LPIT_GPT_IP_DOZE_MODE_SUPPORT == STD_ON)
        /** @brief DOZE Mode Enable Bit */
        (boolean)FALSE,
#endif
        /** @brief LPIT Debug Mode */
        (boolean)FALSE
};

const Lpit_Gpt_Ip_ChannelConfigType LPIT_0_ChannelConfig_PB_VS_0[2U] = 
{
    /** @brief GptLpitChannels_0 */
    {
        /** @brief Lpit Channel Id */
        0U,
        /** @brief Lpit callback name */
        &Gpt_ProcessCommonInterrupt,
        /** @brief Lpit callback param */
        (uint8)0U,
        #if (LPIT_GPT_IP_ENABLE_EXT_TRIGGERS == STD_ON)
        /* LPIT External/Internal Trigger Configuration */
        (uint32)0U | \
        (uint32)((uint32)1U << LPIT_TMR_TCTRL_TRG_SRC_SHIFT) | \
        (uint32)((uint32)0U << LPIT_TMR_TCTRL_TROT_SHIFT) | \
        (uint32)((uint32)0U << LPIT_TMR_TCTRL_TSOI_SHIFT) | \
        (uint32)((uint32)0U << LPIT_TMR_TCTRL_TSOT_SHIFT),
        #endif
        /** @brief Lpit channel mode */
        LPIT_GPT_IP_CH_MODE_CONTINUOUS
    }
    ,
    /** @brief GptLpitChannels_1 */
    {
        /** @brief Lpit Channel Id */
        1U,
        /** @brief Lpit callback name */
        &Gpt_ProcessCommonInterrupt,
        /** @brief Lpit callback param */
        (uint8)1U,
        #if (LPIT_GPT_IP_ENABLE_EXT_TRIGGERS == STD_ON)
        /* LPIT External/Internal Trigger Configuration */
        (uint32)0U | \
        (uint32)((uint32)1U << LPIT_TMR_TCTRL_TRG_SRC_SHIFT) | \
        (uint32)((uint32)0U << LPIT_TMR_TCTRL_TROT_SHIFT) | \
        (uint32)((uint32)0U << LPIT_TMR_TCTRL_TSOI_SHIFT) | \
        (uint32)((uint32)0U << LPIT_TMR_TCTRL_TSOT_SHIFT),
        #endif
        /** @brief Lpit channel mode */
        LPIT_GPT_IP_CH_MODE_CONTINUOUS
    }
};

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Gpt_MemMap.h"
/*==================================================================================================
 *                                       GLOBAL FUNCTIONS
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
 *================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
 *================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
 *================================================================================================*/

#ifdef __cplusplus
}
#endif /* LPIT_GPT_IP_PBCFG_C*/

/** @} */
