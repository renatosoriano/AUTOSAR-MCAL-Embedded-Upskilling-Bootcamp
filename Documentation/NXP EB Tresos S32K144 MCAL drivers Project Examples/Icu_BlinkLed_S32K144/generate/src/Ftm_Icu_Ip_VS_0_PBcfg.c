/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm Lpit Lptmr Port_Ci LpCmp
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

/**
 *   @file       Ftm_Icu_Ip_VS_0_PBcfg.c
 *   @version    2.0.0
 *
 *   @brief      AUTOSAR Icu - contains the data exported by the ICU module.
 *   @details    Contains the information that will be exported by the module, as requested by AUTOSAR.
 *
 *   @addtogroup ftm_icu_ip FTM IPL
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
#include "Ftm_Icu_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTM_ICU_IP_VS_0_PBCFG_VENDOR_ID_C                    43
#define FTM_ICU_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C     4
#define FTM_ICU_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C     7
#define FTM_ICU_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C  0
#define FTM_ICU_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C             2
#define FTM_ICU_IP_VS_0_PBCFG_SW_MINOR_VERSION_C             0
#define FTM_ICU_IP_VS_0_PBCFG_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ICU header file are of the same vendor */
#if (FTM_ICU_IP_VS_0_PBCFG_VENDOR_ID_C != FTM_ICU_IP_TYPES_VENDOR_ID)
    #error "Ftm_Icu_Ip_VS_0_PBcfg.c and Ftm_Icu_Ip_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((FTM_ICU_IP_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C != FTM_ICU_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_ICU_IP_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C != FTM_ICU_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FTM_ICU_IP_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C != FTM_ICU_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Ftm_Icu_Ip_VS_0_PBcfg.c and Ftm_Icu_Ip_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((FTM_ICU_IP_VS_0_PBCFG_SW_MAJOR_VERSION_C != FTM_ICU_IP_TYPES_SW_MAJOR_VERSION) || \
     (FTM_ICU_IP_VS_0_PBCFG_SW_MINOR_VERSION_C != FTM_ICU_IP_TYPES_SW_MINOR_VERSION) || \
     (FTM_ICU_IP_VS_0_PBCFG_SW_PATCH_VERSION_C != FTM_ICU_IP_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Ftm_Icu_Ip_VS_0_PBcfg.c and Ftm_Icu_Ip_Types.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/** @brief Signature of report events interrupt function. */
extern void Icu_ReportEvents(uint16 Channel, boolean bOverflow);

/** @brief Signature of wakeup and overflow interrupt function. */
extern void Icu_ReportWakeupAndOverflow(uint16 Channel, boolean bOverflow);

/** @brief Signature of change logic channel state function. */
extern void Icu_LogicChStateCallback(uint16 logicChannel, uint8 mask, boolean set);


#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/**
 *  @brief PB_VS_0 FTM Channels Configuration
 */
const Ftm_Icu_Ip_ChannelConfigType Ftm_Icu_Ip_0_ChannelConfig_PB_VS_0[1U] =
{
    /** @brief IcuFtmChannels_0 */
    {
        /** @brief ID of FTM hardware channel used. */
        (uint8)1,
        /** @brief FTM IP layer mode of operation. */
        FTM_ICU_MODE_SIGNAL_EDGE_DETECT,
        /** @brief DMA support for timestamp measurement. */
        FTM_ICU_MODE_WITHOUT_DMA,
        /** @brief Measurement mode for signal measurement. */
        FTM_ICU_NO_MEASUREMENT,
        /** @brief Edge alignment for signal measurement. */
        FTM_ICU_RISING_EDGE,
        /** @brief Continuos measurement enable/disable. */
        (boolean)FALSE,
        /** @brief FTM Channel Input Filter value */
        (uint8)0,
        /** @brief Callback function for channels. */
        &Icu_ReportEvents,
        /** @brief Parameters used by callback function. */
        (uint8)0,
#if (STD_ON == FTM_ICU_TIMESTAMP_API)
        /** @brief Timestamp buffer used. */
        FTM_ICU_NO_TIMESTAMP,
#endif
        /** @brief Address of function used to change logic channel state in HLD. */
        &Icu_LogicChStateCallback,
        /** @brief Channel specific notification(e.g timestamp). */
        NULL_PTR,
        /** @brief Logic channel overflow notification. */
        NULL_PTR
    }
};

/**
 *  @brief PB_VS_0 FTM 0 Instance Configuration
 */
const Ftm_Icu_Ip_InstanceConfigType Ftm_Icu_Ip_0_InstanceConfig_PB_VS_0 = 
{
    /** @brief FTM clock source */
    FTM_SYSTEM_CLOCK,
    /** @brief FTM instance prescaler  */
    (uint8)1,
#if (FTM_ICU_DUAL_CLOCK_MODE_API == STD_ON)
    /** @brief FTM instance alternate prescaler  */
    (uint8)128,
#endif
    /** @brief FTM debug mode  */
    MODE_3,
    /** @brief FTM maxim counter value */
    (uint16)65535
};

/**
 *  @brief    PB_VS_0 FTM IP Configuration
 */
const Ftm_Icu_Ip_ConfigType Ftm_Icu_Ip_0_Config_PB_VS_0 = 
{
    /** @brief Number of FTM channels in the Icu configuration */
    (uint8)1,
    /** @brief The FTM instance configuration */
    &Ftm_Icu_Ip_0_InstanceConfig_PB_VS_0,
    /** @brief Pointer to the array of FTM channel configurations */
    &Ftm_Icu_Ip_0_ChannelConfig_PB_VS_0
};

#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
