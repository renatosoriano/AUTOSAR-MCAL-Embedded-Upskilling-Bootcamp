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
*   @file    Mcu_Ipw.c
*   @version    2.0.0
*
*   @brief   AUTOSAR Mcu - Mcu driver header file.
*   @details AUTOSAR specific Mcu driver header file.

*   @addtogroup MCU_DRIVER Mcu Driver
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
/* Header file with prototype functions defines in this layer. */
#include "Mcu_Ipw.h"
#include "Clock_Ip.h"
#include "Power_Ip.h"
#include "Ram_Ip.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif

#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Mcu_Dem_Wrapper.h"
#endif

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_IPW_VENDOR_ID_C                      43
#define MCU_IPW_AR_RELEASE_MAJOR_VERSION_C       4
#define MCU_IPW_AR_RELEASE_MINOR_VERSION_C       7
#define MCU_IPW_AR_RELEASE_REVISION_VERSION_C    0
#define MCU_IPW_SW_MAJOR_VERSION_C               2
#define MCU_IPW_SW_MINOR_VERSION_C               0
#define MCU_IPW_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Mcu_Ipw.c file and Mcu_Ipw.h file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_IPW_VENDOR_ID)
    #error "Mcu_Ipw.c and Mcu_Ipw.h have different vendor ids"
#endif

/* Check if Mcu_Ipw.c file and Mcu_Ipw.h file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C != MCU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C != MCU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_Ipw.c and Mcu_Ipw.h are different"
#endif

/* Check if Mcu_Ipw.c file and Mcu_Ipw.h file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_IPW_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_IPW_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_Ipw.c and Mcu_Ipw.h are different"
#endif

/* Check if Mcu_Ipw.c file and Power_Ip.h file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != POWER_IP_VENDOR_ID)
    #error "Mcu_Ipw.c and Power_Ip.h have different vendor ids"
#endif

/* Check if Mcu_Ipw.c file and Power_Ip.h file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C != POWER_IP_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != POWER_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_Ipw.c and Power_Ip.h are different"
#endif

/* Check if Mcu_Ipw.c file and Power_Ip.h file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != POWER_IP_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != POWER_IP_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != POWER_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_Ipw.c and Power_Ip.h are different"
#endif

/* Check if Mcu_Ipw.c file and Clock_Ip.h file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != CLOCK_IP_VENDOR_ID)
    #error "Mcu_Ipw.c and Clock_Ip.h have different vendor ids"
#endif

/* Check if Mcu_Ipw.c file and Clock_Ip.h file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_Ipw.c and Clock_Ip.h are different"
#endif

/* Check if Mcu_Ipw.c file and Clock_Ip.h file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != CLOCK_IP_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != CLOCK_IP_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != CLOCK_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_Ipw.c and Clock_Ip.h are different"
#endif

/* Check if Mcu_Ipw.c file and Ram_Ip.h file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != RAM_IP_VENDOR_ID)
    #error "Mcu_Ipw.c and Ram_Ip.h have different vendor ids"
#endif

/* Check if Mcu_Ipw.c file and Ram_Ip.h file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C != RAM_IP_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C != RAM_IP_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != RAM_IP_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_Ipw.c and Ram_Ip.h are different"
#endif

/* Check if Mcu_Ipw.c file and Ram_Ip.h file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != RAM_IP_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != RAM_IP_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != RAM_IP_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_Ipw.c and Ram_Ip.h are different"
#endif

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if Mcu_Ipw.c file and Det.h file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mcu_Ipw.c and Det.h are different"
#endif
#endif
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/* Check if Mcu_Ipw.c file and Mcu_Dem_Wrapper.h file are of the same vendor */
#if (MCU_IPW_VENDOR_ID != MCU_DEM_WRAPPER_VENDOR_ID)
    #error "Mcu_Ipw.c and Mcu_Dem_Wrapper.h have different vendor ids"
#endif

/* Check if Mcu_Ipw.c file and Mcu_Dem_Wrapper.h file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION != MCU_DEM_WRAPPER_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION != MCU_DEM_WRAPPER_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION != MCU_DEM_WRAPPER_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_Ipw.c and Mcu_Dem_Wrapper.h are different"
#endif

/* Check if Mcu_Ipw.c file and Mcu_Dem_Wrapper.h file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION != MCU_DEM_WRAPPER_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION != MCU_DEM_WRAPPER_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION != MCU_DEM_WRAPPER_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_Ipw.c and Mcu_Dem_Wrapper.h are different"
#endif
#endif /* (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

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

#if (CLOCK_IP_ENABLE_NOTIFICATIONS == STD_ON)
static void ClockNotificationsCallback(Clock_Ip_NotificationType Notification, Clock_Ip_NameType ClockName);
#endif

#if (POWER_IP_ENABLE_NOTIFICATIONS == STD_ON)
static void ReportPowerErrorsCallback(Power_Ip_ReportErrorType Error, uint8 ErrorCode);
#endif

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (CLOCK_IP_ENABLE_NOTIFICATIONS == STD_ON)
static void ClockNotificationsCallback(Clock_Ip_NotificationType Notification, Clock_Ip_NameType ClockName)
{
    (void)ClockName;

    switch(Notification)
    {
        case CLOCK_IP_CMU_ERROR:
        {
            Mcu_ClkSrcFailureNotification(ClockName);
        }
        break;


        case CLOCK_IP_REPORT_TIMEOUT_ERROR:
        {
#if (defined(MCU_DISABLE_DEM_REPORT_ERROR_STATUS) && (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF))
            Mcu_Macro_ReportDemTimeoutError();
#endif /* (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
        }
        break;

        default:
        {
            /* Notification is not consumed HLD layer (it's not enabled from MCU component) */
        }
        break;
    }
}
#endif /* (CLOCK_IP_ENABLE_NOTIFICATIONS == STD_ON) */

#if (POWER_IP_ENABLE_NOTIFICATIONS == STD_ON)
static void ReportPowerErrorsCallback(Power_Ip_ReportErrorType Error, uint8 ErrorCode)
{
    switch(Error)
    {
        case POWER_IP_REPORT_TIMEOUT_ERROR:
        {
            (void)ErrorCode;
        #if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            Mcu_Macro_ReportDemTimeoutError();
        #endif
        }
        break;
        case POWER_IP_REPORT_SWITCH_MODE_ERROR:
        {
            (void)ErrorCode;
        #if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            Mcu_Macro_ReportDemSwitchModeError();
        #endif
        }
        break;
        case POWER_IP_ISR_ERROR:
        {
        #ifdef MCU_ERROR_ISR_NOTIFICATION
            MCU_ERROR_ISR_NOTIFICATION(ErrorCode);
        #endif
        }
        break;
        case POWER_IP_REPORT_VLPSA_NOTIFICATION:
        {
            (void)ErrorCode;
        #ifdef MCU_VLPSA_NOTIFICATION
            MCU_VLPSA_NOTIFICATION();
        #endif
        }
        break;
        default:
        {
            /* Reporting errors mechanism */
        }
        break;
    }
}
#endif /* (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief            This function initializes the MCU module on the common (main) platform.
* @details          The function initializes the CGM, ME, RGM, and PMC modules.
*                   Called by:
*                       - Mcu_Init() from HLD.
*
* @param[in]        HwIPsConfigPtr   Pointer to IPW configuration structure.
*
* @return           void
*
*/
void Mcu_Ipw_Init(const Mcu_HwIPsConfigType * HwIPsConfigPtr)
{
#if (MCU_INIT_CLOCK == STD_ON)
  #if (CLOCK_IP_ENABLE_NOTIFICATIONS == STD_ON)
    Clock_Ip_InstallNotificationsCallback(ClockNotificationsCallback);
  #endif
#endif

#if (POWER_IP_ENABLE_NOTIFICATIONS == STD_ON)
    Power_Ip_InstallNotificationsCallback(ReportPowerErrorsCallback);
#endif

    /* Init Power and Reset */
    Power_Ip_Init(HwIPsConfigPtr);

    (void)HwIPsConfigPtr; /* Fix warning compiler: unused variable Mcu_pHwIPsConfigPtr */
}


#ifndef MCU_MAX_NORAMCONFIGS
/**
* @brief            This function initializes a given RAM section of the MCU on the common (main) platform.
* @details          Function initializes the RAM section specified by the pointer to the "Mcu_RamConfigType" parameter.
*                   The section's base address, size, value to be written, and write-at-once-size are provided by
*                   the configuration structure.
*                   The function will write the value specified in the configuration structure.
*                   After the write it will read back the RAM to verify that the requested value was
*                   written.
*                   Called by:
*                       - Mcu_InitRamSection() from HLD.
*
* @param[in]        RamConfigPtr   Pointer to RAM section configuration structure
*                   (member of 'Mcu_ConfigType' struct).
*
* @return           Status signaling if the given RAM section has or has not been successfully initialized.
* @retval           E_OK        The RAM section check was successful.
* @retval           E_NOT_OK    The RAM section check was not successful.
*
*/
Std_ReturnType Mcu_Ipw_InitRamSection(const Mcu_RamConfigType * RamConfigPtr)
{
    /* Ram status variable. */
    Std_ReturnType RamStatus;

    switch(Ram_Ip_InitRamSection(RamConfigPtr))
    {
        case RAM_IP_STATUS_OK:
        {
            RamStatus = E_OK;
        }
        break;
        case RAM_IP_STATUS_NOT_OK:
        /* pass-through */
        default:
        {
            RamStatus = E_NOT_OK;
        }
        break;
    }

    /* Return the RAM state. */
    return RamStatus;

}
#endif /* ifndef MCU_MAX_NORAMCONFIGS */


#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            This function initializes the clock structure on the common (main) platform.
* @details          This function initializes the clock structure by configuring the CGM module.
*                   Called by:
*                       - Mcu_InitClock() from HLD.
*
* @param[in]        ClockConfigPtr   Pointer to clock configuration structure
*                   (member of 'Mcu_ConfigType' struct).
*
* @return           void
*
*/
void Mcu_Ipw_InitClock(const Mcu_ClockConfigType * ClockConfigPtr)
{
    Clock_Ip_InitClock(ClockConfigPtr);
}
#endif /* (MCU_INIT_CLOCK == STD_ON) */


#if (MCU_INIT_CLOCK == STD_ON)
  #if (MCU_NO_PLL == STD_OFF)
/**
* @brief              This function activates the main PLL as the system clock source.
* @details            This function sets the PLL as the system clock and also enables monitoring.
*                     Called by:
*                       - Mcu_DistributePllClock() from HLD.
*
* @return           void
*
*/
void Mcu_Ipw_DistributePllClock(void)
{
    Clock_Ip_DistributePll();
}
  #endif /* (MCU_NO_PLL == STD_OFF) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */


#if (MCU_NO_PLL == STD_OFF)
/**
* @brief            This function returns the lock status of the PLL.
* @details          The user takes care that the PLL is locked by executing Mcu_GetPllStatus.
*                   If the MCU_NO_PLL is TRUE the MCU_GetPllStatus has to return
*                   MCU_PLL_STATUS_UNDEFINED.
*                   Called by:
*                       - Mcu_GetPllStatus() from HLD.
*
* @return           Provides the lock status of the PLL.
* @retval           MCU_PLL_STATUS_UNDEFINED   PLL Status is unknown.
* @retval           MCU_PLL_LOCKED             PLL is locked.
* @retval           MCU_PLL_UNLOCKED           PLL is unlocked.
*
*/
Mcu_PllStatusType Mcu_Ipw_GetPllStatus(void)
{
    /* PLL status variable. */
    Mcu_PllStatusType PllStatus;

    switch(Clock_Ip_GetPllStatus())
    {
        case CLOCK_IP_PLL_LOCKED:
        {
            PllStatus = MCU_PLL_LOCKED;
        }
        break;
        case CLOCK_IP_PLL_UNLOCKED:
        {
            PllStatus = MCU_PLL_UNLOCKED;
        }
        break;
        case CLOCK_IP_PLL_STATUS_UNDEFINED:
        default:
        {
            PllStatus = MCU_PLL_STATUS_UNDEFINED;
        }
        break;
    }

    /* Return the PLL status. */
    return PllStatus;
}
#endif /* (MCU_NO_PLL == STD_OFF) */


#ifdef MCU_GET_CLOCK_FREQUENCY_API
#if (MCU_GET_CLOCK_FREQUENCY_API == STD_ON)
/**
* @brief            This function returns the frequency of a given clock.
* @details          The function returns the frequency of a given clock which is request by user.
*                   Called by:
*                       - Mcu_GetClockFrequency() from HLD.
*
* @param[in]        ClockName   Name of the clock source for which need to get frequency.
*
* @return           Provides the frequency value of a source clock.
*
*/
uint32 MCU_Ipw_GetClockFrequency(Clock_Ip_NameType ClockName)
{
    return Clock_Ip_GetClockFrequency(ClockName);
}
#endif /* (MCU_GET_CLOCK_FREQUENCY_API == STD_ON) */
#endif /* MCU_GET_CLOCK_FREQUENCY_API */

/**
* @brief            This function initializes the mode structure.
* @details          This function initializes the mode structure by configuring the MC_ME module.
*                   Called by:
*                       - Mcu_SetMode() from HLD.
*
* @param[in]        ModeConfigPtr   Pointer to mode configuration structure.
*
* @return           void
*
*/
void Mcu_Ipw_SetMode(const Mcu_ModeConfigType * ModeConfigPtr)
{
    Power_Ip_SetMode(ModeConfigPtr);
}


#if (MCU_PERFORM_RESET_API == STD_ON)
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
*/
void Mcu_Ipw_PerformReset(const Mcu_HwIPsConfigType * HwIPsConfigPtr)
{
    /*
     *  Performs a microcontroller reset.
     *  A RESET mode requested via the ME_MCTL register is passed to the MC_RGM, which generates a
     *  global system reset and initiates the reset sequence.
     */

    Power_Ip_PerformReset(HwIPsConfigPtr);
}
#endif /* (MCU_PERFORM_RESET_API == STD_ON) */

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
*/
Mcu_ResetType Mcu_Ipw_GetResetReason(void)
{
    return (Mcu_ResetType)Power_Ip_GetResetReason();
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
*/
Mcu_RawResetType Mcu_Ipw_GetResetRawValue(void)
{
    return (Mcu_RawResetType)Power_Ip_GetResetRawValue();
}

#if (MCU_POWERMODE_STATE_API == STD_ON)
/**
* @brief            This function return current power mode.
*
* @details          This function return current power mode.
*
* @param[in]        None
*
* @return           Power_Ip_PowerModeStateType
*/
Mcu_PowerModeStateType Mcu_Ipw_GetPowerModeState(void)
{
    Mcu_PowerModeStateType State ;

    State = Power_Ip_GetPowerModeState();
    return State;
}
#endif /*(MCU_POWERMODE_STATE_API == STD_ON)*/

#ifdef MCU_DISABLE_CMU_API
#if (MCU_DISABLE_CMU_API == STD_ON)
/* Function disable clock monitor */
void Mcu_Ipw_DisableCmu(Clock_Ip_NameType ClockName)
{
    Clock_Ip_DisableClockMonitor(ClockName);
}
#endif /* (MCU_DISABLE_CMU_API == STD_ON) */
#endif /* MCU_DISABLE_CMU_API */

#ifdef MCU_SLEEPONEXIT_SUPPORT
  #if (MCU_SLEEPONEXIT_SUPPORT == STD_ON)
/**
* @brief            This function disable/enable SleepOnExit.
* @details          Disable/enable Sleep on exit when returning from Handler mode to Thread mode.
*                   Called by:
*                       - Mcu_CM4_SleepOnExit() from HLD.
*
* @param[in]        None
*
* @return           void
*
*/
void Mcu_Ipw_SleepOnExit(Mcu_SleepOnExitType SleepOnExit)
{
    if(MCU_SLEEP_ON_EXIT_DISABLED == (Mcu_SleepOnExitType)SleepOnExit)
    {
        Power_Ip_DisableSleepOnExit();
    }
    else
    {
        Power_Ip_EnableSleepOnExit();
    }
}
  #endif
#endif

#ifdef MCU_SRAM_RETEN_CONFIG_API
#if (MCU_SRAM_RETEN_CONFIG_API == STD_ON)
/**
 * @brief   Configuration for SRAM retention.
 *
 * @details This function configure for both SRAML_RETEN and SRAMU_RETEN bits.
 *
 * @return                   void
 */
void Mcu_Ipw_SRAMRetentionConfig(Mcu_SRAMRetenConfigType SRAMRetenConfig)
{
    Power_Ip_SRAMRetentionConfig(SRAMRetenConfig);
}
#endif
#endif

#ifdef MCU_PMCAECONFIG_API
#if (MCU_PMCAECONFIG_API == STD_ON)
/**
* @brief            This function configure the Power Management Controller AE.
* @details          This function configure the Power Management Controller AE of
*                   the microcontroller.
*                   Called by:
*                       - Mcu_PmcAeConfig() from HLD.
*
* @param[in]        HwIPsConfigPtr  Pointer to LLD configuration structure (member of
*                   'Mcu_ConfigType' struct).
*
* @return           void
*
*/
void Mcu_Ipw_PmcAeConfig(const Mcu_HwIPsConfigType * HwIPsConfigPtr)
{
    Power_Ip_PmcAeConfig(HwIPsConfigPtr);
}
#endif /* (MCU_PMCAECONFIG_API == STD_ON) */
#endif

#ifdef MCU_AECRESETCONFIG_API
#if (MCU_AECRESETCONFIG_API == STD_ON)
/**
* @brief            This function configure the reset generator AE.
* @details          This function configure the reset generator AE of
*                   the microcontroller.
*                   Called by:
*                       - Mcu_AecResetConfig() from HLD.
*
* @param[in]        HwIPsConfigPtr  Pointer to LLD configuration structure (member of
*                   'Mcu_ConfigType' struct).
*
* @return           void
*
*/
void Mcu_Ipw_AecResetConfig(const Mcu_HwIPsConfigType * HwIPsConfigPtr)
{
    Power_Ip_AecResetConfig(HwIPsConfigPtr);
}
#endif /* (MCU_AECRESETCONFIG_API == STD_ON) */
#endif

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

