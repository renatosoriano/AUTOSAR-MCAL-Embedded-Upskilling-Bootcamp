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
*   @file       Clock_Ip_Divider.c
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
#define CLOCK_IP_DIVIDER_VENDOR_ID_C                      43
#define CLOCK_IP_DIVIDER_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_DIVIDER_AR_RELEASE_MINOR_VERSION_C       7
#define CLOCK_IP_DIVIDER_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_DIVIDER_SW_MAJOR_VERSION_C               2
#define CLOCK_IP_DIVIDER_SW_MINOR_VERSION_C               0
#define CLOCK_IP_DIVIDER_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Divider.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_DIVIDER_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Divider.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Divider.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_DIVIDER_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_DIVIDER_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_DIVIDER_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Divider.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Divider.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_DIVIDER_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_DIVIDER_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_DIVIDER_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Divider.c and Clock_Ip_Private.h are different"
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
#ifdef CLOCK_IP_SCG_ASYNC_DIV1
void Clock_Ip_SetScgAsyncDiv1_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_ASYNC_DIV2
void Clock_Ip_SetScgAsyncDiv2_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_DIVCORE_RUN
/* Set divider value of CORE_RUN_CLK to register */
void Clock_Ip_SetScgRunDivcore_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_DIVBUS_RUN
/* Set divider value of BUS_RUN_CLK to register */
void Clock_Ip_SetScgRunDivbus_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_DIVSLOW_RUN
/* Set divider value of SLOW_RUN_CLK to register */
void Clock_Ip_SetScgRunDivslow_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_DIVCORE_VLPR
/* Set divider value of CORE_VLPR_CLK to register */
void Clock_Ip_SetScgVlprDivcore_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_DIVBUS_VLPR
/* Set divider value of BUS_VLPR_CLK to register */
void Clock_Ip_SetScgVlprDivbus_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_DIVSLOW_VLPR
/* Set divider value of SLOW_VLPR_CLK to register */
void Clock_Ip_SetScgVlprDivslow_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_DIVCORE_HSRUN
/* Set divider value of CORE_HSRUN_CLK to register */
void Clock_Ip_SetScgHsrunDivcore_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_DIVBUS_HSRUN
/* Set divider value of BUS_HSRUN_CLK to register */
void Clock_Ip_SetScgHsrunDivbus_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SCG_DIVSLOW_HSRUN
/* Set divider value of SLOW_HSRUN_CLK to register */
void Clock_Ip_SetScgHsrunDivslow_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SIM_CLKOUT_DIV
/* Set divider value of CLKOUT0_CLK to register */
void Clock_Ip_SetSimClkoutDiv_TrustedCall(Clock_Ip_DividerConfigType const *Config);
#endif

#ifdef CLOCK_IP_PCC_PCD_FRAC
void Clock_Ip_SetPccPcdDivFrac_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SIM_TRACE_DIV_MUL
void Clock_Ip_SetSimTraceDivMul_TrustedCall(Clock_Ip_DividerConfigType const* Config);
#endif

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

static void Clock_Ip_Callback_DividerEmpty(Clock_Ip_DividerConfigType const* Config);
#ifdef CLOCK_IP_SCG_ASYNC_DIV1
static void Clock_Ip_SetScgAsyncDiv1(Clock_Ip_DividerConfigType const* Config);
#endif
#ifdef CLOCK_IP_SCG_ASYNC_DIV2
static void Clock_Ip_SetScgAsyncDiv2(Clock_Ip_DividerConfigType const* Config);
#endif
#ifdef CLOCK_IP_SCG_DIVCORE_RUN
static void Clock_Ip_SetScgRunDivcore(Clock_Ip_DividerConfigType const* Config);
#endif
#ifdef CLOCK_IP_SCG_DIVBUS_RUN
static void Clock_Ip_SetScgRunDivbus(Clock_Ip_DividerConfigType const* Config);
#endif
#ifdef CLOCK_IP_SCG_DIVSLOW_RUN
static void Clock_Ip_SetScgRunDivslow(Clock_Ip_DividerConfigType const* Config);
#endif
#ifdef CLOCK_IP_SCG_DIVCORE_VLPR
static void Clock_Ip_SetScgVlprDivcore(Clock_Ip_DividerConfigType const* Config);
#endif
#ifdef CLOCK_IP_SCG_DIVBUS_VLPR
static void Clock_Ip_SetScgVlprDivbus(Clock_Ip_DividerConfigType const* Config);
#endif
#ifdef CLOCK_IP_SCG_DIVSLOW_VLPR
static void Clock_Ip_SetScgVlprDivslow(Clock_Ip_DividerConfigType const* Config);
#endif
#ifdef CLOCK_IP_SCG_DIVCORE_HSRUN
static void Clock_Ip_SetScgHsrunDivcore(Clock_Ip_DividerConfigType const* Config);
#endif
#ifdef CLOCK_IP_SCG_DIVBUS_HSRUN
static void Clock_Ip_SetScgHsrunDivbus(Clock_Ip_DividerConfigType const* Config);
#endif
#ifdef CLOCK_IP_SCG_DIVSLOW_HSRUN
static void Clock_Ip_SetScgHsrunDivslow(Clock_Ip_DividerConfigType const* Config);
#endif

#ifdef CLOCK_IP_SIM_CLKOUT_DIV
static void Clock_Ip_SetSimClkoutDiv(Clock_Ip_DividerConfigType const *Config);
#endif

#ifdef CLOCK_IP_PCC_PCD_FRAC
static void Clock_Ip_SetPccPcdDivFrac(Clock_Ip_DividerConfigType const* Config);
#endif
#ifdef CLOCK_IP_SIM_TRACE_DIV_MUL
static void Clock_Ip_SetSimTraceDivMul(Clock_Ip_DividerConfigType const* Config);
#endif


/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
/* Clock start section code */

#include "Mcu_MemMap.h"

static void Clock_Ip_Callback_DividerEmpty(Clock_Ip_DividerConfigType const* Config)
{
    (void)Config;
    /* No implementation */
}

#ifdef CLOCK_IP_SCG_ASYNC_DIV1
static void Clock_Ip_SetScgAsyncDiv1(Clock_Ip_DividerConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetScgAsyncDiv1_TrustedCall,(Config));
      #else
        Clock_Ip_SetScgAsyncDiv1_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SCG_ASYNC_DIV2
static void Clock_Ip_SetScgAsyncDiv2(Clock_Ip_DividerConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetScgAsyncDiv2_TrustedCall,(Config));
      #else
        Clock_Ip_SetScgAsyncDiv2_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SCG_DIVCORE_RUN
static void Clock_Ip_SetScgRunDivcore(Clock_Ip_DividerConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetScgRunDivcore_TrustedCall,(Config));
      #else
        Clock_Ip_SetScgRunDivcore_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SCG_DIVBUS_RUN
static void Clock_Ip_SetScgRunDivbus(Clock_Ip_DividerConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetScgRunDivbus_TrustedCall,(Config));
      #else
        Clock_Ip_SetScgRunDivbus_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SCG_DIVSLOW_RUN
static void Clock_Ip_SetScgRunDivslow(Clock_Ip_DividerConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetScgRunDivslow_TrustedCall,(Config));
      #else
        Clock_Ip_SetScgRunDivslow_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SCG_DIVCORE_VLPR
static void Clock_Ip_SetScgVlprDivcore(Clock_Ip_DividerConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetScgVlprDivcore_TrustedCall,(Config));
      #else
        Clock_Ip_SetScgVlprDivcore_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SCG_DIVBUS_VLPR
static void Clock_Ip_SetScgVlprDivbus(Clock_Ip_DividerConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetScgVlprDivbus_TrustedCall,(Config));
      #else
        Clock_Ip_SetScgVlprDivbus_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SCG_DIVSLOW_VLPR
static void Clock_Ip_SetScgVlprDivslow(Clock_Ip_DividerConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetScgVlprDivslow_TrustedCall,(Config));
      #else
        Clock_Ip_SetScgVlprDivslow_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SCG_DIVCORE_HSRUN
static void Clock_Ip_SetScgHsrunDivcore(Clock_Ip_DividerConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetScgHsrunDivcore_TrustedCall,(Config));
      #else
        Clock_Ip_SetScgHsrunDivcore_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SCG_DIVBUS_HSRUN
static void Clock_Ip_SetScgHsrunDivbus(Clock_Ip_DividerConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetScgHsrunDivbus_TrustedCall,(Config));
      #else
        Clock_Ip_SetScgHsrunDivbus_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SCG_DIVSLOW_HSRUN
static void Clock_Ip_SetScgHsrunDivslow(Clock_Ip_DividerConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetScgHsrunDivslow_TrustedCall,(Config));
      #else
        Clock_Ip_SetScgHsrunDivslow_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SIM_CLKOUT_DIV
static void Clock_Ip_SetSimClkoutDiv(Clock_Ip_DividerConfigType const *Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetSimClkoutDiv_TrustedCall,(Config));
      #else
        Clock_Ip_SetSimClkoutDiv_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_PCC_PCD_FRAC
static void Clock_Ip_SetPccPcdDivFrac(Clock_Ip_DividerConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetPccPcdDivFrac_TrustedCall,(Config));
      #else
        Clock_Ip_SetPccPcdDivFrac_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

#ifdef CLOCK_IP_SIM_TRACE_DIV_MUL
static void Clock_Ip_SetSimTraceDivMul(Clock_Ip_DividerConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetSimTraceDivMul_TrustedCall,(Config));
      #else
        Clock_Ip_SetSimTraceDivMul_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif



/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef CLOCK_IP_SCG_ASYNC_DIV1
void Clock_Ip_SetScgAsyncDiv1_TrustedCall(Clock_Ip_DividerConfigType const* Config)
{
    uint32 RegValue;
    uint32 Instance      = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_MODULE_INSTANCE];
    uint32 DividerValue  = Clock_Ip_au8DividerValueHardwareValue[Config->Value];    /* Hw value corresponding to divider value. Translate the value by which is divided to hardware value. */


    RegValue = Clock_Ip_apxScgPeriphAsyncDivs[Instance]->ASYNC_DIV;
    RegValue &= ~SCG_SIRCDIV_SIRCDIV1_MASK;
    RegValue |= (DividerValue << SCG_SIRCDIV_SIRCDIV1_SHIFT);
    Clock_Ip_apxScgPeriphAsyncDivs[Instance]->ASYNC_DIV = RegValue;
}
#endif

#ifdef CLOCK_IP_SCG_ASYNC_DIV2
void Clock_Ip_SetScgAsyncDiv2_TrustedCall(Clock_Ip_DividerConfigType const* Config)
{
    uint32 RegValue;
    uint32 Instance      = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_MODULE_INSTANCE];
    uint32 DividerValue  = Clock_Ip_au8DividerValueHardwareValue[Config->Value];    /* Hw value corresponding to divider value. Translate the value by which is divided to hardware value. */

    RegValue = Clock_Ip_apxScgPeriphAsyncDivs[Instance]->ASYNC_DIV;
    RegValue &= ~SCG_SIRCDIV_SIRCDIV2_MASK;
    RegValue |= (DividerValue << SCG_SIRCDIV_SIRCDIV2_SHIFT);
    Clock_Ip_apxScgPeriphAsyncDivs[Instance]->ASYNC_DIV = RegValue;
}
#endif

#ifdef CLOCK_IP_SCG_DIVCORE_RUN
/* Set divider value of CORE_RUN_CLK to register */
void Clock_Ip_SetScgRunDivcore_TrustedCall(Clock_Ip_DividerConfigType const* Config)
{
    uint32 RegValue;

    RegValue = IP_SCG->RCCR;
    RegValue &= ~SCG_RCCR_DIVCORE_MASK;
    RegValue |= ((Config->Value - 1U) << SCG_RCCR_DIVCORE_SHIFT);
    IP_SCG->RCCR = RegValue;
}
#endif

#ifdef CLOCK_IP_SCG_DIVBUS_RUN
/* Set divider value of BUS_RUN_CLK to register */
void Clock_Ip_SetScgRunDivbus_TrustedCall(Clock_Ip_DividerConfigType const* Config)
{
    uint32 RegValue;

    RegValue = IP_SCG->RCCR;
    RegValue &= ~SCG_RCCR_DIVBUS_MASK;
    RegValue |= ((Config->Value - 1U) << SCG_RCCR_DIVBUS_SHIFT);
    IP_SCG->RCCR = RegValue;
}
#endif

#ifdef CLOCK_IP_SCG_DIVSLOW_RUN
/* Set divider value of SLOW_RUN_CLK to register */
void Clock_Ip_SetScgRunDivslow_TrustedCall(Clock_Ip_DividerConfigType const* Config)
{
    uint32 RegValue;

    RegValue = IP_SCG->RCCR;
    RegValue &= ~SCG_RCCR_DIVSLOW_MASK;
    RegValue |= ((Config->Value - 1U) << SCG_RCCR_DIVSLOW_SHIFT);
    IP_SCG->RCCR = RegValue;
}
#endif

#ifdef CLOCK_IP_SCG_DIVCORE_VLPR
/* Set divider value of CORE_VLPR_CLK to register */
void Clock_Ip_SetScgVlprDivcore_TrustedCall(Clock_Ip_DividerConfigType const* Config)
{
    uint32 RegValue;

    RegValue = IP_SCG->VCCR;
    RegValue &= ~SCG_VCCR_DIVCORE_MASK;
    RegValue |= ((Config->Value - 1U) << SCG_VCCR_DIVCORE_SHIFT);
    IP_SCG->VCCR = RegValue;
}
#endif

#ifdef CLOCK_IP_SCG_DIVBUS_VLPR
/* Set divider value of BUS_VLPR_CLK to register */
void Clock_Ip_SetScgVlprDivbus_TrustedCall(Clock_Ip_DividerConfigType const* Config)
{
    uint32 RegValue;

    RegValue = IP_SCG->VCCR;
    RegValue &= ~SCG_VCCR_DIVBUS_MASK;
    RegValue |= ((Config->Value - 1U) << SCG_VCCR_DIVBUS_SHIFT);
    IP_SCG->VCCR = RegValue;
}
#endif

#ifdef CLOCK_IP_SCG_DIVSLOW_VLPR
/* Set divider value of SLOW_VLPR_CLK to register */
void Clock_Ip_SetScgVlprDivslow_TrustedCall(Clock_Ip_DividerConfigType const* Config)
{
    uint32 RegValue;

    RegValue = IP_SCG->VCCR;
    RegValue &= ~SCG_VCCR_DIVSLOW_MASK;
    RegValue |= ((Config->Value - 1U) << SCG_VCCR_DIVSLOW_SHIFT);
    IP_SCG->VCCR = RegValue;
}
#endif

#ifdef CLOCK_IP_SCG_DIVCORE_HSRUN
/* Set divider value of CORE_HSRUN_CLK to register */
void Clock_Ip_SetScgHsrunDivcore_TrustedCall(Clock_Ip_DividerConfigType const* Config)
{
    uint32 RegValue;

    RegValue = IP_SCG->HCCR;
    RegValue &= ~SCG_HCCR_DIVCORE_MASK;
    RegValue |= ((Config->Value - 1U) << SCG_HCCR_DIVCORE_SHIFT);
    IP_SCG->HCCR = RegValue;
}
#endif

#ifdef CLOCK_IP_SCG_DIVBUS_HSRUN
/* Set divider value of BUS_HSRUN_CLK to register */
void Clock_Ip_SetScgHsrunDivbus_TrustedCall(Clock_Ip_DividerConfigType const* Config)
{
    uint32 RegValue;

    RegValue = IP_SCG->HCCR;
    RegValue &= ~SCG_HCCR_DIVBUS_MASK;
    RegValue |= ((Config->Value - 1U) << SCG_HCCR_DIVBUS_SHIFT);
    IP_SCG->HCCR = RegValue;
}
#endif

#ifdef CLOCK_IP_SCG_DIVSLOW_HSRUN
/* Set divider value of SLOW_HSRUN_CLK to register */
void Clock_Ip_SetScgHsrunDivslow_TrustedCall(Clock_Ip_DividerConfigType const* Config)
{
    uint32 RegValue;

    RegValue = IP_SCG->HCCR;
    RegValue &= ~SCG_HCCR_DIVSLOW_MASK;
    RegValue |= ((Config->Value - 1U) << SCG_HCCR_DIVSLOW_SHIFT);
    IP_SCG->HCCR = RegValue;
}
#endif

#ifdef CLOCK_IP_SIM_CLKOUT_DIV
/* Set divider value of CLKOUT0_CLK to register */
void Clock_Ip_SetSimClkoutDiv_TrustedCall(Clock_Ip_DividerConfigType const *Config)
{
    uint32 RegValue;

    RegValue = IP_SIM->CHIPCTL;
    RegValue &= ~SIM_CHIPCTL_CLKOUTDIV_MASK;
    RegValue |= SIM_CHIPCTL_CLKOUTDIV(Config->Value - 1U);
    IP_SIM->CHIPCTL = RegValue;
}
#endif

#ifdef CLOCK_IP_PCC_PCD_FRAC
void Clock_Ip_SetPccPcdDivFrac_TrustedCall(Clock_Ip_DividerConfigType const* Config)
{
    uint32 RegValue;

    RegValue = IP_PCC->PCCn[Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_DIVIDER_INDEX]];
    RegValue &= ~(PCC_PCCn_PCD_MASK | PCC_PCCn_FRAC_MASK);
    RegValue |= PCC_PCCn_PCD(Config->Value - 1U);                            /* Divider */
    RegValue |= PCC_PCCn_FRAC((uint32)(Config->Options[0U]) - 1U);                        /* Multiplier */
    IP_PCC->PCCn[Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_DIVIDER_INDEX]] = RegValue;
}
#endif

#ifdef CLOCK_IP_SIM_TRACE_DIV_MUL
void Clock_Ip_SetSimTraceDivMul_TrustedCall(Clock_Ip_DividerConfigType const* Config)
{
    uint32 RegValue;

    /* Disable TRACEDIVEN to configure TRACEDIV */
    IP_SIM->CLKDIV4  &= ~(SIM_CLKDIV4_TRACEDIVEN_MASK);
    RegValue = IP_SIM->CLKDIV4;
    RegValue &= ~(SIM_CLKDIV4_TRACEDIV_MASK | SIM_CLKDIV4_TRACEFRAC_MASK);
    RegValue |= SIM_CLKDIV4_TRACEDIV((uint32)(Config->Value) - 1U)              |    /* Divider */
                     SIM_CLKDIV4_TRACEFRAC((uint32)(Config->Options[0U]) - 1U);                /* Multiplier */
    IP_SIM->CLKDIV4 = RegValue;
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

const Clock_Ip_DividerCallbackType Clock_Ip_axDividerCallbacks[CLOCK_IP_DIVIDER_CALLBACKS_COUNT] =
{
    {
        Clock_Ip_Callback_DividerEmpty,                  /* Set */
    },
#ifdef CLOCK_IP_SCG_ASYNC_DIV1
    {
        Clock_Ip_SetScgAsyncDiv1,                       /* Set */
    },
#endif
#ifdef CLOCK_IP_SCG_ASYNC_DIV2
    {
        Clock_Ip_SetScgAsyncDiv2,                       /* Set */
    },
#endif
#ifdef CLOCK_IP_SCG_DIVCORE_RUN
    {
        Clock_Ip_SetScgRunDivcore,                     /* Set */
    },
#endif
#ifdef CLOCK_IP_SCG_DIVBUS_RUN
    {
        Clock_Ip_SetScgRunDivbus,                  /* Set */
    },
#endif
#ifdef CLOCK_IP_SCG_DIVSLOW_RUN
    {
        Clock_Ip_SetScgRunDivslow,                 /* Set */
    },
#endif
#ifdef CLOCK_IP_SCG_DIVCORE_VLPR
    {
        Clock_Ip_SetScgVlprDivcore,                     /* Set */
    },
#endif
#ifdef CLOCK_IP_SCG_DIVBUS_VLPR
    {
        Clock_Ip_SetScgVlprDivbus,                  /* Set */
    },
#endif
#ifdef CLOCK_IP_SCG_DIVSLOW_VLPR
    {
        Clock_Ip_SetScgVlprDivslow,                 /* Set */
    },
#endif
#ifdef CLOCK_IP_SCG_DIVCORE_HSRUN
    {
        Clock_Ip_SetScgHsrunDivcore,                     /* Set */
    },
#endif
#ifdef CLOCK_IP_SCG_DIVBUS_HSRUN
    {
        Clock_Ip_SetScgHsrunDivbus,                  /* Set */
    },
#endif
#ifdef CLOCK_IP_SCG_DIVSLOW_HSRUN
    {
        Clock_Ip_SetScgHsrunDivslow,                 /* Set */
    },
#endif
#ifdef CLOCK_IP_SIM_CLKOUT_DIV
    {
        Clock_Ip_SetSimClkoutDiv,                    /* Set */
    },
#endif
#ifdef CLOCK_IP_PCC_PCD_FRAC
    {
        Clock_Ip_SetPccPcdDivFrac,                   /* Set */
    },
#endif
#ifdef CLOCK_IP_SIM_TRACE_DIV_MUL
    {
        Clock_Ip_SetSimTraceDivMul,                  /* Set */
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
