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
*   @file       Clock_Ip_Specific.c
*   @version    2.0.0
*
*   @brief   CLOCK driver implementations.
*   @details CLOCK driver implementations.
*
*   @addtogroup CLOCK_DRIVER Clock Ip Driver
*   @{
*/


#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Clock_Ip_Private.h"

#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    #define USER_MODE_REG_PROT_ENABLED      (STD_ON)
    #include "RegLockMacros.h"
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_SPECIFIC_VENDOR_ID_C                      43
#define CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION_C       7
#define CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION_C               2
#define CLOCK_IP_SPECIFIC_SW_MINOR_VERSION_C               0
#define CLOCK_IP_SPECIFIC_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Specific.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_SPECIFIC_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Specific.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Specific.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Specific.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Specific.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_SPECIFIC_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_SPECIFIC_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Specific.c and Clock_Ip_Private.h are different"
#endif

#if (defined(CLOCK_IP_ENABLE_USER_MODE_SUPPORT))
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Clock_Ip_Specific.c file and RegLockMacros.h file are of the same Autosar version */
    #if ((CLOCK_IP_SPECIFIC_AR_RELEASE_MAJOR_VERSION_C    != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
        (CLOCK_IP_SPECIFIC_AR_RELEASE_MINOR_VERSION_C    != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Clock_Ip_Specific.c and RegLockMacros.h are different"
    #endif
    #endif
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define CLOCK_IP_SCS_SELECTOR_HARDWARE_VALUES_NO           7U
#define CLOCK_IP_RUN_POWER_MODE_STATUS                     1U

#if (defined (CLOCK_IP_S32K118) || defined(CLOCK_IP_S32K116))

    #define CLOCK_IP_SYS_OSC                       1U
    #define CLOCK_IP_CMU                           1U
    #define CLOCK_IP_SCS_RUN                       4U
    #define CLOCK_IP_FIRCOSC                       4U
    #define CLOCK_IP_DIVCORE_RUN                   5U
    #define CLOCK_IP_DIVBUS_RUN                    7U
    #define CLOCK_IP_DIVSLOW_RUN                   9U

#elif (defined (CLOCK_IP_S32K142W) || defined(CLOCK_IP_S32K144W) || defined(CLOCK_IP_S32M244) || \
    defined(CLOCK_IP_S32M242) || defined(CLOCK_IP_S32M241) || defined(CLOCK_IP_S32M243))

    #define CLOCK_IP_SYS_OSC                       1U
    #define CLOCK_IP_SYS_PLL                       1U
    #define CLOCK_IP_FIRCOSC                       4U
    #define CLOCK_IP_SCS_RUN                       5U
    #define CLOCK_IP_DIVCORE_RUN                   6U
    #define CLOCK_IP_DIVBUS_RUN                    8U
    #define CLOCK_IP_DIVSLOW_RUN                   10U

#elif (defined (CLOCK_IP_S32K142) || defined(CLOCK_IP_S32K144) || defined(CLOCK_IP_S32K146) || defined(CLOCK_IP_S32K148))

    #define CLOCK_IP_SYS_OSC                       1U
    #define CLOCK_IP_SYS_PLL                       1U
    #define CLOCK_IP_FIRCOSC                       4U
    #define CLOCK_IP_SCS_RUN                       5U
    #define CLOCK_IP_DIVCORE_RUN                   6U
    #define CLOCK_IP_SCS_HSRUN                     7U
    #define CLOCK_IP_DIVCORE_HSRUN                 8U
    #define CLOCK_IP_DIVBUS_RUN                    9U
    #define CLOCK_IP_DIVBUS_HSRUN                  11U
    #define CLOCK_IP_DIVSLOW_RUN                   12U
    #define CLOCK_IP_DIVSLOW_HSRUN                 14U

#endif

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/
/* Clock start initialized section data */
#define MCU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcu_MemMap.h"

static const Clock_Ip_ClockConfigType *Clock_Ip_apConfig;

#if defined(CLOCK_IP_HAS_SPLL_CLK)
static const Clock_Ip_PllCallbackType * Clock_Ip_pxSpllClock;
#endif

static const Clock_Ip_ExtOscCallbackType *Clock_Ip_pxSoscClock;
static const Clock_Ip_IntOscCallbackType *Clock_Ip_pxFircClock;

#if defined(CLOCK_IP_HAS_FIRC_MON1_CLK) || defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
static const Clock_Ip_ClockMonitorCallbackType *Clock_Ip_pxCmuFircMonitor;
#endif
static const Clock_Ip_SelectorCallbackType *Clock_Ip_pxScsRunClockSelector;

static const Clock_Ip_DividerCallbackType *Clock_Ip_pxCoreRunClockDivider;
static const Clock_Ip_DividerCallbackType *Clock_Ip_pxBusRunClockDivider;
static const Clock_Ip_DividerCallbackType *Clock_Ip_pxSlowRunClockDivider;

static const Clock_Ip_IrcoscConfigType *Clock_Ip_pxFircConfig;
static const Clock_Ip_XoscConfigType *Clock_Ip_pxSoscConfig;
#if defined(CLOCK_IP_HAS_SPLL_CLK)
static const Clock_Ip_PllConfigType *Clock_Ip_pxSpllConfig;
#endif


#if defined(CLOCK_IP_HAS_FIRC_MON1_CLK) || defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
const Clock_Ip_CmuConfigType *Clock_Ip_pxCmuFircMon1Config;
const Clock_Ip_CmuConfigType *Clock_Ip_pxCmuFircMon2Config;
#endif

static const Clock_Ip_SelectorConfigType *Clock_Ip_pxScsConfigRunMode;
static const Clock_Ip_SelectorConfigType *Clock_Ip_pxScsConfigVlprMode;

static const Clock_Ip_DividerConfigType *Clock_Ip_pxCoreConfigRunMode;
static const Clock_Ip_DividerConfigType *Clock_Ip_pxCoreConfigVlprMode;
static const Clock_Ip_DividerConfigType *Clock_Ip_pxBusConfigRunMode;
static const Clock_Ip_DividerConfigType *Clock_Ip_pxBusConfigVlprMode;
static const Clock_Ip_DividerConfigType *Clock_Ip_pxSlowConfigRunMode;
static const Clock_Ip_DividerConfigType *Clock_Ip_pxSlowConfigVlprMode;

#if defined(CLOCK_IP_HAS_SLOW_HSRUN_CLK)
static const Clock_Ip_SelectorCallbackType *Clock_Ip_pxScsHsrunClockSelector;

static const Clock_Ip_DividerCallbackType *Clock_Ip_pxCoreHsrunClockDivider;
static const Clock_Ip_DividerCallbackType *Clock_Ip_pxBusHsrunClockDivider;
static const Clock_Ip_DividerCallbackType *Clock_Ip_pxSlowHsrunClockDivider;
static const Clock_Ip_SelectorConfigType *Clock_Ip_pxScsConfigHsrunMode;
static const Clock_Ip_DividerConfigType *Clock_Ip_pxCoreConfigHsrunMode;
static const Clock_Ip_DividerConfigType *Clock_Ip_pxBusConfigHsrunMode;
static const Clock_Ip_DividerConfigType *Clock_Ip_pxSlowConfigHsrunMode;
#endif

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcu_MemMap.h"



/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

static const Clock_Ip_NameType ClockSource[CLOCK_IP_SCS_SELECTOR_HARDWARE_VALUES_NO] =
{
    CLOCK_IS_OFF,                  /* clock name for 0  hardware value */
    SOSC_CLK,                      /* clock name for 1  hardware value */
    SIRC_CLK,                      /* clock name for 2  hardware value */
    FIRC_CLK,                      /* clock name for 3  hardware value */
    CLOCK_IS_OFF,                  /* clock name for 4  hardware value */
    CLOCK_IS_OFF,                  /* clock name for 5  hardware value */
    #if defined(CLOCK_IP_HAS_SPLL_CLK)
        SPLL_CLK,                  /* clock name for 6  hardware value */
    #else
        CLOCK_IS_OFF,              /* clock name for 6  hardware value */
    #endif
};


/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
/* Clock start initialized section data */
#define MCU_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcu_MemMap.h"

static Clock_Ip_IrcoscConfigType FircConfiguration;
static Clock_Ip_XoscConfigType SoscConfiguration;

#if defined(CLOCK_IP_HAS_SPLL_CLK)
static Clock_Ip_PllConfigType SpllConfiguration;
#endif

#if defined(CLOCK_IP_HAS_FIRC_MON1_CLK) || defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
static Clock_Ip_CmuConfigType CmuConfiguration;
#endif

static Clock_Ip_SelectorConfigType SelectorConfigurations[3U];
static Clock_Ip_DividerConfigType CoreDividerConfigurations[3U];
static Clock_Ip_DividerConfigType BusDividerConfigurations[3U];
static Clock_Ip_DividerConfigType SlowDividerConfigurations[3U];

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Mcu_MemMap.h"

/* Clock start initialized section data */
#define MCU_START_SEC_VAR_INIT_BOOLEAN
#include "Mcu_MemMap.h"

static boolean Clock_Ip_bFircWasEnabledBeforeMcuInit = TRUE;                 /* Firc clock was enabled before MCU initialization */
static boolean Clock_Ip_bAcceptedCopyClockConfiguration = TRUE;

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_INIT_BOOLEAN
#include "Mcu_MemMap.h"

/* Clock start initialized section data */
#define MCU_START_SEC_VAR_CLEARED_BOOLEAN
#include "Mcu_MemMap.h"

static boolean Clock_Ip_bObjsAreInitialized;   /* Clock objects are initialized. */

/* Clock stop initialized section data */
#define MCU_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/* Clock start section code */
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#if defined(CLOCK_IP_HAS_FIRC_MON1_CLK)
void Clock_Ip_EnableCmu0Gate_TrustedCall(void);
#endif

#if defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
void Clock_Ip_EnableCmu1Gate_TrustedCall(void);
#endif

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

static const Clock_Ip_IrcoscConfigType *getFircConfig(void);
static const Clock_Ip_XoscConfigType *getSoscConfig(void);
static const Clock_Ip_XoscConfigType *getSoscConfig(void);
#if defined(CLOCK_IP_HAS_SPLL_CLK)
static const Clock_Ip_PllConfigType *getSpllConfig(void);
#endif
#if defined(CLOCK_IP_HAS_FIRC_MON1_CLK) || defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
static const Clock_Ip_CmuConfigType *getCmuFircConfig(Clock_Ip_NameType Name);
static void Clock_Ip_PllPowerClockIp(void);
#endif
static const Clock_Ip_SelectorConfigType *getSelectorConfig(Clock_Ip_NameType Name);
static const Clock_Ip_DividerConfigType *getCoreDividerConfig(Clock_Ip_NameType Name);
static const Clock_Ip_DividerConfigType *getBusDividerConfig(Clock_Ip_NameType Name);
static const Clock_Ip_DividerConfigType *getSlowDividerConfig(Clock_Ip_NameType Name);
static void Clock_Ip_ClockInitializeObjects(Clock_Ip_ClockConfigType const * Config);
void SetFircToResetValue_TrustedCall(void);
void SetSimLpoclksRegister_TrustedCall(Clock_Ip_ClockConfigType const *Config);

static void DisableSafeClock(Clock_Ip_ClockConfigType const * Config);
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/



#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

static void DisableSafeClock(Clock_Ip_ClockConfigType const * Config)
{
    uint32 Index;
    boolean FircConfigFound = FALSE;

    if (Config != NULL_PTR)
    {
        for (Index = 0U; Index < Clock_Ip_apConfig->IrcoscsCount; Index++)
        {
            if (Clock_Ip_apConfig->Ircoscs[Index].Name == FIRC_CLK)
            {
                FircConfigFound = TRUE;
                if (Clock_Ip_apConfig->Ircoscs[Index].Enable == FALSE)
                {
                    /* Disable FIRC according to configuration */
                    Clock_Ip_axIntOscCallbacks[Clock_Ip_au8IrcoscCallbackIndex[CLOCK_IP_FIRCOSC]].Disable(FIRC_CLK);
                }
                break;
            }
        }
    }

    if ((FircConfigFound == FALSE) && (Clock_Ip_bFircWasEnabledBeforeMcuInit == FALSE))
    {
        /* Disable FIRC according to configuration */
        Clock_Ip_axIntOscCallbacks[Clock_Ip_au8IrcoscCallbackIndex[CLOCK_IP_FIRCOSC]].Disable(FIRC_CLK);
    }
}

void SetFircToResetValue_TrustedCall(void)
{
        /* Range is 48Mhz. */
        IP_SCG->FIRCCFG = SCG_FIRCCFG_RANGE(0U);

        /* Enable clock, Regulator is enabled. */
        IP_SCG->FIRCCSR |= (SCG_FIRCCSR_FIRCEN(1U) | SCG_FIRCCSR_FIRCREGOFF(0U));
}

void SetSimLpoclksRegister_TrustedCall(Clock_Ip_ClockConfigType const *Config)
{
    uint32 SimLpoValue = 3U; /* Reset value of SIM_LPOCLKS register */
    uint32 Index;

    /* The LPOCLKS register is a write-once register so configuration will be written here*/

    for (Index = 0U; Index < Config->SelectorsCount; Index++)
    {
        /* Selector for RTC_CLK */
        if (RTC_CLK == Config->Selectors[Index].Name)
        {
            SimLpoValue |= ((uint32)(Clock_Ip_au16SelectorEntryHardwareValue[Config->Selectors[Index].Value]) << SIM_LPOCLKS_RTCCLKSEL_SHIFT);
        }

         /* Selector for LPO_CLK */
        if (LPO_CLK == Config->Selectors[Index].Name)
        {
            SimLpoValue |= ((uint32)(Clock_Ip_au8SelectorEntrySIMHardwareValue[Config->Selectors[Index].Value]) << SIM_LPOCLKS_LPOCLKSEL_SHIFT);
        }
    }

    for (Index = 0U; Index < Config->GatesCount; Index++)    /* Set clock gates that are under clock control. */
    {
        /* Gate for LPO_32K_CLK */
        if (LPO_32K_CLK == Config->Gates[Index].Name)
        {
             SimLpoValue |= ((uint32)(Config->Gates[Index].Enable) << SIM_LPOCLKS_LPO32KCLKEN_SHIFT);
        }

         /* Gate for LPO_1K_CLK */
        if (LPO_1K_CLK == Config->Gates[Index].Name)
        {
            SimLpoValue |= ((uint32)(Config->Gates[Index].Enable) << SIM_LPOCLKS_LPO1KCLKEN_SHIFT);
        }
    }

    IP_SIM->LPOCLKS = SimLpoValue;
}

#if defined(CLOCK_IP_HAS_FIRC_MON1_CLK)
void Clock_Ip_EnableCmu0Gate_TrustedCall(void)
{
    uint32 RegValue;

    RegValue = IP_PCC->PCCn[Clock_Ip_au8ClockFeatures[CMU0_CLK][CLOCK_IP_GATE_INDEX]];
    RegValue &= ~PCC_PCCn_CGC_MASK;
    RegValue |= PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[Clock_Ip_au8ClockFeatures[CMU0_CLK][CLOCK_IP_GATE_INDEX]] = RegValue;

}
#endif

#if defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
void Clock_Ip_EnableCmu1Gate_TrustedCall(void)
{
    uint32 RegValue;

    RegValue = IP_PCC->PCCn[Clock_Ip_au8ClockFeatures[CMU1_CLK][CLOCK_IP_GATE_INDEX]];
    RegValue &= ~PCC_PCCn_CGC_MASK;
    RegValue |= PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[Clock_Ip_au8ClockFeatures[CMU1_CLK][CLOCK_IP_GATE_INDEX]] = RegValue;
}
#endif

#if defined(CLOCK_IP_HAS_FIRC_MON1_CLK) || defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
static void Clock_Ip_PllPowerClockIp(void)
{
    #if defined(CLOCK_IP_HAS_FIRC_MON1_CLK)
        #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
            #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call(Clock_Ip_EnableCmu0Gate_TrustedCall);
            #else
    Clock_Ip_EnableCmu0Gate_TrustedCall();
            #endif
        #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    #endif

    #if defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
        #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
            #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call(Clock_Ip_EnableCmu1Gate_TrustedCall);
            #else
    Clock_Ip_EnableCmu1Gate_TrustedCall();
            #endif
        #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    #endif
}
#endif


static void Clock_Ip_SpecificPlatformInitClock(Clock_Ip_ClockConfigType const * Config)
{
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 IrcoscStatus;

    (void)Clock_Ip_FreqIds;
    Clock_Ip_apConfig = Config;

    (void)CLOCK_IP_RUN_POWER_MODE_STATUS;

    /* Clocks cannot be configured while the chip is in other mode than RUN_MODE */
    CLOCK_IP_DEV_ASSERT(CLOCK_IP_RUN_POWER_MODE_STATUS == ((IP_SMC->PMSTAT & SMC_PMSTAT_PMSTAT_MASK) >> SMC_PMSTAT_PMSTAT_SHIFT));

    /* Check whether FIRC is disabled, enable it in this case. */
    if ((IP_SCG->FIRCCSR & SCG_FIRCCSR_FIRCEN_MASK) == 0U)
    {
        Clock_Ip_bFircWasEnabledBeforeMcuInit = FALSE;

    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call(SetFircToResetValue_TrustedCall);
      #else
        SetFircToResetValue_TrustedCall();
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */

        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        /* Wait until ircosc is locked */
        do
        {
            IrcoscStatus = (((IP_SCG->FIRCCSR & SCG_FIRCCSR_FIRCVLD_MASK) >> SCG_FIRCCSR_FIRCVLD_SHIFT));
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while ((IrcoscStatus == 0U) && (FALSE == TimeoutOccurred));

        if (FALSE != TimeoutOccurred)
        {
            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, FIRC_CLK);
        }
    }
    else
    {
        Clock_Ip_bFircWasEnabledBeforeMcuInit = TRUE;
    }


    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
        #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(SetSimLpoclksRegister_TrustedCall,(Config));
        #else
    SetSimLpoclksRegister_TrustedCall(Config);
        #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */

    #if defined(CLOCK_IP_HAS_FIRC_MON1_CLK) || defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
    Clock_Ip_PllPowerClockIp();
    #endif
}

/**
* @brief            This function will get current configuration of FIRC.
*/
static const Clock_Ip_IrcoscConfigType *getFircConfig(void)
{
    uint32 Index;

    const Clock_Ip_IrcoscConfigType *ReturnValue = NULL_PTR;

    if (Clock_Ip_apConfig != NULL_PTR)
    {
        for (Index = 0U; Index < Clock_Ip_apConfig->IrcoscsCount; Index++)
        {
            if (Clock_Ip_apConfig->Ircoscs[Index].Name == FIRC_CLK)
            {
                ReturnValue = &Clock_Ip_apConfig->Ircoscs[Index];
                break;
            }
        }
    }

    /* Element is not under mcu control */
    if (ReturnValue == NULL_PTR)
    {
        ReturnValue = &FircConfiguration;
        FircConfiguration.Name = FIRC_CLK;
        FircConfiguration.Enable = (uint16)(IP_SCG->FIRCCSR & SCG_FIRCCSR_FIRCEN_MASK) >> SCG_FIRCCSR_FIRCEN_SHIFT;
        FircConfiguration.Range = (uint8)(IP_SCG->FIRCCFG & SCG_FIRCCFG_RANGE_MASK) >> SCG_FIRCCFG_RANGE_SHIFT;
        FircConfiguration.Regulator = (uint8)(IP_SCG->FIRCCSR & SCG_FIRCCSR_FIRCREGOFF_MASK) >> SCG_FIRCCSR_FIRCREGOFF_SHIFT;
    }

    return ReturnValue;
}

/**
* @brief            This function will get current configuration of SOSC.
*/
static const Clock_Ip_XoscConfigType *getSoscConfig(void)
{
    uint32 Index;

    const Clock_Ip_XoscConfigType *ReturnValue = NULL_PTR;

    if (Clock_Ip_apConfig != NULL_PTR)
    {
        for (Index = 0U; Index < Clock_Ip_apConfig->XoscsCount; Index++)
        {
            if (Clock_Ip_apConfig->Xoscs[Index].Name == SOSC_CLK)
            {
                ReturnValue = &Clock_Ip_apConfig->Xoscs[Index];
                break;
            }
        }
    }

    /* Element is not under mcu control */
    if (ReturnValue == NULL_PTR)
    {
        ReturnValue = &SoscConfiguration;
        SoscConfiguration.Name = SOSC_CLK;
        SoscConfiguration.Enable = (uint16)(IP_SCG->SOSCCSR & SCG_SOSCCSR_SOSCEN_MASK) >> SCG_SOSCCSR_SOSCEN_SHIFT;
        SoscConfiguration.Freq = CLOCK_IP_DEFAULT_SOSC_FREQUENCY;
    }

    return ReturnValue;
}

#if defined(CLOCK_IP_HAS_SPLL_CLK)
/**
* @brief            This function will get current configuration of SPLL.
*/
static const Clock_Ip_PllConfigType *getSpllConfig(void)
{
    uint32 Index;
    const Clock_Ip_PllConfigType *ReturnValue = NULL_PTR;

    if (Clock_Ip_apConfig != NULL_PTR)
    {
        for (Index = 0U; Index < Clock_Ip_apConfig->PllsCount; Index++)
        {
            if (Clock_Ip_apConfig->Plls[Index].Name == SPLL_CLK)
            {
                ReturnValue = &Clock_Ip_apConfig->Plls[Index];
                break;
            }
        }
    }

    /* Element is not under mcu control */
    if (ReturnValue == NULL_PTR)
    {
        ReturnValue = &SpllConfiguration;
        SpllConfiguration.Name = SPLL_CLK;
        SpllConfiguration.Enable = (uint16)(IP_SCG->SPLLCSR & SCG_SPLLCSR_SPLLEN_MASK) >> SCG_SPLLCSR_SPLLEN_SHIFT;
        SpllConfiguration.Predivider = (uint8)((IP_SCG->SPLLCFG & SCG_SPLLCFG_PREDIV_MASK) >> SCG_SPLLCFG_PREDIV_SHIFT);
        SpllConfiguration.MulFactorDiv = (uint8)((IP_SCG->SPLLCFG & SCG_SPLLCFG_MULT_MASK) >> SCG_SPLLCFG_MULT_SHIFT);
    }

    return ReturnValue;
}
#endif

#if defined(CLOCK_IP_HAS_FIRC_MON1_CLK) || defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
static const Clock_Ip_CmuConfigType *getCmuFircConfig(Clock_Ip_NameType Name)
{
    uint32 Index;
    const Clock_Ip_CmuConfigType *ReturnValue = NULL_PTR;

    if (Clock_Ip_apConfig != NULL_PTR)
    {
        for (Index = 0U; Index < Clock_Ip_apConfig->CmusCount; Index++)
        {
            if (Clock_Ip_apConfig->Cmus[Index].Name == Name)
            {
                ReturnValue = &Clock_Ip_apConfig->Cmus[Index];
                break;
            }
        }
    }

    /* Element is not under mcu control */
    if (ReturnValue == NULL_PTR)
    {
        ReturnValue = &CmuConfiguration;
        CmuConfiguration.Name = Name;
        switch(Name)
        {
            case FIRC_MON1_CLK:
                /* Check enable clock gate for CMU0 */
                if(((IP_PCC->PCCn[62] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT) == 1U)
                {
                    CmuConfiguration.Enable = (Clock_Ip_apxCmu[0U]->GCR & CMU_FC_GCR_FCE_MASK) >> CMU_FC_GCR_FCE_SHIFT;
                }
                break;
            case FIRC_MON2_CLK:
                /* Check enable clock gate for CMU1 */
                if(((IP_PCC->PCCn[63] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT) == 1U)
                {
                    CmuConfiguration.Enable = (Clock_Ip_apxCmu[1U]->GCR & CMU_FC_GCR_FCE_MASK) >> CMU_FC_GCR_FCE_SHIFT;
                }
                break;
            default:
                /* Invalid clock name */
                break;
        }
    }

    return ReturnValue;
}
#endif

static const Clock_Ip_SelectorConfigType *getSelectorConfig(Clock_Ip_NameType Name)
{
    const Clock_Ip_SelectorConfigType *ReturnValue = NULL_PTR;
    uint32 SelectorConfigIndex;
    uint32 Index;

    switch(Name)
    {
        case SCS_RUN_CLK:
            SelectorConfigIndex = 0U;
            break;
        case SCS_VLPR_CLK:
            SelectorConfigIndex = 1U;
            break;
#if defined(CLOCK_IP_HAS_SCS_HSRUN_CLK)
        case SCS_HSRUN_CLK:
            SelectorConfigIndex = 2U;
            break;
#endif
        default:
            SelectorConfigIndex = 0U;
            break;
    }


    if (Clock_Ip_apConfig != NULL_PTR)
    {
        for (Index = 0U; Index < Clock_Ip_apConfig->SelectorsCount; Index++)
        {
            if (Clock_Ip_apConfig->Selectors[Index].Name == Name)
            {
                ReturnValue = &Clock_Ip_apConfig->Selectors[Index];
                break;
            }
        }
    }

    /* Element is not under mcu control */
    if (ReturnValue == NULL_PTR)
    {
        ReturnValue = &SelectorConfigurations[SelectorConfigIndex];
        SelectorConfigurations[SelectorConfigIndex].Name = Name;
        switch(Name)
        {
            case SCS_RUN_CLK:
                SelectorConfigurations[SelectorConfigIndex].Value = ClockSource[(IP_SCG->RCCR & SCG_RCCR_SCS_MASK) >> SCG_RCCR_SCS_SHIFT];
                break;
            case SCS_VLPR_CLK:
                SelectorConfigurations[SelectorConfigIndex].Value = ClockSource[(IP_SCG->VCCR & SCG_VCCR_SCS_MASK) >> SCG_VCCR_SCS_SHIFT];
                break;
#if defined(CLOCK_IP_HAS_SCS_HSRUN_CLK)
            case SCS_HSRUN_CLK:
                SelectorConfigurations[SelectorConfigIndex].Value = ClockSource[(IP_SCG->HCCR & SCG_HCCR_SCS_MASK) >> SCG_HCCR_SCS_SHIFT];
                break;
#endif
            default:
                /* Invalid clock name */
                break;
        }
    }

    return ReturnValue;
}

static const Clock_Ip_DividerConfigType *getCoreDividerConfig(Clock_Ip_NameType Name)
{
    const Clock_Ip_DividerConfigType *ReturnValue = NULL_PTR;
    uint32 DividerConfigIndex = 0U;
    uint32 Index;

    switch(Name)
    {
        case CORE_RUN_CLK:
            DividerConfigIndex = 0U;
            break;
        case CORE_VLPR_CLK:
            DividerConfigIndex = 1U;
            break;
#if defined(CLOCK_IP_HAS_CORE_HSRUN_CLK)
        case CORE_HSRUN_CLK:
            DividerConfigIndex = 2U;
            break;
#endif
            default:
                /* Invalid clock name */
                break;
    }


    if (Clock_Ip_apConfig != NULL_PTR)
    {
        for (Index = 0U; Index < Clock_Ip_apConfig->DividersCount; Index++)
        {
            if (Clock_Ip_apConfig->Dividers[Index].Name == Name)
            {
                ReturnValue = &Clock_Ip_apConfig->Dividers[Index];
                break;
            }
        }
    }

    /* Element is not under mcu control */
    if (ReturnValue == NULL_PTR)
    {
        ReturnValue = &CoreDividerConfigurations[DividerConfigIndex];
        CoreDividerConfigurations[DividerConfigIndex].Name = Name;
        switch(Name)
        {
            case CORE_RUN_CLK:
                CoreDividerConfigurations[DividerConfigIndex].Value = ((IP_SCG->RCCR & SCG_RCCR_DIVCORE_MASK) >> SCG_RCCR_DIVCORE_SHIFT) + 1U;
                break;
            case CORE_VLPR_CLK:
                CoreDividerConfigurations[DividerConfigIndex].Value = ((IP_SCG->VCCR & SCG_VCCR_DIVCORE_MASK) >> SCG_VCCR_DIVCORE_SHIFT) + 1U;
                break;
#if defined(CLOCK_IP_HAS_CORE_HSRUN_CLK)
            case CORE_HSRUN_CLK:
                CoreDividerConfigurations[DividerConfigIndex].Value = ((IP_SCG->HCCR & SCG_HCCR_DIVCORE_MASK) >> SCG_HCCR_DIVCORE_SHIFT) + 1U;
                break;
#endif
            default:
                /* Invalid clock name */
                break;
        }
    }

    return ReturnValue;
}


static const Clock_Ip_DividerConfigType *getBusDividerConfig(Clock_Ip_NameType Name)
{
    const Clock_Ip_DividerConfigType *ReturnValue = NULL_PTR;
    uint32 DividerConfigIndex = 0U;
    uint32 Index;

    switch(Name)
    {
        case BUS_RUN_CLK:
            DividerConfigIndex = 0U;
            break;
        case BUS_VLPR_CLK:
            DividerConfigIndex = 1U;
            break;
#if defined(CLOCK_IP_HAS_BUS_HSRUN_CLK)
        case BUS_HSRUN_CLK:
            DividerConfigIndex = 2U;
            break;
#endif
            default:
                /* Invalid clock name */
                break;

    }


    if (Clock_Ip_apConfig != NULL_PTR)
    {
        for (Index = 0U; Index < Clock_Ip_apConfig->DividersCount; Index++)
        {
            if (Clock_Ip_apConfig->Dividers[Index].Name == Name)
            {
                ReturnValue = &Clock_Ip_apConfig->Dividers[Index];
                break;
            }
        }
    }

    /* Element is not under mcu control */
    if (ReturnValue == NULL_PTR)
    {
        ReturnValue = &BusDividerConfigurations[DividerConfigIndex];
        BusDividerConfigurations[DividerConfigIndex].Name = Name;
        switch(Name)
        {
            case BUS_RUN_CLK:
                BusDividerConfigurations[DividerConfigIndex].Value = ((IP_SCG->RCCR & SCG_RCCR_DIVBUS_MASK) >> SCG_RCCR_DIVBUS_SHIFT) + 1U;
                break;
            case BUS_VLPR_CLK:
                BusDividerConfigurations[DividerConfigIndex].Value = ((IP_SCG->VCCR & SCG_VCCR_DIVBUS_MASK) >> SCG_VCCR_DIVBUS_SHIFT) + 1U;
                break;
#if defined(CLOCK_IP_HAS_BUS_HSRUN_CLK)
            case BUS_HSRUN_CLK:
                BusDividerConfigurations[DividerConfigIndex].Value = ((IP_SCG->HCCR & SCG_HCCR_DIVBUS_MASK) >> SCG_HCCR_DIVBUS_SHIFT) + 1U;
                break;
#endif
            default:
                /* Invalid clock name */
                break;
        }
    }

    return ReturnValue;
}

static const Clock_Ip_DividerConfigType *getSlowDividerConfig(Clock_Ip_NameType Name)
{
    const Clock_Ip_DividerConfigType *ReturnValue = NULL_PTR;
    uint32 DividerConfigIndex = 0U;
    uint32 Index;

    switch(Name)
    {
        case SLOW_RUN_CLK:
            DividerConfigIndex = 0U;
            break;
        case SLOW_VLPR_CLK:
            DividerConfigIndex = 1U;
            break;
#if defined(CLOCK_IP_HAS_SLOW_HSRUN_CLK)
        case SLOW_HSRUN_CLK:
            DividerConfigIndex = 2U;
            break;
#endif
            default:
                /* Invalid clock name */
                break;

    }


    if (Clock_Ip_apConfig != NULL_PTR)
    {
        for (Index = 0U; Index < Clock_Ip_apConfig->DividersCount; Index++)
        {
            if (Clock_Ip_apConfig->Dividers[Index].Name == Name)
            {
                ReturnValue = &Clock_Ip_apConfig->Dividers[Index];
                break;
            }
        }
    }

    /* Element is not under mcu control */
    if (ReturnValue == NULL_PTR)
    {
        ReturnValue = &SlowDividerConfigurations[DividerConfigIndex];
        SlowDividerConfigurations[DividerConfigIndex].Name = Name;
        switch(Name)
        {
            case SLOW_RUN_CLK:
                SlowDividerConfigurations[DividerConfigIndex].Value = ((IP_SCG->RCCR & SCG_RCCR_DIVSLOW_MASK) >> SCG_RCCR_DIVSLOW_SHIFT) + 1U;
                break;
            case SLOW_VLPR_CLK:
                SlowDividerConfigurations[DividerConfigIndex].Value = ((IP_SCG->VCCR & SCG_VCCR_DIVSLOW_MASK) >> SCG_VCCR_DIVSLOW_SHIFT) + 1U;
                break;
#if defined(CLOCK_IP_HAS_SLOW_HSRUN_CLK)
            case SLOW_HSRUN_CLK:
                SlowDividerConfigurations[DividerConfigIndex].Value = ((IP_SCG->HCCR & SCG_HCCR_DIVSLOW_MASK) >> SCG_HCCR_DIVSLOW_SHIFT) + 1U;
                break;
#endif
            default:
                /* Invalid clock name */
                break;
        }
    }

    return ReturnValue;
}

/* Initialize objects for clock */
static void Clock_Ip_ClockInitializeObjects(Clock_Ip_ClockConfigType const * Config)
{
    if (FALSE == Clock_Ip_bObjsAreInitialized)
    {
        Clock_Ip_bObjsAreInitialized = TRUE;

    #if defined(CLOCK_IP_HAS_SPLL_CLK)
        Clock_Ip_pxSpllClock = &Clock_Ip_axPllCallbacks[Clock_Ip_au8PllCallbackIndex[CLOCK_IP_SYS_PLL]];
    #endif

        Clock_Ip_pxSoscClock = &Clock_Ip_axExtOscCallbacks[Clock_Ip_au8XoscCallbackIndex[CLOCK_IP_SYS_OSC]];

        Clock_Ip_pxFircClock = &Clock_Ip_axIntOscCallbacks[Clock_Ip_au8IrcoscCallbackIndex[CLOCK_IP_FIRCOSC]];

    #if defined(CLOCK_IP_HAS_FIRC_MON1_CLK) || defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
        Clock_Ip_pxCmuFircMonitor = &Clock_Ip_axCmuCallbacks[Clock_Ip_au8CmuCallbackIndex[CLOCK_IP_CMU]];
    #endif

        Clock_Ip_pxScsRunClockSelector   = &Clock_Ip_axSelectorCallbacks[Clock_Ip_au8SelectorCallbackIndex[CLOCK_IP_SCS_RUN]];
    #if defined(CLOCK_IP_HAS_SCS_HSRUN_CLK)
        Clock_Ip_pxScsHsrunClockSelector = &Clock_Ip_axSelectorCallbacks[Clock_Ip_au8SelectorCallbackIndex[CLOCK_IP_SCS_HSRUN]];
    #endif

        Clock_Ip_pxCoreRunClockDivider = &Clock_Ip_axDividerCallbacks[Clock_Ip_au8DividerCallbackIndex[CLOCK_IP_DIVCORE_RUN]];
    #if defined(CLOCK_IP_HAS_CORE_HSRUN_CLK)
        Clock_Ip_pxCoreHsrunClockDivider = &Clock_Ip_axDividerCallbacks[Clock_Ip_au8DividerCallbackIndex[CLOCK_IP_DIVCORE_HSRUN]];
    #endif

        Clock_Ip_pxBusRunClockDivider = &Clock_Ip_axDividerCallbacks[Clock_Ip_au8DividerCallbackIndex[CLOCK_IP_DIVBUS_RUN]];
    #if defined(CLOCK_IP_HAS_BUS_HSRUN_CLK)
        Clock_Ip_pxBusHsrunClockDivider = &Clock_Ip_axDividerCallbacks[Clock_Ip_au8DividerCallbackIndex[CLOCK_IP_DIVBUS_HSRUN]];
    #endif

        Clock_Ip_pxSlowRunClockDivider = &Clock_Ip_axDividerCallbacks[Clock_Ip_au8DividerCallbackIndex[CLOCK_IP_DIVSLOW_RUN]];
    #if defined(CLOCK_IP_HAS_SLOW_HSRUN_CLK)
        Clock_Ip_pxSlowHsrunClockDivider = &Clock_Ip_axDividerCallbacks[Clock_Ip_au8DividerCallbackIndex[CLOCK_IP_DIVSLOW_HSRUN]];
    #endif
    }

    if( ((TRUE == Clock_Ip_bAcceptedCopyClockConfiguration) && (Config == NULL_PTR)) || (Clock_Ip_bSentFromUpdateDriverContext ==TRUE) )
    {
        Clock_Ip_pxFircConfig = getFircConfig();
        Clock_Ip_pxSoscConfig = getSoscConfig();
    #if defined(CLOCK_IP_HAS_SPLL_CLK)
        Clock_Ip_pxSpllConfig = getSpllConfig();
    #endif

    #if defined(CLOCK_IP_HAS_FIRC_MON1_CLK)
        Clock_Ip_pxCmuFircMon1Config = getCmuFircConfig(FIRC_MON1_CLK);
    #endif
    #if defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
        Clock_Ip_pxCmuFircMon2Config = getCmuFircConfig(FIRC_MON2_CLK);
    #endif

        Clock_Ip_pxScsConfigRunMode = getSelectorConfig(SCS_RUN_CLK);
        Clock_Ip_pxScsConfigVlprMode = getSelectorConfig(SCS_VLPR_CLK);
    #if defined(CLOCK_IP_HAS_SCS_HSRUN_CLK)
        Clock_Ip_pxScsConfigHsrunMode = getSelectorConfig(SCS_HSRUN_CLK);
    #endif

        Clock_Ip_pxCoreConfigRunMode = getCoreDividerConfig(CORE_RUN_CLK);
        Clock_Ip_pxCoreConfigVlprMode = getCoreDividerConfig(CORE_VLPR_CLK);
    #if defined(CLOCK_IP_HAS_CORE_HSRUN_CLK)
        Clock_Ip_pxCoreConfigHsrunMode = getCoreDividerConfig(CORE_HSRUN_CLK);
    #endif

        Clock_Ip_pxBusConfigRunMode = getBusDividerConfig(BUS_RUN_CLK);
        Clock_Ip_pxBusConfigVlprMode = getBusDividerConfig(BUS_VLPR_CLK);
    #if defined(CLOCK_IP_HAS_BUS_HSRUN_CLK)
        Clock_Ip_pxBusConfigHsrunMode = getBusDividerConfig(BUS_HSRUN_CLK);
    #endif

        Clock_Ip_pxSlowConfigRunMode = getSlowDividerConfig(SLOW_RUN_CLK);
        Clock_Ip_pxSlowConfigVlprMode = getSlowDividerConfig(SLOW_VLPR_CLK);
    #if defined(CLOCK_IP_HAS_SLOW_HSRUN_CLK)
        Clock_Ip_pxSlowConfigHsrunMode = getSlowDividerConfig(SLOW_HSRUN_CLK);
    #endif
    }

}


void Clock_Ip_ClockPowerModeChangeNotification(Clock_Ip_PowerModesType PowerMode, Clock_Ip_PowerNotificationType Notification)
{
    switch(PowerMode)
    {
        case VLPR_MODE:
        case VLPS_MODE:
        {
            if(BEFORE_POWER_MODE_CHANGE == Notification)
            {
                Clock_Ip_bAcceptedCopyClockConfiguration = FALSE;

                /* Disable all cmus */
#if defined(CLOCK_IP_HAS_FIRC_MON1_CLK)
                /* Check enable clock gate for CMU0 */
                if(((IP_PCC->PCCn[62] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT) == 1U)
                {
                    Clock_Ip_pxCmuFircMonitor->Disable(FIRC_MON1_CLK);
                }
#endif
#if defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
                /* Check enable clock gate for CMU1 */
                if(((IP_PCC->PCCn[63] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT) == 1U)
                {
                    Clock_Ip_pxCmuFircMonitor->Disable(FIRC_MON2_CLK);
                }
#endif

                /* Load system clock settings for VLPR mode */
                Clock_Ip_pxScsRunClockSelector->Set(Clock_Ip_pxScsConfigVlprMode);
                Clock_Ip_pxCoreRunClockDivider->Set(Clock_Ip_pxCoreConfigVlprMode);
                Clock_Ip_pxBusRunClockDivider->Set(Clock_Ip_pxBusConfigVlprMode);
                Clock_Ip_pxSlowRunClockDivider->Set(Clock_Ip_pxSlowConfigVlprMode);

                /* Disable all clock sources except SIRC */
#if defined(CLOCK_IP_HAS_SPLL_CLK)
                Clock_Ip_pxSpllClock->Disable(Clock_Ip_pxSpllConfig->Name);
#endif
                Clock_Ip_pxSoscClock->Disable(Clock_Ip_pxSoscConfig->Name);
                Clock_Ip_pxFircClock->Disable(Clock_Ip_pxFircConfig->Name);
            }
        }
        break;

        case RUN_MODE:
        {
            if(POWER_MODE_CHANGED == Notification)
            {
                Clock_Ip_bAcceptedCopyClockConfiguration = TRUE;
                /* Restore clock source settings */
                Clock_Ip_pxFircClock->Enable(Clock_Ip_pxFircConfig);

                Clock_Ip_pxSoscClock->Enable(Clock_Ip_pxSoscConfig);                 /* Enable */
                Clock_Ip_pxSoscClock->Complete(Clock_Ip_pxSoscConfig);               /* Wait to lock */

#if defined(CLOCK_IP_HAS_SPLL_CLK)
                Clock_Ip_pxSpllClock->Enable(Clock_Ip_pxSpllConfig);                 /* Enable */
                (void)(Clock_Ip_pxSpllClock->Complete(Clock_Ip_pxSpllConfig->Name));         /* Wait to lock */
#endif

                /* Restore system clock settings */
                Clock_Ip_pxScsRunClockSelector->Set(Clock_Ip_pxScsConfigRunMode);
                Clock_Ip_pxCoreRunClockDivider->Set(Clock_Ip_pxCoreConfigRunMode);
                Clock_Ip_pxBusRunClockDivider->Set(Clock_Ip_pxBusConfigRunMode);
                Clock_Ip_pxSlowRunClockDivider->Set(Clock_Ip_pxSlowConfigRunMode);

                /* Restore all cmus */
#if defined(CLOCK_IP_HAS_FIRC_MON1_CLK)
                /* Check enable clock gate for CMU0 */
                if(((IP_PCC->PCCn[62] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT) == 1U)
                {
                    Clock_Ip_pxCmuFircMonitor->Enable(Clock_Ip_pxCmuFircMon1Config);
                }
#endif
#if defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
                /* Check enable clock gate for CMU1 */
                if(((IP_PCC->PCCn[63] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT) == 1U)
                {
                    Clock_Ip_pxCmuFircMonitor->Enable(Clock_Ip_pxCmuFircMon2Config);
                }
#endif
            }
        }
        break;

        case HSRUN_MODE:
        {
            if(POWER_MODE_CHANGED == Notification)
            {
                Clock_Ip_bAcceptedCopyClockConfiguration = TRUE;
                /* Restore clock source settings */
                Clock_Ip_pxFircClock->Enable(Clock_Ip_pxFircConfig);

                Clock_Ip_pxSoscClock->Enable(Clock_Ip_pxSoscConfig);                 /* Enable */
                Clock_Ip_pxSoscClock->Complete(Clock_Ip_pxSoscConfig);               /* Wait to lock */

#if defined(CLOCK_IP_HAS_SPLL_CLK)
                Clock_Ip_pxSpllClock->Enable(Clock_Ip_pxSpllConfig);                 /* Enable */
                (void)(Clock_Ip_pxSpllClock->Complete(Clock_Ip_pxSpllConfig->Name));         /* Wait to lock */
#endif

                /* Restore system clock settings */
#if defined(CLOCK_IP_HAS_SCS_HSRUN_CLK)
                Clock_Ip_pxScsHsrunClockSelector->Set(Clock_Ip_pxScsConfigHsrunMode);
#endif
#if defined(CLOCK_IP_HAS_CORE_HSRUN_CLK)
                Clock_Ip_pxCoreHsrunClockDivider->Set(Clock_Ip_pxCoreConfigHsrunMode);
#endif
#if defined(CLOCK_IP_HAS_BUS_HSRUN_CLK)
                Clock_Ip_pxBusHsrunClockDivider->Set(Clock_Ip_pxBusConfigHsrunMode);
#endif
#if defined(CLOCK_IP_HAS_SLOW_HSRUN_CLK)
                Clock_Ip_pxSlowHsrunClockDivider->Set(Clock_Ip_pxSlowConfigHsrunMode);
#endif

                /* Restore all cmus */
#if defined(CLOCK_IP_HAS_FIRC_MON1_CLK)
                /* Check enable clock gate for CMU0 */
                if(((IP_PCC->PCCn[62] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT) == 1U)
                {
                    Clock_Ip_pxCmuFircMonitor->Enable(Clock_Ip_pxCmuFircMon1Config);
                }
#endif
#if defined(CLOCK_IP_HAS_FIRC_MON2_CLK)
                /* Check enable clock gate for CMU1 */
                if(((IP_PCC->PCCn[63] & PCC_PCCn_CGC_MASK) >> PCC_PCCn_CGC_SHIFT) == 1U)
                {
                    Clock_Ip_pxCmuFircMonitor->Enable(Clock_Ip_pxCmuFircMon2Config);
                }
#endif
            }
        }
        break;

        default:
        {
            /* Invalid power mode */
        }
        break;
    }

}


void Clock_Ip_Command(Clock_Ip_ClockConfigType const * Config, Clock_Ip_CommandType Command)
{
    switch(Command)
    {
        case CLOCK_IP_INITIALIZE_CLOCK_OBJECTS_COMMAND:
            Clock_Ip_ClockInitializeObjects(Config);
            break;
        case CLOCK_IP_INITIALIZE_PLATFORM_COMMAND:
            Clock_Ip_SpecificPlatformInitClock(Config);
            break;
        case CLOCK_IP_DISABLE_SAFE_CLOCK_COMMAND:
            DisableSafeClock(Config);
            break;
        default:
            /* Command is not implemented on this platform */
            break;
    }
}

/* Clock stop section code */
#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

