/*
** ###################################################################
**     Processor:           S32K148_M4
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K1XX RM Rev.14
**     Version:             rev. 1.1, 2022-02-02
**     Build:               b220202
**
**     Abstract:
**         Peripheral Access Layer for S32K148_M4
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
**     - rev. 1.0 Taru Shree 26-Feb-21  Initial release based on 
**                                      S32K1xx RM Rev 13.
**     
**     - rev. 1.1 Taru Shree 02-Feb-22  1)Initial release based on
**                                      S32K1xx RM Rev 14.
**                                      2)FLEXCAN-
**                                      FLEXCAN_RAMn_COUNT’s value 
**                                      is changed from 256 to 128.
**                                      3)PDB-
**                                      PDB_CH_COUNT’s value is changed 
**                                      from 2 to 4.
**                                      4)SCG-
**                                      FIRCCSR register: FIRCERR 
**                                      bitfield is removed.
**
** ###################################################################
*/

/*!
 * @file S32K148.h
 * @version 1.1
 * @date 2022-02-02
 * @brief Peripheral Access Layer for S32K148
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K148_H_)  /* Check if memory map has not been already included */
#define S32K148_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K148_ADC.h"
#include "S32K148_AIPS.h"
#include "S32K148_CMP.h"
#include "S32K148_CRC.h"
#include "S32K148_DMA.h"
#include "S32K148_DMAMUX.h"
#include "S32K148_EIM.h"
#include "S32K148_ENET.h"
#include "S32K148_ERM.h"
#include "S32K148_EWM.h"
#include "S32K148_FLEXCAN.h"
#include "S32K148_FLEXIO.h"
#include "S32K148_FTFC.h"
#include "S32K148_FTM.h"
#include "S32K148_GPIO.h"
#include "S32K148_LMEM.h"
#include "S32K148_LPI2C.h"
#include "S32K148_LPIT.h"
#include "S32K148_LPSPI.h"
#include "S32K148_LPTMR.h"
#include "S32K148_LPUART.h"
#include "S32K148_MCM.h"
#include "S32K148_MPU.h"
#include "S32K148_MSCM.h"
#include "S32K148_NVIC.h"
#include "S32K148_PCC.h"
#include "S32K148_PDB.h"
#include "S32K148_PMC.h"
#include "S32K148_PORT.h"
#include "S32K148_QUADSPI.h"
#include "S32K148_RCM.h"
#include "S32K148_RTC.h"
#include "S32K148_SAI.h"
#include "S32K148_SCB.h"
#include "S32K148_SCG.h"
#include "S32K148_SIM.h"
#include "S32K148_SMC.h"
#include "S32K148_SYSTICK.h"
#include "S32K148_TRGMUX.h"
#include "S32K148_WDOG.h"

#endif  /* #if !defined(S32K148_H_) */
