/*
** ###################################################################
**     Processor:           S32K118_M0P
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K1XX RM Rev.14
**     Version:             rev. 1.1, 2022-01-24
**     Build:               b220124
**
**     Abstract:
**         Peripheral Access Layer for S32K118_M0P
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
**     - rev. 1.0 Taru Shree 01-March-21  Initial release based on 
**                                        S32K1xx RM Rev 13.
**    
**     - rev. 1.1 Taru Shree 24-Jan-21  1)Initial release based on 
**                                      S32K1xx RM Rev 14.
**                                      2)DMA- 
**                                      DMA_DCHMID_COUNT is removed.
**                                      3)DMAMUX- 
**                                      DMAMUX_CHCFG_COUNT's value is changed 
**                                      from 8 to 4.
**                                      4)FLEXCAN-
**                                      FLEXCAN_RAMn_COUNT's value is changed 
**                                      from 256 to 128.
**                                      5)RCM- 
**                                      PARAM register: ELOL bitfield is removed. 
**                                      6)SGC- 
**                                      FIRCCSR register: FIRCERR bitfield is 
**                                      removed. 
**
** ###################################################################
*/

/*!
 * @file S32K118.h
 * @version 1.1
 * @date 2022-01-24
 * @brief Peripheral Access Layer for S32K118
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K118_H_)  /* Check if memory map has not been already included */
#define S32K118_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K118_ADC.h"
#include "S32K118_AIPS.h"
#include "S32K118_CMP.h"
#include "S32K118_CMU.h"
#include "S32K118_CRC.h"
#include "S32K118_DMA.h"
#include "S32K118_DMAMUX.h"
#include "S32K118_EIM.h"
#include "S32K118_ERM.h"
#include "S32K118_FLEXCAN.h"
#include "S32K118_FLEXIO.h"
#include "S32K118_FTFC.h"
#include "S32K118_FTM.h"
#include "S32K118_GPIO.h"
#include "S32K118_LMEM.h"
#include "S32K118_LPI2C.h"
#include "S32K118_LPIT.h"
#include "S32K118_LPSPI.h"
#include "S32K118_LPTMR.h"
#include "S32K118_LPUART.h"
#include "S32K118_MCM.h"
#include "S32K118_MPU.h"
#include "S32K118_MSCM.h"
#include "S32K118_MTB_DWT.h"
#include "S32K118_NVIC.h"
#include "S32K118_PCC.h"
#include "S32K118_PDB.h"
#include "S32K118_PMC.h"
#include "S32K118_PORT.h"
#include "S32K118_RCM.h"
#include "S32K118_RTC.h"
#include "S32K118_SCB.h"
#include "S32K118_SCG.h"
#include "S32K118_SIM.h"
#include "S32K118_SMC.h"
#include "S32K118_SYSTICK.h"
#include "S32K118_TRGMUX.h"
#include "S32K118_WDOG.h"

#endif  /* #if !defined(S32K118_H_) */
