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
*   @file       Power_Ip_RCM.c
*   @version    2.0.0
*
*   @brief
*   @brief   POWER driver implementations.
*   @details POWER driver implementations.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
*   @{
*/


#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Power_Ip_RCM.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_RCM_IRQ_VENDOR_ID_C                      43
#define POWER_IP_RCM_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define POWER_IP_RCM_IRQ_AR_RELEASE_MINOR_VERSION_C       7
#define POWER_IP_RCM_IRQ_AR_RELEASE_REVISION_VERSION_C    0
#define POWER_IP_RCM_IRQ_SW_MAJOR_VERSION_C               2
#define POWER_IP_RCM_IRQ_SW_MINOR_VERSION_C               0
#define POWER_IP_RCM_IRQ_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcal header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((POWER_IP_RCM_IRQ_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (POWER_IP_RCM_IRQ_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Power_Ip_RCM_Irq.c and Mcal.h are different"
    #endif
#endif

/* Check if current file and Power_Ip_RCM header file are of the same Autosar version */
#if (POWER_IP_RCM_IRQ_VENDOR_ID_C != POWER_IP_RCM_VENDOR_ID)
    #error "Power_Ip_RCM_Irq.c and Power_Ip_RCM.h have different vendor ids"
#endif
/* Check if current file and Power_Ip_RCM header file are of the same Autosar version */
#if ((POWER_IP_RCM_IRQ_AR_RELEASE_MAJOR_VERSION_C    != POWER_IP_RCM_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_RCM_IRQ_AR_RELEASE_MINOR_VERSION_C    != POWER_IP_RCM_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_RCM_IRQ_AR_RELEASE_REVISION_VERSION_C != POWER_IP_RCM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_RCM_Irq.c and Power_Ip_RCM.h are different"
#endif
/* Check if current file and Power_Ip_RCM header file are of the same Software version */
#if ((POWER_IP_RCM_IRQ_SW_MAJOR_VERSION_C != POWER_IP_RCM_SW_MAJOR_VERSION) || \
     (POWER_IP_RCM_IRQ_SW_MINOR_VERSION_C != POWER_IP_RCM_SW_MINOR_VERSION) || \
     (POWER_IP_RCM_IRQ_SW_PATCH_VERSION_C != POWER_IP_RCM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_RCM_Irq.c and Power_Ip_RCM.h are different"
#endif
/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#if (defined(POWER_IP_RESET_ALTERNATE_ISR_USED) && (POWER_IP_RESET_ALTERNATE_ISR_USED == STD_ON))
ISR(Power_Ip_RCM_AlternateResetIsr);
#endif
/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if (defined(POWER_IP_RESET_ALTERNATE_ISR_USED) && (POWER_IP_RESET_ALTERNATE_ISR_USED == STD_ON))
/**
* @brief        Alternate Reset Event ISR.
* @details      This ISR is generated by the RCM IP when some events are configured to generate
*               an interrupt request.
*
* @isr
*
*/
ISR(Power_Ip_RCM_AlternateResetIsr)
{
    Power_Ip_RCM_ResetAltInt();
    EXIT_INTERRUPT();
}
#endif /* (POWER_IP_RESET_ALTERNATE_ISR_USED == STD_ON) */

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
