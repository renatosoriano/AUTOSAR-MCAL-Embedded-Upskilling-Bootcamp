/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   Copyright 2020-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef MCU_IPW_H
#define MCU_IPW_H

/**
*   @file    Mcu_Ipw.h
*   @implements Mcu_Ipw.h_Artifact
*   @version    2.0.0
*
*   @brief   AUTOSAR Mcu - Mcu driver header file.
*   @details AUTOSAR specific Mcu driver header file.

*   @addtogroup MCU_DRIVER Mcu Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif



/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_Ipw_Types.h"
#include "Mcu_EnvCfg.h"
#include "Mcal.h"

/*==================================================================================================
                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_IPW_VENDOR_ID                     43
#define MCU_IPW_AR_RELEASE_MAJOR_VERSION      4
#define MCU_IPW_AR_RELEASE_MINOR_VERSION      7
#define MCU_IPW_AR_RELEASE_REVISION_VERSION   0
#define MCU_IPW_SW_MAJOR_VERSION              2
#define MCU_IPW_SW_MINOR_VERSION              0
#define MCU_IPW_SW_PATCH_VERSION              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Mcu_Ipw.h file and Mcu_Ipw_Types.h file are of the same vendor */
#if (MCU_IPW_VENDOR_ID != MCU_IPW_TYPES_VENDOR_ID)
    #error "Mcu_Ipw.h and Mcu_Ipw_Types.h have different vendor ids"
#endif

/* Check if Mcu_Ipw.h file and Mcu_Ipw_Types.h file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION != MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION != MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION != MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_Ipw.h and Mcu_Ipw_Types.h are different"
#endif

/* Check if Mcu_Ipw.h file and Mcu_Ipw_Types.h file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION != MCU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION != MCU_IPW_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION != MCU_IPW_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_Ipw.h and Mcu_Ipw_Types.h are different"
#endif

/* Check if Mcu_Ipw.h file and Mcu_EnvCfg.h file are of the same vendor */
#if (MCU_IPW_VENDOR_ID != MCU_ENVCFG_VENDOR_ID)
    #error "Mcu_Ipw.h and Mcu_EnvCfg.h have different vendor ids"
#endif

/* Check if Mcu_Ipw.h file and Mcu_EnvCfg.h file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION != MCU_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION != MCU_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION != MCU_ENVCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_Ipw.h and Mcu_EnvCfg.h are different"
#endif

/* Check if Mcu_Ipw.h file and Mcu_EnvCfg.h file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION != MCU_ENVCFG_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION != MCU_ENVCFG_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION != MCU_ENVCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_Ipw.h and Mcu_EnvCfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Mcu_Ipw.h file and Mcal.h file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mcu_Ipw.h and Mcal.h are different"
#endif
#endif
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#ifdef MCU_EMIOS_CONFIGURE_GPREN_API
#if (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON)
    #define MCU_EMIOS_GPREN_BIT_ENABLE          (0x01U)
    #define MCU_EMIOS_GPREN_BIT_DISABLE         (0x00U)
    #define MCU_EMIOS_MCR_GPREN_MASK32          eMIOS_MCR_GPREN_MASK
#endif
#endif


#if (MCU_INIT_CLOCK == STD_ON)
/* When clock_ip notifications are enabled, then callback is install to receive notifications.
*/
#if (\
(defined(MCU_DISABLE_DEM_REPORT_ERROR_STATUS) && (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)) ||   \
(defined(MCU_CMU_ERROR_ISR_USED) && (MCU_CMU_ERROR_ISR_USED == STD_ON))                            ||   \
defined(MCU_ERROR_ISR_NOTIFICATION)                                                                     \
)
#define CLOCK_IP_ENABLE_NOTIFICATIONS STD_ON
#else
#define CLOCK_IP_ENABLE_NOTIFICATIONS STD_OFF
#endif
#else
#define CLOCK_IP_ENABLE_NOTIFICATIONS STD_OFF
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#if (\
    (defined(MCU_DISABLE_DEM_REPORT_ERROR_STATUS) && (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)) || \
    (defined(MCU_ERROR_ISR_NOTIFICATION)) || \
    (defined(POWER_IP_REPORT_VLPSA_NOTIFICATION)) \
    )
#define POWER_IP_ENABLE_NOTIFICATIONS STD_ON
#else
#define POWER_IP_ENABLE_NOTIFICATIONS STD_OFF
#endif


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
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

#if (MCU_INIT_CLOCK == STD_ON)
void Mcu_ClkSrcFailureNotification(Clock_Ip_NameType ClockName);
#endif /* (MCU_INIT_CLOCK == STD_ON) */

void Mcu_Ipw_Init(const Mcu_HwIPsConfigType * HwIPsConfigPtr);

void Mcu_Ipw_SetMode(const Mcu_ModeConfigType * ModeConfigPtr);

#ifndef MCU_MAX_NORAMCONFIGS
Std_ReturnType Mcu_Ipw_InitRamSection(const Mcu_RamConfigType * RamConfigPtr);
#endif /* ifndef MCU_MAX_NORAMCONFIGS */

#if (MCU_INIT_CLOCK == STD_ON)
void Mcu_Ipw_InitClock(const Mcu_ClockConfigType * ClockConfigPtr);
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#if (MCU_INIT_CLOCK == STD_ON)
    #if (MCU_NO_PLL == STD_OFF)
void Mcu_Ipw_DistributePllClock(void);
    #endif /* (MCU_NO_PLL == STD_OFF) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#if (MCU_NO_PLL == STD_OFF)
Mcu_PllStatusType Mcu_Ipw_GetPllStatus(void);
#endif /* (MCU_NO_PLL == STD_OFF) */

#if MCU_PERFORM_RESET_API == STD_ON
void Mcu_Ipw_PerformReset(const Mcu_HwIPsConfigType * HwIPsConfigPtr);
#endif /* (MCU_PERFORM_RESET_API == STD_ON) */

Mcu_ResetType Mcu_Ipw_GetResetReason(void);

Mcu_RawResetType Mcu_Ipw_GetResetRawValue(void);

#if (MCU_POWERMODE_STATE_API == STD_ON)
Mcu_PowerModeStateType Mcu_Ipw_GetPowerModeState(void);
#endif /* (MCU_POWERMODE_STATE_API == STD_ON) */

#ifdef MCU_DISABLE_CMU_API
#if (MCU_DISABLE_CMU_API == STD_ON)
void Mcu_Ipw_DisableCmu(Clock_Ip_NameType ClockName);
#endif
#endif

#ifdef MCU_EMIOS_CONFIGURE_GPREN_API
#if (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON)
void Mcu_Ipw_EmiosConfigureGpren(uint8 Module, uint8 Value);
#endif
#endif

#ifdef MCU_GET_CLOCK_FREQUENCY_API
#if (MCU_GET_CLOCK_FREQUENCY_API == STD_ON)
uint32 MCU_Ipw_GetClockFrequency(Clock_Ip_NameType ClockName);
#endif /* (MCU_GET_CLOCK_FREQUENCY_API == STD_ON) */
#endif /* MCU_GET_CLOCK_FREQUENCY_API */


#ifdef MCU_SLEEPONEXIT_SUPPORT
  #if (MCU_SLEEPONEXIT_SUPPORT == STD_ON)
void Mcu_Ipw_SleepOnExit(Mcu_SleepOnExitType SleepOnExit);
  #endif
#endif

#ifdef MCU_SRAM_RETEN_CONFIG_API
#if (MCU_SRAM_RETEN_CONFIG_API == STD_ON)
/**
 * @brief   Configuration for SRAM retention.
 *
 * @details This function configure for both SRAML_RETEN and SRAMU_RETEN bits.
 *
 * @return                   void
 */
void Mcu_Ipw_SRAMRetentionConfig(Mcu_SRAMRetenConfigType SRAMRetenConfig);
#endif
#endif

#ifdef MCU_PMCAECONFIG_API
#if (MCU_PMCAECONFIG_API == STD_ON)
void Mcu_Ipw_PmcAeConfig(const Mcu_HwIPsConfigType * HwIPsConfigPtr);
#endif /* (MCU_PMCAECONFIG_API == STD_ON) */
#endif 

#ifdef MCU_AECRESETCONFIG_API
#if (MCU_AECRESETCONFIG_API == STD_ON)
void Mcu_Ipw_AecResetConfig(const Mcu_HwIPsConfigType * HwIPsConfigPtr);
#endif /* (MCU_AECRESETCONFIG_API == STD_ON) */
#endif 

#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
#endif /* MCU_IPW_H */

