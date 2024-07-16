/**
*   @file    CanIf.h
*   @version 2.0.0
*
*   @brief   AUTOSAR CanIf - CanIf module interface
*   @details AUTOSAR CanIf module interface.- Stub Version
*   This file contains sample code only. It is not part of the production code deliverables.
*
*   @addtogroup CANIF_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : generic
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   (c) Copyright 2020-2023 NXP Semiconductors
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

#ifndef CANIF_H
#define CANIF_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CanIf_Cfg.h"
#include "CanIf_Types.h"
#include "EcuM.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_VENDOR_ID                         43
#define CANIF_MODULE_ID                         60
#define CANIF_AR_RELEASE_MAJOR_VERSION          4
#define CANIF_AR_RELEASE_MINOR_VERSION          7
#define CANIF_AR_RELEASE_REVISION_VERSION       0
#define CANIF_SW_MAJOR_VERSION                  2
#define CANIF_SW_MINOR_VERSION                  0
#define CANIF_SW_PATCH_VERSION                  0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CanIf_Types.h header file are of the same vendor */
#if (CANIF_VENDOR_ID != CANIF_TYPES_VENDOR_ID)
#error "CanIf.h and CanIf_Types.h have different vendor ids"
#endif
/* Check if current file and CanIf_Types.h header file are of the same Autosar version */
#if ((CANIF_AR_RELEASE_MAJOR_VERSION != CANIF_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (CANIF_AR_RELEASE_MINOR_VERSION != CANIF_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (CANIF_AR_RELEASE_REVISION_VERSION != CANIF_TYPES_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of CanIf.h and CanIf_Types.h are different"
#endif
/* Check if current file and CanIf_Types.h header file are of the same software version */
#if ((CANIF_SW_MAJOR_VERSION != CANIF_TYPES_SW_MAJOR_VERSION) || \
     (CANIF_SW_MINOR_VERSION != CANIF_TYPES_SW_MINOR_VERSION) || \
     (CANIF_SW_PATCH_VERSION != CANIF_TYPES_SW_PATCH_VERSION))
  #error "Software Version Numbers of CanIf.h and CanIf_Types.h are different"
#endif

/* Check if current file and EcuM.h header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CANIF_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) || \
        (CANIF_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CanIf.h and EcuM.h are different"
    #endif
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
           
/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct
{
    const uint8 NumRxPdu;
    const uint8 NumTxPdu;
    const CanIf_CanDrvConfigType * const * CanDrvConfigPtr;
    const CanIf_RxPduType * CanIf_RxPduConfigPtr;
    const CanIf_TxPduType * CanIf_TxPduConfigPtr;
} CanIf_ConfigType;
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

CANIF_CONFIG_EXT

#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

void CanIf_Init(const CanIf_ConfigType * ConfigPtr);
Std_ReturnType CanIf_Transmit(PduIdType CanTxPduId, const PduInfoType * PduInfoPtr);
Std_ReturnType CanIf_TriggerTransmit(PduIdType TxPduId, PduInfoType * PduInfoPtr);
Std_ReturnType CanIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource);

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif                          /* CANIF_H */

/** @} */
