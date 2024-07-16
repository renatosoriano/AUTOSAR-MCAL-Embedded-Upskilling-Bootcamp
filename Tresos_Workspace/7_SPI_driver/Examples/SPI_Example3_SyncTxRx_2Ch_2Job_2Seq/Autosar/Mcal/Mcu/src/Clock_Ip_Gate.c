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
*   @file       Clock_Ip_Gate.c
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
#define CLOCK_IP_GATE_VENDOR_ID_C                      43
#define CLOCK_IP_GATE_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_GATE_AR_RELEASE_MINOR_VERSION_C       7
#define CLOCK_IP_GATE_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_GATE_SW_MAJOR_VERSION_C               2
#define CLOCK_IP_GATE_SW_MINOR_VERSION_C               0
#define CLOCK_IP_GATE_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Gate.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_GATE_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Gate.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Gate.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_GATE_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_GATE_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_GATE_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Gate.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Gate.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_GATE_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_GATE_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_GATE_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Gate.c and Clock_Ip_Private.h are different"
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
#ifdef CLOCK_IP_SIM_LPO1K_ENABLE
/* Write configuration of clock gate to register */
void Clock_Ip_ClockSetSimLPO1KEnable_TrustedCall(Clock_Ip_GateConfigType const* Config);
#endif

#ifdef CLOCK_IP_SIM_LPO32K_ENABLE
/* Write configuration of clock gate to register */
void Clock_Ip_ClockSetSimLPO32KEnable_TrustedCall(Clock_Ip_GateConfigType const* Config);
#endif

#ifdef CLOCK_IP_SIM_CLKOUT_ENABLE
/* Write configuration of clock gate to register */
void Clock_Ip_ClockSetSimClkoutEnable_TrustedCall(Clock_Ip_GateConfigType const* Config);
#endif

#ifdef CLOCK_IP_PCC_CGC_ENABLE
/* Write configuration of clock gate to register */
void Clock_Ip_ClockSetPccCgcEnable_TrustedCall(Clock_Ip_GateConfigType const* Config);
#endif

#ifdef CLOCK_IP_SIM_PLATCGC_CGC
/* Write configuration of clock gate to register */
void Clock_Ip_ClockSetSimGate_TrustedCall(Clock_Ip_GateConfigType const* Config);
#endif

#ifdef CLOCK_IP_SIM_TRACE_ENABLE
/* Write configuration of clock gate to register */
void Clock_Ip_ClockSetSimTraceEnable_TrustedCall(Clock_Ip_GateConfigType const* Config);
#endif

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

static void Clock_Ip_ClockSetGateEmpty(Clock_Ip_GateConfigType const* Config);
static void Clock_Ip_ClockUpdateGateEmpty(Clock_Ip_NameType ClockName, boolean Gate);
#ifdef CLOCK_IP_SIM_LPO1K_ENABLE
static void Clock_Ip_ClockSetSimLPO1KEnable(Clock_Ip_GateConfigType const* Config);
static void Clock_Ip_ClockUpdateSimLPO1KEnable(Clock_Ip_NameType ClockName, boolean Gate);
#endif
#ifdef CLOCK_IP_SIM_LPO32K_ENABLE
static void Clock_Ip_ClockSetSimLPO32KEnable(Clock_Ip_GateConfigType const* Config);
static void Clock_Ip_ClockUpdateSimLPO32KEnable(Clock_Ip_NameType ClockName, boolean Gate);
#endif
#ifdef CLOCK_IP_SIM_CLKOUT_ENABLE
static void Clock_Ip_ClockSetSimClkoutEnable(Clock_Ip_GateConfigType const* Config);
static void Clock_Ip_ClockUpdateSimClkoutEnable(Clock_Ip_NameType ClockName, boolean Gate);
#endif
#ifdef CLOCK_IP_PCC_CGC_ENABLE
static void Clock_Ip_ClockSetPccCgcEnable(Clock_Ip_GateConfigType const* Config);
static void Clock_Ip_ClockUpdatePccCgcEnable(Clock_Ip_NameType ClockName, boolean Gate);
#endif
#ifdef CLOCK_IP_SIM_PLATCGC_CGC
static void Clock_Ip_ClockSetSimGate(Clock_Ip_GateConfigType const* Config);
static void Clock_Ip_ClockUpdateSimGate(Clock_Ip_NameType ClockName, boolean Gate);
#endif
#ifdef CLOCK_IP_SIM_TRACE_ENABLE
static void Clock_Ip_ClockSetSimTraceEnable(Clock_Ip_GateConfigType const* Config);
static void Clock_Ip_ClockUpdateSimTraceEnable(Clock_Ip_NameType ClockName, boolean Gate);
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

static void Clock_Ip_ClockSetGateEmpty(Clock_Ip_GateConfigType const* Config)
{
    (void)Config;
    /* No implementation */
}
static void Clock_Ip_ClockUpdateGateEmpty(Clock_Ip_NameType ClockName, boolean Gate)
{
    (void)ClockName;
    (void)Gate;
    /* No implementation */
}

#ifdef CLOCK_IP_SIM_LPO1K_ENABLE
static void Clock_Ip_ClockSetSimLPO1KEnable(Clock_Ip_GateConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_ClockSetSimLPO1KEnable_TrustedCall,(Config));
      #else
        Clock_Ip_ClockSetSimLPO1KEnable_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}

static void Clock_Ip_ClockUpdateSimLPO1KEnable(Clock_Ip_NameType ClockName, boolean Gate)
{
    Clock_Ip_GateConfigType Config;

    Config.Name = ClockName;
    if (TRUE == Gate)
    {
        Config.Enable = 0U;
    }
    else
    {
        Config.Enable = 1U;
    }
    /* Write configuration to register */
    Clock_Ip_ClockSetSimLPO1KEnable(&Config);
}
#endif

#ifdef CLOCK_IP_SIM_LPO32K_ENABLE
static void Clock_Ip_ClockSetSimLPO32KEnable(Clock_Ip_GateConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_ClockSetSimLPO32KEnable_TrustedCall,(Config));
      #else
        Clock_Ip_ClockSetSimLPO32KEnable_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_ClockUpdateSimLPO32KEnable(Clock_Ip_NameType ClockName, boolean Gate)
{
    Clock_Ip_GateConfigType Config;

    Config.Name = ClockName;
    if (TRUE == Gate)
    {
        Config.Enable = 0U;
    }
    else
    {
        Config.Enable = 1U;
    }
    /* Write configuration to register */
    Clock_Ip_ClockSetSimLPO32KEnable(&Config);
}
#endif

#ifdef CLOCK_IP_SIM_CLKOUT_ENABLE
static void Clock_Ip_ClockSetSimClkoutEnable(Clock_Ip_GateConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_ClockSetSimClkoutEnable_TrustedCall,(Config));
      #else
        Clock_Ip_ClockSetSimClkoutEnable_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_ClockUpdateSimClkoutEnable(Clock_Ip_NameType ClockName, boolean Gate)
{
    Clock_Ip_GateConfigType Config;

    Config.Name = ClockName;
    if (TRUE == Gate)
    {
        Config.Enable = 0U;
    }
    else
    {
        Config.Enable = 1U;
    }
    /* Write configuration to register */
    Clock_Ip_ClockSetSimClkoutEnable(&Config);
}
#endif

#ifdef CLOCK_IP_PCC_CGC_ENABLE
static void Clock_Ip_ClockSetPccCgcEnable(Clock_Ip_GateConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_ClockSetPccCgcEnable_TrustedCall,(Config));
      #else
        Clock_Ip_ClockSetPccCgcEnable_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_ClockUpdatePccCgcEnable(Clock_Ip_NameType ClockName, boolean Gate)
{
    Clock_Ip_GateConfigType Config;

    Config.Name = ClockName;
    if (TRUE == Gate)
    {
        Config.Enable = 0U;
    }
    else
    {
        Config.Enable = 1U;
    }
    /* Write configuration to register */
    Clock_Ip_ClockSetPccCgcEnable(&Config);
}
#endif

#ifdef CLOCK_IP_SIM_PLATCGC_CGC
#define SIM_PLATCGC_CGC_SHIFT(x)   (x)
#define SIM_PLATCGC_CGC_MASK(x)  ((uint32)1U << (x))
static void Clock_Ip_ClockSetSimGate(Clock_Ip_GateConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_ClockSetSimGate_TrustedCall,(Config));
      #else
        Clock_Ip_ClockSetSimGate_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_ClockUpdateSimGate(Clock_Ip_NameType ClockName, boolean Gate)
{
    Clock_Ip_GateConfigType Config;

    Config.Name = ClockName;
    if (TRUE == Gate)
    {
        Config.Enable = 0U;
    }
    else
    {
        Config.Enable = 1U;
    }
    /* Write configuration to register */
    Clock_Ip_ClockSetSimGate(&Config);
}
#endif

#ifdef CLOCK_IP_SIM_TRACE_ENABLE
static void Clock_Ip_ClockSetSimTraceEnable(Clock_Ip_GateConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_ClockSetSimTraceEnable_TrustedCall,(Config));
      #else
        Clock_Ip_ClockSetSimTraceEnable_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}

static void Clock_Ip_ClockUpdateSimTraceEnable(Clock_Ip_NameType ClockName, boolean Gate)
{
    Clock_Ip_GateConfigType Config;

    Config.Name = ClockName;
    if (TRUE == Gate)
    {
        Config.Enable = 0U;
    }
    else
    {
        Config.Enable = 1U;
    }
    /* Write configuration to register */
    Clock_Ip_ClockSetSimTraceEnable(&Config);
}
#endif


/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef CLOCK_IP_SIM_LPO1K_ENABLE
/* Write configuration of clock gate to register */
void Clock_Ip_ClockSetSimLPO1KEnable_TrustedCall(Clock_Ip_GateConfigType const* Config)
{
    uint32 RegValue;

    RegValue = IP_SIM->LPOCLKS;
    RegValue &= ~SIM_LPOCLKS_LPO1KCLKEN_MASK;
    RegValue |= ((uint32)(Config->Enable) << SIM_LPOCLKS_LPO1KCLKEN_SHIFT);
    IP_SIM->LPOCLKS = RegValue;
}
#endif

#ifdef CLOCK_IP_SIM_LPO32K_ENABLE
/* Write configuration of clock gate to register */
void Clock_Ip_ClockSetSimLPO32KEnable_TrustedCall(Clock_Ip_GateConfigType const* Config)
{
    uint32 RegValue;

    RegValue = IP_SIM->LPOCLKS;
    RegValue &= ~SIM_LPOCLKS_LPO32KCLKEN_MASK;
    RegValue |= ((uint32)(Config->Enable) << SIM_LPOCLKS_LPO32KCLKEN_SHIFT);
    IP_SIM->LPOCLKS = RegValue;
}
#endif

#ifdef CLOCK_IP_SIM_CLKOUT_ENABLE
/* Write configuration of clock gate to register */
void Clock_Ip_ClockSetSimClkoutEnable_TrustedCall(Clock_Ip_GateConfigType const* Config)
{
    uint32 RegValue;

    RegValue = IP_SIM->CHIPCTL;
    RegValue &= ~SIM_CHIPCTL_CLKOUTEN_MASK;
    RegValue |= ((uint32)(Config->Enable) << SIM_CHIPCTL_CLKOUTEN_SHIFT);
    IP_SIM->CHIPCTL = RegValue;
}
#endif

#ifdef CLOCK_IP_PCC_CGC_ENABLE
/* Write configuration of clock gate to register */
void Clock_Ip_ClockSetPccCgcEnable_TrustedCall(Clock_Ip_GateConfigType const* Config)
{
    uint32 RegValue;

    RegValue = IP_PCC->PCCn[Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_GATE_INDEX]];
    RegValue &= ~PCC_PCCn_CGC_MASK;
    RegValue |= ((uint32)(Config->Enable) << PCC_PCCn_CGC_SHIFT);
    IP_PCC->PCCn[Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_GATE_INDEX]] = RegValue;

}
#endif

#ifdef CLOCK_IP_SIM_PLATCGC_CGC
/* Write configuration of clock gate to register */
void Clock_Ip_ClockSetSimGate_TrustedCall(Clock_Ip_GateConfigType const* Config)
{
    uint32 Enable = Config->Enable;
    uint32 GateIndex = Clock_Ip_au8ClockFeatures[Config->Name][CLOCK_IP_GATE_INDEX];

    uint32 RegValue = (uint32 )IP_SIM->PLATCGC;
    RegValue &= (~((uint32 )SIM_PLATCGC_CGC_MASK(GateIndex)));
    RegValue |= Enable << SIM_PLATCGC_CGC_SHIFT(GateIndex);
    IP_SIM->PLATCGC = (uint32 )RegValue;
}
#endif

#ifdef CLOCK_IP_SIM_TRACE_ENABLE
/* Write configuration of clock gate to register */
void Clock_Ip_ClockSetSimTraceEnable_TrustedCall(Clock_Ip_GateConfigType const* Config)
{
    uint32 RegValue;

    RegValue = IP_SIM->CLKDIV4;
    if (1U == Config->Enable)
    {
        RegValue |= (SIM_CLKDIV4_TRACEDIVEN_MASK);
    }
    else
    {
        RegValue &= ~(SIM_CLKDIV4_TRACEDIVEN_MASK);
    }
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

const Clock_Ip_GateCallbackType Clock_Ip_axGateCallbacks[CLOCK_IP_GATE_CALLBACKS_COUNT] =
{
    {
        Clock_Ip_ClockSetGateEmpty,     /* Set */
        Clock_Ip_ClockUpdateGateEmpty,  /* Update */
    },
#ifdef CLOCK_IP_PCC_CGC_ENABLE
    {
        Clock_Ip_ClockSetPccCgcEnable,         /* Set */
        Clock_Ip_ClockUpdatePccCgcEnable,      /* Update */
    },
#endif
#ifdef CLOCK_IP_SIM_CLKOUT_ENABLE
    {
        Clock_Ip_ClockSetSimClkoutEnable,      /* Set */
        Clock_Ip_ClockUpdateSimClkoutEnable,   /* Update */
    },
#endif
#ifdef CLOCK_IP_SIM_LPO32K_ENABLE
    {
        Clock_Ip_ClockSetSimLPO32KEnable,      /* Set */
        Clock_Ip_ClockUpdateSimLPO32KEnable,   /* Update */
    },
#endif
#ifdef CLOCK_IP_SIM_LPO1K_ENABLE
    {
        Clock_Ip_ClockSetSimLPO1KEnable,      /* Set */
        Clock_Ip_ClockUpdateSimLPO1KEnable,   /* Update */
    },
#endif
#ifdef CLOCK_IP_SIM_PLATCGC_CGC
    {
        Clock_Ip_ClockSetSimGate,              /* Set */
        Clock_Ip_ClockUpdateSimGate,           /* Update */
    },
#endif
#ifdef CLOCK_IP_SIM_TRACE_ENABLE
    {
        Clock_Ip_ClockSetSimTraceEnable,       /* Set */
        Clock_Ip_ClockUpdateSimTraceEnable,    /* Update */
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

