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
 * @file S32M24x_DPGA_AE.h
 * @version 1.3
 * @date 2023-05-30
 * @brief Peripheral Access Layer for S32M24x_DPGA_AE
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
#if !defined(S32M24x_DPGA_AE_H_)  /* Check if memory map has not been already included */
#define S32M24x_DPGA_AE_H_

#include "S32M24x_COMMON.h"

/* ----------------------------------------------------------------------------
   -- DPGA_AE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DPGA_AE_Peripheral_Access_Layer DPGA_AE Peripheral Access Layer
 * @{
 */

/** DPGA_AE - Register Layout Typedef */
typedef struct {
  __IO uint8_t INTF;                               /**< Interrupt Flags, offset: 0x0 */
  __IO uint8_t INTEN;                              /**< Interrupt enable, offset: 0x1 */
  __I  uint8_t STAT;                               /**< Status, offset: 0x2 */
  __IO uint8_t CTRL;                               /**< Control, offset: 0x3 */
  __IO uint32_t AMPCFG;                            /**< Amplifier Configuration, offset: 0x4 */
  __IO uint32_t BTCFG;                             /**< Blanking time configuration, offset: 0x8 */
  __IO uint32_t VDCFG;                             /**< Voltage Detector Configuration, offset: 0xC */
} DPGA_AE_Type, *DPGA_AE_MemMapPtr;

/** Number of instances of the DPGA_AE module. */
#define DPGA_AE_INSTANCE_COUNT                   (1u)

/* DPGA_AE - Peripheral instance base addresses */
/** Peripheral DPGA_AE base address */
#define IP_DPGA_AE_BASE                          (0x140u)
/** Peripheral DPGA_AE base pointer */
#define IP_DPGA_AE                               ((DPGA_AE_Type *)IP_DPGA_AE_BASE)
/** Array initializer of DPGA_AE peripheral base addresses */
#define IP_DPGA_AE_BASE_ADDRS                    { IP_DPGA_AE_BASE }
/** Array initializer of DPGA_AE peripheral base pointers */
#define IP_DPGA_AE_BASE_PTRS                     { IP_DPGA_AE }

/* ----------------------------------------------------------------------------
   -- DPGA_AE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DPGA_AE_Register_Masks DPGA_AE Register Masks
 * @{
 */

/*! @name INTF - Interrupt Flags */
/*! @{ */

#define DPGA_AE_INTF_LDIF_MASK                   (0x1U)
#define DPGA_AE_INTF_LDIF_SHIFT                  (0U)
#define DPGA_AE_INTF_LDIF_WIDTH                  (1U)
#define DPGA_AE_INTF_LDIF(x)                     (((uint8_t)(((uint8_t)(x)) << DPGA_AE_INTF_LDIF_SHIFT)) & DPGA_AE_INTF_LDIF_MASK)

#define DPGA_AE_INTF_HDIF_MASK                   (0x2U)
#define DPGA_AE_INTF_HDIF_SHIFT                  (1U)
#define DPGA_AE_INTF_HDIF_WIDTH                  (1U)
#define DPGA_AE_INTF_HDIF(x)                     (((uint8_t)(((uint8_t)(x)) << DPGA_AE_INTF_HDIF_SHIFT)) & DPGA_AE_INTF_HDIF_MASK)

#define DPGA_AE_INTF_AMPCFGIF_MASK               (0x10U)
#define DPGA_AE_INTF_AMPCFGIF_SHIFT              (4U)
#define DPGA_AE_INTF_AMPCFGIF_WIDTH              (1U)
#define DPGA_AE_INTF_AMPCFGIF(x)                 (((uint8_t)(((uint8_t)(x)) << DPGA_AE_INTF_AMPCFGIF_SHIFT)) & DPGA_AE_INTF_AMPCFGIF_MASK)

#define DPGA_AE_INTF_BTCFGIF_MASK                (0x20U)
#define DPGA_AE_INTF_BTCFGIF_SHIFT               (5U)
#define DPGA_AE_INTF_BTCFGIF_WIDTH               (1U)
#define DPGA_AE_INTF_BTCFGIF(x)                  (((uint8_t)(((uint8_t)(x)) << DPGA_AE_INTF_BTCFGIF_SHIFT)) & DPGA_AE_INTF_BTCFGIF_MASK)
/*! @} */

/*! @name INTEN - Interrupt enable */
/*! @{ */

#define DPGA_AE_INTEN_LDIE_MASK                  (0x1U)
#define DPGA_AE_INTEN_LDIE_SHIFT                 (0U)
#define DPGA_AE_INTEN_LDIE_WIDTH                 (1U)
#define DPGA_AE_INTEN_LDIE(x)                    (((uint8_t)(((uint8_t)(x)) << DPGA_AE_INTEN_LDIE_SHIFT)) & DPGA_AE_INTEN_LDIE_MASK)

#define DPGA_AE_INTEN_HDIE_MASK                  (0x2U)
#define DPGA_AE_INTEN_HDIE_SHIFT                 (1U)
#define DPGA_AE_INTEN_HDIE_WIDTH                 (1U)
#define DPGA_AE_INTEN_HDIE(x)                    (((uint8_t)(((uint8_t)(x)) << DPGA_AE_INTEN_HDIE_SHIFT)) & DPGA_AE_INTEN_HDIE_MASK)

#define DPGA_AE_INTEN_AMPCFGIE_MASK              (0x10U)
#define DPGA_AE_INTEN_AMPCFGIE_SHIFT             (4U)
#define DPGA_AE_INTEN_AMPCFGIE_WIDTH             (1U)
#define DPGA_AE_INTEN_AMPCFGIE(x)                (((uint8_t)(((uint8_t)(x)) << DPGA_AE_INTEN_AMPCFGIE_SHIFT)) & DPGA_AE_INTEN_AMPCFGIE_MASK)

#define DPGA_AE_INTEN_BTCFGIE_MASK               (0x20U)
#define DPGA_AE_INTEN_BTCFGIE_SHIFT              (5U)
#define DPGA_AE_INTEN_BTCFGIE_WIDTH              (1U)
#define DPGA_AE_INTEN_BTCFGIE(x)                 (((uint8_t)(((uint8_t)(x)) << DPGA_AE_INTEN_BTCFGIE_SHIFT)) & DPGA_AE_INTEN_BTCFGIE_MASK)
/*! @} */

/*! @name STAT - Status */
/*! @{ */

#define DPGA_AE_STAT_LDS_MASK                    (0x1U)
#define DPGA_AE_STAT_LDS_SHIFT                   (0U)
#define DPGA_AE_STAT_LDS_WIDTH                   (1U)
#define DPGA_AE_STAT_LDS(x)                      (((uint8_t)(((uint8_t)(x)) << DPGA_AE_STAT_LDS_SHIFT)) & DPGA_AE_STAT_LDS_MASK)

#define DPGA_AE_STAT_HDS_MASK                    (0x2U)
#define DPGA_AE_STAT_HDS_SHIFT                   (1U)
#define DPGA_AE_STAT_HDS_WIDTH                   (1U)
#define DPGA_AE_STAT_HDS(x)                      (((uint8_t)(((uint8_t)(x)) << DPGA_AE_STAT_HDS_SHIFT)) & DPGA_AE_STAT_HDS_MASK)

#define DPGA_AE_STAT_AMPCFGS_MASK                (0x10U)
#define DPGA_AE_STAT_AMPCFGS_SHIFT               (4U)
#define DPGA_AE_STAT_AMPCFGS_WIDTH               (1U)
#define DPGA_AE_STAT_AMPCFGS(x)                  (((uint8_t)(((uint8_t)(x)) << DPGA_AE_STAT_AMPCFGS_SHIFT)) & DPGA_AE_STAT_AMPCFGS_MASK)

#define DPGA_AE_STAT_BTCFGS_MASK                 (0x20U)
#define DPGA_AE_STAT_BTCFGS_SHIFT                (5U)
#define DPGA_AE_STAT_BTCFGS_WIDTH                (1U)
#define DPGA_AE_STAT_BTCFGS(x)                   (((uint8_t)(((uint8_t)(x)) << DPGA_AE_STAT_BTCFGS_SHIFT)) & DPGA_AE_STAT_BTCFGS_MASK)
/*! @} */

/*! @name CTRL - Control */
/*! @{ */

#define DPGA_AE_CTRL_EN_MASK                     (0x1U)
#define DPGA_AE_CTRL_EN_SHIFT                    (0U)
#define DPGA_AE_CTRL_EN_WIDTH                    (1U)
#define DPGA_AE_CTRL_EN(x)                       (((uint8_t)(((uint8_t)(x)) << DPGA_AE_CTRL_EN_SHIFT)) & DPGA_AE_CTRL_EN_MASK)

#define DPGA_AE_CTRL_VDEN_MASK                   (0x2U)
#define DPGA_AE_CTRL_VDEN_SHIFT                  (1U)
#define DPGA_AE_CTRL_VDEN_WIDTH                  (1U)
#define DPGA_AE_CTRL_VDEN(x)                     (((uint8_t)(((uint8_t)(x)) << DPGA_AE_CTRL_VDEN_SHIFT)) & DPGA_AE_CTRL_VDEN_MASK)

#define DPGA_AE_CTRL_CFGEN_MASK                  (0x4U)
#define DPGA_AE_CTRL_CFGEN_SHIFT                 (2U)
#define DPGA_AE_CTRL_CFGEN_WIDTH                 (1U)
#define DPGA_AE_CTRL_CFGEN(x)                    (((uint8_t)(((uint8_t)(x)) << DPGA_AE_CTRL_CFGEN_SHIFT)) & DPGA_AE_CTRL_CFGEN_MASK)

#define DPGA_AE_CTRL_BIVDEN_MASK                 (0x8U)
#define DPGA_AE_CTRL_BIVDEN_SHIFT                (3U)
#define DPGA_AE_CTRL_BIVDEN_WIDTH                (1U)
#define DPGA_AE_CTRL_BIVDEN(x)                   (((uint8_t)(((uint8_t)(x)) << DPGA_AE_CTRL_BIVDEN_SHIFT)) & DPGA_AE_CTRL_BIVDEN_MASK)

#define DPGA_AE_CTRL_AMPTEN_MASK                 (0x10U)
#define DPGA_AE_CTRL_AMPTEN_SHIFT                (4U)
#define DPGA_AE_CTRL_AMPTEN_WIDTH                (1U)
#define DPGA_AE_CTRL_AMPTEN(x)                   (((uint8_t)(((uint8_t)(x)) << DPGA_AE_CTRL_AMPTEN_SHIFT)) & DPGA_AE_CTRL_AMPTEN_MASK)

#define DPGA_AE_CTRL_VDTEN_MASK                  (0x20U)
#define DPGA_AE_CTRL_VDTEN_SHIFT                 (5U)
#define DPGA_AE_CTRL_VDTEN_WIDTH                 (1U)
#define DPGA_AE_CTRL_VDTEN(x)                    (((uint8_t)(((uint8_t)(x)) << DPGA_AE_CTRL_VDTEN_SHIFT)) & DPGA_AE_CTRL_VDTEN_MASK)

#define DPGA_AE_CTRL_FSTEN_MASK                  (0x80U)
#define DPGA_AE_CTRL_FSTEN_SHIFT                 (7U)
#define DPGA_AE_CTRL_FSTEN_WIDTH                 (1U)
#define DPGA_AE_CTRL_FSTEN(x)                    (((uint8_t)(((uint8_t)(x)) << DPGA_AE_CTRL_FSTEN_SHIFT)) & DPGA_AE_CTRL_FSTEN_MASK)
/*! @} */

/*! @name AMPCFG - Amplifier Configuration */
/*! @{ */

#define DPGA_AE_AMPCFG_ICMFSEL_MASK              (0x3FU)
#define DPGA_AE_AMPCFG_ICMFSEL_SHIFT             (0U)
#define DPGA_AE_AMPCFG_ICMFSEL_WIDTH             (6U)
#define DPGA_AE_AMPCFG_ICMFSEL(x)                (((uint32_t)(((uint32_t)(x)) << DPGA_AE_AMPCFG_ICMFSEL_SHIFT)) & DPGA_AE_AMPCFG_ICMFSEL_MASK)

#define DPGA_AE_AMPCFG_ICMCSEL_MASK              (0x300U)
#define DPGA_AE_AMPCFG_ICMCSEL_SHIFT             (8U)
#define DPGA_AE_AMPCFG_ICMCSEL_WIDTH             (2U)
#define DPGA_AE_AMPCFG_ICMCSEL(x)                (((uint32_t)(((uint32_t)(x)) << DPGA_AE_AMPCFG_ICMCSEL_SHIFT)) & DPGA_AE_AMPCFG_ICMCSEL_MASK)

#define DPGA_AE_AMPCFG_IGND_MASK                 (0x800U)
#define DPGA_AE_AMPCFG_IGND_SHIFT                (11U)
#define DPGA_AE_AMPCFG_IGND_WIDTH                (1U)
#define DPGA_AE_AMPCFG_IGND(x)                   (((uint32_t)(((uint32_t)(x)) << DPGA_AE_AMPCFG_IGND_SHIFT)) & DPGA_AE_AMPCFG_IGND_MASK)

#define DPGA_AE_AMPCFG_GAINSEL_MASK              (0x7000U)
#define DPGA_AE_AMPCFG_GAINSEL_SHIFT             (12U)
#define DPGA_AE_AMPCFG_GAINSEL_WIDTH             (3U)
#define DPGA_AE_AMPCFG_GAINSEL(x)                (((uint32_t)(((uint32_t)(x)) << DPGA_AE_AMPCFG_GAINSEL_SHIFT)) & DPGA_AE_AMPCFG_GAINSEL_MASK)

#define DPGA_AE_AMPCFG_OFFSEL_MASK               (0xF00000U)
#define DPGA_AE_AMPCFG_OFFSEL_SHIFT              (20U)
#define DPGA_AE_AMPCFG_OFFSEL_WIDTH              (4U)
#define DPGA_AE_AMPCFG_OFFSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DPGA_AE_AMPCFG_OFFSEL_SHIFT)) & DPGA_AE_AMPCFG_OFFSEL_MASK)

#define DPGA_AE_AMPCFG_OCMSEL_MASK               (0x30000000U)
#define DPGA_AE_AMPCFG_OCMSEL_SHIFT              (28U)
#define DPGA_AE_AMPCFG_OCMSEL_WIDTH              (2U)
#define DPGA_AE_AMPCFG_OCMSEL(x)                 (((uint32_t)(((uint32_t)(x)) << DPGA_AE_AMPCFG_OCMSEL_SHIFT)) & DPGA_AE_AMPCFG_OCMSEL_MASK)
/*! @} */

/*! @name BTCFG - Blanking time configuration */
/*! @{ */

#define DPGA_AE_BTCFG_BTDUR_MASK                 (0xFFU)
#define DPGA_AE_BTCFG_BTDUR_SHIFT                (0U)
#define DPGA_AE_BTCFG_BTDUR_WIDTH                (8U)
#define DPGA_AE_BTCFG_BTDUR(x)                   (((uint32_t)(((uint32_t)(x)) << DPGA_AE_BTCFG_BTDUR_SHIFT)) & DPGA_AE_BTCFG_BTDUR_MASK)

#define DPGA_AE_BTCFG_SELTRG0_MASK               (0x30000U)
#define DPGA_AE_BTCFG_SELTRG0_SHIFT              (16U)
#define DPGA_AE_BTCFG_SELTRG0_WIDTH              (2U)
#define DPGA_AE_BTCFG_SELTRG0(x)                 (((uint32_t)(((uint32_t)(x)) << DPGA_AE_BTCFG_SELTRG0_SHIFT)) & DPGA_AE_BTCFG_SELTRG0_MASK)

#define DPGA_AE_BTCFG_SELTRG1_MASK               (0xC0000U)
#define DPGA_AE_BTCFG_SELTRG1_SHIFT              (18U)
#define DPGA_AE_BTCFG_SELTRG1_WIDTH              (2U)
#define DPGA_AE_BTCFG_SELTRG1(x)                 (((uint32_t)(((uint32_t)(x)) << DPGA_AE_BTCFG_SELTRG1_SHIFT)) & DPGA_AE_BTCFG_SELTRG1_MASK)

#define DPGA_AE_BTCFG_SELTRG2_MASK               (0x300000U)
#define DPGA_AE_BTCFG_SELTRG2_SHIFT              (20U)
#define DPGA_AE_BTCFG_SELTRG2_WIDTH              (2U)
#define DPGA_AE_BTCFG_SELTRG2(x)                 (((uint32_t)(((uint32_t)(x)) << DPGA_AE_BTCFG_SELTRG2_SHIFT)) & DPGA_AE_BTCFG_SELTRG2_MASK)

#define DPGA_AE_BTCFG_SELTRG3_MASK               (0xC00000U)
#define DPGA_AE_BTCFG_SELTRG3_SHIFT              (22U)
#define DPGA_AE_BTCFG_SELTRG3_WIDTH              (2U)
#define DPGA_AE_BTCFG_SELTRG3(x)                 (((uint32_t)(((uint32_t)(x)) << DPGA_AE_BTCFG_SELTRG3_SHIFT)) & DPGA_AE_BTCFG_SELTRG3_MASK)

#define DPGA_AE_BTCFG_SELTRG4_MASK               (0x3000000U)
#define DPGA_AE_BTCFG_SELTRG4_SHIFT              (24U)
#define DPGA_AE_BTCFG_SELTRG4_WIDTH              (2U)
#define DPGA_AE_BTCFG_SELTRG4(x)                 (((uint32_t)(((uint32_t)(x)) << DPGA_AE_BTCFG_SELTRG4_SHIFT)) & DPGA_AE_BTCFG_SELTRG4_MASK)

#define DPGA_AE_BTCFG_SELTRG5_MASK               (0xC000000U)
#define DPGA_AE_BTCFG_SELTRG5_SHIFT              (26U)
#define DPGA_AE_BTCFG_SELTRG5_WIDTH              (2U)
#define DPGA_AE_BTCFG_SELTRG5(x)                 (((uint32_t)(((uint32_t)(x)) << DPGA_AE_BTCFG_SELTRG5_SHIFT)) & DPGA_AE_BTCFG_SELTRG5_MASK)
/*! @} */

/*! @name VDCFG - Voltage Detector Configuration */
/*! @{ */

#define DPGA_AE_VDCFG_LDLIM_MASK                 (0xFU)
#define DPGA_AE_VDCFG_LDLIM_SHIFT                (0U)
#define DPGA_AE_VDCFG_LDLIM_WIDTH                (4U)
#define DPGA_AE_VDCFG_LDLIM(x)                   (((uint32_t)(((uint32_t)(x)) << DPGA_AE_VDCFG_LDLIM_SHIFT)) & DPGA_AE_VDCFG_LDLIM_MASK)

#define DPGA_AE_VDCFG_LDFDUR_MASK                (0x3FF0U)
#define DPGA_AE_VDCFG_LDFDUR_SHIFT               (4U)
#define DPGA_AE_VDCFG_LDFDUR_WIDTH               (10U)
#define DPGA_AE_VDCFG_LDFDUR(x)                  (((uint32_t)(((uint32_t)(x)) << DPGA_AE_VDCFG_LDFDUR_SHIFT)) & DPGA_AE_VDCFG_LDFDUR_MASK)

#define DPGA_AE_VDCFG_HDLIM_MASK                 (0xF0000U)
#define DPGA_AE_VDCFG_HDLIM_SHIFT                (16U)
#define DPGA_AE_VDCFG_HDLIM_WIDTH                (4U)
#define DPGA_AE_VDCFG_HDLIM(x)                   (((uint32_t)(((uint32_t)(x)) << DPGA_AE_VDCFG_HDLIM_SHIFT)) & DPGA_AE_VDCFG_HDLIM_MASK)

#define DPGA_AE_VDCFG_HDFDUR_MASK                (0x3FF00000U)
#define DPGA_AE_VDCFG_HDFDUR_SHIFT               (20U)
#define DPGA_AE_VDCFG_HDFDUR_WIDTH               (10U)
#define DPGA_AE_VDCFG_HDFDUR(x)                  (((uint32_t)(((uint32_t)(x)) << DPGA_AE_VDCFG_HDFDUR_SHIFT)) & DPGA_AE_VDCFG_HDFDUR_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group DPGA_AE_Register_Masks */

/*!
 * @}
 */ /* end of group DPGA_AE_Peripheral_Access_Layer */

#endif  /* #if !defined(S32M24x_DPGA_AE_H_) */
