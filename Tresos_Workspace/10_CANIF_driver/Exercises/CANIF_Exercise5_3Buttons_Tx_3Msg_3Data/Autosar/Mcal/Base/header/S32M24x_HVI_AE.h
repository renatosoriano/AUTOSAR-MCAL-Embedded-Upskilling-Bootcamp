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
 * @file S32M24x_HVI_AE.h
 * @version 1.3
 * @date 2023-05-30
 * @brief Peripheral Access Layer for S32M24x_HVI_AE
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
#if !defined(S32M24x_HVI_AE_H_)  /* Check if memory map has not been already included */
#define S32M24x_HVI_AE_H_

#include "S32M24x_COMMON.h"

/* ----------------------------------------------------------------------------
   -- HVI_AE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HVI_AE_Peripheral_Access_Layer HVI_AE Peripheral Access Layer
 * @{
 */

/** HVI_AE - Size of Registers Arrays */
#define HVI_AE_UCTRL_ARRAY_COUNT                  2u

/** HVI_AE - Register Layout Typedef */
typedef struct {
  __IO uint32_t INTF;                              /**< Interrupt Flags, offset: 0x0 */
  __IO uint32_t INTEN;                             /**< Interrupt Enables, offset: 0x4 */
  __I  uint32_t STAT;                              /**< Status, offset: 0x8 */
  __IO uint32_t GCTRL;                             /**< Global Control, offset: 0xC */
  uint8_t RESERVED_0[4];
  struct {                                         /* offset: 0x14, array step: 0x4 */
    __IO uint16_t UCFG;                              /**< Unit Configuration 0..Unit Configuration 1, array offset: 0x14, array step: 0x4 */
    __IO uint8_t UCTRL;                              /**< Unit Control 0..Unit Control 1, array offset: 0x16, array step: 0x4 */
    __IO uint8_t VMCFG;                              /**< Voltage Monitor Configuration 0, array offset: 0x17, array step: 0x4, valid indices: [0] */
  } UCTRL_ARRAY[HVI_AE_UCTRL_ARRAY_COUNT];
} HVI_AE_Type, *HVI_AE_MemMapPtr;

/** Number of instances of the HVI_AE module. */
#define HVI_AE_INSTANCE_COUNT                    (1u)

/* HVI_AE - Peripheral instance base addresses */
/** Peripheral HVI_AE base address */
#define IP_HVI_AE_BASE                           (0x200u)
/** Peripheral HVI_AE base pointer */
#define IP_HVI_AE                                ((HVI_AE_Type *)IP_HVI_AE_BASE)
/** Array initializer of HVI_AE peripheral base addresses */
#define IP_HVI_AE_BASE_ADDRS                     { IP_HVI_AE_BASE }
/** Array initializer of HVI_AE peripheral base pointers */
#define IP_HVI_AE_BASE_PTRS                      { IP_HVI_AE }

/* ----------------------------------------------------------------------------
   -- HVI_AE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HVI_AE_Register_Masks HVI_AE Register Masks
 * @{
 */

/*! @name INTF - Interrupt Flags */
/*! @{ */

#define HVI_AE_INTF_LDIF0_MASK                   (0x1U)
#define HVI_AE_INTF_LDIF0_SHIFT                  (0U)
#define HVI_AE_INTF_LDIF0_WIDTH                  (1U)
#define HVI_AE_INTF_LDIF0(x)                     (((uint32_t)(((uint32_t)(x)) << HVI_AE_INTF_LDIF0_SHIFT)) & HVI_AE_INTF_LDIF0_MASK)

#define HVI_AE_INTF_HDIF0_MASK                   (0x100U)
#define HVI_AE_INTF_HDIF0_SHIFT                  (8U)
#define HVI_AE_INTF_HDIF0_WIDTH                  (1U)
#define HVI_AE_INTF_HDIF0(x)                     (((uint32_t)(((uint32_t)(x)) << HVI_AE_INTF_HDIF0_SHIFT)) & HVI_AE_INTF_HDIF0_MASK)

#define HVI_AE_INTF_DINIF0_MASK                  (0x10000U)
#define HVI_AE_INTF_DINIF0_SHIFT                 (16U)
#define HVI_AE_INTF_DINIF0_WIDTH                 (1U)
#define HVI_AE_INTF_DINIF0(x)                    (((uint32_t)(((uint32_t)(x)) << HVI_AE_INTF_DINIF0_SHIFT)) & HVI_AE_INTF_DINIF0_MASK)

#define HVI_AE_INTF_DINIF1_MASK                  (0x20000U)
#define HVI_AE_INTF_DINIF1_SHIFT                 (17U)
#define HVI_AE_INTF_DINIF1_WIDTH                 (1U)
#define HVI_AE_INTF_DINIF1(x)                    (((uint32_t)(((uint32_t)(x)) << HVI_AE_INTF_DINIF1_SHIFT)) & HVI_AE_INTF_DINIF1_MASK)
/*! @} */

/*! @name INTEN - Interrupt Enables */
/*! @{ */

#define HVI_AE_INTEN_LDIE0_MASK                  (0x1U)
#define HVI_AE_INTEN_LDIE0_SHIFT                 (0U)
#define HVI_AE_INTEN_LDIE0_WIDTH                 (1U)
#define HVI_AE_INTEN_LDIE0(x)                    (((uint32_t)(((uint32_t)(x)) << HVI_AE_INTEN_LDIE0_SHIFT)) & HVI_AE_INTEN_LDIE0_MASK)

#define HVI_AE_INTEN_HDIE0_MASK                  (0x100U)
#define HVI_AE_INTEN_HDIE0_SHIFT                 (8U)
#define HVI_AE_INTEN_HDIE0_WIDTH                 (1U)
#define HVI_AE_INTEN_HDIE0(x)                    (((uint32_t)(((uint32_t)(x)) << HVI_AE_INTEN_HDIE0_SHIFT)) & HVI_AE_INTEN_HDIE0_MASK)

#define HVI_AE_INTEN_DINIE0_MASK                 (0x10000U)
#define HVI_AE_INTEN_DINIE0_SHIFT                (16U)
#define HVI_AE_INTEN_DINIE0_WIDTH                (1U)
#define HVI_AE_INTEN_DINIE0(x)                   (((uint32_t)(((uint32_t)(x)) << HVI_AE_INTEN_DINIE0_SHIFT)) & HVI_AE_INTEN_DINIE0_MASK)

#define HVI_AE_INTEN_DINIE1_MASK                 (0x20000U)
#define HVI_AE_INTEN_DINIE1_SHIFT                (17U)
#define HVI_AE_INTEN_DINIE1_WIDTH                (1U)
#define HVI_AE_INTEN_DINIE1(x)                   (((uint32_t)(((uint32_t)(x)) << HVI_AE_INTEN_DINIE1_SHIFT)) & HVI_AE_INTEN_DINIE1_MASK)
/*! @} */

/*! @name STAT - Status */
/*! @{ */

#define HVI_AE_STAT_LDS0_MASK                    (0x1U)
#define HVI_AE_STAT_LDS0_SHIFT                   (0U)
#define HVI_AE_STAT_LDS0_WIDTH                   (1U)
#define HVI_AE_STAT_LDS0(x)                      (((uint32_t)(((uint32_t)(x)) << HVI_AE_STAT_LDS0_SHIFT)) & HVI_AE_STAT_LDS0_MASK)

#define HVI_AE_STAT_HDS0_MASK                    (0x100U)
#define HVI_AE_STAT_HDS0_SHIFT                   (8U)
#define HVI_AE_STAT_HDS0_WIDTH                   (1U)
#define HVI_AE_STAT_HDS0(x)                      (((uint32_t)(((uint32_t)(x)) << HVI_AE_STAT_HDS0_SHIFT)) & HVI_AE_STAT_HDS0_MASK)

#define HVI_AE_STAT_DINS0_MASK                   (0x10000U)
#define HVI_AE_STAT_DINS0_SHIFT                  (16U)
#define HVI_AE_STAT_DINS0_WIDTH                  (1U)
#define HVI_AE_STAT_DINS0(x)                     (((uint32_t)(((uint32_t)(x)) << HVI_AE_STAT_DINS0_SHIFT)) & HVI_AE_STAT_DINS0_MASK)

#define HVI_AE_STAT_DINS1_MASK                   (0x20000U)
#define HVI_AE_STAT_DINS1_SHIFT                  (17U)
#define HVI_AE_STAT_DINS1_WIDTH                  (1U)
#define HVI_AE_STAT_DINS1(x)                     (((uint32_t)(((uint32_t)(x)) << HVI_AE_STAT_DINS1_SHIFT)) & HVI_AE_STAT_DINS1_MASK)
/*! @} */

/*! @name GCTRL - Global Control */
/*! @{ */

#define HVI_AE_GCTRL_AINEN_MASK                  (0x7U)
#define HVI_AE_GCTRL_AINEN_SHIFT                 (0U)
#define HVI_AE_GCTRL_AINEN_WIDTH                 (3U)
#define HVI_AE_GCTRL_AINEN(x)                    (((uint32_t)(((uint32_t)(x)) << HVI_AE_GCTRL_AINEN_SHIFT)) & HVI_AE_GCTRL_AINEN_MASK)

#define HVI_AE_GCTRL_AINSEL_MASK                 (0x18U)
#define HVI_AE_GCTRL_AINSEL_SHIFT                (3U)
#define HVI_AE_GCTRL_AINSEL_WIDTH                (2U)
#define HVI_AE_GCTRL_AINSEL(x)                   (((uint32_t)(((uint32_t)(x)) << HVI_AE_GCTRL_AINSEL_SHIFT)) & HVI_AE_GCTRL_AINSEL_MASK)
/*! @} */

/*! @name UCFG - Unit Configuration 0..Unit Configuration 1 */
/*! @{ */

#define HVI_AE_UCFG_PDEN_MASK                    (0x2U)
#define HVI_AE_UCFG_PDEN_SHIFT                   (1U)
#define HVI_AE_UCFG_PDEN_WIDTH                   (1U)
#define HVI_AE_UCFG_PDEN(x)                      (((uint16_t)(((uint16_t)(x)) << HVI_AE_UCFG_PDEN_SHIFT)) & HVI_AE_UCFG_PDEN_MASK)

#define HVI_AE_UCFG_PUEN_MASK                    (0x4U)
#define HVI_AE_UCFG_PUEN_SHIFT                   (2U)
#define HVI_AE_UCFG_PUEN_WIDTH                   (1U)
#define HVI_AE_UCFG_PUEN(x)                      (((uint16_t)(((uint16_t)(x)) << HVI_AE_UCFG_PUEN_SHIFT)) & HVI_AE_UCFG_PUEN_MASK)

#define HVI_AE_UCFG_DIVSEL_MASK                  (0x18U)
#define HVI_AE_UCFG_DIVSEL_SHIFT                 (3U)
#define HVI_AE_UCFG_DIVSEL_WIDTH                 (2U)
#define HVI_AE_UCFG_DIVSEL(x)                    (((uint16_t)(((uint16_t)(x)) << HVI_AE_UCFG_DIVSEL_SHIFT)) & HVI_AE_UCFG_DIVSEL_MASK)

#define HVI_AE_UCFG_DINEN_MASK                   (0x100U)
#define HVI_AE_UCFG_DINEN_SHIFT                  (8U)
#define HVI_AE_UCFG_DINEN_WIDTH                  (1U)
#define HVI_AE_UCFG_DINEN(x)                     (((uint16_t)(((uint16_t)(x)) << HVI_AE_UCFG_DINEN_SHIFT)) & HVI_AE_UCFG_DINEN_MASK)

#define HVI_AE_UCFG_DINPO_MASK                   (0x200U)
#define HVI_AE_UCFG_DINPO_SHIFT                  (9U)
#define HVI_AE_UCFG_DINPO_WIDTH                  (1U)
#define HVI_AE_UCFG_DINPO(x)                     (((uint16_t)(((uint16_t)(x)) << HVI_AE_UCFG_DINPO_SHIFT)) & HVI_AE_UCFG_DINPO_MASK)
/*! @} */

/*! @name UCTRL - Unit Control 0..Unit Control 1 */
/*! @{ */

#define HVI_AE_UCTRL_EN_MASK                     (0x1U)
#define HVI_AE_UCTRL_EN_SHIFT                    (0U)
#define HVI_AE_UCTRL_EN_WIDTH                    (1U)
#define HVI_AE_UCTRL_EN(x)                       (((uint8_t)(((uint8_t)(x)) << HVI_AE_UCTRL_EN_SHIFT)) & HVI_AE_UCTRL_EN_MASK)

#define HVI_AE_UCTRL_CFGEN_MASK                  (0x2U)
#define HVI_AE_UCTRL_CFGEN_SHIFT                 (1U)
#define HVI_AE_UCTRL_CFGEN_WIDTH                 (1U)
#define HVI_AE_UCTRL_CFGEN(x)                    (((uint8_t)(((uint8_t)(x)) << HVI_AE_UCTRL_CFGEN_SHIFT)) & HVI_AE_UCTRL_CFGEN_MASK)
/*! @} */

/*! @name VMCFG - Voltage Monitor Configuration 0 */
/*! @{ */

#define HVI_AE_VMCFG_LDEN_MASK                   (0x1U)
#define HVI_AE_VMCFG_LDEN_SHIFT                  (0U)
#define HVI_AE_VMCFG_LDEN_WIDTH                  (1U)
#define HVI_AE_VMCFG_LDEN(x)                     (((uint8_t)(((uint8_t)(x)) << HVI_AE_VMCFG_LDEN_SHIFT)) & HVI_AE_VMCFG_LDEN_MASK)

#define HVI_AE_VMCFG_HDEN_MASK                   (0x2U)
#define HVI_AE_VMCFG_HDEN_SHIFT                  (1U)
#define HVI_AE_VMCFG_HDEN_WIDTH                  (1U)
#define HVI_AE_VMCFG_HDEN(x)                     (((uint8_t)(((uint8_t)(x)) << HVI_AE_VMCFG_HDEN_SHIFT)) & HVI_AE_VMCFG_HDEN_MASK)

#define HVI_AE_VMCFG_LDREFSEL_MASK               (0xCU)
#define HVI_AE_VMCFG_LDREFSEL_SHIFT              (2U)
#define HVI_AE_VMCFG_LDREFSEL_WIDTH              (2U)
#define HVI_AE_VMCFG_LDREFSEL(x)                 (((uint8_t)(((uint8_t)(x)) << HVI_AE_VMCFG_LDREFSEL_SHIFT)) & HVI_AE_VMCFG_LDREFSEL_MASK)

#define HVI_AE_VMCFG_HDREFSEL_MASK               (0x20U)
#define HVI_AE_VMCFG_HDREFSEL_SHIFT              (5U)
#define HVI_AE_VMCFG_HDREFSEL_WIDTH              (1U)
#define HVI_AE_VMCFG_HDREFSEL(x)                 (((uint8_t)(((uint8_t)(x)) << HVI_AE_VMCFG_HDREFSEL_SHIFT)) & HVI_AE_VMCFG_HDREFSEL_MASK)

#define HVI_AE_VMCFG_VMINSEL_MASK                (0x80U)
#define HVI_AE_VMCFG_VMINSEL_SHIFT               (7U)
#define HVI_AE_VMCFG_VMINSEL_WIDTH               (1U)
#define HVI_AE_VMCFG_VMINSEL(x)                  (((uint8_t)(((uint8_t)(x)) << HVI_AE_VMCFG_VMINSEL_SHIFT)) & HVI_AE_VMCFG_VMINSEL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group HVI_AE_Register_Masks */

/*!
 * @}
 */ /* end of group HVI_AE_Peripheral_Access_Layer */

#endif  /* #if !defined(S32M24x_HVI_AE_H_) */
