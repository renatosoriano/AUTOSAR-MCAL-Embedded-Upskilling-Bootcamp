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
*   @file    nvic.c
*   @version 2.0.0
*
*   @brief   AUTOSAR Platform - nvic driver
*   @details Functions that manage interrupts and exceptions via the NVIC.
*            This file contains sample code only. It is not part of the production code deliverables.
==================================================================================================*/

#include "Std_Types.h"
#include "nvic.h"

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#ifdef FEATURE_NVIC_PRIORITY_GROUPING
/*================================================================================================*/
/** 
* @brief Set Priority Grouping
* @details The function sets the priority grouping field using the required unlock sequence.
*  The parameter PriorityGroup is assigned to the field SCB->AIRCR [10:8] PRIGROUP field.
*   Only values from 0..7 are used.
*   In case of a conflict between priority grouping and available
*   priority bits (__NVIC_PRIO_BITS), the smallest possible priority group is set
*/
/*================================================================================================*/
void NVIC_SetPriorityGrouping(uint32 PriorityGroup)
{
    /* Set the PRIGROUP[10:8] bits according to NVIC_PriorityGroup value */
    S32_SCB->AIRCR = (S32_SCB->AIRCR & (~0x700UL)) | PriorityGroup;
}
#endif
/*================================================================================================*/
/** 
* @brief Enable External Interrupt
* @details The function enables a device-specific interrupt in the NVIC interrupt controller.
*/
/*================================================================================================*/ 
void NVIC_EnableIRQ(uint8 IRQn)
{
    S32_NVIC->ISER[FEATURE_NVIC_REGISTER_INDEX(IRQn)] = (uint32)(1UL << ((uint32)(IRQn) & (uint32)0x1FU));
}

/*================================================================================================*/
/** 
* @brief Disable External Interrupt
* @details The function disables a device-specific interrupt in the NVIC interrupt controller
*/
/*================================================================================================*/  
void NVIC_DisableIRQ(uint8 IRQn)
{
    S32_NVIC->ICER[FEATURE_NVIC_REGISTER_INDEX(IRQn)] = (uint32)(1UL << ((uint32)(IRQn) & (uint32)0x1FU));
}
 
 
/*================================================================================================*/
/** 
* @brief Set Interrupt Priority
* @details The function sets the priority of an interrupt.
*/
/*================================================================================================*/  
void NVIC_SetPriority(uint8 IRQn, uint8 priority)
{
     uint8 shift = (uint8) (8U - FEATURE_NVIC_PRIO_BITS);
#ifdef FEATURE_NVIC_CORTEX_M4  
    S32_NVIC->IP[(uint32)(IRQn)] = (uint8)(((((uint32)priority) << shift)) & 0xFFUL);
#else
    uint32 iprVectorId = (uint32)(IRQn) >> 2U;
    uint8  priByteShift = (uint8)((((uint8)IRQn) & 0x3U) << 3U);
    S32_NVIC->IP[iprVectorId] &= ~(3U << priByteShift);
    S32_NVIC->IP[iprVectorId] |= ((uint32)(((((uint32)priority) << shift)) & 0xFFUL)) << priByteShift;
#endif
}
 
 
 
