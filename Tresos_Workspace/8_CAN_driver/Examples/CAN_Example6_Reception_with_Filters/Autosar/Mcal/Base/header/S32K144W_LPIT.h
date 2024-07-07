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
** ###################################################################
*/

/*!
 * @file S32K144W_LPIT.h
 * @version 1.4
 * @date 2022-02-09
 * @brief Peripheral Access Layer for S32K144W_LPIT
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
#if !defined(S32K144W_LPIT_H_)  /* Check if memory map has not been already included */
#define S32K144W_LPIT_H_

#include "S32K144W_COMMON.h"

/* ----------------------------------------------------------------------------
   -- LPIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPIT_Peripheral_Access_Layer LPIT Peripheral Access Layer
 * @{
 */

/** LPIT - Size of Registers Arrays */
#define LPIT_TMR_COUNT                            4u

/** LPIT - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t MCR;                               /**< Module Control Register, offset: 0x8 */
  __IO uint32_t MSR;                               /**< Module Status Register, offset: 0xC */
  __IO uint32_t MIER;                              /**< Module Interrupt Enable Register, offset: 0x10 */
  __IO uint32_t SETTEN;                            /**< Set Timer Enable Register, offset: 0x14 */
  __O  uint32_t CLRTEN;                            /**< Clear Timer Enable Register, offset: 0x18 */
  uint8_t RESERVED_0[4];
  struct {                                         /* offset: 0x20, array step: 0x10 */
    __IO uint32_t TVAL;                              /**< Timer Value Register, array offset: 0x20, array step: 0x10 */
    __I  uint32_t CVAL;                              /**< Current Timer Value, array offset: 0x24, array step: 0x10 */
    __IO uint32_t TCTRL;                             /**< Timer Control Register, array offset: 0x28, array step: 0x10 */
    uint8_t RESERVED_0[4];
  } TMR[LPIT_TMR_COUNT];
} LPIT_Type, *LPIT_MemMapPtr;

/** Number of instances of the LPIT module. */
#define LPIT_INSTANCE_COUNT                      (1u)

/* LPIT - Peripheral instance base addresses */
/** Peripheral LPIT0 base address */
#define IP_LPIT0_BASE                            (0x40037000u)
/** Peripheral LPIT0 base pointer */
#define IP_LPIT0                                 ((LPIT_Type *)IP_LPIT0_BASE)
/** Array initializer of LPIT peripheral base addresses */
#define IP_LPIT_BASE_ADDRS                       { IP_LPIT0_BASE }
/** Array initializer of LPIT peripheral base pointers */
#define IP_LPIT_BASE_PTRS                        { IP_LPIT0 }

/* ----------------------------------------------------------------------------
   -- LPIT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPIT_Register_Masks LPIT Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define LPIT_VERID_FEATURE_MASK                  (0xFFFFU)
#define LPIT_VERID_FEATURE_SHIFT                 (0U)
#define LPIT_VERID_FEATURE_WIDTH                 (16U)
#define LPIT_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x)) << LPIT_VERID_FEATURE_SHIFT)) & LPIT_VERID_FEATURE_MASK)

#define LPIT_VERID_MINOR_MASK                    (0xFF0000U)
#define LPIT_VERID_MINOR_SHIFT                   (16U)
#define LPIT_VERID_MINOR_WIDTH                   (8U)
#define LPIT_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << LPIT_VERID_MINOR_SHIFT)) & LPIT_VERID_MINOR_MASK)

#define LPIT_VERID_MAJOR_MASK                    (0xFF000000U)
#define LPIT_VERID_MAJOR_SHIFT                   (24U)
#define LPIT_VERID_MAJOR_WIDTH                   (8U)
#define LPIT_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << LPIT_VERID_MAJOR_SHIFT)) & LPIT_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter Register */
/*! @{ */

#define LPIT_PARAM_CHANNEL_MASK                  (0xFFU)
#define LPIT_PARAM_CHANNEL_SHIFT                 (0U)
#define LPIT_PARAM_CHANNEL_WIDTH                 (8U)
#define LPIT_PARAM_CHANNEL(x)                    (((uint32_t)(((uint32_t)(x)) << LPIT_PARAM_CHANNEL_SHIFT)) & LPIT_PARAM_CHANNEL_MASK)

#define LPIT_PARAM_EXT_TRIG_MASK                 (0xFF00U)
#define LPIT_PARAM_EXT_TRIG_SHIFT                (8U)
#define LPIT_PARAM_EXT_TRIG_WIDTH                (8U)
#define LPIT_PARAM_EXT_TRIG(x)                   (((uint32_t)(((uint32_t)(x)) << LPIT_PARAM_EXT_TRIG_SHIFT)) & LPIT_PARAM_EXT_TRIG_MASK)
/*! @} */

/*! @name MCR - Module Control Register */
/*! @{ */

#define LPIT_MCR_M_CEN_MASK                      (0x1U)
#define LPIT_MCR_M_CEN_SHIFT                     (0U)
#define LPIT_MCR_M_CEN_WIDTH                     (1U)
#define LPIT_MCR_M_CEN(x)                        (((uint32_t)(((uint32_t)(x)) << LPIT_MCR_M_CEN_SHIFT)) & LPIT_MCR_M_CEN_MASK)

#define LPIT_MCR_SW_RST_MASK                     (0x2U)
#define LPIT_MCR_SW_RST_SHIFT                    (1U)
#define LPIT_MCR_SW_RST_WIDTH                    (1U)
#define LPIT_MCR_SW_RST(x)                       (((uint32_t)(((uint32_t)(x)) << LPIT_MCR_SW_RST_SHIFT)) & LPIT_MCR_SW_RST_MASK)

#define LPIT_MCR_DOZE_EN_MASK                    (0x4U)
#define LPIT_MCR_DOZE_EN_SHIFT                   (2U)
#define LPIT_MCR_DOZE_EN_WIDTH                   (1U)
#define LPIT_MCR_DOZE_EN(x)                      (((uint32_t)(((uint32_t)(x)) << LPIT_MCR_DOZE_EN_SHIFT)) & LPIT_MCR_DOZE_EN_MASK)

#define LPIT_MCR_DBG_EN_MASK                     (0x8U)
#define LPIT_MCR_DBG_EN_SHIFT                    (3U)
#define LPIT_MCR_DBG_EN_WIDTH                    (1U)
#define LPIT_MCR_DBG_EN(x)                       (((uint32_t)(((uint32_t)(x)) << LPIT_MCR_DBG_EN_SHIFT)) & LPIT_MCR_DBG_EN_MASK)
/*! @} */

/*! @name MSR - Module Status Register */
/*! @{ */

#define LPIT_MSR_TIF0_MASK                       (0x1U)
#define LPIT_MSR_TIF0_SHIFT                      (0U)
#define LPIT_MSR_TIF0_WIDTH                      (1U)
#define LPIT_MSR_TIF0(x)                         (((uint32_t)(((uint32_t)(x)) << LPIT_MSR_TIF0_SHIFT)) & LPIT_MSR_TIF0_MASK)

#define LPIT_MSR_TIF1_MASK                       (0x2U)
#define LPIT_MSR_TIF1_SHIFT                      (1U)
#define LPIT_MSR_TIF1_WIDTH                      (1U)
#define LPIT_MSR_TIF1(x)                         (((uint32_t)(((uint32_t)(x)) << LPIT_MSR_TIF1_SHIFT)) & LPIT_MSR_TIF1_MASK)

#define LPIT_MSR_TIF2_MASK                       (0x4U)
#define LPIT_MSR_TIF2_SHIFT                      (2U)
#define LPIT_MSR_TIF2_WIDTH                      (1U)
#define LPIT_MSR_TIF2(x)                         (((uint32_t)(((uint32_t)(x)) << LPIT_MSR_TIF2_SHIFT)) & LPIT_MSR_TIF2_MASK)

#define LPIT_MSR_TIF3_MASK                       (0x8U)
#define LPIT_MSR_TIF3_SHIFT                      (3U)
#define LPIT_MSR_TIF3_WIDTH                      (1U)
#define LPIT_MSR_TIF3(x)                         (((uint32_t)(((uint32_t)(x)) << LPIT_MSR_TIF3_SHIFT)) & LPIT_MSR_TIF3_MASK)
/*! @} */

/*! @name MIER - Module Interrupt Enable Register */
/*! @{ */

#define LPIT_MIER_TIE0_MASK                      (0x1U)
#define LPIT_MIER_TIE0_SHIFT                     (0U)
#define LPIT_MIER_TIE0_WIDTH                     (1U)
#define LPIT_MIER_TIE0(x)                        (((uint32_t)(((uint32_t)(x)) << LPIT_MIER_TIE0_SHIFT)) & LPIT_MIER_TIE0_MASK)

#define LPIT_MIER_TIE1_MASK                      (0x2U)
#define LPIT_MIER_TIE1_SHIFT                     (1U)
#define LPIT_MIER_TIE1_WIDTH                     (1U)
#define LPIT_MIER_TIE1(x)                        (((uint32_t)(((uint32_t)(x)) << LPIT_MIER_TIE1_SHIFT)) & LPIT_MIER_TIE1_MASK)

#define LPIT_MIER_TIE2_MASK                      (0x4U)
#define LPIT_MIER_TIE2_SHIFT                     (2U)
#define LPIT_MIER_TIE2_WIDTH                     (1U)
#define LPIT_MIER_TIE2(x)                        (((uint32_t)(((uint32_t)(x)) << LPIT_MIER_TIE2_SHIFT)) & LPIT_MIER_TIE2_MASK)

#define LPIT_MIER_TIE3_MASK                      (0x8U)
#define LPIT_MIER_TIE3_SHIFT                     (3U)
#define LPIT_MIER_TIE3_WIDTH                     (1U)
#define LPIT_MIER_TIE3(x)                        (((uint32_t)(((uint32_t)(x)) << LPIT_MIER_TIE3_SHIFT)) & LPIT_MIER_TIE3_MASK)
/*! @} */

/*! @name SETTEN - Set Timer Enable Register */
/*! @{ */

#define LPIT_SETTEN_SET_T_EN_0_MASK              (0x1U)
#define LPIT_SETTEN_SET_T_EN_0_SHIFT             (0U)
#define LPIT_SETTEN_SET_T_EN_0_WIDTH             (1U)
#define LPIT_SETTEN_SET_T_EN_0(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_SETTEN_SET_T_EN_0_SHIFT)) & LPIT_SETTEN_SET_T_EN_0_MASK)

#define LPIT_SETTEN_SET_T_EN_1_MASK              (0x2U)
#define LPIT_SETTEN_SET_T_EN_1_SHIFT             (1U)
#define LPIT_SETTEN_SET_T_EN_1_WIDTH             (1U)
#define LPIT_SETTEN_SET_T_EN_1(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_SETTEN_SET_T_EN_1_SHIFT)) & LPIT_SETTEN_SET_T_EN_1_MASK)

#define LPIT_SETTEN_SET_T_EN_2_MASK              (0x4U)
#define LPIT_SETTEN_SET_T_EN_2_SHIFT             (2U)
#define LPIT_SETTEN_SET_T_EN_2_WIDTH             (1U)
#define LPIT_SETTEN_SET_T_EN_2(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_SETTEN_SET_T_EN_2_SHIFT)) & LPIT_SETTEN_SET_T_EN_2_MASK)

#define LPIT_SETTEN_SET_T_EN_3_MASK              (0x8U)
#define LPIT_SETTEN_SET_T_EN_3_SHIFT             (3U)
#define LPIT_SETTEN_SET_T_EN_3_WIDTH             (1U)
#define LPIT_SETTEN_SET_T_EN_3(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_SETTEN_SET_T_EN_3_SHIFT)) & LPIT_SETTEN_SET_T_EN_3_MASK)
/*! @} */

/*! @name CLRTEN - Clear Timer Enable Register */
/*! @{ */

#define LPIT_CLRTEN_CLR_T_EN_0_MASK              (0x1U)
#define LPIT_CLRTEN_CLR_T_EN_0_SHIFT             (0U)
#define LPIT_CLRTEN_CLR_T_EN_0_WIDTH             (1U)
#define LPIT_CLRTEN_CLR_T_EN_0(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_CLRTEN_CLR_T_EN_0_SHIFT)) & LPIT_CLRTEN_CLR_T_EN_0_MASK)

#define LPIT_CLRTEN_CLR_T_EN_1_MASK              (0x2U)
#define LPIT_CLRTEN_CLR_T_EN_1_SHIFT             (1U)
#define LPIT_CLRTEN_CLR_T_EN_1_WIDTH             (1U)
#define LPIT_CLRTEN_CLR_T_EN_1(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_CLRTEN_CLR_T_EN_1_SHIFT)) & LPIT_CLRTEN_CLR_T_EN_1_MASK)

#define LPIT_CLRTEN_CLR_T_EN_2_MASK              (0x4U)
#define LPIT_CLRTEN_CLR_T_EN_2_SHIFT             (2U)
#define LPIT_CLRTEN_CLR_T_EN_2_WIDTH             (1U)
#define LPIT_CLRTEN_CLR_T_EN_2(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_CLRTEN_CLR_T_EN_2_SHIFT)) & LPIT_CLRTEN_CLR_T_EN_2_MASK)

#define LPIT_CLRTEN_CLR_T_EN_3_MASK              (0x8U)
#define LPIT_CLRTEN_CLR_T_EN_3_SHIFT             (3U)
#define LPIT_CLRTEN_CLR_T_EN_3_WIDTH             (1U)
#define LPIT_CLRTEN_CLR_T_EN_3(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_CLRTEN_CLR_T_EN_3_SHIFT)) & LPIT_CLRTEN_CLR_T_EN_3_MASK)
/*! @} */

/*! @name TMR_TVAL - Timer Value Register */
/*! @{ */

#define LPIT_TMR_TVAL_TMR_VAL_MASK               (0xFFFFFFFFU)
#define LPIT_TMR_TVAL_TMR_VAL_SHIFT              (0U)
#define LPIT_TMR_TVAL_TMR_VAL_WIDTH              (32U)
#define LPIT_TMR_TVAL_TMR_VAL(x)                 (((uint32_t)(((uint32_t)(x)) << LPIT_TMR_TVAL_TMR_VAL_SHIFT)) & LPIT_TMR_TVAL_TMR_VAL_MASK)
/*! @} */

/*! @name TMR_CVAL - Current Timer Value */
/*! @{ */

#define LPIT_TMR_CVAL_TMR_CUR_VAL_MASK           (0xFFFFFFFFU)
#define LPIT_TMR_CVAL_TMR_CUR_VAL_SHIFT          (0U)
#define LPIT_TMR_CVAL_TMR_CUR_VAL_WIDTH          (32U)
#define LPIT_TMR_CVAL_TMR_CUR_VAL(x)             (((uint32_t)(((uint32_t)(x)) << LPIT_TMR_CVAL_TMR_CUR_VAL_SHIFT)) & LPIT_TMR_CVAL_TMR_CUR_VAL_MASK)
/*! @} */

/*! @name TMR_TCTRL - Timer Control Register */
/*! @{ */

#define LPIT_TMR_TCTRL_T_EN_MASK                 (0x1U)
#define LPIT_TMR_TCTRL_T_EN_SHIFT                (0U)
#define LPIT_TMR_TCTRL_T_EN_WIDTH                (1U)
#define LPIT_TMR_TCTRL_T_EN(x)                   (((uint32_t)(((uint32_t)(x)) << LPIT_TMR_TCTRL_T_EN_SHIFT)) & LPIT_TMR_TCTRL_T_EN_MASK)

#define LPIT_TMR_TCTRL_CHAIN_MASK                (0x2U)
#define LPIT_TMR_TCTRL_CHAIN_SHIFT               (1U)
#define LPIT_TMR_TCTRL_CHAIN_WIDTH               (1U)
#define LPIT_TMR_TCTRL_CHAIN(x)                  (((uint32_t)(((uint32_t)(x)) << LPIT_TMR_TCTRL_CHAIN_SHIFT)) & LPIT_TMR_TCTRL_CHAIN_MASK)

#define LPIT_TMR_TCTRL_MODE_MASK                 (0xCU)
#define LPIT_TMR_TCTRL_MODE_SHIFT                (2U)
#define LPIT_TMR_TCTRL_MODE_WIDTH                (2U)
#define LPIT_TMR_TCTRL_MODE(x)                   (((uint32_t)(((uint32_t)(x)) << LPIT_TMR_TCTRL_MODE_SHIFT)) & LPIT_TMR_TCTRL_MODE_MASK)

#define LPIT_TMR_TCTRL_TSOT_MASK                 (0x10000U)
#define LPIT_TMR_TCTRL_TSOT_SHIFT                (16U)
#define LPIT_TMR_TCTRL_TSOT_WIDTH                (1U)
#define LPIT_TMR_TCTRL_TSOT(x)                   (((uint32_t)(((uint32_t)(x)) << LPIT_TMR_TCTRL_TSOT_SHIFT)) & LPIT_TMR_TCTRL_TSOT_MASK)

#define LPIT_TMR_TCTRL_TSOI_MASK                 (0x20000U)
#define LPIT_TMR_TCTRL_TSOI_SHIFT                (17U)
#define LPIT_TMR_TCTRL_TSOI_WIDTH                (1U)
#define LPIT_TMR_TCTRL_TSOI(x)                   (((uint32_t)(((uint32_t)(x)) << LPIT_TMR_TCTRL_TSOI_SHIFT)) & LPIT_TMR_TCTRL_TSOI_MASK)

#define LPIT_TMR_TCTRL_TROT_MASK                 (0x40000U)
#define LPIT_TMR_TCTRL_TROT_SHIFT                (18U)
#define LPIT_TMR_TCTRL_TROT_WIDTH                (1U)
#define LPIT_TMR_TCTRL_TROT(x)                   (((uint32_t)(((uint32_t)(x)) << LPIT_TMR_TCTRL_TROT_SHIFT)) & LPIT_TMR_TCTRL_TROT_MASK)

#define LPIT_TMR_TCTRL_TRG_SRC_MASK              (0x800000U)
#define LPIT_TMR_TCTRL_TRG_SRC_SHIFT             (23U)
#define LPIT_TMR_TCTRL_TRG_SRC_WIDTH             (1U)
#define LPIT_TMR_TCTRL_TRG_SRC(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_TMR_TCTRL_TRG_SRC_SHIFT)) & LPIT_TMR_TCTRL_TRG_SRC_MASK)

#define LPIT_TMR_TCTRL_TRG_SEL_MASK              (0xF000000U)
#define LPIT_TMR_TCTRL_TRG_SEL_SHIFT             (24U)
#define LPIT_TMR_TCTRL_TRG_SEL_WIDTH             (4U)
#define LPIT_TMR_TCTRL_TRG_SEL(x)                (((uint32_t)(((uint32_t)(x)) << LPIT_TMR_TCTRL_TRG_SEL_SHIFT)) & LPIT_TMR_TCTRL_TRG_SEL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group LPIT_Register_Masks */

/*!
 * @}
 */ /* end of group LPIT_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K144W_LPIT_H_) */
