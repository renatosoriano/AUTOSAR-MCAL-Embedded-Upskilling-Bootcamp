/**
*   @file    CanIf_Types.h
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
#ifndef CANIF_TYPES_H
#define CANIF_TYPES_H

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
#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_TYPES_VENDOR_ID                         43
#define CANIF_TYPES_AR_RELEASE_MAJOR_VERSION          4
#define CANIF_TYPES_AR_RELEASE_MINOR_VERSION          7
#define CANIF_TYPES_AR_RELEASE_REVISION_VERSION       0
#define CANIF_TYPES_SW_MAJOR_VERSION                  2
#define CANIF_TYPES_SW_MINOR_VERSION                  0
#define CANIF_TYPES_SW_PATCH_VERSION                  0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Can_GeneralTypes.h header file are of the same version */
    #if ((CANIF_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_GENERALTYPES_AR_RELEASE_MAJOR_VERSION) || \
        (CANIF_TYPES_AR_RELEASE_MINOR_VERSION != CAN_GENERALTYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CanIf_Types.h and Can_GeneralTypes.h are different"
    #endif
#endif
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
typedef enum
{
    CANIF_EXTENDED_CAN = 0U,        /* CAN frame with extended identifier (29 bits) */
    CANIF_EXTENDED_FD_CAN,          /* CAN FD frame with extended identifier (29 bits) */
    CANIF_STANDARD_CAN,             /* CAN frame with standard identifier (11 bits) */
    CANIF_STANDARD_FD_CAN           /* CAN FD frame with standard identifier (11 bits) */
} CanIf_FrameType;
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* This is a function pointer type for the RxIndication function of all upper layers of CanIf. */
typedef void (*CanIf_UserRxIndicationPtrType)(PduIdType RxPduId, const PduInfoType * PduInfoPtr);
/* This is a function pointer type for the TxConfirmation function of all upper layers of CanIf. */
typedef void (*CanIf_UserTxConfirmationPtrType)(PduIdType CanIfTxPduId, Std_ReturnType result);

/* ----------------------Definition of function pointer types to CanDrv API(s)---------------------*/
/* Pointer to Can_Write */
typedef Std_ReturnType (*CanIf_CanWriteFuncPtrType)(Can_HwHandleType Hth, const Can_PduType * PduInfo);

/* -------------Pre-compile structures - which always are constant accorss all variants------------*/
typedef struct
{
    const CanIf_CanWriteFuncPtrType CanWrite;     /**< Pointer to corresponding Can_Write API defined in corresponding CanDRV */
} CanIf_CanDrvFuncPtrType;

typedef struct
{
    const uint8 CanDrvId;                           /**<  CanDrv Id confugred in CanIf */
    const Can_HwHandleType NumCanHoh;               /**<  Total number of HOH of CanDrv */
    const CanIf_CanDrvFuncPtrType * CanApi;         /**<  Pointer to Can_Write API */
} CanIf_CanDrvPCConfigType;

typedef struct
{
    const uint8 CanIfCtrlId;                            /**< Specifies the CanIf controller Id configured in CanIf Drv */
    const uint8 CanCtrlId;                              /**< Specifies the Can controller Id configured in Can Drv referred from CanIf Drv */
    const CanIf_CanDrvPCConfigType * CanDrvConfigPtr;  /**< The CanDrv which the CanIf controller refers to */
} CanIf_CtrlPCConfigType;

typedef struct
{
    const uint8 NumOfCtrl;
    const CanIf_CtrlPCConfigType * CanIfCtrlConfigPtr;
} CanIf_PCConfigType;
/* --------------------Postbuild structures - which can have different values accross all variants---*/
typedef struct
{
    const PduIdType PduId;                                  /* PduId */
    const boolean PduLengthCheck;                           /* Specifies if the Pdu length will be checked */
    const uint16 PduLength;                                 /* PduLength */
    const uint8 CanIfCtrlId;                                /* The CanIf controller Id which the PDU belongs to */
    const CanIf_UserRxIndicationPtrType UserRxIndication;   /*  UserRxIndication function pointer */
} CanIf_RxPduType;

typedef struct
{
    const PduIdType PduId;                                      /* PduId */
    const Can_IdType CanId;                                     /* CanId */
    const CanIf_FrameType CanFrameType;                         /* Frame type */
    const Can_HwHandleType CanHth;                              /* Hth */
    const uint8 CanIfCtrlId;                                    /* The CanIf controller Id which the PDU belongs to */
    const CanIf_UserTxConfirmationPtrType UserTxConfirmation;   /*  UserRxIndication function pointer */
} CanIf_TxPduType;

typedef struct
{
    const CanIf_RxPduType * const * HohToRxPduMappingPtr;
} CanIf_CanDrvConfigType;

#ifdef __cplusplus
}
#endif

#endif 
