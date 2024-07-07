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
 * @file S32M24x_MEM_OTP_AE.h
 * @version 1.3
 * @date 2023-05-30
 * @brief Peripheral Access Layer for S32M24x_MEM_OTP_AE
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
#if !defined(S32M24x_MEM_OTP_AE_H_)  /* Check if memory map has not been already included */
#define S32M24x_MEM_OTP_AE_H_

#include "S32M24x_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MEM_OTP_AE Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MEM_OTP_AE_Peripheral_Access_Layer MEM_OTP_AE Peripheral Access Layer
 * @{
 */

/** MEM_OTP_AE - Register Layout Typedef */
typedef struct {
  __IO uint16_t CTRL_CMD;                          /**< Control Command, offset: 0x0 */
  __IO uint16_t STRT_STP;                          /**< Start Stop, offset: 0x2 */
  uint8_t RESERVED_0[4];
  __I  uint16_t DATAOUT;                           /**< Data Output, offset: 0x8 */
  __I  uint16_t STATUS;                            /**< Status, offset: 0xA */
  uint8_t RESERVED_1[16];
  __I  uint16_t ERROR;                             /**< Error, offset: 0x1C */
  __I  uint16_t MODE;                              /**< Mode, offset: 0x1E */
} MEM_OTP_AE_Type, *MEM_OTP_AE_MemMapPtr;

/** Number of instances of the MEM_OTP_AE module. */
#define MEM_OTP_AE_INSTANCE_COUNT                (1u)

/* MEM_OTP_AE - Peripheral instance base addresses */
/** Peripheral MEM_OTP_AE base address */
#define IP_MEM_OTP_AE_BASE                       (0x120u)
/** Peripheral MEM_OTP_AE base pointer */
#define IP_MEM_OTP_AE                            ((MEM_OTP_AE_Type *)IP_MEM_OTP_AE_BASE)
/** Array initializer of MEM_OTP_AE peripheral base addresses */
#define IP_MEM_OTP_AE_BASE_ADDRS                 { IP_MEM_OTP_AE_BASE }
/** Array initializer of MEM_OTP_AE peripheral base pointers */
#define IP_MEM_OTP_AE_BASE_PTRS                  { IP_MEM_OTP_AE }

/* ----------------------------------------------------------------------------
   -- MEM_OTP_AE Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MEM_OTP_AE_Register_Masks MEM_OTP_AE Register Masks
 * @{
 */

/*! @name CTRL_CMD - Control Command */
/*! @{ */

#define MEM_OTP_AE_CTRL_CMD_CMD_MASK             (0x3FU)
#define MEM_OTP_AE_CTRL_CMD_CMD_SHIFT            (0U)
#define MEM_OTP_AE_CTRL_CMD_CMD_WIDTH            (6U)
#define MEM_OTP_AE_CTRL_CMD_CMD(x)               (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_CTRL_CMD_CMD_SHIFT)) & MEM_OTP_AE_CTRL_CMD_CMD_MASK)
/*! @} */

/*! @name STRT_STP - Start Stop */
/*! @{ */

#define MEM_OTP_AE_STRT_STP_START_MASK           (0xFFU)
#define MEM_OTP_AE_STRT_STP_START_SHIFT          (0U)
#define MEM_OTP_AE_STRT_STP_START_WIDTH          (8U)
#define MEM_OTP_AE_STRT_STP_START(x)             (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_STRT_STP_START_SHIFT)) & MEM_OTP_AE_STRT_STP_START_MASK)

#define MEM_OTP_AE_STRT_STP_STOP_MASK            (0xFF00U)
#define MEM_OTP_AE_STRT_STP_STOP_SHIFT           (8U)
#define MEM_OTP_AE_STRT_STP_STOP_WIDTH           (8U)
#define MEM_OTP_AE_STRT_STP_STOP(x)              (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_STRT_STP_STOP_SHIFT)) & MEM_OTP_AE_STRT_STP_STOP_MASK)
/*! @} */

/*! @name DATAOUT - Data Output */
/*! @{ */

#define MEM_OTP_AE_DATAOUT_OUTPUT_MASK           (0xFFU)
#define MEM_OTP_AE_DATAOUT_OUTPUT_SHIFT          (0U)
#define MEM_OTP_AE_DATAOUT_OUTPUT_WIDTH          (8U)
#define MEM_OTP_AE_DATAOUT_OUTPUT(x)             (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_DATAOUT_OUTPUT_SHIFT)) & MEM_OTP_AE_DATAOUT_OUTPUT_MASK)

#define MEM_OTP_AE_DATAOUT_MIRRD_MASK            (0xFF00U)
#define MEM_OTP_AE_DATAOUT_MIRRD_SHIFT           (8U)
#define MEM_OTP_AE_DATAOUT_MIRRD_WIDTH           (8U)
#define MEM_OTP_AE_DATAOUT_MIRRD(x)              (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_DATAOUT_MIRRD_SHIFT)) & MEM_OTP_AE_DATAOUT_MIRRD_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define MEM_OTP_AE_STATUS_SECTCRCOK0_MASK        (0x1U)
#define MEM_OTP_AE_STATUS_SECTCRCOK0_SHIFT       (0U)
#define MEM_OTP_AE_STATUS_SECTCRCOK0_WIDTH       (1U)
#define MEM_OTP_AE_STATUS_SECTCRCOK0(x)          (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_STATUS_SECTCRCOK0_SHIFT)) & MEM_OTP_AE_STATUS_SECTCRCOK0_MASK)

#define MEM_OTP_AE_STATUS_SECTCRCOK1_MASK        (0x2U)
#define MEM_OTP_AE_STATUS_SECTCRCOK1_SHIFT       (1U)
#define MEM_OTP_AE_STATUS_SECTCRCOK1_WIDTH       (1U)
#define MEM_OTP_AE_STATUS_SECTCRCOK1(x)          (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_STATUS_SECTCRCOK1_SHIFT)) & MEM_OTP_AE_STATUS_SECTCRCOK1_MASK)

#define MEM_OTP_AE_STATUS_SECTCRCOK2_MASK        (0x4U)
#define MEM_OTP_AE_STATUS_SECTCRCOK2_SHIFT       (2U)
#define MEM_OTP_AE_STATUS_SECTCRCOK2_WIDTH       (1U)
#define MEM_OTP_AE_STATUS_SECTCRCOK2(x)          (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_STATUS_SECTCRCOK2_SHIFT)) & MEM_OTP_AE_STATUS_SECTCRCOK2_MASK)

#define MEM_OTP_AE_STATUS_SECTCRCOK3_MASK        (0x8U)
#define MEM_OTP_AE_STATUS_SECTCRCOK3_SHIFT       (3U)
#define MEM_OTP_AE_STATUS_SECTCRCOK3_WIDTH       (1U)
#define MEM_OTP_AE_STATUS_SECTCRCOK3(x)          (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_STATUS_SECTCRCOK3_SHIFT)) & MEM_OTP_AE_STATUS_SECTCRCOK3_MASK)

#define MEM_OTP_AE_STATUS_SECTWP0_MASK           (0x10U)
#define MEM_OTP_AE_STATUS_SECTWP0_SHIFT          (4U)
#define MEM_OTP_AE_STATUS_SECTWP0_WIDTH          (1U)
#define MEM_OTP_AE_STATUS_SECTWP0(x)             (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_STATUS_SECTWP0_SHIFT)) & MEM_OTP_AE_STATUS_SECTWP0_MASK)

#define MEM_OTP_AE_STATUS_SECTWP1_MASK           (0x20U)
#define MEM_OTP_AE_STATUS_SECTWP1_SHIFT          (5U)
#define MEM_OTP_AE_STATUS_SECTWP1_WIDTH          (1U)
#define MEM_OTP_AE_STATUS_SECTWP1(x)             (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_STATUS_SECTWP1_SHIFT)) & MEM_OTP_AE_STATUS_SECTWP1_MASK)

#define MEM_OTP_AE_STATUS_SECTWP2_MASK           (0x40U)
#define MEM_OTP_AE_STATUS_SECTWP2_SHIFT          (6U)
#define MEM_OTP_AE_STATUS_SECTWP2_WIDTH          (1U)
#define MEM_OTP_AE_STATUS_SECTWP2(x)             (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_STATUS_SECTWP2_SHIFT)) & MEM_OTP_AE_STATUS_SECTWP2_MASK)

#define MEM_OTP_AE_STATUS_SECTWP3_MASK           (0x80U)
#define MEM_OTP_AE_STATUS_SECTWP3_SHIFT          (7U)
#define MEM_OTP_AE_STATUS_SECTWP3_WIDTH          (1U)
#define MEM_OTP_AE_STATUS_SECTWP3(x)             (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_STATUS_SECTWP3_SHIFT)) & MEM_OTP_AE_STATUS_SECTWP3_MASK)

#define MEM_OTP_AE_STATUS_SECTBE0_MASK           (0x100U)
#define MEM_OTP_AE_STATUS_SECTBE0_SHIFT          (8U)
#define MEM_OTP_AE_STATUS_SECTBE0_WIDTH          (1U)
#define MEM_OTP_AE_STATUS_SECTBE0(x)             (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_STATUS_SECTBE0_SHIFT)) & MEM_OTP_AE_STATUS_SECTBE0_MASK)

#define MEM_OTP_AE_STATUS_SECTBE1_MASK           (0x200U)
#define MEM_OTP_AE_STATUS_SECTBE1_SHIFT          (9U)
#define MEM_OTP_AE_STATUS_SECTBE1_WIDTH          (1U)
#define MEM_OTP_AE_STATUS_SECTBE1(x)             (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_STATUS_SECTBE1_SHIFT)) & MEM_OTP_AE_STATUS_SECTBE1_MASK)

#define MEM_OTP_AE_STATUS_SECTBE2_MASK           (0x400U)
#define MEM_OTP_AE_STATUS_SECTBE2_SHIFT          (10U)
#define MEM_OTP_AE_STATUS_SECTBE2_WIDTH          (1U)
#define MEM_OTP_AE_STATUS_SECTBE2(x)             (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_STATUS_SECTBE2_SHIFT)) & MEM_OTP_AE_STATUS_SECTBE2_MASK)

#define MEM_OTP_AE_STATUS_SECTBE3_MASK           (0x800U)
#define MEM_OTP_AE_STATUS_SECTBE3_SHIFT          (11U)
#define MEM_OTP_AE_STATUS_SECTBE3_WIDTH          (1U)
#define MEM_OTP_AE_STATUS_SECTBE3(x)             (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_STATUS_SECTBE3_SHIFT)) & MEM_OTP_AE_STATUS_SECTBE3_MASK)
/*! @} */

/*! @name ERROR - Error */
/*! @{ */

#define MEM_OTP_AE_ERROR_RDTRIES_MASK            (0x3FU)
#define MEM_OTP_AE_ERROR_RDTRIES_SHIFT           (0U)
#define MEM_OTP_AE_ERROR_RDTRIES_WIDTH           (6U)
#define MEM_OTP_AE_ERROR_RDTRIES(x)              (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_ERROR_RDTRIES_SHIFT)) & MEM_OTP_AE_ERROR_RDTRIES_MASK)

#define MEM_OTP_AE_ERROR_CTRLBUSY_MASK           (0x40U)
#define MEM_OTP_AE_ERROR_CTRLBUSY_SHIFT          (6U)
#define MEM_OTP_AE_ERROR_CTRLBUSY_WIDTH          (1U)
#define MEM_OTP_AE_ERROR_CTRLBUSY(x)             (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_ERROR_CTRLBUSY_SHIFT)) & MEM_OTP_AE_ERROR_CTRLBUSY_MASK)

#define MEM_OTP_AE_ERROR_CTRLERR_MASK            (0x80U)
#define MEM_OTP_AE_ERROR_CTRLERR_SHIFT           (7U)
#define MEM_OTP_AE_ERROR_CTRLERR_WIDTH           (1U)
#define MEM_OTP_AE_ERROR_CTRLERR(x)              (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_ERROR_CTRLERR_SHIFT)) & MEM_OTP_AE_ERROR_CTRLERR_MASK)

#define MEM_OTP_AE_ERROR_ECC1ERR_MASK            (0x200U)
#define MEM_OTP_AE_ERROR_ECC1ERR_SHIFT           (9U)
#define MEM_OTP_AE_ERROR_ECC1ERR_WIDTH           (1U)
#define MEM_OTP_AE_ERROR_ECC1ERR(x)              (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_ERROR_ECC1ERR_SHIFT)) & MEM_OTP_AE_ERROR_ECC1ERR_MASK)

#define MEM_OTP_AE_ERROR_ECC2ERR_MASK            (0x400U)
#define MEM_OTP_AE_ERROR_ECC2ERR_SHIFT           (10U)
#define MEM_OTP_AE_ERROR_ECC2ERR_WIDTH           (1U)
#define MEM_OTP_AE_ERROR_ECC2ERR(x)              (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_ERROR_ECC2ERR_SHIFT)) & MEM_OTP_AE_ERROR_ECC2ERR_MASK)

#define MEM_OTP_AE_ERROR_BOOTERR_MASK            (0x4000U)
#define MEM_OTP_AE_ERROR_BOOTERR_SHIFT           (14U)
#define MEM_OTP_AE_ERROR_BOOTERR_WIDTH           (1U)
#define MEM_OTP_AE_ERROR_BOOTERR(x)              (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_ERROR_BOOTERR_SHIFT)) & MEM_OTP_AE_ERROR_BOOTERR_MASK)
/*! @} */

/*! @name MODE - Mode */
/*! @{ */

#define MEM_OTP_AE_MODE_SECTCRCCOMP0_MASK        (0x1U)
#define MEM_OTP_AE_MODE_SECTCRCCOMP0_SHIFT       (0U)
#define MEM_OTP_AE_MODE_SECTCRCCOMP0_WIDTH       (1U)
#define MEM_OTP_AE_MODE_SECTCRCCOMP0(x)          (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_MODE_SECTCRCCOMP0_SHIFT)) & MEM_OTP_AE_MODE_SECTCRCCOMP0_MASK)

#define MEM_OTP_AE_MODE_SECTCRCCOMP1_MASK        (0x2U)
#define MEM_OTP_AE_MODE_SECTCRCCOMP1_SHIFT       (1U)
#define MEM_OTP_AE_MODE_SECTCRCCOMP1_WIDTH       (1U)
#define MEM_OTP_AE_MODE_SECTCRCCOMP1(x)          (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_MODE_SECTCRCCOMP1_SHIFT)) & MEM_OTP_AE_MODE_SECTCRCCOMP1_MASK)

#define MEM_OTP_AE_MODE_SECTCRCCOMP2_MASK        (0x4U)
#define MEM_OTP_AE_MODE_SECTCRCCOMP2_SHIFT       (2U)
#define MEM_OTP_AE_MODE_SECTCRCCOMP2_WIDTH       (1U)
#define MEM_OTP_AE_MODE_SECTCRCCOMP2(x)          (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_MODE_SECTCRCCOMP2_SHIFT)) & MEM_OTP_AE_MODE_SECTCRCCOMP2_MASK)

#define MEM_OTP_AE_MODE_SECTCRCCOMP3_MASK        (0x8U)
#define MEM_OTP_AE_MODE_SECTCRCCOMP3_SHIFT       (3U)
#define MEM_OTP_AE_MODE_SECTCRCCOMP3_WIDTH       (1U)
#define MEM_OTP_AE_MODE_SECTCRCCOMP3(x)          (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_MODE_SECTCRCCOMP3_SHIFT)) & MEM_OTP_AE_MODE_SECTCRCCOMP3_MASK)

#define MEM_OTP_AE_MODE_TSTIC_MASK               (0x100U)
#define MEM_OTP_AE_MODE_TSTIC_SHIFT              (8U)
#define MEM_OTP_AE_MODE_TSTIC_WIDTH              (1U)
#define MEM_OTP_AE_MODE_TSTIC(x)                 (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_MODE_TSTIC_SHIFT)) & MEM_OTP_AE_MODE_TSTIC_MASK)

#define MEM_OTP_AE_MODE_SUPERUSR_MASK            (0x600U)
#define MEM_OTP_AE_MODE_SUPERUSR_SHIFT           (9U)
#define MEM_OTP_AE_MODE_SUPERUSR_WIDTH           (2U)
#define MEM_OTP_AE_MODE_SUPERUSR(x)              (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_MODE_SUPERUSR_SHIFT)) & MEM_OTP_AE_MODE_SUPERUSR_MASK)

#define MEM_OTP_AE_MODE_VERID_MASK               (0xF000U)
#define MEM_OTP_AE_MODE_VERID_SHIFT              (12U)
#define MEM_OTP_AE_MODE_VERID_WIDTH              (4U)
#define MEM_OTP_AE_MODE_VERID(x)                 (((uint16_t)(((uint16_t)(x)) << MEM_OTP_AE_MODE_VERID_SHIFT)) & MEM_OTP_AE_MODE_VERID_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MEM_OTP_AE_Register_Masks */

/*!
 * @}
 */ /* end of group MEM_OTP_AE_Peripheral_Access_Layer */

#endif  /* #if !defined(S32M24x_MEM_OTP_AE_H_) */
