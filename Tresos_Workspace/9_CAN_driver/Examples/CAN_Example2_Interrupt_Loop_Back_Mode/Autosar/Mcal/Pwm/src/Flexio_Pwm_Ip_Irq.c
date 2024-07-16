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
*   @file Flexio_Pwm_Ip_Irq.c
*
*   @addtogroup flexio_pwm_ip_irq FlexIO Pwm IPL
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
#include "Flexio_Pwm_Ip_Irq.h"
#include "Flexio_Pwm_Ip_HwAccess.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXIO_PWM_IP_IRQ_VENDOR_ID_C                      43
#define FLEXIO_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define FLEXIO_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define FLEXIO_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define FLEXIO_PWM_IP_IRQ_SW_MAJOR_VERSION_C               2
#define FLEXIO_PWM_IP_IRQ_SW_MINOR_VERSION_C               0
#define FLEXIO_PWM_IP_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Flexio_Pwm_Ip_Irq.h file are of the same vendor */
#if (FLEXIO_PWM_IP_IRQ_VENDOR_ID_C != FLEXIO_PWM_IP_IRQ_VENDOR_ID)
    #error "Vendor IDs of Flexio_Pwm_Ip_Irq.c and Flexio_Pwm_Ip_Irq.h are different."
#endif

/* Check if source file and Flexio_Pwm_Ip_Irq.h file are of the same AUTOSAR version */
#if ((FLEXIO_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXIO_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Flexio_Pwm_Ip_Irq.c and Flexio_Pwm_Ip_Irq.h are different."
#endif

/* Check if source file and Flexio_Pwm_Ip_Irq.h file are of the same Software version */
#if ((FLEXIO_PWM_IP_IRQ_SW_MAJOR_VERSION_C != FLEXIO_PWM_IP_IRQ_SW_MAJOR_VERSION)  || \
     (FLEXIO_PWM_IP_IRQ_SW_MINOR_VERSION_C != FLEXIO_PWM_IP_IRQ_SW_MINOR_VERSION)  || \
     (FLEXIO_PWM_IP_IRQ_SW_PATCH_VERSION_C != FLEXIO_PWM_IP_IRQ_SW_PATCH_VERSION))
    #error "Software version numbers of Flexio_Pwm_Ip_Irq.c and Flexio_Pwm_Ip_Irq.h are different."
#endif

/* Check if source file and Flexio_Pwm_Ip_HwAccess.h file are of the same vendor */
#if (FLEXIO_PWM_IP_IRQ_VENDOR_ID_C != FLEXIO_PWM_IP_HWACCESS_VENDOR_ID)
    #error "Vendor IDs of Flexio_Pwm_Ip_Irq.c and Flexio_Pwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and Flexio_Pwm_Ip_HwAccess.h file are of the same AUTOSAR version */
#if ((FLEXIO_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION_C    != FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_MAJOR_VERSION) || \
     (FLEXIO_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION_C    != FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_MINOR_VERSION) || \
     (FLEXIO_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION_C != FLEXIO_PWM_IP_HWACCESS_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Flexio_Pwm_Ip_Irq.c and Flexio_Pwm_Ip_HwAccess.h are different."
#endif

/* Check if source file and Flexio_Pwm_Ip_HwAccess.h file are of the same Software version */
#if ((FLEXIO_PWM_IP_IRQ_SW_MAJOR_VERSION_C != FLEXIO_PWM_IP_HWACCESS_SW_MAJOR_VERSION)  || \
     (FLEXIO_PWM_IP_IRQ_SW_MINOR_VERSION_C != FLEXIO_PWM_IP_HWACCESS_SW_MINOR_VERSION)  || \
     (FLEXIO_PWM_IP_IRQ_SW_PATCH_VERSION_C != FLEXIO_PWM_IP_HWACCESS_SW_PATCH_VERSION))
    #error "Software version numbers of Flexio_Pwm_Ip_Irq.c and Flexio_Pwm_Ip_HwAccess.h are different."
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
#if (FLEXIO_PWM_IP_USED == STD_ON)
#define PWM_START_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

/** @brief Array with base addresses for Flexio instances available on platform */
extern Flexio_Pwm_Ip_HwAddrType * const Flexio_Pwm_Ip_aBasePtr[FLEXIO_PWM_IP_INSTANCE_COUNT];

#define PWM_STOP_SEC_CONST_UNSPECIFIED
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

/** @brief Array with pointers to user cfg structs*/
extern const Flexio_Pwm_Ip_ChannelConfigType * Flexio_Pwm_Ip_aState[FLEXIO_PWM_IP_CHANNEL_COUNT];

#define PWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_CLEARED_8
#include "Pwm_MemMap.h"

/** @brief Interrupt enable masks for used timers */
extern volatile uint8 Flexio_Pwm_Ip_u8TimerIrqMask;

#define PWM_STOP_SEC_VAR_CLEARED_8
#include "Pwm_MemMap.h"


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

/**
 *
 * Function Name : Flexio_Pwm_Ip_IrqHandler
 * Description   : Flexio Pwm Interrupt Request handler
 * The function will determine the type of interrupt that occurred and call the user
 * callback.
 *
 * @implements Flexio_Pwm_Ip_IrqHandler_Activity
 */
void Flexio_Pwm_Ip_IrqHandler(uint8 ChannelId,
                              uint8 TimerFlags
                              )
{
    /* Find what type of interrupt occurred */
    if ((TimerFlags & Flexio_Pwm_Ip_u8TimerIrqMask & (1U << Flexio_Pwm_Ip_aState[ChannelId]->TimerId)) != 0U)
    {
        if(NULL_PTR != Flexio_Pwm_Ip_aState[ChannelId]->IplCallback.CbFunction)
        {
            /* The timer end of period occurred */
            Flexio_Pwm_Ip_aState[ChannelId]->IplCallback.CbFunction(
                                        FLEXIO_PWM_IP_TIMER_IRQ,
                                        Flexio_Pwm_Ip_aState[ChannelId]->IplCallback.CbParameter);
        }
        else
        {
            if(NULL_PTR != Flexio_Pwm_Ip_aState[ChannelId]->HldCallback.CbFunction)
            {
                Flexio_Pwm_Ip_aState[ChannelId]->HldCallback.CbFunction(
                            Flexio_Pwm_Ip_aState[ChannelId]->HldCallback.CbParameter);
            }
        }
    }

    (void)TimerFlags;
}

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#endif /* FLEXIO_PWM_IP_USED == STD_ON */
#ifdef __cplusplus
}
#endif

/** @} */
