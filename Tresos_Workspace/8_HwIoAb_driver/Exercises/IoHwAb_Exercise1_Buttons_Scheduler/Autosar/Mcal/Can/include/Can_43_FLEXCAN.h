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

#ifndef CAN_43_FLEXCAN_H
#define CAN_43_FLEXCAN_H

/**
*   @file    Can_43_FLEXCAN.h
*   @version 2.0.0
*
*   @brief   AUTOSAR Can_43_FLEXCAN - module interface.
*   @details API header for CAN driver.
*
*   @addtogroup CAN_43_FLEXCAN_DRIVER
*   @{
*/

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
* @section Can_43_FLEXCAN_h_REF_1
* Violates MISRA 2012 Required Directive 4.10, Precautions shall be taken in order to prevent the contents
* of a header file being included more than once.
* This violation is not fixed since the inclusion of <MA>_MemMap.h is as per AUTOSAR requirement [SWS_MemMap_00003].
*
* @section Can_43_FLEXCAN_h_REF_2
* Violates MISRA 2012 Advisory Rule 2.5, A project should not contain unused macro declarations.
* Declaration is reserved for future feature.
*
* @section Can_43_FLEXCAN_h_REF_3
* Violates MISRA 2012 Advisory Rule 4.9, A function should be used in preference to a function-like macro where they are interchangeable.
* Function like macro are used to reduce code complexity
*
* @section Can_43_FLEXCAN_h_REF_4
* Violates MISRA 2012 Advisory Rule 2.3, A project should not contain unused type declarations.
* The declarations are used depend on user configuration.
*
* @section Can_43_FLEXCAN_h_REF_5
* Violates MISRA 2012 Advisory Rule 8.9, An object should be defined at block scope if identifier only appears in a single function.
* These objects are used when Precompile is supported.
*
* @section Can_43_FLEXCAN_h_REF_6
* Violates MISRA 2012 Advisory Rule 20.1, #include directives should only be preceded by preprocessor
* directives or comments.
*/

/*
(CAN043) The file Can.h contains the declaration of the Can module API.
(CAN037) The file Can.h only contains 'extern' declarations of constants, global data, type definitions and services
            that are specified in the Can module SWS.
*/

/**
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
*
*/
#include "ComStackTypes.h"
#include "Soc_Ips.h"
#include "Can_43_FLEXCAN_Ipw_Types.h"
#if (CAN_43_FLEXCAN_USE_FLEXCAN_IP  == STD_ON)
#include "Can_Flexcan_Types.h"
#endif
#if (CAN_43_FLEXCAN_USE_CANEXCEL_IP  == STD_ON)
#include "Can_CanEXCEL_Types.h"
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
    Internal micro-dependent versioning. Check of AUTOSAR & Vendor specification version.
*/
/**
* @{
*
*/
#define CAN_43_FLEXCAN_VENDOR_ID                   43
#define CAN_43_FLEXCAN_MODULE_ID                   80
#define CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION    4
#define CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION    7
#define CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION 0
#define CAN_43_FLEXCAN_SW_MAJOR_VERSION            2
#define CAN_43_FLEXCAN_SW_MINOR_VERSION            0
#define CAN_43_FLEXCAN_SW_PATCH_VERSION            0
/**@}*/
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Can_43_FLEXCAN_Ipw_Types header file are of the same vendor */
#if (CAN_43_FLEXCAN_VENDOR_ID != CAN_43_FLEXCAN_IPW_TYPES_VENDOR_ID_H)
    #error "Can_43_FLEXCAN.h and Can_43_FLEXCAN_Ipw_Types.h have different vendor ids"
#endif
/* Check if current file and Can_43_FLEXCAN_Ipw_Types header file are of the same Autosar version */
#if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION != CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION != CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION != CAN_43_FLEXCAN_IPW_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_43_FLEXCAN.h and Can_43_FLEXCAN_Ipw_Types.h are different"
#endif

/* Check if current file and Can_43_FLEXCAN_Ipw_Types header file are of the same software version */
#if ((CAN_43_FLEXCAN_SW_MAJOR_VERSION != CAN_43_FLEXCAN_IPW_TYPES_SW_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_SW_MINOR_VERSION != CAN_43_FLEXCAN_IPW_TYPES_SW_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_SW_PATCH_VERSION != CAN_43_FLEXCAN_IPW_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_43_FLEXCAN.h and Can_43_FLEXCAN_Ipw_Types.h are different"
#endif

#if (CAN_43_FLEXCAN_USE_FLEXCAN_IP  == STD_ON)
/* Check if current file and Can_Flexcan_Types header file are of the same vendor */
#if (CAN_43_FLEXCAN_VENDOR_ID != CAN_FLEXCAN_TYPES_VENDOR_ID_H)
    #error "Can_43_FLEXCAN.h and Can_Flexcan_Types.h have different vendor ids"
#endif
/* Check if current file and Can_Flexcan_Types header file are of the same Autosar version */
#if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION != CAN_FLEXCAN_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION != CAN_FLEXCAN_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION != CAN_FLEXCAN_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_43_FLEXCAN.h and Can_Flexcan_Types.h are different"
#endif
/* Check if current file and Can_43_FLEXCAN_Ipw_Types header file are of the same software version */
#if ((CAN_43_FLEXCAN_SW_MAJOR_VERSION != CAN_FLEXCAN_TYPES_SW_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_SW_MINOR_VERSION != CAN_FLEXCAN_TYPES_SW_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_SW_PATCH_VERSION != CAN_FLEXCAN_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_43_FLEXCAN.h and Can_Flexcan_Types.h are different"
#endif
#endif /* (CAN_43_FLEXCAN_USE_FLEXCAN_IP  == STD_ON) */
#if (CAN_43_FLEXCAN_USE_CANEXCEL_IP  == STD_ON)
/* Check if current file and Can_Canexcel_Types header file are of the same vendor */
#if (CAN_43_FLEXCAN_VENDOR_ID != CAN_CANEXCEL_TYPES_VENDOR_ID_H)
    #error "Can_43_FLEXCAN.h and Can_Canexcel_Types.h have different vendor ids"
#endif
/* Check if current file and Can_Canexcel_Types header file are of the same Autosar version */
#if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION !=    CAN_CANEXCEL_TYPES_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION !=    CAN_CANEXCEL_TYPES_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_AR_RELEASE_REVISION_VERSION != CAN_CANEXCEL_TYPES_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Can_43_FLEXCAN.h and Can_Canexcel_Types.h are different"
#endif
/* Check if current file and Can_Canexcel_Types header file are of the same software version */
#if ((CAN_43_FLEXCAN_SW_MAJOR_VERSION != CAN_CANEXCEL_TYPES_SW_MAJOR_VERSION_H) || \
     (CAN_43_FLEXCAN_SW_MINOR_VERSION != CAN_CANEXCEL_TYPES_SW_MINOR_VERSION_H) || \
     (CAN_43_FLEXCAN_SW_PATCH_VERSION != CAN_CANEXCEL_TYPES_SW_PATCH_VERSION_H) \
    )
    #error "Software Version Numbers of Can_43_FLEXCAN.h and Can_Canexcel_Types.h are different"
#endif
#endif /* (CAN_43_FLEXCAN_USE_CANEXCEL_IP  == STD_ON) */
/* Check if current file and CAN configuration header file are of the same software version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Software Version Numbers of Can_43_FLEXCAN.h and Soc_Ips.h are different"
    #endif

    /* Check if current file and ComStackTypes header file are of the same Autosar version */
    #if ((CAN_43_FLEXCAN_AR_RELEASE_MAJOR_VERSION != COMTYPE_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_43_FLEXCAN_AR_RELEASE_MINOR_VERSION != COMTYPE_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Can_43_FLEXCAN.h and ComStackTypes.h are different"
    #endif

#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#if (CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON)
    /**
    * @brief          Can_43_FLEXCAN_StatusType
    * @details        CAN Driver status used for checking and preventing double driver intialization.
    *                 CAN_UNINIT = The CAN controller is not initialized. The CAN Controller is not participating on the CAN bus.
    *                              All registers belonging to the CAN module are in reset state, CAN interrupts are disabled.
    *                 CAN_READY = Controller has initialized: static variables, including flags;
    *                             Common setting for the complete CAN HW unit; CAN controller specific settings for each CAN controller.
    *
    */
    typedef enum
    {
        CAN_43_FLEXCAN_UNINIT = 0U, /**< @brief Driver not initialized */
        CAN_43_FLEXCAN_READY       /**< @brief Driver ready */
    }Can_43_FLEXCAN_DriverStatusType;
#endif /* CAN_43_FLEXCAN_DEV_ERROR_DETECT == STD_ON */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** @brief Can Configuration */
typedef struct
{
    /** @brief Configuration Core ID */
    const uint32 Can_u32CoreID;
    /** @brief The first Hth after Hrh consecutive */
    const Can_HwHandleType Can_uHthFirstIndex;
    /** @brief Mapping Controller ID to Controller hardware offset */
    const uint8 * Can_pCtrlOffsetToCtrlIDMap;
    /** @brief Mapping Controller ID to Hardware Object ID */
    const uint8 * Can_pHwObjIDToCtrlIDMap;
    /** @brief Pointer to Can Hardware Object Config */
    const Can_43_FLEXCAN_HwObjectConfigType * Can_pHwObjectConfig;
#if (CAN_43_FLEXCAN_PUBLIC_ICOM_SUPPORT == STD_ON)
    /** @brief The size of Can Pn Configs */
    const uint8 u8NumCanIcomConfigs;
    /** brief Pointer point to Can Pn Configs */
    const Can_43_FLEXCAN_IcomConfigsType * pCanIcomConfigs;
#endif /* (CAN_43_FLEXCAN_PUBLIC_ICOM_SUPPORT == STD_ON) */
#if (CAN_43_FLEXCAN_USE_CANEXCEL_IP  == STD_ON)
    /** @brief The first CanXL Hth after CanXL Hrh consecutive */
    const Can_HwHandleType CanXL_uHthFirstIndex;
    /** @brief Mapping Controller ID to CanXL Hardware Object ID */
    const uint8 * CanXL_pHwObjIDToCtrlIDMap;
    /** @brief Pointer to CanXL Hardware Object Config */
    const Can_43_FLEXCAN_XL_HwObjectConfigType * CanXL_pHwObjectConfig;
#endif
    /** @brief Pointer to Can Controller Config */
    const Can_43_FLEXCAN_ControllerConfigType * const * Can_ppController;
}Can_43_FLEXCAN_ConfigType;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define CAN_43_FLEXCAN_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_43_FLEXCAN_h_REF_1 MISRA 2012 Required Directive 4.10 */
#include "Can_43_FLEXCAN_MemMap.h"

CAN_43_FLEXCAN_CONFIG_EXT

#define CAN_43_FLEXCAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_43_FLEXCAN_h_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_43_FLEXCAN_h_REF_6 MISRA 2012 Advisory Rule 20.1 */
#include "Can_43_FLEXCAN_MemMap.h"
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define CAN_43_FLEXCAN_START_SEC_CODE
/* @violates @ref Can_43_FLEXCAN_h_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_43_FLEXCAN_h_REF_6 MISRA 2012 Advisory Rule 20.1 */
#include "Can_43_FLEXCAN_MemMap.h"

#if (CAN_43_FLEXCAN_VERSION_INFO_API == STD_ON)
    /**
    * @brief          Returns the version information of this module. SID is 0x07
    * @details        This routine is called by:
    *                - CanIf or an upper layer according to Autosar requirements.
    *
    * @param[in]      versioninfo A pointer to location to store version info
    *                             Must be omitted if the function does not have parameters.
    *
    * @return         void
    *
    *
    * @pre            The CAN_VERSION_INFO_API define must be configured on.
    * @post           The version information is return if the parameter versionInfo is not a null pointer.
    *
    *
    */
    void Can_43_FLEXCAN_GetVersionInfo(Std_VersionInfoType * versioninfo);
#endif /* CAN_43_FLEXCAN_VERSION_INFO_API == STD_ON */

/**
* @brief          Initialize the CAN driver. SID is 0x00.
* @details        Initialize all the controllers.
*                 The CAN module shall be initialized by Can_Init(<&Can_Configuration>) service call during the start-up.
*                 This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Config Pointer to driver configuration.
*
* @return         void
*
*
* @pre            Can_Init shall be called at most once during runtime.
* @post           Can_Init shall initialize all the controllers and set the driver in READY state.
*
*/
void Can_43_FLEXCAN_Init(const Can_43_FLEXCAN_ConfigType * Config);

/**
* @brief          De-initialize the CAN driver. SID is 0x10.
* @details        De-initialize all the controllers.
*                 The CAN module shall be de-initialized by Can_DeInit() service call during the start-up.
*                 This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      None
*
* @return         void
*
*
* @pre            Before controller de-initalization, the driver must be initialized and the controllers must be not in Start state.
* @post           Can_DeInit shall de-initialize all the controllers and set the driver in UNINIT state.
*
*/
void Can_43_FLEXCAN_DeInit(void);

#if (CAN_43_FLEXCAN_SET_BAUDRATE_API == STD_ON)
    /**
    * @brief         This function set baudrate
    * @details       This routine is called by an upper layer.
    *
    * @param[in]     Controller controller ID
    * @param[in]     BaudRateConfigID baudrateID selection
    *
    * @return        Std_ReturnType  Result of the transition.
    * @retval        E_OK  Switch baudrate operation was ok.
    * @retval        E_NOT_OK  Switch baudrate operation was not ok.
    *
    * @pre           Driver must be initialized.
    */
    Std_ReturnType Can_43_FLEXCAN_SetBaudrate
    (
        uint8 Controller,
        uint16 BaudRateConfigID
    );
#endif /* CAN_43_FLEXCAN_SET_BAUDRATE_API == STD_ON */

/**
* @brief          Put the controller into a required state. SID is 0x03.
* @details        Switch the controller from one state to another.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller - Can controller for which the status shall be changed - based on configuration order list (CanControllerId).
* @param[in]      Transition - Possible transitions (CAN_CS_STOPPED , CAN_CS_STARTED , CAN_CS_SLEEP)
* @return         Std_ReturnType  Result of the transition.
* @retval         E_OK   request accepted.
* @retval         E_NOT_OK  request not accepted, a development error occurred.
*
*
* @pre            Before changing the controller state the driver must be initialized.
* @post           After the transition to the new state the interrupts required for that state must be enebaled.
*
*
*/
Std_ReturnType Can_43_FLEXCAN_SetControllerMode(uint8 Controller, Can_ControllerStateType Transition);

#if (CAN_43_FLEXCAN_LISTEN_ONLY_MODE == STD_ON)
/**
* @brief          Enable or disable Listen Only Mode. SID is 0x32.
* @details        Enable or disable Listen Only Mode.
* @param[in]      Controller - Controller in which ListenOnlyMode will be enabled/disabled.
* @param[in]      State - Enable or Disable the feature (CAN_43_FLEXCAN_NORMAL_MODE , CAN_43_FLEXCAN_LISTEN_MODE)
* @return         Std_ReturnType  Result of the transition.
* @retval         E_OK   request accepted.
* @retval         E_NOT_OK  request not accepted, a development error occurred.
*
* @pre
* @post
*
*
*/
Std_ReturnType Can_43_FLEXCAN_ListenOnlyMode(uint8 Controller, Can_43_FLEXCAN_ListenOnlyType State);
#endif /* (CAN_43_FLEXCAN_LISTEN_ONLY_MODE == STD_ON) */

/**
* @brief          Disable INTs. SID is 0x04.
* @details        Switch OFF the controller's interrupts.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller Can controller for which interrupts shall be disabled - based on configuration order list (CanControllerId).
*
* @return         void
*
*
* @pre            Driver must be initalzied before changing the interrupts state (en or dis).
* @post           Controller must not respond to any interrupt assertion.
*
*
*/
void Can_43_FLEXCAN_DisableControllerInterrupts(uint8 Controller);

/**
* @brief          Enable INTs. SID is 0x05.
* @details        Switch ON the controller's interrupts.
*                 This routine is called by:
*                 - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller Can controller for which interrupts shall be disabled - based on configuration order list (CanControllerId).
*
* @return         void
*
*
* @pre            Driver must be initalzied before changing the interrupts state (en or dis).
* @post           Controller must respond to interrupt assertion.
*
*/
void Can_43_FLEXCAN_EnableControllerInterrupts(uint8 Controller);

#if (CAN_43_FLEXCAN_CHECK_WAKEUP_API == STD_ON)
    Std_ReturnType Can_43_FLEXCAN_CheckWakeup(uint8 Controller);
#endif

/**
* @brief          Obtains the error state of the CAN controller.. SID is 0x11
* @details        This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      ControllerId: Abstracted CanIf ControllerId which is assigned to a CAN controller, which is requested for ErrorState.
*
* @param[out]     ErrorStatePtr: Pointer to a memory location, where the error state of the CAN controller will be stored.
*
* @return         Std_ReturnType  Result of the transition.
* @retval         E_OK : Error state request has been accepted.
* @retval         E_NOT_OK : Error state request has not been accepted.
*
* @pre
* @post
*
*
*/
Std_ReturnType Can_43_FLEXCAN_GetControllerErrorState
(
    uint8 ControllerId,
    Can_ErrorStateType * ErrorStatePtr
);

/**
* @brief          Reports about the current status of the requested CAN controller. SID is 0x12
* @details        This routine is called by:
*                - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Controller: CAN controller for which the status shall be requested.
*
* @param[out]     ControllerModePtr: Pointer to a memory location, where the current mode of the CAN controller will be stored.
*
* @return         Std_ReturnType  Result of the transition.
* @retval         E_OK : Controller mode request has been accepted.
* @retval         E_NOT_OK : Controller mode request has not been accepted.
*
* @pre
* @post
*
*
*/
Std_ReturnType Can_43_FLEXCAN_GetControllerMode
(
    uint8 Controller,
    Can_ControllerStateType * ControllerModePtr
);

/**
* @brief            Return the Rx error counter for a CAN controller
* @details          Return the Rx error counter for a CAN controller. This value might not be
*                   available for all CAN controller, in which case E_NOT_OK would be returned.
*                   Please note that the value of the counter might not be correct at the moment
*                   the API returns it, because the Rx counter is handled asynchronously in hardware.
*                   Applications should not trust this value for any assumption about the current bus state.
*
* @param[in]        ControllerId: CAN controller, whose current Rx error counter shall be acquired.
* @param[out]       RxErrorCounterPtr: Pointer to a memory location, where the current Rx error
*                       counter of the CAN controller will be stored.
*
* @return           Std_ReturnType  Result of the transition.
* @retval           E_OK:  Rx error counter available.
* @retval           E_NOT_OK: Wrong ControllerId, or Rx error counter not available.
*
* @pre
* @post
*
*/
Std_ReturnType Can_43_FLEXCAN_GetControllerRxErrorCounter
(
    uint8 ControllerId,
    uint8 * RxErrorCounterPtr
);

/**
* @brief            Return the Tx error counter for a CAN controller
* @details          Return the Tx error counter for a CAN controller. This value might not be
*                   available for all CAN controller, in which case E_NOT_OK would be returned.
*                   Please note that the value of the counter might not be correct at the moment
*                   the API returns it, because the Tx counter is handled asynchronously in hardware.
*                   Applications should not trust this value for any assumption about the current bus state.
*
* @param[in]        ControllerId: CAN controller, whose current Tx error counter shall be acquired.
* @param[out]       TxErrorCounterPtr: Pointer to a memory location, where the current Tx error
*                       counter of the CAN controller will be stored.
*
* @return           Std_ReturnType  Result of the transition.
* @retval           E_OK:  Tx error counter available.
* @retval           E_NOT_OK: Wrong ControllerId, or Tx error counter not available.
*
* @pre
* @post
*
*/
Std_ReturnType Can_43_FLEXCAN_GetControllerTxErrorCounter
(
    uint8 ControllerId,
    uint8 * TxErrorCounterPtr
);

/**
* @brief          Transmit information on CAN bus. SID is 0x06.
* @details        Can_Write checks if hardware transmit object that is identified by the HTH is free.
*                    Can_Write checks if another Can_Write is ongoing for the same HTH.
*                     a) hardware transmit object is free:
*                         The mutex for that HTH is set to 'signaled' the ID, DLC and SDU are put in a format appropriate for
*                           the hardware (if necessary) and copied in the appropriate hardware registers or buffers.
*                        All necessary control operations to initiate the transmit are done.
*                         The mutex for that HTH is released. The function returns with E_OK.
*                    b) hardware transmit object is busy with another transmit request.
*                         The function returns with CAN_BUSY.
*                     c) A preemptive call of Can_Write has been issued, that could not be handled reentrant (i.e. a call with the same HTH).
*                        The function returns with CAN_BUSY the function is non blocking
*                     d) The hardware transmit object is busy with another transmit request for an L-PDU that has lower priority than that for the current request
*                        The transmission of the previous L-PDU is cancelled (asynchronously).
*                        The function returns with CAN_BUSY.
*                   This routine is called by:
*                   - CanIf or an upper layer according to Autosar requirements.
*
* @param[in]      Hth Information which HW-transmit handle shall be used for transmit.
*                 Implicitly this is also the information about the controller to use because the Hth numbers are unique inside one hardware unit.
* @param[in]      PduInfo Pointer to SDU user memory, DLC and Identifier.
* @return         Std_ReturnType   Result of the write operation.
* @retval         E_OK   Write command has been accepted.
* @retval         E_NOT_OK  Development error occured.
* @retval         CAN_BUSY   No of TX hardware buffer available or preemtive call of Can_Write() that can't be implemented reentrant.
*
*
* @pre            Driver must be initialized and MB must be configured for Tx.
* @post           The data can be transmitted or rejected because of another data with a higher priority.
*
*
*/
Std_ReturnType Can_43_FLEXCAN_Write
(
    Can_HwHandleType Hth,
    const Can_PduType * PduInfo
);

#if (CAN_43_FLEXCAN_ABORT_MB_API == STD_ON)
    /**
    * @brief          Process a message buffer abort
    * @details        This function write a abort code (b'1001) to MBCS[CODE] field of the MB.
    *                This routine is called by:
    *                - CanIf or an upper layer according to Autosar requirements.
    *
    * @param[in]      Hth - HW-transmit handler
    *
    *
    * @pre            Driver must be initialized and the current MB transmission should be ready for transmit.
    *
    *
    * @note           Not AUTOSAR required. This is user implementation.
    */
    void Can_43_FLEXCAN_AbortMb(Can_HwHandleType Hth);
#endif /* CAN_43_FLEXCAN_ABORT_MB_API == STD_ON */

#if (CAN_43_FLEXCAN_DUAL_CLOCK_MODE == STD_ON)
    /**
    * @brief          Function switch between two prescaler that was configured when Clock Source value to driver changed to another one.
    * @details        Function sets all controllers' prescaller based on input parameter.
    *
    * @param[in]      eClkMode - prescaler setting (NORMAL or ALTERNATE)
    *
    * @pre            Can_Init must be called before, all controllers must be in STOPPED.
    *
    */
    void Can_43_FLEXCAN_SetClockMode(Can_43_FLEXCAN_ClockModeType eClkMode);
#endif

#if (CAN_43_FLEXCAN_PUBLIC_ICOM_SUPPORT == STD_ON)
/**
* @brief          Set controller into Pretended Networking mode with the ConfigurationID valid.
* @details        This function is API which support the Pretended Networking featrue. After this function is called,
*                 it will configure for controller with information in the configurationIDs (corresponding with ID valid )

*
* @param[in]      Controller    CAN controller for which the init shall be done. Based on configuration order list (CanControllerId).
* @param[in]      ConfigurationId the ID of CanIcomConfig
*
* @return        Std_ReturnType
* @retval        E_OK       PNET is Enabled/disabled successfully.
* @retval        E_NOT_OK   PNET is not Enabled/disabled successfully.
*
* @pre            Driver must be initialized
*
* @note           In order to activate PNET (ConfigurationId != 0) the controller must be in START mode.
* @implements    Can_SetIcomConfiguration_Activity
*/
Std_ReturnType Can_43_FLEXCAN_SetIcomConfiguration(uint8 Controller, IcomConfigIdType ConfigurationId);
#endif /* (CAN_43_FLEXCAN_PUBLIC_ICOM_SUPPORT == STD_ON) */

#if (CAN_43_FLEXCAN_TIMESTAMP_ENABLE == STD_ON)
/**
* @brief          Returns a time value out of the HW registers according to the capability of the Hardware.
* @details        Returns a time value out of the HW registers according to the capability of the Hardware.

*
* @param[in]      ControllerId    Index of the addresses CAN controller.
* @param[out]     timeStampPtr    Current time stamp.
*
* @return        Std_ReturnType
* @retval        E_OK       Successful.
* @retval        E_NOT_OK   failed.
*
* @pre            Driver must be initialized
*
* @implements    Can_GetCurrentTime_Activity
*/
Std_ReturnType Can_43_FLEXCAN_GetCurrentTime(uint8 ControllerId, Can_TimeStampType* timeStampPtr);

#if (CAN_43_FLEXCAN_TS_EXTERNAL_TIMER_USED == STD_ON)
/**
* @brief          Set a new global time(second part only).
* @details        This function will set a new global time(second part only).
*
*
* @param[in]      ControllerId    Index of the addresses CAN controller.
* @param[out]     timeStampPtr    Current time stamp.
*
* @return        Std_ReturnType
* @retval        E_OK       Successful.
* @retval        E_NOT_OK   failed.
*
* @pre            Driver must be initialized
*
* @note           This function is available only if High resolution timestamp source is a STM channel.
*                 This function should be called while STM timer counter was stopped.
*                 When the STM counter is started again, the global nanosecond part will be zero.
*                 Due to Hardware supports only one HR timestamp source for all controllers so this function will effect all controllers enable HR timestamp.
* @implements    Can_SetCurrentTime_Activity
*/
Std_ReturnType Can_43_FLEXCAN_SetCurrentTime(uint8 ControllerId, const Can_TimeStampType* timeStampPtr);
#endif /* (CAN_43_FLEXCAN_TS_EXTERNAL_TIMER_USED == STD_ON) */
/**
* @brief        Activates egress time stamping on a dedicated HTH.
* @details      Some HW does store once the egress time stamp marker and some HW needs it 
*               always before transmission. There will be no "disable" functionality, due to the fact, 
*               that the message type is always "time stamped" by network design
*
*
* @param[in]      Hth    Index of the addresses CAN controller.
*
*
* @pre            Driver must be initialized
*
* @note           This function will not affect due to the fact that timestamp will be enabled on all transmit Objects when it's controller started.
* @implements    Can_EnableEgressTimeStamp_Activity
*/
void Can_43_FLEXCAN_EnableEgressTimeStamp(Can_HwHandleType Hth);

/**
* @brief          Reads back the egress time stamp on a dedicated message object.
* @details        Reads back the egress time stamp on a dedicated message object. It needs to be 
*                 called within the TxConfirmation() function.
*
*
* @param[in]      TxPduId           L-PDU handle of CAN L-PDU for which the time stamp shall be returned.
* @param[in]      Hth               HW-transmit handle for which the egress timestamp shall be retrieved.
* @param[out]     timeStampPtr      Current time stamp.
*
* @return        Std_ReturnType
* @retval        E_OK       Successful.
* @retval        E_NOT_OK   Failed to read time stamp.
*
* @pre            Driver must be initialized
*
* @note           This function need to be called before 1 second since the timestamp captured by hardware(HTH transmitted successfully).
* @implements    Can_GetEgressTimeStamp_Activity
*/
Std_ReturnType Can_43_FLEXCAN_GetEgressTimeStamp(PduIdType TxPduId, Can_HwHandleType Hth, Can_TimeStampType* timeStampPtr);

/**
* @brief          Reads back the ingress time stamp on a dedicated message object.
* @details        Reads back the ingress time stamp on a dedicated message object. It needs to be 
*                 called within the RxIndication() function.
*
*
* @param[in]      Hrh               HW-receive handle for which the ingress timestamp shall be retrieved.
* @param[out]     timeStampPtr      Current time stamp.
*
* @return        Std_ReturnType
* @retval        E_OK       Successful.
* @retval        E_NOT_OK   Failed to read time stamp.
*
* @pre            Driver must be initialized
*
* @note           This function need to be called before 1 second since the timestamp captured by hardware(HRH received successfully).
* @implements    Can_GetIngressTimeStamp_Activity
*/
Std_ReturnType Can_43_FLEXCAN_GetIngressTimeStamp(Can_HwHandleType Hrh, Can_TimeStampType* timeStampPtr);
#endif /* (CAN_43_FLEXCAN_TIMESTAMP_ENABLE == STD_ON) */

#define CAN_43_FLEXCAN_STOP_SEC_CODE
/* @violates @ref Can_43_FLEXCAN_h_REF_1 MISRA 2012 Required Directive 4.10 */
/* @violates @ref Can_43_FLEXCAN_h_REF_6 MISRA 2012 Advisory Rule 20.1 */
#include "Can_43_FLEXCAN_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* CAN_43_FLEXCAN_H */
