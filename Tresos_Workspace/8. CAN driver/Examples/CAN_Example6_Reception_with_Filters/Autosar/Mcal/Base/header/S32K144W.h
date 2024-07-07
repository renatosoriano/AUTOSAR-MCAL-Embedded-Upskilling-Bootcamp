/*
** ###################################################################
**     Processor:           S32K144W_M4
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K1XX RM Rev.14
**     Version:             rev. 1.4, 2022-02-09
**     Build:               b220209
**
**     Abstract:
**         Peripheral Access Layer for S32K144W_M4
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
**     - rev. 1.0 Taru Shree 23-Oct-19  Initial release based on 
**                                      RM Rev.12 Draft B.
**     - rev. 1.1 Taru Shree 12-Feb-20  1)Initial release based on
**                                      RM Rev.12.
**                                      2)CAN- 
**                                      CAN_RAMn_COUNT is changed from
**                                      128 to 256.
**                                      3)DMA-
**                                      DCHMID register array is removed.
**                                      4)GPIO-
**                                      Following peripheral instance names are 
**                                      changed-
**                                      -from GPIOA to PTA.
**                                      -from GPIOB to PTB.
**                                      -from GPIOC to PTC.
**                                      -from GPIOD to PTD.
**                                      -from GPIOE to PTE.
**                                      5)TRGMUX-
**                                      -ADCx_REG is changed to ADCx.
**                                      -CMP0_REG is changed to CMP0.
**                                      -FTMx_REG is changed to FTMx.
**                                      -PDBx_REG is changed to PDBx.
**                                      -FLEXIO_REG is changed to FLEXIO.
**                                      -LPIT0_REG is changed to LPIT0.
**                                      -LPUARTx_REG is changed to LPUARTx.
**                                      -LPI2C0_REG is changed to LPI2C0.
**                                      -LPSPIx_REG is changed to LPSPIx.
**                                      -LPTMR0_REG is changed to LPTMR0.
**     - rev.1.2 Taru Shree 09-March-20 1)Initial release based on
**                                      RM Rev.12.1. 
**                                      2)FTFM Interrupts are updated.   
**                                      3)PCC-
**                                      PCC_ATX register is removed.          
**     - rev.1.3 Taru Shree 25-Feb-21   1)Initial release based on
**                                      RM Rev.13.
**                                      2)Read_Collision interrupt is
**                                      renamed as FTFM_Read_Collision.
**                                      3)In address definitions,
**                                      instances are prefixed with "IP".
**     - rev.1.4 Taru Shree 09-Feb-22   1)Initial release based on
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
 * @file S32K144W.h
 * @version 1.4
 * @date 2022-02-09
 * @brief Peripheral Access Layer for S32K144W
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/* Prevention from multiple including the same memory map */
#if !defined(S32K144W_H_)  /* Check if memory map has not been already included */
#define S32K144W_H_

/* ----------------------------------------------------------------------------
   -- IP Header Files
   ---------------------------------------------------------------------------- */

/* IP Header Files List */
#include "S32K144W_ADC.h"
#include "S32K144W_AIPS.h"
#include "S32K144W_CMP.h"
#include "S32K144W_CRC.h"
#include "S32K144W_DMA.h"
#include "S32K144W_DMAMUX.h"
#include "S32K144W_EIM.h"
#include "S32K144W_ERM.h"
#include "S32K144W_EWM.h"
#include "S32K144W_FLEXCAN.h"
#include "S32K144W_FLEXIO.h"
#include "S32K144W_FTFM.h"
#include "S32K144W_FTM.h"
#include "S32K144W_GPIO.h"
#include "S32K144W_LMEM.h"
#include "S32K144W_LPI2C.h"
#include "S32K144W_LPIT.h"
#include "S32K144W_LPSPI.h"
#include "S32K144W_LPTMR.h"
#include "S32K144W_LPUART.h"
#include "S32K144W_MCM.h"
#include "S32K144W_MPU.h"
#include "S32K144W_MSCM.h"
#include "S32K144W_NVIC.h"
#include "S32K144W_PCC.h"
#include "S32K144W_PDB.h"
#include "S32K144W_PMC.h"
#include "S32K144W_PORT.h"
#include "S32K144W_RCM.h"
#include "S32K144W_RTC.h"
#include "S32K144W_SCB.h"
#include "S32K144W_SCG.h"
#include "S32K144W_SIM.h"
#include "S32K144W_SMC.h"
#include "S32K144W_SYSTICK.h"
#include "S32K144W_TRGMUX.h"
#include "S32K144W_WDOG.h"

#endif  /* #if !defined(S32K144W_H_) */
