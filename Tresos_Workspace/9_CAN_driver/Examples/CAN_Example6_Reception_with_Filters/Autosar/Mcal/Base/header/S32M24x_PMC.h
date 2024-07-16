/*
** ###################################################################
**     Processor:           S32M24x
**     Reference manual:    S32M24x RM Rev.2 Draft A
**     Version:             rev. 1.3, 2023-05-30
**     Build:               b230530
**
**     Abstract:
**         Peripheral Access Layer for S32M24x
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2023 NXP
**
**     NXP Confidential. This software is owned or controlled by NXP and may
**     only be used strictly in accordance with the applicable license terms.
**     By expressly accepting such terms or by downloading, installing,
**     activating and/or otherwise using the software, you are agreeing that
**     you have read, and that you agree to comply with and are bound by,
**     such license terms. If you do not agree to be bound by the applicable
**     license terms, then you may not retain, install, activate or otherwise
**     use the software.
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
** ###################################################################
*/

/*!
 * @file S32M24x_PMC.h
 * @version 1.3
 * @date 2023-05-30
 * @brief Peripheral Access Layer for S32M24x_PMC
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
#if !defined(S32M24x_PMC_H_)  /* Check if memory map has not been already included */
#define S32M24x_PMC_H_

#include "S32M24x_COMMON.h"

/* ----------------------------------------------------------------------------
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Peripheral_Access_Layer PMC Peripheral Access Layer
 * @{
 */

/** PMC - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[1];
  __IO uint8_t LVDSC2;                             /**< Low Voltage Detect Status and Control 2 Register, offset: 0x1 */
  __IO uint8_t REGSC;                              /**< Regulator Status and Control Register, offset: 0x2 */
  __IO uint8_t LVRFLG;                             /**< Low Voltage Reset Flags Register, offset: 0x3 */
  __IO uint8_t LPOTRIM;                            /**< Low Power Oscillator Trim Register, offset: 0x4 */
} PMC_Type, *PMC_MemMapPtr;

/** Number of instances of the PMC module. */
#define PMC_INSTANCE_COUNT                       (1u)

/* PMC - Peripheral instance base addresses */
/** Peripheral PMC base address */
#define IP_PMC_BASE                              (0x4007D000u)
/** Peripheral PMC base pointer */
#define IP_PMC                                   ((PMC_Type *)IP_PMC_BASE)
/** Array initializer of PMC peripheral base addresses */
#define IP_PMC_BASE_ADDRS                        { IP_PMC_BASE }
/** Array initializer of PMC peripheral base pointers */
#define IP_PMC_BASE_PTRS                         { IP_PMC }

/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/*! @name LVDSC2 - Low Voltage Detect Status and Control 2 Register */
/*! @{ */

#define PMC_LVDSC2_LVWIE_MASK                    (0x20U)
#define PMC_LVDSC2_LVWIE_SHIFT                   (5U)
#define PMC_LVDSC2_LVWIE_WIDTH                   (1U)
#define PMC_LVDSC2_LVWIE(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC2_LVWIE_SHIFT)) & PMC_LVDSC2_LVWIE_MASK)

#define PMC_LVDSC2_LVWACK_MASK                   (0x40U)
#define PMC_LVDSC2_LVWACK_SHIFT                  (6U)
#define PMC_LVDSC2_LVWACK_WIDTH                  (1U)
#define PMC_LVDSC2_LVWACK(x)                     (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC2_LVWACK_SHIFT)) & PMC_LVDSC2_LVWACK_MASK)

#define PMC_LVDSC2_LVWF_MASK                     (0x80U)
#define PMC_LVDSC2_LVWF_SHIFT                    (7U)
#define PMC_LVDSC2_LVWF_WIDTH                    (1U)
#define PMC_LVDSC2_LVWF(x)                       (((uint8_t)(((uint8_t)(x)) << PMC_LVDSC2_LVWF_SHIFT)) & PMC_LVDSC2_LVWF_MASK)
/*! @} */

/*! @name REGSC - Regulator Status and Control Register */
/*! @{ */

#define PMC_REGSC_BIASEN_MASK                    (0x1U)
#define PMC_REGSC_BIASEN_SHIFT                   (0U)
#define PMC_REGSC_BIASEN_WIDTH                   (1U)
#define PMC_REGSC_BIASEN(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_REGSC_BIASEN_SHIFT)) & PMC_REGSC_BIASEN_MASK)

#define PMC_REGSC_CLKBIASDIS_MASK                (0x2U)
#define PMC_REGSC_CLKBIASDIS_SHIFT               (1U)
#define PMC_REGSC_CLKBIASDIS_WIDTH               (1U)
#define PMC_REGSC_CLKBIASDIS(x)                  (((uint8_t)(((uint8_t)(x)) << PMC_REGSC_CLKBIASDIS_SHIFT)) & PMC_REGSC_CLKBIASDIS_MASK)

#define PMC_REGSC_REGFPM_MASK                    (0x4U)
#define PMC_REGSC_REGFPM_SHIFT                   (2U)
#define PMC_REGSC_REGFPM_WIDTH                   (1U)
#define PMC_REGSC_REGFPM(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_REGSC_REGFPM_SHIFT)) & PMC_REGSC_REGFPM_MASK)

#define PMC_REGSC_LPOSTAT_MASK                   (0x40U)
#define PMC_REGSC_LPOSTAT_SHIFT                  (6U)
#define PMC_REGSC_LPOSTAT_WIDTH                  (1U)
#define PMC_REGSC_LPOSTAT(x)                     (((uint8_t)(((uint8_t)(x)) << PMC_REGSC_LPOSTAT_SHIFT)) & PMC_REGSC_LPOSTAT_MASK)

#define PMC_REGSC_LPODIS_MASK                    (0x80U)
#define PMC_REGSC_LPODIS_SHIFT                   (7U)
#define PMC_REGSC_LPODIS_WIDTH                   (1U)
#define PMC_REGSC_LPODIS(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_REGSC_LPODIS_SHIFT)) & PMC_REGSC_LPODIS_MASK)
/*! @} */

/*! @name LVRFLG - Low Voltage Reset Flags Register */
/*! @{ */

#define PMC_LVRFLG_LVRF_MASK                     (0x1U)
#define PMC_LVRFLG_LVRF_SHIFT                    (0U)
#define PMC_LVRFLG_LVRF_WIDTH                    (1U)
#define PMC_LVRFLG_LVRF(x)                       (((uint8_t)(((uint8_t)(x)) << PMC_LVRFLG_LVRF_SHIFT)) & PMC_LVRFLG_LVRF_MASK)

#define PMC_LVRFLG_LVRLPF_MASK                   (0x2U)
#define PMC_LVRFLG_LVRLPF_SHIFT                  (1U)
#define PMC_LVRFLG_LVRLPF_WIDTH                  (1U)
#define PMC_LVRFLG_LVRLPF(x)                     (((uint8_t)(((uint8_t)(x)) << PMC_LVRFLG_LVRLPF_SHIFT)) & PMC_LVRFLG_LVRLPF_MASK)

#define PMC_LVRFLG_LVRXF_MASK                    (0x4U)
#define PMC_LVRFLG_LVRXF_SHIFT                   (2U)
#define PMC_LVRFLG_LVRXF_WIDTH                   (1U)
#define PMC_LVRFLG_LVRXF(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_LVRFLG_LVRXF_SHIFT)) & PMC_LVRFLG_LVRXF_MASK)

#define PMC_LVRFLG_LVRXLPF_MASK                  (0x8U)
#define PMC_LVRFLG_LVRXLPF_SHIFT                 (3U)
#define PMC_LVRFLG_LVRXLPF_WIDTH                 (1U)
#define PMC_LVRFLG_LVRXLPF(x)                    (((uint8_t)(((uint8_t)(x)) << PMC_LVRFLG_LVRXLPF_SHIFT)) & PMC_LVRFLG_LVRXLPF_MASK)

#define PMC_LVRFLG_LVR3F_MASK                    (0x10U)
#define PMC_LVRFLG_LVR3F_SHIFT                   (4U)
#define PMC_LVRFLG_LVR3F_WIDTH                   (1U)
#define PMC_LVRFLG_LVR3F(x)                      (((uint8_t)(((uint8_t)(x)) << PMC_LVRFLG_LVR3F_SHIFT)) & PMC_LVRFLG_LVR3F_MASK)

#define PMC_LVRFLG_LVR3FLSF_MASK                 (0x20U)
#define PMC_LVRFLG_LVR3FLSF_SHIFT                (5U)
#define PMC_LVRFLG_LVR3FLSF_WIDTH                (1U)
#define PMC_LVRFLG_LVR3FLSF(x)                   (((uint8_t)(((uint8_t)(x)) << PMC_LVRFLG_LVR3FLSF_SHIFT)) & PMC_LVRFLG_LVR3FLSF_MASK)

#define PMC_LVRFLG_PORF_MASK                     (0x80U)
#define PMC_LVRFLG_PORF_SHIFT                    (7U)
#define PMC_LVRFLG_PORF_WIDTH                    (1U)
#define PMC_LVRFLG_PORF(x)                       (((uint8_t)(((uint8_t)(x)) << PMC_LVRFLG_PORF_SHIFT)) & PMC_LVRFLG_PORF_MASK)
/*! @} */

/*! @name LPOTRIM - Low Power Oscillator Trim Register */
/*! @{ */

#define PMC_LPOTRIM_LPOTRIM_MASK                 (0x1FU)
#define PMC_LPOTRIM_LPOTRIM_SHIFT                (0U)
#define PMC_LPOTRIM_LPOTRIM_WIDTH                (5U)
#define PMC_LPOTRIM_LPOTRIM(x)                   (((uint8_t)(((uint8_t)(x)) << PMC_LPOTRIM_LPOTRIM_SHIFT)) & PMC_LPOTRIM_LPOTRIM_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group PMC_Register_Masks */

/*!
 * @}
 */ /* end of group PMC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32M24x_PMC_H_) */
