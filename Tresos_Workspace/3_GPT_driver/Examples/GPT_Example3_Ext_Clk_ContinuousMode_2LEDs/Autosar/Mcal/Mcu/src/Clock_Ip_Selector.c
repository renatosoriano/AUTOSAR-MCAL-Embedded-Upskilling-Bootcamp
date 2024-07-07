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
*   @file       Clock_Ip_Selector.c
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
#define CLOCK_IP_SELECTOR_VENDOR_ID_C                      43
#define CLOCK_IP_SELECTOR_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_SELECTOR_AR_RELEASE_MINOR_VERSION_C       7
#define CLOCK_IP_SELECTOR_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_SELECTOR_SW_MAJOR_VERSION_C               2
#define CLOCK_IP_SELECTOR_SW_MINOR_VERSION_C               0
#define CLOCK_IP_SELECTOR_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Selector.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_SELECTOR_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Selector.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Selector.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_SELECTOR_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_SELECTOR_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_SELECTOR_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Selector.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Selector.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_SELECTOR_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_SELECTOR_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_SELECTOR_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Selector.c and Clock_Ip_Private.h are different"
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

#ifdef CLOCK_IP_SCG_SCS_RUN_SEL
void Clock_Ip_ResetScgRunSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
void Clock_Ip_SetScgRunSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SCG_SCS_VLPR_SEL
void Clock_Ip_SetScgVlprSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SCG_SCS_HSRUN_SEL
void Clock_Ip_ResetScgHsrunSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
void Clock_Ip_SetScgHsrunSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SIM_RTC_SEL
void Clock_Ip_ResetSimRtcSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
void Clock_Ip_SetSimRtcSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SIM_LPO_SEL
void Clock_Ip_ResetSimLpoSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
void Clock_Ip_SetSimLpoSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SCG_CLKOUT_SEL
void Clock_Ip_ResetScgClkoutSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
void Clock_Ip_SetScgClkoutSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SIM_FTMOPT_SEL
void Clock_Ip_ResetSimFtmoptSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
void Clock_Ip_SetSimFtmoptSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SIM_CLKOUT_SEL
/* Clear CLKOUTSEL and CLKOUTEN bit field in SIM_CHIPCTL register  */
void Clock_Ip_ResetSimClkoutSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
void Clock_Ip_SetSimClkoutSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_PCC_PCS_SELECT
void Clock_Ip_ResetPccPcsSelect_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
void Clock_Ip_SetPccPcsSelect_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SIM_TRACE_SEL
void Clock_Ip_ResetSimTraceSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
void Clock_Ip_SetSimTraceSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config);
#endif

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

static void Clock_Ip_CallbackSelectorEmpty(Clock_Ip_SelectorConfigType const* Config);

#ifdef CLOCK_IP_SIM_RTC_SEL
static void Clock_Ip_ResetSimRtcSel(Clock_Ip_SelectorConfigType const *Config);
static void Clock_Ip_SetSimRtcSel(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SIM_LPO_SEL
static void Clock_Ip_ResetSimLpoSel(Clock_Ip_SelectorConfigType const *Config);
static void Clock_Ip_SetSimLpoSel(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SCG_CLKOUT_SEL
static void Clock_Ip_ResetScgClkoutSel(Clock_Ip_SelectorConfigType const *Config);
static void Clock_Ip_SetScgClkoutSel(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SCG_SCS_RUN_SEL
static void Clock_Ip_ResetScgRunSel(Clock_Ip_SelectorConfigType const *Config);
static void Clock_Ip_SetScgRunSel(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SCG_SCS_VLPR_SEL
static void Clock_Ip_SetScgVlprSel(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SCG_SCS_HSRUN_SEL
static void Clock_Ip_ResetScgHsrunSel(Clock_Ip_SelectorConfigType const *Config);
static void Clock_Ip_SetScgHsrunSel(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SIM_FTMOPT_SEL
static void Clock_Ip_ResetSimFtmoptSel(Clock_Ip_SelectorConfigType const *Config);
static void Clock_Ip_SetSimFtmoptSel(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SIM_CLKOUT_SEL
static void Clock_Ip_ResetSimClkoutSel(Clock_Ip_SelectorConfigType const *Config);
static void Clock_Ip_SetSimClkoutSel(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_PCC_PCS_SELECT
static void Clock_Ip_ResetPccPcsSelect(Clock_Ip_SelectorConfigType const *Config);
static void Clock_Ip_SetPccPcsSelect(Clock_Ip_SelectorConfigType const *Config);
#endif

#ifdef CLOCK_IP_SIM_TRACE_SEL
static void Clock_Ip_ResetSimTraceSel(Clock_Ip_SelectorConfigType const *Config);
static void Clock_Ip_SetSimTraceSel(Clock_Ip_SelectorConfigType const *Config);
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

static void Clock_Ip_CallbackSelectorEmpty(Clock_Ip_SelectorConfigType const* Config)
{
    (void)Config;
    /* No implementation */
}

#ifdef CLOCK_IP_SCG_SCS_RUN_SEL
static void Clock_Ip_ResetScgRunSel(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_ResetScgRunSel_TrustedCall,(Config));
      #else
        Clock_Ip_ResetScgRunSel_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}

static void Clock_Ip_SetScgRunSel(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetScgRunSel_TrustedCall,(Config));
      #else
        Clock_Ip_SetScgRunSel_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}

#endif

#ifdef CLOCK_IP_SCG_SCS_VLPR_SEL
static void Clock_Ip_SetScgVlprSel(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetScgVlprSel_TrustedCall,(Config));
      #else
        Clock_Ip_SetScgVlprSel_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}

#endif

#ifdef CLOCK_IP_SCG_SCS_HSRUN_SEL
static void Clock_Ip_ResetScgHsrunSel(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_ResetScgHsrunSel_TrustedCall,(Config));
      #else
        Clock_Ip_ResetScgHsrunSel_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_SetScgHsrunSel(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetScgHsrunSel_TrustedCall,(Config));
      #else
        Clock_Ip_SetScgHsrunSel_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SIM_RTC_SEL
static void Clock_Ip_ResetSimRtcSel(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_ResetSimRtcSel_TrustedCall,(Config));
      #else
        Clock_Ip_ResetSimRtcSel_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_SetSimRtcSel(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetSimRtcSel_TrustedCall,(Config));
      #else
        Clock_Ip_SetSimRtcSel_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SIM_LPO_SEL
static void Clock_Ip_ResetSimLpoSel(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_ResetSimLpoSel_TrustedCall,(Config));
      #else
        Clock_Ip_ResetSimLpoSel_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_SetSimLpoSel(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetSimLpoSel_TrustedCall,(Config));
      #else
        Clock_Ip_SetSimLpoSel_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SCG_CLKOUT_SEL
static void Clock_Ip_ResetScgClkoutSel(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_ResetScgClkoutSel_TrustedCall,(Config));
      #else
        Clock_Ip_ResetScgClkoutSel_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_SetScgClkoutSel(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetScgClkoutSel_TrustedCall,(Config));
      #else
        Clock_Ip_SetScgClkoutSel_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SIM_FTMOPT_SEL
static void Clock_Ip_ResetSimFtmoptSel(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_ResetSimFtmoptSel_TrustedCall,(Config));
      #else
        Clock_Ip_ResetSimFtmoptSel_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_SetSimFtmoptSel(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetSimFtmoptSel_TrustedCall,(Config));
      #else
        Clock_Ip_SetSimFtmoptSel_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SIM_CLKOUT_SEL
static void Clock_Ip_ResetSimClkoutSel(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_ResetSimClkoutSel_TrustedCall,(Config));
      #else
        Clock_Ip_ResetSimClkoutSel_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_SetSimClkoutSel(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetSimClkoutSel_TrustedCall,(Config));
      #else
        Clock_Ip_SetSimClkoutSel_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_PCC_PCS_SELECT
static void Clock_Ip_ResetPccPcsSelect(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_ResetPccPcsSelect_TrustedCall,(Config));
      #else
        Clock_Ip_ResetPccPcsSelect_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_SetPccPcsSelect(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetPccPcsSelect_TrustedCall,(Config));
      #else
        Clock_Ip_SetPccPcsSelect_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SIM_TRACE_SEL
static void Clock_Ip_ResetSimTraceSel(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_ResetSimTraceSel_TrustedCall,(Config));
      #else
        Clock_Ip_ResetSimTraceSel_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_SetSimTraceSel(Clock_Ip_SelectorConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetSimTraceSel_TrustedCall,(Config));
      #else
        Clock_Ip_SetSimTraceSel_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef CLOCK_IP_SCG_SCS_RUN_SEL
void Clock_Ip_ResetScgRunSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;
    uint32 SelectorValue = Clock_Ip_au8SelectorEntryScsHardwareValue[FIRC_CLK];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    (void)Config;

    RegValue = IP_SCG->RCCR;
    RegValue &= ~SCG_RCCR_SCS_MASK;
    RegValue |= SCG_RCCR_SCS(SelectorValue);
    IP_SCG->RCCR = RegValue;
}

void Clock_Ip_SetScgRunSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;
    uint32 SelectorValue = Clock_Ip_au8SelectorEntryScsHardwareValue[Config->Value];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    RegValue = IP_SCG->RCCR;
    RegValue &= ~SCG_RCCR_SCS_MASK;
    RegValue |= SCG_RCCR_SCS(SelectorValue);
    IP_SCG->RCCR = RegValue;
}
#endif

#ifdef CLOCK_IP_SCG_SCS_VLPR_SEL

void Clock_Ip_SetScgVlprSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;
    uint32 SelectorValue = Clock_Ip_au8SelectorEntryScsHardwareValue[Config->Value];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    RegValue = IP_SCG->VCCR;
    RegValue &= ~SCG_VCCR_SCS_MASK;
    RegValue |= SCG_VCCR_SCS(SelectorValue);
    IP_SCG->VCCR = RegValue;
}

#endif

#ifdef CLOCK_IP_SCG_SCS_HSRUN_SEL
void Clock_Ip_ResetScgHsrunSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;
    uint32 SelectorValue = Clock_Ip_au8SelectorEntryScsHardwareValue[FIRC_CLK];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    (void)Config;

    RegValue = IP_SCG->HCCR;
    RegValue &= ~SCG_HCCR_SCS_MASK;
    RegValue |= SCG_HCCR_SCS(SelectorValue);
    IP_SCG->HCCR = RegValue;
}
void Clock_Ip_SetScgHsrunSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;
    uint32 SelectorValue = Clock_Ip_au8SelectorEntryScsHardwareValue[Config->Value];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    RegValue = IP_SCG->HCCR;
    RegValue &= ~SCG_HCCR_SCS_MASK;
    RegValue |= SCG_HCCR_SCS(SelectorValue);
    IP_SCG->HCCR = RegValue;
}
#endif

#ifdef CLOCK_IP_SIM_RTC_SEL
void Clock_Ip_ResetSimRtcSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;
    uint32 SelectorValue = Clock_Ip_au16SelectorEntryHardwareValue[SOSCDIV1_CLK];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    (void)Config;

    RegValue = IP_SIM->LPOCLKS;
    RegValue &= ~SIM_LPOCLKS_RTCCLKSEL_MASK;
    RegValue |= (SelectorValue << SIM_LPOCLKS_RTCCLKSEL_SHIFT);
    IP_SIM->LPOCLKS = RegValue;
}

void Clock_Ip_SetSimRtcSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;
    uint32 SelectorValue = Clock_Ip_au16SelectorEntryHardwareValue[Config->Value];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    RegValue = IP_SIM->LPOCLKS;
    RegValue &= ~SIM_LPOCLKS_RTCCLKSEL_MASK;
    RegValue |= (SelectorValue << SIM_LPOCLKS_RTCCLKSEL_SHIFT);
    IP_SIM->LPOCLKS = RegValue;
}
#endif

#ifdef CLOCK_IP_SIM_LPO_SEL
void Clock_Ip_ResetSimLpoSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;
    uint32 SelectorValue = Clock_Ip_au8SelectorEntrySIMHardwareValue[LPO_128K_CLK];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    (void)Config;

    RegValue = IP_SIM->LPOCLKS;
    RegValue &= ~SIM_LPOCLKS_LPOCLKSEL_MASK;
    RegValue |= (SelectorValue << SIM_LPOCLKS_LPOCLKSEL_SHIFT);
    IP_SIM->LPOCLKS = RegValue;
}
void Clock_Ip_SetSimLpoSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;
    /* LPO_CLK selector mapped to Clock_Ip_au8SelectorEntrySIMHardwareValue */
    uint32 SelectorValue = Clock_Ip_au8SelectorEntrySIMHardwareValue[Config->Value];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    (void)Config;

    RegValue = IP_SIM->LPOCLKS;
    RegValue &= ~SIM_LPOCLKS_LPOCLKSEL_MASK;
    RegValue |= (SelectorValue << SIM_LPOCLKS_LPOCLKSEL_SHIFT);
    IP_SIM->LPOCLKS = RegValue;
}
#endif

#ifdef CLOCK_IP_SCG_CLKOUT_SEL
void Clock_Ip_ResetScgClkoutSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;
    /* LPO_CLK selector mapped to Clock_Ip_au8SelectorEntryScsHardwareValue */
    uint32 SelectorValue = Clock_Ip_au8SelectorEntryScsHardwareValue[FIRC_CLK];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    (void)Config;

    RegValue = IP_SCG->CLKOUTCNFG;
    RegValue &= ~SCG_CLKOUTCNFG_CLKOUTSEL_MASK;
    RegValue |= (SelectorValue << SCG_CLKOUTCNFG_CLKOUTSEL_SHIFT);
    IP_SCG->CLKOUTCNFG = RegValue;
}
void Clock_Ip_SetScgClkoutSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;
    uint32 SelectorValue = Clock_Ip_au8SelectorEntryScsHardwareValue[Config->Value];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    RegValue = IP_SCG->CLKOUTCNFG;
    RegValue &= ~SCG_CLKOUTCNFG_CLKOUTSEL_MASK;
    RegValue |= (SelectorValue << SCG_CLKOUTCNFG_CLKOUTSEL_SHIFT);
    IP_SCG->CLKOUTCNFG = RegValue;
}
#endif

#ifdef CLOCK_IP_SIM_FTMOPT_SEL
#define SIM_FTMOPT0_FTM_0_3_CLKSEL_SHIFT(x)  (24U + ((x) << 1U))
#define SIM_FTMOPT0_FTM_0_3_CLKSEL_MASK(x)   ((uint32)3U << SIM_FTMOPT0_FTM_0_3_CLKSEL_SHIFT(x))
#define SIM_FTMOPT0_FTM_4_7_CLKSEL_SHIFT(x)  (16U + (((x) - 4U) << 1U))
#define SIM_FTMOPT0_FTM_4_7_CLKSEL_MASK(x)   ((uint32)3U << SIM_FTMOPT0_FTM_4_7_CLKSEL_SHIFT(x))
void Clock_Ip_ResetSimFtmoptSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;
    uint32 SelectorValue = Clock_Ip_au16SelectorEntryHardwareValue[FIRC_CLK];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */
    uint32 Instance      = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_MODULE_INSTANCE];

    RegValue = IP_SIM->FTMOPT0;
    if(Instance < 4U)
    {
        RegValue &= ~(SIM_FTMOPT0_FTM_0_3_CLKSEL_MASK(Instance));
        RegValue |= (SelectorValue << SIM_FTMOPT0_FTM_0_3_CLKSEL_SHIFT(Instance));
    }
    else
    {
        RegValue &= ~(SIM_FTMOPT0_FTM_4_7_CLKSEL_MASK(Instance));
        RegValue |= (SelectorValue << SIM_FTMOPT0_FTM_4_7_CLKSEL_SHIFT(Instance));
    }

    IP_SIM->FTMOPT0 = RegValue;
}
void Clock_Ip_SetSimFtmoptSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;
    uint32 SelectorValue = Clock_Ip_au16SelectorEntryHardwareValue[Config->Value];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */
    uint32 Instance      = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_MODULE_INSTANCE];

    RegValue = IP_SIM->FTMOPT0;
    if(Instance < 4U)
    {
        RegValue &= ~(SIM_FTMOPT0_FTM_0_3_CLKSEL_MASK(Instance));
        RegValue |= (SelectorValue << SIM_FTMOPT0_FTM_0_3_CLKSEL_SHIFT(Instance));
    }
    else
    {
        RegValue &= ~(SIM_FTMOPT0_FTM_4_7_CLKSEL_MASK(Instance));
        RegValue |= (SelectorValue << SIM_FTMOPT0_FTM_4_7_CLKSEL_SHIFT(Instance));
    }

    IP_SIM->FTMOPT0 = RegValue;
}
#endif

#ifdef CLOCK_IP_SIM_CLKOUT_SEL
/* Clear CLKOUTSEL and CLKOUTEN bit field in SIM_CHIPCTL register  */
void Clock_Ip_ResetSimClkoutSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;

    (void)Config;

    RegValue = IP_SIM->CHIPCTL;
    RegValue &= ~(SIM_CHIPCTL_CLKOUTSEL_MASK | SIM_CHIPCTL_CLKOUTEN_MASK);
    IP_SIM->CHIPCTL = RegValue;
}
void Clock_Ip_SetSimClkoutSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;
    uint32 SelectorValue = Clock_Ip_au16SelectorEntryHardwareValue[Config->Value];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    RegValue = IP_SIM->CHIPCTL;
    RegValue &= ~SIM_CHIPCTL_CLKOUTSEL_MASK;
    RegValue |= (SelectorValue << SIM_CHIPCTL_CLKOUTSEL_SHIFT);
    IP_SIM->CHIPCTL = RegValue;
}
#endif

#ifdef CLOCK_IP_PCC_PCS_SELECT
/**
* @brief            This function will reset writable bit fields of PCC register
*/
void Clock_Ip_ResetPccPcsSelect_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 PccIndex = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_SELECTOR_INDEX];

    /* Disable CGC before set PCS */
    IP_PCC->PCCn[PccIndex] &= ~(PCC_PCCn_CGC_MASK);
    IP_PCC->PCCn[PccIndex] &= ~(PCC_PCCn_PCS_MASK);
}
void Clock_Ip_SetPccPcsSelect_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;
    uint32 PccIndex = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_SELECTOR_INDEX];
    uint32 SelectorValue = Clock_Ip_au8SelectorEntryPcsHardwareValue[Config->Value];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    RegValue = IP_PCC->PCCn[PccIndex];
    RegValue &= ~PCC_PCCn_PCS_MASK;
    RegValue |= PCC_PCCn_PCS(SelectorValue);
    IP_PCC->PCCn[PccIndex] = RegValue;
}
#endif

#ifdef CLOCK_IP_SIM_TRACE_SEL
void Clock_Ip_ResetSimTraceSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;
    /* TRACE_CLK selector mapped to Clock_Ip_au16SelectorEntryHardwareValue */
    uint32 SelectorValue = Clock_Ip_au16SelectorEntryHardwareValue[CORE_CLK];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    (void) Config;
    RegValue = (uint32)IP_SIM->CHIPCTL;
    RegValue &= (~((uint32)SIM_CHIPCTL_TRACECLK_SEL_MASK));
    RegValue |= SIM_CHIPCTL_TRACECLK_SEL(SelectorValue);
    IP_SIM->CHIPCTL = (uint32)RegValue;
}
void Clock_Ip_SetSimTraceSel_TrustedCall(Clock_Ip_SelectorConfigType const *Config)
{
    uint32 RegValue;
    /* TRACE_CLK selector mapped to Clock_Ip_au16SelectorEntryHardwareValue */
    uint32 SelectorValue = Clock_Ip_au16SelectorEntryHardwareValue[Config->Value];    /* Hw value corresponding to selector entry. Translate input clock source to hardware value. */

    RegValue = (uint32)IP_SIM->CHIPCTL;
    RegValue &= (~((uint32)SIM_CHIPCTL_TRACECLK_SEL_MASK));
    RegValue |= SIM_CHIPCTL_TRACECLK_SEL(SelectorValue);
    IP_SIM->CHIPCTL = (uint32)RegValue;
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

const Clock_Ip_SelectorCallbackType Clock_Ip_axSelectorCallbacks[CLOCK_IP_SELECTOR_CALLBACKS_COUNT] =
{
    {
        Clock_Ip_CallbackSelectorEmpty,            /* Reset */
        Clock_Ip_CallbackSelectorEmpty,            /* Set */
    },
#ifdef CLOCK_IP_SCG_SCS_RUN_SEL
    {
        Clock_Ip_ResetScgRunSel,                 /* Reset */
        Clock_Ip_SetScgRunSel,                   /* Set */
    },
#endif

#ifdef CLOCK_IP_SCG_SCS_VLPR_SEL
    {
        Clock_Ip_CallbackSelectorEmpty,          /* Reset */
        Clock_Ip_SetScgVlprSel,                   /* Set */
    },
#endif

#ifdef CLOCK_IP_SCG_SCS_HSRUN_SEL
    {
        Clock_Ip_ResetScgHsrunSel,                 /* Reset */
        Clock_Ip_SetScgHsrunSel,                   /* Set */
    },
#endif

#ifdef CLOCK_IP_SIM_RTC_SEL
    {
        Clock_Ip_ResetSimRtcSel,                 /* Reset */
        Clock_Ip_SetSimRtcSel,                   /* Set */
    },
#endif

#ifdef CLOCK_IP_SIM_LPO_SEL
    {
        Clock_Ip_ResetSimLpoSel,                 /* Reset */
        Clock_Ip_SetSimLpoSel,                   /* Set */
    },
#endif

#ifdef CLOCK_IP_SCG_CLKOUT_SEL
    {
        Clock_Ip_ResetScgClkoutSel,             /* Reset */
        Clock_Ip_SetScgClkoutSel,               /* Set */
    },
#endif

#ifdef CLOCK_IP_SIM_FTMOPT_SEL
    {
        Clock_Ip_ResetSimFtmoptSel,              /* Reset */
        Clock_Ip_SetSimFtmoptSel,                /* Set */
    },
#endif

#ifdef CLOCK_IP_SIM_CLKOUT_SEL
    {
        Clock_Ip_ResetSimClkoutSel,              /* Reset */
        Clock_Ip_SetSimClkoutSel,                /* Set */
    },
#endif

#ifdef CLOCK_IP_PCC_PCS_SELECT
    {
        Clock_Ip_ResetPccPcsSelect,              /* Reset */
        Clock_Ip_SetPccPcsSelect,                /* Set */
    },
#endif

#ifdef CLOCK_IP_SIM_TRACE_SEL
    {
        Clock_Ip_ResetSimTraceSel,               /* Reset */
        Clock_Ip_SetSimTraceSel,                 /* Set */
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
