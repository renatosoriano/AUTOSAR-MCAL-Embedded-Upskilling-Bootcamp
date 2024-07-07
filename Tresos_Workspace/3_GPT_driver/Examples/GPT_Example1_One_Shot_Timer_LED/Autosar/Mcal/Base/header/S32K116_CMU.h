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
 * @file S32K116_CMU.h
 * @version 1.1
 * @date 2022-01-21
 * @brief Peripheral Access Layer for S32K116_CMU
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
#if !defined(S32K116_CMU_H_)  /* Check if memory map has not been already included */
#define S32K116_CMU_H_

#include "S32K116_COMMON.h"

/* ----------------------------------------------------------------------------
   -- CMU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMU_Peripheral_Access_Layer CMU Peripheral Access Layer
 * @{
 */

/** CMU - Register Layout Typedef */
typedef struct {
  __IO uint32_t GCR;                               /**< Global Configuration Register, offset: 0x0 */
  __IO uint32_t RCCR;                              /**< Reference Count Configuration Register, offset: 0x4 */
  __IO uint32_t HTCR;                              /**< High Threshold Configuration Register, offset: 0x8 */
  __IO uint32_t LTCR;                              /**< Low Threshold Configuration Register, offset: 0xC */
  __IO uint32_t SR;                                /**< Status Register, offset: 0x10 */
  __IO uint32_t IER;                               /**< Interrupt Enable Register, offset: 0x14 */
} CMU_Type, *CMU_MemMapPtr;

/** Number of instances of the CMU module. */
#define CMU_INSTANCE_COUNT                       (2u)

/* CMU - Peripheral instance base addresses */
/** Peripheral CMU0 base address */
#define IP_CMU0_BASE                             (0x4003E000u)
/** Peripheral CMU0 base pointer */
#define IP_CMU0                                  ((CMU_Type *)IP_CMU0_BASE)
/** Peripheral CMU1 base address */
#define IP_CMU1_BASE                             (0x4003F000u)
/** Peripheral CMU1 base pointer */
#define IP_CMU1                                  ((CMU_Type *)IP_CMU1_BASE)
/** Array initializer of CMU peripheral base addresses */
#define IP_CMU_BASE_ADDRS                        { IP_CMU0_BASE, IP_CMU1_BASE }
/** Array initializer of CMU peripheral base pointers */
#define IP_CMU_BASE_PTRS                         { IP_CMU0, IP_CMU1 }

/* ----------------------------------------------------------------------------
   -- CMU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CMU_Register_Masks CMU Register Masks
 * @{
 */

/*! @name GCR - Global Configuration Register */
/*! @{ */

#define CMU_GCR_FCE_MASK                         (0x1U)
#define CMU_GCR_FCE_SHIFT                        (0U)
#define CMU_GCR_FCE_WIDTH                        (1U)
#define CMU_GCR_FCE(x)                           (((uint32_t)(((uint32_t)(x)) << CMU_GCR_FCE_SHIFT)) & CMU_GCR_FCE_MASK)
/*! @} */

/*! @name RCCR - Reference Count Configuration Register */
/*! @{ */

#define CMU_RCCR_REF_CNT_MASK                    (0xFFFFU)
#define CMU_RCCR_REF_CNT_SHIFT                   (0U)
#define CMU_RCCR_REF_CNT_WIDTH                   (16U)
#define CMU_RCCR_REF_CNT(x)                      (((uint32_t)(((uint32_t)(x)) << CMU_RCCR_REF_CNT_SHIFT)) & CMU_RCCR_REF_CNT_MASK)
/*! @} */

/*! @name HTCR - High Threshold Configuration Register */
/*! @{ */

#define CMU_HTCR_HFREF_MASK                      (0xFFFFFFU)
#define CMU_HTCR_HFREF_SHIFT                     (0U)
#define CMU_HTCR_HFREF_WIDTH                     (24U)
#define CMU_HTCR_HFREF(x)                        (((uint32_t)(((uint32_t)(x)) << CMU_HTCR_HFREF_SHIFT)) & CMU_HTCR_HFREF_MASK)
/*! @} */

/*! @name LTCR - Low Threshold Configuration Register */
/*! @{ */

#define CMU_LTCR_LFREF_MASK                      (0xFFFFFFU)
#define CMU_LTCR_LFREF_SHIFT                     (0U)
#define CMU_LTCR_LFREF_WIDTH                     (24U)
#define CMU_LTCR_LFREF(x)                        (((uint32_t)(((uint32_t)(x)) << CMU_LTCR_LFREF_SHIFT)) & CMU_LTCR_LFREF_MASK)
/*! @} */

/*! @name SR - Status Register */
/*! @{ */

#define CMU_SR_FLL_MASK                          (0x1U)
#define CMU_SR_FLL_SHIFT                         (0U)
#define CMU_SR_FLL_WIDTH                         (1U)
#define CMU_SR_FLL(x)                            (((uint32_t)(((uint32_t)(x)) << CMU_SR_FLL_SHIFT)) & CMU_SR_FLL_MASK)

#define CMU_SR_FHH_MASK                          (0x2U)
#define CMU_SR_FHH_SHIFT                         (1U)
#define CMU_SR_FHH_WIDTH                         (1U)
#define CMU_SR_FHH(x)                            (((uint32_t)(((uint32_t)(x)) << CMU_SR_FHH_SHIFT)) & CMU_SR_FHH_MASK)

#define CMU_SR_STATE_MASK                        (0xCU)
#define CMU_SR_STATE_SHIFT                       (2U)
#define CMU_SR_STATE_WIDTH                       (2U)
#define CMU_SR_STATE(x)                          (((uint32_t)(((uint32_t)(x)) << CMU_SR_STATE_SHIFT)) & CMU_SR_STATE_MASK)

#define CMU_SR_RS_MASK                           (0x10U)
#define CMU_SR_RS_SHIFT                          (4U)
#define CMU_SR_RS_WIDTH                          (1U)
#define CMU_SR_RS(x)                             (((uint32_t)(((uint32_t)(x)) << CMU_SR_RS_SHIFT)) & CMU_SR_RS_MASK)
/*! @} */

/*! @name IER - Interrupt Enable Register */
/*! @{ */

#define CMU_IER_FLLIE_MASK                       (0x1U)
#define CMU_IER_FLLIE_SHIFT                      (0U)
#define CMU_IER_FLLIE_WIDTH                      (1U)
#define CMU_IER_FLLIE(x)                         (((uint32_t)(((uint32_t)(x)) << CMU_IER_FLLIE_SHIFT)) & CMU_IER_FLLIE_MASK)

#define CMU_IER_FHHIE_MASK                       (0x2U)
#define CMU_IER_FHHIE_SHIFT                      (1U)
#define CMU_IER_FHHIE_WIDTH                      (1U)
#define CMU_IER_FHHIE(x)                         (((uint32_t)(((uint32_t)(x)) << CMU_IER_FHHIE_SHIFT)) & CMU_IER_FHHIE_MASK)

#define CMU_IER_FLLAIE_MASK                      (0x4U)
#define CMU_IER_FLLAIE_SHIFT                     (2U)
#define CMU_IER_FLLAIE_WIDTH                     (1U)
#define CMU_IER_FLLAIE(x)                        (((uint32_t)(((uint32_t)(x)) << CMU_IER_FLLAIE_SHIFT)) & CMU_IER_FLLAIE_MASK)

#define CMU_IER_FHHAIE_MASK                      (0x8U)
#define CMU_IER_FHHAIE_SHIFT                     (3U)
#define CMU_IER_FHHAIE_WIDTH                     (1U)
#define CMU_IER_FHHAIE(x)                        (((uint32_t)(((uint32_t)(x)) << CMU_IER_FHHAIE_SHIFT)) & CMU_IER_FHHAIE_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group CMU_Register_Masks */

/*!
 * @}
 */ /* end of group CMU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K116_CMU_H_) */
