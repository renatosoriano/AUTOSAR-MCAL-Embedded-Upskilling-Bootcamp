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

#ifndef POWER_IP_TRUSTEDFUNCTIONS_H
#define POWER_IP_TRUSTEDFUNCTIONS_H

/**
*   @file    Power_Ip_TrustedFunctions.h
*   @version    2.0.0
*
*   @brief   POWER IP type header file.
*   @details POWER IP type header file.

*   @addtogroup CLOCK_DRIVER Clock Ip Driver
*   @{
*/

#if defined(__cplusplus)
extern "C"{
#endif
/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_TRUSTEDFUNCTIONS_VENDOR_ID                       43
#define POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MAJOR_VERSION        4
#define POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_MINOR_VERSION        7
#define POWER_IP_TRUSTEDFUNCTIONS_AR_RELEASE_REVISION_VERSION     0
#define POWER_IP_TRUSTEDFUNCTIONS_SW_MAJOR_VERSION                2
#define POWER_IP_TRUSTEDFUNCTIONS_SW_MINOR_VERSION                0
#define POWER_IP_TRUSTEDFUNCTIONS_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/




/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef POWER_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)

#ifdef POWER_IP_SLEEPONEXIT_SUPPORT
#if (POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON)
/**
 * @brief        The function disables SLEEPONEXIT bit.
 *
 * @param        None
 * @return       None
 *
 */
extern void Power_Ip_CM4_DisableSleepOnExit(void);

/**
 * @brief        The function enables SLEEPONEXIT bit.
 *
 * @param        None
 * @return       None
 *
 */
extern void Power_Ip_CM4_EnableSleepOnExit(void);
  #endif
#endif

/**
 * @brief        The function enables DEEPSLEEP.
 *
 * @param        None
 * @return       None
 *
 */
extern void Power_Ip_CM4_EnableDeepSleep(void);

/**
 * @brief        The function disables DEEPSLEEP.
 *
 * @param        None
 * @return       None
 *
 */
extern void Power_Ip_CM4_DisableDeepSleep(void);

#if (POWER_IP_PERFORM_RESET_API == STD_ON)
/**
 * @brief        The function initiates a system reset request to reset the SoC.
 *
 * @param        None
 * @return       None
 *
 */
extern void Power_Ip_CM4_SystemReset(void);
#endif

/**
 * @brief        This function configure the Power Management Controller
 *
 * @param        ConfigPtr   Pointer to PMC configuration structure.
 * @return       None
 *
 */
extern void Power_Ip_PMC_PowerInit(const Power_Ip_PMC_ConfigType * ConfigPtr);

#if (defined(POWER_IP_DISABLE_RCM_INIT) && (STD_OFF == POWER_IP_DISABLE_RCM_INIT))
/**
 * @brief        This function initializes the Reset parameters.
 *
 * @param        ConfigPtr   Pointer to the RCM configuration structure.
 * @return       None
 *
 */
extern void Power_Ip_RCM_ResetInit(const Power_Ip_RCM_ConfigType * ConfigPtr);
#endif

/**
 * @brief        This function returns the Reset reason.
 *
 * @param        None
 * @return       None
 *
 */
extern uint32 Power_Ip_RCM_GetResetReason(void);

/**
 * @brief        This function returns the Raw Reset value.
 *
 * @param        None
 * @return       Register value with the Reset status.
 *
 */
extern Power_Ip_RawResetType Power_Ip_RCM_GetResetRawValue(void);

#ifdef POWER_IP_SRAM_RETEN_CONFIG_API
#if (POWER_IP_SRAM_RETEN_CONFIG_API == STD_ON)
/**
 * @brief        Configuration for SRAM retention.
 *
 * @param        None
 * @return       None
 *
 */
extern void Power_Ip_SIM_SRAMRetentionConfig(Power_Ip_SRAMRetenConfigType SRAMRetenConfig);

#endif
#endif

#if (defined(POWER_IP_DISABLE_SMC_INIT) && (STD_OFF == POWER_IP_DISABLE_SMC_INIT))
/**
 * @brief        This function will configure the allowed modes
 *
 * @param        ConfigPtr
 * @return       None
 *
 */
extern void Power_Ip_SMC_AllowedModesConfig(const Power_Ip_SMC_ConfigType * ConfigPtr);
#endif

/**
 * @brief        This function switches the mode by writing SMC_PMCTRL and SMC_STOPCTRL.
 *
 * @param        ModeConfigPtr   Pointer to mode configuration structure.
 * @return       uint32
 *
 */
extern uint32 Power_Ip_SMC_ModeConfig(const Power_Ip_ModeConfigType * ModeConfigPtr);

  #endif
#endif /* POWER_IP_ENABLE_USER_MODE_SUPPORT */

/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#if defined(__cplusplus)
}
#endif /* __cplusplus*/

/*! @}*/

#endif /* CLOCK_IP_TRUSTEDFUNCTIONS_H */


