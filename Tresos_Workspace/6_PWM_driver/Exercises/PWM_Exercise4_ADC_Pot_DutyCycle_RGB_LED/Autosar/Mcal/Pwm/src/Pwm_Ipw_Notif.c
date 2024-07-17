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

/**
*   @file Pwm_Ipw_Notif.c
*
*   @addtogroup pwm_ipw_irq FlexIO Pwm IPL
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
#include "Pwm_Notif.h"
#include "Pwm_Ipw_Notif.h"
#include "Pwm_Ipw_Cfg.h"
#include "Flexio_Pwm_Ip_Types.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PWM_IPW_NOTIF_VENDOR_ID_C                      43
#define PWM_IPW_NOTIF_AR_RELEASE_MAJOR_VERSION_C       4
#define PWM_IPW_NOTIF_AR_RELEASE_MINOR_VERSION_C       7
#define PWM_IPW_NOTIF_AR_RELEASE_REVISION_VERSION_C    0
#define PWM_IPW_NOTIF_SW_MAJOR_VERSION_C               2
#define PWM_IPW_NOTIF_SW_MINOR_VERSION_C               0
#define PWM_IPW_NOTIF_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Pwm_Notif.h file are of the same vendor */
#if (PWM_IPW_NOTIF_VENDOR_ID_C != PWM_NOTIF_VENDOR_ID)
    #error "Vendor IDs of Pwm_Ipw_Notif.c and Pwm_Notif.h are different."
#endif

/* Check if source file and Pwm_Notif.h file are of the same AUTOSAR version */
#if ((PWM_IPW_NOTIF_AR_RELEASE_MAJOR_VERSION_C    != PWM_NOTIF_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_NOTIF_AR_RELEASE_MINOR_VERSION_C    != PWM_NOTIF_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_NOTIF_AR_RELEASE_REVISION_VERSION_C != PWM_NOTIF_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw_Notif.c and Pwm_Notif.h are different."
#endif

/* Check if source file and Pwm_Notif.h file are of the same Software version */
#if ((PWM_IPW_NOTIF_SW_MAJOR_VERSION_C != PWM_NOTIF_SW_MAJOR_VERSION)  || \
     (PWM_IPW_NOTIF_SW_MINOR_VERSION_C != PWM_NOTIF_SW_MINOR_VERSION)  || \
     (PWM_IPW_NOTIF_SW_PATCH_VERSION_C != PWM_NOTIF_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw_Notif.c and Pwm_Notif.h are different."
#endif

/* Check if source file and Pwm_Ipw_Notif.h file are of the same vendor */
#if (PWM_IPW_NOTIF_VENDOR_ID_C != PWM_IPW_NOTIF_VENDOR_ID)
    #error "Vendor IDs of Pwm_Ipw_Notif.c and Pwm_Ipw_Notif.h are different."
#endif

/* Check if source file and Pwm_Ipw_Notif.h file are of the same AUTOSAR version */
#if ((PWM_IPW_NOTIF_AR_RELEASE_MAJOR_VERSION_C    != PWM_IPW_NOTIF_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_NOTIF_AR_RELEASE_MINOR_VERSION_C    != PWM_IPW_NOTIF_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_NOTIF_AR_RELEASE_REVISION_VERSION_C != PWM_IPW_NOTIF_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw_Notif.c and Pwm_Ipw_Notif.h are different."
#endif

/* Check if source file and Pwm_Ipw_Notif.h file are of the same Software version */
#if ((PWM_IPW_NOTIF_SW_MAJOR_VERSION_C != PWM_IPW_NOTIF_SW_MAJOR_VERSION)  || \
     (PWM_IPW_NOTIF_SW_MINOR_VERSION_C != PWM_IPW_NOTIF_SW_MINOR_VERSION)  || \
     (PWM_IPW_NOTIF_SW_PATCH_VERSION_C != PWM_IPW_NOTIF_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw_Notif.c and Pwm_Ipw_Notif.h are different."
#endif

/* Check if source file and Pwm_Ipw_Cfg.h file are of the same vendor */
#if (PWM_IPW_NOTIF_VENDOR_ID_C != PWM_IPW_CFG_VENDOR_ID)
    #error "Vendor IDs of Pwm_Ipw_Notif.c and Pwm_Ipw_Cfg.h are different."
#endif

/* Check if source file and Pwm_Ipw_Cfg.h file are of the same AUTOSAR version */
#if ((PWM_IPW_NOTIF_AR_RELEASE_MAJOR_VERSION_C    != PWM_IPW_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_NOTIF_AR_RELEASE_MINOR_VERSION_C    != PWM_IPW_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_NOTIF_AR_RELEASE_REVISION_VERSION_C != PWM_IPW_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw_Notif.c and Pwm_Ipw_Cfg.h are different."
#endif

/* Check if source file and Pwm_Ipw_Cfg.h file are of the same Software version */
#if ((PWM_IPW_NOTIF_SW_MAJOR_VERSION_C != PWM_IPW_CFG_SW_MAJOR_VERSION)  || \
     (PWM_IPW_NOTIF_SW_MINOR_VERSION_C != PWM_IPW_CFG_SW_MINOR_VERSION)  || \
     (PWM_IPW_NOTIF_SW_PATCH_VERSION_C != PWM_IPW_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw_Notif.c and Pwm_Ipw_Cfg.h are different."
#endif

/* Check if source file and Pwm_Ipw_Notif.h file are of the same vendor */
#if (PWM_IPW_NOTIF_VENDOR_ID_C != FLEXIO_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Pwm_Ipw_Notif.c and Flexio_Pwm_Ip_Types.h are different."
#endif

/* Check if source file and Pwm_Ipw_Notif.h file are of the same AUTOSAR version */
#if ((PWM_IPW_NOTIF_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_NOTIF_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_NOTIF_AR_RELEASE_REVISION_VERSION_C != FLEXIO_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Pwm_Ipw_Notif.c and Flexio_Pwm_Ip_Types.h are different."
#endif

/* Check if source file and Pwm_Ipw_Notif.h file are of the same Software version */
#if ((PWM_IPW_NOTIF_SW_MAJOR_VERSION_C != FLEXIO_PWM_IP_TYPES_SW_MAJOR_VERSION)  || \
     (PWM_IPW_NOTIF_SW_MINOR_VERSION_C != FLEXIO_PWM_IP_TYPES_SW_MINOR_VERSION)  || \
     (PWM_IPW_NOTIF_SW_PATCH_VERSION_C != FLEXIO_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Pwm_Ipw_Notif.c and Flexio_Pwm_Ip_Types.h are different."
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
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief        Pwm_Ipw_FlexTimerNotification
* @details      This function is called from FlexTimer's IPL in order to forward a
*               channel notification call from the IP configuration.
*
* @param        irqType - Type of irq that occured in hw
* @param        channel - Hw channel for which notification should be called
*
* @return       void
*
*/
void Pwm_Ipw_FlexTimerNotification(uint8 Channel)
{
    Pwm_Notification(Channel);
}

/**
* @brief        Pwm_Ipw_FlexioNotification
* @details      This function is called from Flexio's IPL in order to forward a
*               channel notification call from the IP configuration.
*
* @param        Channel - Hw channel for which notification should be called
*
* @return       void
*
*/
void Pwm_Ipw_FlexioNotification(uint8 Channel)
{
    Pwm_Notification((uint8)(Channel + PWM_IPW_FLEXIO_CHANNEL_OFFSET));
}
#endif

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
