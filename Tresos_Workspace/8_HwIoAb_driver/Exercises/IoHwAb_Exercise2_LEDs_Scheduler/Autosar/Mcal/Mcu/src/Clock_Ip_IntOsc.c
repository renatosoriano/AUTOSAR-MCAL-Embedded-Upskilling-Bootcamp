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
*   @file       Clock_Ip_IntOsc.c
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

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CLOCK_IP_INTOSC_VENDOR_ID_C                      43
#define CLOCK_IP_INTOSC_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_INTOSC_AR_RELEASE_MINOR_VERSION_C       7
#define CLOCK_IP_INTOSC_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_INTOSC_SW_MAJOR_VERSION_C               2
#define CLOCK_IP_INTOSC_SW_MINOR_VERSION_C               0
#define CLOCK_IP_INTOSC_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_IntOsc.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_INTOSC_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_IntOsc.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_IntOsc.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_INTOSC_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_INTOSC_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_INTOSC_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_IntOsc.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_IntOsc.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_INTOSC_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_INTOSC_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_INTOSC_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_IntOsc.c and Clock_Ip_Private.h are different"
#endif

/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"
#ifdef CLOCK_IP_SIRC_ENABLE
void Clock_Ip_SetSirc_TrustedCall(Clock_Ip_IrcoscConfigType const* Config);
void Clock_Ip_EnableSirc_TrustedCall(Clock_Ip_IrcoscConfigType const* Config);
void Clock_Ip_DisableSirc_TrustedCall(Clock_Ip_NameType Name);
#endif

#ifdef CLOCK_IP_SIRC_VLP_ENABLE
void Clock_Ip_SetSircVlp_TrustedCall(Clock_Ip_IrcoscConfigType const* Config);
void Clock_Ip_EnableSircVlp_TrustedCall(Clock_Ip_IrcoscConfigType const* Config);
void Clock_Ip_DisableSircVlp_TrustedCall(Clock_Ip_NameType Name);
#endif

#ifdef CLOCK_IP_SIRC_STOP_ENABLE
void Clock_Ip_SetSircStop_TrustedCall(Clock_Ip_IrcoscConfigType const* Config);
void Clock_Ip_EnableSircStop_TrustedCall(Clock_Ip_IrcoscConfigType const* Config);
void Clock_Ip_DisableSircStop_TrustedCall(Clock_Ip_NameType Name);
#endif

#ifdef CLOCK_IP_FIRC_ENABLE
void Clock_Ip_SetFirc_TrustedCall(Clock_Ip_IrcoscConfigType const* Config);
void Clock_Ip_EnableFirc_TrustedCall(Clock_Ip_IrcoscConfigType const* Config);
void Clock_Ip_DisableFirc_TrustedCall(Clock_Ip_NameType Name);
#endif

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

static void Clock_Ip_InternalOscillatorEmpty(Clock_Ip_IrcoscConfigType const* Config);
static void Clock_Ip_InternalOscillatorEmpty_Disable(Clock_Ip_NameType Name);
#ifdef CLOCK_IP_FIRC_DIV_SEL_HSEb_CONFIG_REG_GPR
static void Clock_Ip_SetFircDivSelHSEb(Clock_Ip_IrcoscConfigType const* Config);
#endif
#ifdef CLOCK_IP_SIRC_ENABLE
static void Clock_Ip_SetSirc(Clock_Ip_IrcoscConfigType const* Config);
static void Clock_Ip_EnableSirc(Clock_Ip_IrcoscConfigType const* Config);
static void Clock_Ip_DisableSirc(Clock_Ip_NameType Name);
#endif
#ifdef CLOCK_IP_SIRC_VLP_ENABLE
static void Clock_Ip_SetSircVlp(Clock_Ip_IrcoscConfigType const* Config);
static void Clock_Ip_EnableSircVlp(Clock_Ip_IrcoscConfigType const* Config);
static void Clock_Ip_DisableSircVlp(Clock_Ip_NameType Name);
#endif
#ifdef CLOCK_IP_SIRC_STOP_ENABLE
static void Clock_Ip_SetSircStop(Clock_Ip_IrcoscConfigType const* Config);
static void Clock_Ip_EnableSircStop(Clock_Ip_IrcoscConfigType const* Config);
static void Clock_Ip_DisableSircStop(Clock_Ip_NameType Name);
#endif
#ifdef CLOCK_IP_FIRC_ENABLE
static void Clock_Ip_SetFirc(Clock_Ip_IrcoscConfigType const* Config);
static void Clock_Ip_EnableFirc(Clock_Ip_IrcoscConfigType const* Config);
static void Clock_Ip_DisableFirc(Clock_Ip_NameType Name);
#endif
/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

static void Clock_Ip_InternalOscillatorEmpty(Clock_Ip_IrcoscConfigType const* Config)
{
    (void)Config;
    /* No implementation */
}
static void Clock_Ip_InternalOscillatorEmpty_Disable(Clock_Ip_NameType Name)
{
    (void)Name;
    /* No implementation */
}


#ifdef CLOCK_IP_FIRC_DIV_SEL_HSEb_CONFIG_REG_GPR
#define CLOCK_IP_WFI_EXECUTED MC_ME_PRTN0_CORE2_STAT_WFI_MASK
#define CLOCK_IP_APP_CAN_WRITE 5U
/* Set Firc Div Sel */
static void Clock_Ip_SetFircDivSelHSEb(Clock_Ip_IrcoscConfigType const* Config)
{
    uint32 RegValue;
    uint32 DividerValue = 0U;

    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 WfiStatus;

    if (NULL_PTR != Config)
    {
        switch(Config->Range)
        {
            case CLOCK_IP_SUPPORTS_48MHZ_FREQUENCY:
                DividerValue = 3U;
                break;
            case CLOCK_IP_SUPPORTS_24MHZ_FREQUENCY:
                DividerValue = 1U;
                break;
            case CLOCK_IP_SUPPORTS_3MHZ_FREQUENCY:
                DividerValue = 2U;
                break;
            default:
                /* No option in hardware for this value */
                break;
        }

        /* If divider value option from configuration is valid */
        if (DividerValue != 0U)
        {
            /* Application can write this divider */
            if ( ((IP_CONFIGURATION_GPR->CONFIG_REG_GPR & CONFIGURATION_GPR_CONFIG_REG_GPR_APP_CORE_ACC_MASK)>>CONFIGURATION_GPR_CONFIG_REG_GPR_APP_CORE_ACC_SHIFT) == CLOCK_IP_APP_CAN_WRITE)
            {
                /* Before access to CONFIG_REG_GPR register, driver should wait for Secure BAF to go in WFI
                   by reading register PRTN0_CORE2_STAT. Wfi status will be checked. */
                Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
                /* Wait for acknowledge to be cleared. */
                do
                {
                    WfiStatus = (IP_MC_ME->PRTN0_CORE2_STAT & MC_ME_PRTN0_CORE2_STAT_WFI_MASK);
                    TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
                }
                while ((CLOCK_IP_WFI_EXECUTED != WfiStatus) && (FALSE == TimeoutOccurred));

                if (FALSE == TimeoutOccurred)
                {
                    RegValue = IP_CONFIGURATION_GPR->CONFIG_REG_GPR;
                    RegValue &= ~CONFIGURATION_GPR_CONFIG_REG_GPR_FIRC_DIV_SEL_MASK;
                    RegValue |= CONFIGURATION_GPR_CONFIG_REG_GPR_FIRC_DIV_SEL(DividerValue);
                    IP_CONFIGURATION_GPR->CONFIG_REG_GPR = RegValue;
                }
                else
                {
                    Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Config->Name);
                }
            }
            else
            {
                /* HSE firmware doesn't allow to write FIRC post divider. Firc range cannot be set as it's configured. */
                Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_WRITE_PROTECTION_ERROR, Config->Name);
            }
        }
    }
    else
    {
        (void)RegValue;
        (void)DividerValue;
        (void)TimeoutOccurred;
        (void)StartTime;
        (void)ElapsedTime;
        (void)TimeoutTicks;
        (void)WfiStatus;
    }
}
#endif

#ifdef CLOCK_IP_SIRC_ENABLE
static void Clock_Ip_SetSirc(Clock_Ip_IrcoscConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetSirc_TrustedCall,(Config));
      #else
        Clock_Ip_SetSirc_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_EnableSirc(Clock_Ip_IrcoscConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_EnableSirc_TrustedCall,(Config));
      #else
        Clock_Ip_EnableSirc_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_DisableSirc(Clock_Ip_NameType Name)
{
#ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(Clock_Ip_DisableSirc_TrustedCall,(Name));
  #else
    Clock_Ip_DisableSirc_TrustedCall(Name);
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
}
#endif

#ifdef CLOCK_IP_SIRC_VLP_ENABLE
static void Clock_Ip_SetSircVlp(Clock_Ip_IrcoscConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetSircVlp_TrustedCall,(Config));
      #else
        Clock_Ip_SetSircVlp_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_EnableSircVlp(Clock_Ip_IrcoscConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_EnableSircVlp_TrustedCall,(Config));
      #else
        Clock_Ip_EnableSircVlp_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_DisableSircVlp(Clock_Ip_NameType Name)
{
#ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(Clock_Ip_DisableSircVlp_TrustedCall,(Name));
  #else
    Clock_Ip_DisableSircVlp_TrustedCall(Name);
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
}
#endif

#ifdef CLOCK_IP_SIRC_STOP_ENABLE
static void Clock_Ip_SetSircStop(Clock_Ip_IrcoscConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetSircStop_TrustedCall,(Config));
      #else
        Clock_Ip_SetSircStop_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_EnableSircStop(Clock_Ip_IrcoscConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_EnableSircStop_TrustedCall,(Config));
      #else
        Clock_Ip_EnableSircStop_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_DisableSircStop(Clock_Ip_NameType Name)
{
#ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(Clock_Ip_DisableSircStop_TrustedCall,(Name));
  #else
    Clock_Ip_DisableSircStop_TrustedCall(Name);
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
}
#endif

#ifdef CLOCK_IP_FIRC_ENABLE
#define CLOCK_IP_SIRC_CLK_SOURCE 2U
#define CLOCK_IP_FIRC_CLK_SOURCE 3U
static void SetInputSouceSytemClock(uint32 SourceClock)
{
    uint32 RegValue;
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 ScsStatus;

    RegValue = IP_SCG->RCCR;
    RegValue &= ~SCG_RCCR_SCS_MASK;
    RegValue |= (SourceClock << SCG_RCCR_SCS_SHIFT);
    IP_SCG->RCCR = RegValue;

    Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
    do
    {
        ScsStatus = (((IP_SCG->CSR & SCG_CSR_SCS_MASK) >> SCG_CSR_SCS_SHIFT) != (SourceClock))?0U:1U;
        TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
    }
    while ((0U == ScsStatus) && (FALSE == TimeoutOccurred));

    if (FALSE != TimeoutOccurred)
    {
        /* Report timeout error */
        Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, FIRC_CLK);
    }
}
static void Clock_Ip_SetFirc(Clock_Ip_IrcoscConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetFirc_TrustedCall,(Config));
      #else
        Clock_Ip_SetFirc_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_EnableFirc(Clock_Ip_IrcoscConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_EnableFirc_TrustedCall,(Config));
      #else
        Clock_Ip_EnableFirc_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_DisableFirc(Clock_Ip_NameType Name)
{
#ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(Clock_Ip_DisableFirc_TrustedCall,(Name));
  #else
    Clock_Ip_DisableFirc_TrustedCall(Name);
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
}
#endif



/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef CLOCK_IP_SIRC_ENABLE
void Clock_Ip_SetSirc_TrustedCall(Clock_Ip_IrcoscConfigType const* Config)
{
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 IrcoscStatus;
    Clock_Ip_IrcoscConfigType SircConfig;

    if (NULL_PTR == Config)
    {
        SircConfig.Name   = FIRC_CLK;
        SircConfig.Range  = 1U;   /* 8MHz */
        SircConfig.Enable = 1U;   /* enabled */
        SircConfig.LowPowerModeEnable =1U;
    }
    else
    {
        SircConfig.Name   = Config->Name;
        SircConfig.Range  = Config->Range;
        SircConfig.Enable = Config->Enable;
        SircConfig.LowPowerModeEnable = Config->LowPowerModeEnable;
    }

    /* Clear LK bit field */
    IP_SCG->SIRCCSR &= (~((uint32)SCG_SIRCCSR_LK_MASK));

    /* Disable clock */
    IP_SCG->SIRCCSR &= (~((uint32)SCG_SIRCCSR_SIRCEN_MASK));

    /* Disable SIRC Low Power */
    IP_SCG->SIRCCSR &= (~((uint32)SCG_SIRCCSR_SIRCLPEN_MASK));

    /* Configure SIRC. */
    if (1U == SircConfig.Enable)
    {
        /* Step frequency range. */
        IP_SCG->SIRCCFG = SCG_SIRCCFG_RANGE(SircConfig.Range);

        /* Enable clock. */
        IP_SCG->SIRCCSR |= SCG_SIRCCSR_SIRCEN(1U);

        /* Set SIRC in VLP modes */
        IP_SCG->SIRCCSR |= SCG_SIRCCSR_SIRCLPEN(SircConfig.LowPowerModeEnable);

        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        /* Wait until ircosc is locked */
        do
        {
            IrcoscStatus = (((IP_SCG->SIRCCSR & SCG_SIRCCSR_SIRCVLD_MASK) >> SCG_SIRCCSR_SIRCVLD_SHIFT));
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while ((0U == IrcoscStatus) && (FALSE == TimeoutOccurred));

        if (FALSE != TimeoutOccurred)
        {
            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, SircConfig.Name);
        }
    }
}
void Clock_Ip_EnableSirc_TrustedCall(Clock_Ip_IrcoscConfigType const* Config)
{
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 IrcoscStatus;

    /* Enable clock. */
    IP_SCG->SIRCCSR |= SCG_SIRCCSR_SIRCEN(1U);

    /* Enable SIRC Low Power */
    IP_SCG->SIRCCSR |= SCG_SIRCCSR_SIRCLPEN(1UL);

    Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
    /* Wait until ircosc is locked */
    do
    {
        IrcoscStatus = (((IP_SCG->SIRCCSR & SCG_SIRCCSR_SIRCVLD_MASK) >> SCG_SIRCCSR_SIRCVLD_SHIFT));
        TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
    }
    while ((0U == IrcoscStatus) && (FALSE == TimeoutOccurred));

    if (FALSE != TimeoutOccurred)
    {
        /* Report timeout error */
        Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Config->Name);
    }
}
void Clock_Ip_DisableSirc_TrustedCall(Clock_Ip_NameType Name)
{
    (void)Name;

    /* Disable clock. */
    IP_SCG->SIRCCSR &= ~SCG_SIRCCSR_SIRCEN_MASK;

    /* Disable SIRC Low Power */
    IP_SCG->SIRCCSR &= (~((uint32)SCG_SIRCCSR_SIRCLPEN_MASK));
}
#endif

#ifdef CLOCK_IP_SIRC_VLP_ENABLE
void Clock_Ip_SetSircVlp_TrustedCall(Clock_Ip_IrcoscConfigType const* Config)
{
    /* Clear LK bit field */
    IP_SCG->SIRCCSR &= (~((uint32)SCG_SIRCCSR_LK_MASK));

    IP_SCG->SIRCCSR &= (~((uint32)SCG_SIRCCSR_SIRCLPEN_MASK));

    /* Configure SIRC in VLP mode */
    IP_SCG->SIRCCSR |= SCG_SIRCCSR_SIRCLPEN(Config->LowPowerModeEnable);
}
void Clock_Ip_EnableSircVlp_TrustedCall(Clock_Ip_IrcoscConfigType const* Config)
{
    if (1U == Config->Enable)
    {
        /* Enable clock in VLP mode */
        IP_SCG->SIRCCSR |= SCG_SIRCCSR_SIRCLPEN(1U);
    }
}
void Clock_Ip_DisableSircVlp_TrustedCall(Clock_Ip_NameType Name)
{
    (void)Name;

    /* Disable clock */
    IP_SCG->SIRCCSR &= (~((uint32)SCG_SIRCCSR_SIRCLPEN_MASK));
}
#endif

#ifdef CLOCK_IP_SIRC_STOP_ENABLE
void Clock_Ip_SetSircStop_TrustedCall(Clock_Ip_IrcoscConfigType const* Config)
{
    (void)Config;

    /* Clear LK bit field */
    IP_SCG->SIRCCSR &= (~((uint32)SCG_SIRCCSR_LK_MASK));

    IP_SCG->SIRCCSR &= (~((uint32)SCG_SIRCCSR_SIRCSTEN_MASK));

    /* Configure SIRC in STOP mode */
    IP_SCG->SIRCCSR |= SCG_SIRCCSR_SIRCSTEN(Config->StopModeEnable);
}
void Clock_Ip_EnableSircStop_TrustedCall(Clock_Ip_IrcoscConfigType const* Config)
{
    if (1U == Config->Enable)
    {
        /* Enable clock in VLP mode */
        IP_SCG->SIRCCSR |= SCG_SIRCCSR_SIRCSTEN(1U);
    }
}
void Clock_Ip_DisableSircStop_TrustedCall(Clock_Ip_NameType Name)
{
    (void)Name;

    /* Disable clock */
    IP_SCG->SIRCCSR &= (~((uint32)SCG_SIRCCSR_SIRCSTEN_MASK));
}
#endif

#ifdef CLOCK_IP_FIRC_ENABLE
void Clock_Ip_SetFirc_TrustedCall(Clock_Ip_IrcoscConfigType const* Config)
{
    uint32 Instance = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_MODULE_INSTANCE];
    boolean TimeoutOccurred = FALSE;
    boolean SircWasDisabled = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 IrcoscStatus;

    (void)Instance;

    /* Clear LK bit field */
    IP_SCG->FIRCCSR &= (uint32)(~(SCG_FIRCCSR_LK_MASK));

    /* Check that FIRC is used by system clock) */
    if ((IP_SCG->FIRCCSR & SCG_FIRCCSR_FIRCSEL_MASK) != 0U)
    {
        /* Check whether FIRC is already configured as required */
        if ( (Config->Range != ((IP_SCG->FIRCCFG & SCG_FIRCCFG_RANGE_MASK) >> SCG_FIRCCFG_RANGE_SHIFT)) ||
            (Config->Regulator != ((IP_SCG->FIRCCSR & SCG_FIRCCSR_FIRCREGOFF_MASK) >> SCG_FIRCCSR_FIRCREGOFF_SHIFT)) )
        {
            /* Enable SIRC if it is disabled. */
            if (0U == (IP_SCG->SIRCCSR & SCG_SIRCCSR_SIRCEN_MASK))
            {
                SircWasDisabled = TRUE;
                Clock_Ip_SetSirc(NULL_PTR);
            }

            /* Switch to SIRC */
            SetInputSouceSytemClock(CLOCK_IP_SIRC_CLK_SOURCE);

            /* Disable clock */
            IP_SCG->FIRCCSR &= (~((uint32)SCG_FIRCCSR_FIRCEN_MASK));

            /* Configure FIRC. */
            if (1U == Config->Enable)
            {
                /* Step frequency range. */
                IP_SCG->FIRCCFG = SCG_FIRCCFG_RANGE(Config->Range);

                /* Enable clock. */
                IP_SCG->FIRCCSR |= (SCG_FIRCCSR_FIRCEN(1U) | SCG_FIRCCSR_FIRCREGOFF(Config->Regulator));

                Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
                /* Wait until ircosc is locked */
                do
                {
                    IrcoscStatus = (((IP_SCG->FIRCCSR & SCG_FIRCCSR_FIRCVLD_MASK) >> SCG_FIRCCSR_FIRCVLD_SHIFT));
                    TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
                }
                while ((0U == IrcoscStatus) && (FALSE == TimeoutOccurred));

                if (FALSE != TimeoutOccurred)
                {
                    /* Report timeout error */
                    Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Config->Name);
                }

                /* Switch back to FIRC */
                SetInputSouceSytemClock(CLOCK_IP_FIRC_CLK_SOURCE);

                if (SircWasDisabled)
                {
                    Clock_Ip_DisableSirc(SIRC_CLK);
                }
            }
        }
    }
    else
    {
        /* Configure FIRC. */

        /* Disable clock */
        IP_SCG->FIRCCSR &= (~((uint32)SCG_FIRCCSR_FIRCEN_MASK));

        if (1U == Config->Enable)
        {
            /* Step frequency range. */
            IP_SCG->FIRCCFG = SCG_FIRCCFG_RANGE(Config->Range);

            /* Enable clock. */
            IP_SCG->FIRCCSR |= (SCG_FIRCCSR_FIRCEN(1U) | SCG_FIRCCSR_FIRCREGOFF(Config->Regulator));

            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until ircosc is locked */
            do
            {
                IrcoscStatus = (((IP_SCG->FIRCCSR & SCG_FIRCCSR_FIRCVLD_MASK) >> SCG_FIRCCSR_FIRCVLD_SHIFT));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == IrcoscStatus) && (FALSE == TimeoutOccurred));

            if (FALSE != TimeoutOccurred)
            {
                /* Report timeout error */
                Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Config->Name);
            }
        }
    }
}
void Clock_Ip_EnableFirc_TrustedCall(Clock_Ip_IrcoscConfigType const* Config)
{
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 IrcoscStatus;

    if (1U == Config->Enable)
    {
        /* Enable clock. */
        IP_SCG->FIRCCSR |= SCG_FIRCCSR_FIRCEN(1U);

        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        /* Wait until ircosc is locked */
        do
        {
            IrcoscStatus = (((IP_SCG->FIRCCSR & SCG_FIRCCSR_FIRCVLD_MASK) >> SCG_FIRCCSR_FIRCVLD_SHIFT));
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while ((0U == IrcoscStatus) && (FALSE == TimeoutOccurred));

        if (FALSE != TimeoutOccurred)
        {
            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Config->Name);
        }
    }
}
void Clock_Ip_DisableFirc_TrustedCall(Clock_Ip_NameType Name)
{
    (void) Name;

    /* Disable clock. */
    IP_SCG->FIRCCSR &= ~SCG_FIRCCSR_FIRCEN_MASK;
}
#endif

/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/
/* Clock start constant section data */
#define MCU_START_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"

const Clock_Ip_IntOscCallbackType Clock_Ip_axIntOscCallbacks[CLOCK_IP_IRCOSC_CALLBACKS_COUNT] =
{
    {
        Clock_Ip_InternalOscillatorEmpty,          /* Set */
        Clock_Ip_InternalOscillatorEmpty,          /* Enable */
        Clock_Ip_InternalOscillatorEmpty_Disable,  /* Disable */
    },
#ifdef CLOCK_IP_FIRC_DIV_SEL_HSEb_CONFIG_REG_GPR
    {
        Clock_Ip_SetFircDivSelHSEb,                     /* Set */
        Clock_Ip_InternalOscillatorEmpty,               /* Enable */
        Clock_Ip_InternalOscillatorEmpty_Disable,       /* Disable */
    },
#endif
#ifdef CLOCK_IP_SIRC_ENABLE
    {
        Clock_Ip_SetSirc,                         /* Set */
        Clock_Ip_EnableSirc,                      /* Enable */
        Clock_Ip_DisableSirc,                     /* Disable */
    },
#endif

#ifdef CLOCK_IP_SIRC_VLP_ENABLE
    {
        Clock_Ip_SetSircVlp,                      /* Set */
        Clock_Ip_EnableSircVlp,                   /* Enable */
        Clock_Ip_DisableSircVlp,                  /* Disable */
    },
#endif

#ifdef CLOCK_IP_SIRC_STOP_ENABLE
    {
        Clock_Ip_SetSircStop,                      /* Set */
        Clock_Ip_EnableSircStop,                   /* Enable */
        Clock_Ip_DisableSircStop,                  /* Disable */
    },
#endif

#ifdef CLOCK_IP_FIRC_ENABLE
    {
        Clock_Ip_SetFirc,                          /* Set */
        Clock_Ip_EnableFirc,                       /* Enable */
        Clock_Ip_DisableFirc,                      /* Disable */
    },
#endif
};




/* Clock stop constant section data */
#define MCU_STOP_SEC_CONST_UNSPECIFIED

#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
