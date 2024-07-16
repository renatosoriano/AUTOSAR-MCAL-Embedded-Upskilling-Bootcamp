/*
** ###################################################################
**     Processor:           S32K144_M4
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K1XX RM Rev.14
**     Version:             rev. 1.1, 2022-02-07
**     Build:               b220207
**
**     Abstract:
**         Peripheral Access Layer for S32K144_M4
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
 * @file S32K144_EWM.h
 * @version 1.1
 * @date 2022-02-07
 * @brief Peripheral Access Layer for S32K144_EWM
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
#if !defined(S32K144_EWM_H_)  /* Check if memory map has not been already included */
#define S32K144_EWM_H_

#include "S32K144_COMMON.h"

/* ----------------------------------------------------------------------------
   -- EWM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EWM_Peripheral_Access_Layer EWM Peripheral Access Layer
 * @{
 */

/** EWM - Register Layout Typedef */
typedef struct {
  __IO uint8_t CTRL;                               /**< Control Register, offset: 0x0 */
  __O  uint8_t SERV;                               /**< Service Register, offset: 0x1 */
  __IO uint8_t CMPL;                               /**< Compare Low Register, offset: 0x2 */
  __IO uint8_t CMPH;                               /**< Compare High Register, offset: 0x3 */
  uint8_t RESERVED_0[1];
  __IO uint8_t CLKPRESCALER;                       /**< Clock Prescaler Register, offset: 0x5 */
} EWM_Type, *EWM_MemMapPtr;

/** Number of instances of the EWM module. */
#define EWM_INSTANCE_COUNT                       (1u)

/* EWM - Peripheral instance base addresses */
/** Peripheral EWM base address */
#define IP_EWM_BASE                              (0x40061000u)
/** Peripheral EWM base pointer */
#define IP_EWM                                   ((EWM_Type *)IP_EWM_BASE)
/** Array initializer of EWM peripheral base addresses */
#define IP_EWM_BASE_ADDRS                        { IP_EWM_BASE }
/** Array initializer of EWM peripheral base pointers */
#define IP_EWM_BASE_PTRS                         { IP_EWM }

/* ----------------------------------------------------------------------------
   -- EWM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup EWM_Register_Masks EWM Register Masks
 * @{
 */

/*! @name CTRL - Control Register */
/*! @{ */

#define EWM_CTRL_EWMEN_MASK                      (0x1U)
#define EWM_CTRL_EWMEN_SHIFT                     (0U)
#define EWM_CTRL_EWMEN_WIDTH                     (1U)
#define EWM_CTRL_EWMEN(x)                        (((uint8_t)(((uint8_t)(x)) << EWM_CTRL_EWMEN_SHIFT)) & EWM_CTRL_EWMEN_MASK)

#define EWM_CTRL_ASSIN_MASK                      (0x2U)
#define EWM_CTRL_ASSIN_SHIFT                     (1U)
#define EWM_CTRL_ASSIN_WIDTH                     (1U)
#define EWM_CTRL_ASSIN(x)                        (((uint8_t)(((uint8_t)(x)) << EWM_CTRL_ASSIN_SHIFT)) & EWM_CTRL_ASSIN_MASK)

#define EWM_CTRL_INEN_MASK                       (0x4U)
#define EWM_CTRL_INEN_SHIFT                      (2U)
#define EWM_CTRL_INEN_WIDTH                      (1U)
#define EWM_CTRL_INEN(x)                         (((uint8_t)(((uint8_t)(x)) << EWM_CTRL_INEN_SHIFT)) & EWM_CTRL_INEN_MASK)

#define EWM_CTRL_INTEN_MASK                      (0x8U)
#define EWM_CTRL_INTEN_SHIFT                     (3U)
#define EWM_CTRL_INTEN_WIDTH                     (1U)
#define EWM_CTRL_INTEN(x)                        (((uint8_t)(((uint8_t)(x)) << EWM_CTRL_INTEN_SHIFT)) & EWM_CTRL_INTEN_MASK)
/*! @} */

/*! @name SERV - Service Register */
/*! @{ */

#define EWM_SERV_SERVICE_MASK                    (0xFFU)
#define EWM_SERV_SERVICE_SHIFT                   (0U)
#define EWM_SERV_SERVICE_WIDTH                   (8U)
#define EWM_SERV_SERVICE(x)                      (((uint8_t)(((uint8_t)(x)) << EWM_SERV_SERVICE_SHIFT)) & EWM_SERV_SERVICE_MASK)
/*! @} */

/*! @name CMPL - Compare Low Register */
/*! @{ */

#define EWM_CMPL_COMPAREL_MASK                   (0xFFU)
#define EWM_CMPL_COMPAREL_SHIFT                  (0U)
#define EWM_CMPL_COMPAREL_WIDTH                  (8U)
#define EWM_CMPL_COMPAREL(x)                     (((uint8_t)(((uint8_t)(x)) << EWM_CMPL_COMPAREL_SHIFT)) & EWM_CMPL_COMPAREL_MASK)
/*! @} */

/*! @name CMPH - Compare High Register */
/*! @{ */

#define EWM_CMPH_COMPAREH_MASK                   (0xFFU)
#define EWM_CMPH_COMPAREH_SHIFT                  (0U)
#define EWM_CMPH_COMPAREH_WIDTH                  (8U)
#define EWM_CMPH_COMPAREH(x)                     (((uint8_t)(((uint8_t)(x)) << EWM_CMPH_COMPAREH_SHIFT)) & EWM_CMPH_COMPAREH_MASK)
/*! @} */

/*! @name CLKPRESCALER - Clock Prescaler Register */
/*! @{ */

#define EWM_CLKPRESCALER_CLK_DIV_MASK            (0xFFU)
#define EWM_CLKPRESCALER_CLK_DIV_SHIFT           (0U)
#define EWM_CLKPRESCALER_CLK_DIV_WIDTH           (8U)
#define EWM_CLKPRESCALER_CLK_DIV(x)              (((uint8_t)(((uint8_t)(x)) << EWM_CLKPRESCALER_CLK_DIV_SHIFT)) & EWM_CLKPRESCALER_CLK_DIV_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group EWM_Register_Masks */

/*!
 * @}
 */ /* end of group EWM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K144_EWM_H_) */
