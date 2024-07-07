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
*   @file       Clock_Ip_ExtOsc.c
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
#define CLOCK_IP_EXTOSC_VENDOR_ID_C                      43
#define CLOCK_IP_EXTOSC_AR_RELEASE_MAJOR_VERSION_C       4
#define CLOCK_IP_EXTOSC_AR_RELEASE_MINOR_VERSION_C       7
#define CLOCK_IP_EXTOSC_AR_RELEASE_REVISION_VERSION_C    0
#define CLOCK_IP_EXTOSC_SW_MAJOR_VERSION_C               2
#define CLOCK_IP_EXTOSC_SW_MINOR_VERSION_C               0
#define CLOCK_IP_EXTOSC_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Clock_Ip_ExtOsc.c file and Clock_Ip_Private.h file are of the same vendor */
#if (CLOCK_IP_EXTOSC_VENDOR_ID_C != CLOCK_IP_PRIVATE_VENDOR_ID)
    #error "Clock_Ip_ExtOsc.c and Clock_Ip_Private.h have different vendor ids"
#endif

/* Check if Clock_Ip_ExtOsc.c file and Clock_Ip_Private.h file are of the same Autosar version */
#if ((CLOCK_IP_EXTOSC_AR_RELEASE_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (CLOCK_IP_EXTOSC_AR_RELEASE_MINOR_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (CLOCK_IP_EXTOSC_AR_RELEASE_REVISION_VERSION_C != CLOCK_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Clock_Ip_ExtOsc.c and Clock_Ip_Private.h are different"
#endif

/* Check if Clock_Ip_ExtOsc.c file and Clock_Ip_Private.h file are of the same Software version */
#if ((CLOCK_IP_EXTOSC_SW_MAJOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (CLOCK_IP_EXTOSC_SW_MINOR_VERSION_C != CLOCK_IP_PRIVATE_SW_MINOR_VERSION) || \
     (CLOCK_IP_EXTOSC_SW_PATCH_VERSION_C != CLOCK_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Clock_Ip_ExtOsc.c and Clock_Ip_Private.h are different"
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



/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

static void Clock_Ip_ExternalOscillatorEmpty(Clock_Ip_XoscConfigType const* Config);
static void Clock_Ip_DisableClockIpExternalOscillatorEmpty(Clock_Ip_NameType XoscName);

#ifdef CLOCK_IP_SOSC_ENABLE
void Clock_Ip_ResetSOSC_TrustedCall(Clock_Ip_XoscConfigType const* Config);
void Clock_Ip_SetSOSC_TrustedCall(Clock_Ip_XoscConfigType const* Config);
void Clock_Ip_DisableSOSC_TrustedCall(Clock_Ip_NameType XoscName);
void Clock_Ip_EnableSOSC_TrustedCall(Clock_Ip_XoscConfigType const* Config);
#endif
static void Clock_Ip_ExternalOscillatorEmpty(Clock_Ip_XoscConfigType const* Config);




/* Clock stop section code */
#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"
/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/* Clock start section code */
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

static void Clock_Ip_ExternalOscillatorEmpty(Clock_Ip_XoscConfigType const* Config)
{
    (void)Config;
    /* No implementation */
}
static void Clock_Ip_DisableClockIpExternalOscillatorEmpty(Clock_Ip_NameType XoscName)
{
    (void)XoscName;
    /* No implementation */
}




#ifdef CLOCK_IP_SOSC_ENABLE
static void Clock_Ip_ResetSOSC(Clock_Ip_XoscConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_ResetSOSC_TrustedCall,(Config));
      #else
        Clock_Ip_ResetSOSC_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
static void Clock_Ip_SetSOSC(Clock_Ip_XoscConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_SetSOSC_TrustedCall,(Config));
      #else
        Clock_Ip_SetSOSC_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */

    #ifdef CLOCK_IP_GET_FREQUENCY_API
    #if (CLOCK_IP_GET_FREQUENCY_API == STD_ON)
        Clock_Ip_SetExternalOscillatorFrequency(Config->Name,Config->Freq);
    #endif
    #endif
    }
}
static void Clock_Ip_CompleteSOSC(Clock_Ip_XoscConfigType const* Config)
{
    boolean TimeoutOccurred = FALSE;
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    uint32 SoscStatus;

    if (NULL_PTR != Config)
    {
        /* Configure SOSC. */
        if ((IP_SCG->SOSCCSR & SCG_SOSCCSR_SOSCEN_MASK) != 0U)
        {
            Clock_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, CLOCK_IP_TIMEOUT_VALUE_US);
            /* Wait until ircosc is locked */
            do
            {
                SoscStatus = (((IP_SCG->SOSCCSR & SCG_SOSCCSR_SOSCVLD_MASK) >> SCG_SOSCCSR_SOSCVLD_SHIFT));
                TimeoutOccurred = Clock_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
            }
            while ((0U == SoscStatus) && (FALSE == TimeoutOccurred));

            if (FALSE != TimeoutOccurred)
            {
                /* Report timeout error */
                Clock_Ip_ReportClockErrors(CLOCK_IP_REPORT_TIMEOUT_ERROR, Config->Name);
            }
        }
    }
    else
    {
        (void)TimeoutOccurred;
        (void)StartTime;
        (void)ElapsedTime;
        (void)TimeoutTicks;
        (void)SoscStatus;
    }
}
static void Clock_Ip_DisableSOSC(Clock_Ip_NameType XoscName)
{
#ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
    OsIf_Trusted_Call1param(Clock_Ip_DisableSOSC_TrustedCall,(XoscName));
  #else
    Clock_Ip_DisableSOSC_TrustedCall(XoscName);
  #endif
#endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
}
static void Clock_Ip_EnableSOSC(Clock_Ip_XoscConfigType const* Config)
{
    if (NULL_PTR != Config)
    {
    #ifdef CLOCK_IP_ENABLE_USER_MODE_SUPPORT
      #if (STD_ON == CLOCK_IP_ENABLE_USER_MODE_SUPPORT)
        OsIf_Trusted_Call1param(Clock_Ip_EnableSOSC_TrustedCall,(Config));
      #else
        Clock_Ip_EnableSOSC_TrustedCall(Config);
      #endif
    #endif /* CLOCK_IP_ENABLE_USER_MODE_SUPPORT */
    }
}
#endif


/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef CLOCK_IP_SOSC_ENABLE
void Clock_Ip_ResetSOSC_TrustedCall(Clock_Ip_XoscConfigType const* Config)
{
    (void)Config;

    /* Clear LK bit field */
    IP_SCG->SOSCCSR &= (~((uint32)SCG_SOSCCSR_LK_MASK));

    /* Disable clock monitor */
    IP_SCG->SOSCCSR &= (~((uint32)SCG_SOSCCSR_SOSCCM_MASK));

    /* Disable clock monitor reset*/
    IP_SCG->SOSCCSR &= (~((uint32)SCG_SOSCCSR_SOSCCMRE_MASK));

    /* Disable clock */
    IP_SCG->SOSCCSR &= (~((uint32)SCG_SOSCCSR_SOSCEN_MASK));
}
void Clock_Ip_SetSOSC_TrustedCall(Clock_Ip_XoscConfigType const* Config)
{
    /* Configure SOSC. */
    if (1U == Config->Enable)
    {
#ifdef CLOCK_IP_GET_FREQUENCY_API
#if (CLOCK_IP_GET_FREQUENCY_API == STD_ON)
        Clock_Ip_SetExternalOscillatorFrequency(Config->Name,Config->Freq);
#endif
#endif
        switch(Config->Gain)
        {
#ifdef CLOCK_IP_HAS_LOW_GAIN
            case CLOCK_IP_HAS_LOW_GAIN:
            {
                /* Set gain value. */
                IP_SCG->SOSCCFG &= ~SCG_SOSCCFG_HGO_MASK;
            }
            break;
#endif
#ifdef CLOCK_IP_HAS_HIGH_GAIN
            case CLOCK_IP_HAS_HIGH_GAIN:
            {
                /* Set gain value. */
                IP_SCG->SOSCCFG |= SCG_SOSCCFG_HGO_MASK;
            }
            break;
#endif
            default:
            {
                /* Invalid configuration element */
                CLOCK_IP_DEV_ASSERT(FALSE);
            }
            break;
        }


        IP_SCG->SOSCCFG &= ~SCG_SOSCCFG_RANGE_MASK;

        if ((Config->Freq >= 4000000U) && (Config->Freq < 8000000U))
        {
            IP_SCG->SOSCCFG |= SCG_SOSCCFG_RANGE(2U);
        }
        else
        {
            IP_SCG->SOSCCFG |= SCG_SOSCCFG_RANGE(3U);
        }

        if (0U == Config->BypassOption)
        {
            IP_SCG->SOSCCFG |= SCG_SOSCCFG_EREFS_MASK;
        }
        else
        {
            IP_SCG->SOSCCFG &= ~SCG_SOSCCFG_EREFS_MASK;
        }


        /* Enable clock, configure monitor, lock register. */
        switch (Config->Monitor)
        {
#ifdef CLOCK_IP_HAS_MONITOR_DISABLE
            case CLOCK_IP_HAS_MONITOR_DISABLE:
            {
                IP_SCG->SOSCCSR = SCG_SOSCCSR_SOSCEN(1UL) |
                               SCG_SOSCCSR_SOSCCM(0UL) |
                               SCG_SOSCCSR_SOSCCMRE(0UL);
            }
            break;
#endif
#ifdef CLOCK_IP_HAS_MONITOR_INT
            case CLOCK_IP_HAS_MONITOR_INT:
            {
                IP_SCG->SOSCCSR = SCG_SOSCCSR_SOSCEN(1UL) |
                               SCG_SOSCCSR_SOSCCM(1UL) |
                               SCG_SOSCCSR_SOSCCMRE(0UL);
            }
            break;
#endif
#ifdef CLOCK_IP_HAS_MONITOR_RESET
            case CLOCK_IP_HAS_MONITOR_RESET:
            {
                IP_SCG->SOSCCSR = SCG_SOSCCSR_SOSCEN(1UL) |
                               SCG_SOSCCSR_SOSCCM(1UL) |
                               SCG_SOSCCSR_SOSCCMRE(1UL);
            }
            break;
#endif
            default:
                /* Enable SOSC. */
                IP_SCG->SOSCCSR |= SCG_SOSCCSR_SOSCEN_MASK;

                /* Invalid monitor mode */
                CLOCK_IP_DEV_ASSERT(FALSE);
                break;
        }
    }
}

void Clock_Ip_DisableSOSC_TrustedCall(Clock_Ip_NameType XoscName)
{
    (void)XoscName;

    /* Disable SOSC. */
    IP_SCG->SOSCCSR &= ~SCG_SOSCCSR_SOSCEN_MASK;
}

void Clock_Ip_EnableSOSC_TrustedCall(Clock_Ip_XoscConfigType const* Config)
{
    if (1U == Config->Enable)
    {
        /* Enable SOSC. */
        IP_SCG->SOSCCSR |= SCG_SOSCCSR_SOSCEN_MASK;
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

const Clock_Ip_ExtOscCallbackType Clock_Ip_axExtOscCallbacks[CLOCK_IP_XOSC_CALLBACKS_COUNT] =
{
    {
        Clock_Ip_ExternalOscillatorEmpty,        /* Reset */
        Clock_Ip_ExternalOscillatorEmpty,        /* Set */
        Clock_Ip_ExternalOscillatorEmpty,        /* Complete */
        Clock_Ip_DisableClockIpExternalOscillatorEmpty, /* Disable */
        Clock_Ip_ExternalOscillatorEmpty,        /* Enable */
    },
#ifdef CLOCK_IP_SOSC_ENABLE
    {
        Clock_Ip_ResetSOSC,                          /* Reset */
        Clock_Ip_SetSOSC,                            /* Set */
        Clock_Ip_CompleteSOSC,                       /* Complete */
        Clock_Ip_DisableSOSC,                        /* Disable */
        Clock_Ip_EnableSOSC,                         /* Enable */
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
