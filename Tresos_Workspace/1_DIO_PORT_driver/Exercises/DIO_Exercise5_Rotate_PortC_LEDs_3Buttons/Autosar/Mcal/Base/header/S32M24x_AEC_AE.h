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
 * @file S32M24x_AEC_AE.h
 * @version 1.3
 * @date 2023-05-30
 * @brief Peripheral Access Layer for S32M24x_AEC_AE
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
#if !defined(S32M24x_AEC_AE_H_)  /* Check if memory map has not been already included */
#define S32M24x_AEC_AE_H_

#include "S32M24x_COMMON.h"

/* ----------------------------------------------------------------------------
   -- AEC_AE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AEC_AE_Peripheral_Access_Layer AEC_AE Peripheral Access Layer
 * @{
 */

/** AEC_AE - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< AEC Version ID, offset: 0x0 */
  uint8_t RESERVED_0[4];
  __IO uint16_t LOCK_CONTROL;                      /**< Lock Control, offset: 0x8 */
  uint8_t RESERVED_1[2];
  __IO uint32_t LPWU_CONTROL;                      /**< Power Mode Control, offset: 0xC */
  __IO uint16_t EVENTS_STATUS;                     /**< Event Notifications Status, offset: 0x10 */
  uint8_t RESERVED_2[2];
  __IO uint16_t EVENTS_ENABLE;                     /**< Event Notifications Enable, offset: 0x14 */
  uint8_t RESERVED_3[2];
  __IO uint16_t FAULTS_STATUS;                     /**< Fault Notifications Status, offset: 0x18 */
  uint8_t RESERVED_4[2];
  __IO uint16_t FAULTS_ENABLE;                     /**< Fault Notifications Enable, offset: 0x1C */
  uint8_t RESERVED_5[2];
  __IO uint32_t NOTIFS_MONITOR;                    /**< Monitoring of Notifications, offset: 0x20 */
  __O  uint32_t IRQ_SET;                           /**< Set Status Bits, offset: 0x24 */
  __IO uint32_t SAFETY_ENABLE;                     /**< Safety Enable, offset: 0x28 */
  __IO uint16_t SYSCLK_CHECK;                      /**< System Clock Check, offset: 0x2C */
  uint8_t RESERVED_6[2];
  __IO uint16_t ALIVE_WD_CFG;                      /**< Alive Watchdog Configuration, offset: 0x30 */
  uint8_t RESERVED_7[2];
  __IO uint16_t ALIVE_WD_TOKEN;                    /**< Alive Watchdog Reference Value, offset: 0x34 */
  uint8_t RESERVED_8[2];
  __IO uint16_t ALIVE_WD_ANSWER;                   /**< Alive Watchdog Answer, offset: 0x38 */
  uint8_t RESERVED_9[2];
  __IO uint16_t FAULT_WD_CFG;                      /**< Fault Watchdog Configuration, offset: 0x3C */
  uint8_t RESERVED_10[2];
  __IO uint32_t CLKGEN_CFG;                        /**< Clock Generator Configuration, offset: 0x40 */
  __IO uint16_t RSTGEN_CFG;                        /**< Reset Generator Configuration, offset: 0x44 */
  uint8_t RESERVED_11[2];
  __IO uint32_t IO_FUNCMUX_CFG;                    /**< IO Funcmux Configuration, offset: 0x48 */
  uint8_t RESERVED_12[20];
  __IO uint16_t LINPHY_CFG;                        /**< LINPHY Configuration, offset: 0x60 */
  uint8_t RESERVED_13[2];
  __IO uint32_t LINPHY_MONITOR;                    /**< LINPHY Monitor, offset: 0x64 */
  uint8_t RESERVED_14[8];
  __IO uint16_t CANPHY_CFG;                        /**< CANPHY Configuration, offset: 0x70 */
  uint8_t RESERVED_15[2];
  __IO uint16_t CANPHY_MONITOR;                    /**< CANPHY Monitor, offset: 0x74 */
  uint8_t RESERVED_16[10];
  __IO uint32_t TMON_PHY;                          /**< Temperature Monitor PHY, offset: 0x80 */
  __IO uint32_t TMON_PMC;                          /**< Temperature Monitor PMC, offset: 0x84 */
  __IO uint16_t TMON_MONITOR;                      /**< TMON Monitor, offset: 0x88 */
  __IO uint16_t TMON_CHECK;                        /**< TMON Check, offset: 0x8A */
} AEC_AE_Type, *AEC_AE_MemMapPtr;

/** Number of instances of the AEC_AE module. */
#define AEC_AE_INSTANCE_COUNT                    (1u)

/* AEC_AE - Peripheral instance base addresses */
/** Peripheral AEC_AE base address */
#define IP_AEC_AE_BASE                           (0u)
/** Peripheral AEC_AE base pointer */
#define IP_AEC_AE                                ((AEC_AE_Type *)IP_AEC_AE_BASE)
/** Array initializer of AEC_AE peripheral base addresses */
#define IP_AEC_AE_BASE_ADDRS                     { IP_AEC_AE_BASE }
/** Array initializer of AEC_AE peripheral base pointers */
#define IP_AEC_AE_BASE_PTRS                      { IP_AEC_AE }

/* ----------------------------------------------------------------------------
   -- AEC_AE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AEC_AE_Register_Masks AEC_AE Register Masks
 * @{
 */

/*! @name VERID - AEC Version ID */
/*! @{ */

#define AEC_AE_VERID_MINOR_MASK                  (0xFU)
#define AEC_AE_VERID_MINOR_SHIFT                 (0U)
#define AEC_AE_VERID_MINOR_WIDTH                 (4U)
#define AEC_AE_VERID_MINOR(x)                    (((uint32_t)(((uint32_t)(x)) << AEC_AE_VERID_MINOR_SHIFT)) & AEC_AE_VERID_MINOR_MASK)

#define AEC_AE_VERID_VARIANT_MASK                (0xF0U)
#define AEC_AE_VERID_VARIANT_SHIFT               (4U)
#define AEC_AE_VERID_VARIANT_WIDTH               (4U)
#define AEC_AE_VERID_VARIANT(x)                  (((uint32_t)(((uint32_t)(x)) << AEC_AE_VERID_VARIANT_SHIFT)) & AEC_AE_VERID_VARIANT_MASK)

#define AEC_AE_VERID_MAJOR_MASK                  (0xFF00U)
#define AEC_AE_VERID_MAJOR_SHIFT                 (8U)
#define AEC_AE_VERID_MAJOR_WIDTH                 (8U)
#define AEC_AE_VERID_MAJOR(x)                    (((uint32_t)(((uint32_t)(x)) << AEC_AE_VERID_MAJOR_SHIFT)) & AEC_AE_VERID_MAJOR_MASK)

#define AEC_AE_VERID_ID_MASK                     (0xFFFF0000U)
#define AEC_AE_VERID_ID_SHIFT                    (16U)
#define AEC_AE_VERID_ID_WIDTH                    (16U)
#define AEC_AE_VERID_ID(x)                       (((uint32_t)(((uint32_t)(x)) << AEC_AE_VERID_ID_SHIFT)) & AEC_AE_VERID_ID_MASK)
/*! @} */

/*! @name LOCK_CONTROL - Lock Control */
/*! @{ */

#define AEC_AE_LOCK_CONTROL_AWDG_CFG_LOCK_MASK   (0x1U)
#define AEC_AE_LOCK_CONTROL_AWDG_CFG_LOCK_SHIFT  (0U)
#define AEC_AE_LOCK_CONTROL_AWDG_CFG_LOCK_WIDTH  (1U)
#define AEC_AE_LOCK_CONTROL_AWDG_CFG_LOCK(x)     (((uint16_t)(((uint16_t)(x)) << AEC_AE_LOCK_CONTROL_AWDG_CFG_LOCK_SHIFT)) & AEC_AE_LOCK_CONTROL_AWDG_CFG_LOCK_MASK)

#define AEC_AE_LOCK_CONTROL_FWDG_CFG_LOCK_MASK   (0x2U)
#define AEC_AE_LOCK_CONTROL_FWDG_CFG_LOCK_SHIFT  (1U)
#define AEC_AE_LOCK_CONTROL_FWDG_CFG_LOCK_WIDTH  (1U)
#define AEC_AE_LOCK_CONTROL_FWDG_CFG_LOCK(x)     (((uint16_t)(((uint16_t)(x)) << AEC_AE_LOCK_CONTROL_FWDG_CFG_LOCK_SHIFT)) & AEC_AE_LOCK_CONTROL_FWDG_CFG_LOCK_MASK)

#define AEC_AE_LOCK_CONTROL_TMON_CHK_LOCK_MASK   (0x4U)
#define AEC_AE_LOCK_CONTROL_TMON_CHK_LOCK_SHIFT  (2U)
#define AEC_AE_LOCK_CONTROL_TMON_CHK_LOCK_WIDTH  (1U)
#define AEC_AE_LOCK_CONTROL_TMON_CHK_LOCK(x)     (((uint16_t)(((uint16_t)(x)) << AEC_AE_LOCK_CONTROL_TMON_CHK_LOCK_SHIFT)) & AEC_AE_LOCK_CONTROL_TMON_CHK_LOCK_MASK)

#define AEC_AE_LOCK_CONTROL_LPWU_CTL_LOCK_MASK   (0x8U)
#define AEC_AE_LOCK_CONTROL_LPWU_CTL_LOCK_SHIFT  (3U)
#define AEC_AE_LOCK_CONTROL_LPWU_CTL_LOCK_WIDTH  (1U)
#define AEC_AE_LOCK_CONTROL_LPWU_CTL_LOCK(x)     (((uint16_t)(((uint16_t)(x)) << AEC_AE_LOCK_CONTROL_LPWU_CTL_LOCK_SHIFT)) & AEC_AE_LOCK_CONTROL_LPWU_CTL_LOCK_MASK)

#define AEC_AE_LOCK_CONTROL_CLKG_CFG_LOCK_MASK   (0x10U)
#define AEC_AE_LOCK_CONTROL_CLKG_CFG_LOCK_SHIFT  (4U)
#define AEC_AE_LOCK_CONTROL_CLKG_CFG_LOCK_WIDTH  (1U)
#define AEC_AE_LOCK_CONTROL_CLKG_CFG_LOCK(x)     (((uint16_t)(((uint16_t)(x)) << AEC_AE_LOCK_CONTROL_CLKG_CFG_LOCK_SHIFT)) & AEC_AE_LOCK_CONTROL_CLKG_CFG_LOCK_MASK)

#define AEC_AE_LOCK_CONTROL_IRQ_SET_LOCK_MASK    (0x20U)
#define AEC_AE_LOCK_CONTROL_IRQ_SET_LOCK_SHIFT   (5U)
#define AEC_AE_LOCK_CONTROL_IRQ_SET_LOCK_WIDTH   (1U)
#define AEC_AE_LOCK_CONTROL_IRQ_SET_LOCK(x)      (((uint16_t)(((uint16_t)(x)) << AEC_AE_LOCK_CONTROL_IRQ_SET_LOCK_SHIFT)) & AEC_AE_LOCK_CONTROL_IRQ_SET_LOCK_MASK)

#define AEC_AE_LOCK_CONTROL_RSTG_CFG_LOCK_MASK   (0x40U)
#define AEC_AE_LOCK_CONTROL_RSTG_CFG_LOCK_SHIFT  (6U)
#define AEC_AE_LOCK_CONTROL_RSTG_CFG_LOCK_WIDTH  (1U)
#define AEC_AE_LOCK_CONTROL_RSTG_CFG_LOCK(x)     (((uint16_t)(((uint16_t)(x)) << AEC_AE_LOCK_CONTROL_RSTG_CFG_LOCK_SHIFT)) & AEC_AE_LOCK_CONTROL_RSTG_CFG_LOCK_MASK)

#define AEC_AE_LOCK_CONTROL_UNLOCK_KEY_MASK      (0xFF00U)
#define AEC_AE_LOCK_CONTROL_UNLOCK_KEY_SHIFT     (8U)
#define AEC_AE_LOCK_CONTROL_UNLOCK_KEY_WIDTH     (8U)
#define AEC_AE_LOCK_CONTROL_UNLOCK_KEY(x)        (((uint16_t)(((uint16_t)(x)) << AEC_AE_LOCK_CONTROL_UNLOCK_KEY_SHIFT)) & AEC_AE_LOCK_CONTROL_UNLOCK_KEY_MASK)
/*! @} */

/*! @name LPWU_CONTROL - Power Mode Control */
/*! @{ */

#define AEC_AE_LPWU_CONTROL_LPTIMER_CFG_MASK     (0xFFFFU)
#define AEC_AE_LPWU_CONTROL_LPTIMER_CFG_SHIFT    (0U)
#define AEC_AE_LPWU_CONTROL_LPTIMER_CFG_WIDTH    (16U)
#define AEC_AE_LPWU_CONTROL_LPTIMER_CFG(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_LPWU_CONTROL_LPTIMER_CFG_SHIFT)) & AEC_AE_LPWU_CONTROL_LPTIMER_CFG_MASK)

#define AEC_AE_LPWU_CONTROL_SLEEP_REQ_MASK       (0x10000U)
#define AEC_AE_LPWU_CONTROL_SLEEP_REQ_SHIFT      (16U)
#define AEC_AE_LPWU_CONTROL_SLEEP_REQ_WIDTH      (1U)
#define AEC_AE_LPWU_CONTROL_SLEEP_REQ(x)         (((uint32_t)(((uint32_t)(x)) << AEC_AE_LPWU_CONTROL_SLEEP_REQ_SHIFT)) & AEC_AE_LPWU_CONTROL_SLEEP_REQ_MASK)

#define AEC_AE_LPWU_CONTROL_DEEP_SLEEP_REQ_MASK  (0x20000U)
#define AEC_AE_LPWU_CONTROL_DEEP_SLEEP_REQ_SHIFT (17U)
#define AEC_AE_LPWU_CONTROL_DEEP_SLEEP_REQ_WIDTH (1U)
#define AEC_AE_LPWU_CONTROL_DEEP_SLEEP_REQ(x)    (((uint32_t)(((uint32_t)(x)) << AEC_AE_LPWU_CONTROL_DEEP_SLEEP_REQ_SHIFT)) & AEC_AE_LPWU_CONTROL_DEEP_SLEEP_REQ_MASK)

#define AEC_AE_LPWU_CONTROL_SW_RST_REQ_MASK      (0x80000U)
#define AEC_AE_LPWU_CONTROL_SW_RST_REQ_SHIFT     (19U)
#define AEC_AE_LPWU_CONTROL_SW_RST_REQ_WIDTH     (1U)
#define AEC_AE_LPWU_CONTROL_SW_RST_REQ(x)        (((uint32_t)(((uint32_t)(x)) << AEC_AE_LPWU_CONTROL_SW_RST_REQ_SHIFT)) & AEC_AE_LPWU_CONTROL_SW_RST_REQ_MASK)

#define AEC_AE_LPWU_CONTROL_NOIRQ_CFG_MASK       (0x80000000U)
#define AEC_AE_LPWU_CONTROL_NOIRQ_CFG_SHIFT      (31U)
#define AEC_AE_LPWU_CONTROL_NOIRQ_CFG_WIDTH      (1U)
#define AEC_AE_LPWU_CONTROL_NOIRQ_CFG(x)         (((uint32_t)(((uint32_t)(x)) << AEC_AE_LPWU_CONTROL_NOIRQ_CFG_SHIFT)) & AEC_AE_LPWU_CONTROL_NOIRQ_CFG_MASK)
/*! @} */

/*! @name EVENTS_STATUS - Event Notifications Status */
/*! @{ */

#define AEC_AE_EVENTS_STATUS_LIN_INT_FL_MASK     (0x4U)
#define AEC_AE_EVENTS_STATUS_LIN_INT_FL_SHIFT    (2U)
#define AEC_AE_EVENTS_STATUS_LIN_INT_FL_WIDTH    (1U)
#define AEC_AE_EVENTS_STATUS_LIN_INT_FL(x)       (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_STATUS_LIN_INT_FL_SHIFT)) & AEC_AE_EVENTS_STATUS_LIN_INT_FL_MASK)

#define AEC_AE_EVENTS_STATUS_OCD_VDDE_FL_MASK    (0x8U)
#define AEC_AE_EVENTS_STATUS_OCD_VDDE_FL_SHIFT   (3U)
#define AEC_AE_EVENTS_STATUS_OCD_VDDE_FL_WIDTH   (1U)
#define AEC_AE_EVENTS_STATUS_OCD_VDDE_FL(x)      (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_STATUS_OCD_VDDE_FL_SHIFT)) & AEC_AE_EVENTS_STATUS_OCD_VDDE_FL_MASK)

#define AEC_AE_EVENTS_STATUS_TEMP_WDG_PMC_FL_MASK (0x10U)
#define AEC_AE_EVENTS_STATUS_TEMP_WDG_PMC_FL_SHIFT (4U)
#define AEC_AE_EVENTS_STATUS_TEMP_WDG_PMC_FL_WIDTH (1U)
#define AEC_AE_EVENTS_STATUS_TEMP_WDG_PMC_FL(x)  (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_STATUS_TEMP_WDG_PMC_FL_SHIFT)) & AEC_AE_EVENTS_STATUS_TEMP_WDG_PMC_FL_MASK)

#define AEC_AE_EVENTS_STATUS_TEMP_WDG_PHY_FL_MASK (0x20U)
#define AEC_AE_EVENTS_STATUS_TEMP_WDG_PHY_FL_SHIFT (5U)
#define AEC_AE_EVENTS_STATUS_TEMP_WDG_PHY_FL_WIDTH (1U)
#define AEC_AE_EVENTS_STATUS_TEMP_WDG_PHY_FL(x)  (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_STATUS_TEMP_WDG_PHY_FL_SHIFT)) & AEC_AE_EVENTS_STATUS_TEMP_WDG_PHY_FL_MASK)

#define AEC_AE_EVENTS_STATUS_CAN_INT_FL_MASK     (0x40U)
#define AEC_AE_EVENTS_STATUS_CAN_INT_FL_SHIFT    (6U)
#define AEC_AE_EVENTS_STATUS_CAN_INT_FL_WIDTH    (1U)
#define AEC_AE_EVENTS_STATUS_CAN_INT_FL(x)       (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_STATUS_CAN_INT_FL_SHIFT)) & AEC_AE_EVENTS_STATUS_CAN_INT_FL_MASK)

#define AEC_AE_EVENTS_STATUS_LVD_VDDC_FL_MASK    (0x80U)
#define AEC_AE_EVENTS_STATUS_LVD_VDDC_FL_SHIFT   (7U)
#define AEC_AE_EVENTS_STATUS_LVD_VDDC_FL_WIDTH   (1U)
#define AEC_AE_EVENTS_STATUS_LVD_VDDC_FL(x)      (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_STATUS_LVD_VDDC_FL_SHIFT)) & AEC_AE_EVENTS_STATUS_LVD_VDDC_FL_MASK)

#define AEC_AE_EVENTS_STATUS_WAKEUP_FL_MASK      (0x100U)
#define AEC_AE_EVENTS_STATUS_WAKEUP_FL_SHIFT     (8U)
#define AEC_AE_EVENTS_STATUS_WAKEUP_FL_WIDTH     (1U)
#define AEC_AE_EVENTS_STATUS_WAKEUP_FL(x)        (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_STATUS_WAKEUP_FL_SHIFT)) & AEC_AE_EVENTS_STATUS_WAKEUP_FL_MASK)

#define AEC_AE_EVENTS_STATUS_HVI_ACTIVE_FL_MASK  (0x200U)
#define AEC_AE_EVENTS_STATUS_HVI_ACTIVE_FL_SHIFT (9U)
#define AEC_AE_EVENTS_STATUS_HVI_ACTIVE_FL_WIDTH (1U)
#define AEC_AE_EVENTS_STATUS_HVI_ACTIVE_FL(x)    (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_STATUS_HVI_ACTIVE_FL_SHIFT)) & AEC_AE_EVENTS_STATUS_HVI_ACTIVE_FL_MASK)

#define AEC_AE_EVENTS_STATUS_HVI_AE_SUPPLY_FL_MASK (0x1000U)
#define AEC_AE_EVENTS_STATUS_HVI_AE_SUPPLY_FL_SHIFT (12U)
#define AEC_AE_EVENTS_STATUS_HVI_AE_SUPPLY_FL_WIDTH (1U)
#define AEC_AE_EVENTS_STATUS_HVI_AE_SUPPLY_FL(x) (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_STATUS_HVI_AE_SUPPLY_FL_SHIFT)) & AEC_AE_EVENTS_STATUS_HVI_AE_SUPPLY_FL_MASK)

#define AEC_AE_EVENTS_STATUS_STATERESET_FL_MASK  (0x4000U)
#define AEC_AE_EVENTS_STATUS_STATERESET_FL_SHIFT (14U)
#define AEC_AE_EVENTS_STATUS_STATERESET_FL_WIDTH (1U)
#define AEC_AE_EVENTS_STATUS_STATERESET_FL(x)    (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_STATUS_STATERESET_FL_SHIFT)) & AEC_AE_EVENTS_STATUS_STATERESET_FL_MASK)

#define AEC_AE_EVENTS_STATUS_FRAMEWIDTH_FL_MASK  (0x8000U)
#define AEC_AE_EVENTS_STATUS_FRAMEWIDTH_FL_SHIFT (15U)
#define AEC_AE_EVENTS_STATUS_FRAMEWIDTH_FL_WIDTH (1U)
#define AEC_AE_EVENTS_STATUS_FRAMEWIDTH_FL(x)    (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_STATUS_FRAMEWIDTH_FL_SHIFT)) & AEC_AE_EVENTS_STATUS_FRAMEWIDTH_FL_MASK)
/*! @} */

/*! @name EVENTS_ENABLE - Event Notifications Enable */
/*! @{ */

#define AEC_AE_EVENTS_ENABLE_LIN_INT_EN_MASK     (0x4U)
#define AEC_AE_EVENTS_ENABLE_LIN_INT_EN_SHIFT    (2U)
#define AEC_AE_EVENTS_ENABLE_LIN_INT_EN_WIDTH    (1U)
#define AEC_AE_EVENTS_ENABLE_LIN_INT_EN(x)       (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_ENABLE_LIN_INT_EN_SHIFT)) & AEC_AE_EVENTS_ENABLE_LIN_INT_EN_MASK)

#define AEC_AE_EVENTS_ENABLE_OCD_VDDE_EN_MASK    (0x8U)
#define AEC_AE_EVENTS_ENABLE_OCD_VDDE_EN_SHIFT   (3U)
#define AEC_AE_EVENTS_ENABLE_OCD_VDDE_EN_WIDTH   (1U)
#define AEC_AE_EVENTS_ENABLE_OCD_VDDE_EN(x)      (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_ENABLE_OCD_VDDE_EN_SHIFT)) & AEC_AE_EVENTS_ENABLE_OCD_VDDE_EN_MASK)

#define AEC_AE_EVENTS_ENABLE_TEMP_WDG_PMC_EN_MASK (0x10U)
#define AEC_AE_EVENTS_ENABLE_TEMP_WDG_PMC_EN_SHIFT (4U)
#define AEC_AE_EVENTS_ENABLE_TEMP_WDG_PMC_EN_WIDTH (1U)
#define AEC_AE_EVENTS_ENABLE_TEMP_WDG_PMC_EN(x)  (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_ENABLE_TEMP_WDG_PMC_EN_SHIFT)) & AEC_AE_EVENTS_ENABLE_TEMP_WDG_PMC_EN_MASK)

#define AEC_AE_EVENTS_ENABLE_TEMP_WDG_PHY_EN_MASK (0x20U)
#define AEC_AE_EVENTS_ENABLE_TEMP_WDG_PHY_EN_SHIFT (5U)
#define AEC_AE_EVENTS_ENABLE_TEMP_WDG_PHY_EN_WIDTH (1U)
#define AEC_AE_EVENTS_ENABLE_TEMP_WDG_PHY_EN(x)  (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_ENABLE_TEMP_WDG_PHY_EN_SHIFT)) & AEC_AE_EVENTS_ENABLE_TEMP_WDG_PHY_EN_MASK)

#define AEC_AE_EVENTS_ENABLE_CAN_INT_EN_MASK     (0x40U)
#define AEC_AE_EVENTS_ENABLE_CAN_INT_EN_SHIFT    (6U)
#define AEC_AE_EVENTS_ENABLE_CAN_INT_EN_WIDTH    (1U)
#define AEC_AE_EVENTS_ENABLE_CAN_INT_EN(x)       (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_ENABLE_CAN_INT_EN_SHIFT)) & AEC_AE_EVENTS_ENABLE_CAN_INT_EN_MASK)

#define AEC_AE_EVENTS_ENABLE_LVD_VDDC_EN_MASK    (0x80U)
#define AEC_AE_EVENTS_ENABLE_LVD_VDDC_EN_SHIFT   (7U)
#define AEC_AE_EVENTS_ENABLE_LVD_VDDC_EN_WIDTH   (1U)
#define AEC_AE_EVENTS_ENABLE_LVD_VDDC_EN(x)      (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_ENABLE_LVD_VDDC_EN_SHIFT)) & AEC_AE_EVENTS_ENABLE_LVD_VDDC_EN_MASK)

#define AEC_AE_EVENTS_ENABLE_WAKEUP_EN_MASK      (0x100U)
#define AEC_AE_EVENTS_ENABLE_WAKEUP_EN_SHIFT     (8U)
#define AEC_AE_EVENTS_ENABLE_WAKEUP_EN_WIDTH     (1U)
#define AEC_AE_EVENTS_ENABLE_WAKEUP_EN(x)        (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_ENABLE_WAKEUP_EN_SHIFT)) & AEC_AE_EVENTS_ENABLE_WAKEUP_EN_MASK)

#define AEC_AE_EVENTS_ENABLE_HVI_ACTIVE_EN_MASK  (0x200U)
#define AEC_AE_EVENTS_ENABLE_HVI_ACTIVE_EN_SHIFT (9U)
#define AEC_AE_EVENTS_ENABLE_HVI_ACTIVE_EN_WIDTH (1U)
#define AEC_AE_EVENTS_ENABLE_HVI_ACTIVE_EN(x)    (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_ENABLE_HVI_ACTIVE_EN_SHIFT)) & AEC_AE_EVENTS_ENABLE_HVI_ACTIVE_EN_MASK)

#define AEC_AE_EVENTS_ENABLE_HVI_AE_SUPPLY_EN_MASK (0x1000U)
#define AEC_AE_EVENTS_ENABLE_HVI_AE_SUPPLY_EN_SHIFT (12U)
#define AEC_AE_EVENTS_ENABLE_HVI_AE_SUPPLY_EN_WIDTH (1U)
#define AEC_AE_EVENTS_ENABLE_HVI_AE_SUPPLY_EN(x) (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_ENABLE_HVI_AE_SUPPLY_EN_SHIFT)) & AEC_AE_EVENTS_ENABLE_HVI_AE_SUPPLY_EN_MASK)

#define AEC_AE_EVENTS_ENABLE_STATERESET_EN_MASK  (0x4000U)
#define AEC_AE_EVENTS_ENABLE_STATERESET_EN_SHIFT (14U)
#define AEC_AE_EVENTS_ENABLE_STATERESET_EN_WIDTH (1U)
#define AEC_AE_EVENTS_ENABLE_STATERESET_EN(x)    (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_ENABLE_STATERESET_EN_SHIFT)) & AEC_AE_EVENTS_ENABLE_STATERESET_EN_MASK)

#define AEC_AE_EVENTS_ENABLE_FRAMEWIDTH_EN_MASK  (0x8000U)
#define AEC_AE_EVENTS_ENABLE_FRAMEWIDTH_EN_SHIFT (15U)
#define AEC_AE_EVENTS_ENABLE_FRAMEWIDTH_EN_WIDTH (1U)
#define AEC_AE_EVENTS_ENABLE_FRAMEWIDTH_EN(x)    (((uint16_t)(((uint16_t)(x)) << AEC_AE_EVENTS_ENABLE_FRAMEWIDTH_EN_SHIFT)) & AEC_AE_EVENTS_ENABLE_FRAMEWIDTH_EN_MASK)
/*! @} */

/*! @name FAULTS_STATUS - Fault Notifications Status */
/*! @{ */

#define AEC_AE_FAULTS_STATUS_GDU_FAULT_PROT_FL_MASK (0x1U)
#define AEC_AE_FAULTS_STATUS_GDU_FAULT_PROT_FL_SHIFT (0U)
#define AEC_AE_FAULTS_STATUS_GDU_FAULT_PROT_FL_WIDTH (1U)
#define AEC_AE_FAULTS_STATUS_GDU_FAULT_PROT_FL(x) (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_STATUS_GDU_FAULT_PROT_FL_SHIFT)) & AEC_AE_FAULTS_STATUS_GDU_FAULT_PROT_FL_MASK)

#define AEC_AE_FAULTS_STATUS_GDU_INT_FL_MASK     (0x2U)
#define AEC_AE_FAULTS_STATUS_GDU_INT_FL_SHIFT    (1U)
#define AEC_AE_FAULTS_STATUS_GDU_INT_FL_WIDTH    (1U)
#define AEC_AE_FAULTS_STATUS_GDU_INT_FL(x)       (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_STATUS_GDU_INT_FL_SHIFT)) & AEC_AE_FAULTS_STATUS_GDU_INT_FL_MASK)

#define AEC_AE_FAULTS_STATUS_DPGA_OC_NEG_FL_MASK (0x4U)
#define AEC_AE_FAULTS_STATUS_DPGA_OC_NEG_FL_SHIFT (2U)
#define AEC_AE_FAULTS_STATUS_DPGA_OC_NEG_FL_WIDTH (1U)
#define AEC_AE_FAULTS_STATUS_DPGA_OC_NEG_FL(x)   (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_STATUS_DPGA_OC_NEG_FL_SHIFT)) & AEC_AE_FAULTS_STATUS_DPGA_OC_NEG_FL_MASK)

#define AEC_AE_FAULTS_STATUS_DPGA_OC_POS_FL_MASK (0x8U)
#define AEC_AE_FAULTS_STATUS_DPGA_OC_POS_FL_SHIFT (3U)
#define AEC_AE_FAULTS_STATUS_DPGA_OC_POS_FL_WIDTH (1U)
#define AEC_AE_FAULTS_STATUS_DPGA_OC_POS_FL(x)   (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_STATUS_DPGA_OC_POS_FL_SHIFT)) & AEC_AE_FAULTS_STATUS_DPGA_OC_POS_FL_MASK)

#define AEC_AE_FAULTS_STATUS_PMC_VLS_FL_MASK     (0x10U)
#define AEC_AE_FAULTS_STATUS_PMC_VLS_FL_SHIFT    (4U)
#define AEC_AE_FAULTS_STATUS_PMC_VLS_FL_WIDTH    (1U)
#define AEC_AE_FAULTS_STATUS_PMC_VLS_FL(x)       (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_STATUS_PMC_VLS_FL_SHIFT)) & AEC_AE_FAULTS_STATUS_PMC_VLS_FL_MASK)

#define AEC_AE_FAULTS_STATUS_RAW_FAILED_FL_MASK  (0x80U)
#define AEC_AE_FAULTS_STATUS_RAW_FAILED_FL_SHIFT (7U)
#define AEC_AE_FAULTS_STATUS_RAW_FAILED_FL_WIDTH (1U)
#define AEC_AE_FAULTS_STATUS_RAW_FAILED_FL(x)    (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_STATUS_RAW_FAILED_FL_SHIFT)) & AEC_AE_FAULTS_STATUS_RAW_FAILED_FL_MASK)

#define AEC_AE_FAULTS_STATUS_CHKSUM_ERR_FL_MASK  (0x100U)
#define AEC_AE_FAULTS_STATUS_CHKSUM_ERR_FL_SHIFT (8U)
#define AEC_AE_FAULTS_STATUS_CHKSUM_ERR_FL_WIDTH (1U)
#define AEC_AE_FAULTS_STATUS_CHKSUM_ERR_FL(x)    (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_STATUS_CHKSUM_ERR_FL_SHIFT)) & AEC_AE_FAULTS_STATUS_CHKSUM_ERR_FL_MASK)

#define AEC_AE_FAULTS_STATUS_OBSCHK_ERR_FL_MASK  (0x200U)
#define AEC_AE_FAULTS_STATUS_OBSCHK_ERR_FL_SHIFT (9U)
#define AEC_AE_FAULTS_STATUS_OBSCHK_ERR_FL_WIDTH (1U)
#define AEC_AE_FAULTS_STATUS_OBSCHK_ERR_FL(x)    (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_STATUS_OBSCHK_ERR_FL_SHIFT)) & AEC_AE_FAULTS_STATUS_OBSCHK_ERR_FL_MASK)

#define AEC_AE_FAULTS_STATUS_XFER_ERR_FL_MASK    (0x400U)
#define AEC_AE_FAULTS_STATUS_XFER_ERR_FL_SHIFT   (10U)
#define AEC_AE_FAULTS_STATUS_XFER_ERR_FL_WIDTH   (1U)
#define AEC_AE_FAULTS_STATUS_XFER_ERR_FL(x)      (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_STATUS_XFER_ERR_FL_SHIFT)) & AEC_AE_FAULTS_STATUS_XFER_ERR_FL_MASK)

#define AEC_AE_FAULTS_STATUS_EVENT_EXPIRED_FL_MASK (0x800U)
#define AEC_AE_FAULTS_STATUS_EVENT_EXPIRED_FL_SHIFT (11U)
#define AEC_AE_FAULTS_STATUS_EVENT_EXPIRED_FL_WIDTH (1U)
#define AEC_AE_FAULTS_STATUS_EVENT_EXPIRED_FL(x) (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_STATUS_EVENT_EXPIRED_FL_SHIFT)) & AEC_AE_FAULTS_STATUS_EVENT_EXPIRED_FL_MASK)

#define AEC_AE_FAULTS_STATUS_MCU_SUPPLY_FL_MASK  (0x1000U)
#define AEC_AE_FAULTS_STATUS_MCU_SUPPLY_FL_SHIFT (12U)
#define AEC_AE_FAULTS_STATUS_MCU_SUPPLY_FL_WIDTH (1U)
#define AEC_AE_FAULTS_STATUS_MCU_SUPPLY_FL(x)    (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_STATUS_MCU_SUPPLY_FL_SHIFT)) & AEC_AE_FAULTS_STATUS_MCU_SUPPLY_FL_MASK)

#define AEC_AE_FAULTS_STATUS_HVD_AE_INTERN_FL_MASK (0x2000U)
#define AEC_AE_FAULTS_STATUS_HVD_AE_INTERN_FL_SHIFT (13U)
#define AEC_AE_FAULTS_STATUS_HVD_AE_INTERN_FL_WIDTH (1U)
#define AEC_AE_FAULTS_STATUS_HVD_AE_INTERN_FL(x) (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_STATUS_HVD_AE_INTERN_FL_SHIFT)) & AEC_AE_FAULTS_STATUS_HVD_AE_INTERN_FL_MASK)

#define AEC_AE_FAULTS_STATUS_ILL_TEST_FL_MASK    (0x4000U)
#define AEC_AE_FAULTS_STATUS_ILL_TEST_FL_SHIFT   (14U)
#define AEC_AE_FAULTS_STATUS_ILL_TEST_FL_WIDTH   (1U)
#define AEC_AE_FAULTS_STATUS_ILL_TEST_FL(x)      (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_STATUS_ILL_TEST_FL_SHIFT)) & AEC_AE_FAULTS_STATUS_ILL_TEST_FL_MASK)

#define AEC_AE_FAULTS_STATUS_ALIVE_WDG_FL_MASK   (0x8000U)
#define AEC_AE_FAULTS_STATUS_ALIVE_WDG_FL_SHIFT  (15U)
#define AEC_AE_FAULTS_STATUS_ALIVE_WDG_FL_WIDTH  (1U)
#define AEC_AE_FAULTS_STATUS_ALIVE_WDG_FL(x)     (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_STATUS_ALIVE_WDG_FL_SHIFT)) & AEC_AE_FAULTS_STATUS_ALIVE_WDG_FL_MASK)
/*! @} */

/*! @name FAULTS_ENABLE - Fault Notifications Enable */
/*! @{ */

#define AEC_AE_FAULTS_ENABLE_GDU_FAULT_PROT_EN_MASK (0x1U)
#define AEC_AE_FAULTS_ENABLE_GDU_FAULT_PROT_EN_SHIFT (0U)
#define AEC_AE_FAULTS_ENABLE_GDU_FAULT_PROT_EN_WIDTH (1U)
#define AEC_AE_FAULTS_ENABLE_GDU_FAULT_PROT_EN(x) (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_ENABLE_GDU_FAULT_PROT_EN_SHIFT)) & AEC_AE_FAULTS_ENABLE_GDU_FAULT_PROT_EN_MASK)

#define AEC_AE_FAULTS_ENABLE_GDU_INT_EN_MASK     (0x2U)
#define AEC_AE_FAULTS_ENABLE_GDU_INT_EN_SHIFT    (1U)
#define AEC_AE_FAULTS_ENABLE_GDU_INT_EN_WIDTH    (1U)
#define AEC_AE_FAULTS_ENABLE_GDU_INT_EN(x)       (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_ENABLE_GDU_INT_EN_SHIFT)) & AEC_AE_FAULTS_ENABLE_GDU_INT_EN_MASK)

#define AEC_AE_FAULTS_ENABLE_DPGA_OC_NEG_EN_MASK (0x4U)
#define AEC_AE_FAULTS_ENABLE_DPGA_OC_NEG_EN_SHIFT (2U)
#define AEC_AE_FAULTS_ENABLE_DPGA_OC_NEG_EN_WIDTH (1U)
#define AEC_AE_FAULTS_ENABLE_DPGA_OC_NEG_EN(x)   (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_ENABLE_DPGA_OC_NEG_EN_SHIFT)) & AEC_AE_FAULTS_ENABLE_DPGA_OC_NEG_EN_MASK)

#define AEC_AE_FAULTS_ENABLE_DPGA_OC_POS_EN_MASK (0x8U)
#define AEC_AE_FAULTS_ENABLE_DPGA_OC_POS_EN_SHIFT (3U)
#define AEC_AE_FAULTS_ENABLE_DPGA_OC_POS_EN_WIDTH (1U)
#define AEC_AE_FAULTS_ENABLE_DPGA_OC_POS_EN(x)   (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_ENABLE_DPGA_OC_POS_EN_SHIFT)) & AEC_AE_FAULTS_ENABLE_DPGA_OC_POS_EN_MASK)

#define AEC_AE_FAULTS_ENABLE_PMC_VLS_EN_MASK     (0x10U)
#define AEC_AE_FAULTS_ENABLE_PMC_VLS_EN_SHIFT    (4U)
#define AEC_AE_FAULTS_ENABLE_PMC_VLS_EN_WIDTH    (1U)
#define AEC_AE_FAULTS_ENABLE_PMC_VLS_EN(x)       (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_ENABLE_PMC_VLS_EN_SHIFT)) & AEC_AE_FAULTS_ENABLE_PMC_VLS_EN_MASK)

#define AEC_AE_FAULTS_ENABLE_RAW_FAILED_EN_MASK  (0x80U)
#define AEC_AE_FAULTS_ENABLE_RAW_FAILED_EN_SHIFT (7U)
#define AEC_AE_FAULTS_ENABLE_RAW_FAILED_EN_WIDTH (1U)
#define AEC_AE_FAULTS_ENABLE_RAW_FAILED_EN(x)    (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_ENABLE_RAW_FAILED_EN_SHIFT)) & AEC_AE_FAULTS_ENABLE_RAW_FAILED_EN_MASK)

#define AEC_AE_FAULTS_ENABLE_CHKSUM_ERR_EN_MASK  (0x100U)
#define AEC_AE_FAULTS_ENABLE_CHKSUM_ERR_EN_SHIFT (8U)
#define AEC_AE_FAULTS_ENABLE_CHKSUM_ERR_EN_WIDTH (1U)
#define AEC_AE_FAULTS_ENABLE_CHKSUM_ERR_EN(x)    (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_ENABLE_CHKSUM_ERR_EN_SHIFT)) & AEC_AE_FAULTS_ENABLE_CHKSUM_ERR_EN_MASK)

#define AEC_AE_FAULTS_ENABLE_OBSCHK_ERR_EN_MASK  (0x200U)
#define AEC_AE_FAULTS_ENABLE_OBSCHK_ERR_EN_SHIFT (9U)
#define AEC_AE_FAULTS_ENABLE_OBSCHK_ERR_EN_WIDTH (1U)
#define AEC_AE_FAULTS_ENABLE_OBSCHK_ERR_EN(x)    (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_ENABLE_OBSCHK_ERR_EN_SHIFT)) & AEC_AE_FAULTS_ENABLE_OBSCHK_ERR_EN_MASK)

#define AEC_AE_FAULTS_ENABLE_XFER_ERR_EN_MASK    (0x400U)
#define AEC_AE_FAULTS_ENABLE_XFER_ERR_EN_SHIFT   (10U)
#define AEC_AE_FAULTS_ENABLE_XFER_ERR_EN_WIDTH   (1U)
#define AEC_AE_FAULTS_ENABLE_XFER_ERR_EN(x)      (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_ENABLE_XFER_ERR_EN_SHIFT)) & AEC_AE_FAULTS_ENABLE_XFER_ERR_EN_MASK)

#define AEC_AE_FAULTS_ENABLE_EVENT_EXPIRED_EN_MASK (0x800U)
#define AEC_AE_FAULTS_ENABLE_EVENT_EXPIRED_EN_SHIFT (11U)
#define AEC_AE_FAULTS_ENABLE_EVENT_EXPIRED_EN_WIDTH (1U)
#define AEC_AE_FAULTS_ENABLE_EVENT_EXPIRED_EN(x) (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_ENABLE_EVENT_EXPIRED_EN_SHIFT)) & AEC_AE_FAULTS_ENABLE_EVENT_EXPIRED_EN_MASK)

#define AEC_AE_FAULTS_ENABLE_MCU_SUPPLY_EN_MASK  (0x1000U)
#define AEC_AE_FAULTS_ENABLE_MCU_SUPPLY_EN_SHIFT (12U)
#define AEC_AE_FAULTS_ENABLE_MCU_SUPPLY_EN_WIDTH (1U)
#define AEC_AE_FAULTS_ENABLE_MCU_SUPPLY_EN(x)    (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_ENABLE_MCU_SUPPLY_EN_SHIFT)) & AEC_AE_FAULTS_ENABLE_MCU_SUPPLY_EN_MASK)

#define AEC_AE_FAULTS_ENABLE_HVD_AE_INTERN_EN_MASK (0x2000U)
#define AEC_AE_FAULTS_ENABLE_HVD_AE_INTERN_EN_SHIFT (13U)
#define AEC_AE_FAULTS_ENABLE_HVD_AE_INTERN_EN_WIDTH (1U)
#define AEC_AE_FAULTS_ENABLE_HVD_AE_INTERN_EN(x) (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_ENABLE_HVD_AE_INTERN_EN_SHIFT)) & AEC_AE_FAULTS_ENABLE_HVD_AE_INTERN_EN_MASK)

#define AEC_AE_FAULTS_ENABLE_ILL_TEST_EN_MASK    (0x4000U)
#define AEC_AE_FAULTS_ENABLE_ILL_TEST_EN_SHIFT   (14U)
#define AEC_AE_FAULTS_ENABLE_ILL_TEST_EN_WIDTH   (1U)
#define AEC_AE_FAULTS_ENABLE_ILL_TEST_EN(x)      (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_ENABLE_ILL_TEST_EN_SHIFT)) & AEC_AE_FAULTS_ENABLE_ILL_TEST_EN_MASK)

#define AEC_AE_FAULTS_ENABLE_ALIVE_WDG_EN_MASK   (0x8000U)
#define AEC_AE_FAULTS_ENABLE_ALIVE_WDG_EN_SHIFT  (15U)
#define AEC_AE_FAULTS_ENABLE_ALIVE_WDG_EN_WIDTH  (1U)
#define AEC_AE_FAULTS_ENABLE_ALIVE_WDG_EN(x)     (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULTS_ENABLE_ALIVE_WDG_EN_SHIFT)) & AEC_AE_FAULTS_ENABLE_ALIVE_WDG_EN_MASK)
/*! @} */

/*! @name NOTIFS_MONITOR - Monitoring of Notifications */
/*! @{ */

#define AEC_AE_NOTIFS_MONITOR_ALIVE_WD_CFG_PAR_VAL_MASK (0x1U)
#define AEC_AE_NOTIFS_MONITOR_ALIVE_WD_CFG_PAR_VAL_SHIFT (0U)
#define AEC_AE_NOTIFS_MONITOR_ALIVE_WD_CFG_PAR_VAL_WIDTH (1U)
#define AEC_AE_NOTIFS_MONITOR_ALIVE_WD_CFG_PAR_VAL(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_NOTIFS_MONITOR_ALIVE_WD_CFG_PAR_VAL_SHIFT)) & AEC_AE_NOTIFS_MONITOR_ALIVE_WD_CFG_PAR_VAL_MASK)

#define AEC_AE_NOTIFS_MONITOR_ALIVE_WD_CFG_PAR_ERR_MASK (0x2U)
#define AEC_AE_NOTIFS_MONITOR_ALIVE_WD_CFG_PAR_ERR_SHIFT (1U)
#define AEC_AE_NOTIFS_MONITOR_ALIVE_WD_CFG_PAR_ERR_WIDTH (1U)
#define AEC_AE_NOTIFS_MONITOR_ALIVE_WD_CFG_PAR_ERR(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_NOTIFS_MONITOR_ALIVE_WD_CFG_PAR_ERR_SHIFT)) & AEC_AE_NOTIFS_MONITOR_ALIVE_WD_CFG_PAR_ERR_MASK)

#define AEC_AE_NOTIFS_MONITOR_FAULT_WD_CFG_PAR_VAL_MASK (0x4U)
#define AEC_AE_NOTIFS_MONITOR_FAULT_WD_CFG_PAR_VAL_SHIFT (2U)
#define AEC_AE_NOTIFS_MONITOR_FAULT_WD_CFG_PAR_VAL_WIDTH (1U)
#define AEC_AE_NOTIFS_MONITOR_FAULT_WD_CFG_PAR_VAL(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_NOTIFS_MONITOR_FAULT_WD_CFG_PAR_VAL_SHIFT)) & AEC_AE_NOTIFS_MONITOR_FAULT_WD_CFG_PAR_VAL_MASK)

#define AEC_AE_NOTIFS_MONITOR_FAULT_WD_CFG_PAR_ERR_MASK (0x8U)
#define AEC_AE_NOTIFS_MONITOR_FAULT_WD_CFG_PAR_ERR_SHIFT (3U)
#define AEC_AE_NOTIFS_MONITOR_FAULT_WD_CFG_PAR_ERR_WIDTH (1U)
#define AEC_AE_NOTIFS_MONITOR_FAULT_WD_CFG_PAR_ERR(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_NOTIFS_MONITOR_FAULT_WD_CFG_PAR_ERR_SHIFT)) & AEC_AE_NOTIFS_MONITOR_FAULT_WD_CFG_PAR_ERR_MASK)

#define AEC_AE_NOTIFS_MONITOR_EVENTS_ENA_PAR_VAL_MASK (0x10U)
#define AEC_AE_NOTIFS_MONITOR_EVENTS_ENA_PAR_VAL_SHIFT (4U)
#define AEC_AE_NOTIFS_MONITOR_EVENTS_ENA_PAR_VAL_WIDTH (1U)
#define AEC_AE_NOTIFS_MONITOR_EVENTS_ENA_PAR_VAL(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_NOTIFS_MONITOR_EVENTS_ENA_PAR_VAL_SHIFT)) & AEC_AE_NOTIFS_MONITOR_EVENTS_ENA_PAR_VAL_MASK)

#define AEC_AE_NOTIFS_MONITOR_EVENTS_ENA_PAR_ERR_MASK (0x20U)
#define AEC_AE_NOTIFS_MONITOR_EVENTS_ENA_PAR_ERR_SHIFT (5U)
#define AEC_AE_NOTIFS_MONITOR_EVENTS_ENA_PAR_ERR_WIDTH (1U)
#define AEC_AE_NOTIFS_MONITOR_EVENTS_ENA_PAR_ERR(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_NOTIFS_MONITOR_EVENTS_ENA_PAR_ERR_SHIFT)) & AEC_AE_NOTIFS_MONITOR_EVENTS_ENA_PAR_ERR_MASK)

#define AEC_AE_NOTIFS_MONITOR_FAULTS_ENA_PAR_VAL_MASK (0x40U)
#define AEC_AE_NOTIFS_MONITOR_FAULTS_ENA_PAR_VAL_SHIFT (6U)
#define AEC_AE_NOTIFS_MONITOR_FAULTS_ENA_PAR_VAL_WIDTH (1U)
#define AEC_AE_NOTIFS_MONITOR_FAULTS_ENA_PAR_VAL(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_NOTIFS_MONITOR_FAULTS_ENA_PAR_VAL_SHIFT)) & AEC_AE_NOTIFS_MONITOR_FAULTS_ENA_PAR_VAL_MASK)

#define AEC_AE_NOTIFS_MONITOR_FAULTS_ENA_PAR_ERR_MASK (0x80U)
#define AEC_AE_NOTIFS_MONITOR_FAULTS_ENA_PAR_ERR_SHIFT (7U)
#define AEC_AE_NOTIFS_MONITOR_FAULTS_ENA_PAR_ERR_WIDTH (1U)
#define AEC_AE_NOTIFS_MONITOR_FAULTS_ENA_PAR_ERR(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_NOTIFS_MONITOR_FAULTS_ENA_PAR_ERR_SHIFT)) & AEC_AE_NOTIFS_MONITOR_FAULTS_ENA_PAR_ERR_MASK)

#define AEC_AE_NOTIFS_MONITOR_RSTG_CFG_PAR_VAL_MASK (0x100U)
#define AEC_AE_NOTIFS_MONITOR_RSTG_CFG_PAR_VAL_SHIFT (8U)
#define AEC_AE_NOTIFS_MONITOR_RSTG_CFG_PAR_VAL_WIDTH (1U)
#define AEC_AE_NOTIFS_MONITOR_RSTG_CFG_PAR_VAL(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_NOTIFS_MONITOR_RSTG_CFG_PAR_VAL_SHIFT)) & AEC_AE_NOTIFS_MONITOR_RSTG_CFG_PAR_VAL_MASK)

#define AEC_AE_NOTIFS_MONITOR_RSTG_CFG_PAR_ERR_MASK (0x200U)
#define AEC_AE_NOTIFS_MONITOR_RSTG_CFG_PAR_ERR_SHIFT (9U)
#define AEC_AE_NOTIFS_MONITOR_RSTG_CFG_PAR_ERR_WIDTH (1U)
#define AEC_AE_NOTIFS_MONITOR_RSTG_CFG_PAR_ERR(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_NOTIFS_MONITOR_RSTG_CFG_PAR_ERR_SHIFT)) & AEC_AE_NOTIFS_MONITOR_RSTG_CFG_PAR_ERR_MASK)

#define AEC_AE_NOTIFS_MONITOR_OTP_MIRROR_PAR_VAL_MASK (0x400U)
#define AEC_AE_NOTIFS_MONITOR_OTP_MIRROR_PAR_VAL_SHIFT (10U)
#define AEC_AE_NOTIFS_MONITOR_OTP_MIRROR_PAR_VAL_WIDTH (1U)
#define AEC_AE_NOTIFS_MONITOR_OTP_MIRROR_PAR_VAL(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_NOTIFS_MONITOR_OTP_MIRROR_PAR_VAL_SHIFT)) & AEC_AE_NOTIFS_MONITOR_OTP_MIRROR_PAR_VAL_MASK)

#define AEC_AE_NOTIFS_MONITOR_OTP_MIRROR_PAR_ERR_MASK (0x800U)
#define AEC_AE_NOTIFS_MONITOR_OTP_MIRROR_PAR_ERR_SHIFT (11U)
#define AEC_AE_NOTIFS_MONITOR_OTP_MIRROR_PAR_ERR_WIDTH (1U)
#define AEC_AE_NOTIFS_MONITOR_OTP_MIRROR_PAR_ERR(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_NOTIFS_MONITOR_OTP_MIRROR_PAR_ERR_SHIFT)) & AEC_AE_NOTIFS_MONITOR_OTP_MIRROR_PAR_ERR_MASK)

#define AEC_AE_NOTIFS_MONITOR_DPGA_PAR_ERR_MASK  (0x10000U)
#define AEC_AE_NOTIFS_MONITOR_DPGA_PAR_ERR_SHIFT (16U)
#define AEC_AE_NOTIFS_MONITOR_DPGA_PAR_ERR_WIDTH (1U)
#define AEC_AE_NOTIFS_MONITOR_DPGA_PAR_ERR(x)    (((uint32_t)(((uint32_t)(x)) << AEC_AE_NOTIFS_MONITOR_DPGA_PAR_ERR_SHIFT)) & AEC_AE_NOTIFS_MONITOR_DPGA_PAR_ERR_MASK)
/*! @} */

/*! @name IRQ_SET - Set Status Bits */
/*! @{ */

#define AEC_AE_IRQ_SET_EVT02_SET_MASK            (0x4U)
#define AEC_AE_IRQ_SET_EVT02_SET_SHIFT           (2U)
#define AEC_AE_IRQ_SET_EVT02_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_EVT02_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_EVT02_SET_SHIFT)) & AEC_AE_IRQ_SET_EVT02_SET_MASK)

#define AEC_AE_IRQ_SET_EVT03_SET_MASK            (0x8U)
#define AEC_AE_IRQ_SET_EVT03_SET_SHIFT           (3U)
#define AEC_AE_IRQ_SET_EVT03_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_EVT03_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_EVT03_SET_SHIFT)) & AEC_AE_IRQ_SET_EVT03_SET_MASK)

#define AEC_AE_IRQ_SET_EVT04_SET_MASK            (0x10U)
#define AEC_AE_IRQ_SET_EVT04_SET_SHIFT           (4U)
#define AEC_AE_IRQ_SET_EVT04_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_EVT04_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_EVT04_SET_SHIFT)) & AEC_AE_IRQ_SET_EVT04_SET_MASK)

#define AEC_AE_IRQ_SET_EVT05_SET_MASK            (0x20U)
#define AEC_AE_IRQ_SET_EVT05_SET_SHIFT           (5U)
#define AEC_AE_IRQ_SET_EVT05_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_EVT05_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_EVT05_SET_SHIFT)) & AEC_AE_IRQ_SET_EVT05_SET_MASK)

#define AEC_AE_IRQ_SET_EVT06_SET_MASK            (0x40U)
#define AEC_AE_IRQ_SET_EVT06_SET_SHIFT           (6U)
#define AEC_AE_IRQ_SET_EVT06_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_EVT06_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_EVT06_SET_SHIFT)) & AEC_AE_IRQ_SET_EVT06_SET_MASK)

#define AEC_AE_IRQ_SET_EVT07_SET_MASK            (0x80U)
#define AEC_AE_IRQ_SET_EVT07_SET_SHIFT           (7U)
#define AEC_AE_IRQ_SET_EVT07_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_EVT07_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_EVT07_SET_SHIFT)) & AEC_AE_IRQ_SET_EVT07_SET_MASK)

#define AEC_AE_IRQ_SET_EVT08_SET_MASK            (0x100U)
#define AEC_AE_IRQ_SET_EVT08_SET_SHIFT           (8U)
#define AEC_AE_IRQ_SET_EVT08_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_EVT08_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_EVT08_SET_SHIFT)) & AEC_AE_IRQ_SET_EVT08_SET_MASK)

#define AEC_AE_IRQ_SET_EVT09_SET_MASK            (0x200U)
#define AEC_AE_IRQ_SET_EVT09_SET_SHIFT           (9U)
#define AEC_AE_IRQ_SET_EVT09_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_EVT09_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_EVT09_SET_SHIFT)) & AEC_AE_IRQ_SET_EVT09_SET_MASK)

#define AEC_AE_IRQ_SET_EVT12_SET_MASK            (0x1000U)
#define AEC_AE_IRQ_SET_EVT12_SET_SHIFT           (12U)
#define AEC_AE_IRQ_SET_EVT12_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_EVT12_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_EVT12_SET_SHIFT)) & AEC_AE_IRQ_SET_EVT12_SET_MASK)

#define AEC_AE_IRQ_SET_EVT14_SET_MASK            (0x4000U)
#define AEC_AE_IRQ_SET_EVT14_SET_SHIFT           (14U)
#define AEC_AE_IRQ_SET_EVT14_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_EVT14_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_EVT14_SET_SHIFT)) & AEC_AE_IRQ_SET_EVT14_SET_MASK)

#define AEC_AE_IRQ_SET_EVT15_SET_MASK            (0x8000U)
#define AEC_AE_IRQ_SET_EVT15_SET_SHIFT           (15U)
#define AEC_AE_IRQ_SET_EVT15_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_EVT15_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_EVT15_SET_SHIFT)) & AEC_AE_IRQ_SET_EVT15_SET_MASK)

#define AEC_AE_IRQ_SET_FLT00_SET_MASK            (0x10000U)
#define AEC_AE_IRQ_SET_FLT00_SET_SHIFT           (16U)
#define AEC_AE_IRQ_SET_FLT00_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_FLT00_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_FLT00_SET_SHIFT)) & AEC_AE_IRQ_SET_FLT00_SET_MASK)

#define AEC_AE_IRQ_SET_FLT01_SET_MASK            (0x20000U)
#define AEC_AE_IRQ_SET_FLT01_SET_SHIFT           (17U)
#define AEC_AE_IRQ_SET_FLT01_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_FLT01_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_FLT01_SET_SHIFT)) & AEC_AE_IRQ_SET_FLT01_SET_MASK)

#define AEC_AE_IRQ_SET_FLT02_SET_MASK            (0x40000U)
#define AEC_AE_IRQ_SET_FLT02_SET_SHIFT           (18U)
#define AEC_AE_IRQ_SET_FLT02_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_FLT02_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_FLT02_SET_SHIFT)) & AEC_AE_IRQ_SET_FLT02_SET_MASK)

#define AEC_AE_IRQ_SET_FLT03_SET_MASK            (0x80000U)
#define AEC_AE_IRQ_SET_FLT03_SET_SHIFT           (19U)
#define AEC_AE_IRQ_SET_FLT03_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_FLT03_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_FLT03_SET_SHIFT)) & AEC_AE_IRQ_SET_FLT03_SET_MASK)

#define AEC_AE_IRQ_SET_FLT04_SET_MASK            (0x100000U)
#define AEC_AE_IRQ_SET_FLT04_SET_SHIFT           (20U)
#define AEC_AE_IRQ_SET_FLT04_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_FLT04_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_FLT04_SET_SHIFT)) & AEC_AE_IRQ_SET_FLT04_SET_MASK)

#define AEC_AE_IRQ_SET_FLT07_SET_MASK            (0x800000U)
#define AEC_AE_IRQ_SET_FLT07_SET_SHIFT           (23U)
#define AEC_AE_IRQ_SET_FLT07_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_FLT07_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_FLT07_SET_SHIFT)) & AEC_AE_IRQ_SET_FLT07_SET_MASK)

#define AEC_AE_IRQ_SET_FLT08_SET_MASK            (0x1000000U)
#define AEC_AE_IRQ_SET_FLT08_SET_SHIFT           (24U)
#define AEC_AE_IRQ_SET_FLT08_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_FLT08_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_FLT08_SET_SHIFT)) & AEC_AE_IRQ_SET_FLT08_SET_MASK)

#define AEC_AE_IRQ_SET_FLT09_SET_MASK            (0x2000000U)
#define AEC_AE_IRQ_SET_FLT09_SET_SHIFT           (25U)
#define AEC_AE_IRQ_SET_FLT09_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_FLT09_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_FLT09_SET_SHIFT)) & AEC_AE_IRQ_SET_FLT09_SET_MASK)

#define AEC_AE_IRQ_SET_FLT10_SET_MASK            (0x4000000U)
#define AEC_AE_IRQ_SET_FLT10_SET_SHIFT           (26U)
#define AEC_AE_IRQ_SET_FLT10_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_FLT10_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_FLT10_SET_SHIFT)) & AEC_AE_IRQ_SET_FLT10_SET_MASK)

#define AEC_AE_IRQ_SET_FLT11_SET_MASK            (0x8000000U)
#define AEC_AE_IRQ_SET_FLT11_SET_SHIFT           (27U)
#define AEC_AE_IRQ_SET_FLT11_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_FLT11_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_FLT11_SET_SHIFT)) & AEC_AE_IRQ_SET_FLT11_SET_MASK)

#define AEC_AE_IRQ_SET_FLT12_SET_MASK            (0x10000000U)
#define AEC_AE_IRQ_SET_FLT12_SET_SHIFT           (28U)
#define AEC_AE_IRQ_SET_FLT12_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_FLT12_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_FLT12_SET_SHIFT)) & AEC_AE_IRQ_SET_FLT12_SET_MASK)

#define AEC_AE_IRQ_SET_FLT13_SET_MASK            (0x20000000U)
#define AEC_AE_IRQ_SET_FLT13_SET_SHIFT           (29U)
#define AEC_AE_IRQ_SET_FLT13_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_FLT13_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_FLT13_SET_SHIFT)) & AEC_AE_IRQ_SET_FLT13_SET_MASK)

#define AEC_AE_IRQ_SET_FLT14_SET_MASK            (0x40000000U)
#define AEC_AE_IRQ_SET_FLT14_SET_SHIFT           (30U)
#define AEC_AE_IRQ_SET_FLT14_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_FLT14_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_FLT14_SET_SHIFT)) & AEC_AE_IRQ_SET_FLT14_SET_MASK)

#define AEC_AE_IRQ_SET_FLT15_SET_MASK            (0x80000000U)
#define AEC_AE_IRQ_SET_FLT15_SET_SHIFT           (31U)
#define AEC_AE_IRQ_SET_FLT15_SET_WIDTH           (1U)
#define AEC_AE_IRQ_SET_FLT15_SET(x)              (((uint32_t)(((uint32_t)(x)) << AEC_AE_IRQ_SET_FLT15_SET_SHIFT)) & AEC_AE_IRQ_SET_FLT15_SET_MASK)
/*! @} */

/*! @name SAFETY_ENABLE - Safety Enable */
/*! @{ */

#define AEC_AE_SAFETY_ENABLE_EVENT00_EN_MASK     (0x1U)
#define AEC_AE_SAFETY_ENABLE_EVENT00_EN_SHIFT    (0U)
#define AEC_AE_SAFETY_ENABLE_EVENT00_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_EVENT00_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_EVENT00_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_EVENT00_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_EVENT01_EN_MASK     (0x2U)
#define AEC_AE_SAFETY_ENABLE_EVENT01_EN_SHIFT    (1U)
#define AEC_AE_SAFETY_ENABLE_EVENT01_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_EVENT01_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_EVENT01_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_EVENT01_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_EVENT02_EN_MASK     (0x4U)
#define AEC_AE_SAFETY_ENABLE_EVENT02_EN_SHIFT    (2U)
#define AEC_AE_SAFETY_ENABLE_EVENT02_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_EVENT02_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_EVENT02_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_EVENT02_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_EVENT03_EN_MASK     (0x8U)
#define AEC_AE_SAFETY_ENABLE_EVENT03_EN_SHIFT    (3U)
#define AEC_AE_SAFETY_ENABLE_EVENT03_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_EVENT03_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_EVENT03_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_EVENT03_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_EVENT04_EN_MASK     (0x10U)
#define AEC_AE_SAFETY_ENABLE_EVENT04_EN_SHIFT    (4U)
#define AEC_AE_SAFETY_ENABLE_EVENT04_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_EVENT04_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_EVENT04_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_EVENT04_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_EVENT05_EN_MASK     (0x20U)
#define AEC_AE_SAFETY_ENABLE_EVENT05_EN_SHIFT    (5U)
#define AEC_AE_SAFETY_ENABLE_EVENT05_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_EVENT05_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_EVENT05_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_EVENT05_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_EVENT06_EN_MASK     (0x40U)
#define AEC_AE_SAFETY_ENABLE_EVENT06_EN_SHIFT    (6U)
#define AEC_AE_SAFETY_ENABLE_EVENT06_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_EVENT06_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_EVENT06_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_EVENT06_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_EVENT07_EN_MASK     (0x80U)
#define AEC_AE_SAFETY_ENABLE_EVENT07_EN_SHIFT    (7U)
#define AEC_AE_SAFETY_ENABLE_EVENT07_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_EVENT07_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_EVENT07_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_EVENT07_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_EVENT08_EN_MASK     (0x100U)
#define AEC_AE_SAFETY_ENABLE_EVENT08_EN_SHIFT    (8U)
#define AEC_AE_SAFETY_ENABLE_EVENT08_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_EVENT08_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_EVENT08_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_EVENT08_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_EVENT09_EN_MASK     (0x200U)
#define AEC_AE_SAFETY_ENABLE_EVENT09_EN_SHIFT    (9U)
#define AEC_AE_SAFETY_ENABLE_EVENT09_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_EVENT09_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_EVENT09_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_EVENT09_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_EVENT10_EN_MASK     (0x400U)
#define AEC_AE_SAFETY_ENABLE_EVENT10_EN_SHIFT    (10U)
#define AEC_AE_SAFETY_ENABLE_EVENT10_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_EVENT10_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_EVENT10_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_EVENT10_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_EVENT11_EN_MASK     (0x800U)
#define AEC_AE_SAFETY_ENABLE_EVENT11_EN_SHIFT    (11U)
#define AEC_AE_SAFETY_ENABLE_EVENT11_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_EVENT11_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_EVENT11_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_EVENT11_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_EVENT12_EN_MASK     (0x1000U)
#define AEC_AE_SAFETY_ENABLE_EVENT12_EN_SHIFT    (12U)
#define AEC_AE_SAFETY_ENABLE_EVENT12_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_EVENT12_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_EVENT12_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_EVENT12_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_EVENT13_EN_MASK     (0x2000U)
#define AEC_AE_SAFETY_ENABLE_EVENT13_EN_SHIFT    (13U)
#define AEC_AE_SAFETY_ENABLE_EVENT13_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_EVENT13_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_EVENT13_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_EVENT13_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_EVENT14_EN_MASK     (0x4000U)
#define AEC_AE_SAFETY_ENABLE_EVENT14_EN_SHIFT    (14U)
#define AEC_AE_SAFETY_ENABLE_EVENT14_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_EVENT14_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_EVENT14_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_EVENT14_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_EVENT15_EN_MASK     (0x8000U)
#define AEC_AE_SAFETY_ENABLE_EVENT15_EN_SHIFT    (15U)
#define AEC_AE_SAFETY_ENABLE_EVENT15_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_EVENT15_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_EVENT15_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_EVENT15_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_FAULT00_EN_MASK     (0x10000U)
#define AEC_AE_SAFETY_ENABLE_FAULT00_EN_SHIFT    (16U)
#define AEC_AE_SAFETY_ENABLE_FAULT00_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_FAULT00_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_FAULT00_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_FAULT00_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_FAULT01_EN_MASK     (0x20000U)
#define AEC_AE_SAFETY_ENABLE_FAULT01_EN_SHIFT    (17U)
#define AEC_AE_SAFETY_ENABLE_FAULT01_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_FAULT01_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_FAULT01_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_FAULT01_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_FAULT02_EN_MASK     (0x40000U)
#define AEC_AE_SAFETY_ENABLE_FAULT02_EN_SHIFT    (18U)
#define AEC_AE_SAFETY_ENABLE_FAULT02_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_FAULT02_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_FAULT02_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_FAULT02_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_FAULT03_EN_MASK     (0x80000U)
#define AEC_AE_SAFETY_ENABLE_FAULT03_EN_SHIFT    (19U)
#define AEC_AE_SAFETY_ENABLE_FAULT03_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_FAULT03_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_FAULT03_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_FAULT03_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_FAULT04_EN_MASK     (0x100000U)
#define AEC_AE_SAFETY_ENABLE_FAULT04_EN_SHIFT    (20U)
#define AEC_AE_SAFETY_ENABLE_FAULT04_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_FAULT04_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_FAULT04_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_FAULT04_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_FAULT05_EN_MASK     (0x200000U)
#define AEC_AE_SAFETY_ENABLE_FAULT05_EN_SHIFT    (21U)
#define AEC_AE_SAFETY_ENABLE_FAULT05_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_FAULT05_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_FAULT05_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_FAULT05_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_FAULT06_EN_MASK     (0x400000U)
#define AEC_AE_SAFETY_ENABLE_FAULT06_EN_SHIFT    (22U)
#define AEC_AE_SAFETY_ENABLE_FAULT06_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_FAULT06_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_FAULT06_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_FAULT06_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_FAULT07_EN_MASK     (0x800000U)
#define AEC_AE_SAFETY_ENABLE_FAULT07_EN_SHIFT    (23U)
#define AEC_AE_SAFETY_ENABLE_FAULT07_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_FAULT07_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_FAULT07_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_FAULT07_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_FAULT08_EN_MASK     (0x1000000U)
#define AEC_AE_SAFETY_ENABLE_FAULT08_EN_SHIFT    (24U)
#define AEC_AE_SAFETY_ENABLE_FAULT08_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_FAULT08_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_FAULT08_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_FAULT08_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_FAULT09_EN_MASK     (0x2000000U)
#define AEC_AE_SAFETY_ENABLE_FAULT09_EN_SHIFT    (25U)
#define AEC_AE_SAFETY_ENABLE_FAULT09_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_FAULT09_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_FAULT09_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_FAULT09_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_FAULT10_EN_MASK     (0x4000000U)
#define AEC_AE_SAFETY_ENABLE_FAULT10_EN_SHIFT    (26U)
#define AEC_AE_SAFETY_ENABLE_FAULT10_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_FAULT10_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_FAULT10_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_FAULT10_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_FAULT11_EN_MASK     (0x8000000U)
#define AEC_AE_SAFETY_ENABLE_FAULT11_EN_SHIFT    (27U)
#define AEC_AE_SAFETY_ENABLE_FAULT11_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_FAULT11_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_FAULT11_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_FAULT11_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_FAULT12_EN_MASK     (0x10000000U)
#define AEC_AE_SAFETY_ENABLE_FAULT12_EN_SHIFT    (28U)
#define AEC_AE_SAFETY_ENABLE_FAULT12_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_FAULT12_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_FAULT12_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_FAULT12_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_FAULT13_EN_MASK     (0x20000000U)
#define AEC_AE_SAFETY_ENABLE_FAULT13_EN_SHIFT    (29U)
#define AEC_AE_SAFETY_ENABLE_FAULT13_EN_WIDTH    (1U)
#define AEC_AE_SAFETY_ENABLE_FAULT13_EN(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_FAULT13_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_FAULT13_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_FAULT_ILL_TEST_EN_MASK (0x40000000U)
#define AEC_AE_SAFETY_ENABLE_FAULT_ILL_TEST_EN_SHIFT (30U)
#define AEC_AE_SAFETY_ENABLE_FAULT_ILL_TEST_EN_WIDTH (1U)
#define AEC_AE_SAFETY_ENABLE_FAULT_ILL_TEST_EN(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_FAULT_ILL_TEST_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_FAULT_ILL_TEST_EN_MASK)

#define AEC_AE_SAFETY_ENABLE_FAULT_ALIVE_WDG_EN_MASK (0x80000000U)
#define AEC_AE_SAFETY_ENABLE_FAULT_ALIVE_WDG_EN_SHIFT (31U)
#define AEC_AE_SAFETY_ENABLE_FAULT_ALIVE_WDG_EN_WIDTH (1U)
#define AEC_AE_SAFETY_ENABLE_FAULT_ALIVE_WDG_EN(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_SAFETY_ENABLE_FAULT_ALIVE_WDG_EN_SHIFT)) & AEC_AE_SAFETY_ENABLE_FAULT_ALIVE_WDG_EN_MASK)
/*! @} */

/*! @name SYSCLK_CHECK - System Clock Check */
/*! @{ */

#define AEC_AE_SYSCLK_CHECK_VALID_THR_L_MASK     (0x7FU)
#define AEC_AE_SYSCLK_CHECK_VALID_THR_L_SHIFT    (0U)
#define AEC_AE_SYSCLK_CHECK_VALID_THR_L_WIDTH    (7U)
#define AEC_AE_SYSCLK_CHECK_VALID_THR_L(x)       (((uint16_t)(((uint16_t)(x)) << AEC_AE_SYSCLK_CHECK_VALID_THR_L_SHIFT)) & AEC_AE_SYSCLK_CHECK_VALID_THR_L_MASK)

#define AEC_AE_SYSCLK_CHECK_VALID_THR_U_MASK     (0xFF80U)
#define AEC_AE_SYSCLK_CHECK_VALID_THR_U_SHIFT    (7U)
#define AEC_AE_SYSCLK_CHECK_VALID_THR_U_WIDTH    (9U)
#define AEC_AE_SYSCLK_CHECK_VALID_THR_U(x)       (((uint16_t)(((uint16_t)(x)) << AEC_AE_SYSCLK_CHECK_VALID_THR_U_SHIFT)) & AEC_AE_SYSCLK_CHECK_VALID_THR_U_MASK)
/*! @} */

/*! @name ALIVE_WD_CFG - Alive Watchdog Configuration */
/*! @{ */

#define AEC_AE_ALIVE_WD_CFG_WDW_PERIOD_MASK      (0xFU)
#define AEC_AE_ALIVE_WD_CFG_WDW_PERIOD_SHIFT     (0U)
#define AEC_AE_ALIVE_WD_CFG_WDW_PERIOD_WIDTH     (4U)
#define AEC_AE_ALIVE_WD_CFG_WDW_PERIOD(x)        (((uint16_t)(((uint16_t)(x)) << AEC_AE_ALIVE_WD_CFG_WDW_PERIOD_SHIFT)) & AEC_AE_ALIVE_WD_CFG_WDW_PERIOD_MASK)

#define AEC_AE_ALIVE_WD_CFG_WDW_DC_MASK          (0xC0U)
#define AEC_AE_ALIVE_WD_CFG_WDW_DC_SHIFT         (6U)
#define AEC_AE_ALIVE_WD_CFG_WDW_DC_WIDTH         (2U)
#define AEC_AE_ALIVE_WD_CFG_WDW_DC(x)            (((uint16_t)(((uint16_t)(x)) << AEC_AE_ALIVE_WD_CFG_WDW_DC_SHIFT)) & AEC_AE_ALIVE_WD_CFG_WDW_DC_MASK)

#define AEC_AE_ALIVE_WD_CFG_WDW_BADRESP_MASK     (0x300U)
#define AEC_AE_ALIVE_WD_CFG_WDW_BADRESP_SHIFT    (8U)
#define AEC_AE_ALIVE_WD_CFG_WDW_BADRESP_WIDTH    (2U)
#define AEC_AE_ALIVE_WD_CFG_WDW_BADRESP(x)       (((uint16_t)(((uint16_t)(x)) << AEC_AE_ALIVE_WD_CFG_WDW_BADRESP_SHIFT)) & AEC_AE_ALIVE_WD_CFG_WDW_BADRESP_MASK)

#define AEC_AE_ALIVE_WD_CFG_WDW_MODE_MASK        (0x4000U)
#define AEC_AE_ALIVE_WD_CFG_WDW_MODE_SHIFT       (14U)
#define AEC_AE_ALIVE_WD_CFG_WDW_MODE_WIDTH       (1U)
#define AEC_AE_ALIVE_WD_CFG_WDW_MODE(x)          (((uint16_t)(((uint16_t)(x)) << AEC_AE_ALIVE_WD_CFG_WDW_MODE_SHIFT)) & AEC_AE_ALIVE_WD_CFG_WDW_MODE_MASK)

#define AEC_AE_ALIVE_WD_CFG_WDW_FAULTREC_MASK    (0x8000U)
#define AEC_AE_ALIVE_WD_CFG_WDW_FAULTREC_SHIFT   (15U)
#define AEC_AE_ALIVE_WD_CFG_WDW_FAULTREC_WIDTH   (1U)
#define AEC_AE_ALIVE_WD_CFG_WDW_FAULTREC(x)      (((uint16_t)(((uint16_t)(x)) << AEC_AE_ALIVE_WD_CFG_WDW_FAULTREC_SHIFT)) & AEC_AE_ALIVE_WD_CFG_WDW_FAULTREC_MASK)
/*! @} */

/*! @name ALIVE_WD_TOKEN - Alive Watchdog Reference Value */
/*! @{ */

#define AEC_AE_ALIVE_WD_TOKEN_WD_TOKEN_MASK      (0xFFFFU)
#define AEC_AE_ALIVE_WD_TOKEN_WD_TOKEN_SHIFT     (0U)
#define AEC_AE_ALIVE_WD_TOKEN_WD_TOKEN_WIDTH     (16U)
#define AEC_AE_ALIVE_WD_TOKEN_WD_TOKEN(x)        (((uint16_t)(((uint16_t)(x)) << AEC_AE_ALIVE_WD_TOKEN_WD_TOKEN_SHIFT)) & AEC_AE_ALIVE_WD_TOKEN_WD_TOKEN_MASK)
/*! @} */

/*! @name ALIVE_WD_ANSWER - Alive Watchdog Answer */
/*! @{ */

#define AEC_AE_ALIVE_WD_ANSWER_WD_ANSWER_MASK    (0xFFFFU)
#define AEC_AE_ALIVE_WD_ANSWER_WD_ANSWER_SHIFT   (0U)
#define AEC_AE_ALIVE_WD_ANSWER_WD_ANSWER_WIDTH   (16U)
#define AEC_AE_ALIVE_WD_ANSWER_WD_ANSWER(x)      (((uint16_t)(((uint16_t)(x)) << AEC_AE_ALIVE_WD_ANSWER_WD_ANSWER_SHIFT)) & AEC_AE_ALIVE_WD_ANSWER_WD_ANSWER_MASK)
/*! @} */

/*! @name FAULT_WD_CFG - Fault Watchdog Configuration */
/*! @{ */

#define AEC_AE_FAULT_WD_CFG_TIME_OUT_CFG_MASK    (0xFFFU)
#define AEC_AE_FAULT_WD_CFG_TIME_OUT_CFG_SHIFT   (0U)
#define AEC_AE_FAULT_WD_CFG_TIME_OUT_CFG_WIDTH   (12U)
#define AEC_AE_FAULT_WD_CFG_TIME_OUT_CFG(x)      (((uint16_t)(((uint16_t)(x)) << AEC_AE_FAULT_WD_CFG_TIME_OUT_CFG_SHIFT)) & AEC_AE_FAULT_WD_CFG_TIME_OUT_CFG_MASK)
/*! @} */

/*! @name CLKGEN_CFG - Clock Generator Configuration */
/*! @{ */

#define AEC_AE_CLKGEN_CFG_CLKGEN_CFG_MASK        (0xFFU)
#define AEC_AE_CLKGEN_CFG_CLKGEN_CFG_SHIFT       (0U)
#define AEC_AE_CLKGEN_CFG_CLKGEN_CFG_WIDTH       (8U)
#define AEC_AE_CLKGEN_CFG_CLKGEN_CFG(x)          (((uint32_t)(((uint32_t)(x)) << AEC_AE_CLKGEN_CFG_CLKGEN_CFG_SHIFT)) & AEC_AE_CLKGEN_CFG_CLKGEN_CFG_MASK)

#define AEC_AE_CLKGEN_CFG_CXPI_CLK_EN_MASK       (0x100U)
#define AEC_AE_CLKGEN_CFG_CXPI_CLK_EN_SHIFT      (8U)
#define AEC_AE_CLKGEN_CFG_CXPI_CLK_EN_WIDTH      (1U)
#define AEC_AE_CLKGEN_CFG_CXPI_CLK_EN(x)         (((uint32_t)(((uint32_t)(x)) << AEC_AE_CLKGEN_CFG_CXPI_CLK_EN_SHIFT)) & AEC_AE_CLKGEN_CFG_CXPI_CLK_EN_MASK)

#define AEC_AE_CLKGEN_CFG_RCOSC_MOD_ENA_MASK     (0x400U)
#define AEC_AE_CLKGEN_CFG_RCOSC_MOD_ENA_SHIFT    (10U)
#define AEC_AE_CLKGEN_CFG_RCOSC_MOD_ENA_WIDTH    (1U)
#define AEC_AE_CLKGEN_CFG_RCOSC_MOD_ENA(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_CLKGEN_CFG_RCOSC_MOD_ENA_SHIFT)) & AEC_AE_CLKGEN_CFG_RCOSC_MOD_ENA_MASK)

#define AEC_AE_CLKGEN_CFG_RCOSC_MOD_FRQ_MASK     (0x3800U)
#define AEC_AE_CLKGEN_CFG_RCOSC_MOD_FRQ_SHIFT    (11U)
#define AEC_AE_CLKGEN_CFG_RCOSC_MOD_FRQ_WIDTH    (3U)
#define AEC_AE_CLKGEN_CFG_RCOSC_MOD_FRQ(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_CLKGEN_CFG_RCOSC_MOD_FRQ_SHIFT)) & AEC_AE_CLKGEN_CFG_RCOSC_MOD_FRQ_MASK)

#define AEC_AE_CLKGEN_CFG_RCOSC_MOD_NBR_MASK     (0xC000U)
#define AEC_AE_CLKGEN_CFG_RCOSC_MOD_NBR_SHIFT    (14U)
#define AEC_AE_CLKGEN_CFG_RCOSC_MOD_NBR_WIDTH    (2U)
#define AEC_AE_CLKGEN_CFG_RCOSC_MOD_NBR(x)       (((uint32_t)(((uint32_t)(x)) << AEC_AE_CLKGEN_CFG_RCOSC_MOD_NBR_SHIFT)) & AEC_AE_CLKGEN_CFG_RCOSC_MOD_NBR_MASK)

#define AEC_AE_CLKGEN_CFG_SYSCLK_FREQ_VAL_MASK   (0x1FF0000U)
#define AEC_AE_CLKGEN_CFG_SYSCLK_FREQ_VAL_SHIFT  (16U)
#define AEC_AE_CLKGEN_CFG_SYSCLK_FREQ_VAL_WIDTH  (9U)
#define AEC_AE_CLKGEN_CFG_SYSCLK_FREQ_VAL(x)     (((uint32_t)(((uint32_t)(x)) << AEC_AE_CLKGEN_CFG_SYSCLK_FREQ_VAL_SHIFT)) & AEC_AE_CLKGEN_CFG_SYSCLK_FREQ_VAL_MASK)

#define AEC_AE_CLKGEN_CFG_SYSCLK_FREQ_CFG_MASK   (0x10000000U)
#define AEC_AE_CLKGEN_CFG_SYSCLK_FREQ_CFG_SHIFT  (28U)
#define AEC_AE_CLKGEN_CFG_SYSCLK_FREQ_CFG_WIDTH  (1U)
#define AEC_AE_CLKGEN_CFG_SYSCLK_FREQ_CFG(x)     (((uint32_t)(((uint32_t)(x)) << AEC_AE_CLKGEN_CFG_SYSCLK_FREQ_CFG_SHIFT)) & AEC_AE_CLKGEN_CFG_SYSCLK_FREQ_CFG_MASK)
/*! @} */

/*! @name RSTGEN_CFG - Reset Generator Configuration */
/*! @{ */

#define AEC_AE_RSTGEN_CFG_RSTGEN_CFG_MASK        (0x1FFU)
#define AEC_AE_RSTGEN_CFG_RSTGEN_CFG_SHIFT       (0U)
#define AEC_AE_RSTGEN_CFG_RSTGEN_CFG_WIDTH       (9U)
#define AEC_AE_RSTGEN_CFG_RSTGEN_CFG(x)          (((uint16_t)(((uint16_t)(x)) << AEC_AE_RSTGEN_CFG_RSTGEN_CFG_SHIFT)) & AEC_AE_RSTGEN_CFG_RSTGEN_CFG_MASK)

#define AEC_AE_RSTGEN_CFG_NOFLUSH_MASK           (0x8000U)
#define AEC_AE_RSTGEN_CFG_NOFLUSH_SHIFT          (15U)
#define AEC_AE_RSTGEN_CFG_NOFLUSH_WIDTH          (1U)
#define AEC_AE_RSTGEN_CFG_NOFLUSH(x)             (((uint16_t)(((uint16_t)(x)) << AEC_AE_RSTGEN_CFG_NOFLUSH_SHIFT)) & AEC_AE_RSTGEN_CFG_NOFLUSH_MASK)
/*! @} */

/*! @name IO_FUNCMUX_CFG - IO Funcmux Configuration */
/*! @{ */

#define AEC_AE_IO_FUNCMUX_CFG_DPGA_OUT_MASK      (0x1U)
#define AEC_AE_IO_FUNCMUX_CFG_DPGA_OUT_SHIFT     (0U)
#define AEC_AE_IO_FUNCMUX_CFG_DPGA_OUT_WIDTH     (1U)
#define AEC_AE_IO_FUNCMUX_CFG_DPGA_OUT(x)        (((uint32_t)(((uint32_t)(x)) << AEC_AE_IO_FUNCMUX_CFG_DPGA_OUT_SHIFT)) & AEC_AE_IO_FUNCMUX_CFG_DPGA_OUT_MASK)

#define AEC_AE_IO_FUNCMUX_CFG_AMPOUT_SEL_MASK    (0xEU)
#define AEC_AE_IO_FUNCMUX_CFG_AMPOUT_SEL_SHIFT   (1U)
#define AEC_AE_IO_FUNCMUX_CFG_AMPOUT_SEL_WIDTH   (3U)
#define AEC_AE_IO_FUNCMUX_CFG_AMPOUT_SEL(x)      (((uint32_t)(((uint32_t)(x)) << AEC_AE_IO_FUNCMUX_CFG_AMPOUT_SEL_SHIFT)) & AEC_AE_IO_FUNCMUX_CFG_AMPOUT_SEL_MASK)

#define AEC_AE_IO_FUNCMUX_CFG_VDDE_DRV_MASK      (0x100U)
#define AEC_AE_IO_FUNCMUX_CFG_VDDE_DRV_SHIFT     (8U)
#define AEC_AE_IO_FUNCMUX_CFG_VDDE_DRV_WIDTH     (1U)
#define AEC_AE_IO_FUNCMUX_CFG_VDDE_DRV(x)        (((uint32_t)(((uint32_t)(x)) << AEC_AE_IO_FUNCMUX_CFG_VDDE_DRV_SHIFT)) & AEC_AE_IO_FUNCMUX_CFG_VDDE_DRV_MASK)

#define AEC_AE_IO_FUNCMUX_CFG_VDDE_SEL_MASK      (0x200U)
#define AEC_AE_IO_FUNCMUX_CFG_VDDE_SEL_SHIFT     (9U)
#define AEC_AE_IO_FUNCMUX_CFG_VDDE_SEL_WIDTH     (1U)
#define AEC_AE_IO_FUNCMUX_CFG_VDDE_SEL(x)        (((uint32_t)(((uint32_t)(x)) << AEC_AE_IO_FUNCMUX_CFG_VDDE_SEL_SHIFT)) & AEC_AE_IO_FUNCMUX_CFG_VDDE_SEL_MASK)

#define AEC_AE_IO_FUNCMUX_CFG_PHY_SEL_MASK       (0xC00U)
#define AEC_AE_IO_FUNCMUX_CFG_PHY_SEL_SHIFT      (10U)
#define AEC_AE_IO_FUNCMUX_CFG_PHY_SEL_WIDTH      (2U)
#define AEC_AE_IO_FUNCMUX_CFG_PHY_SEL(x)         (((uint32_t)(((uint32_t)(x)) << AEC_AE_IO_FUNCMUX_CFG_PHY_SEL_SHIFT)) & AEC_AE_IO_FUNCMUX_CFG_PHY_SEL_MASK)

#define AEC_AE_IO_FUNCMUX_CFG_VDDE_OCD_EN_MASK   (0x1000U)
#define AEC_AE_IO_FUNCMUX_CFG_VDDE_OCD_EN_SHIFT  (12U)
#define AEC_AE_IO_FUNCMUX_CFG_VDDE_OCD_EN_WIDTH  (1U)
#define AEC_AE_IO_FUNCMUX_CFG_VDDE_OCD_EN(x)     (((uint32_t)(((uint32_t)(x)) << AEC_AE_IO_FUNCMUX_CFG_VDDE_OCD_EN_SHIFT)) & AEC_AE_IO_FUNCMUX_CFG_VDDE_OCD_EN_MASK)

#define AEC_AE_IO_FUNCMUX_CFG_D2D_EN_MASK        (0x10000U)
#define AEC_AE_IO_FUNCMUX_CFG_D2D_EN_SHIFT       (16U)
#define AEC_AE_IO_FUNCMUX_CFG_D2D_EN_WIDTH       (1U)
#define AEC_AE_IO_FUNCMUX_CFG_D2D_EN(x)          (((uint32_t)(((uint32_t)(x)) << AEC_AE_IO_FUNCMUX_CFG_D2D_EN_SHIFT)) & AEC_AE_IO_FUNCMUX_CFG_D2D_EN_MASK)

#define AEC_AE_IO_FUNCMUX_CFG_OUTSEL_MASK        (0x20000U)
#define AEC_AE_IO_FUNCMUX_CFG_OUTSEL_SHIFT       (17U)
#define AEC_AE_IO_FUNCMUX_CFG_OUTSEL_WIDTH       (1U)
#define AEC_AE_IO_FUNCMUX_CFG_OUTSEL(x)          (((uint32_t)(((uint32_t)(x)) << AEC_AE_IO_FUNCMUX_CFG_OUTSEL_SHIFT)) & AEC_AE_IO_FUNCMUX_CFG_OUTSEL_MASK)

#define AEC_AE_IO_FUNCMUX_CFG_CLKSEL_MASK        (0xC0000U)
#define AEC_AE_IO_FUNCMUX_CFG_CLKSEL_SHIFT       (18U)
#define AEC_AE_IO_FUNCMUX_CFG_CLKSEL_WIDTH       (2U)
#define AEC_AE_IO_FUNCMUX_CFG_CLKSEL(x)          (((uint32_t)(((uint32_t)(x)) << AEC_AE_IO_FUNCMUX_CFG_CLKSEL_SHIFT)) & AEC_AE_IO_FUNCMUX_CFG_CLKSEL_MASK)
/*! @} */

/*! @name LINPHY_CFG - LINPHY Configuration */
/*! @{ */

#define AEC_AE_LINPHY_CFG_MODE_MASK              (0x3U)
#define AEC_AE_LINPHY_CFG_MODE_SHIFT             (0U)
#define AEC_AE_LINPHY_CFG_MODE_WIDTH             (2U)
#define AEC_AE_LINPHY_CFG_MODE(x)                (((uint16_t)(((uint16_t)(x)) << AEC_AE_LINPHY_CFG_MODE_SHIFT)) & AEC_AE_LINPHY_CFG_MODE_MASK)

#define AEC_AE_LINPHY_CFG_ENAWUP_MASK            (0x4U)
#define AEC_AE_LINPHY_CFG_ENAWUP_SHIFT           (2U)
#define AEC_AE_LINPHY_CFG_ENAWUP_WIDTH           (1U)
#define AEC_AE_LINPHY_CFG_ENAWUP(x)              (((uint16_t)(((uint16_t)(x)) << AEC_AE_LINPHY_CFG_ENAWUP_SHIFT)) & AEC_AE_LINPHY_CFG_ENAWUP_MASK)

#define AEC_AE_LINPHY_CFG_ENATXTO_MASK           (0x8U)
#define AEC_AE_LINPHY_CFG_ENATXTO_SHIFT          (3U)
#define AEC_AE_LINPHY_CFG_ENATXTO_WIDTH          (1U)
#define AEC_AE_LINPHY_CFG_ENATXTO(x)             (((uint16_t)(((uint16_t)(x)) << AEC_AE_LINPHY_CFG_ENATXTO_SHIFT)) & AEC_AE_LINPHY_CFG_ENATXTO_MASK)

#define AEC_AE_LINPHY_CFG_SLEW_MASK              (0x30U)
#define AEC_AE_LINPHY_CFG_SLEW_SHIFT             (4U)
#define AEC_AE_LINPHY_CFG_SLEW_WIDTH             (2U)
#define AEC_AE_LINPHY_CFG_SLEW(x)                (((uint16_t)(((uint16_t)(x)) << AEC_AE_LINPHY_CFG_SLEW_SHIFT)) & AEC_AE_LINPHY_CFG_SLEW_MASK)

#define AEC_AE_LINPHY_CFG_CXPI_NSLP_MASK         (0x100U)
#define AEC_AE_LINPHY_CFG_CXPI_NSLP_SHIFT        (8U)
#define AEC_AE_LINPHY_CFG_CXPI_NSLP_WIDTH        (1U)
#define AEC_AE_LINPHY_CFG_CXPI_NSLP(x)           (((uint16_t)(((uint16_t)(x)) << AEC_AE_LINPHY_CFG_CXPI_NSLP_SHIFT)) & AEC_AE_LINPHY_CFG_CXPI_NSLP_MASK)

#define AEC_AE_LINPHY_CFG_CXPI_MS_MASK           (0x200U)
#define AEC_AE_LINPHY_CFG_CXPI_MS_SHIFT          (9U)
#define AEC_AE_LINPHY_CFG_CXPI_MS_WIDTH          (1U)
#define AEC_AE_LINPHY_CFG_CXPI_MS(x)             (((uint16_t)(((uint16_t)(x)) << AEC_AE_LINPHY_CFG_CXPI_MS_SHIFT)) & AEC_AE_LINPHY_CFG_CXPI_MS_MASK)

#define AEC_AE_LINPHY_CFG_CXPI_SLOPE_MASK        (0x400U)
#define AEC_AE_LINPHY_CFG_CXPI_SLOPE_SHIFT       (10U)
#define AEC_AE_LINPHY_CFG_CXPI_SLOPE_WIDTH       (1U)
#define AEC_AE_LINPHY_CFG_CXPI_SLOPE(x)          (((uint16_t)(((uint16_t)(x)) << AEC_AE_LINPHY_CFG_CXPI_SLOPE_SHIFT)) & AEC_AE_LINPHY_CFG_CXPI_SLOPE_MASK)

#define AEC_AE_LINPHY_CFG_CXPI_BOOST_MASK        (0x800U)
#define AEC_AE_LINPHY_CFG_CXPI_BOOST_SHIFT       (11U)
#define AEC_AE_LINPHY_CFG_CXPI_BOOST_WIDTH       (1U)
#define AEC_AE_LINPHY_CFG_CXPI_BOOST(x)          (((uint16_t)(((uint16_t)(x)) << AEC_AE_LINPHY_CFG_CXPI_BOOST_SHIFT)) & AEC_AE_LINPHY_CFG_CXPI_BOOST_MASK)

#define AEC_AE_LINPHY_CFG_LIN_CXPI_SEL_MASK      (0x4000U)
#define AEC_AE_LINPHY_CFG_LIN_CXPI_SEL_SHIFT     (14U)
#define AEC_AE_LINPHY_CFG_LIN_CXPI_SEL_WIDTH     (1U)
#define AEC_AE_LINPHY_CFG_LIN_CXPI_SEL(x)        (((uint16_t)(((uint16_t)(x)) << AEC_AE_LINPHY_CFG_LIN_CXPI_SEL_SHIFT)) & AEC_AE_LINPHY_CFG_LIN_CXPI_SEL_MASK)

#define AEC_AE_LINPHY_CFG_LINPHY_ENABLE_MASK     (0x8000U)
#define AEC_AE_LINPHY_CFG_LINPHY_ENABLE_SHIFT    (15U)
#define AEC_AE_LINPHY_CFG_LINPHY_ENABLE_WIDTH    (1U)
#define AEC_AE_LINPHY_CFG_LINPHY_ENABLE(x)       (((uint16_t)(((uint16_t)(x)) << AEC_AE_LINPHY_CFG_LINPHY_ENABLE_SHIFT)) & AEC_AE_LINPHY_CFG_LINPHY_ENABLE_MASK)
/*! @} */

/*! @name LINPHY_MONITOR - LINPHY Monitor */
/*! @{ */

#define AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_FL_MASK (0x1U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_FL_SHIFT (0U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_FL_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_FL(x)  (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_FL_SHIFT)) & AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_FL_MASK)

#define AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_FL_MASK (0x2U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_FL_SHIFT (1U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_FL_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_FL(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_FL_SHIFT)) & AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_FL_MASK)

#define AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_FL_MASK (0x4U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_FL_SHIFT (2U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_FL_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_FL(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_FL_SHIFT)) & AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_FL_MASK)

#define AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_FL_MASK (0x8U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_FL_SHIFT (3U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_FL_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_FL(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_FL_SHIFT)) & AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_FL_MASK)

#define AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_MON_MASK (0x10U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_MON_SHIFT (4U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_MON_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_MON(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_MON_SHIFT)) & AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_MON_MASK)

#define AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_MON_MASK (0x20U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_MON_SHIFT (5U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_MON_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_MON(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_MON_SHIFT)) & AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_MON_MASK)

#define AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_MON_MASK (0x40U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_MON_SHIFT (6U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_MON_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_MON(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_MON_SHIFT)) & AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_MON_MASK)

#define AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_MON_MASK (0x80U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_MON_SHIFT (7U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_MON_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_MON(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_MON_SHIFT)) & AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_MON_MASK)

#define AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_EN_MASK (0x100U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_EN_SHIFT (8U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_EN_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_EN(x)  (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_EN_SHIFT)) & AEC_AE_LINPHY_MONITOR_LINPHY_WKUP_EN_MASK)

#define AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_EN_MASK (0x200U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_EN_SHIFT (9U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_EN_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_EN(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_EN_SHIFT)) & AEC_AE_LINPHY_MONITOR_LINPHY_SCPSTATE_EN_MASK)

#define AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_EN_MASK (0x400U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_EN_SHIFT (10U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_EN_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_EN(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_EN_SHIFT)) & AEC_AE_LINPHY_MONITOR_LINPHY_TXTOSTATE_EN_MASK)

#define AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_EN_MASK (0x800U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_EN_SHIFT (11U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_EN_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_EN(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_EN_SHIFT)) & AEC_AE_LINPHY_MONITOR_LINPHY_ERROR_EN_MASK)

#define AEC_AE_LINPHY_MONITOR_CXPI_WKUP_FL_MASK  (0x10000U)
#define AEC_AE_LINPHY_MONITOR_CXPI_WKUP_FL_SHIFT (16U)
#define AEC_AE_LINPHY_MONITOR_CXPI_WKUP_FL_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_CXPI_WKUP_FL(x)    (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_CXPI_WKUP_FL_SHIFT)) & AEC_AE_LINPHY_MONITOR_CXPI_WKUP_FL_MASK)

#define AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_FL_MASK (0x20000U)
#define AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_FL_SHIFT (17U)
#define AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_FL_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_FL(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_FL_SHIFT)) & AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_FL_MASK)

#define AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_FL_MASK (0x40000U)
#define AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_FL_SHIFT (18U)
#define AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_FL_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_FL(x)   (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_FL_SHIFT)) & AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_FL_MASK)

#define AEC_AE_LINPHY_MONITOR_CXPI_WKUP_MON_MASK (0x100000U)
#define AEC_AE_LINPHY_MONITOR_CXPI_WKUP_MON_SHIFT (20U)
#define AEC_AE_LINPHY_MONITOR_CXPI_WKUP_MON_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_CXPI_WKUP_MON(x)   (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_CXPI_WKUP_MON_SHIFT)) & AEC_AE_LINPHY_MONITOR_CXPI_WKUP_MON_MASK)

#define AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_MON_MASK (0x200000U)
#define AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_MON_SHIFT (21U)
#define AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_MON_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_MON(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_MON_SHIFT)) & AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_MON_MASK)

#define AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_MON_MASK (0x400000U)
#define AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_MON_SHIFT (22U)
#define AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_MON_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_MON(x)  (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_MON_SHIFT)) & AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_MON_MASK)

#define AEC_AE_LINPHY_MONITOR_CXPI_WKUP_EN_MASK  (0x1000000U)
#define AEC_AE_LINPHY_MONITOR_CXPI_WKUP_EN_SHIFT (24U)
#define AEC_AE_LINPHY_MONITOR_CXPI_WKUP_EN_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_CXPI_WKUP_EN(x)    (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_CXPI_WKUP_EN_SHIFT)) & AEC_AE_LINPHY_MONITOR_CXPI_WKUP_EN_MASK)

#define AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_EN_MASK (0x2000000U)
#define AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_EN_SHIFT (25U)
#define AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_EN_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_EN(x) (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_EN_SHIFT)) & AEC_AE_LINPHY_MONITOR_CXPI_DOMTIMOUT_EN_MASK)

#define AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_EN_MASK (0x4000000U)
#define AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_EN_SHIFT (26U)
#define AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_EN_WIDTH (1U)
#define AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_EN(x)   (((uint32_t)(((uint32_t)(x)) << AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_EN_SHIFT)) & AEC_AE_LINPHY_MONITOR_CXPI_ARBIT_EN_MASK)
/*! @} */

/*! @name CANPHY_CFG - CANPHY Configuration */
/*! @{ */

#define AEC_AE_CANPHY_CFG_MODE_MASK              (0x3U)
#define AEC_AE_CANPHY_CFG_MODE_SHIFT             (0U)
#define AEC_AE_CANPHY_CFG_MODE_WIDTH             (2U)
#define AEC_AE_CANPHY_CFG_MODE(x)                (((uint16_t)(((uint16_t)(x)) << AEC_AE_CANPHY_CFG_MODE_SHIFT)) & AEC_AE_CANPHY_CFG_MODE_MASK)

#define AEC_AE_CANPHY_CFG_CANPHY_ENABLE_MASK     (0x8000U)
#define AEC_AE_CANPHY_CFG_CANPHY_ENABLE_SHIFT    (15U)
#define AEC_AE_CANPHY_CFG_CANPHY_ENABLE_WIDTH    (1U)
#define AEC_AE_CANPHY_CFG_CANPHY_ENABLE(x)       (((uint16_t)(((uint16_t)(x)) << AEC_AE_CANPHY_CFG_CANPHY_ENABLE_SHIFT)) & AEC_AE_CANPHY_CFG_CANPHY_ENABLE_MASK)
/*! @} */

/*! @name CANPHY_MONITOR - CANPHY Monitor */
/*! @{ */

#define AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_FL_MASK (0x1U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_FL_SHIFT (0U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_FL_WIDTH (1U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_FL(x)  (((uint16_t)(((uint16_t)(x)) << AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_FL_SHIFT)) & AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_FL_MASK)

#define AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_FL_MASK (0x2U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_FL_SHIFT (1U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_FL_WIDTH (1U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_FL(x) (((uint16_t)(((uint16_t)(x)) << AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_FL_SHIFT)) & AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_FL_MASK)

#define AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_FL_MASK (0x4U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_FL_SHIFT (2U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_FL_WIDTH (1U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_FL(x) (((uint16_t)(((uint16_t)(x)) << AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_FL_SHIFT)) & AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_FL_MASK)

#define AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_MON_MASK (0x10U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_MON_SHIFT (4U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_MON_WIDTH (1U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_MON(x) (((uint16_t)(((uint16_t)(x)) << AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_MON_SHIFT)) & AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_MON_MASK)

#define AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_MON_MASK (0x20U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_MON_SHIFT (5U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_MON_WIDTH (1U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_MON(x) (((uint16_t)(((uint16_t)(x)) << AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_MON_SHIFT)) & AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_MON_MASK)

#define AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_MON_MASK (0x40U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_MON_SHIFT (6U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_MON_WIDTH (1U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_MON(x) (((uint16_t)(((uint16_t)(x)) << AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_MON_SHIFT)) & AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_MON_MASK)

#define AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_EN_MASK (0x100U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_EN_SHIFT (8U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_EN_WIDTH (1U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_EN(x)  (((uint16_t)(((uint16_t)(x)) << AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_EN_SHIFT)) & AEC_AE_CANPHY_MONITOR_CANPHY_WKUP_EN_MASK)

#define AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_EN_MASK (0x200U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_EN_SHIFT (9U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_EN_WIDTH (1U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_EN(x) (((uint16_t)(((uint16_t)(x)) << AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_EN_SHIFT)) & AEC_AE_CANPHY_MONITOR_CANPHY_TXDOMTIMEDOUT_EN_MASK)

#define AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_EN_MASK (0x400U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_EN_SHIFT (10U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_EN_WIDTH (1U)
#define AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_EN(x) (((uint16_t)(((uint16_t)(x)) << AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_EN_SHIFT)) & AEC_AE_CANPHY_MONITOR_CANPHY_INVALIDSTATE_EN_MASK)
/*! @} */

/*! @name TMON_PHY - Temperature Monitor PHY */
/*! @{ */

#define AEC_AE_TMON_PHY_PHY_85_FL_MASK           (0x1U)
#define AEC_AE_TMON_PHY_PHY_85_FL_SHIFT          (0U)
#define AEC_AE_TMON_PHY_PHY_85_FL_WIDTH          (1U)
#define AEC_AE_TMON_PHY_PHY_85_FL(x)             (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PHY_PHY_85_FL_SHIFT)) & AEC_AE_TMON_PHY_PHY_85_FL_MASK)

#define AEC_AE_TMON_PHY_PHY_125_FL_MASK          (0x2U)
#define AEC_AE_TMON_PHY_PHY_125_FL_SHIFT         (1U)
#define AEC_AE_TMON_PHY_PHY_125_FL_WIDTH         (1U)
#define AEC_AE_TMON_PHY_PHY_125_FL(x)            (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PHY_PHY_125_FL_SHIFT)) & AEC_AE_TMON_PHY_PHY_125_FL_MASK)

#define AEC_AE_TMON_PHY_PHY_150_FL_MASK          (0x4U)
#define AEC_AE_TMON_PHY_PHY_150_FL_SHIFT         (2U)
#define AEC_AE_TMON_PHY_PHY_150_FL_WIDTH         (1U)
#define AEC_AE_TMON_PHY_PHY_150_FL(x)            (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PHY_PHY_150_FL_SHIFT)) & AEC_AE_TMON_PHY_PHY_150_FL_MASK)

#define AEC_AE_TMON_PHY_PHY_175_FL_MASK          (0x8U)
#define AEC_AE_TMON_PHY_PHY_175_FL_SHIFT         (3U)
#define AEC_AE_TMON_PHY_PHY_175_FL_WIDTH         (1U)
#define AEC_AE_TMON_PHY_PHY_175_FL(x)            (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PHY_PHY_175_FL_SHIFT)) & AEC_AE_TMON_PHY_PHY_175_FL_MASK)

#define AEC_AE_TMON_PHY_PHY_85_MON_MASK          (0x100U)
#define AEC_AE_TMON_PHY_PHY_85_MON_SHIFT         (8U)
#define AEC_AE_TMON_PHY_PHY_85_MON_WIDTH         (1U)
#define AEC_AE_TMON_PHY_PHY_85_MON(x)            (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PHY_PHY_85_MON_SHIFT)) & AEC_AE_TMON_PHY_PHY_85_MON_MASK)

#define AEC_AE_TMON_PHY_PHY_125_MON_MASK         (0x200U)
#define AEC_AE_TMON_PHY_PHY_125_MON_SHIFT        (9U)
#define AEC_AE_TMON_PHY_PHY_125_MON_WIDTH        (1U)
#define AEC_AE_TMON_PHY_PHY_125_MON(x)           (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PHY_PHY_125_MON_SHIFT)) & AEC_AE_TMON_PHY_PHY_125_MON_MASK)

#define AEC_AE_TMON_PHY_PHY_150_MON_MASK         (0x400U)
#define AEC_AE_TMON_PHY_PHY_150_MON_SHIFT        (10U)
#define AEC_AE_TMON_PHY_PHY_150_MON_WIDTH        (1U)
#define AEC_AE_TMON_PHY_PHY_150_MON(x)           (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PHY_PHY_150_MON_SHIFT)) & AEC_AE_TMON_PHY_PHY_150_MON_MASK)

#define AEC_AE_TMON_PHY_PHY_175_MON_MASK         (0x800U)
#define AEC_AE_TMON_PHY_PHY_175_MON_SHIFT        (11U)
#define AEC_AE_TMON_PHY_PHY_175_MON_WIDTH        (1U)
#define AEC_AE_TMON_PHY_PHY_175_MON(x)           (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PHY_PHY_175_MON_SHIFT)) & AEC_AE_TMON_PHY_PHY_175_MON_MASK)

#define AEC_AE_TMON_PHY_PHY_85_EN_MASK           (0x10000U)
#define AEC_AE_TMON_PHY_PHY_85_EN_SHIFT          (16U)
#define AEC_AE_TMON_PHY_PHY_85_EN_WIDTH          (1U)
#define AEC_AE_TMON_PHY_PHY_85_EN(x)             (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PHY_PHY_85_EN_SHIFT)) & AEC_AE_TMON_PHY_PHY_85_EN_MASK)

#define AEC_AE_TMON_PHY_PHY_125_EN_MASK          (0x20000U)
#define AEC_AE_TMON_PHY_PHY_125_EN_SHIFT         (17U)
#define AEC_AE_TMON_PHY_PHY_125_EN_WIDTH         (1U)
#define AEC_AE_TMON_PHY_PHY_125_EN(x)            (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PHY_PHY_125_EN_SHIFT)) & AEC_AE_TMON_PHY_PHY_125_EN_MASK)

#define AEC_AE_TMON_PHY_PHY_150_EN_MASK          (0x40000U)
#define AEC_AE_TMON_PHY_PHY_150_EN_SHIFT         (18U)
#define AEC_AE_TMON_PHY_PHY_150_EN_WIDTH         (1U)
#define AEC_AE_TMON_PHY_PHY_150_EN(x)            (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PHY_PHY_150_EN_SHIFT)) & AEC_AE_TMON_PHY_PHY_150_EN_MASK)

#define AEC_AE_TMON_PHY_PHY_175_EN_MASK          (0x80000U)
#define AEC_AE_TMON_PHY_PHY_175_EN_SHIFT         (19U)
#define AEC_AE_TMON_PHY_PHY_175_EN_WIDTH         (1U)
#define AEC_AE_TMON_PHY_PHY_175_EN(x)            (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PHY_PHY_175_EN_SHIFT)) & AEC_AE_TMON_PHY_PHY_175_EN_MASK)
/*! @} */

/*! @name TMON_PMC - Temperature Monitor PMC */
/*! @{ */

#define AEC_AE_TMON_PMC_PMC_85_FL_MASK           (0x1U)
#define AEC_AE_TMON_PMC_PMC_85_FL_SHIFT          (0U)
#define AEC_AE_TMON_PMC_PMC_85_FL_WIDTH          (1U)
#define AEC_AE_TMON_PMC_PMC_85_FL(x)             (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PMC_PMC_85_FL_SHIFT)) & AEC_AE_TMON_PMC_PMC_85_FL_MASK)

#define AEC_AE_TMON_PMC_PMC_125_FL_MASK          (0x2U)
#define AEC_AE_TMON_PMC_PMC_125_FL_SHIFT         (1U)
#define AEC_AE_TMON_PMC_PMC_125_FL_WIDTH         (1U)
#define AEC_AE_TMON_PMC_PMC_125_FL(x)            (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PMC_PMC_125_FL_SHIFT)) & AEC_AE_TMON_PMC_PMC_125_FL_MASK)

#define AEC_AE_TMON_PMC_PMC_150_FL_MASK          (0x4U)
#define AEC_AE_TMON_PMC_PMC_150_FL_SHIFT         (2U)
#define AEC_AE_TMON_PMC_PMC_150_FL_WIDTH         (1U)
#define AEC_AE_TMON_PMC_PMC_150_FL(x)            (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PMC_PMC_150_FL_SHIFT)) & AEC_AE_TMON_PMC_PMC_150_FL_MASK)

#define AEC_AE_TMON_PMC_PMC_175_FL_MASK          (0x8U)
#define AEC_AE_TMON_PMC_PMC_175_FL_SHIFT         (3U)
#define AEC_AE_TMON_PMC_PMC_175_FL_WIDTH         (1U)
#define AEC_AE_TMON_PMC_PMC_175_FL(x)            (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PMC_PMC_175_FL_SHIFT)) & AEC_AE_TMON_PMC_PMC_175_FL_MASK)

#define AEC_AE_TMON_PMC_PMC_85_MON_MASK          (0x100U)
#define AEC_AE_TMON_PMC_PMC_85_MON_SHIFT         (8U)
#define AEC_AE_TMON_PMC_PMC_85_MON_WIDTH         (1U)
#define AEC_AE_TMON_PMC_PMC_85_MON(x)            (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PMC_PMC_85_MON_SHIFT)) & AEC_AE_TMON_PMC_PMC_85_MON_MASK)

#define AEC_AE_TMON_PMC_PMC_125_MON_MASK         (0x200U)
#define AEC_AE_TMON_PMC_PMC_125_MON_SHIFT        (9U)
#define AEC_AE_TMON_PMC_PMC_125_MON_WIDTH        (1U)
#define AEC_AE_TMON_PMC_PMC_125_MON(x)           (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PMC_PMC_125_MON_SHIFT)) & AEC_AE_TMON_PMC_PMC_125_MON_MASK)

#define AEC_AE_TMON_PMC_PMC_150_MON_MASK         (0x400U)
#define AEC_AE_TMON_PMC_PMC_150_MON_SHIFT        (10U)
#define AEC_AE_TMON_PMC_PMC_150_MON_WIDTH        (1U)
#define AEC_AE_TMON_PMC_PMC_150_MON(x)           (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PMC_PMC_150_MON_SHIFT)) & AEC_AE_TMON_PMC_PMC_150_MON_MASK)

#define AEC_AE_TMON_PMC_PMC_175_MON_MASK         (0x800U)
#define AEC_AE_TMON_PMC_PMC_175_MON_SHIFT        (11U)
#define AEC_AE_TMON_PMC_PMC_175_MON_WIDTH        (1U)
#define AEC_AE_TMON_PMC_PMC_175_MON(x)           (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PMC_PMC_175_MON_SHIFT)) & AEC_AE_TMON_PMC_PMC_175_MON_MASK)

#define AEC_AE_TMON_PMC_PMC_85_EN_MASK           (0x10000U)
#define AEC_AE_TMON_PMC_PMC_85_EN_SHIFT          (16U)
#define AEC_AE_TMON_PMC_PMC_85_EN_WIDTH          (1U)
#define AEC_AE_TMON_PMC_PMC_85_EN(x)             (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PMC_PMC_85_EN_SHIFT)) & AEC_AE_TMON_PMC_PMC_85_EN_MASK)

#define AEC_AE_TMON_PMC_PMC_125_EN_MASK          (0x20000U)
#define AEC_AE_TMON_PMC_PMC_125_EN_SHIFT         (17U)
#define AEC_AE_TMON_PMC_PMC_125_EN_WIDTH         (1U)
#define AEC_AE_TMON_PMC_PMC_125_EN(x)            (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PMC_PMC_125_EN_SHIFT)) & AEC_AE_TMON_PMC_PMC_125_EN_MASK)

#define AEC_AE_TMON_PMC_PMC_150_EN_MASK          (0x40000U)
#define AEC_AE_TMON_PMC_PMC_150_EN_SHIFT         (18U)
#define AEC_AE_TMON_PMC_PMC_150_EN_WIDTH         (1U)
#define AEC_AE_TMON_PMC_PMC_150_EN(x)            (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PMC_PMC_150_EN_SHIFT)) & AEC_AE_TMON_PMC_PMC_150_EN_MASK)

#define AEC_AE_TMON_PMC_PMC_175_EN_MASK          (0x80000U)
#define AEC_AE_TMON_PMC_PMC_175_EN_SHIFT         (19U)
#define AEC_AE_TMON_PMC_PMC_175_EN_WIDTH         (1U)
#define AEC_AE_TMON_PMC_PMC_175_EN(x)            (((uint32_t)(((uint32_t)(x)) << AEC_AE_TMON_PMC_PMC_175_EN_SHIFT)) & AEC_AE_TMON_PMC_PMC_175_EN_MASK)
/*! @} */

/*! @name TMON_MONITOR - TMON Monitor */
/*! @{ */

#define AEC_AE_TMON_MONITOR_PHY_SELF_FL_MASK     (0x1U)
#define AEC_AE_TMON_MONITOR_PHY_SELF_FL_SHIFT    (0U)
#define AEC_AE_TMON_MONITOR_PHY_SELF_FL_WIDTH    (1U)
#define AEC_AE_TMON_MONITOR_PHY_SELF_FL(x)       (((uint16_t)(((uint16_t)(x)) << AEC_AE_TMON_MONITOR_PHY_SELF_FL_SHIFT)) & AEC_AE_TMON_MONITOR_PHY_SELF_FL_MASK)

#define AEC_AE_TMON_MONITOR_PHY_SELF_MON_MASK    (0x2U)
#define AEC_AE_TMON_MONITOR_PHY_SELF_MON_SHIFT   (1U)
#define AEC_AE_TMON_MONITOR_PHY_SELF_MON_WIDTH   (1U)
#define AEC_AE_TMON_MONITOR_PHY_SELF_MON(x)      (((uint16_t)(((uint16_t)(x)) << AEC_AE_TMON_MONITOR_PHY_SELF_MON_SHIFT)) & AEC_AE_TMON_MONITOR_PHY_SELF_MON_MASK)

#define AEC_AE_TMON_MONITOR_PHY_SELF_EN_MASK     (0x10U)
#define AEC_AE_TMON_MONITOR_PHY_SELF_EN_SHIFT    (4U)
#define AEC_AE_TMON_MONITOR_PHY_SELF_EN_WIDTH    (1U)
#define AEC_AE_TMON_MONITOR_PHY_SELF_EN(x)       (((uint16_t)(((uint16_t)(x)) << AEC_AE_TMON_MONITOR_PHY_SELF_EN_SHIFT)) & AEC_AE_TMON_MONITOR_PHY_SELF_EN_MASK)

#define AEC_AE_TMON_MONITOR_PMC_SELF_FL_MASK     (0x100U)
#define AEC_AE_TMON_MONITOR_PMC_SELF_FL_SHIFT    (8U)
#define AEC_AE_TMON_MONITOR_PMC_SELF_FL_WIDTH    (1U)
#define AEC_AE_TMON_MONITOR_PMC_SELF_FL(x)       (((uint16_t)(((uint16_t)(x)) << AEC_AE_TMON_MONITOR_PMC_SELF_FL_SHIFT)) & AEC_AE_TMON_MONITOR_PMC_SELF_FL_MASK)

#define AEC_AE_TMON_MONITOR_PMC_SELF_MON_MASK    (0x200U)
#define AEC_AE_TMON_MONITOR_PMC_SELF_MON_SHIFT   (9U)
#define AEC_AE_TMON_MONITOR_PMC_SELF_MON_WIDTH   (1U)
#define AEC_AE_TMON_MONITOR_PMC_SELF_MON(x)      (((uint16_t)(((uint16_t)(x)) << AEC_AE_TMON_MONITOR_PMC_SELF_MON_SHIFT)) & AEC_AE_TMON_MONITOR_PMC_SELF_MON_MASK)

#define AEC_AE_TMON_MONITOR_PMC_SELF_EN_MASK     (0x1000U)
#define AEC_AE_TMON_MONITOR_PMC_SELF_EN_SHIFT    (12U)
#define AEC_AE_TMON_MONITOR_PMC_SELF_EN_WIDTH    (1U)
#define AEC_AE_TMON_MONITOR_PMC_SELF_EN(x)       (((uint16_t)(((uint16_t)(x)) << AEC_AE_TMON_MONITOR_PMC_SELF_EN_SHIFT)) & AEC_AE_TMON_MONITOR_PMC_SELF_EN_MASK)
/*! @} */

/*! @name TMON_CHECK - TMON Check */
/*! @{ */

#define AEC_AE_TMON_CHECK_SELF_CMD_MASK          (0x1U)
#define AEC_AE_TMON_CHECK_SELF_CMD_SHIFT         (0U)
#define AEC_AE_TMON_CHECK_SELF_CMD_WIDTH         (1U)
#define AEC_AE_TMON_CHECK_SELF_CMD(x)            (((uint16_t)(((uint16_t)(x)) << AEC_AE_TMON_CHECK_SELF_CMD_SHIFT)) & AEC_AE_TMON_CHECK_SELF_CMD_MASK)

#define AEC_AE_TMON_CHECK_SELF_ACT_MASK          (0x2U)
#define AEC_AE_TMON_CHECK_SELF_ACT_SHIFT         (1U)
#define AEC_AE_TMON_CHECK_SELF_ACT_WIDTH         (1U)
#define AEC_AE_TMON_CHECK_SELF_ACT(x)            (((uint16_t)(((uint16_t)(x)) << AEC_AE_TMON_CHECK_SELF_ACT_SHIFT)) & AEC_AE_TMON_CHECK_SELF_ACT_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group AEC_AE_Register_Masks */

/*!
 * @}
 */ /* end of group AEC_AE_Peripheral_Access_Layer */

#endif  /* #if !defined(S32M24x_AEC_AE_H_) */
