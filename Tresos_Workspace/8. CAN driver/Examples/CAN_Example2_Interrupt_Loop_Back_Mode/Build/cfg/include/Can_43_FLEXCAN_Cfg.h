/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXCAN
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   (c) Copyright 2020-2024 NXP Semiconductors
*   All Rights Reserved.
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
/*
@brief   The consistency of the configuration must be checked by the configuration tool(s).
@brief   (SWS_Can_00022) The code configuration of the Can module is CAN controller specific.
         If the CAN controller is sited on-chip, the code generation tool for the Can module is Controller specific.
         If the CAN controller is an external device the generation tool must not be Controller specific.
@brief   (SWS_Can_00024) The valid values that can be configured are hardware dependent.
         Therefore the rules and constraints can't be given in the standard.
         The configuration tool is responsible to do a static configuration checking, also regarding dependencies between modules (i.e. Port driver, MCU driver etc.)
*/
/*
* @file    Can_Cfg.h
*/

#ifndef CAN_43_FLEXCAN_CFG_H
#define CAN_43_FLEXCAN_CFG_H

/**
*   @file    Can_43_FLEXCAN_Cfg.h
*   @version 2.0.0
*
*   @brief   AUTOSAR Can_43_FLEXCAN - module interface
*   @details Configuration settings generated by user settings.
*
*   @addtogroup CAN_43_FLEXCAN_DRIVER
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, External identifiers shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, Identifiers declared in the same scope and name space shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, Macro identifiers shall be distinct.
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, Identifiers shall be distinct from macro names.
* The used compilers use more than 31 chars for identifiers.
*
* @section Can_43_FLEXCAN_Cfg_h_REF_1
* Violates MISRA 2012 Advisory Rule 2.5, A project should not contain unused macro declarations.
* Some macro are required by ASR even they are not use in MCAL layer
*
* @section Can_43_FLEXCAN_Cfg_h_REF_2
* Violates MISRA 2012 Advisory Rule 4.9, A function should be used in preference to a function-like macro where they are interchangeable.
* Function like macro are used to reduce code complexity
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Can_43_FLEXCAN_PBcfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           Can_43_FLEXCAN_Cfg.h
*/
#define CAN_43_FLEXCAN_VENDOR_ID_CFG_H                     43
#define CAN_43_FLEXCAN_MODULE_ID_CFG_H                     80
#define CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION_CFG_H      4
#define CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION_CFG_H      7
#define CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION_CFG_H   0
#define CAN_43_FLEXCAN_SW_MAJOR_VERSION_CFG_H              2
#define CAN_43_FLEXCAN_SW_MINOR_VERSION_CFG_H              0
#define CAN_43_FLEXCAN_SW_PATCH_VERSION_CFG_H              0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Can_43_FLEXCAN_PBcfg.h configuration header file are of the same vendor */
#if (CAN_43_FLEXCAN_VENDOR_ID_PBCFG_H != CAN_43_FLEXCAN_VENDOR_ID_CFG_H)
#error "Can_43_FLEXCAN_PBcfg.h and Can_43_FLEXCAN_Cfg.h have different vendor IDs"
#endif
/* Check if header file and Can_43_FLEXCAN_PBcfg.h configuration header file are of the same Autosar version */
#if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION_PBCFG_H != CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
(CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION_PBCFG_H != CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION_CFG_H) || \
(CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION_PBCFG_H != CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION_CFG_H) \
)
#error "AutoSar Version Numbers of Can_43_FLEXCAN_PBcfg.h and Can_43_FLEXCAN_Cfg.h are different"
#endif
/* Check if header file and Can_43_FLEXCAN_PBcfg.h configuration header file are of the same software version */
#if ((CAN_43_FLEXCAN_SW_MAJOR_VERSION_PBCFG_H != CAN_43_FLEXCAN_SW_MAJOR_VERSION_CFG_H) || \
(CAN_43_FLEXCAN_SW_MINOR_VERSION_PBCFG_H != CAN_43_FLEXCAN_SW_MINOR_VERSION_CFG_H) || \
(CAN_43_FLEXCAN_SW_PATCH_VERSION_PBCFG_H != CAN_43_FLEXCAN_SW_PATCH_VERSION_CFG_H) \
)
#error "Software Version Numbers of Can_43_FLEXCAN_PBcfg.h and Can_43_FLEXCAN_Cfg.h are different"
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
*   @brief      Enable/Disable Precompile Support
*/
#define CAN_43_FLEXCAN_PRECOMPILE_SUPPORT    (STD_OFF)

/**
*   @brief      Number of Can Controller Support
*/
#define CAN_43_FLEXCAN_HWCONTROLLER_SUPPORT    3U

/**
*   @brief      Controller unsed
*/
#define CAN_43_FLEXCAN_CONTROLLER_UNUSED    ((uint8)0xFFU)

/**
*   @brief      The definition represent for Message buffer index which not assigned for any Hw Object
*/
#define CAN_43_FLEXCAN_HWOBJ_UNMAPPED    ((Can_HwHandleType)0xFFFFU)

/**
*   @brief      The definition represent for number of ECUC partition configured.
*/
#define CAN_43_FLEXCAN_MAX_PARTITIONS    1U

/**
*   @brief      Number Of Hw Message Buffer support
*/
#define CAN_43_FLEXCAN_HWMB_COUNT    ((uint8)32U)

/**
*  @brief      The definition of TimeStamp Enable Support for Hw Objects
*/
#define CAN_43_FLEXCAN_TIMESTAMP_ENABLE    (STD_OFF)

/* @brief Has external timer used for timestamp */


#define CAN_43_FLEXCAN_TS_EXTERNAL_TIMER_USED    (STD_OFF)
/**
*   @brief      The definition used for guarding GetCoreID/Multicore
*/
#define CAN_43_FLEXCAN_MULTICORE_ENABLED    (STD_OFF)

/**
*   @brief      Define if global variables need to be placed in non-cache area or not
*/
#define CAN_43_FLEXCAN_NO_CACHE_NEEDED    (STD_OFF)

/**
*   @brief      Enable/Disable Development Error Detection and Notification
*/
#define CAN_43_FLEXCAN_DEV_ERROR_DETECT    (STD_OFF)

/**
*   @brief      Enable/Disable support Can_GetVersionInfo API
*/
#define CAN_43_FLEXCAN_VERSION_INFO_API    (STD_OFF)

/**
*   @brief      Enable/Disable support Can_SetBaudrate API
*/
#define CAN_43_FLEXCAN_SET_BAUDRATE_API    (STD_OFF)

/**
*   @brief      Enable/Disable support Can_AbortMb API
*/
#define CAN_43_FLEXCAN_ABORT_MB_API    (STD_OFF)

/**
*   @brief      Enable/Disable LPdu Callout Function
*/
#define CAN_43_FLEXCAN_LPDU_CALLOUT_FUNC_ENABLE    (STD_OFF)

/**
*   @brief      Enable/Disable Extended Range of Can Hw Object
*/
#define CAN_43_FLEXCAN_MBCOUNTEXTENSION    (STD_OFF)

/**
*   @brief      Instance of the Can Hw unit
*/
#define CAN_43_FLEXCAN_INSTANCE    ((uint8)0U)

/**
*   @brief      Enable/Disable support Dual Clock Mode
*/
#define CAN_43_FLEXCAN_DUAL_CLOCK_MODE    (STD_OFF)

/**
*   @brief      Enable/Disable support Listen Only Mode
*/
#define CAN_43_FLEXCAN_LISTEN_ONLY_MODE    (STD_OFF)

/**
* @brief          Enable/Disable LPdu Receive callout function support
*/
#define CAN_43_FLEXCAN_LPDU_CALLOUT_SUPPORT    (STD_OFF)
#define CAN_43_FLEXCAN_LPDU_CALLOUT_FUNC_CALLED    

/**
*   @brief      Symbolic Name generated for CanMainFunctionRWPeriods
*/

/**
*   @brief      Period for cyclic call of Main Function Read/Write
*/

#define CAN_43_FLEXCAN_MAINFUNCTION_MULTIPLE_WRITE    (STD_OFF)
#define CAN_43_FLEXCAN_MAINFUNCTION_MULTIPLE_READ    (STD_OFF)

/**
*   @brief      Period for cyclic call of Main Function Mode
*/
#define CAN_43_FLEXCAN_MAINFUNCTION_MODE_PERIOD    (0.001F)



/**
*   @brief      Supporting Pretended Networking
*/
#define CAN_43_FLEXCAN_PUBLIC_ICOM_SUPPORT    (STD_OFF)

/**
*   @brief      Number Of Can Controller Config
*/
#define CAN_43_FLEXCAN_CONTROLLER_CONFIG_COUNT    (1U)

/**
*   @brief      Number Of HardwareObject Config
*/
#define CAN_43_FLEXCAN_HWOBJECT_CONFIG_COUNT    ((Can_HwHandleType)2U)

/**
*   @brief      Symbolic Name generated for Can Controller
*/
#define CanController_0    ((uint8)0U)

/**
*   @brief      Symbolic Name generated for Can HardwareObject
*/
#define CanHardwareObject_0    ((Can_HwHandleType)0U)
#define CanHardwareObject_1    ((Can_HwHandleType)1U)

/**
*   @brief      Enable/Disable support  Can_CheckWakeup API
*/
#define CAN_43_FLEXCAN_CHECK_WAKEUP_API    (STD_OFF)

/**
*   @brief      Can Tx Polling support
*/
#define CAN_43_FLEXCAN_TX_POLLING_SUPPORT    (STD_OFF)

/**
*   @brief      Can Rx Polling support
*/
#define CAN_43_FLEXCAN_RX_POLLING_SUPPORT    (STD_OFF)

/**
*   @brief      Can Bus Off Polling support
*/
#define CAN_43_FLEXCAN_BUSOFF_POLLING_SUPPORT    (STD_OFF)

/**
*   @brief      Can Wakeup Polling support
*/
#define CAN_43_FLEXCAN_WAKEUP_POLLING_SUPPORT    (STD_ON)

/**
*   @brief      Can Wakeup support
*/
#define CAN_43_FLEXCAN_WAKEUP_SUPPORT    (STD_OFF)

/**
*   @brief      Can Rx/Tx common interrupt support
*/


/**
*   @brief      The definition was represented for at least one Hw Object enabled trigger transmit.
*/
#define CAN_43_FLEXCAN_TRIGGER_TRANSMIT_USED    (STD_OFF)


#define CAN_43_FLEXCAN_CONFIG_EXT \
    CAN_43_FLEXCAN_CONFIG_PB


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* _CAN_43_FLEXCAN_CFG_H_ */
