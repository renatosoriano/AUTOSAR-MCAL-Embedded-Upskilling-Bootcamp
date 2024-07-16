/*
** ###################################################################
**     Processor:           S32K116_M0P
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K1XX RM Rev.14
**     Version:             rev. 1.1, 2022-01-21
**     Build:               b220121
**
**     Abstract:
**         Peripheral Access Layer for S32K116_M0P
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
** ###################################################################
*/

/*!
 * @file S32K116_PCC.h
 * @version 1.1
 * @date 2022-01-21
 * @brief Peripheral Access Layer for S32K116_PCC
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32K116_PCC_H_)  /* Check if memory map has not been already included */
#define S32K116_PCC_H_

#include "S32K116_COMMON.h"

/* ----------------------------------------------------------------------------
   -- PCC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC_Peripheral_Access_Layer PCC Peripheral Access Layer
 * @{
 */

/** PCC - Size of Registers Arrays */
#define PCC_PCCn_COUNT                            116u

/** PCC - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCCn[PCC_PCCn_COUNT];              /**< PCC FTFC Register..PCC CMP0 Register, array offset: 0x0, array step: 0x4 */
} PCC_Type, *PCC_MemMapPtr;

/** Number of instances of the PCC module. */
#define PCC_INSTANCE_COUNT                       (1u)

/* PCC - Peripheral instance base addresses */
/** Peripheral PCC base address */
#define IP_PCC_BASE                              (0x40065000u)
/** Peripheral PCC base pointer */
#define IP_PCC                                   ((PCC_Type *)IP_PCC_BASE)
/** Array initializer of PCC peripheral base addresses */
#define IP_PCC_BASE_ADDRS                        { IP_PCC_BASE }
/** Array initializer of PCC peripheral base pointers */
#define IP_PCC_BASE_PTRS                         { IP_PCC }

/* ----------------------------------------------------------------------------
   -- PCC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PCC_Register_Masks PCC Register Masks
 * @{
 */

/*! @name PCCn - PCC FTFC Register..PCC CMP0 Register */
/*! @{ */

#define PCC_PCCn_PCD_MASK                        (0x7U)
#define PCC_PCCn_PCD_SHIFT                       (0U)
#define PCC_PCCn_PCD_WIDTH                       (3U)
#define PCC_PCCn_PCD(x)                          (((uint32_t)(((uint32_t)(x)) << PCC_PCCn_PCD_SHIFT)) & PCC_PCCn_PCD_MASK)

#define PCC_PCCn_FRAC_MASK                       (0x8U)
#define PCC_PCCn_FRAC_SHIFT                      (3U)
#define PCC_PCCn_FRAC_WIDTH                      (1U)
#define PCC_PCCn_FRAC(x)                         (((uint32_t)(((uint32_t)(x)) << PCC_PCCn_FRAC_SHIFT)) & PCC_PCCn_FRAC_MASK)

#define PCC_PCCn_PCS_MASK                        (0x7000000U)
#define PCC_PCCn_PCS_SHIFT                       (24U)
#define PCC_PCCn_PCS_WIDTH                       (3U)
#define PCC_PCCn_PCS(x)                          (((uint32_t)(((uint32_t)(x)) << PCC_PCCn_PCS_SHIFT)) & PCC_PCCn_PCS_MASK)

#define PCC_PCCn_CGC_MASK                        (0x40000000U)
#define PCC_PCCn_CGC_SHIFT                       (30U)
#define PCC_PCCn_CGC_WIDTH                       (1U)
#define PCC_PCCn_CGC(x)                          (((uint32_t)(((uint32_t)(x)) << PCC_PCCn_CGC_SHIFT)) & PCC_PCCn_CGC_MASK)

#define PCC_PCCn_PR_MASK                         (0x80000000U)
#define PCC_PCCn_PR_SHIFT                        (31U)
#define PCC_PCCn_PR_WIDTH                        (1U)
#define PCC_PCCn_PR(x)                           (((uint32_t)(((uint32_t)(x)) << PCC_PCCn_PR_SHIFT)) & PCC_PCCn_PR_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group PCC_Register_Masks */
#define PCC_FTFC_INDEX 32
#define PCC_DMAMUX_INDEX 33
#define PCC_FlexCAN0_INDEX 36
#define PCC_LPSPI0_INDEX 44
#define PCC_CRC_INDEX 50
#define PCC_PDB0_INDEX 54
#define PCC_LPIT_INDEX 55
#define PCC_FTM0_INDEX 56
#define PCC_FTM1_INDEX 57
#define PCC_ADC0_INDEX 59
#define PCC_RTC_INDEX 61
#define PCC_CMU0_INDEX 62
#define PCC_CMU1_INDEX 63
#define PCC_LPTMR0_INDEX 64
#define PCC_PORTA_INDEX 73
#define PCC_PORTB_INDEX 74
#define PCC_PORTC_INDEX 75
#define PCC_PORTD_INDEX 76
#define PCC_PORTE_INDEX 77
#define PCC_FlexIO_INDEX 90
#define PCC_LPI2C0_INDEX 102
#define PCC_LPUART0_INDEX 106
#define PCC_LPUART1_INDEX 107
#define PCC_CMP0_INDEX 115


/*!
 * @}
 */ /* end of group PCC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K116_PCC_H_) */
