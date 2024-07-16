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

#ifndef FTM_PWM_IP_IRQ_H
#define FTM_PWM_IP_IRQ_H

/**
*   @file
*
*   @internal
*   @addtogroup group_name
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "OsIf.h"
#include "Ftm_Pwm_Ip_Cfg.h"
#include "Ftm_Pwm_Ip_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define FTM_PWM_IP_IRQ_VENDOR_ID                       43
#define FTM_PWM_IP_IRQ_MODULE_ID                       121
#define FTM_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define FTM_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION        7
#define FTM_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION     0
#define FTM_PWM_IP_IRQ_SW_MAJOR_VERSION                2
#define FTM_PWM_IP_IRQ_SW_MINOR_VERSION                0
#define FTM_PWM_IP_IRQ_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and OsIf.h are of the same AUTOSAR version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((FTM_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION != OSIF_AR_RELEASE_MAJOR_VERSION) || \
         (FTM_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION != OSIF_AR_RELEASE_MINOR_VERSION))
        #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Irq.h and OsIf.h are different."
    #endif
#endif

/* Check if header file and Ftm_Pwm_Ip_Cfg.h header file are of the same vendor */
#if (FTM_PWM_IP_IRQ_VENDOR_ID != FTM_PWM_IP_CFG_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip_Irq.h and Ftm_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Cfg.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != FTM_PWM_IP_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION    != FTM_PWM_IP_CFG_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION != FTM_PWM_IP_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Irq.h and Ftm_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Cfg.h header file are of the same software version */
#if ((FTM_PWM_IP_IRQ_SW_MAJOR_VERSION != FTM_PWM_IP_CFG_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_IRQ_SW_MINOR_VERSION != FTM_PWM_IP_CFG_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_IRQ_SW_PATCH_VERSION != FTM_PWM_IP_CFG_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip_Irq.h and Ftm_Pwm_Ip_Cfg.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same vendor */
#if (FTM_PWM_IP_IRQ_VENDOR_ID != FTM_PWM_IP_TYPES_VENDOR_ID)
    #error "Vendor IDs of Ftm_Pwm_Ip_Irq.h and Ftm_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same AUTOSAR version */
#if ((FTM_PWM_IP_IRQ_AR_RELEASE_MAJOR_VERSION    != FTM_PWM_IP_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FTM_PWM_IP_IRQ_AR_RELEASE_MINOR_VERSION    != FTM_PWM_IP_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (FTM_PWM_IP_IRQ_AR_RELEASE_REVISION_VERSION != FTM_PWM_IP_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR version numbers of Ftm_Pwm_Ip_Irq.h and Ftm_Pwm_Ip_Types.h are different."
#endif

/* Check if header file and Ftm_Pwm_Ip_Types.h header file are of the same software version */
#if ((FTM_PWM_IP_IRQ_SW_MAJOR_VERSION != FTM_PWM_IP_TYPES_SW_MAJOR_VERSION) || \
     (FTM_PWM_IP_IRQ_SW_MINOR_VERSION != FTM_PWM_IP_TYPES_SW_MINOR_VERSION) || \
     (FTM_PWM_IP_IRQ_SW_PATCH_VERSION != FTM_PWM_IP_TYPES_SW_PATCH_VERSION))
    #error "Software version numbers of Ftm_Pwm_Ip_Irq.h and Ftm_Pwm_Ip_Types.h are different."
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
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
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

#if (defined FTM_PWM_IP_0_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0
 */
ISR(FTM_0_ISR);
#endif

#if (defined FTM_PWM_IP_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1
 */
ISR(FTM_1_ISR);
#endif

#if (defined FTM_PWM_IP_2_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2
 */
ISR(FTM_2_ISR);
#endif

#if (defined FTM_PWM_IP_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3
 */
ISR(FTM_3_ISR);
#endif

#if (defined FTM_PWM_IP_4_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4
 */
ISR(FTM_4_ISR);
#endif

#if (defined FTM_PWM_IP_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5
 */
ISR(FTM_5_ISR);
#endif



#if (defined FTM_PWM_IP_0_OVF_RELOAD_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 overflow, reload interrupt
 */
ISR(FTM_0_OVF_RELOAD_ISR);
#endif

#if (defined FTM_PWM_IP_1_OVF_RELOAD_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 overflow, reload interrupt
 */
ISR(FTM_1_OVF_RELOAD_ISR);
#endif

#if (defined FTM_PWM_IP_2_OVF_RELOAD_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 overflow, reload interrupt
 */
ISR(FTM_2_OVF_RELOAD_ISR);
#endif

#if (defined FTM_PWM_IP_3_OVF_RELOAD_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 overflow, reload interrupt
 */
ISR(FTM_3_OVF_RELOAD_ISR);
#endif

#if (defined FTM_PWM_IP_4_OVF_RELOAD_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 overflow, reload interrupt
 */
ISR(FTM_4_OVF_RELOAD_ISR);
#endif

#if (defined FTM_PWM_IP_5_OVF_RELOAD_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 overflow, reload interrupt
 */
ISR(FTM_5_OVF_RELOAD_ISR);
#endif

#if (defined FTM_PWM_IP_6_OVF_RELOAD_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 overflow, reload interrupt
 */
ISR(FTM_6_OVF_RELOAD_ISR);
#endif

#if (defined FTM_PWM_IP_7_OVF_RELOAD_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 overflow, reload interrupt
 */
ISR(FTM_7_OVF_RELOAD_ISR);
#endif

#if (defined FTM_PWM_IP_0_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 0 - channel 1.
 */
ISR(FTM_0_CH_0_CH_1_ISR);
#endif

#if (defined FTM_PWM_IP_0_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 2 - channel 3.
 */
ISR(FTM_0_CH_2_CH_3_ISR);
#endif

#if (defined FTM_PWM_IP_0_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 4 - channel 5.
 */
ISR(FTM_0_CH_4_CH_5_ISR);
#endif

#if (defined FTM_PWM_IP_0_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 channel 6 - channel 7.
 */
ISR(FTM_0_CH_6_CH_7_ISR);
#endif

#if (defined FTM_PWM_IP_1_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 0 - channel 1.
 */
ISR(FTM_1_CH_0_CH_1_ISR);
#endif

#if (defined FTM_PWM_IP_1_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 2 - channel 3.
 */
ISR(FTM_1_CH_2_CH_3_ISR);
#endif

#if (defined FTM_PWM_IP_1_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 4 - channel 5.
 */
ISR(FTM_1_CH_4_CH_5_ISR);
#endif

#if (defined FTM_PWM_IP_1_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 channel 6 - channel 7.
 */
ISR(FTM_1_CH_6_CH_7_ISR);
#endif

#if (defined FTM_PWM_IP_2_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 0 - channel 1.
 */
ISR(FTM_2_CH_0_CH_1_ISR);
#endif

#if (defined FTM_PWM_IP_2_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 2 - channel 3.
 */
ISR(FTM_2_CH_2_CH_3_ISR);
#endif

#if (defined FTM_PWM_IP_2_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 4 - channel 5.
 */
ISR(FTM_2_CH_4_CH_5_ISR);
#endif

#if (defined FTM_PWM_IP_2_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 channel 6 - channel 7.
 */
ISR(FTM_2_CH_6_CH_7_ISR);
#endif

#if (defined FTM_PWM_IP_3_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 0 - channel 1.
 */
ISR(FTM_3_CH_0_CH_1_ISR);
#endif

#if (defined FTM_PWM_IP_3_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 2 - channel 3.
 */
ISR(FTM_3_CH_2_CH_3_ISR);
#endif

#if (defined FTM_PWM_IP_3_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 4 - channel 5.
 */
ISR(FTM_3_CH_4_CH_5_ISR);
#endif

#if (defined FTM_PWM_IP_3_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 channel 6 - channel 7.
 */
ISR(FTM_3_CH_6_CH_7_ISR);
#endif

#if (defined FTM_PWM_IP_4_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 0 - channel 1.
 */
ISR(FTM_4_CH_0_CH_1_ISR);
#endif

#if (defined FTM_PWM_IP_4_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 2 - channel 3.
 */
ISR(FTM_4_CH_2_CH_3_ISR);
#endif

#if (defined FTM_PWM_IP_4_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 4 - channel 5.
 */
ISR(FTM_4_CH_4_CH_5_ISR);
#endif

#if (defined FTM_PWM_IP_4_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 channel 6 - channel 7.
 */
ISR(FTM_4_CH_6_CH_7_ISR);
#endif

#if (defined FTM_PWM_IP_5_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 0 - channel 1.
 */
ISR(FTM_5_CH_0_CH_1_ISR);
#endif

#if (defined FTM_PWM_IP_5_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 2 - channel 3.
 */
ISR(FTM_5_CH_2_CH_3_ISR);
#endif

#if (defined FTM_PWM_IP_5_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 4 - channel 5.
 */
ISR(FTM_5_CH_4_CH_5_ISR);
#endif

#if (defined FTM_PWM_IP_5_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 channel 6 - channel 7.
 */
ISR(FTM_5_CH_6_CH_7_ISR);
#endif

#if (defined FTM_PWM_IP_6_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 channel 0 - channel 1.
 */
ISR(FTM_6_CH_0_CH_1_ISR);
#endif

#if (defined FTM_PWM_IP_6_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 channel 2 - channel 3.
 */
ISR(FTM_6_CH_2_CH_3_ISR);
#endif

#if (defined FTM_PWM_IP_6_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 channel 4 - channel 5.
 */
ISR(FTM_6_CH_4_CH_5_ISR);
#endif

#if (defined FTM_PWM_IP_6_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 channel 6 - channel 7.
 */
ISR(FTM_6_CH_6_CH_7_ISR);
#endif

#if (defined FTM_PWM_IP_7_CH_0_CH_1_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 channel 0 - channel 1.
 */
ISR(FTM_7_CH_0_CH_1_ISR);
#endif

#if (defined FTM_PWM_IP_7_CH_2_CH_3_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 channel 2 - channel 3.
 */
ISR(FTM_7_CH_2_CH_3_ISR);
#endif

#if (defined FTM_PWM_IP_7_CH_4_CH_5_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 channel 4 - channel 5.
 */
ISR(FTM_7_CH_4_CH_5_ISR);
#endif

#if (defined FTM_PWM_IP_7_CH_6_CH_7_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 channel 6 - channel 7.
 */
ISR(FTM_7_CH_6_CH_7_ISR);
#endif


#if (defined FTM_PWM_IP_0_FAULT_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 0 fault
 */
ISR(FTM_0_FAULT_ISR);
#endif

#if (defined FTM_PWM_IP_1_FAULT_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 1 fault
 */
ISR(FTM_1_FAULT_ISR);
#endif

#if (defined FTM_PWM_IP_2_FAULT_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 2 fault
 */
ISR(FTM_2_FAULT_ISR);
#endif

#if (defined FTM_PWM_IP_3_FAULT_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 3 fault
 */
ISR(FTM_3_FAULT_ISR);
#endif

#if (defined FTM_PWM_IP_4_FAULT_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 4 fault
 */
ISR(FTM_4_FAULT_ISR);
#endif

#if (defined FTM_PWM_IP_5_FAULT_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 5 fault
 */
ISR(FTM_5_FAULT_ISR);
#endif

#if (defined FTM_PWM_IP_6_FAULT_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 6 fault
 */
ISR(FTM_6_FAULT_ISR);
#endif

#if (defined FTM_PWM_IP_7_FAULT_ISR_USED)
/**
 * @brief          Independent interrupt handler.
 * @details        Interrupt handler for FTM module 7 fault
 */
ISR(FTM_7_FAULT_ISR);
#endif

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif  /* FTM_PWM_IP_IRQ_H */

/** @} */
