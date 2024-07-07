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
 * @file S32K116_MTB_DWT.h
 * @version 1.1
 * @date 2022-01-21
 * @brief Peripheral Access Layer for S32K116_MTB_DWT
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
#if !defined(S32K116_MTB_DWT_H_)  /* Check if memory map has not been already included */
#define S32K116_MTB_DWT_H_

#include "S32K116_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MTB_DWT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTB_DWT_Peripheral_Access_Layer MTB_DWT Peripheral Access Layer
 * @{
 */

/** MTB_DWT - Size of Registers Arrays */
#define MTB_DWT_CMF_COUNT                         2u
#define MTB_DWT_PERIPHID_COUNT                    8u
#define MTB_DWT_COMPID_COUNT                      4u

/** MTB_DWT - Register Layout Typedef */
typedef struct {
  __I  uint32_t CTRL;                              /**< MTB DWT Control Register, offset: 0x0 */
  uint8_t RESERVED_0[28];
  struct {                                         /* offset: 0x20, array step: 0x10 */
    __IO uint32_t COMP;                              /**< MTB_DWT Comparator Register, array offset: 0x20, array step: 0x10 */
    __IO uint32_t MASK;                              /**< MTB_DWT Comparator Mask Register, array offset: 0x24, array step: 0x10 */
    __IO uint32_t FCT;                               /**< MTB_DWT Comparator Function Register 0..MTB_DWT Comparator Function Register 1, array offset: 0x28, array step: 0x10 */
    uint8_t RESERVED_0[4];
  } CMF[MTB_DWT_CMF_COUNT];
  uint8_t RESERVED_1[448];
  __IO uint32_t TBCTRL;                            /**< MTB_DWT Trace Buffer Control Register, offset: 0x200 */
  uint8_t RESERVED_2[3524];
  __I  uint32_t DEVICECFG;                         /**< Device Configuration Register, offset: 0xFC8 */
  __I  uint32_t DEVICETYPID;                       /**< Device Type Identifier Register, offset: 0xFCC */
  __I  uint32_t PERIPHID[MTB_DWT_PERIPHID_COUNT];  /**< Peripheral ID Register, array offset: 0xFD0, array step: 0x4 */
  __I  uint32_t COMPID[MTB_DWT_COMPID_COUNT];      /**< Component ID Register, array offset: 0xFF0, array step: 0x4 */
} MTB_DWT_Type, *MTB_DWT_MemMapPtr;

/** Number of instances of the MTB_DWT module. */
#define MTB_DWT_INSTANCE_COUNT                   (1u)

/* MTB_DWT - Peripheral instance base addresses */
/** Peripheral MTB_DWT base address */
#define IP_MTB_DWT_BASE                          (0xF0001000u)
/** Peripheral MTB_DWT base pointer */
#define IP_MTB_DWT                               ((MTB_DWT_Type *)IP_MTB_DWT_BASE)
/** Array initializer of MTB_DWT peripheral base addresses */
#define IP_MTB_DWT_BASE_ADDRS                    { IP_MTB_DWT_BASE }
/** Array initializer of MTB_DWT peripheral base pointers */
#define IP_MTB_DWT_BASE_PTRS                     { IP_MTB_DWT }

/* ----------------------------------------------------------------------------
   -- MTB_DWT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MTB_DWT_Register_Masks MTB_DWT Register Masks
 * @{
 */

/*! @name CTRL - MTB DWT Control Register */
/*! @{ */

#define MTB_DWT_CTRL_DWTCFGCTRL_MASK             (0xFFFFFFFU)
#define MTB_DWT_CTRL_DWTCFGCTRL_SHIFT            (0U)
#define MTB_DWT_CTRL_DWTCFGCTRL_WIDTH            (28U)
#define MTB_DWT_CTRL_DWTCFGCTRL(x)               (((uint32_t)(((uint32_t)(x)) << MTB_DWT_CTRL_DWTCFGCTRL_SHIFT)) & MTB_DWT_CTRL_DWTCFGCTRL_MASK)

#define MTB_DWT_CTRL_NUMCMP_MASK                 (0xF0000000U)
#define MTB_DWT_CTRL_NUMCMP_SHIFT                (28U)
#define MTB_DWT_CTRL_NUMCMP_WIDTH                (4U)
#define MTB_DWT_CTRL_NUMCMP(x)                   (((uint32_t)(((uint32_t)(x)) << MTB_DWT_CTRL_NUMCMP_SHIFT)) & MTB_DWT_CTRL_NUMCMP_MASK)
/*! @} */

/*! @name COMP - MTB_DWT Comparator Register */
/*! @{ */

#define MTB_DWT_COMP_COMP_MASK                   (0xFFFFFFFFU)
#define MTB_DWT_COMP_COMP_SHIFT                  (0U)
#define MTB_DWT_COMP_COMP_WIDTH                  (32U)
#define MTB_DWT_COMP_COMP(x)                     (((uint32_t)(((uint32_t)(x)) << MTB_DWT_COMP_COMP_SHIFT)) & MTB_DWT_COMP_COMP_MASK)
/*! @} */

/*! @name MASK - MTB_DWT Comparator Mask Register */
/*! @{ */

#define MTB_DWT_MASK_MASK_MASK                   (0x1FU)
#define MTB_DWT_MASK_MASK_SHIFT                  (0U)
#define MTB_DWT_MASK_MASK_WIDTH                  (5U)
#define MTB_DWT_MASK_MASK(x)                     (((uint32_t)(((uint32_t)(x)) << MTB_DWT_MASK_MASK_SHIFT)) & MTB_DWT_MASK_MASK_MASK)
/*! @} */

/*! @name FCT - MTB_DWT Comparator Function Register 0..MTB_DWT Comparator Function Register 1 */
/*! @{ */

#define MTB_DWT_FCT_FUNCTION_MASK                (0xFU)
#define MTB_DWT_FCT_FUNCTION_SHIFT               (0U)
#define MTB_DWT_FCT_FUNCTION_WIDTH               (4U)
#define MTB_DWT_FCT_FUNCTION(x)                  (((uint32_t)(((uint32_t)(x)) << MTB_DWT_FCT_FUNCTION_SHIFT)) & MTB_DWT_FCT_FUNCTION_MASK)

#define MTB_DWT_FCT_DATAVMATCH_MASK              (0x100U)
#define MTB_DWT_FCT_DATAVMATCH_SHIFT             (8U)
#define MTB_DWT_FCT_DATAVMATCH_WIDTH             (1U)
#define MTB_DWT_FCT_DATAVMATCH(x)                (((uint32_t)(((uint32_t)(x)) << MTB_DWT_FCT_DATAVMATCH_SHIFT)) & MTB_DWT_FCT_DATAVMATCH_MASK)

#define MTB_DWT_FCT_DATAVSIZE_MASK               (0xC00U)
#define MTB_DWT_FCT_DATAVSIZE_SHIFT              (10U)
#define MTB_DWT_FCT_DATAVSIZE_WIDTH              (2U)
#define MTB_DWT_FCT_DATAVSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << MTB_DWT_FCT_DATAVSIZE_SHIFT)) & MTB_DWT_FCT_DATAVSIZE_MASK)

#define MTB_DWT_FCT_DATAVADDR0_MASK              (0xF000U)
#define MTB_DWT_FCT_DATAVADDR0_SHIFT             (12U)
#define MTB_DWT_FCT_DATAVADDR0_WIDTH             (4U)
#define MTB_DWT_FCT_DATAVADDR0(x)                (((uint32_t)(((uint32_t)(x)) << MTB_DWT_FCT_DATAVADDR0_SHIFT)) & MTB_DWT_FCT_DATAVADDR0_MASK)

#define MTB_DWT_FCT_MATCHED_MASK                 (0x1000000U)
#define MTB_DWT_FCT_MATCHED_SHIFT                (24U)
#define MTB_DWT_FCT_MATCHED_WIDTH                (1U)
#define MTB_DWT_FCT_MATCHED(x)                   (((uint32_t)(((uint32_t)(x)) << MTB_DWT_FCT_MATCHED_SHIFT)) & MTB_DWT_FCT_MATCHED_MASK)
/*! @} */

/*! @name TBCTRL - MTB_DWT Trace Buffer Control Register */
/*! @{ */

#define MTB_DWT_TBCTRL_ACOMP0_MASK               (0x1U)
#define MTB_DWT_TBCTRL_ACOMP0_SHIFT              (0U)
#define MTB_DWT_TBCTRL_ACOMP0_WIDTH              (1U)
#define MTB_DWT_TBCTRL_ACOMP0(x)                 (((uint32_t)(((uint32_t)(x)) << MTB_DWT_TBCTRL_ACOMP0_SHIFT)) & MTB_DWT_TBCTRL_ACOMP0_MASK)

#define MTB_DWT_TBCTRL_ACOMP1_MASK               (0x2U)
#define MTB_DWT_TBCTRL_ACOMP1_SHIFT              (1U)
#define MTB_DWT_TBCTRL_ACOMP1_WIDTH              (1U)
#define MTB_DWT_TBCTRL_ACOMP1(x)                 (((uint32_t)(((uint32_t)(x)) << MTB_DWT_TBCTRL_ACOMP1_SHIFT)) & MTB_DWT_TBCTRL_ACOMP1_MASK)

#define MTB_DWT_TBCTRL_NUMCOMP_MASK              (0xF0000000U)
#define MTB_DWT_TBCTRL_NUMCOMP_SHIFT             (28U)
#define MTB_DWT_TBCTRL_NUMCOMP_WIDTH             (4U)
#define MTB_DWT_TBCTRL_NUMCOMP(x)                (((uint32_t)(((uint32_t)(x)) << MTB_DWT_TBCTRL_NUMCOMP_SHIFT)) & MTB_DWT_TBCTRL_NUMCOMP_MASK)
/*! @} */

/*! @name DEVICECFG - Device Configuration Register */
/*! @{ */

#define MTB_DWT_DEVICECFG_DEVICECFG_MASK         (0xFFFFFFFFU)
#define MTB_DWT_DEVICECFG_DEVICECFG_SHIFT        (0U)
#define MTB_DWT_DEVICECFG_DEVICECFG_WIDTH        (32U)
#define MTB_DWT_DEVICECFG_DEVICECFG(x)           (((uint32_t)(((uint32_t)(x)) << MTB_DWT_DEVICECFG_DEVICECFG_SHIFT)) & MTB_DWT_DEVICECFG_DEVICECFG_MASK)
/*! @} */

/*! @name DEVICETYPID - Device Type Identifier Register */
/*! @{ */

#define MTB_DWT_DEVICETYPID_DEVICETYPID_MASK     (0xFFFFFFFFU)
#define MTB_DWT_DEVICETYPID_DEVICETYPID_SHIFT    (0U)
#define MTB_DWT_DEVICETYPID_DEVICETYPID_WIDTH    (32U)
#define MTB_DWT_DEVICETYPID_DEVICETYPID(x)       (((uint32_t)(((uint32_t)(x)) << MTB_DWT_DEVICETYPID_DEVICETYPID_SHIFT)) & MTB_DWT_DEVICETYPID_DEVICETYPID_MASK)
/*! @} */

/*! @name PERIPHID - Peripheral ID Register */
/*! @{ */

#define MTB_DWT_PERIPHID_PERIPHID_MASK           (0xFFFFFFFFU)
#define MTB_DWT_PERIPHID_PERIPHID_SHIFT          (0U)
#define MTB_DWT_PERIPHID_PERIPHID_WIDTH          (32U)
#define MTB_DWT_PERIPHID_PERIPHID(x)             (((uint32_t)(((uint32_t)(x)) << MTB_DWT_PERIPHID_PERIPHID_SHIFT)) & MTB_DWT_PERIPHID_PERIPHID_MASK)
/*! @} */

/*! @name COMPID - Component ID Register */
/*! @{ */

#define MTB_DWT_COMPID_COMPID_MASK               (0xFFFFFFFFU)
#define MTB_DWT_COMPID_COMPID_SHIFT              (0U)
#define MTB_DWT_COMPID_COMPID_WIDTH              (32U)
#define MTB_DWT_COMPID_COMPID(x)                 (((uint32_t)(((uint32_t)(x)) << MTB_DWT_COMPID_COMPID_SHIFT)) & MTB_DWT_COMPID_COMPID_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MTB_DWT_Register_Masks */

/*!
 * @}
 */ /* end of group MTB_DWT_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K116_MTB_DWT_H_) */
