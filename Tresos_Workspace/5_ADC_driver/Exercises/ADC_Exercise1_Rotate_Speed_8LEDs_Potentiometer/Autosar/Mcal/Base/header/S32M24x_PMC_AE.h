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
 * @file S32M24x_PMC_AE.h
 * @version 1.3
 * @date 2023-05-30
 * @brief Peripheral Access Layer for S32M24x_PMC_AE
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
#if !defined(S32M24x_PMC_AE_H_)  /* Check if memory map has not been already included */
#define S32M24x_PMC_AE_H_

#include "S32M24x_COMMON.h"

/* ----------------------------------------------------------------------------
   -- PMC_AE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_AE_Peripheral_Access_Layer PMC_AE Peripheral Access Layer
 * @{
 */

/** PMC_AE - Register Layout Typedef */
typedef struct {
  __IO uint32_t CONFIG;                            /**< PMC Configuration Register, offset: 0x0 */
  __IO uint32_t MONITOR;                           /**< PMC Monitor Register, offset: 0x4 */
  uint8_t RESERVED_0[4];
  __IO uint32_t MONCHECK;                          /**< Monitor Self Check Register, offset: 0xC */
} PMC_AE_Type, *PMC_AE_MemMapPtr;

/** Number of instances of the PMC_AE module. */
#define PMC_AE_INSTANCE_COUNT                    (1u)

/* PMC_AE - Peripheral instance base addresses */
/** Peripheral PMC_AE base address */
#define IP_PMC_AE_BASE                           (0x100u)
/** Peripheral PMC_AE base pointer */
#define IP_PMC_AE                                ((PMC_AE_Type *)IP_PMC_AE_BASE)
/** Array initializer of PMC_AE peripheral base addresses */
#define IP_PMC_AE_BASE_ADDRS                     { IP_PMC_AE_BASE }
/** Array initializer of PMC_AE peripheral base pointers */
#define IP_PMC_AE_BASE_PTRS                      { IP_PMC_AE }

/* ----------------------------------------------------------------------------
   -- PMC_AE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_AE_Register_Masks PMC_AE Register Masks
 * @{
 */

/*! @name CONFIG - PMC Configuration Register */
/*! @{ */

#define PMC_AE_CONFIG_VDDSEL5V_MASK              (0x1U)
#define PMC_AE_CONFIG_VDDSEL5V_SHIFT             (0U)
#define PMC_AE_CONFIG_VDDSEL5V_WIDTH             (1U)
#define PMC_AE_CONFIG_VDDSEL5V(x)                (((uint32_t)(((uint32_t)(x)) << PMC_AE_CONFIG_VDDSEL5V_SHIFT)) & PMC_AE_CONFIG_VDDSEL5V_MASK)

#define PMC_AE_CONFIG_VPREINT_MASK               (0x2U)
#define PMC_AE_CONFIG_VPREINT_SHIFT              (1U)
#define PMC_AE_CONFIG_VPREINT_WIDTH              (1U)
#define PMC_AE_CONFIG_VPREINT(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_AE_CONFIG_VPREINT_SHIFT)) & PMC_AE_CONFIG_VPREINT_MASK)

#define PMC_AE_CONFIG_VPREEXT_MASK               (0x4U)
#define PMC_AE_CONFIG_VPREEXT_SHIFT              (2U)
#define PMC_AE_CONFIG_VPREEXT_WIDTH              (1U)
#define PMC_AE_CONFIG_VPREEXT(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_AE_CONFIG_VPREEXT_SHIFT)) & PMC_AE_CONFIG_VPREEXT_MASK)

#define PMC_AE_CONFIG_VDDCEN_MASK                (0x8U)
#define PMC_AE_CONFIG_VDDCEN_SHIFT               (3U)
#define PMC_AE_CONFIG_VDDCEN_WIDTH               (1U)
#define PMC_AE_CONFIG_VDDCEN(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_AE_CONFIG_VDDCEN_SHIFT)) & PMC_AE_CONFIG_VDDCEN_MASK)

#define PMC_AE_CONFIG_LINSUPSEL_MASK             (0x10U)
#define PMC_AE_CONFIG_LINSUPSEL_SHIFT            (4U)
#define PMC_AE_CONFIG_LINSUPSEL_WIDTH            (1U)
#define PMC_AE_CONFIG_LINSUPSEL(x)               (((uint32_t)(((uint32_t)(x)) << PMC_AE_CONFIG_LINSUPSEL_SHIFT)) & PMC_AE_CONFIG_LINSUPSEL_MASK)

#define PMC_AE_CONFIG_LVDVLSSEL_MASK             (0x20U)
#define PMC_AE_CONFIG_LVDVLSSEL_SHIFT            (5U)
#define PMC_AE_CONFIG_LVDVLSSEL_WIDTH            (1U)
#define PMC_AE_CONFIG_LVDVLSSEL(x)               (((uint32_t)(((uint32_t)(x)) << PMC_AE_CONFIG_LVDVLSSEL_SHIFT)) & PMC_AE_CONFIG_LVDVLSSEL_MASK)

#define PMC_AE_CONFIG_LINSUPEN_MASK              (0x40U)
#define PMC_AE_CONFIG_LINSUPEN_SHIFT             (6U)
#define PMC_AE_CONFIG_LINSUPEN_WIDTH             (1U)
#define PMC_AE_CONFIG_LINSUPEN(x)                (((uint32_t)(((uint32_t)(x)) << PMC_AE_CONFIG_LINSUPEN_SHIFT)) & PMC_AE_CONFIG_LINSUPEN_MASK)
/*! @} */

/*! @name MONITOR - PMC Monitor Register */
/*! @{ */

#define PMC_AE_MONITOR_HVD15F_MASK               (0x1U)
#define PMC_AE_MONITOR_HVD15F_SHIFT              (0U)
#define PMC_AE_MONITOR_HVD15F_WIDTH              (1U)
#define PMC_AE_MONITOR_HVD15F(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_HVD15F_SHIFT)) & PMC_AE_MONITOR_HVD15F_MASK)

#define PMC_AE_MONITOR_HVDINTF_MASK              (0x2U)
#define PMC_AE_MONITOR_HVDINTF_SHIFT             (1U)
#define PMC_AE_MONITOR_HVDINTF_WIDTH             (1U)
#define PMC_AE_MONITOR_HVDINTF(x)                (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_HVDINTF_SHIFT)) & PMC_AE_MONITOR_HVDINTF_MASK)

#define PMC_AE_MONITOR_HVDVDDF_MASK              (0x4U)
#define PMC_AE_MONITOR_HVDVDDF_SHIFT             (2U)
#define PMC_AE_MONITOR_HVDVDDF_WIDTH             (1U)
#define PMC_AE_MONITOR_HVDVDDF(x)                (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_HVDVDDF_SHIFT)) & PMC_AE_MONITOR_HVDVDDF_MASK)

#define PMC_AE_MONITOR_LVDCF_MASK                (0x8U)
#define PMC_AE_MONITOR_LVDCF_SHIFT               (3U)
#define PMC_AE_MONITOR_LVDCF_WIDTH               (1U)
#define PMC_AE_MONITOR_LVDCF(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_LVDCF_SHIFT)) & PMC_AE_MONITOR_LVDCF_MASK)

#define PMC_AE_MONITOR_LVDVLSF_MASK              (0x10U)
#define PMC_AE_MONITOR_LVDVLSF_SHIFT             (4U)
#define PMC_AE_MONITOR_LVDVLSF_WIDTH             (1U)
#define PMC_AE_MONITOR_LVDVLSF(x)                (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_LVDVLSF_SHIFT)) & PMC_AE_MONITOR_LVDVLSF_MASK)

#define PMC_AE_MONITOR_LVR15F_MASK               (0x20U)
#define PMC_AE_MONITOR_LVR15F_SHIFT              (5U)
#define PMC_AE_MONITOR_LVR15F_WIDTH              (1U)
#define PMC_AE_MONITOR_LVR15F(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_LVR15F_SHIFT)) & PMC_AE_MONITOR_LVR15F_MASK)

#define PMC_AE_MONITOR_LVRINTF_MASK              (0x40U)
#define PMC_AE_MONITOR_LVRINTF_SHIFT             (6U)
#define PMC_AE_MONITOR_LVRINTF_WIDTH             (1U)
#define PMC_AE_MONITOR_LVRINTF(x)                (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_LVRINTF_SHIFT)) & PMC_AE_MONITOR_LVRINTF_MASK)

#define PMC_AE_MONITOR_PORF_MASK                 (0x80U)
#define PMC_AE_MONITOR_PORF_SHIFT                (7U)
#define PMC_AE_MONITOR_PORF_WIDTH                (1U)
#define PMC_AE_MONITOR_PORF(x)                   (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_PORF_SHIFT)) & PMC_AE_MONITOR_PORF_MASK)

#define PMC_AE_MONITOR_IHVD15F_MASK              (0x100U)
#define PMC_AE_MONITOR_IHVD15F_SHIFT             (8U)
#define PMC_AE_MONITOR_IHVD15F_WIDTH             (1U)
#define PMC_AE_MONITOR_IHVD15F(x)                (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_IHVD15F_SHIFT)) & PMC_AE_MONITOR_IHVD15F_MASK)

#define PMC_AE_MONITOR_IHVDINTF_MASK             (0x200U)
#define PMC_AE_MONITOR_IHVDINTF_SHIFT            (9U)
#define PMC_AE_MONITOR_IHVDINTF_WIDTH            (1U)
#define PMC_AE_MONITOR_IHVDINTF(x)               (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_IHVDINTF_SHIFT)) & PMC_AE_MONITOR_IHVDINTF_MASK)

#define PMC_AE_MONITOR_IHVDVDDF_MASK             (0x400U)
#define PMC_AE_MONITOR_IHVDVDDF_SHIFT            (10U)
#define PMC_AE_MONITOR_IHVDVDDF_WIDTH            (1U)
#define PMC_AE_MONITOR_IHVDVDDF(x)               (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_IHVDVDDF_SHIFT)) & PMC_AE_MONITOR_IHVDVDDF_MASK)

#define PMC_AE_MONITOR_ILVR15F_MASK              (0x2000U)
#define PMC_AE_MONITOR_ILVR15F_SHIFT             (13U)
#define PMC_AE_MONITOR_ILVR15F_WIDTH             (1U)
#define PMC_AE_MONITOR_ILVR15F(x)                (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_ILVR15F_SHIFT)) & PMC_AE_MONITOR_ILVR15F_MASK)

#define PMC_AE_MONITOR_ILVRINTF_MASK             (0x4000U)
#define PMC_AE_MONITOR_ILVRINTF_SHIFT            (14U)
#define PMC_AE_MONITOR_ILVRINTF_WIDTH            (1U)
#define PMC_AE_MONITOR_ILVRINTF(x)               (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_ILVRINTF_SHIFT)) & PMC_AE_MONITOR_ILVRINTF_MASK)

#define PMC_AE_MONITOR_HVD15S_MASK               (0x10000U)
#define PMC_AE_MONITOR_HVD15S_SHIFT              (16U)
#define PMC_AE_MONITOR_HVD15S_WIDTH              (1U)
#define PMC_AE_MONITOR_HVD15S(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_HVD15S_SHIFT)) & PMC_AE_MONITOR_HVD15S_MASK)

#define PMC_AE_MONITOR_HVDINTS_MASK              (0x20000U)
#define PMC_AE_MONITOR_HVDINTS_SHIFT             (17U)
#define PMC_AE_MONITOR_HVDINTS_WIDTH             (1U)
#define PMC_AE_MONITOR_HVDINTS(x)                (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_HVDINTS_SHIFT)) & PMC_AE_MONITOR_HVDINTS_MASK)

#define PMC_AE_MONITOR_HVDVDDS_MASK              (0x40000U)
#define PMC_AE_MONITOR_HVDVDDS_SHIFT             (18U)
#define PMC_AE_MONITOR_HVDVDDS_WIDTH             (1U)
#define PMC_AE_MONITOR_HVDVDDS(x)                (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_HVDVDDS_SHIFT)) & PMC_AE_MONITOR_HVDVDDS_MASK)

#define PMC_AE_MONITOR_LVDCS_MASK                (0x80000U)
#define PMC_AE_MONITOR_LVDCS_SHIFT               (19U)
#define PMC_AE_MONITOR_LVDCS_WIDTH               (1U)
#define PMC_AE_MONITOR_LVDCS(x)                  (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_LVDCS_SHIFT)) & PMC_AE_MONITOR_LVDCS_MASK)

#define PMC_AE_MONITOR_LVDVLSS_MASK              (0x100000U)
#define PMC_AE_MONITOR_LVDVLSS_SHIFT             (20U)
#define PMC_AE_MONITOR_LVDVLSS_WIDTH             (1U)
#define PMC_AE_MONITOR_LVDVLSS(x)                (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_LVDVLSS_SHIFT)) & PMC_AE_MONITOR_LVDVLSS_MASK)

#define PMC_AE_MONITOR_HVDINT15IE_MASK           (0x1000000U)
#define PMC_AE_MONITOR_HVDINT15IE_SHIFT          (24U)
#define PMC_AE_MONITOR_HVDINT15IE_WIDTH          (1U)
#define PMC_AE_MONITOR_HVDINT15IE(x)             (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_HVDINT15IE_SHIFT)) & PMC_AE_MONITOR_HVDINT15IE_MASK)

#define PMC_AE_MONITOR_HVDVDDIE_MASK             (0x4000000U)
#define PMC_AE_MONITOR_HVDVDDIE_SHIFT            (26U)
#define PMC_AE_MONITOR_HVDVDDIE_WIDTH            (1U)
#define PMC_AE_MONITOR_HVDVDDIE(x)               (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_HVDVDDIE_SHIFT)) & PMC_AE_MONITOR_HVDVDDIE_MASK)

#define PMC_AE_MONITOR_LVDCIE_MASK               (0x8000000U)
#define PMC_AE_MONITOR_LVDCIE_SHIFT              (27U)
#define PMC_AE_MONITOR_LVDCIE_WIDTH              (1U)
#define PMC_AE_MONITOR_LVDCIE(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_LVDCIE_SHIFT)) & PMC_AE_MONITOR_LVDCIE_MASK)

#define PMC_AE_MONITOR_LVDVLSIE_MASK             (0x10000000U)
#define PMC_AE_MONITOR_LVDVLSIE_SHIFT            (28U)
#define PMC_AE_MONITOR_LVDVLSIE_WIDTH            (1U)
#define PMC_AE_MONITOR_LVDVLSIE(x)               (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONITOR_LVDVLSIE_SHIFT)) & PMC_AE_MONITOR_LVDVLSIE_MASK)
/*! @} */

/*! @name MONCHECK - Monitor Self Check Register */
/*! @{ */

#define PMC_AE_MONCHECK_DONEF_MASK               (0x10000U)
#define PMC_AE_MONCHECK_DONEF_SHIFT              (16U)
#define PMC_AE_MONCHECK_DONEF_WIDTH              (1U)
#define PMC_AE_MONCHECK_DONEF(x)                 (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONCHECK_DONEF_SHIFT)) & PMC_AE_MONCHECK_DONEF_MASK)

#define PMC_AE_MONCHECK_TRIGGER_MASK             (0xC00000U)
#define PMC_AE_MONCHECK_TRIGGER_SHIFT            (22U)
#define PMC_AE_MONCHECK_TRIGGER_WIDTH            (2U)
#define PMC_AE_MONCHECK_TRIGGER(x)               (((uint32_t)(((uint32_t)(x)) << PMC_AE_MONCHECK_TRIGGER_SHIFT)) & PMC_AE_MONCHECK_TRIGGER_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group PMC_AE_Register_Masks */

/*!
 * @}
 */ /* end of group PMC_AE_Peripheral_Access_Layer */

#endif  /* #if !defined(S32M24x_PMC_AE_H_) */
