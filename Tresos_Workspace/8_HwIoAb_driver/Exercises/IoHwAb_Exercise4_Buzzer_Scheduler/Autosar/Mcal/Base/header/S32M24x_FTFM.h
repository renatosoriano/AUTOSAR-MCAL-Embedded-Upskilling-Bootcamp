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
 * @file S32M24x_FTFM.h
 * @version 1.3
 * @date 2023-05-30
 * @brief Peripheral Access Layer for S32M24x_FTFM
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
#if !defined(S32M24x_FTFM_H_)  /* Check if memory map has not been already included */
#define S32M24x_FTFM_H_

#include "S32M24x_COMMON.h"

/* ----------------------------------------------------------------------------
   -- FTFM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFM_Peripheral_Access_Layer FTFM Peripheral Access Layer
 * @{
 */

/** FTFM - Size of Registers Arrays */
#define FTFM_FCCOB_COUNT                          12u
#define FTFM_FPROT_COUNT                          4u

/** FTFM - Register Layout Typedef */
typedef struct {
  __IO uint8_t FSTAT;                              /**< Flash Status Register, offset: 0x0 */
  __IO uint8_t FCNFG;                              /**< Flash Configuration Register, offset: 0x1 */
  __I  uint8_t FSEC;                               /**< Flash Security Register, offset: 0x2 */
  __I  uint8_t FOPT;                               /**< Flash Option Register, offset: 0x3 */
  __IO uint8_t FCCOB[FTFM_FCCOB_COUNT];            /**< Flash Common Command Object Registers, array offset: 0x4, array step: 0x1 */
  __IO uint8_t FPROT[FTFM_FPROT_COUNT];            /**< Program Flash Protection Registers, array offset: 0x10, array step: 0x1 */
  uint8_t RESERVED_0[2];
  __IO uint8_t FEPROT;                             /**< EEPROM Protection Register, offset: 0x16 */
  __IO uint8_t FDPROT;                             /**< Data Flash Protection Register, offset: 0x17 */
  uint8_t RESERVED_1[20];
  __I  uint8_t FCSESTAT1;                          /**< Flash CSEc Status Register 1, offset: 0x2C */
  __I  uint8_t FCSESTAT0;                          /**< Flash CSEc Status Register 0, offset: 0x2D */
  __IO uint8_t FERSTAT;                            /**< Flash Error Status Register, offset: 0x2E */
  __IO uint8_t FERCNFG;                            /**< Flash Error Configuration Register, offset: 0x2F */
} FTFM_Type, *FTFM_MemMapPtr;

/** Number of instances of the FTFM module. */
#define FTFM_INSTANCE_COUNT                      (1u)

/* FTFM - Peripheral instance base addresses */
/** Peripheral FTFM base address */
#define IP_FTFM_BASE                             (0x40020000u)
/** Peripheral FTFM base pointer */
#define IP_FTFM                                  ((FTFM_Type *)IP_FTFM_BASE)
/** Array initializer of FTFM peripheral base addresses */
#define IP_FTFM_BASE_ADDRS                       { IP_FTFM_BASE }
/** Array initializer of FTFM peripheral base pointers */
#define IP_FTFM_BASE_PTRS                        { IP_FTFM }

/* ----------------------------------------------------------------------------
   -- FTFM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTFM_Register_Masks FTFM Register Masks
 * @{
 */

/*! @name FSTAT - Flash Status Register */
/*! @{ */

#define FTFM_FSTAT_MGSTAT0_MASK                  (0x1U)
#define FTFM_FSTAT_MGSTAT0_SHIFT                 (0U)
#define FTFM_FSTAT_MGSTAT0_WIDTH                 (1U)
#define FTFM_FSTAT_MGSTAT0(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FSTAT_MGSTAT0_SHIFT)) & FTFM_FSTAT_MGSTAT0_MASK)

#define FTFM_FSTAT_MGSTAT1_MASK                  (0x2U)
#define FTFM_FSTAT_MGSTAT1_SHIFT                 (1U)
#define FTFM_FSTAT_MGSTAT1_WIDTH                 (1U)
#define FTFM_FSTAT_MGSTAT1(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FSTAT_MGSTAT1_SHIFT)) & FTFM_FSTAT_MGSTAT1_MASK)

#define FTFM_FSTAT_MGSTAT2_MASK                  (0x4U)
#define FTFM_FSTAT_MGSTAT2_SHIFT                 (2U)
#define FTFM_FSTAT_MGSTAT2_WIDTH                 (1U)
#define FTFM_FSTAT_MGSTAT2(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FSTAT_MGSTAT2_SHIFT)) & FTFM_FSTAT_MGSTAT2_MASK)

#define FTFM_FSTAT_MGSTAT3_MASK                  (0x8U)
#define FTFM_FSTAT_MGSTAT3_SHIFT                 (3U)
#define FTFM_FSTAT_MGSTAT3_WIDTH                 (1U)
#define FTFM_FSTAT_MGSTAT3(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FSTAT_MGSTAT3_SHIFT)) & FTFM_FSTAT_MGSTAT3_MASK)

#define FTFM_FSTAT_FPVIOL_MASK                   (0x10U)
#define FTFM_FSTAT_FPVIOL_SHIFT                  (4U)
#define FTFM_FSTAT_FPVIOL_WIDTH                  (1U)
#define FTFM_FSTAT_FPVIOL(x)                     (((uint8_t)(((uint8_t)(x)) << FTFM_FSTAT_FPVIOL_SHIFT)) & FTFM_FSTAT_FPVIOL_MASK)

#define FTFM_FSTAT_ACCERR_MASK                   (0x20U)
#define FTFM_FSTAT_ACCERR_SHIFT                  (5U)
#define FTFM_FSTAT_ACCERR_WIDTH                  (1U)
#define FTFM_FSTAT_ACCERR(x)                     (((uint8_t)(((uint8_t)(x)) << FTFM_FSTAT_ACCERR_SHIFT)) & FTFM_FSTAT_ACCERR_MASK)

#define FTFM_FSTAT_RDCOLERR_MASK                 (0x40U)
#define FTFM_FSTAT_RDCOLERR_SHIFT                (6U)
#define FTFM_FSTAT_RDCOLERR_WIDTH                (1U)
#define FTFM_FSTAT_RDCOLERR(x)                   (((uint8_t)(((uint8_t)(x)) << FTFM_FSTAT_RDCOLERR_SHIFT)) & FTFM_FSTAT_RDCOLERR_MASK)

#define FTFM_FSTAT_CCIF_MASK                     (0x80U)
#define FTFM_FSTAT_CCIF_SHIFT                    (7U)
#define FTFM_FSTAT_CCIF_WIDTH                    (1U)
#define FTFM_FSTAT_CCIF(x)                       (((uint8_t)(((uint8_t)(x)) << FTFM_FSTAT_CCIF_SHIFT)) & FTFM_FSTAT_CCIF_MASK)
/*! @} */

/*! @name FCNFG - Flash Configuration Register */
/*! @{ */

#define FTFM_FCNFG_EEERDY_MASK                   (0x1U)
#define FTFM_FCNFG_EEERDY_SHIFT                  (0U)
#define FTFM_FCNFG_EEERDY_WIDTH                  (1U)
#define FTFM_FCNFG_EEERDY(x)                     (((uint8_t)(((uint8_t)(x)) << FTFM_FCNFG_EEERDY_SHIFT)) & FTFM_FCNFG_EEERDY_MASK)

#define FTFM_FCNFG_RAMRDY_MASK                   (0x2U)
#define FTFM_FCNFG_RAMRDY_SHIFT                  (1U)
#define FTFM_FCNFG_RAMRDY_WIDTH                  (1U)
#define FTFM_FCNFG_RAMRDY(x)                     (((uint8_t)(((uint8_t)(x)) << FTFM_FCNFG_RAMRDY_SHIFT)) & FTFM_FCNFG_RAMRDY_MASK)

#define FTFM_FCNFG_ERSSUSP_MASK                  (0x10U)
#define FTFM_FCNFG_ERSSUSP_SHIFT                 (4U)
#define FTFM_FCNFG_ERSSUSP_WIDTH                 (1U)
#define FTFM_FCNFG_ERSSUSP(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FCNFG_ERSSUSP_SHIFT)) & FTFM_FCNFG_ERSSUSP_MASK)

#define FTFM_FCNFG_ERSAREQ_MASK                  (0x20U)
#define FTFM_FCNFG_ERSAREQ_SHIFT                 (5U)
#define FTFM_FCNFG_ERSAREQ_WIDTH                 (1U)
#define FTFM_FCNFG_ERSAREQ(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FCNFG_ERSAREQ_SHIFT)) & FTFM_FCNFG_ERSAREQ_MASK)

#define FTFM_FCNFG_RDCOLLIE_MASK                 (0x40U)
#define FTFM_FCNFG_RDCOLLIE_SHIFT                (6U)
#define FTFM_FCNFG_RDCOLLIE_WIDTH                (1U)
#define FTFM_FCNFG_RDCOLLIE(x)                   (((uint8_t)(((uint8_t)(x)) << FTFM_FCNFG_RDCOLLIE_SHIFT)) & FTFM_FCNFG_RDCOLLIE_MASK)

#define FTFM_FCNFG_CCIE_MASK                     (0x80U)
#define FTFM_FCNFG_CCIE_SHIFT                    (7U)
#define FTFM_FCNFG_CCIE_WIDTH                    (1U)
#define FTFM_FCNFG_CCIE(x)                       (((uint8_t)(((uint8_t)(x)) << FTFM_FCNFG_CCIE_SHIFT)) & FTFM_FCNFG_CCIE_MASK)
/*! @} */

/*! @name FSEC - Flash Security Register */
/*! @{ */

#define FTFM_FSEC_SEC_MASK                       (0x3U)
#define FTFM_FSEC_SEC_SHIFT                      (0U)
#define FTFM_FSEC_SEC_WIDTH                      (2U)
#define FTFM_FSEC_SEC(x)                         (((uint8_t)(((uint8_t)(x)) << FTFM_FSEC_SEC_SHIFT)) & FTFM_FSEC_SEC_MASK)

#define FTFM_FSEC_FSLACC_MASK                    (0xCU)
#define FTFM_FSEC_FSLACC_SHIFT                   (2U)
#define FTFM_FSEC_FSLACC_WIDTH                   (2U)
#define FTFM_FSEC_FSLACC(x)                      (((uint8_t)(((uint8_t)(x)) << FTFM_FSEC_FSLACC_SHIFT)) & FTFM_FSEC_FSLACC_MASK)

#define FTFM_FSEC_MEEN_MASK                      (0x30U)
#define FTFM_FSEC_MEEN_SHIFT                     (4U)
#define FTFM_FSEC_MEEN_WIDTH                     (2U)
#define FTFM_FSEC_MEEN(x)                        (((uint8_t)(((uint8_t)(x)) << FTFM_FSEC_MEEN_SHIFT)) & FTFM_FSEC_MEEN_MASK)

#define FTFM_FSEC_KEYEN_MASK                     (0xC0U)
#define FTFM_FSEC_KEYEN_SHIFT                    (6U)
#define FTFM_FSEC_KEYEN_WIDTH                    (2U)
#define FTFM_FSEC_KEYEN(x)                       (((uint8_t)(((uint8_t)(x)) << FTFM_FSEC_KEYEN_SHIFT)) & FTFM_FSEC_KEYEN_MASK)
/*! @} */

/*! @name FOPT - Flash Option Register */
/*! @{ */

#define FTFM_FOPT_OPT_MASK                       (0xFFU)
#define FTFM_FOPT_OPT_SHIFT                      (0U)
#define FTFM_FOPT_OPT_WIDTH                      (8U)
#define FTFM_FOPT_OPT(x)                         (((uint8_t)(((uint8_t)(x)) << FTFM_FOPT_OPT_SHIFT)) & FTFM_FOPT_OPT_MASK)
/*! @} */

/*! @name FCCOB - Flash Common Command Object Registers */
/*! @{ */

#define FTFM_FCCOB_CCOBn_MASK                    (0xFFU)
#define FTFM_FCCOB_CCOBn_SHIFT                   (0U)
#define FTFM_FCCOB_CCOBn_WIDTH                   (8U)
#define FTFM_FCCOB_CCOBn(x)                      (((uint8_t)(((uint8_t)(x)) << FTFM_FCCOB_CCOBn_SHIFT)) & FTFM_FCCOB_CCOBn_MASK)
/*! @} */

/*! @name FPROT - Program Flash Protection Registers */
/*! @{ */

#define FTFM_FPROT_PROT_MASK                     (0xFFU)
#define FTFM_FPROT_PROT_SHIFT                    (0U)
#define FTFM_FPROT_PROT_WIDTH                    (8U)
#define FTFM_FPROT_PROT(x)                       (((uint8_t)(((uint8_t)(x)) << FTFM_FPROT_PROT_SHIFT)) & FTFM_FPROT_PROT_MASK)
/*! @} */

/*! @name FEPROT - EEPROM Protection Register */
/*! @{ */

#define FTFM_FEPROT_EPROT_MASK                   (0xFFU)
#define FTFM_FEPROT_EPROT_SHIFT                  (0U)
#define FTFM_FEPROT_EPROT_WIDTH                  (8U)
#define FTFM_FEPROT_EPROT(x)                     (((uint8_t)(((uint8_t)(x)) << FTFM_FEPROT_EPROT_SHIFT)) & FTFM_FEPROT_EPROT_MASK)
/*! @} */

/*! @name FDPROT - Data Flash Protection Register */
/*! @{ */

#define FTFM_FDPROT_DPROT_MASK                   (0xFFU)
#define FTFM_FDPROT_DPROT_SHIFT                  (0U)
#define FTFM_FDPROT_DPROT_WIDTH                  (8U)
#define FTFM_FDPROT_DPROT(x)                     (((uint8_t)(((uint8_t)(x)) << FTFM_FDPROT_DPROT_SHIFT)) & FTFM_FDPROT_DPROT_MASK)
/*! @} */

/*! @name FCSESTAT1 - Flash CSEc Status Register 1 */
/*! @{ */

#define FTFM_FCSESTAT1_BSY_MASK                  (0x1U)
#define FTFM_FCSESTAT1_BSY_SHIFT                 (0U)
#define FTFM_FCSESTAT1_BSY_WIDTH                 (1U)
#define FTFM_FCSESTAT1_BSY(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FCSESTAT1_BSY_SHIFT)) & FTFM_FCSESTAT1_BSY_MASK)

#define FTFM_FCSESTAT1_SB_MASK                   (0x2U)
#define FTFM_FCSESTAT1_SB_SHIFT                  (1U)
#define FTFM_FCSESTAT1_SB_WIDTH                  (1U)
#define FTFM_FCSESTAT1_SB(x)                     (((uint8_t)(((uint8_t)(x)) << FTFM_FCSESTAT1_SB_SHIFT)) & FTFM_FCSESTAT1_SB_MASK)

#define FTFM_FCSESTAT1_BIN_MASK                  (0x4U)
#define FTFM_FCSESTAT1_BIN_SHIFT                 (2U)
#define FTFM_FCSESTAT1_BIN_WIDTH                 (1U)
#define FTFM_FCSESTAT1_BIN(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FCSESTAT1_BIN_SHIFT)) & FTFM_FCSESTAT1_BIN_MASK)

#define FTFM_FCSESTAT1_BFN_MASK                  (0x8U)
#define FTFM_FCSESTAT1_BFN_SHIFT                 (3U)
#define FTFM_FCSESTAT1_BFN_WIDTH                 (1U)
#define FTFM_FCSESTAT1_BFN(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FCSESTAT1_BFN_SHIFT)) & FTFM_FCSESTAT1_BFN_MASK)

#define FTFM_FCSESTAT1_BOK_MASK                  (0x10U)
#define FTFM_FCSESTAT1_BOK_SHIFT                 (4U)
#define FTFM_FCSESTAT1_BOK_WIDTH                 (1U)
#define FTFM_FCSESTAT1_BOK(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FCSESTAT1_BOK_SHIFT)) & FTFM_FCSESTAT1_BOK_MASK)

#define FTFM_FCSESTAT1_RIN_MASK                  (0x20U)
#define FTFM_FCSESTAT1_RIN_SHIFT                 (5U)
#define FTFM_FCSESTAT1_RIN_WIDTH                 (1U)
#define FTFM_FCSESTAT1_RIN(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FCSESTAT1_RIN_SHIFT)) & FTFM_FCSESTAT1_RIN_MASK)

#define FTFM_FCSESTAT1_EDB_MASK                  (0x40U)
#define FTFM_FCSESTAT1_EDB_SHIFT                 (6U)
#define FTFM_FCSESTAT1_EDB_WIDTH                 (1U)
#define FTFM_FCSESTAT1_EDB(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FCSESTAT1_EDB_SHIFT)) & FTFM_FCSESTAT1_EDB_MASK)

#define FTFM_FCSESTAT1_IDB_MASK                  (0x80U)
#define FTFM_FCSESTAT1_IDB_SHIFT                 (7U)
#define FTFM_FCSESTAT1_IDB_WIDTH                 (1U)
#define FTFM_FCSESTAT1_IDB(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FCSESTAT1_IDB_SHIFT)) & FTFM_FCSESTAT1_IDB_MASK)
/*! @} */

/*! @name FCSESTAT0 - Flash CSEc Status Register 0 */
/*! @{ */

#define FTFM_FCSESTAT0_CMDTYPE_MASK              (0x2U)
#define FTFM_FCSESTAT0_CMDTYPE_SHIFT             (1U)
#define FTFM_FCSESTAT0_CMDTYPE_WIDTH             (1U)
#define FTFM_FCSESTAT0_CMDTYPE(x)                (((uint8_t)(((uint8_t)(x)) << FTFM_FCSESTAT0_CMDTYPE_SHIFT)) & FTFM_FCSESTAT0_CMDTYPE_MASK)

#define FTFM_FCSESTAT0_MEMERR_MASK               (0x4U)
#define FTFM_FCSESTAT0_MEMERR_SHIFT              (2U)
#define FTFM_FCSESTAT0_MEMERR_WIDTH              (1U)
#define FTFM_FCSESTAT0_MEMERR(x)                 (((uint8_t)(((uint8_t)(x)) << FTFM_FCSESTAT0_MEMERR_SHIFT)) & FTFM_FCSESTAT0_MEMERR_MASK)
/*! @} */

/*! @name FERSTAT - Flash Error Status Register */
/*! @{ */

#define FTFM_FERSTAT_PDFDIF_MASK                 (0x1U)
#define FTFM_FERSTAT_PDFDIF_SHIFT                (0U)
#define FTFM_FERSTAT_PDFDIF_WIDTH                (1U)
#define FTFM_FERSTAT_PDFDIF(x)                   (((uint8_t)(((uint8_t)(x)) << FTFM_FERSTAT_PDFDIF_SHIFT)) & FTFM_FERSTAT_PDFDIF_MASK)

#define FTFM_FERSTAT_DFDIF_MASK                  (0x2U)
#define FTFM_FERSTAT_DFDIF_SHIFT                 (1U)
#define FTFM_FERSTAT_DFDIF_WIDTH                 (1U)
#define FTFM_FERSTAT_DFDIF(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FERSTAT_DFDIF_SHIFT)) & FTFM_FERSTAT_DFDIF_MASK)

#define FTFM_FERSTAT_EDFDIF_MASK                 (0x4U)
#define FTFM_FERSTAT_EDFDIF_SHIFT                (2U)
#define FTFM_FERSTAT_EDFDIF_WIDTH                (1U)
#define FTFM_FERSTAT_EDFDIF(x)                   (((uint8_t)(((uint8_t)(x)) << FTFM_FERSTAT_EDFDIF_SHIFT)) & FTFM_FERSTAT_EDFDIF_MASK)

#define FTFM_FERSTAT_CDFDIF_MASK                 (0x8U)
#define FTFM_FERSTAT_CDFDIF_SHIFT                (3U)
#define FTFM_FERSTAT_CDFDIF_WIDTH                (1U)
#define FTFM_FERSTAT_CDFDIF(x)                   (((uint8_t)(((uint8_t)(x)) << FTFM_FERSTAT_CDFDIF_SHIFT)) & FTFM_FERSTAT_CDFDIF_MASK)
/*! @} */

/*! @name FERCNFG - Flash Error Configuration Register */
/*! @{ */

#define FTFM_FERCNFG_PDFDIE_MASK                 (0x1U)
#define FTFM_FERCNFG_PDFDIE_SHIFT                (0U)
#define FTFM_FERCNFG_PDFDIE_WIDTH                (1U)
#define FTFM_FERCNFG_PDFDIE(x)                   (((uint8_t)(((uint8_t)(x)) << FTFM_FERCNFG_PDFDIE_SHIFT)) & FTFM_FERCNFG_PDFDIE_MASK)

#define FTFM_FERCNFG_DFDIE_MASK                  (0x2U)
#define FTFM_FERCNFG_DFDIE_SHIFT                 (1U)
#define FTFM_FERCNFG_DFDIE_WIDTH                 (1U)
#define FTFM_FERCNFG_DFDIE(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FERCNFG_DFDIE_SHIFT)) & FTFM_FERCNFG_DFDIE_MASK)

#define FTFM_FERCNFG_EDFDIE_MASK                 (0x4U)
#define FTFM_FERCNFG_EDFDIE_SHIFT                (2U)
#define FTFM_FERCNFG_EDFDIE_WIDTH                (1U)
#define FTFM_FERCNFG_EDFDIE(x)                   (((uint8_t)(((uint8_t)(x)) << FTFM_FERCNFG_EDFDIE_SHIFT)) & FTFM_FERCNFG_EDFDIE_MASK)

#define FTFM_FERCNFG_CDFDIE_MASK                 (0x8U)
#define FTFM_FERCNFG_CDFDIE_SHIFT                (3U)
#define FTFM_FERCNFG_CDFDIE_WIDTH                (1U)
#define FTFM_FERCNFG_CDFDIE(x)                   (((uint8_t)(((uint8_t)(x)) << FTFM_FERCNFG_CDFDIE_SHIFT)) & FTFM_FERCNFG_CDFDIE_MASK)

#define FTFM_FERCNFG_PFDFD_MASK                  (0x10U)
#define FTFM_FERCNFG_PFDFD_SHIFT                 (4U)
#define FTFM_FERCNFG_PFDFD_WIDTH                 (1U)
#define FTFM_FERCNFG_PFDFD(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FERCNFG_PFDFD_SHIFT)) & FTFM_FERCNFG_PFDFD_MASK)

#define FTFM_FERCNFG_FDFD_MASK                   (0x20U)
#define FTFM_FERCNFG_FDFD_SHIFT                  (5U)
#define FTFM_FERCNFG_FDFD_WIDTH                  (1U)
#define FTFM_FERCNFG_FDFD(x)                     (((uint8_t)(((uint8_t)(x)) << FTFM_FERCNFG_FDFD_SHIFT)) & FTFM_FERCNFG_FDFD_MASK)

#define FTFM_FERCNFG_EFDFD_MASK                  (0x40U)
#define FTFM_FERCNFG_EFDFD_SHIFT                 (6U)
#define FTFM_FERCNFG_EFDFD_WIDTH                 (1U)
#define FTFM_FERCNFG_EFDFD(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FERCNFG_EFDFD_SHIFT)) & FTFM_FERCNFG_EFDFD_MASK)

#define FTFM_FERCNFG_CFDFD_MASK                  (0x80U)
#define FTFM_FERCNFG_CFDFD_SHIFT                 (7U)
#define FTFM_FERCNFG_CFDFD_WIDTH                 (1U)
#define FTFM_FERCNFG_CFDFD(x)                    (((uint8_t)(((uint8_t)(x)) << FTFM_FERCNFG_CFDFD_SHIFT)) & FTFM_FERCNFG_CFDFD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group FTFM_Register_Masks */

/*!
 * @}
 */ /* end of group FTFM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32M24x_FTFM_H_) */
