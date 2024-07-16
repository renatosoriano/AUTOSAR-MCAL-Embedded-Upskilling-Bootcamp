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
*   @file       Clock_Ip_Pll.c
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
#define CLOCK_IP_PLL_VENDOR_ID_C                      43
#define CLOCK_IP_PLL_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_PLL_AR_RELEASE_MINOR_VERSION_C       7
#define CLOCK_IP_PLL_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_PLL_SW_MAJOR_VERSION_C               2
#define CLOCK_IP_PLL_SW_MINOR_VERSION_C               0
#define CLOCK_IP_PLL_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_Pll.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_PLL_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_Pll.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_Pll.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_PLL_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_PLL_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_PLL_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_Pll.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_Pll.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_PLL_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_PLL_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_PLL_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_Pll.c and Clock_Ip_Private.h are different"
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

#ifdef CLOCK_IP_SPLL_ENABLE
void Clock_Ip_ResetSpll_TrustedCall(Clock_Ip_PllConfigType const* Config);
void Clock_Ip_SetSpll_TrustedCall(Clock_Ip_PllConfigType const* Config);
void Clock_Ip_DisableSpll_TrustedCall(Clock_Ip_NameType PllName);
void Clock_Ip_EnableSpll_TrustedCall(Clock_Ip_PllConfigType const* Config);
#endif

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


static void Clock_Ip_CallbackPllEmpty(Clock_Ip_PllConfigType const* Config);
static Clock_Ip_PllStatusReturnType Clock_Ip_CallbackPllEmptyComplete(Clock_Ip_NameType PllName);
static void Clock_Ip_CallbackPllEmptyDisable(Clock_Ip_NameType PllName);

#ifdef CLOCK_IP_SPLL_ENABLE
static void Clock_Ip_ResetSpll(Clock_Ip_PllConfigType const* Config);
static void Clock_Ip_SetSpll(Clock_Ip_PllConfigType const* Config);
static Clock_Ip_PllStatusReturnType Clock_Ip_CompleteSpll(Clock_Ip_NameType PllName);
static void Clock_Ip_EnableSpll(Clock_Ip_PllConfigType const* Config);
static void Clock_Ip_DisableSpll(Clock_Ip_NameType PllName);
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


static void Clock_Ip_CallbackPllEmpty(Clock_Ip_PllConfigType const* Config)
{
    (void)Config;
    /* No implementation */
}
static Clock_Ip_PllStatusReturnType Clock_Ip_CallbackPllEmptyComplete(Clock_Ip_NameType PllName)
{
    (void)PllName;
    /* No implementation */
    return STATUS_PLL_LOCKED;
}
static void Clock_Ip_CallbackPllEmptyDisable(Clock_Ip_NameType PllName)
{
    (void)PllName;
    /* No implementation */
}


#ifdef CLOCK_IP_SPLL_ENABLE
static void Clock_Ip_ResetSpll(Clock_Ip_PllConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_ResetSpll_TrustedCall,(Config));
      #else
        Clock_Ip_ResetSpll_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_SetSpll(Clock_Ip_PllConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetSpll_TrustedCall,(Config));
      #else
        Clock_Ip_SetSpll_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static Clock_Ip_PllStatusReturnType Clock_Ip_CompleteSpll(Clock_Ip_NameType PllName)
{
    Clock_Ip_PllStatusReturnType PllStatus = STATUS_PLL_UNLOCKED;
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 SpllStatus;


    /* Configure SPLL. */
    if ((IP_SCG->SPLLCSR & SCG_SPLLCSR_SPLLEN_MASK) != 0U)
    {
        Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
        /* Wait until pll is locked */
        do
        {
            SpllStatus = (((IP_SCG->SPLLCSR & SCG_SPLLCSR_SPLLVLD_MASK) >> SCG_SPLLCSR_SPLLVLD_SHIFT));
            TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
        }
        while ((0U == SpllStatus) && (FALSE == TimeoutOccurred));

        if (FALSE == TimeoutOccurred)
        {
            PllStatus = STATUS_PLL_LOCKED;
        }
        else
        {
            /* Report timeout error */
            Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, PllName);
        }
    }
    else
    {
        PllStatus = STATUS_PLL_NOT_ENABLED;
    }
    
    return PllStatus;
}
static void Clock_Ip_DisableSpll(Clock_Ip_NameType PllName)
{
#ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(Clock_Ip_DisableSpll_TrustedCall,(PllName));
  #else
    Clock_Ip_DisableSpll_TrustedCall(PllName);
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
}
static void Clock_Ip_EnableSpll(Clock_Ip_PllConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_EnableSpll_TrustedCall,(Config));
      #else
        Clock_Ip_EnableSpll_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef CLOCK_IP_SPLL_ENABLE
void Clock_Ip_ResetSpll_TrustedCall(Clock_Ip_PllConfigType const* Config)
{
    (void)Config;

    /* Power down PLL */

    /* Clear LK bit field */
    IP_SCG->SPLLCSR &= (~((uint32)SCG_SPLLCSR_LK_MASK));

    /* Disable clock monitor */
    IP_SCG->SPLLCSR &= (~((uint32)SCG_SPLLCSR_SPLLCM_MASK));

    /* Disable clock monitor reset*/
    IP_SCG->SPLLCSR &= (~((uint32)SCG_SPLLCSR_SPLLCMRE_MASK));

    /* Disable clock */
    IP_SCG->SPLLCSR &= (~((uint32)SCG_SPLLCSR_SPLLEN_MASK));

    /* Reset PLL configuration. */
    #if (defined (CLOCK_IP_S32K142W) || defined(CLOCK_IP_S32K144W) || defined(CLOCK_IP_S32M244))
    IP_SCG->SPLLCFG &= (~((uint32)SCG_SPLLCFG_SOURCE_MASK));
    #endif
    IP_SCG->SPLLCFG &= (~((uint32)SCG_SPLLCFG_PREDIV_MASK));
    IP_SCG->SPLLCFG &= (~((uint32)SCG_SPLLCFG_MULT_MASK));
}
void Clock_Ip_SetSpll_TrustedCall(Clock_Ip_PllConfigType const* Config)
{
    /* Configure SPLL. */
    if (1U == Config->Enable)
    {
        #if (defined (CLOCK_IP_S32K142W) || defined(CLOCK_IP_S32K144W) || defined(CLOCK_IP_S32M244))
        /* Select input reference. */
        if (Config->InputReference == SOSC_CLK)
        {
            IP_SCG->SPLLCFG |= SCG_SPLLCFG_SOURCE(0UL);
        }
        else
        {
            IP_SCG->SPLLCFG |= SCG_SPLLCFG_SOURCE(1UL);
        }
        #endif

        /* Set PLL configuration. */
        IP_SCG->SPLLCFG |= SCG_SPLLCFG_PREDIV((uint32)(Config->Predivider) - 1U)  |
                        SCG_SPLLCFG_MULT((uint32)(Config->MulFactorDiv) - 16U);

        /* Enable clock, configure monitor, lock register. */
        switch (Config->Monitor)
        {
#ifdef CLOCK_IP_HAS_MONITOR_DISABLE
            case CLOCK_IP_HAS_MONITOR_DISABLE:
            {
                IP_SCG->SPLLCSR = SCG_SPLLCSR_SPLLCM(0UL) |
                               SCG_SPLLCSR_SPLLCMRE(0UL);
            }
            break;
#endif
#ifdef CLOCK_IP_HAS_MONITOR_INT
            case CLOCK_IP_HAS_MONITOR_INT:
            {
                IP_SCG->SPLLCSR = SCG_SPLLCSR_SPLLCM(1UL) |
                               SCG_SPLLCSR_SPLLCMRE(0UL);
            }
            break;
#endif
#ifdef CLOCK_IP_HAS_MONITOR_RESET
            case CLOCK_IP_HAS_MONITOR_RESET:
            {
                IP_SCG->SPLLCSR = SCG_SPLLCSR_SPLLCM(1UL) |
                               SCG_SPLLCSR_SPLLCMRE(1UL);
            }
            break;
#endif
            default:
                /* Invalid monitor mode */
                CLOCK_IP_DEV_ASSERT(FALSE);
                break;
        }
    }
}
void Clock_Ip_DisableSpll_TrustedCall(Clock_Ip_NameType PllName)
{
    (void)PllName;

    /* Power down PLL */

    /* Clear LK bit field */
    IP_SCG->SPLLCSR &= (~((uint32)SCG_SPLLCSR_LK_MASK));

    /* Disable clock */
    IP_SCG->SPLLCSR &= (~((uint32)SCG_SPLLCSR_SPLLEN_MASK));
}
void Clock_Ip_EnableSpll_TrustedCall(Clock_Ip_PllConfigType const* Config)
{
    /* Configure SPLL. */
    if (1U == Config->Enable)
    {
        /* Enable SPLL */
        IP_SCG->SPLLCSR |= SCG_SPLLCSR_SPLLEN(1UL);
    }
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
const Clock_Ip_PllCallbackType Clock_Ip_axPllCallbacks[CLOCK_IP_PLL_CALLBACKS_COUNT] =
{
    {
        Clock_Ip_CallbackPllEmpty,            /* Reset */
        Clock_Ip_CallbackPllEmpty,            /* Set */
        Clock_Ip_CallbackPllEmptyComplete,    /* Complete */
        Clock_Ip_CallbackPllEmpty,            /* Enable */
        Clock_Ip_CallbackPllEmptyDisable,     /* Disable */
    },
    /* System Pll */
#ifdef CLOCK_IP_SPLL_ENABLE
    {
        Clock_Ip_ResetSpll,                                                                /* Reset */
        Clock_Ip_SetSpll,                                                                  /* Set */
        Clock_Ip_CompleteSpll,                                                             /* Complete */
        Clock_Ip_EnableSpll,                                                               /* Enable */
        Clock_Ip_DisableSpll,                                                              /* Disable */
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

