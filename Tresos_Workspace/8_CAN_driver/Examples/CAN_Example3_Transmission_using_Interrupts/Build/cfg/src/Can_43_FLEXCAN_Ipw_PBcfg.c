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

/**
*   @file    Can_43_FLEXCAN_Ipw_PBcfg.c
*   @version 2.0.0
*
*   @brief   AUTOSAR Can_43_FLEXCAN - module interface
*   @details Configuration Structures for PostBuild
*
*   @addtogroup CAN_43_FLEXCAN_DRIVER
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
#include "Can_43_FLEXCAN_Ipw_Cfg.h"
#include "Can_43_FLEXCAN_Ipw_Types.h"
#include "FlexCAN_Ip.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           Can_43_FLEXCAN_Ipw_PBcfg.c
*/
#define CAN_43_FLEXCAN_IPW_PBCFG_VENDOR_ID_C                     43
#define CAN_43_FLEXCAN_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define CAN_43_FLEXCAN_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C      7
#define CAN_43_FLEXCAN_IPW_PBCFG_AR_RELEASE_REVISION_VERSION_C   0
#define CAN_43_FLEXCAN_IPW_PBCFG_SW_MAJOR_VERSION_C              2
#define CAN_43_FLEXCAN_IPW_PBCFG_SW_MINOR_VERSION_C              0
#define CAN_43_FLEXCAN_IPW_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Can_43_FLEXCAN_Ipw_Cfg.h are of the same vendor */
#if (CAN_43_FLEXCAN_IPW_PBCFG_VENDOR_ID_C != CAN_43_FLEXCAN_IPW_CFG_VENDOR_ID)
    #error "Can_43_FLEXCAN_Ipw_PBcfg.c and Can_43_FLEXCAN_Ipw_Cfg.h have different vendor ids"
#endif
/* Check if current file and Can_43_FLEXCAN_Ipw_Cfg.h are of the same Autosar version */
#if ((CAN_43_FLEXCAN_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C    != CAN_43_FLEXCAN_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C    != CAN_43_FLEXCAN_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_IPW_PBCFG_AR_RELEASE_REVISION_VERSION_C != CAN_43_FLEXCAN_IPW_CFG_AR_RELEASE_REVISION_VERSION)\
    )
    #error "AutoSar Version Numbers of Can_43_FLEXCAN_Ipw_PBcfg.c and Can_43_FLEXCAN_Ipw_Cfg.h are different"
#endif
/* Check if current file and Can_43_FLEXCAN_Ipw_Cfg.h are of the same Software version */
#if ((CAN_43_FLEXCAN_IPW_PBCFG_SW_MAJOR_VERSION_C != CAN_43_FLEXCAN_IPW_CFG_SW_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_IPW_PBCFG_SW_MINOR_VERSION_C != CAN_43_FLEXCAN_IPW_CFG_SW_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_IPW_PBCFG_SW_PATCH_VERSION_C != CAN_43_FLEXCAN_IPW_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Can_43_FLEXCAN_Ipw_PBcfg.c and Can_43_FLEXCAN_Ipw_Cfg.h are different"
#endif

/* Check if current file and FlexCAN_Ip header file are of the same vendor */
#if (CAN_43_FLEXCAN_IPW_PBCFG_VENDOR_ID_C != FLEXCAN_IP_VENDOR_ID_H)
    #error "Can_43_FLEXCAN_Ipw_PBcfg.c and FlexCAN_Ip.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip header file are of the same Autosar version */
#if ((CAN_43_FLEXCAN_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C     != FLEXCAN_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C     != FLEXCAN_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IPW_PBCFG_AR_RELEASE_REVISION_VERSION_C  != FLEXCAN_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_43_FLEXCAN_Ipw_PBcfg.c and FlexCAN_Ip.h are different"
#endif
/* Check if current file and FlexCAN_Ip header file are of the same Software version */
#if ((CAN_43_FLEXCAN_IPW_PBCFG_SW_MAJOR_VERSION_C != FLEXCAN_IP_SW_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IPW_PBCFG_SW_MINOR_VERSION_C != FLEXCAN_IP_SW_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IPW_PBCFG_SW_PATCH_VERSION_C != FLEXCAN_IP_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_43_FLEXCAN_Ipw_PBcfg.c and FlexCAN_Ip.h are different"
#endif

/* Check if current file and Can_43_FLEXCAN_Ipw_Types.h are of the same vendor */
#if (CAN_43_FLEXCAN_IPW_PBCFG_VENDOR_ID_C != CAN_43_FLEXCAN_IPW_TYPES_VENDOR_ID_H)
    #error "Can_43_FLEXCAN_Ipw_PBcfg.c and Can_43_FLEXCAN_Ipw_Types.h have different vendor IDs"
#endif
/* Check if current file and Can_43_FLEXCAN_Ipw_Types.h are of the same Autosar version */
#if ((CAN_43_FLEXCAN_IPW_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
    (CAN_43_FLEXCAN_IPW_PBCFG_AR_RELEASE_MINOR_VERSION_C != CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
    (CAN_43_FLEXCAN_IPW_PBCFG_AR_RELEASE_REVISION_VERSION_C != CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
#error "AutoSar Version Numbers of Can_43_FLEXCAN_Ipw_PBcfg.c and Can_43_FLEXCAN_Ipw_Types.h are different"
#endif
/* Check if current file and Can_43_FLEXCAN_Ipw_Types.h are of the same software version */
#if ((CAN_43_FLEXCAN_IPW_PBCFG_SW_MAJOR_VERSION_C != CAN_43_FLEXCAN_IPW_TYPES_SW_MAJOR_VERSION_H) || \
    (CAN_43_FLEXCAN_IPW_PBCFG_SW_MINOR_VERSION_C != CAN_43_FLEXCAN_IPW_TYPES_SW_MINOR_VERSION_H) || \
    (CAN_43_FLEXCAN_IPW_PBCFG_SW_PATCH_VERSION_C != CAN_43_FLEXCAN_IPW_TYPES_SW_PATCH_VERSION_H) \
    )
#error "Software Version Numbers of Can_43_FLEXCAN_Ipw_PBcfg.c and Can_43_FLEXCAN_Ipw_Types.h are different"
#endif

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define CAN_43_FLEXCAN_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_43_FLEXCAN_MemMap.h"

/**
* @brief   Export FLEXCAN configurations.
*/
const Can_43_FLEXCAN_Ipw_HwChannelConfigType Can_43_FLEXCANIpwHwChannelConfig0 =
{
    /* Here should be included the structure from FLEXCAN_IP_CFg*/
    &Flexcan_aCtrlConfigPB[0U]
};

/* PN configuration wrapper */

#define CAN_43_FLEXCAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Can_43_FLEXCAN_MemMap.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */
