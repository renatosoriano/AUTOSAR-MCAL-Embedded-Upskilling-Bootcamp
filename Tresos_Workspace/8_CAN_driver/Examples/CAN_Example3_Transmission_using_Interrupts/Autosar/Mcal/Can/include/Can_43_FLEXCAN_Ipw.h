/**
*   @file    Can_Ipw.h
*   @version 2.0.0
*
*   @brief   AUTOSAR Can_43_FLEXCAN - module interface
*   @details Main header file - can include different IPV models.
*
*   @addtogroup CAN_43_FLEXCAN_DRIVER
*   @{
*/
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
/*==================================================================================================
==================================================================================================*/

#ifndef CAN_43_FLEXCAN_IPW_H
#define CAN_43_FLEXCAN_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/*
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
* @section Can_43_FLEXCAN_Ipw_h_REF_1
* Violates MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents
* of a header file being included more than once. This comes from the order of includes in the .c file
* and from include dependencies. As a safe approach, any file must include all its dependencies.
* Header files are already protected against double inclusions. The inclusion of Can_Memmap.h is as
* per AUTOSAR requirement (SWS_MemMap_00003)
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "FlexCAN_Ip.h"
#include "Can_Flexcan_Types.h"
#include "Can_43_FLEXCAN_Ipw_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
*
*/
#define CAN_43_FLEXCAN_IPW_VENDOR_ID_H                    43
#define CAN_43_FLEXCAN_IPW_MODULE_ID                      80
#define CAN_43_FLEXCAN_IPW_AR_RELEASE_MAJOR_VERSION_H     4
#define CAN_43_FLEXCAN_IPW_AR_RELEASE_MINOR_VERSION_H     7
#define CAN_43_FLEXCAN_IPW_AR_RELEASE_REVISION_VERSION_H  0
#define CAN_43_FLEXCAN_IPW_SW_MAJOR_VERSION_H             2
#define CAN_43_FLEXCAN_IPW_SW_MINOR_VERSION_H             0
#define CAN_43_FLEXCAN_IPW_SW_PATCH_VERSION_H             0
/**@}*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and FlexCAN_Ip header file are of the same vendor */
#if (CAN_43_FLEXCAN_IPW_VENDOR_ID_H != FLEXCAN_IP_VENDOR_ID_H)
    #error "Can_43_FLEXCAN_Ipw.h and FlexCAN_Ip.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip header file are of the same Autosar version */
#if ((CAN_43_FLEXCAN_IPW_AR_RELEASE_MAJOR_VERSION_H    != FLEXCAN_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IPW_AR_RELEASE_MINOR_VERSION_H    != FLEXCAN_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IPW_AR_RELEASE_REVISION_VERSION_H != FLEXCAN_IP_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of Can_43_FLEXCAN_Ipw.h and FlexCAN_Ip.h are different"
#endif
/* Check if current file and FlexCAN_Ip header file are of the same Software version */
#if ((CAN_43_FLEXCAN_IPW_SW_MAJOR_VERSION_H != FLEXCAN_IP_SW_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IPW_SW_MINOR_VERSION_H != FLEXCAN_IP_SW_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IPW_SW_PATCH_VERSION_H != FLEXCAN_IP_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_43_FLEXCAN_Ipw.h and FlexCAN_Ip.h are different"
#endif


/* Check if current file and Can_43_FLEXCAN_Ipw_Cfg header file are of the same vendor */
#if (CAN_43_FLEXCAN_IPW_VENDOR_ID_H != CAN_43_FLEXCAN_IPW_CFG_VENDOR_ID)
    #error "Can_43_FLEXCAN_Ipw.h and Can_43_FLEXCAN_Ipw_Cfg.h have different vendor ids"
#endif
/* Check if current file and Can_43_FLEXCAN_Ipw_Cfg header file are of the same Autosar version */
#if ((CAN_43_FLEXCAN_IPW_AR_RELEASE_MAJOR_VERSION_H    != CAN_43_FLEXCAN_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_IPW_AR_RELEASE_MINOR_VERSION_H    != CAN_43_FLEXCAN_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_IPW_AR_RELEASE_REVISION_VERSION_H != CAN_43_FLEXCAN_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Can_43_FLEXCAN_Ipw.h and Can_43_FLEXCAN_Ipw_Cfg.h are different"
#endif
/* Check if current file and Can_43_FLEXCAN_Ipw_Cfg header file are of the same Software version */
#if ((CAN_43_FLEXCAN_IPW_SW_MAJOR_VERSION_H != CAN_43_FLEXCAN_IPW_CFG_SW_MAJOR_VERSION) || \
     (CAN_43_FLEXCAN_IPW_SW_MINOR_VERSION_H != CAN_43_FLEXCAN_IPW_CFG_SW_MINOR_VERSION) || \
     (CAN_43_FLEXCAN_IPW_SW_PATCH_VERSION_H != CAN_43_FLEXCAN_IPW_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Can_43_FLEXCAN_Ipw.h and Can_43_FLEXCAN_Ipw_Cfg.h are different"
#endif

/* Check if current file and Can_Flexcan_Types header file are of the same vendor */
#if (CAN_43_FLEXCAN_IPW_VENDOR_ID_H != CAN_FLEXCAN_TYPES_VENDOR_ID_H)
    #error "Can_43_FLEXCAN_Ipw.h and Can_Flexcan_Types.h have different vendor ids"
#endif
/* Check if current file and Can_Flexcan_Types header file are of the same Autosar version */
#if ((CAN_43_FLEXCAN_IPW_AR_RELEASE_MAJOR_VERSION_H    != CAN_FLEXCAN_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IPW_AR_RELEASE_MINOR_VERSION_H    != CAN_FLEXCAN_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IPW_AR_RELEASE_REVISION_VERSION_H != CAN_FLEXCAN_TYPES_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of Can_43_FLEXCAN_Ipw.h and Can_Flexcan_Types.h are different"
#endif
/* Check if current file and Can_Flexcan_Types header file are of the same Software version */
#if ((CAN_43_FLEXCAN_IPW_SW_MAJOR_VERSION_H != CAN_FLEXCAN_TYPES_SW_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IPW_SW_MINOR_VERSION_H != CAN_FLEXCAN_TYPES_SW_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_IPW_SW_PATCH_VERSION_H != CAN_FLEXCAN_TYPES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_43_FLEXCAN_Ipw.h and Can_Flexcan_Types.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* @violates @ref Can_Flexcan_h_REF_2 MISRA 2012 Advisory Rule 4.9 */
#define Call_Can_FlexCan_Init(instance, status, Can_pControllerConfig)         FlexCAN_Ip_Init(instance, status, Can_pControllerConfig)
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_43_FLEXCAN_START_SEC_CODE
/* @violates @ref Can_43_FLEXCAN_Ipw_h_REF_1 MISRA 2012 Required Directive 4.10. */
#include "Can_43_FLEXCAN_MemMap.h"
/* Initialize Controller */
Std_ReturnType Can_43_FLEXCAN_Ipw_Init(const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig);

/* De-Initialize Controller */
void Can_43_FLEXCAN_Ipw_DeInit(const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig);

#if (CAN_43_FLEXCAN_SET_BAUDRATE_API == STD_ON)
/* Set Baud Rate of Controller */
Std_ReturnType Can_43_FLEXCAN_Ipw_SetBaudrate
    (
        const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig,
        uint16 BaudRateConfigID
    );
#endif
/* Set Controller to participate the CAN network */
Std_ReturnType Can_43_FLEXCAN_Ipw_SetControllerToStartMode(const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig);

/* Set Controller to stop participating the CAN network */
Std_ReturnType Can_43_FLEXCAN_Ipw_SetControllerToStopMode(const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig);

/* Disable Can Controller Interrupt */
void Can_43_FLEXCAN_Ipw_DisableControllerInterrupts(const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig);

/* Enable Can Controller Interrupt */
void Can_43_FLEXCAN_Ipw_EnableControllerInterrupts(const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig);

/* Get Controller Error State */
Std_ReturnType Can_43_FLEXCAN_Ipw_GetControllerErrorState(const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig, uint8 * pValue);

/* Get Controller Rx Error Counter */
Std_ReturnType Can_43_FLEXCAN_Ipw_GetControllerRxErrorCounter(const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig, uint8 * pValue);

/* Get Controller Tx Error Counter */
Std_ReturnType Can_43_FLEXCAN_Ipw_GetControllerTxErrorCounter(const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig, uint8 * pValue);

#if (CAN_43_FLEXCAN_LISTEN_ONLY_MODE == STD_ON)
/* Enable or disable Listen Only Mode */
Std_ReturnType Can_43_FLEXCAN_Ipw_ListenOnlyMode(const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig, const Can_43_FLEXCAN_ListenOnlyType State);
#endif /* (CAN_43_FLEXCAN_LISTEN_ONLY_MODE == STD_ON) */

/* Write Pduinfo to Hw Buffer and request transmission */
Std_ReturnType Can_43_FLEXCAN_Ipw_Write
(
    const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig,
    const Can_43_FLEXCAN_HwObjectConfigType * Can_pHwObjectConfig,
    const Can_PduType * PduInfo
);

#if (CAN_43_FLEXCAN_ABORT_MB_API == STD_ON)
    /* Cancel of a pending CAN transmission */
    void Can_43_FLEXCAN_Ipw_AbortMb
    (
        const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig,
        const Can_43_FLEXCAN_HwObjectConfigType * Can_pHwObjectConfig
    );
#endif

#if (CAN_43_FLEXCAN_DUAL_CLOCK_MODE == STD_ON)
    /* Switch to another clock by changing controller's prescaler */
    void Can_43_FLEXCAN_Ipw_SetClockMode
    (
        const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig,
        uint16 Can_u16BaudrateID,
        Can_43_FLEXCAN_ClockModeType Can_eClkMode
    );
#endif
/* Polling Tx Confirmation */
void Can_43_FLEXCAN_Ipw_MainFunction_Write
(
    const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig,
    const Can_43_FLEXCAN_HwObjectConfigType * Can_pHwObjectConfig
);

/* Polling Rx Indication */
void Can_43_FLEXCAN_Ipw_MainFunction_Read
(
    const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig,
    const Can_43_FLEXCAN_HwObjectConfigType * Can_pHwObjectConfig
);

/* Polling Bus Off */
void Can_43_FLEXCAN_Ipw_MainFunction_BusOff(const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig);

/* Polling Controller Mode Transitions */
void Can_43_FLEXCAN_Ipw_MainFunction_Mode
(
    const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig,
    Can_ControllerStateType * Can_pControllerState
);

#if (CAN_43_FLEXCAN_MB_INTERRUPT_SUPPORT == STD_ON)
    /**
    *   @brief     Process Hw Object
    */
    void Can_43_FLEXCAN_Ipw_ProcessHwObject
    (
        const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig,
        const Can_43_FLEXCAN_ConfigType * Can_pConfig,
        uint8 u8MbIdx,
        Can_43_FLEXCAN_MbType mbType
    );
#endif

#if (CAN_43_FLEXCAN_PUBLIC_ICOM_SUPPORT == STD_ON)
Std_ReturnType Can_43_FLEXCAN_Ipw_DeactivateIcomConfiguration(const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig);

Std_ReturnType Can_43_FLEXCAN_Ipw_SetIcomConfiguration(const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig, const Can_43_FLEXCAN_IcomConfigsType * pIcomConfig);
void Can_43_FLEXCAN_Ipw_ProcessPN(const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig, const Can_43_FLEXCAN_IcomConfigsType * pIcomConfig);
#endif /* (CAN_43_FLEXCAN_PUBLIC_ICOM_SUPPORT == STD_ON) */

#if (CAN_43_FLEXCAN_TIMESTAMP_ENABLE == STD_ON)
void Can_43_FLEXCAN_Ipw_GetCurrentTime(Can_TimeStampType* timeStampPtr);

#if (CAN_43_FLEXCAN_TS_EXTERNAL_TIMER_USED == STD_ON)
void Can_43_FLEXCAN_Ipw_SetCurrentTime(const Can_TimeStampType* timeStampPtr);
#endif /* (CAN_TS_EXTERNAL_TIMER_USED == STD_ON) */

void Can_43_FLEXCAN_Ipw_EnableEgressTimeStamp
(
    const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig,
    const Can_43_FLEXCAN_HwObjectConfigType * Can_pHwObjectConfig
);

Std_ReturnType Can_43_FLEXCAN_Ipw_GetEgressTimeStamp
(
    const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig,
    const Can_43_FLEXCAN_HwObjectConfigType * Can_pHwObjectConfig,
    const PduIdType TxPduId,
    Can_TimeStampType* timeStampPtr
);

void Can_43_FLEXCAN_Ipw_GetIngressTimeStamp
(
    const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig,
    const Can_43_FLEXCAN_HwObjectConfigType * Can_pHwObjectConfig,
    Can_TimeStampType* timeStampPtr
);
#endif /* (CAN_43_FLEXCAN_TIMESTAMP_ENABLE == STD_ON) */

#if (CAN_43_FLEXCAN_ERROR_INTERRUPT_SUPPORT == STD_ON)
void Can_43_FLEXCAN_Ipw_ErrorHandling(const Can_43_FLEXCAN_ControllerConfigType * Can_pControllerConfig, uint32 u32ErrStatus);
#endif /* (CAN_43_FLEXCAN_ERROR_INTERRUPT_SUPPORT == STD_ON) */

#define CAN_43_FLEXCAN_STOP_SEC_CODE
/* @violates @ref Can_43_FLEXCAN_Ipw_h_REF_1 MISRA 2012 Required Directive 4.10. */
#include "Can_43_FLEXCAN_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*TEMPLATE_H*/

/** @} */
