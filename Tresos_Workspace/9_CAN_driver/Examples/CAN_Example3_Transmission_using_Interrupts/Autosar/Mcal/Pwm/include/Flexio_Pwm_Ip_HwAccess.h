/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm Flexio
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

#ifndef FLEXIO_PWM_IP_HWACCESS_H
#define FLEXIO_PWM_IP_HWACCESS_H

/**
*   @file Flexio_Pwm_Ip_HwAccess.h
*
*   @internal
*   @addtogroup flexio_pwm_ip FlexIO Pwm IPL
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
#include "Std_Types.h"
#include "Flexio_Pwm_Ip_Cfg.h"
#include "Flexio_Pwm_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_PWM_IP_HWACCESS_VENDOR_ID                    43
#define FLEXIO_PWM_IP_HWACCESS_MODULE_ID                    121
#define FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_PWM_IP_HWACCESS_SW_MAJOR_VERSION             2
#define FLEXIO_PWM_IP_HWACCESS_SW_MINOR_VERSION             0
#define FLEXIO_PWM_IP_HWACCESS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Flexio_Pwm_Ip_HwAccess.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and Flexio_Pwm_Ip_Cfg.h header file are of the same vendor */
#if (FLEXIO_PWM_IP_HWACCESS_VENDOR_ID != FLEXIO_PWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of Flexio_Pwm_Ip_HwAccess.h and Flexio_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Cfg.h header file are of the same AUTOSAR version */
#if ((FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != FLEXIO_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != FLEXIO_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != FLEXIO_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Flexio_Pwm_Ip_HwAccess.h and Flexio_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Cfg.h header file are of the same software version */
#if ((FLEXIO_PWM_IP_HWACCESS_SW_MAJOR_VERSION != FLEXIO_PWM_IP_CFG_SW_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_HWACCESS_SW_MINOR_VERSION != FLEXIO_PWM_IP_CFG_SW_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_HWACCESS_SW_PATCH_VERSION != FLEXIO_PWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Flexio_Pwm_Ip_HwAccess.h and Flexio_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same vendor */
#if (FLEXIO_PWM_IP_HWACCESS_VENDOR_ID != FLEXIO_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Flexio_Pwm_Ip_HwAccess.h and Flexio_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same AUTOSAR version */
#if ((FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION    != FLEXIO_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION    != FLEXIO_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION != FLEXIO_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Flexio_Pwm_Ip_HwAccess.h and Flexio_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same software version */
#if ((FLEXIO_PWM_IP_HWACCESS_SW_MAJOR_VERSION != FLEXIO_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_HWACCESS_SW_MINOR_VERSION != FLEXIO_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_HWACCESS_SW_PATCH_VERSION != FLEXIO_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Flexio_Pwm_Ip_HwAccess.h and Flexio_Pwm_Ip_Types.h are different."
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 *  @brief      Timer Pin ouput states
 *  @details    This enumeration specifies timer pin out states Flexio
 *
 *  @internal
 */
typedef enum
{
    /** @brief Timer Pin output disabled */
    FLEXIO_PWM_IP_TIMER_PIN_OUTPUT_DISABLE  = 0x00U,
    /** @brief Timer Pin Output mode */
    FLEXIO_PWM_IP_TIMER_PIN_OUTPUT_ENABLE   = 0x03U
} Flexio_Pwm_Ip_TimerPinType;

/**
 *  @brief      Timer initial states
 *  @details    This enumeration specifies timer initial output states
 *
 *  @internal
 */
typedef enum
{
    /** @brief Timer Initial output is logic one */
    FLEXIO_PWM_IP_TIMER_INIT_HIGH   = 0x00U,
    /** @brief Timer Initial output is logic zero */
    FLEXIO_PWM_IP_TIMER_INIT_LOW    = 0x1U
} Flexio_Pwm_Ip_TimerInitType;

/**
 *  @brief      Timer modes
 *  @details    This enumeration specifies timer modes for Pwm generation
 *
 *  @internal
 */
typedef enum
{
    /** @brief Timer disabled */
    FLEXIO_PWM_IP_TIMER_DISABLED  = 0x00U,
    /** @brief Timer in 8 bit Pwm High mode */
    FLEXIO_PWM_IP_TIMER_PWM_HIGH  = 0x02U,
    /** @brief Timer in 8 bit Pwm Low mode */
    FLEXIO_PWM_IP_TIMER_PWM_LOW   = 0x06U
} Flexio_Pwm_Ip_TimerModeType;


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/*========================================= PIN Register =========================================*/
/**
 *  @brief      Return logic state of the pin output
 *
 *  @param[in]  Base The Flexio Base address pointer
 *  @param[in]  Pin The Pin id for the given instance
 *
 *  @return     Logic state of the selected pin
 *
 *  @internal
 */
static inline boolean Flexio_Pwm_Ip_GetPinState(const Flexio_Pwm_Ip_HwAddrType *const Base, uint8 Pin)
{
    return (boolean)((((Base->PIN & FLEXIO_PIN_PDI_MASK) >> Pin) & 0x1U) == 0x1U)? TRUE : FALSE;
}

/*======================================= TIMSTAT Register =======================================*/
/**
 *  @brief      Return if the flag event occurred on one timer
 *
 *  @param[in]  Base    The Flexio Base address pointer
 *  @param[in]  Timer   The Timer id for the given instance
 *
 *  @return     Value of the flag for selected timer
 *
 *  @internal
 */
static inline boolean Flexio_Pwm_Ip_GetTimerFlag(const Flexio_Pwm_Ip_HwAddrType *const Base, uint8 Timer)
{
    return (boolean)((((Base->PIN & FLEXIO_TIMSTAT_TSF_MASK) >> Timer) & 0x1U) == 0x1U)? TRUE : FALSE;
}
/*======================================= TIMCTLn Register =======================================*/
/**
 *  @brief      Enable/Disable the pin out for the selected timer
 *
 *  @param[in]  Base        The Flexio Base address pointer
 *  @param[in]  Timer       The Timer id for the given instance
 *  @param[in]  PinMode     The Timer Pin output mode
 *
 *  @return     void
 *
 *  @internal
 */
static inline void Flexio_Pwm_Ip_SetTimerPinOutput(Flexio_Pwm_Ip_HwAddrType * Base, uint8 Timer, Flexio_Pwm_Ip_TimerPinType PinMode)
{
    Base->TIMCTL[Timer] = (Base->TIMCTL[Timer] & ~FLEXIO_TIMCTL_PINCFG_MASK) | FLEXIO_TIMCTL_PINCFG(PinMode);
}

/**
 *  @brief      Select the pin that the selected timer will ouput the signal
 *
 *  @param[in]  Base    The Flexio Base address pointer
 *  @param[in]  Timer   The Timer id for the given instance
 *  @param[in]  Pin     The Pin id used to output pwm signal
 *
 *  @return     void
 *
 *  @internal
 */
static inline void Flexio_Pwm_Ip_SetTimerPin(Flexio_Pwm_Ip_HwAddrType * Base, uint8 Timer, uint8 Pin)
{
    Base->TIMCTL[Timer] = (Base->TIMCTL[Timer] & ~FLEXIO_TIMCTL_PINSEL_MASK) | FLEXIO_TIMCTL_PINSEL(Pin);
}

#if (defined(FLEXIO_PWM_IP_HAS_LOW_MODE) && (FLEXIO_PWM_IP_HAS_LOW_MODE == STD_ON))
/**
 *  @brief      Select the pin polarity
 *
 *  @param[in]  Base        The Flexio Base address pointer
 *  @param[in]  Timer       The Timer id for the given instance
 *  @param[in]  Polarity    The Pin polarity type
 *
 *  @return     void
 *
 *  @internal
 */
static inline void Flexio_Pwm_Ip_SetTimerPinPolarity(Flexio_Pwm_Ip_HwAddrType * Base, uint8 Timer, Flexio_Pwm_Ip_PolarityType Polarity)
{
    Base->TIMCTL[Timer] = (Base->TIMCTL[Timer] & ~FLEXIO_TIMCTL_PINPOL_MASK) | FLEXIO_TIMCTL_PINPOL(Polarity);
}
#endif

/**
 *  @brief      Select the timer mode used for pwm generation
 *
 *  @param[in]  Base        The Flexio Base address pointer
 *  @param[in]  Timer       The Timer id for the given instance
 *  @param[in]  TimerMode   The mode of used timer 
 *
 *  @return     void
 *
 *  @internal
 */
static inline void Flexio_Pwm_Ip_SetTimerMode(Flexio_Pwm_Ip_HwAddrType * Base, uint8 Timer, Flexio_Pwm_Ip_TimerModeType TimerMode)
{
    Base->TIMCTL[Timer] = (Base->TIMCTL[Timer] & ~FLEXIO_TIMCTL_TIMOD_MASK) | FLEXIO_TIMCTL_TIMOD(TimerMode);
}

/*======================================= TIMCFGn Register =======================================*/
/**
 *  @brief      Select the timer initial state
 *
 *  @param[in]  Base            The Flexio Base address pointer
 *  @param[in]  Timer           The Timer id for the given instance
 *  @param[in]  TimerInitOut    The Timer initial ouput value
 *
 *  @return     void
 *
 *  @internal
 */
static inline void Flexio_Pwm_Ip_SetTimerInitMode(Flexio_Pwm_Ip_HwAddrType * Base, uint8 Timer, Flexio_Pwm_Ip_TimerInitType TimerInitOut)
{
    Base->TIMCFG[Timer] = (Base->TIMCFG[Timer] & ~FLEXIO_TIMCFG_TIMOUT_MASK) | FLEXIO_TIMCFG_TIMOUT(TimerInitOut);
}
/*======================================= TIMCMPn Register =======================================*/
/**
 *  @brief      Set the upper 8 bit value for timer comparator
 *
 *  @param[in]  Base    The Flexio Base address pointer
 *  @param[in]  Timer   The Timer id for the given instance
 *  @param[in]  Value   The value of the upper 8 bits of timer comparator
 *
 *  @return     void
 *
 *  @internal
 */
static inline void Flexio_Pwm_Ip_SetUpperValue(Flexio_Pwm_Ip_HwAddrType * Base, uint8 Timer, uint8 Value)
{
    Base->TIMCMP[Timer] = (Base->TIMCMP[Timer] & ~FLEXIO_PWM_IP_TIMCMP_CMP_UPPER_MASK)
                        | FLEXIO_PWM_IP_TIMCMP_CMP_UPPER(Value);
}

/**
 *  @brief      Set the lower 8 bit value for timer comparator
 *
 *  @param[in]  Base    The Flexio Base address pointer
 *  @param[in]  Timer   The Timer id for the given instance
 *  @param[in]  Value   The value of the lower 8 bits of timer comparator
 *
 *  @return     void
 *
 *  @internal
 */
static inline void Flexio_Pwm_Ip_SetLowerValue(Flexio_Pwm_Ip_HwAddrType * Base, uint8 Timer, uint8 Value)
{
    Base->TIMCMP[Timer] = (Base->TIMCMP[Timer] & ~FLEXIO_PWM_IP_TIMCMP_CMP_LOWER_MASK)
                        | FLEXIO_PWM_IP_TIMCMP_CMP_LOWER(Value);
}

/**
 *  @brief      Get the upper 8 bit value for timer comparator
 *
 *  @param[in]  Base     The Flexio Base address pointer
 *  @param[in]  Timer    The Timer id for the given instance
 *
 *  @return     The value of the upper 8 bits of timer comparator
 *
 *  @internal
 */
static inline uint8 Flexio_Pwm_Ip_GetUpperValue(const Flexio_Pwm_Ip_HwAddrType *const Base, uint8 Timer)
{
    return (uint8)(((uint32)Base->TIMCMP[Timer] & FLEXIO_PWM_IP_TIMCMP_CMP_UPPER_MASK) >> FLEXIO_PWM_IP_TIMCMP_CMP_UPPER_SHIFT);
}

/**
 *  @brief      Get the lower 8 bit value for timer comparator
 *
 *  @param[in]  Base     The Flexio Base address pointer
 *  @param[in]  Timer    The Timer id for the given instance
 *
 *  @return     The value of the lower 8 bits of timer comparator
 *
 *  @internal
 */
static inline uint8 Flexio_Pwm_Ip_GetLowerValue(const Flexio_Pwm_Ip_HwAddrType *const Base, uint8 Timer)
{
    return (uint8)(((uint32)Base->TIMCMP[Timer] & FLEXIO_PWM_IP_TIMCMP_CMP_LOWER_MASK) >> FLEXIO_PWM_IP_TIMCMP_CMP_LOWER_SHIFT);
}

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_PWM_IP_HWACCESS_H */
