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

#ifndef FLEXIO_PWM_IP_H
#define FLEXIO_PWM_IP_H

/**
*   @file Flexio_Pwm_Ip.h
*
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
#define FLEXIO_PWM_IP_VENDOR_ID                    43
#define FLEXIO_PWM_IP_MODULE_ID                    121
#define FLEXIO_PWM_IP_AR_RELEASE_MAJOR_VERSION     4
#define FLEXIO_PWM_IP_AR_RELEASE_MINOR_VERSION     7
#define FLEXIO_PWM_IP_AR_RELEASE_REVISION_VERSION  0
#define FLEXIO_PWM_IP_SW_MAJOR_VERSION             2
#define FLEXIO_PWM_IP_SW_MINOR_VERSION             0
#define FLEXIO_PWM_IP_SW_PATCH_VERSION             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Std_Types.h are of the same AUTOSAR version */
    #if ((FLEXIO_PWM_IP_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXIO_PWM_IP_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR Version Numbers of Flexio_Pwm_Ip.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and Flexio_Pwm_Ip_Cfg.h header file are of the same vendor */
#if (FLEXIO_PWM_IP_VENDOR_ID != FLEXIO_PWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of Flexio_Pwm_Ip.h and Flexio_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Cfg.h header file are of the same AUTOSAR version */
#if ((FLEXIO_PWM_IP_AR_RELEASE_MAJOR_VERSION    != FLEXIO_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_AR_RELEASE_MINOR_VERSION    != FLEXIO_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_AR_RELEASE_REVISION_VERSION != FLEXIO_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Flexio_Pwm_Ip.h and Flexio_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Cfg.h header file are of the same software version */
#if ((FLEXIO_PWM_IP_SW_MAJOR_VERSION != FLEXIO_PWM_IP_CFG_SW_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_SW_MINOR_VERSION != FLEXIO_PWM_IP_CFG_SW_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_SW_PATCH_VERSION != FLEXIO_PWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Flexio_Pwm_Ip.h and Flexio_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same vendor */
#if (FLEXIO_PWM_IP_VENDOR_ID != FLEXIO_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Flexio_Pwm_Ip.h and Flexio_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same AUTOSAR version */
#if ((FLEXIO_PWM_IP_AR_RELEASE_MAJOR_VERSION    != FLEXIO_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_AR_RELEASE_MINOR_VERSION    != FLEXIO_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_AR_RELEASE_REVISION_VERSION != FLEXIO_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Flexio_Pwm_Ip.h and Flexio_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Flexio_Pwm_Ip_Types.h header file are of the same software version */
#if ((FLEXIO_PWM_IP_SW_MAJOR_VERSION != FLEXIO_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_SW_MINOR_VERSION != FLEXIO_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_SW_PATCH_VERSION != FLEXIO_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Flexio_Pwm_Ip.h and Flexio_Pwm_Ip_Types.h are different."
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

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
/**
 * @brief Initialize a flexio channel in pwm mode.
 * @details The function will initialize one timer and pin of the selected flexio channel in pwm
 * mode, with the configuration of the user. The interrupts will be disabled.
 *
 * @param[in] InstanceId   The Flexio instance id
 * @param[in] UserCfg      The channel configuration for the selected Flexio instance
 * @return FLEXIO_PWM_IP_STATUS_SUCCESS - if the initialization was successfull
 */
Flexio_Pwm_Ip_StatusType Flexio_Pwm_Ip_InitChannel(uint8 InstanceId, const Flexio_Pwm_Ip_ChannelConfigType * const UserCfg);

/**
 * @brief Deinitialize a flexio channel.
 * @details The function will reset the timer and pin of the selected flexio channel.
 *
 * @param[in] InstanceId    The Flexio instance id
 * @param[in] Channel       The channel id for the selected Flexio instance
 * @return FLEXIO_PWM_IP_STATUS_SUCCESS - if the deinitialization was successfull
 */
Flexio_Pwm_Ip_StatusType Flexio_Pwm_Ip_DeInitChannel(uint8 InstanceId, uint8 Channel);



/**
 * @brief Set a new value for duty cycle and period of the channel.
 * @details The function will update the selected flexio channel with the new values for the
 * duty cycle and period.
 *
 * @param[in] InstanceId    The Flexio instance id
 * @param[in] Channel       The channel id for the selected Flexio instance
 * @param[in] Period        The new value for the period
 * @param[in] DutyCycle     The new value for the duty cycle
 * @return FLEXIO_PWM_IP_STATUS_SUCCESS - if the initialization was successfull
 */
Flexio_Pwm_Ip_StatusType Flexio_Pwm_Ip_UpdatePeriodDuty(uint8 InstanceId, uint8 Channel, uint16 Period, uint16 DutyCycle);

/**
 * @brief Get the logic level of the channel ouput.
 * @details The function will return the logic level that the selected flexio channel is driving on
 * on the output pin.
 *
 * @param[in] InstanceId    The Flexio instance id
 * @param[in] Channel       The channel id for the selected Flexio instance
 * @return FLEXIO_PWM_IP_STATUS_SUCCESS - if the initialization was successfull
 */
boolean Flexio_Pwm_Ip_GetOutputState(uint8 InstanceId, uint8 Channel);

/**
 * @brief Update the interrupt mode for a channel.
 * @details The function will set a new mode for the flag event response on the selected channel.
 *
 * @param[in] InstanceId    The Flexio instance id
 * @param[in] Channel       The channel id for the selected Flexio instance
 * @param[in] IrqMode       The new irq mode for the channel
 * @return FLEXIO_PWM_IP_STATUS_SUCCESS - if the initialization was successfull
 */
Flexio_Pwm_Ip_StatusType Flexio_Pwm_Ip_UpdateInterruptMode(uint8 InstanceId, uint8 Channel, Flexio_Pwm_Ip_InterruptType IrqMode);

/**
 * @brief Getting the period for a channel.
 * @details The function will get the period on the selected channel.
 *
 * @param[in] InstanceId    The Flexio instance id
 * @param[in] Channel       The channel id for the selected Flexio instance

 * @return uint16
 */
uint16 Flexio_Pwm_Ip_GetPeriod(uint8 InstanceId, uint8 Channel);

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FLEXIO_PWM_IP_H */
