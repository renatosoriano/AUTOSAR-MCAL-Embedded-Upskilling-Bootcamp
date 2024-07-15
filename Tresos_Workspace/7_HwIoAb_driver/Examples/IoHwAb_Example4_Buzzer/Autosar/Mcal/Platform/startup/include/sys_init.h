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
*/
/*==================================================================================================
*   @file    sys_init.h
*   @version 2.0.0
*
*   @brief   AUTOSAR Platform - RTD auxiliary APIs used for RTD testing
*   @details RTD auxiliary APIs used for RTD testing
*            This file contains sample code only. It is not part of the production code deliverables
==================================================================================================*/

#ifndef SYS_INIT_H
#define SYS_INIT_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Mcal.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define INT_NUM_SOURCES (224)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


typedef void (*int_function_t)(void);

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
/** 
* @brief sys_disableIsrSource
* @details function used to disable the interrupt number id
*/
void sys_disableIsrSource(uint8 id);  
/** 
* @brief sys_init
* @details function used to enable the interrupt number id and set up the priority
*/
void sys_enableIsrSource(uint8 id, uint8 prio);
/** 
* @brief sys_init
* @details function used to register the interrupt handler in the interrupt vectors
*/
void sys_registerIsrHandler(uint8 irq_id, int_function_t isr_handler);
/** 
* @brief sys_init
* @details function used to enable all interrupts
*/
void sys_enableAllInterrupts(void);
/** 
* @brief sys_init
* @details function used to disable all interrupts
*/
void sys_disableAllInterrupts(void);

/** 
* @brief sys_init
* @details function used to initiatialize clocks, system clock is system Pll 120 MHz
*/
Std_ReturnType sys_init(void);

/** 
* @brief sys_halt
* @details function used to enter halt mode
*/
void sys_halt(void);

/** 
* @brief sys_stop
* @details function used to enter stop mode
*/
void sys_stop(void);

/** 
* @brief EUnit_GetCoreID
* @details function used to provide the CoreID to EUnit
*/
uint8 EUnit_GetCoreID(void);


#ifdef __cplusplus
}
#endif

#endif /*SYS_INIT_H*/
