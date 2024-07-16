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

#ifndef FLEXIO_PWM_IP_TYPES_H
#define FLEXIO_PWM_IP_TYPES_H

/**
*   @file Flexio_Pwm_Ip_Types.h
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
#include "Flexio_Pwm_Ip_CfgDefines.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_PWM_IP_TYPES_VENDOR_ID                    43
#define FLEXIO_PWM_IP_TYPES_MODULE_ID                    121
#define FLEXIO_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_PWM_IP_TYPES_SW_MAJOR_VERSION             2
#define FLEXIO_PWM_IP_TYPES_SW_MINOR_VERSION             0
#define FLEXIO_PWM_IP_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((FLEXIO_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Flexio_Pwm_Ip_Types.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and Flexio_Pwm_Ip_Cfg.h header file are of the same vendor */
#if (FLEXIO_PWM_IP_TYPES_VENDOR_ID != FLEXIO_PWM_IP_CFGDEFINES_VENDOR_ID)
    #error "Vendor IDs of Flexio_Pwm_Ip_Types.h and Flexio_Pwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Cfg.h header file are of the same AUTOSAR version */
#if ((FLEXIO_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION    != FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION    != FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION != FLEXIO_PWM_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Flexio_Pwm_Ip_Types.h and Flexio_Pwm_Ip_CfgDefines.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Cfg.h header file are of the same software version */
#if ((FLEXIO_PWM_IP_TYPES_SW_MAJOR_VERSION != FLEXIO_PWM_IP_CFGDEFINES_SW_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_TYPES_SW_MINOR_VERSION != FLEXIO_PWM_IP_CFGDEFINES_SW_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_TYPES_SW_PATCH_VERSION != FLEXIO_PWM_IP_CFGDEFINES_SW_PATCH_VERSION))
    #error "Software version numbers of Flexio_Pwm_Ip_Types.h and Flexio_Pwm_Ip_CfgDefines.h are different."
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
/**
 * @brief       Status return codes.
 * @details     Common error codes will be a unified enumeration (C enum) that will contain all error codes
 *              (common and specific). There will be separate "error values spaces" (or slots), each of 256
 *              positions, allocated per functionality.
 *
 * @internal
 */
typedef enum
{
    /* Generic error codes */
    /** @brief Generic operation success status */
    FLEXIO_PWM_IP_STATUS_SUCCESS                         = E_OK,
    /** @brief Generic operation failure status */
    FLEXIO_PWM_IP_STATUS_ERROR                           = E_NOT_OK,
    /** @brief Generic operation busy status */
    FLEXIO_PWM_IP_STATUS_BUSY                            = 0x002U,
    /** @brief Generic operation timeout status */
    FLEXIO_PWM_IP_STATUS_TIMEOUT                         = 0x003U,
    /** @brief Generic operation unsupported status */
    FLEXIO_PWM_IP_STATUS_UNSUPPORTED                     = 0x004U,

    /* FLEXIO specific error codes */
    /** @brief FLEXIO unsuccessful attempt at acquiring the timer and pin. */
    FLEXIO_PWM_IP_WRONG_TIMER_PIN                       = 0xC00U,
    /** @brief FLEXIO wrong period for given duty cycle. */
    FLEXIO_PWM_IP_WRONG_PERIOD_DUTY                       = 0xC01U,
} Flexio_Pwm_Ip_StatusType;

#if (defined(FLEXIO_PWM_IP_HAS_LOW_MODE) && (FLEXIO_PWM_IP_HAS_LOW_MODE == STD_ON))
/**
 * @brief    PWM output polarity
 * @details  This enumeration specifies what value has the output pin when signal is active
 *
 * @internal
 */
typedef enum
{
    FLEXIO_PWM_IP_ACTIVE_HIGH   = 0x0U,
    FLEXIO_PWM_IP_ACTIVE_LOW    = 0x1U
} Flexio_Pwm_Ip_PolarityType;
#endif

/**
 * @brief       Interrupt types enabled for the channel
 * @details     This enumeration specifies interrupt type of Flexio
 *
 * @internal
 */
typedef enum
{
    /** @brief Interrupt requests are disabled */
    FLEXIO_PWM_IP_IRQ_DISABLED          = 0x00U,
    /** @brief Interrupt requests are generated on pin rising edge */
    FLEXIO_PWM_IP_IRQ_ON_RISING_EDGE    = 0x01U,
    /** @brief Interrupt requests are generated on pin falling edge */
    FLEXIO_PWM_IP_IRQ_ON_FALLING_EDGE   = 0x02U,
    /** @brief Interrupt requests are generated on pin both edge */
    FLEXIO_PWM_IP_IRQ_ON_BOTH_EDGES     = 0x03U,
    /** @brief Interrupt requests are generated on timer period end */
    FLEXIO_PWM_IP_IRQ_ON_PERIOD_END     = 0x04U
} Flexio_Pwm_Ip_InterruptType;

/**
 * @brief       Interrupt types enabled for the channel
 * @details     This enumeration specifies interrupt type of Flexio
 *
 * @internal
 */
typedef enum
{
    /** @brief Timer flag generated the interrupt */
    FLEXIO_PWM_IP_TIMER_IRQ,
    /** @brief Pin rising edge flag generated the interrupt */
    FLEXIO_PWM_IP_PIN_RISING_EDGE_IRQ,
    /** @brief Pin rising edge generated the interrupt */
    FLEXIO_PWM_IP_PIN_FALLING_EDGE_IRQ
} Flexio_Pwm_Ip_OccurredIRQType;

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief       Notification function callback type for IPL.
 *
 * @internal
 */
typedef void (* Flexio_Pwm_Ip_IplCallbackType)(Flexio_Pwm_Ip_OccurredIRQType IrqType, void * Param);
/**
 * @brief       Notification function callback type for HLD.
 *
 * @internal
 */
typedef void (* Flexio_Pwm_Ip_HldCallbackType)(uint8 Channel);

/**
 * @brief       Structure for notification
 * @details     The structure used to notification
 *
 * @internal
 */
typedef struct
{
    /** @brief Callback function pointer */
    Flexio_Pwm_Ip_IplCallbackType       CbFunction;
    /** @brief Callback function parameter pointer */
    void                          * CbParameter;
} Flexio_Pwm_Ip_IplNotificationType;

/**
 * @brief       Structure for notification
 * @details     The structure used to notification
 *
 * @internal
 */
typedef struct
{
    /** @brief Callback function pointer */
    Flexio_Pwm_Ip_HldCallbackType       CbFunction;
    /** @brief Callback function parameter pointer */
    uint8                              CbParameter;
} Flexio_Pwm_Ip_HldNotificationType;

/**
 * @brief     PWM configuration parameters structure
 * @details   Flexio IP specific channel configuration structure type
 *
 * @internal
 */
typedef struct
{
    /** @brief Flexio used timer index */
    uint8 TimerId;
    /** @brief Flexio used pin index */
    uint8 PinId;
    /** @brief Pwm period in ticks */
    uint16 Period;
    /** @brief Pwm duty cycle in ticks */
    uint16 DutyCycle;
#if (defined(FLEXIO_PWM_IP_HAS_LOW_MODE) && (FLEXIO_PWM_IP_HAS_LOW_MODE == STD_ON))
    /** @brief Pwm output polarity */
    Flexio_Pwm_Ip_PolarityType Polarity;
#endif
    /** @brief Interrupt mode */
    Flexio_Pwm_Ip_InterruptType IrqMode;
    /** @brief User notification callback for IPL*/
    Flexio_Pwm_Ip_IplNotificationType IplCallback;
    /** @brief User notification callback for HLD*/
    Flexio_Pwm_Ip_HldNotificationType HldCallback;
} Flexio_Pwm_Ip_ChannelConfigType;


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_PWM_IP_TYPES_H */
