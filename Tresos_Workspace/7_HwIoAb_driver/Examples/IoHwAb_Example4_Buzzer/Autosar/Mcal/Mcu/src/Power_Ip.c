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
/**
*   @file       Power_Ip.c
*   @version    2.0.0
*
*   @brief
*   @brief   POWER driver implementations.
*   @details POWER driver implementations.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
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
#include "Power_Ip.h"
#include "Power_Ip_Private.h"
#include "Power_Ip_PMC.h"
#include "Power_Ip_RCM.h"
#include "Power_Ip_SMC.h"
#include "Power_Ip_CortexM4.h"
#include "Power_Ip_SIM.h"

#ifdef POWER_IP_AECRESETCONFIG_API
#if (POWER_IP_AECRESETCONFIG_API == STD_ON)
#include "Power_Ip_AEC.h"
#endif
#endif

#if ((POWER_MODE_CHANGE_NOTIFICATION == STD_ON) || (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON))
#include "Clock_Ip.h"
#endif
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_VENDOR_ID_C                      43
#define POWER_IP_AR_RELEASE_MAJOR_VERSION_C       4
#define POWER_IP_AR_RELEASE_MINOR_VERSION_C       7
#define POWER_IP_AR_RELEASE_REVISION_VERSION_C    0
#define POWER_IP_SW_MAJOR_VERSION_C               2
#define POWER_IP_SW_MINOR_VERSION_C               0
#define POWER_IP_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip.c file and Power_Ip.h file are of the same vendor */
#if (POWER_IP_VENDOR_ID_C != POWER_IP_VENDOR_ID)
    #error "Power_Ip.c and Power_Ip.h have different vendor ids"
#endif

/* Check if Power_Ip.c file and Power_Ip.h file are of the same Autosar version */
#if ((POWER_IP_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AR_RELEASE_MINOR_VERSION_C != POWER_IP_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AR_RELEASE_REVISION_VERSION_C != POWER_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip.c and Power_Ip.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip.h file are of the same Software version */
#if ((POWER_IP_SW_MAJOR_VERSION_C != POWER_IP_SW_MAJOR_VERSION) || \
     (POWER_IP_SW_MINOR_VERSION_C != POWER_IP_SW_MINOR_VERSION) || \
     (POWER_IP_SW_PATCH_VERSION_C != POWER_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip.c and Power_Ip.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_Private.h file are of the same vendor */
#if (POWER_IP_VENDOR_ID_C != POWER_IP_PRIVATE_VENDOR_ID)
    #error "Power_Ip.c and Power_Ip_Private.h have different vendor ids"
#endif

/* Check if Power_Ip.c file and Power_Ip_Private.h file are of the same Autosar version */
#if ((POWER_IP_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AR_RELEASE_MINOR_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AR_RELEASE_REVISION_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip.c and Power_Ip_Private.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_Private.h file are of the same Software version */
#if ((POWER_IP_SW_MAJOR_VERSION_C != POWER_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (POWER_IP_SW_MINOR_VERSION_C != POWER_IP_PRIVATE_SW_MINOR_VERSION) || \
     (POWER_IP_SW_PATCH_VERSION_C != POWER_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip.c and Power_Ip_Private.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_PMC.h file are of the same vendor */
#if (POWER_IP_VENDOR_ID_C != POWER_IP_PMC_VENDOR_ID)
    #error "Power_Ip.c and Power_Ip_PMC.h have different vendor ids"
#endif

/* Check if Power_Ip.c file and Power_Ip_PMC.h file are of the same Autosar version */
#if ((POWER_IP_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_PMC_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AR_RELEASE_MINOR_VERSION_C != POWER_IP_PMC_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AR_RELEASE_REVISION_VERSION_C != POWER_IP_PMC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip.c and Power_Ip_PMC.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_PMC.h file are of the same Software version */
#if ((POWER_IP_SW_MAJOR_VERSION_C != POWER_IP_PMC_SW_MAJOR_VERSION) || \
     (POWER_IP_SW_MINOR_VERSION_C != POWER_IP_PMC_SW_MINOR_VERSION) || \
     (POWER_IP_SW_PATCH_VERSION_C != POWER_IP_PMC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip.c and Power_Ip_PMC.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_RCM.h file are of the same vendor */
#if (POWER_IP_VENDOR_ID_C != POWER_IP_RCM_VENDOR_ID)
    #error "Power_Ip.c and Power_Ip_RCM.h have different vendor ids"
#endif

/* Check if Power_Ip.c file and Power_Ip_RCM.h file are of the same Autosar version */
#if ((POWER_IP_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_RCM_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AR_RELEASE_MINOR_VERSION_C != POWER_IP_RCM_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AR_RELEASE_REVISION_VERSION_C != POWER_IP_RCM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip.c and Power_Ip_RCM.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_RCM.h file are of the same Software version */
#if ((POWER_IP_SW_MAJOR_VERSION_C != POWER_IP_RCM_SW_MAJOR_VERSION) || \
     (POWER_IP_SW_MINOR_VERSION_C != POWER_IP_RCM_SW_MINOR_VERSION) || \
     (POWER_IP_SW_PATCH_VERSION_C != POWER_IP_RCM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip.c and Power_Ip_RCM.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_SMC.h file are of the same Autosar version */
#if ((POWER_IP_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_SMC_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AR_RELEASE_MINOR_VERSION_C != POWER_IP_SMC_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AR_RELEASE_REVISION_VERSION_C != POWER_IP_SMC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip.c and Power_Ip_SMC.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_SMC.h file are of the same Software version */
#if ((POWER_IP_SW_MAJOR_VERSION_C != POWER_IP_SMC_SW_MAJOR_VERSION) || \
     (POWER_IP_SW_MINOR_VERSION_C != POWER_IP_SMC_SW_MINOR_VERSION) || \
     (POWER_IP_SW_PATCH_VERSION_C != POWER_IP_SMC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip.c and Power_Ip_SMC.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_CortexM4.h file are of the same vendor */
#if (POWER_IP_VENDOR_ID_C != POWER_IP_CORTEXM4_VENDOR_ID)
    #error "Power_Ip.c and Power_Ip_CortexM4.h have different vendor ids"
#endif

/* Check if Power_Ip.c file and Power_Ip_CortexM4.h file are of the same Autosar version */
#if ((POWER_IP_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_CORTEXM4_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AR_RELEASE_MINOR_VERSION_C != POWER_IP_CORTEXM4_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AR_RELEASE_REVISION_VERSION_C != POWER_IP_CORTEXM4_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip.c and Power_Ip_CortexM4.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_CortexM4.h file are of the same Software version */
#if ((POWER_IP_SW_MAJOR_VERSION_C != POWER_IP_CORTEXM4_SW_MAJOR_VERSION) || \
     (POWER_IP_SW_MINOR_VERSION_C != POWER_IP_CORTEXM4_SW_MINOR_VERSION) || \
     (POWER_IP_SW_PATCH_VERSION_C != POWER_IP_CORTEXM4_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip.c and Power_Ip_CortexM4.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_SIM.h file are of the same vendor */
#if (POWER_IP_VENDOR_ID_C != POWER_IP_SIM_VENDOR_ID)
    #error "Power_Ip.c and Power_Ip_SIM.h have different vendor ids"
#endif

/* Check if Power_Ip.c file and Power_Ip_SIM.h file are of the same Autosar version */
#if ((POWER_IP_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_SIM_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AR_RELEASE_MINOR_VERSION_C != POWER_IP_SIM_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AR_RELEASE_REVISION_VERSION_C != POWER_IP_SIM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip.c and Power_Ip_SIM.h are different"
#endif

/* Check if Power_Ip.c file and Power_Ip_SIM.h file are of the same Software version */
#if ((POWER_IP_SW_MAJOR_VERSION_C != POWER_IP_SIM_SW_MAJOR_VERSION) || \
     (POWER_IP_SW_MINOR_VERSION_C != POWER_IP_SIM_SW_MINOR_VERSION) || \
     (POWER_IP_SW_PATCH_VERSION_C != POWER_IP_SIM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip.c and Power_Ip_SIM.h are different"
#endif

#if ((POWER_MODE_CHANGE_NOTIFICATION == STD_ON) || (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON))
/* Check if Power_Ip.c file and Clock_Ip.h file are of the same vendor */
#if (POWER_IP_VENDOR_ID_C != CLOCK_IP_VENDOR_ID)
    #error "Power_Ip.c and Clock_Ip.h have different vendor ids"
#endif

/* Check if Power_Ip.c file and Clock_Ip.h file are of the same Autosar version */
#if ((POWER_IP_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip.c and Clock_Ip.h are different"
#endif

/* Check if Power_Ip.c file and Clock_Ip.h file are of the same Software version */
#if ((POWER_IP_SW_MAJOR_VERSION_C != CLOCK_IP_SW_MAJOR_VERSION) || \
     (POWER_IP_SW_MINOR_VERSION_C != CLOCK_IP_SW_MINOR_VERSION) || \
     (POWER_IP_SW_PATCH_VERSION_C != CLOCK_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip.c and Clock_Ip.h are different"
#endif
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/
/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

static const Power_Ip_ResetType ResetReasonArray[(uint8)MCU_RESET_UNDEFINED + 1U] = {MCU_STOP_ACKNOWLEDGE_ERROR_RESET,MCU_MDM_AP_SYSTEM_RESET,MCU_SW_RESET,MCU_CORE_LOCKUP_RESET,MCU_JTAG_RESET,MCU_POWER_ON_RESET,MCU_EXTERNAL_PIN_RESET,MCU_WATCHDOG_RESET,MCU_CMU_LOSS_OF_CLOCK_RESET,MCU_LOSS_OF_LOCK_RESET,MCU_LOSS_OF_CLOCK_RESET,MCU_LOW_OR_HIGH_VOLTAGE_DETECT_RESET,MCU_NO_RESET_REASON,MCU_MULTIPLE_RESET_REASON,MCU_RESET_UNDEFINED};

/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

/* Power Report Error Callback */
Power_Ip_ReportErrorsCallbackType Power_Ip_pfReportErrorsCallback = Power_Ip_ReportPowerErrorsEmptyCallback;

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#if (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON)
static void Power_Ip_PrepareLowPowerMode(Power_Ip_PowerModeType PowerMode);
#endif
#if (POWER_MODE_CHANGE_NOTIFICATION == STD_ON)
static Clock_Ip_PowerModesType Power_Ip_ModeConvert(Power_Ip_PowerModeType PowerMode);
#endif
static Power_Ip_ResetType Power_Ip_ConvertIntergeToResetType(uint32 ResetReasonIndex);

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON)
static void Power_Ip_PrepareLowPowerMode(Power_Ip_PowerModeType PowerMode)
{

    if ((POWER_IP_VLPS_MODE == PowerMode) || (POWER_IP_VLPR_MODE == PowerMode))
    {
        /*
        * All clock monitors are always disabled when chip in a low power mode.
        * However, to prevent unexpected loss of clock reset events, we should
        * disable them before entering any low power modes, including VLPR and VLPS.
        * The function Clock_Ip_PowerModeChangeNotification will handle disabling the clock
        * before entering low power modes: VLPS and VLPR */
        Clock_Ip_PowerModeChangeNotification(VLPR_MODE, BEFORE_POWER_MODE_CHANGE);

        if (POWER_IP_VLPS_MODE == PowerMode)
        {
            /*This enable chip go into deep sleep mode by setting bit SLEEPDEEP */
            Call_Power_Ip_CM4_EnableDeepSleep();
        }
    }

    if ((POWER_IP_STOP1_MODE == PowerMode) || (POWER_IP_STOP2_MODE == PowerMode))
    {
        /*This enable chip go into deep sleep mode by setting bit SLEEPDEEP */
        Call_Power_Ip_CM4_EnableDeepSleep();
    }
}
#endif

#if (POWER_MODE_CHANGE_NOTIFICATION == STD_ON)
static Clock_Ip_PowerModesType Power_Ip_ModeConvert(Power_Ip_PowerModeType PowerMode)
{
    Clock_Ip_PowerModesType ModeChanged = RUN_MODE;

    switch(PowerMode)
    {
        case (POWER_IP_RUN_MODE):
            ModeChanged = RUN_MODE;
            break;
        case (POWER_IP_HSRUN_MODE):
            ModeChanged = HSRUN_MODE;
            break;
        case (POWER_IP_VLPR_MODE):
            ModeChanged = VLPR_MODE;
            break;
        case (POWER_IP_VLPS_MODE):
            ModeChanged = VLPS_MODE;
            break;
        default:
            /* Do nothing */
            break;
    }

    return ModeChanged;
}
#endif
/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief            This function initializes the mode structure.
* @details          This function initializes the mode structure by configuring the MC_ME module.
*
* @param[in]        ModeConfigPtr   Pointer to mode configuration structure.
*
* @return           void
*
* @implements Power_Ip_SetMode_Activity
*
*/
void Power_Ip_SetMode(const Power_Ip_ModeConfigType * ModeConfigPtr)
{
    uint32 PowerSwitchMode;
#if (POWER_MODE_CHANGE_NOTIFICATION == STD_ON)
    Clock_Ip_PowerModesType ModeChanged;
    Clock_Ip_PowerNotificationType ModeChangeStatus;
#endif
    Power_Ip_PowerModeType PowerMode = ModeConfigPtr->PowerMode;

    if (POWER_IP_MODE_OK != Power_Ip_SMC_ModeCheckEntry(PowerMode))
    {
        PowerSwitchMode = POWER_IP_SWITCH_MODE_FAIL;
    }
    else
    {
#if (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON)
        Power_Ip_PrepareLowPowerMode(PowerMode);
#endif /* (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON) */

        /* Request new mode transition to SMC. */
    PowerSwitchMode = Call_Power_Ip_SMC_ModeConfig(ModeConfigPtr);

#if (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON)
        if ((POWER_IP_VLPS_MODE == PowerMode) ||
            (POWER_IP_STOP1_MODE == PowerMode) || (POWER_IP_STOP2_MODE == PowerMode)
           )
        {
            /*This will clear SLEEPDEEP bit after wake-up */
            Call_Power_Ip_CM4_DisableDeepSleep();
        }
#endif
    }
    if (POWER_IP_SWITCH_MODE_FAIL == PowerSwitchMode)
    {
        Power_Ip_ReportPowerErrors(POWER_IP_REPORT_SWITCH_MODE_ERROR, POWER_IP_ERR_CODE_RESERVED);
    }
    else
    {
#if (POWER_MODE_CHANGE_NOTIFICATION == STD_ON)
        ModeChangeStatus = POWER_MODE_CHANGED;
        /* Convert mode from PowerModeType to Clock_Ip_PowerModesType */
        ModeChanged = Power_Ip_ModeConvert(PowerMode);
        /* Callback Clock Ip Notification. */
        Clock_Ip_PowerModeChangeNotification(ModeChanged,ModeChangeStatus);
#endif
    }
}

#ifdef POWER_IP_POWERMODE_STATE_API
#if (STD_ON == POWER_IP_POWERMODE_STATE_API)
/**
* @brief            This function return current power mode.
* @details          Return value:
*                       0000_0001b = RUN
*                       0000_0100b = VLPR
*                       0001_0000b = VLPS
*                       1000_0000b = HSRUN
*
* @param[in]        None
*
* @return           Power_Ip_PowerModeStateType
*/
Power_Ip_PowerModeStateType Power_Ip_GetPowerModeState(void)
{
    Power_Ip_PowerModeStateType State ;

    State = Power_Ip_SMC_GetPowerModeState();
    return State;
}
#endif
#endif

#if (POWER_IP_PERFORM_RESET_API == STD_ON)
/**
* @brief            This function performs a microcontroller reset.
* @details          This function performs a microcontroller reset by using the hardware feature of
*                   the microcontroller.
*                   Called by:
*                       - Mcu_PerformReset() from HLD.
*
* @param[in]        HwIPsConfigPtr  Pointer to LLD configuration structure (member of
*                   'Mcu_ConfigType' struct).
*
* @return           void
*
* @implements Power_Ip_PerformReset_Activity
*
*/
void Power_Ip_PerformReset(const Power_Ip_HwIPsConfigType * HwIPsConfigPtr)
{
    (void)(HwIPsConfigPtr);

    /* Performs a micro controller reset. */
    Call_Power_Ip_CM4_SystemReset();
}
#endif /* (POWER_IP_PERFORM_RESET_API == STD_ON) */


/**
* @brief            This function convert a number (uint32) to Power_Ip_ResetType.
*
* @details          This function convert a number (uint32) to Power_Ip_ResetType.
*
* @param[in]        ResetReasonIndex   Reset reason index.
*
* @return           Power_Ip_ResetType
*/
static Power_Ip_ResetType Power_Ip_ConvertIntergeToResetType(uint32 ResetReasonIndex)
{
    Power_Ip_ResetType ResetReason = MCU_NO_RESET_REASON;

    if (ResetReasonArray[ResetReasonIndex] <= MCU_RESET_UNDEFINED)
    {
        ResetReason = ResetReasonArray[ResetReasonIndex];
    }
    else
    {
        ResetReason = MCU_NO_RESET_REASON;
    }

    return ResetReason;
}


/**
* @brief            This function returns the reset reason.
* @details          This routine returns the Reset reason that is read from the hardware.
*
* @param[in]        None
*
* @return           void
*
* @implements Power_Ip_GetResetReason_Activity
*
*/
Power_Ip_ResetType Power_Ip_GetResetReason(void)
{
    Power_Ip_ResetType ResetReason;
    uint32 ResetVal;

    ResetVal = Call_Power_Ip_RCM_GetResetReason();

    /* Use function Power_Ip_ConvertIntergeToResetType to avoid MISRA violation 10.5 : cast from uint32 to enum */
    ResetReason = Power_Ip_ConvertIntergeToResetType(ResetVal);

    return (Power_Ip_ResetType) ResetReason;
}

/**
* @brief            This function returns the reset reason.
* @details          This routine returns the Reset reason that is read from the hardware.
*                   Called by:
*                       - Mcu_GetResetReason() from HLD.
*
* @param[in]        None
*
* @return           void
*
* @implements Power_Ip_GetResetRawValue_Activity
*
*/
Power_Ip_RawResetType Power_Ip_GetResetRawValue(void)
{
    Power_Ip_RawResetType ResetReason;

    ResetReason = (Power_Ip_RawResetType)Call_Power_Ip_RCM_GetResetRawValue();
    return (Power_Ip_RawResetType) ResetReason;
}

/**
* @brief            This function initializes the power module.
* @details
*
* @param[in]        HwIPsConfigPtr  Pointer to LLD configuration structure.
*
* @return           void
*
* @implements Power_Ip_Init_Activity
*
*/
void Power_Ip_Init (const Power_Ip_HwIPsConfigType * HwIPsConfigPtr)
{
    POWER_IP_DEV_ASSERT(NULL_PTR != HwIPsConfigPtr);
    (void)(HwIPsConfigPtr);

#if (defined(POWER_IP_DISABLE_RCM_INIT) && (STD_OFF == POWER_IP_DISABLE_RCM_INIT))
    /* Init the RCM */
    Call_Power_Ip_RCM_ResetInit(HwIPsConfigPtr->RCMConfigPtr);
#endif

#if (defined(POWER_IP_DISABLE_PMC_INIT) && (STD_OFF == POWER_IP_DISABLE_PMC_INIT))
    Call_Power_Ip_PMC_PowerInit(HwIPsConfigPtr->PMCConfigPtr);
#endif

#if (defined(POWER_IP_DISABLE_SMC_INIT) && (STD_OFF == POWER_IP_DISABLE_SMC_INIT))
    Call_Power_Ip_SMC_AllowedModesConfig(HwIPsConfigPtr->SMCConfigPtr);
#endif
}

#ifdef POWER_IP_SLEEPONEXIT_SUPPORT
  #if (POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON)
 /**
* @brief        The function disable SLEEPONEXIT bit.
* @details      The function disable SLEEPONEXIT bit.
*
* @param[in]    none
* @return void
* @implements Power_Ip_DisableSleepOnExit_Activity
*/
void Power_Ip_DisableSleepOnExit(void)
{
    Call_Power_Ip_CM4_DisableSleepOnExit();
}
 /**
* @brief        The function enable SLEEPONEXIT bit.
* @details      The function enable SLEEPONEXIT bit.
*
* @param[in]    none
* @return void
* @implements Power_Ip_EnableSleepOnExit_Activity
*/
void Power_Ip_EnableSleepOnExit(void)
{
    Call_Power_Ip_CM4_EnableSleepOnExit();
}
  #endif
#endif

#ifdef POWER_IP_SRAM_RETEN_CONFIG_API
#if (POWER_IP_SRAM_RETEN_CONFIG_API == STD_ON)
/**
 * @brief   Configuration for SRAM retention.
 * @details This function configure for both SRAML_RETEN and SRAMU_RETEN bits.
 *                   Called by:
 *                       - Mcu_Ipw_SRAMRetentionConfig() from IPW
 * @param[in] SRAMRetenConfig    The value will be configured to SRAML_RETEN and SRAMU_RETEN bits.
 *                                  MCU_SRAML_RETEN - SRAML will be retain only.
 *                                  MCU_SRAMU_RETEN - SRAMU will be retain only.
 *                                  MCU_SRAMLU_RETEN - Both SRAML and SRAMU will be retain.
 *                                  MCU_NO_SRAMLU_RETEN - Both SRAML and SRAMU will not be retain.
 *
 * @return                   void
 *
 */
void Power_Ip_SRAMRetentionConfig(Power_Ip_SRAMRetenConfigType SRAMRetenConfig)
{
    Call_Power_Ip_SIM_SRAMRetentionConfig(SRAMRetenConfig);
}
#endif
#endif

#ifdef POWER_IP_PMCAECONFIG_API
#if (POWER_IP_PMCAECONFIG_API == STD_ON)
/**
* @brief            This function performs a microcontroller reset.
* @details          This function performs a microcontroller reset by using the hardware feature of
*                   the microcontroller.
*                   Called by:
*                       - Mcu_PerformReset() from HLD.
*
* @param[in]        HwIPsConfigPtr  Pointer to LLD configuration structure (member of
*                   'Mcu_ConfigType' struct).
*
* @return           void
*
*
*
*/
void Power_Ip_PmcAeConfig(const Power_Ip_HwIPsConfigType * HwIPsConfigPtr)
{
    Power_Ip_PMC_AE_PowerInit(HwIPsConfigPtr->PMCConfigPtr);
}
#endif /* (POWER_IP_PMCAECONFIG_API == STD_ON) */
#endif

#ifdef POWER_IP_AECRESETCONFIG_API
#if (POWER_IP_AECRESETCONFIG_API == STD_ON)
/**
* @brief            This function configure reset generator (AEC_AE)
* @details          This function configure reset generator (AEC_AE)
*                   Called by:
*                       - Mcu_AecResetConfig() from HLD.
*
* @param[in]        HwIPsConfigPtr  Pointer to LLD configuration structure (member of
*                   'Mcu_ConfigType' struct).
*
* @return           void
*
*
*
*/
void Power_Ip_AecResetConfig(const Power_Ip_HwIPsConfigType * HwIPsConfigPtr)
{
    Power_Ip_AEC_Reset_Config(HwIPsConfigPtr->AECConfigPtr);
}
#endif /* (POWER_IP_AECRESETCONFIG_API == STD_ON) */
#endif

/**
* @brief            This function installs a callback for reporting errors from power driver.
* @details
*
* @param[in]        ReportErrorsCallback    Callback to be installed.
*
* @return           void
*
* @implements Power_Ip_InstallNotificationsCallback_Activity
*/
void Power_Ip_InstallNotificationsCallback(Power_Ip_ReportErrorsCallbackType ReportErrorsCallback)
{
    POWER_IP_DEV_ASSERT(NULL_PTR != ReportErrorsCallback);

    Power_Ip_pfReportErrorsCallback = ReportErrorsCallback;
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

