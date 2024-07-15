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

#ifndef POWER_IP_CFG_H
#define POWER_IP_CFG_H


/**
*   @file       Power_Ip_Cfg.h
*   @version    2.0.0
*
*   @brief   AUTOSAR Mcu - Post-Build(PB) configuration file code template.
*   @details Code template for Post-Build(PB) configuration file generation.
*
*   @addtogroup POWER_DRIVER_CONFIGURATION Power Ip Driver
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
#include "Power_Ip_PBcfg.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_CFG_VENDOR_ID                      43
#define POWER_IP_CFG_AR_RELEASE_MAJOR_VERSION       4
#define POWER_IP_CFG_AR_RELEASE_MINOR_VERSION       7
#define POWER_IP_CFG_AR_RELEASE_REVISION_VERSION    0
#define POWER_IP_CFG_SW_MAJOR_VERSION               2
#define POWER_IP_CFG_SW_MINOR_VERSION               0
#define POWER_IP_CFG_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_Cfg.h file and Power_Ip_PBcfg.h file are of the same vendor */
#if (POWER_IP_CFG_VENDOR_ID != POWER_IP_PBCFG_VENDOR_ID)
    #error "Power_Ip_Cfg.h and Power_Ip_PBcfg.h have different vendor ids"
#endif

/* Check if Power_Ip_Cfg.h file and Power_Ip_PBcfg.h file are of the same Autosar version */
#if ((POWER_IP_CFG_AR_RELEASE_MAJOR_VERSION != POWER_IP_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_CFG_AR_RELEASE_MINOR_VERSION != POWER_IP_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_CFG_AR_RELEASE_REVISION_VERSION != POWER_IP_PBCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_Cfg.h and Power_Ip_PBcfg.h are different"
#endif

/* Check if Power_Ip_Cfg.h file and Power_Ip_PBcfg.h file are of the same Software version */
#if ((POWER_IP_CFG_SW_MAJOR_VERSION != POWER_IP_PBCFG_SW_MAJOR_VERSION) || \
     (POWER_IP_CFG_SW_MINOR_VERSION != POWER_IP_PBCFG_SW_MINOR_VERSION) || \
     (POWER_IP_CFG_SW_PATCH_VERSION != POWER_IP_PBCFG_SW_PATCH_VERSION) \
    )
  #error "Software Version Numbers of Power_Ip_Cfg.h and Power_Ip_PBcfg.h are different"
#endif
/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/
#define POWER_IP_DEV_ERROR_DETECT         (STD_OFF)

#define POWER_IP_TIMEOUT_TYPE                (OSIF_COUNTER_DUMMY)

#define POWER_IP_TIMEOUT_VALUE_US            (50000U)

/**
* @brief        Support for User mode.
*               If this parameter has been configured to 'TRUE' the Power can be executed from both supervisor and user mode.
*/
#define POWER_IP_ENABLE_USER_MODE_SUPPORT  (STD_OFF)

/** Check the driver user mode is enabled only when the MCAL_ENABLE_USER_MODE_SUPPORT is enabled */
#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT)
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Power in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined.
  #endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/**
* @brief            Create defines with the values assigned to Mcu Reset Reason configurations.
*                   These values can be  retrieved from Mcu_GetResetReason Api.
*/


#define McuConf_McuResetReasonConf_MCU_STOP_ACKNOWLEDGE_ERROR_RESET   ((uint8)0U)


#define McuConf_McuResetReasonConf_MCU_MDM_AP_SYSTEM_RESET   ((uint8)1U)


#define McuConf_McuResetReasonConf_MCU_SW_RESET   ((uint8)2U)


#define McuConf_McuResetReasonConf_MCU_CORE_LOCKUP_RESET   ((uint8)3U)


#define McuConf_McuResetReasonConf_MCU_JTAG_RESET   ((uint8)4U)


#define McuConf_McuResetReasonConf_MCU_POWER_ON_RESET   ((uint8)5U)


#define McuConf_McuResetReasonConf_MCU_EXTERNAL_PIN_RESET   ((uint8)6U)


#define McuConf_McuResetReasonConf_MCU_WATCHDOG_RESET   ((uint8)7U)


#define McuConf_McuResetReasonConf_MCU_CMU_LOSS_OF_CLOCK_RESET   ((uint8)8U)


#define McuConf_McuResetReasonConf_MCU_LOSS_OF_LOCK_RESET   ((uint8)9U)


#define McuConf_McuResetReasonConf_MCU_LOSS_OF_CLOCK_RESET   ((uint8)10U)


#define McuConf_McuResetReasonConf_MCU_LOW_OR_HIGH_VOLTAGE_DETECT_RESET   ((uint8)11U)


#define McuConf_McuResetReasonConf_MCU_NO_RESET_REASON   ((uint8)12U)


#define McuConf_McuResetReasonConf_MCU_MULTIPLE_RESET_REASON   ((uint8)13U)


#define McuConf_McuResetReasonConf_MCU_RESET_UNDEFINED   ((uint8)14U)


/***********************************************************/
/*             RCM_GetResetRawValue Defines             */
/***********************************************************/
/** @brief This is the corresponding bit of Stop Acknowledge Error reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_SACKERR      ((uint32)0x00002000U)
/** @brief This is the corresponding bit of MDM-AP System Reset Request in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_MDM_AP       ((uint32)0x00000800U)
/** @brief This is the corresponding bit of Software reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_SW           ((uint32)0x00000400U)
/** @brief This is the corresponding bit of Stop Core Lockup reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_LOCKUP       ((uint32)0x00000200U)
/** @brief This is the corresponding bit of JTAG generated reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_JTAG         ((uint32)0x00000100U)
/** @brief This is the corresponding bit of Power-on reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_POR          ((uint32)0x00000080U)
/** @brief This is the corresponding bit of external pin reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_PIN          ((uint32)0x00000040U)
/** @brief This is the corresponding bit of watchdog reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_WDOG         ((uint32)0x00000020U)
/** @brief This is the corresponding bit of CMU Loss-of-Lock reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_CMU_LOC      ((uint32)0x00000010U)
/** @brief This is the corresponding bit of Loss-of-Lock reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_LOL          ((uint32)0x00000008U)
/** @brief This is the corresponding bit of Loss-of-Clock reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_LOC          ((uint32)0x00000004U)
/** @brief This is the corresponding bit of Low-Voltage Detect reset or High-Voltage Detect reset in the returned value of Mcu_GetResetRawReason */
#define MCU_RAW_RESET_LVD          ((uint32)0x00000002U)

/*==================================================================================================
                                             ENUMS
==================================================================================================*/
/**
* @brief            The type Power_Ip_ResetType, represents the different reset that a specified POWER_IP can have.
* @details          The POWER_IP shall provide at least the values MCU_POWER_ON_RESET and MCU_RESET_UNDEFINED for the enumeration Power_Ip_ResetType.
*
* @implements Power_Ip_ResetType_Enumeration
*/
typedef enum
{
    MCU_STOP_ACKNOWLEDGE_ERROR_RESET = McuConf_McuResetReasonConf_MCU_STOP_ACKNOWLEDGE_ERROR_RESET,            /**< @brief Stop Acknowledge Error reset . RCM_SRS[SACKERR]. */
    MCU_MDM_AP_SYSTEM_RESET = McuConf_McuResetReasonConf_MCU_MDM_AP_SYSTEM_RESET,                              /**< @brief MDM-AP System Reset Request . RCM_SRS[MDM_AP]. */
    MCU_SW_RESET = McuConf_McuResetReasonConf_MCU_SW_RESET,                                                    /**< @brief Software reset . RCM_SRS[SW]. */
    MCU_CORE_LOCKUP_RESET = McuConf_McuResetReasonConf_MCU_CORE_LOCKUP_RESET,                                  /**< @brief Core Lockup reset . RCM_SRS[LOCKUP]. */
    MCU_JTAG_RESET = McuConf_McuResetReasonConf_MCU_JTAG_RESET,                                                /**< @brief JTAG generated reset . RCM_SRS[JTAG]. */
    MCU_POWER_ON_RESET = McuConf_McuResetReasonConf_MCU_POWER_ON_RESET,                                        /**< @brief Power-on reset. RCM_SRS[POR]. */
    MCU_EXTERNAL_PIN_RESET = McuConf_McuResetReasonConf_MCU_EXTERNAL_PIN_RESET,                                /**< @brief External Reset Pin. RCM_SRS[PIN]. */
    MCU_WATCHDOG_RESET = McuConf_McuResetReasonConf_MCU_WATCHDOG_RESET,                                        /**< @brief Watchdog reset. RCM_SRS[Watchdog]. */
    MCU_CMU_LOSS_OF_CLOCK_RESET = McuConf_McuResetReasonConf_MCU_CMU_LOSS_OF_CLOCK_RESET,                      /**< @brief CMU Loss-of-Clock Reset. RCM_SRS[CMU_LOC]. */
    MCU_LOSS_OF_LOCK_RESET = McuConf_McuResetReasonConf_MCU_LOSS_OF_LOCK_RESET,                                /**< @brief Loss-of-Lock Reset. RCM_SRS[LOL]. */
    MCU_LOSS_OF_CLOCK_RESET = McuConf_McuResetReasonConf_MCU_LOSS_OF_CLOCK_RESET,                              /**< @brief Loss-of-Clock Reset. RCM_SRS[LOC]. */
    MCU_LOW_OR_HIGH_VOLTAGE_DETECT_RESET = McuConf_McuResetReasonConf_MCU_LOW_OR_HIGH_VOLTAGE_DETECT_RESET,    /**< @brief Low-Voltage Detect Reset or High-Voltage Detect Reset. RCM_SRS[LVD]. */

    MCU_NO_RESET_REASON = McuConf_McuResetReasonConf_MCU_NO_RESET_REASON,                                      /**< @brief No reset reason found */
    MCU_MULTIPLE_RESET_REASON = McuConf_McuResetReasonConf_MCU_MULTIPLE_RESET_REASON,                          /**< @brief More than one reset events are logged except "Power on event" */
    MCU_RESET_UNDEFINED = McuConf_McuResetReasonConf_MCU_RESET_UNDEFINED                                       /**< @brief Undefined reset source. */

} Power_Ip_ResetType;

/**
* @brief            Type of parameter value of the function Mcu_SRAMRetentionConfig.
* @details          The type of Power_Ip_SRAMRetenConfigType is an enumeration with the following values:
*                       MCU_SRAML_RETEN, MCU_SRAMU_RETEN, MCU_SRAMLU_RETEN, MCU_NO_SRAMLU_RETEN.
*/
typedef enum
{
    MCU_SRAML_RETEN = (uint32)0x00100000U,   /**< @brief SRAML will be retain only. */
    MCU_SRAMU_RETEN = (uint32)0x00200000U,   /**< @brief SRAMU will be retain only. */
    MCU_SRAMLU_RETEN = (uint32)0x00000000U,   /**< @brief Both SRAML and SRAMU will be retain. */
    MCU_NO_SRAMLU_RETEN = (uint32)0x00300000U,   /**< @brief Both SRAML and SRAMU will not be retain. */
} Power_Ip_SRAMRetenConfigType;

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* #ifndef POWER_IP_CFG_H */

