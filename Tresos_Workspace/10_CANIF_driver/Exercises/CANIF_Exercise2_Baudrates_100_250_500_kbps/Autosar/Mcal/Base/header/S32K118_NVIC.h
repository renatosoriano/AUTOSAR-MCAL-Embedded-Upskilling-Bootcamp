/*
** ###################################################################
**     Processor:           S32K118_M4
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K1XX RM Rev.13
**     Version:             rev. 1.0, 2021-02-18
**     Build:               b210218
**
**     Abstract:
**         Peripheral Access Layer for S32K118_M4
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2021 NXP
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
 * @file S32K118_NVIC.h
 * @version 1.0
 * @date 2021-02-18
 * @brief Peripheral Access Layer for S32K118_NVIC
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
#if !defined(S32K118_NVIC_H_)  /* Check if memory map has not been already included */
#define S32K118_NVIC_H_

#include "S32K118_COMMON.h"

/* ----------------------------------------------------------------------------
   -- S32_NVIC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S32_NVIC_Peripheral_Access_Layer S32_NVIC Peripheral Access Layer
 * @{
 */


/** S32_NVIC - Size of Registers Arrays */
#define S32_NVIC_ISER_COUNT                      1u
#define S32_NVIC_ICER_COUNT                      1u
#define S32_NVIC_ISPR_COUNT                      1u
#define S32_NVIC_ICPR_COUNT                      1u
#define S32_NVIC_IPR_COUNT                       8u

/** S32_NVIC - Register Layout Typedef */
typedef struct {
  __IO uint32_t ISER[S32_NVIC_ISER_COUNT];         /**< Interrupt Set Enable Register, array offset: 0x0, array step: 0x4 */
       uint8_t RESERVED_0[124];
  __IO uint32_t ICER[S32_NVIC_ICER_COUNT];         /**< Interrupt Clear Enable Register, array offset: 0x80, array step: 0x4 */
       uint8_t RESERVED_1[124];
  __IO uint32_t ISPR[S32_NVIC_ISPR_COUNT];         /**< Interrupt Set Pending Register, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_2[124];
  __IO uint32_t ICPR[S32_NVIC_ICPR_COUNT];         /**< Interrupt Clear Pending Register, array offset: 0x180, array step: 0x4 */
       uint8_t RESERVED_3[380];
  __IO uint32_t IP[S32_NVIC_IPR_COUNT];           /**< Interrupt Priority Register n, array offset: 0x300, array step: 0x4 */
} S32_NVIC_Type, *S32_NVIC_MemMapPtr;

 /** Number of instances of the S32_NVIC module. */
#define S32_NVIC_INSTANCE_COUNT                  (1u)


/* S32_NVIC - Peripheral instance base addresses */
/** Peripheral S32_NVIC base address */
#define S32_NVIC_BASE                            (0xE000E100u)
/** Peripheral S32_NVIC base pointer */
#define S32_NVIC                                 ((S32_NVIC_Type *)S32_NVIC_BASE)
/** Array initializer of S32_NVIC peripheral base addresses */
#define S32_NVIC_BASE_ADDRS                      { S32_NVIC_BASE }
/** Array initializer of S32_NVIC peripheral base pointers */
#define S32_NVIC_BASE_PTRS                       { S32_NVIC }

/* ----------------------------------------------------------------------------
   -- S32_NVIC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S32_NVIC_Register_Masks S32_NVIC Register Masks
 * @{
 */

/* ISER Bit Fields */
#define S32_NVIC_ISER_SETENA_MASK                0xFFFFFFFFu
#define S32_NVIC_ISER_SETENA_SHIFT               0u
#define S32_NVIC_ISER_SETENA_WIDTH               32u
#define S32_NVIC_ISER_SETENA(x)                  (((uint32_t)(((uint32_t)(x))<<S32_NVIC_ISER_SETENA_SHIFT))&S32_NVIC_ISER_SETENA_MASK)
/* ICER Bit Fields */
#define S32_NVIC_ICER_CLRENA_MASK                0xFFFFFFFFu
#define S32_NVIC_ICER_CLRENA_SHIFT               0u
#define S32_NVIC_ICER_CLRENA_WIDTH               32u
#define S32_NVIC_ICER_CLRENA(x)                  (((uint32_t)(((uint32_t)(x))<<S32_NVIC_ICER_CLRENA_SHIFT))&S32_NVIC_ICER_CLRENA_MASK)
/* ISPR Bit Fields */
#define S32_NVIC_ISPR_SETPEND_MASK               0xFFFFFFFFu
#define S32_NVIC_ISPR_SETPEND_SHIFT              0u
#define S32_NVIC_ISPR_SETPEND_WIDTH              32u
#define S32_NVIC_ISPR_SETPEND(x)                 (((uint32_t)(((uint32_t)(x))<<S32_NVIC_ISPR_SETPEND_SHIFT))&S32_NVIC_ISPR_SETPEND_MASK)
/* ICPR Bit Fields */
#define S32_NVIC_ICPR_CLRPEND_MASK               0xFFFFFFFFu
#define S32_NVIC_ICPR_CLRPEND_SHIFT              0u
#define S32_NVIC_ICPR_CLRPEND_WIDTH              32u
#define S32_NVIC_ICPR_CLRPEND(x)                 (((uint32_t)(((uint32_t)(x))<<S32_NVIC_ICPR_CLRPEND_SHIFT))&S32_NVIC_ICPR_CLRPEND_MASK)
/* IPR Bit Fields */
#define S32_NVIC_IPR_PRI_0_MASK                  0xFFu
#define S32_NVIC_IPR_PRI_0_SHIFT                 0u
#define S32_NVIC_IPR_PRI_0_WIDTH                 8u
#define S32_NVIC_IPR_PRI_0(x)                    (((uint32_t)(((uint32_t)(x))<<S32_NVIC_IPR_PRI_0_SHIFT))&S32_NVIC_IPR_PRI_0_MASK)
#define S32_NVIC_IPR_PRI_1_MASK                  0xFF00u
#define S32_NVIC_IPR_PRI_1_SHIFT                 8u
#define S32_NVIC_IPR_PRI_1_WIDTH                 8u
#define S32_NVIC_IPR_PRI_1(x)                    (((uint32_t)(((uint32_t)(x))<<S32_NVIC_IPR_PRI_1_SHIFT))&S32_NVIC_IPR_PRI_1_MASK)
#define S32_NVIC_IPR_PRI_2_MASK                  0xFF0000u
#define S32_NVIC_IPR_PRI_2_SHIFT                 16u
#define S32_NVIC_IPR_PRI_2_WIDTH                 8u
#define S32_NVIC_IPR_PRI_2(x)                    (((uint32_t)(((uint32_t)(x))<<S32_NVIC_IPR_PRI_2_SHIFT))&S32_NVIC_IPR_PRI_2_MASK)
#define S32_NVIC_IPR_PRI_3_MASK                  0xFF000000u
#define S32_NVIC_IPR_PRI_3_SHIFT                 24u
#define S32_NVIC_IPR_PRI_3_WIDTH                 8u
#define S32_NVIC_IPR_PRI_3(x)                    (((uint32_t)(((uint32_t)(x))<<S32_NVIC_IPR_PRI_3_SHIFT))&S32_NVIC_IPR_PRI_3_MASK)

/*!
 * @}
 */ /* end of group S32_NVIC_Register_Masks */


/*!
 * @}
 */ /* end of group S32_NVIC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K118_NVIC_H_) */
