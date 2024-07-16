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
/*================================================================================================
*   @file    system.h
*   @version 2.0.0
*
*   @brief   AUTOSAR Platform - SYSTEM
*   @details SYSTEM
*            This file contains sample code only. It is not part of the production code deliverables.
==================================================================================================*/

#ifndef SYSTEM_H
#define SYSTEM_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "Std_Types.h"

/* 
 * @brief Early platform initialization for interrupts, cache and core MPU
 * @param: None
 * 
 * @return: None
 */
void SystemInit(void);

/* 
 * @brief Default IRQ handler
 * @param: None
 * 
 * @return: None
 */
void default_interrupt_routine(void);

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
/* 
 * @brief Switch to user mode and return the value passed by u32returnValue
 * @param: [in] u8SwitchToSupervisor - if 0, the function will return the value without switching to user mode,
 *                                     if 1, the function will go to user mode before returning the value
 * @param: [in] u32returnValue       - value to be returned
 * 
 * @return: u32returnValue
 */
uint32 Sys_GoToUser_Return(uint32 u32SwitchToSupervisor, uint32 u32returnValue);

/* 
 * @brief Switch to supervisor mode
 * @param: None
 * 
 * @return: operation result, 1 if switch was done, 0 if the CPU was already in supervisor mode or in handler mode
 */
uint32 Sys_GoToSupervisor(void);

/* 
 * @brief Switch to user mode
 * @param: None
 * 
 * @return: 0
 */
uint32 Sys_GoToUser(void);

/* 
 * @brief Sys_SuspendInterrupts
 * @param: None
 * 
 * @return: none
 */
void Sys_SuspendInterrupts(void);
void Sys_ResumeInterrupts(void);
#endif

/* 
 * @brief Get the hardware id of the currently executing core
 * @param: None
 * 
 * @return: coreId
 */
uint8 Sys_GetCoreID(void);

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_H */
