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
 * @file S32M24x_GDU_AE.h
 * @version 1.3
 * @date 2023-05-30
 * @brief Peripheral Access Layer for S32M24x_GDU_AE
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
#if !defined(S32M24x_GDU_AE_H_)  /* Check if memory map has not been already included */
#define S32M24x_GDU_AE_H_

#include "S32M24x_COMMON.h"

/* ----------------------------------------------------------------------------
   -- GDU_AE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GDU_AE_Peripheral_Access_Layer GDU_AE Peripheral Access Layer
 * @{
 */

/** GDU_AE - Register Layout Typedef */
typedef struct {
  __IO uint8_t INTF;                               /**< Interrupt Flag, offset: 0x0 */
  uint8_t RESERVED_0[1];
  __IO uint8_t INTEN;                              /**< Interrupt Enable, offset: 0x2 */
  uint8_t RESERVED_1[1];
  __I  uint16_t STAT;                              /**< Status, offset: 0x4 */
  __IO uint16_t CTL;                               /**< Control, offset: 0x6 */
  __IO uint8_t CFG;                                /**< Configuration, offset: 0x8 */
  uint8_t RESERVED_2[1];
  __IO uint8_t EACFG;                              /**< Error Reaction, offset: 0xA */
  uint8_t RESERVED_3[1];
  __IO uint16_t BOOSTCFG;                          /**< Boost, offset: 0xC */
  __IO uint16_t BTCFG;                             /**< Blanking Time, offset: 0xE */
  __IO uint32_t HSSRON;                            /**< High-Side Slew Rate On, offset: 0x10 */
  __IO uint32_t HSSROFF;                           /**< High-Side Slew Rate Off, offset: 0x14 */
  __IO uint32_t LSSRON;                            /**< Low-Side Slew Rate On, offset: 0x18 */
  __IO uint32_t LSSROFF;                           /**< Low-Side Slew Rate Off, offset: 0x1C */
  __IO uint8_t OFFSDCFG;                           /**< Off-State Diagnostic, offset: 0x20 */
  uint8_t RESERVED_4[3];
  __IO uint16_t DSCFG;                             /**< Desaturation Level, offset: 0x24 */
  uint8_t RESERVED_5[2];
  __IO uint32_t CPCFG;                             /**< Charge Pump, offset: 0x28 */
  __I  uint16_t DLYMR;                             /**< Delay Measurement Result, offset: 0x2C */
  __IO uint16_t DLYMCFG;                           /**< Delay Measurement, offset: 0x2E */
  __IO uint8_t SUPCFG;                             /**< Startup Configuration, offset: 0x30 */
  uint8_t RESERVED_6[3];
  __IO uint32_t IRT;                               /**< Iref Trimming, offset: 0x34 */
} GDU_AE_Type, *GDU_AE_MemMapPtr;

/** Number of instances of the GDU_AE module. */
#define GDU_AE_INSTANCE_COUNT                    (1u)

/* GDU_AE - Peripheral instance base addresses */
/** Peripheral GDU_AE base address */
#define IP_GDU_AE_BASE                           (0x180u)
/** Peripheral GDU_AE base pointer */
#define IP_GDU_AE                                ((GDU_AE_Type *)IP_GDU_AE_BASE)
/** Array initializer of GDU_AE peripheral base addresses */
#define IP_GDU_AE_BASE_ADDRS                     { IP_GDU_AE_BASE }
/** Array initializer of GDU_AE peripheral base pointers */
#define IP_GDU_AE_BASE_PTRS                      { IP_GDU_AE }

/* ----------------------------------------------------------------------------
   -- GDU_AE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GDU_AE_Register_Masks GDU_AE Register Masks
 * @{
 */

/*! @name INTF - Interrupt Flag */
/*! @{ */

#define GDU_AE_INTF_DLSIF0_MASK                  (0x1U)
#define GDU_AE_INTF_DLSIF0_SHIFT                 (0U)
#define GDU_AE_INTF_DLSIF0_WIDTH                 (1U)
#define GDU_AE_INTF_DLSIF0(x)                    (((uint8_t)(((uint8_t)(x)) << GDU_AE_INTF_DLSIF0_SHIFT)) & GDU_AE_INTF_DLSIF0_MASK)

#define GDU_AE_INTF_DLSIF1_MASK                  (0x2U)
#define GDU_AE_INTF_DLSIF1_SHIFT                 (1U)
#define GDU_AE_INTF_DLSIF1_WIDTH                 (1U)
#define GDU_AE_INTF_DLSIF1(x)                    (((uint8_t)(((uint8_t)(x)) << GDU_AE_INTF_DLSIF1_SHIFT)) & GDU_AE_INTF_DLSIF1_MASK)

#define GDU_AE_INTF_DLSIF2_MASK                  (0x4U)
#define GDU_AE_INTF_DLSIF2_SHIFT                 (2U)
#define GDU_AE_INTF_DLSIF2_WIDTH                 (1U)
#define GDU_AE_INTF_DLSIF2(x)                    (((uint8_t)(((uint8_t)(x)) << GDU_AE_INTF_DLSIF2_SHIFT)) & GDU_AE_INTF_DLSIF2_MASK)

#define GDU_AE_INTF_DHSIF0_MASK                  (0x10U)
#define GDU_AE_INTF_DHSIF0_SHIFT                 (4U)
#define GDU_AE_INTF_DHSIF0_WIDTH                 (1U)
#define GDU_AE_INTF_DHSIF0(x)                    (((uint8_t)(((uint8_t)(x)) << GDU_AE_INTF_DHSIF0_SHIFT)) & GDU_AE_INTF_DHSIF0_MASK)

#define GDU_AE_INTF_DHSIF1_MASK                  (0x20U)
#define GDU_AE_INTF_DHSIF1_SHIFT                 (5U)
#define GDU_AE_INTF_DHSIF1_WIDTH                 (1U)
#define GDU_AE_INTF_DHSIF1(x)                    (((uint8_t)(((uint8_t)(x)) << GDU_AE_INTF_DHSIF1_SHIFT)) & GDU_AE_INTF_DHSIF1_MASK)

#define GDU_AE_INTF_DHSIF2_MASK                  (0x40U)
#define GDU_AE_INTF_DHSIF2_SHIFT                 (6U)
#define GDU_AE_INTF_DHSIF2_WIDTH                 (1U)
#define GDU_AE_INTF_DHSIF2(x)                    (((uint8_t)(((uint8_t)(x)) << GDU_AE_INTF_DHSIF2_SHIFT)) & GDU_AE_INTF_DHSIF2_MASK)

#define GDU_AE_INTF_HDHVDIF_MASK                 (0x80U)
#define GDU_AE_INTF_HDHVDIF_SHIFT                (7U)
#define GDU_AE_INTF_HDHVDIF_WIDTH                (1U)
#define GDU_AE_INTF_HDHVDIF(x)                   (((uint8_t)(((uint8_t)(x)) << GDU_AE_INTF_HDHVDIF_SHIFT)) & GDU_AE_INTF_HDHVDIF_MASK)
/*! @} */

/*! @name INTEN - Interrupt Enable */
/*! @{ */

#define GDU_AE_INTEN_DLSIE0_MASK                 (0x1U)
#define GDU_AE_INTEN_DLSIE0_SHIFT                (0U)
#define GDU_AE_INTEN_DLSIE0_WIDTH                (1U)
#define GDU_AE_INTEN_DLSIE0(x)                   (((uint8_t)(((uint8_t)(x)) << GDU_AE_INTEN_DLSIE0_SHIFT)) & GDU_AE_INTEN_DLSIE0_MASK)

#define GDU_AE_INTEN_DLSIE1_MASK                 (0x2U)
#define GDU_AE_INTEN_DLSIE1_SHIFT                (1U)
#define GDU_AE_INTEN_DLSIE1_WIDTH                (1U)
#define GDU_AE_INTEN_DLSIE1(x)                   (((uint8_t)(((uint8_t)(x)) << GDU_AE_INTEN_DLSIE1_SHIFT)) & GDU_AE_INTEN_DLSIE1_MASK)

#define GDU_AE_INTEN_DLSIE2_MASK                 (0x4U)
#define GDU_AE_INTEN_DLSIE2_SHIFT                (2U)
#define GDU_AE_INTEN_DLSIE2_WIDTH                (1U)
#define GDU_AE_INTEN_DLSIE2(x)                   (((uint8_t)(((uint8_t)(x)) << GDU_AE_INTEN_DLSIE2_SHIFT)) & GDU_AE_INTEN_DLSIE2_MASK)

#define GDU_AE_INTEN_DHSIE0_MASK                 (0x10U)
#define GDU_AE_INTEN_DHSIE0_SHIFT                (4U)
#define GDU_AE_INTEN_DHSIE0_WIDTH                (1U)
#define GDU_AE_INTEN_DHSIE0(x)                   (((uint8_t)(((uint8_t)(x)) << GDU_AE_INTEN_DHSIE0_SHIFT)) & GDU_AE_INTEN_DHSIE0_MASK)

#define GDU_AE_INTEN_DHSIE1_MASK                 (0x20U)
#define GDU_AE_INTEN_DHSIE1_SHIFT                (5U)
#define GDU_AE_INTEN_DHSIE1_WIDTH                (1U)
#define GDU_AE_INTEN_DHSIE1(x)                   (((uint8_t)(((uint8_t)(x)) << GDU_AE_INTEN_DHSIE1_SHIFT)) & GDU_AE_INTEN_DHSIE1_MASK)

#define GDU_AE_INTEN_DHSIE2_MASK                 (0x40U)
#define GDU_AE_INTEN_DHSIE2_SHIFT                (6U)
#define GDU_AE_INTEN_DHSIE2_WIDTH                (1U)
#define GDU_AE_INTEN_DHSIE2(x)                   (((uint8_t)(((uint8_t)(x)) << GDU_AE_INTEN_DHSIE2_SHIFT)) & GDU_AE_INTEN_DHSIE2_MASK)

#define GDU_AE_INTEN_HDHVDIE_MASK                (0x80U)
#define GDU_AE_INTEN_HDHVDIE_SHIFT               (7U)
#define GDU_AE_INTEN_HDHVDIE_WIDTH               (1U)
#define GDU_AE_INTEN_HDHVDIE(x)                  (((uint8_t)(((uint8_t)(x)) << GDU_AE_INTEN_HDHVDIE_SHIFT)) & GDU_AE_INTEN_HDHVDIE_MASK)
/*! @} */

/*! @name STAT - Status */
/*! @{ */

#define GDU_AE_STAT_DLSES0_MASK                  (0x1U)
#define GDU_AE_STAT_DLSES0_SHIFT                 (0U)
#define GDU_AE_STAT_DLSES0_WIDTH                 (1U)
#define GDU_AE_STAT_DLSES0(x)                    (((uint16_t)(((uint16_t)(x)) << GDU_AE_STAT_DLSES0_SHIFT)) & GDU_AE_STAT_DLSES0_MASK)

#define GDU_AE_STAT_DLSES1_MASK                  (0x2U)
#define GDU_AE_STAT_DLSES1_SHIFT                 (1U)
#define GDU_AE_STAT_DLSES1_WIDTH                 (1U)
#define GDU_AE_STAT_DLSES1(x)                    (((uint16_t)(((uint16_t)(x)) << GDU_AE_STAT_DLSES1_SHIFT)) & GDU_AE_STAT_DLSES1_MASK)

#define GDU_AE_STAT_DLSES2_MASK                  (0x4U)
#define GDU_AE_STAT_DLSES2_SHIFT                 (2U)
#define GDU_AE_STAT_DLSES2_WIDTH                 (1U)
#define GDU_AE_STAT_DLSES2(x)                    (((uint16_t)(((uint16_t)(x)) << GDU_AE_STAT_DLSES2_SHIFT)) & GDU_AE_STAT_DLSES2_MASK)

#define GDU_AE_STAT_DHSES0_MASK                  (0x10U)
#define GDU_AE_STAT_DHSES0_SHIFT                 (4U)
#define GDU_AE_STAT_DHSES0_WIDTH                 (1U)
#define GDU_AE_STAT_DHSES0(x)                    (((uint16_t)(((uint16_t)(x)) << GDU_AE_STAT_DHSES0_SHIFT)) & GDU_AE_STAT_DHSES0_MASK)

#define GDU_AE_STAT_DHSES1_MASK                  (0x20U)
#define GDU_AE_STAT_DHSES1_SHIFT                 (5U)
#define GDU_AE_STAT_DHSES1_WIDTH                 (1U)
#define GDU_AE_STAT_DHSES1(x)                    (((uint16_t)(((uint16_t)(x)) << GDU_AE_STAT_DHSES1_SHIFT)) & GDU_AE_STAT_DHSES1_MASK)

#define GDU_AE_STAT_DHSES2_MASK                  (0x40U)
#define GDU_AE_STAT_DHSES2_SHIFT                 (6U)
#define GDU_AE_STAT_DHSES2_WIDTH                 (1U)
#define GDU_AE_STAT_DHSES2(x)                    (((uint16_t)(((uint16_t)(x)) << GDU_AE_STAT_DHSES2_SHIFT)) & GDU_AE_STAT_DHSES2_MASK)

#define GDU_AE_STAT_HDHVDS_MASK                  (0x80U)
#define GDU_AE_STAT_HDHVDS_SHIFT                 (7U)
#define GDU_AE_STAT_HDHVDS_WIDTH                 (1U)
#define GDU_AE_STAT_HDHVDS(x)                    (((uint16_t)(((uint16_t)(x)) << GDU_AE_STAT_HDHVDS_SHIFT)) & GDU_AE_STAT_HDHVDS_MASK)
/*! @} */

/*! @name CTL - Control */
/*! @{ */

#define GDU_AE_CTL_GDUEN_MASK                    (0x1U)
#define GDU_AE_CTL_GDUEN_SHIFT                   (0U)
#define GDU_AE_CTL_GDUEN_WIDTH                   (1U)
#define GDU_AE_CTL_GDUEN(x)                      (((uint16_t)(((uint16_t)(x)) << GDU_AE_CTL_GDUEN_SHIFT)) & GDU_AE_CTL_GDUEN_MASK)

#define GDU_AE_CTL_CPEN_MASK                     (0x2U)
#define GDU_AE_CTL_CPEN_SHIFT                    (1U)
#define GDU_AE_CTL_CPEN_WIDTH                    (1U)
#define GDU_AE_CTL_CPEN(x)                       (((uint16_t)(((uint16_t)(x)) << GDU_AE_CTL_CPEN_SHIFT)) & GDU_AE_CTL_CPEN_MASK)

#define GDU_AE_CTL_BOOSTEN_MASK                  (0x4U)
#define GDU_AE_CTL_BOOSTEN_SHIFT                 (2U)
#define GDU_AE_CTL_BOOSTEN_WIDTH                 (1U)
#define GDU_AE_CTL_BOOSTEN(x)                    (((uint16_t)(((uint16_t)(x)) << GDU_AE_CTL_BOOSTEN_SHIFT)) & GDU_AE_CTL_BOOSTEN_MASK)

#define GDU_AE_CTL_DMEN_MASK                     (0x8U)
#define GDU_AE_CTL_DMEN_SHIFT                    (3U)
#define GDU_AE_CTL_DMEN_WIDTH                    (1U)
#define GDU_AE_CTL_DMEN(x)                       (((uint16_t)(((uint16_t)(x)) << GDU_AE_CTL_DMEN_SHIFT)) & GDU_AE_CTL_DMEN_MASK)

#define GDU_AE_CTL_IRTSW_MASK                    (0x10U)
#define GDU_AE_CTL_IRTSW_SHIFT                   (4U)
#define GDU_AE_CTL_IRTSW_WIDTH                   (1U)
#define GDU_AE_CTL_IRTSW(x)                      (((uint16_t)(((uint16_t)(x)) << GDU_AE_CTL_IRTSW_SHIFT)) & GDU_AE_CTL_IRTSW_MASK)

#define GDU_AE_CTL_RWEN_MASK                     (0x20U)
#define GDU_AE_CTL_RWEN_SHIFT                    (5U)
#define GDU_AE_CTL_RWEN_WIDTH                    (1U)
#define GDU_AE_CTL_RWEN(x)                       (((uint16_t)(((uint16_t)(x)) << GDU_AE_CTL_RWEN_SHIFT)) & GDU_AE_CTL_RWEN_MASK)

#define GDU_AE_CTL_SSTEN_MASK                    (0x40U)
#define GDU_AE_CTL_SSTEN_SHIFT                   (6U)
#define GDU_AE_CTL_SSTEN_WIDTH                   (1U)
#define GDU_AE_CTL_SSTEN(x)                      (((uint16_t)(((uint16_t)(x)) << GDU_AE_CTL_SSTEN_SHIFT)) & GDU_AE_CTL_SSTEN_MASK)

#define GDU_AE_CTL_CFGEN_MASK                    (0x80U)
#define GDU_AE_CTL_CFGEN_SHIFT                   (7U)
#define GDU_AE_CTL_CFGEN_WIDTH                   (1U)
#define GDU_AE_CTL_CFGEN(x)                      (((uint16_t)(((uint16_t)(x)) << GDU_AE_CTL_CFGEN_SHIFT)) & GDU_AE_CTL_CFGEN_MASK)
/*! @} */

/*! @name CFG - Configuration */
/*! @{ */

#define GDU_AE_CFG_HDHVDCFG_MASK                 (0x1U)
#define GDU_AE_CFG_HDHVDCFG_SHIFT                (0U)
#define GDU_AE_CFG_HDHVDCFG_WIDTH                (1U)
#define GDU_AE_CFG_HDHVDCFG(x)                   (((uint8_t)(((uint8_t)(x)) << GDU_AE_CFG_HDHVDCFG_SHIFT)) & GDU_AE_CFG_HDHVDCFG_MASK)

#define GDU_AE_CFG_HDHSDIV_MASK                  (0x2U)
#define GDU_AE_CFG_HDHSDIV_SHIFT                 (1U)
#define GDU_AE_CFG_HDHSDIV_WIDTH                 (1U)
#define GDU_AE_CFG_HDHSDIV(x)                    (((uint8_t)(((uint8_t)(x)) << GDU_AE_CFG_HDHSDIV_SHIFT)) & GDU_AE_CFG_HDHSDIV_MASK)

#define GDU_AE_CFG_SYNCEN_MASK                   (0x80U)
#define GDU_AE_CFG_SYNCEN_SHIFT                  (7U)
#define GDU_AE_CFG_SYNCEN_WIDTH                  (1U)
#define GDU_AE_CFG_SYNCEN(x)                     (((uint8_t)(((uint8_t)(x)) << GDU_AE_CFG_SYNCEN_SHIFT)) & GDU_AE_CFG_SYNCEN_MASK)
/*! @} */

/*! @name EACFG - Error Reaction */
/*! @{ */

#define GDU_AE_EACFG_HVDA_MASK                   (0x1U)
#define GDU_AE_EACFG_HVDA_SHIFT                  (0U)
#define GDU_AE_EACFG_HVDA_WIDTH                  (1U)
#define GDU_AE_EACFG_HVDA(x)                     (((uint8_t)(((uint8_t)(x)) << GDU_AE_EACFG_HVDA_SHIFT)) & GDU_AE_EACFG_HVDA_MASK)

#define GDU_AE_EACFG_OCA_MASK                    (0x2U)
#define GDU_AE_EACFG_OCA_SHIFT                   (1U)
#define GDU_AE_EACFG_OCA_WIDTH                   (1U)
#define GDU_AE_EACFG_OCA(x)                      (((uint8_t)(((uint8_t)(x)) << GDU_AE_EACFG_OCA_SHIFT)) & GDU_AE_EACFG_OCA_MASK)

#define GDU_AE_EACFG_DSA_MASK                    (0x4U)
#define GDU_AE_EACFG_DSA_SHIFT                   (2U)
#define GDU_AE_EACFG_DSA_WIDTH                   (1U)
#define GDU_AE_EACFG_DSA(x)                      (((uint8_t)(((uint8_t)(x)) << GDU_AE_EACFG_DSA_SHIFT)) & GDU_AE_EACFG_DSA_MASK)
/*! @} */

/*! @name BOOSTCFG - Boost */
/*! @{ */

#define GDU_AE_BOOSTCFG_BODC_MASK                (0x3U)
#define GDU_AE_BOOSTCFG_BODC_SHIFT               (0U)
#define GDU_AE_BOOSTCFG_BODC_WIDTH               (2U)
#define GDU_AE_BOOSTCFG_BODC(x)                  (((uint16_t)(((uint16_t)(x)) << GDU_AE_BOOSTCFG_BODC_SHIFT)) & GDU_AE_BOOSTCFG_BODC_MASK)

#define GDU_AE_BOOSTCFG_BOCD_MASK                (0x1CU)
#define GDU_AE_BOOSTCFG_BOCD_SHIFT               (2U)
#define GDU_AE_BOOSTCFG_BOCD_WIDTH               (3U)
#define GDU_AE_BOOSTCFG_BOCD(x)                  (((uint16_t)(((uint16_t)(x)) << GDU_AE_BOOSTCFG_BOCD_SHIFT)) & GDU_AE_BOOSTCFG_BOCD_MASK)

#define GDU_AE_BOOSTCFG_BOCL_MASK                (0x700U)
#define GDU_AE_BOOSTCFG_BOCL_SHIFT               (8U)
#define GDU_AE_BOOSTCFG_BOCL_WIDTH               (3U)
#define GDU_AE_BOOSTCFG_BOCL(x)                  (((uint16_t)(((uint16_t)(x)) << GDU_AE_BOOSTCFG_BOCL_SHIFT)) & GDU_AE_BOOSTCFG_BOCL_MASK)
/*! @} */

/*! @name BTCFG - Blanking Time */
/*! @{ */

#define GDU_AE_BTCFG_BT_MASK                     (0x1FFU)
#define GDU_AE_BTCFG_BT_SHIFT                    (0U)
#define GDU_AE_BTCFG_BT_WIDTH                    (9U)
#define GDU_AE_BTCFG_BT(x)                       (((uint16_t)(((uint16_t)(x)) << GDU_AE_BTCFG_BT_SHIFT)) & GDU_AE_BTCFG_BT_MASK)
/*! @} */

/*! @name HSSRON - High-Side Slew Rate On */
/*! @{ */

#define GDU_AE_HSSRON_HSTONC_P1_MASK             (0x1FU)
#define GDU_AE_HSSRON_HSTONC_P1_SHIFT            (0U)
#define GDU_AE_HSSRON_HSTONC_P1_WIDTH            (5U)
#define GDU_AE_HSSRON_HSTONC_P1(x)               (((uint32_t)(((uint32_t)(x)) << GDU_AE_HSSRON_HSTONC_P1_SHIFT)) & GDU_AE_HSSRON_HSTONC_P1_MASK)

#define GDU_AE_HSSRON_HSTONC_P2_MASK             (0x3E0U)
#define GDU_AE_HSSRON_HSTONC_P2_SHIFT            (5U)
#define GDU_AE_HSSRON_HSTONC_P2_WIDTH            (5U)
#define GDU_AE_HSSRON_HSTONC_P2(x)               (((uint32_t)(((uint32_t)(x)) << GDU_AE_HSSRON_HSTONC_P2_SHIFT)) & GDU_AE_HSSRON_HSTONC_P2_MASK)

#define GDU_AE_HSSRON_HSTONC_P3_MASK             (0x7C00U)
#define GDU_AE_HSSRON_HSTONC_P3_SHIFT            (10U)
#define GDU_AE_HSSRON_HSTONC_P3_WIDTH            (5U)
#define GDU_AE_HSSRON_HSTONC_P3(x)               (((uint32_t)(((uint32_t)(x)) << GDU_AE_HSSRON_HSTONC_P3_SHIFT)) & GDU_AE_HSSRON_HSTONC_P3_MASK)

#define GDU_AE_HSSRON_HSTONT_P1_MASK             (0x7F0000U)
#define GDU_AE_HSSRON_HSTONT_P1_SHIFT            (16U)
#define GDU_AE_HSSRON_HSTONT_P1_WIDTH            (7U)
#define GDU_AE_HSSRON_HSTONT_P1(x)               (((uint32_t)(((uint32_t)(x)) << GDU_AE_HSSRON_HSTONT_P1_SHIFT)) & GDU_AE_HSSRON_HSTONT_P1_MASK)

#define GDU_AE_HSSRON_HSTONT_P2_MASK             (0x7F000000U)
#define GDU_AE_HSSRON_HSTONT_P2_SHIFT            (24U)
#define GDU_AE_HSSRON_HSTONT_P2_WIDTH            (7U)
#define GDU_AE_HSSRON_HSTONT_P2(x)               (((uint32_t)(((uint32_t)(x)) << GDU_AE_HSSRON_HSTONT_P2_SHIFT)) & GDU_AE_HSSRON_HSTONT_P2_MASK)
/*! @} */

/*! @name HSSROFF - High-Side Slew Rate Off */
/*! @{ */

#define GDU_AE_HSSROFF_HSTOFFC_P1_MASK           (0x1FU)
#define GDU_AE_HSSROFF_HSTOFFC_P1_SHIFT          (0U)
#define GDU_AE_HSSROFF_HSTOFFC_P1_WIDTH          (5U)
#define GDU_AE_HSSROFF_HSTOFFC_P1(x)             (((uint32_t)(((uint32_t)(x)) << GDU_AE_HSSROFF_HSTOFFC_P1_SHIFT)) & GDU_AE_HSSROFF_HSTOFFC_P1_MASK)

#define GDU_AE_HSSROFF_HSTOFFC_P2_MASK           (0x3E0U)
#define GDU_AE_HSSROFF_HSTOFFC_P2_SHIFT          (5U)
#define GDU_AE_HSSROFF_HSTOFFC_P2_WIDTH          (5U)
#define GDU_AE_HSSROFF_HSTOFFC_P2(x)             (((uint32_t)(((uint32_t)(x)) << GDU_AE_HSSROFF_HSTOFFC_P2_SHIFT)) & GDU_AE_HSSROFF_HSTOFFC_P2_MASK)

#define GDU_AE_HSSROFF_HSTOFFC_P3_MASK           (0x7C00U)
#define GDU_AE_HSSROFF_HSTOFFC_P3_SHIFT          (10U)
#define GDU_AE_HSSROFF_HSTOFFC_P3_WIDTH          (5U)
#define GDU_AE_HSSROFF_HSTOFFC_P3(x)             (((uint32_t)(((uint32_t)(x)) << GDU_AE_HSSROFF_HSTOFFC_P3_SHIFT)) & GDU_AE_HSSROFF_HSTOFFC_P3_MASK)

#define GDU_AE_HSSROFF_HSTOFFT_P1_MASK           (0x7F0000U)
#define GDU_AE_HSSROFF_HSTOFFT_P1_SHIFT          (16U)
#define GDU_AE_HSSROFF_HSTOFFT_P1_WIDTH          (7U)
#define GDU_AE_HSSROFF_HSTOFFT_P1(x)             (((uint32_t)(((uint32_t)(x)) << GDU_AE_HSSROFF_HSTOFFT_P1_SHIFT)) & GDU_AE_HSSROFF_HSTOFFT_P1_MASK)

#define GDU_AE_HSSROFF_HSTOFFT_P2_MASK           (0x7F000000U)
#define GDU_AE_HSSROFF_HSTOFFT_P2_SHIFT          (24U)
#define GDU_AE_HSSROFF_HSTOFFT_P2_WIDTH          (7U)
#define GDU_AE_HSSROFF_HSTOFFT_P2(x)             (((uint32_t)(((uint32_t)(x)) << GDU_AE_HSSROFF_HSTOFFT_P2_SHIFT)) & GDU_AE_HSSROFF_HSTOFFT_P2_MASK)
/*! @} */

/*! @name LSSRON - Low-Side Slew Rate On */
/*! @{ */

#define GDU_AE_LSSRON_LSTONC_P1_MASK             (0x1FU)
#define GDU_AE_LSSRON_LSTONC_P1_SHIFT            (0U)
#define GDU_AE_LSSRON_LSTONC_P1_WIDTH            (5U)
#define GDU_AE_LSSRON_LSTONC_P1(x)               (((uint32_t)(((uint32_t)(x)) << GDU_AE_LSSRON_LSTONC_P1_SHIFT)) & GDU_AE_LSSRON_LSTONC_P1_MASK)

#define GDU_AE_LSSRON_LSTONC_P2_MASK             (0x3E0U)
#define GDU_AE_LSSRON_LSTONC_P2_SHIFT            (5U)
#define GDU_AE_LSSRON_LSTONC_P2_WIDTH            (5U)
#define GDU_AE_LSSRON_LSTONC_P2(x)               (((uint32_t)(((uint32_t)(x)) << GDU_AE_LSSRON_LSTONC_P2_SHIFT)) & GDU_AE_LSSRON_LSTONC_P2_MASK)

#define GDU_AE_LSSRON_LSTONC_P3_MASK             (0x7C00U)
#define GDU_AE_LSSRON_LSTONC_P3_SHIFT            (10U)
#define GDU_AE_LSSRON_LSTONC_P3_WIDTH            (5U)
#define GDU_AE_LSSRON_LSTONC_P3(x)               (((uint32_t)(((uint32_t)(x)) << GDU_AE_LSSRON_LSTONC_P3_SHIFT)) & GDU_AE_LSSRON_LSTONC_P3_MASK)

#define GDU_AE_LSSRON_LSTONT_P1_MASK             (0x7F0000U)
#define GDU_AE_LSSRON_LSTONT_P1_SHIFT            (16U)
#define GDU_AE_LSSRON_LSTONT_P1_WIDTH            (7U)
#define GDU_AE_LSSRON_LSTONT_P1(x)               (((uint32_t)(((uint32_t)(x)) << GDU_AE_LSSRON_LSTONT_P1_SHIFT)) & GDU_AE_LSSRON_LSTONT_P1_MASK)

#define GDU_AE_LSSRON_LSTONT_P2_MASK             (0x7F000000U)
#define GDU_AE_LSSRON_LSTONT_P2_SHIFT            (24U)
#define GDU_AE_LSSRON_LSTONT_P2_WIDTH            (7U)
#define GDU_AE_LSSRON_LSTONT_P2(x)               (((uint32_t)(((uint32_t)(x)) << GDU_AE_LSSRON_LSTONT_P2_SHIFT)) & GDU_AE_LSSRON_LSTONT_P2_MASK)
/*! @} */

/*! @name LSSROFF - Low-Side Slew Rate Off */
/*! @{ */

#define GDU_AE_LSSROFF_LSTOFFC_P1_MASK           (0x1FU)
#define GDU_AE_LSSROFF_LSTOFFC_P1_SHIFT          (0U)
#define GDU_AE_LSSROFF_LSTOFFC_P1_WIDTH          (5U)
#define GDU_AE_LSSROFF_LSTOFFC_P1(x)             (((uint32_t)(((uint32_t)(x)) << GDU_AE_LSSROFF_LSTOFFC_P1_SHIFT)) & GDU_AE_LSSROFF_LSTOFFC_P1_MASK)

#define GDU_AE_LSSROFF_LSTOFFC_P2_MASK           (0x3E0U)
#define GDU_AE_LSSROFF_LSTOFFC_P2_SHIFT          (5U)
#define GDU_AE_LSSROFF_LSTOFFC_P2_WIDTH          (5U)
#define GDU_AE_LSSROFF_LSTOFFC_P2(x)             (((uint32_t)(((uint32_t)(x)) << GDU_AE_LSSROFF_LSTOFFC_P2_SHIFT)) & GDU_AE_LSSROFF_LSTOFFC_P2_MASK)

#define GDU_AE_LSSROFF_LSTOFFC_P3_MASK           (0x7C00U)
#define GDU_AE_LSSROFF_LSTOFFC_P3_SHIFT          (10U)
#define GDU_AE_LSSROFF_LSTOFFC_P3_WIDTH          (5U)
#define GDU_AE_LSSROFF_LSTOFFC_P3(x)             (((uint32_t)(((uint32_t)(x)) << GDU_AE_LSSROFF_LSTOFFC_P3_SHIFT)) & GDU_AE_LSSROFF_LSTOFFC_P3_MASK)

#define GDU_AE_LSSROFF_LSTOFFT_P1_MASK           (0x7F0000U)
#define GDU_AE_LSSROFF_LSTOFFT_P1_SHIFT          (16U)
#define GDU_AE_LSSROFF_LSTOFFT_P1_WIDTH          (7U)
#define GDU_AE_LSSROFF_LSTOFFT_P1(x)             (((uint32_t)(((uint32_t)(x)) << GDU_AE_LSSROFF_LSTOFFT_P1_SHIFT)) & GDU_AE_LSSROFF_LSTOFFT_P1_MASK)

#define GDU_AE_LSSROFF_LSTOFFT_P2_MASK           (0x7F000000U)
#define GDU_AE_LSSROFF_LSTOFFT_P2_SHIFT          (24U)
#define GDU_AE_LSSROFF_LSTOFFT_P2_WIDTH          (7U)
#define GDU_AE_LSSROFF_LSTOFFT_P2(x)             (((uint32_t)(((uint32_t)(x)) << GDU_AE_LSSROFF_LSTOFFT_P2_SHIFT)) & GDU_AE_LSSROFF_LSTOFFT_P2_MASK)
/*! @} */

/*! @name OFFSDCFG - Off-State Diagnostic */
/*! @{ */

#define GDU_AE_OFFSDCFG_OSDPD0_MASK              (0x1U)
#define GDU_AE_OFFSDCFG_OSDPD0_SHIFT             (0U)
#define GDU_AE_OFFSDCFG_OSDPD0_WIDTH             (1U)
#define GDU_AE_OFFSDCFG_OSDPD0(x)                (((uint8_t)(((uint8_t)(x)) << GDU_AE_OFFSDCFG_OSDPD0_SHIFT)) & GDU_AE_OFFSDCFG_OSDPD0_MASK)

#define GDU_AE_OFFSDCFG_OSDPD1_MASK              (0x2U)
#define GDU_AE_OFFSDCFG_OSDPD1_SHIFT             (1U)
#define GDU_AE_OFFSDCFG_OSDPD1_WIDTH             (1U)
#define GDU_AE_OFFSDCFG_OSDPD1(x)                (((uint8_t)(((uint8_t)(x)) << GDU_AE_OFFSDCFG_OSDPD1_SHIFT)) & GDU_AE_OFFSDCFG_OSDPD1_MASK)

#define GDU_AE_OFFSDCFG_OSDPD2_MASK              (0x4U)
#define GDU_AE_OFFSDCFG_OSDPD2_SHIFT             (2U)
#define GDU_AE_OFFSDCFG_OSDPD2_WIDTH             (1U)
#define GDU_AE_OFFSDCFG_OSDPD2(x)                (((uint8_t)(((uint8_t)(x)) << GDU_AE_OFFSDCFG_OSDPD2_SHIFT)) & GDU_AE_OFFSDCFG_OSDPD2_MASK)

#define GDU_AE_OFFSDCFG_OSDPU0_MASK              (0x10U)
#define GDU_AE_OFFSDCFG_OSDPU0_SHIFT             (4U)
#define GDU_AE_OFFSDCFG_OSDPU0_WIDTH             (1U)
#define GDU_AE_OFFSDCFG_OSDPU0(x)                (((uint8_t)(((uint8_t)(x)) << GDU_AE_OFFSDCFG_OSDPU0_SHIFT)) & GDU_AE_OFFSDCFG_OSDPU0_MASK)

#define GDU_AE_OFFSDCFG_OSDPU1_MASK              (0x20U)
#define GDU_AE_OFFSDCFG_OSDPU1_SHIFT             (5U)
#define GDU_AE_OFFSDCFG_OSDPU1_WIDTH             (1U)
#define GDU_AE_OFFSDCFG_OSDPU1(x)                (((uint8_t)(((uint8_t)(x)) << GDU_AE_OFFSDCFG_OSDPU1_SHIFT)) & GDU_AE_OFFSDCFG_OSDPU1_MASK)

#define GDU_AE_OFFSDCFG_OSDPU2_MASK              (0x40U)
#define GDU_AE_OFFSDCFG_OSDPU2_SHIFT             (6U)
#define GDU_AE_OFFSDCFG_OSDPU2_WIDTH             (1U)
#define GDU_AE_OFFSDCFG_OSDPU2(x)                (((uint8_t)(((uint8_t)(x)) << GDU_AE_OFFSDCFG_OSDPU2_SHIFT)) & GDU_AE_OFFSDCFG_OSDPU2_MASK)
/*! @} */

/*! @name DSCFG - Desaturation Level */
/*! @{ */

#define GDU_AE_DSCFG_DSLLS_MASK                  (0x7U)
#define GDU_AE_DSCFG_DSLLS_SHIFT                 (0U)
#define GDU_AE_DSCFG_DSLLS_WIDTH                 (3U)
#define GDU_AE_DSCFG_DSLLS(x)                    (((uint16_t)(((uint16_t)(x)) << GDU_AE_DSCFG_DSLLS_SHIFT)) & GDU_AE_DSCFG_DSLLS_MASK)

#define GDU_AE_DSCFG_DSLHS_MASK                  (0x70U)
#define GDU_AE_DSCFG_DSLHS_SHIFT                 (4U)
#define GDU_AE_DSCFG_DSLHS_WIDTH                 (3U)
#define GDU_AE_DSCFG_DSLHS(x)                    (((uint16_t)(((uint16_t)(x)) << GDU_AE_DSCFG_DSLHS_SHIFT)) & GDU_AE_DSCFG_DSLHS_MASK)

#define GDU_AE_DSCFG_DSFLS_MASK                  (0x300U)
#define GDU_AE_DSCFG_DSFLS_SHIFT                 (8U)
#define GDU_AE_DSCFG_DSFLS_WIDTH                 (2U)
#define GDU_AE_DSCFG_DSFLS(x)                    (((uint16_t)(((uint16_t)(x)) << GDU_AE_DSCFG_DSFLS_SHIFT)) & GDU_AE_DSCFG_DSFLS_MASK)

#define GDU_AE_DSCFG_DSFHS_MASK                  (0x3000U)
#define GDU_AE_DSCFG_DSFHS_SHIFT                 (12U)
#define GDU_AE_DSCFG_DSFHS_WIDTH                 (2U)
#define GDU_AE_DSCFG_DSFHS(x)                    (((uint16_t)(((uint16_t)(x)) << GDU_AE_DSCFG_DSFHS_SHIFT)) & GDU_AE_DSCFG_DSFHS_MASK)
/*! @} */

/*! @name CPCFG - Charge Pump */
/*! @{ */

#define GDU_AE_CPCFG_CPCD_MASK                   (0x3FFU)
#define GDU_AE_CPCFG_CPCD_SHIFT                  (0U)
#define GDU_AE_CPCFG_CPCD_WIDTH                  (10U)
#define GDU_AE_CPCFG_CPCD(x)                     (((uint32_t)(((uint32_t)(x)) << GDU_AE_CPCFG_CPCD_SHIFT)) & GDU_AE_CPCFG_CPCD_MASK)

#define GDU_AE_CPCFG_CPT_MASK                    (0x3F0000U)
#define GDU_AE_CPCFG_CPT_SHIFT                   (16U)
#define GDU_AE_CPCFG_CPT_WIDTH                   (6U)
#define GDU_AE_CPCFG_CPT(x)                      (((uint32_t)(((uint32_t)(x)) << GDU_AE_CPCFG_CPT_SHIFT)) & GDU_AE_CPCFG_CPT_MASK)

#define GDU_AE_CPCFG_CPCDT_MASK                  (0x3000000U)
#define GDU_AE_CPCFG_CPCDT_SHIFT                 (24U)
#define GDU_AE_CPCFG_CPCDT_WIDTH                 (2U)
#define GDU_AE_CPCFG_CPCDT(x)                    (((uint32_t)(((uint32_t)(x)) << GDU_AE_CPCFG_CPCDT_SHIFT)) & GDU_AE_CPCFG_CPCDT_MASK)
/*! @} */

/*! @name DLYMR - Delay Measurement Result */
/*! @{ */

#define GDU_AE_DLYMR_DELAY_MASK                  (0x7FU)
#define GDU_AE_DLYMR_DELAY_SHIFT                 (0U)
#define GDU_AE_DLYMR_DELAY_WIDTH                 (7U)
#define GDU_AE_DLYMR_DELAY(x)                    (((uint16_t)(((uint16_t)(x)) << GDU_AE_DLYMR_DELAY_SHIFT)) & GDU_AE_DLYMR_DELAY_MASK)

#define GDU_AE_DLYMR_DATAVAL_MASK                (0x8000U)
#define GDU_AE_DLYMR_DATAVAL_SHIFT               (15U)
#define GDU_AE_DLYMR_DATAVAL_WIDTH               (1U)
#define GDU_AE_DLYMR_DATAVAL(x)                  (((uint16_t)(((uint16_t)(x)) << GDU_AE_DLYMR_DATAVAL_SHIFT)) & GDU_AE_DLYMR_DATAVAL_MASK)
/*! @} */

/*! @name DLYMCFG - Delay Measurement */
/*! @{ */

#define GDU_AE_DLYMCFG_CHSEL_MASK                (0x7U)
#define GDU_AE_DLYMCFG_CHSEL_SHIFT               (0U)
#define GDU_AE_DLYMCFG_CHSEL_WIDTH               (3U)
#define GDU_AE_DLYMCFG_CHSEL(x)                  (((uint16_t)(((uint16_t)(x)) << GDU_AE_DLYMCFG_CHSEL_SHIFT)) & GDU_AE_DLYMCFG_CHSEL_MASK)

#define GDU_AE_DLYMCFG_EDGESEL_MASK              (0x8U)
#define GDU_AE_DLYMCFG_EDGESEL_SHIFT             (3U)
#define GDU_AE_DLYMCFG_EDGESEL_WIDTH             (1U)
#define GDU_AE_DLYMCFG_EDGESEL(x)                (((uint16_t)(((uint16_t)(x)) << GDU_AE_DLYMCFG_EDGESEL_SHIFT)) & GDU_AE_DLYMCFG_EDGESEL_MASK)
/*! @} */

/*! @name SUPCFG - Startup Configuration */
/*! @{ */

#define GDU_AE_SUPCFG_SUP_MASK                   (0x1U)
#define GDU_AE_SUPCFG_SUP_SHIFT                  (0U)
#define GDU_AE_SUPCFG_SUP_WIDTH                  (1U)
#define GDU_AE_SUPCFG_SUP(x)                     (((uint8_t)(((uint8_t)(x)) << GDU_AE_SUPCFG_SUP_SHIFT)) & GDU_AE_SUPCFG_SUP_MASK)
/*! @} */

/*! @name IRT - Iref Trimming */
/*! @{ */

#define GDU_AE_IRT_IRT0P0_MASK                   (0x7U)
#define GDU_AE_IRT_IRT0P0_SHIFT                  (0U)
#define GDU_AE_IRT_IRT0P0_WIDTH                  (3U)
#define GDU_AE_IRT_IRT0P0(x)                     (((uint32_t)(((uint32_t)(x)) << GDU_AE_IRT_IRT0P0_SHIFT)) & GDU_AE_IRT_IRT0P0_MASK)

#define GDU_AE_IRT_IRT1P0_MASK                   (0x38U)
#define GDU_AE_IRT_IRT1P0_SHIFT                  (3U)
#define GDU_AE_IRT_IRT1P0_WIDTH                  (3U)
#define GDU_AE_IRT_IRT1P0(x)                     (((uint32_t)(((uint32_t)(x)) << GDU_AE_IRT_IRT1P0_SHIFT)) & GDU_AE_IRT_IRT1P0_MASK)

#define GDU_AE_IRT_IRT0P1_MASK                   (0x700U)
#define GDU_AE_IRT_IRT0P1_SHIFT                  (8U)
#define GDU_AE_IRT_IRT0P1_WIDTH                  (3U)
#define GDU_AE_IRT_IRT0P1(x)                     (((uint32_t)(((uint32_t)(x)) << GDU_AE_IRT_IRT0P1_SHIFT)) & GDU_AE_IRT_IRT0P1_MASK)

#define GDU_AE_IRT_IRT1P1_MASK                   (0x3800U)
#define GDU_AE_IRT_IRT1P1_SHIFT                  (11U)
#define GDU_AE_IRT_IRT1P1_WIDTH                  (3U)
#define GDU_AE_IRT_IRT1P1(x)                     (((uint32_t)(((uint32_t)(x)) << GDU_AE_IRT_IRT1P1_SHIFT)) & GDU_AE_IRT_IRT1P1_MASK)

#define GDU_AE_IRT_IRT0P2_MASK                   (0x70000U)
#define GDU_AE_IRT_IRT0P2_SHIFT                  (16U)
#define GDU_AE_IRT_IRT0P2_WIDTH                  (3U)
#define GDU_AE_IRT_IRT0P2(x)                     (((uint32_t)(((uint32_t)(x)) << GDU_AE_IRT_IRT0P2_SHIFT)) & GDU_AE_IRT_IRT0P2_MASK)

#define GDU_AE_IRT_IRT1P2_MASK                   (0x380000U)
#define GDU_AE_IRT_IRT1P2_SHIFT                  (19U)
#define GDU_AE_IRT_IRT1P2_WIDTH                  (3U)
#define GDU_AE_IRT_IRT1P2(x)                     (((uint32_t)(((uint32_t)(x)) << GDU_AE_IRT_IRT1P2_SHIFT)) & GDU_AE_IRT_IRT1P2_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group GDU_AE_Register_Masks */

/*!
 * @}
 */ /* end of group GDU_AE_Peripheral_Access_Layer */

#endif  /* #if !defined(S32M24x_GDU_AE_H_) */
