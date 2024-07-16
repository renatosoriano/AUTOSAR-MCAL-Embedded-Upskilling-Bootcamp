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
** ###################################################################
*/

/*!
 * @file S32K142W_EIM.h
 * @version 1.2
 * @date 2022-02-10
 * @brief Peripheral Access Layer for S32K142W_EIM
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
#if !defined(S32K142W_EIM_H_)  /* Check if memory map has not been already included */
#define S32K142W_EIM_H_

#include "S32K142W_COMMON.h"

/* ----------------------------------------------------------------------------
   -- EIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EIM_Peripheral_Access_Layer EIM Peripheral Access Layer
 * @{
 */

/** EIM - Size of Registers Arrays */
#define EIM_EICHDn_COUNT                          2u

/** EIM - Register Layout Typedef */
typedef struct {
  __IO uint32_t EIMCR;                             /**< Error Injection Module Configuration Register, offset: 0x0 */
  __IO uint32_t EICHEN;                            /**< Error Injection Channel Enable register, offset: 0x4 */
  uint8_t RESERVED_0[248];
  struct {                                         /* offset: 0x100, array step: 0x40 */
    __IO uint32_t WORD0;                             /**< Error Injection Channel Descriptor n, Word0, array offset: 0x100, array step: 0x40 */
    __IO uint32_t WORD1;                             /**< Error Injection Channel Descriptor n, Word1, array offset: 0x104, array step: 0x40 */
    uint8_t RESERVED_0[56];
  } EICHDn[EIM_EICHDn_COUNT];
} EIM_Type, *EIM_MemMapPtr;

/** Number of instances of the EIM module. */
#define EIM_INSTANCE_COUNT                       (1u)

/* EIM - Peripheral instance base addresses */
/** Peripheral EIM base address */
#define IP_EIM_BASE                              (0x40019000u)
/** Peripheral EIM base pointer */
#define IP_EIM                                   ((EIM_Type *)IP_EIM_BASE)
/** Array initializer of EIM peripheral base addresses */
#define IP_EIM_BASE_ADDRS                        { IP_EIM_BASE }
/** Array initializer of EIM peripheral base pointers */
#define IP_EIM_BASE_PTRS                         { IP_EIM }

/* ----------------------------------------------------------------------------
   -- EIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EIM_Register_Masks EIM Register Masks
 * @{
 */

/*! @name EIMCR - Error Injection Module Configuration Register */
/*! @{ */

#define EIM_EIMCR_GEIEN_MASK                     (0x1U)
#define EIM_EIMCR_GEIEN_SHIFT                    (0U)
#define EIM_EIMCR_GEIEN_WIDTH                    (1U)
#define EIM_EIMCR_GEIEN(x)                       (((uint32_t)(((uint32_t)(x)) << EIM_EIMCR_GEIEN_SHIFT)) & EIM_EIMCR_GEIEN_MASK)
/*! @} */

/*! @name EICHEN - Error Injection Channel Enable register */
/*! @{ */

#define EIM_EICHEN_EICH1EN_MASK                  (0x40000000U)
#define EIM_EICHEN_EICH1EN_SHIFT                 (30U)
#define EIM_EICHEN_EICH1EN_WIDTH                 (1U)
#define EIM_EICHEN_EICH1EN(x)                    (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH1EN_SHIFT)) & EIM_EICHEN_EICH1EN_MASK)

#define EIM_EICHEN_EICH0EN_MASK                  (0x80000000U)
#define EIM_EICHEN_EICH0EN_SHIFT                 (31U)
#define EIM_EICHEN_EICH0EN_WIDTH                 (1U)
#define EIM_EICHEN_EICH0EN(x)                    (((uint32_t)(((uint32_t)(x)) << EIM_EICHEN_EICH0EN_SHIFT)) & EIM_EICHEN_EICH0EN_MASK)
/*! @} */

/*! @name EICHDn_WORD0 - Error Injection Channel Descriptor n, Word0 */
/*! @{ */

#define EIM_EICHDn_WORD0_CHKBIT_MASK_MASK        (0xFE000000U)
#define EIM_EICHDn_WORD0_CHKBIT_MASK_SHIFT       (25U)
#define EIM_EICHDn_WORD0_CHKBIT_MASK_WIDTH       (7U)
#define EIM_EICHDn_WORD0_CHKBIT_MASK(x)          (((uint32_t)(((uint32_t)(x)) << EIM_EICHDn_WORD0_CHKBIT_MASK_SHIFT)) & EIM_EICHDn_WORD0_CHKBIT_MASK_MASK)
/*! @} */

/*! @name EICHDn_WORD1 - Error Injection Channel Descriptor n, Word1 */
/*! @{ */

#define EIM_EICHDn_WORD1_B0_3DATA_MASK_MASK      (0xFFFFFFFFU)
#define EIM_EICHDn_WORD1_B0_3DATA_MASK_SHIFT     (0U)
#define EIM_EICHDn_WORD1_B0_3DATA_MASK_WIDTH     (32U)
#define EIM_EICHDn_WORD1_B0_3DATA_MASK(x)        (((uint32_t)(((uint32_t)(x)) << EIM_EICHDn_WORD1_B0_3DATA_MASK_SHIFT)) & EIM_EICHDn_WORD1_B0_3DATA_MASK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group EIM_Register_Masks */

/*!
 * @}
 */ /* end of group EIM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K142W_EIM_H_) */
