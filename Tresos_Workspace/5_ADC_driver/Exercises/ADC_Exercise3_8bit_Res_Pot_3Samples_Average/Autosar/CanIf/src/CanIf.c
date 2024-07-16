/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : generic
* Dependencies : 
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 2.0.0
* Build Version : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
* Copyright 2020-2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
/**
*   @file       CanIf.c
*
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
#include "CanIf.h"
#include "CanIf_Can.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CANIF_VENDOR_ID_C                         43
#define CANIF_MODULE_ID_C                         60
#define CANIF_AR_RELEASE_MAJOR_VERSION_C          4
#define CANIF_AR_RELEASE_MINOR_VERSION_C          7
#define CANIF_AR_RELEASE_REVISION_VERSION_C       0
#define CANIF_SW_MAJOR_VERSION_C                  2
#define CANIF_SW_MINOR_VERSION_C                  0
#define CANIF_SW_PATCH_VERSION_C                  0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

extern const CanIf_PCConfigType CanIf_PCConfig; 
#if (STD_ON == CANIF_PRECOMPILE_SUPPORT)
extern const CanIf_ConfigType CanIf_Config;
#endif

#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define CANIF_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"

static const CanIf_ConfigType * CanIf_ConfigPtr;

#define CANIF_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanIf_MemMap.h"
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#define CANIF_START_SEC_CODE
#include "CanIf_MemMap.h"

void CanIf_Init(const CanIf_ConfigType * ConfigPtr)
{
    #if (STD_ON == CANIF_PRECOMPILE_SUPPORT)
    CanIf_ConfigPtr = &CanIf_Config;
    (void)ConfigPtr;
    #else
    CanIf_ConfigPtr = ConfigPtr;
    #endif
}


Std_ReturnType CanIf_Transmit
(
    PduIdType CanTxPduId,
    const PduInfoType * PduInfoPtr
)
{
    Std_ReturnType RetVal = E_NOT_OK;
    Can_HwHandleType CanHth = 0U;
    Can_PduType PduInfo;
    const CanIf_TxPduType * TxPduInfo = NULL_PTR;
    uint8 CanIfControllerId = 0U;
    const CanIf_CtrlPCConfigType * CanIfController = NULL_PTR;

    if (NULL_PTR != CanIf_ConfigPtr)
    {
        if (CanTxPduId < (CanIf_ConfigPtr->NumTxPdu))
        {
            TxPduInfo = &CanIf_ConfigPtr->CanIf_TxPduConfigPtr[CanTxPduId];
            CanIfControllerId = TxPduInfo->CanIfCtrlId;
            CanIfController = &CanIf_PCConfig.CanIfCtrlConfigPtr[CanIfControllerId];

            CanHth = TxPduInfo->CanHth;

            PduInfo.id = TxPduInfo->CanId;
            /* Convert Id by adding two most significant bits specify the frame type */
            switch (TxPduInfo->CanFrameType)
            {
                case CANIF_EXTENDED_CAN:
                {
                    PduInfo.id |= 0x80000000U;
                    break;
                }
                case CANIF_EXTENDED_FD_CAN:
                {
                    PduInfo.id |= 0xC0000000U;
                    break;
                }
                case CANIF_STANDARD_FD_CAN:
                {
                    PduInfo.id |= 0x40000000U;
                    break;
                }
                default:
                {
                    break;
                }
            }
            
            PduInfo.length = (uint8)(PduInfoPtr->SduLength);
            PduInfo.sdu = PduInfoPtr->SduDataPtr;
            PduInfo.swPduHandle = CanTxPduId;

            RetVal = CanIfController->CanDrvConfigPtr->CanApi->CanWrite(CanHth, &PduInfo); 
        }
    }
    return RetVal;
}

void CanIf_TxConfirmation
(
    PduIdType CanTxPduId
)
{
    PduIdType UserPduId;
    const CanIf_TxPduType * TxPduInfo = NULL_PTR;

    if (NULL_PTR != CanIf_ConfigPtr)
    {
        if (CanTxPduId < (CanIf_ConfigPtr->NumTxPdu))
        {
            TxPduInfo = &CanIf_ConfigPtr->CanIf_TxPduConfigPtr[CanTxPduId];

            if (NULL_PTR != TxPduInfo->UserTxConfirmation)
            {
                UserPduId = TxPduInfo->PduId;
                TxPduInfo->UserTxConfirmation(UserPduId, E_OK);
            }
        }
    }
}


void CanIf_RxIndication
(
    const Can_HwType * Mailbox,
    const PduInfoType * PduInfoPtr
)
{
    PduIdType UserPduId = 0U;
    PduInfoType PduInfo;
    const CanIf_RxPduType * RxPduInfo = NULL_PTR;
    uint8 CanDrvId = 0U;

    if (NULL_PTR != CanIf_ConfigPtr)
    {
        if ((Mailbox->ControllerId) < (CanIf_PCConfig.NumOfCtrl))
        {
            if ((Mailbox->Hoh) < (CanIf_PCConfig.CanIfCtrlConfigPtr[Mailbox->ControllerId].CanDrvConfigPtr->NumCanHoh))
            {
                CanDrvId = CanIf_PCConfig.CanIfCtrlConfigPtr[Mailbox->ControllerId].CanDrvConfigPtr->CanDrvId;
                RxPduInfo = CanIf_ConfigPtr->CanDrvConfigPtr[CanDrvId]->HohToRxPduMappingPtr[Mailbox->Hoh];
                
                /* Will discard the Can HOH if it was not referred by any CanIf RxPDU */
                if (NULL_PTR != RxPduInfo)
                {
                    if (NULL_PTR != RxPduInfo->UserRxIndication)
                    {
                        UserPduId = RxPduInfo->PduId;
                        if ((TRUE == RxPduInfo->PduLengthCheck) && (PduInfoPtr->SduLength > (RxPduInfo->PduLength)))
                        {
                            PduInfo.SduLength = RxPduInfo->PduLength; /* Truncates exceeded data as configured on GUI */
                        }
                        else
                        {
                            PduInfo.SduLength = PduInfoPtr->SduLength;
                        }
                        PduInfo.SduDataPtr = PduInfoPtr->SduDataPtr;
                        RxPduInfo->UserRxIndication(UserPduId, &PduInfo);
                    }
                }
            }
        }
    }
}

#define CANIF_STOP_SEC_CODE
#include "CanIf_MemMap.h"

#ifdef __cplusplus
}
#endif /* CANIF_C */

/** @} */
