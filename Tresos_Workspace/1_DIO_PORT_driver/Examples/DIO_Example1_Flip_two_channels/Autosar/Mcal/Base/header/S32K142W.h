/*
** ###################################################################
**     Processor:           S32K142W_M4
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K1XX RM Rev.14
**     Version:             rev. 1.2, 2022-02-10
**     Build:               b220210
**
**     Abstract:
**         Peripheral Access Layer for S32K142W_M4
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2022 NXP
**
**     NXP Confidential. This software is owned or controlled by NXP and may only be
**     used strictly in accordance with the applicable license terms. By expressly
**     accepting such terms or by downloading, installing, activating and/or otherwise
**     using the software, you are agreeing that you have read, and that you agree to
**     comply with and are bound by, such license terms. If you do not agree to be
**     bound by the applicable license terms, then you may not retain, install,
**     activate or otherwise use the software. The production use license in
**     Section 2.3 is expressly granted for this software.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**
**     - rev. 1.0 Taru Shree 15-May-20  Initial release based on 
**                                      RM Rev.12.1.
**     - rev. 1.1 Taru Shree 26-Feb-21  1)Initial release based on
**                                      RM Rev.13.
**                                      2)Read_Collision interrupt is
**                                      renamed as FTFM_Read_Collision.
**                                      3)In address definitions,
**                                      instances are prefixed with "IP".
**     - rev. 1.2 Taru Shree 10-Feb-22  1)Initial release based on 
**                                      RM Rev.14.
**                                      2)FLEXCAN-
**                                      FLEXCAN_RAMn_COUNT’s value is 
**                                      changed from 256 to 128.
**                                      3)SCG-
**                                      FIRCCSR register: FIRCERR bitfield 
**                                      is removed.
**
** ###################################################################
*/

/*!
 * @file S32K142W.h
 * @version 1.2
 * @date 2022-02-10
 * @brief Peripheral Access Layer for S32K142W
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K142W_H_)  /* Check if memory map has not been already included */
#define S32K142W_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K142W_ADC.h"
#include "S32K142W_AIPS.h"
#include "S32K142W_CMP.h"
#include "S32K142W_CRC.h"
#include "S32K142W_DMA.h"
#include "S32K142W_DMAMUX.h"
#include "S32K142W_EIM.h"
#include "S32K142W_ERM.h"
#include "S32K142W_EWM.h"
#include "S32K142W_FLEXCAN.h"
#include "S32K142W_FLEXIO.h"
#include "S32K142W_FTFM.h"
#include "S32K142W_FTM.h"
#include "S32K142W_GPIO.h"
#include "S32K142W_LMEM.h"
#include "S32K142W_LPI2C.h"
#include "S32K142W_LPIT.h"
#include "S32K142W_LPSPI.h"
#include "S32K142W_LPTMR.h"
#include "S32K142W_LPUART.h"
#include "S32K142W_MCM.h"
#include "S32K142W_MPU.h"
#include "S32K142W_MSCM.h"
#include "S32K142W_NVIC.h"
#include "S32K142W_PCC.h"
#include "S32K142W_PDB.h"
#include "S32K142W_PMC.h"
#include "S32K142W_PORT.h"
#include "S32K142W_RCM.h"
#include "S32K142W_RTC.h"
#include "S32K142W_SCB.h"
#include "S32K142W_SCG.h"
#include "S32K142W_SIM.h"
#include "S32K142W_SMC.h"
#include "S32K142W_SYSTICK.h"
#include "S32K142W_TRGMUX.h"
#include "S32K142W_WDOG.h"

#endif  /* #if !defined(S32K142W_H_) */
