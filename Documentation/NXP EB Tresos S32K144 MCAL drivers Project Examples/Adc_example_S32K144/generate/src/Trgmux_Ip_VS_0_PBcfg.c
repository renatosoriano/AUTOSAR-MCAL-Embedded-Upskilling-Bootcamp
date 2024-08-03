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
#include "Trgmux_Ip_Cfg.h"

/*==================================================================================================
*                                    SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define TRGMUX_IP_VS_0_PBCFG_VENDOR_ID_C                        43
#define TRGMUX_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C         4
#define TRGMUX_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C         7
#define TRGMUX_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C      0
#define TRGMUX_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C                 2
#define TRGMUX_IP_VS_0_PBCFG_SW_MINOR_VERSION_C                 0
#define TRGMUX_IP_VS_0_PBCFG_SW_PATCH_VERSION_C                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Trgmux_Ip_VS_0_PBcfg.c file and Trgmux_Ip_Cfg.h file are of the same vendor */
#if (TRGMUX_IP_VS_0_PBCFG_VENDOR_ID_C != TRGMUX_IP_CFG_VENDOR_ID)
    #error "Trgmux_Ip_VS_0_PBcfg.c and Trgmux_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Trgmux_Ip_VS_0_PBcfg.c file and Trgmux_Ip_Cfg.h file are of the same Autosar version */
#if ((TRGMUX_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C != TRGMUX_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (TRGMUX_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C != TRGMUX_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (TRGMUX_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C != TRGMUX_IP_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Trgmux_Ip_VS_0_PBcfg.c and Trgmux_Ip_Cfg.h are different"
#endif

/* Check if Trgmux_Ip_VS_0_PBcfg.c file and Trgmux_Ip_Cfg.h file are of the same Software version */
#if ((TRGMUX_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C != TRGMUX_IP_CFG_SW_MAJOR_VERSION) || \
     (TRGMUX_IP_VS_0_PBCFG_SW_MINOR_VERSION_C != TRGMUX_IP_CFG_SW_MINOR_VERSION) || \
     (TRGMUX_IP_VS_0_PBCFG_SW_PATCH_VERSION_C != TRGMUX_IP_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Trgmux_Ip_VS_0_PBcfg.c and Trgmux_Ip_Cfg.h are different"
#endif

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


#define MCL_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcl_MemMap.h"

/* TRGMUX Logic Trigger Configuration */
const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger0ConfigPB_VS_0 =
{
    /* uint8 LogicChannel; */         (uint8)TRGMUX_LOGIC_GROUP_0_TRIGGER_0,
    /* uint8 Output; */               (uint8)TRGMUX_IP_OUTPUT_DMA_CH0,
    /* uint8 Input; */                (uint8)TRGMUX_IP_INPUT_LOGIC0_VSS,
    /* uint8 HwInstId; */             (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */               (boolean)FALSE,
};
const Trgmux_Ip_LogicTriggerType Trgmux_Ip_LogicTrigger1ConfigPB_VS_0 =
{
    /* uint8 LogicChannel; */         (uint8)TRGMUX_LOGIC_GROUP_1_TRIGGER_0,
    /* uint8 Output; */               (uint8)TRGMUX_IP_OUTPUT_ADC0_ADHWT_TRIG_0,
    /* uint8 Input; */                (uint8)TRGMUX_IP_INPUT_LOGIC0_VSS,
    /* uint8 HwInstId; */             (uint8)TRGMUX_IP_HW_INST_0,
    /* boolean Lock; */               (boolean)TRUE,
};

/* TRGMUX Initialization Structure */
const Trgmux_Ip_InitType Trgmux_Ip_xTrgmuxInitPB_VS_0 =
{
    /* Trgmux_Ip_LogicTriggerType * paxLogicTrigger[] */
    {
        &Trgmux_Ip_LogicTrigger0ConfigPB_VS_0,
        &Trgmux_Ip_LogicTrigger1ConfigPB_VS_0,
    }
};

#define MCL_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

/*==================================================================================================
 *                                        END OF FILE
==================================================================================================*/
