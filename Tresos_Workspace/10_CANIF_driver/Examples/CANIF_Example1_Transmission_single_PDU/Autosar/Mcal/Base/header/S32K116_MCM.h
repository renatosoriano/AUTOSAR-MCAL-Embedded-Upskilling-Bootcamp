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
 * @file S32K116_MCM.h
 * @version 1.1
 * @date 2022-01-21
 * @brief Peripheral Access Layer for S32K116_MCM
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
#if !defined(S32K116_MCM_H_)  /* Check if memory map has not been already included */
#define S32K116_MCM_H_

#include "S32K116_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Peripheral_Access_Layer MCM Peripheral Access Layer
 * @{
 */

/** MCM - Size of Registers Arrays */
#define MCM_LMDR_COUNT                            2u

/** MCM - Register Layout Typedef */
typedef struct {
  uint8_t RESERVED_0[8];
  __I  uint16_t PLASC;                             /**< Crossbar Switch (AXBS) Slave Configuration, offset: 0x8 */
  __I  uint16_t PLAMC;                             /**< Crossbar Switch (AXBS) Master Configuration, offset: 0xA */
  __IO uint32_t CPCR;                              /**< Core Platform Control Register, offset: 0xC */
  uint8_t RESERVED_1[32];
  __IO uint32_t PID;                               /**< Process ID Register, offset: 0x30 */
  uint8_t RESERVED_2[12];
  __IO uint32_t CPO;                               /**< Compute Operation Control Register, offset: 0x40 */
  uint8_t RESERVED_3[956];
  __IO uint32_t LMDR[MCM_LMDR_COUNT];              /**< Local Memory Descriptor Register, array offset: 0x400, array step: 0x4 */
  uint8_t RESERVED_4[120];
       uint32_t LMPECR;                            /**< LMEM Parity and ECC Control Register, offset: 0x480 */
  uint8_t RESERVED_5[4];
  __IO uint32_t LMPEIR;                            /**< LMEM Parity and ECC Interrupt Register, offset: 0x488 */
  uint8_t RESERVED_6[4];
  __I  uint32_t LMFAR;                             /**< LMEM Fault Address Register, offset: 0x490 */
  __I  uint32_t LMFATR;                            /**< LMEM Fault Attribute Register, offset: 0x494 */
  uint8_t RESERVED_7[8];
  __I  uint32_t LMFDHR;                            /**< LMEM Fault Data High Register, offset: 0x4A0 */
  __I  uint32_t LMFDLR;                            /**< LMEM Fault Data Low Register, offset: 0x4A4 */
} MCM_Type, *MCM_MemMapPtr;

/** Number of instances of the MCM module. */
#define MCM_INSTANCE_COUNT                       (1u)

/* MCM - Peripheral instance base addresses */
/** Peripheral MCM base address */
#define IP_MCM_BASE                              (0xF0003000u)
/** Peripheral MCM base pointer */
#define IP_MCM                                   ((MCM_Type *)IP_MCM_BASE)
/** Array initializer of MCM peripheral base addresses */
#define IP_MCM_BASE_ADDRS                        { IP_MCM_BASE }
/** Array initializer of MCM peripheral base pointers */
#define IP_MCM_BASE_PTRS                         { IP_MCM }

/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Masks MCM Register Masks
 * @{
 */

/*! @name PLASC - Crossbar Switch (AXBS) Slave Configuration */
/*! @{ */

#define MCM_PLASC_ASC_MASK                       (0xFFU)
#define MCM_PLASC_ASC_SHIFT                      (0U)
#define MCM_PLASC_ASC_WIDTH                      (8U)
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x)) << MCM_PLASC_ASC_SHIFT)) & MCM_PLASC_ASC_MASK)
/*! @} */

/*! @name PLAMC - Crossbar Switch (AXBS) Master Configuration */
/*! @{ */

#define MCM_PLAMC_AMC_MASK                       (0xFFU)
#define MCM_PLAMC_AMC_SHIFT                      (0U)
#define MCM_PLAMC_AMC_WIDTH                      (8U)
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x)) << MCM_PLAMC_AMC_SHIFT)) & MCM_PLAMC_AMC_MASK)
/*! @} */

/*! @name CPCR - Core Platform Control Register */
/*! @{ */

#define MCM_CPCR_HLT_FSM_ST_MASK                 (0x3U)
#define MCM_CPCR_HLT_FSM_ST_SHIFT                (0U)
#define MCM_CPCR_HLT_FSM_ST_WIDTH                (2U)
#define MCM_CPCR_HLT_FSM_ST(x)                   (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_HLT_FSM_ST_SHIFT)) & MCM_CPCR_HLT_FSM_ST_MASK)

#define MCM_CPCR_AXBS_HLT_REQ_MASK               (0x4U)
#define MCM_CPCR_AXBS_HLT_REQ_SHIFT              (2U)
#define MCM_CPCR_AXBS_HLT_REQ_WIDTH              (1U)
#define MCM_CPCR_AXBS_HLT_REQ(x)                 (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_AXBS_HLT_REQ_SHIFT)) & MCM_CPCR_AXBS_HLT_REQ_MASK)

#define MCM_CPCR_AXBS_HLTD_MASK                  (0x8U)
#define MCM_CPCR_AXBS_HLTD_SHIFT                 (3U)
#define MCM_CPCR_AXBS_HLTD_WIDTH                 (1U)
#define MCM_CPCR_AXBS_HLTD(x)                    (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_AXBS_HLTD_SHIFT)) & MCM_CPCR_AXBS_HLTD_MASK)

#define MCM_CPCR_FMC_PF_IDLE_MASK                (0x10U)
#define MCM_CPCR_FMC_PF_IDLE_SHIFT               (4U)
#define MCM_CPCR_FMC_PF_IDLE_WIDTH               (1U)
#define MCM_CPCR_FMC_PF_IDLE(x)                  (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_FMC_PF_IDLE_SHIFT)) & MCM_CPCR_FMC_PF_IDLE_MASK)

#define MCM_CPCR_PBRIDGE_IDLE_MASK               (0x40U)
#define MCM_CPCR_PBRIDGE_IDLE_SHIFT              (6U)
#define MCM_CPCR_PBRIDGE_IDLE_WIDTH              (1U)
#define MCM_CPCR_PBRIDGE_IDLE(x)                 (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_PBRIDGE_IDLE_SHIFT)) & MCM_CPCR_PBRIDGE_IDLE_MASK)

#define MCM_CPCR_CBRR_MASK                       (0x200U)
#define MCM_CPCR_CBRR_SHIFT                      (9U)
#define MCM_CPCR_CBRR_WIDTH                      (1U)
#define MCM_CPCR_CBRR(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_CPCR_CBRR_SHIFT)) & MCM_CPCR_CBRR_MASK)
/*! @} */

/*! @name PID - Process ID Register */
/*! @{ */

#define MCM_PID_PID_MASK                         (0xFFU)
#define MCM_PID_PID_SHIFT                        (0U)
#define MCM_PID_PID_WIDTH                        (8U)
#define MCM_PID_PID(x)                           (((uint32_t)(((uint32_t)(x)) << MCM_PID_PID_SHIFT)) & MCM_PID_PID_MASK)
/*! @} */

/*! @name CPO - Compute Operation Control Register */
/*! @{ */

#define MCM_CPO_CPOREQ_MASK                      (0x1U)
#define MCM_CPO_CPOREQ_SHIFT                     (0U)
#define MCM_CPO_CPOREQ_WIDTH                     (1U)
#define MCM_CPO_CPOREQ(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPO_CPOREQ_SHIFT)) & MCM_CPO_CPOREQ_MASK)

#define MCM_CPO_CPOACK_MASK                      (0x2U)
#define MCM_CPO_CPOACK_SHIFT                     (1U)
#define MCM_CPO_CPOACK_WIDTH                     (1U)
#define MCM_CPO_CPOACK(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPO_CPOACK_SHIFT)) & MCM_CPO_CPOACK_MASK)

#define MCM_CPO_CPOWOI_MASK                      (0x4U)
#define MCM_CPO_CPOWOI_SHIFT                     (2U)
#define MCM_CPO_CPOWOI_WIDTH                     (1U)
#define MCM_CPO_CPOWOI(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_CPO_CPOWOI_SHIFT)) & MCM_CPO_CPOWOI_MASK)
/*! @} */

/*! @name LMDR - Local Memory Descriptor Register */
/*! @{ */

#define MCM_LMDR_CF0_MASK                        (0xFU)
#define MCM_LMDR_CF0_SHIFT                       (0U)
#define MCM_LMDR_CF0_WIDTH                       (4U)
#define MCM_LMDR_CF0(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR_CF0_SHIFT)) & MCM_LMDR_CF0_MASK)

#define MCM_LMDR_MT_MASK                         (0xE000U)
#define MCM_LMDR_MT_SHIFT                        (13U)
#define MCM_LMDR_MT_WIDTH                        (3U)
#define MCM_LMDR_MT(x)                           (((uint32_t)(((uint32_t)(x)) << MCM_LMDR_MT_SHIFT)) & MCM_LMDR_MT_MASK)

#define MCM_LMDR_DPW_MASK                        (0xE0000U)
#define MCM_LMDR_DPW_SHIFT                       (17U)
#define MCM_LMDR_DPW_WIDTH                       (3U)
#define MCM_LMDR_DPW(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMDR_DPW_SHIFT)) & MCM_LMDR_DPW_MASK)

#define MCM_LMDR_WY_MASK                         (0xF00000U)
#define MCM_LMDR_WY_SHIFT                        (20U)
#define MCM_LMDR_WY_WIDTH                        (4U)
#define MCM_LMDR_WY(x)                           (((uint32_t)(((uint32_t)(x)) << MCM_LMDR_WY_SHIFT)) & MCM_LMDR_WY_MASK)

#define MCM_LMDR_LMSZ_MASK                       (0xF000000U)
#define MCM_LMDR_LMSZ_SHIFT                      (24U)
#define MCM_LMDR_LMSZ_WIDTH                      (4U)
#define MCM_LMDR_LMSZ(x)                         (((uint32_t)(((uint32_t)(x)) << MCM_LMDR_LMSZ_SHIFT)) & MCM_LMDR_LMSZ_MASK)

#define MCM_LMDR_LMSZH_MASK                      (0x10000000U)
#define MCM_LMDR_LMSZH_SHIFT                     (28U)
#define MCM_LMDR_LMSZH_WIDTH                     (1U)
#define MCM_LMDR_LMSZH(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMDR_LMSZH_SHIFT)) & MCM_LMDR_LMSZH_MASK)

#define MCM_LMDR_V_MASK                          (0x80000000U)
#define MCM_LMDR_V_SHIFT                         (31U)
#define MCM_LMDR_V_WIDTH                         (1U)
#define MCM_LMDR_V(x)                            (((uint32_t)(((uint32_t)(x)) << MCM_LMDR_V_SHIFT)) & MCM_LMDR_V_MASK)
/*! @} */

/*! @name LMPEIR - LMEM Parity and ECC Interrupt Register */
/*! @{ */

#define MCM_LMPEIR_ENC_MASK                      (0xFFU)
#define MCM_LMPEIR_ENC_SHIFT                     (0U)
#define MCM_LMPEIR_ENC_WIDTH                     (8U)
#define MCM_LMPEIR_ENC(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMPEIR_ENC_SHIFT)) & MCM_LMPEIR_ENC_MASK)

#define MCM_LMPEIR_E1B_MASK                      (0xFF00U)
#define MCM_LMPEIR_E1B_SHIFT                     (8U)
#define MCM_LMPEIR_E1B_WIDTH                     (8U)
#define MCM_LMPEIR_E1B(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMPEIR_E1B_SHIFT)) & MCM_LMPEIR_E1B_MASK)

#define MCM_LMPEIR_PEELOC_MASK                   (0x1F000000U)
#define MCM_LMPEIR_PEELOC_SHIFT                  (24U)
#define MCM_LMPEIR_PEELOC_WIDTH                  (5U)
#define MCM_LMPEIR_PEELOC(x)                     (((uint32_t)(((uint32_t)(x)) << MCM_LMPEIR_PEELOC_SHIFT)) & MCM_LMPEIR_PEELOC_MASK)

#define MCM_LMPEIR_V_MASK                        (0x80000000U)
#define MCM_LMPEIR_V_SHIFT                       (31U)
#define MCM_LMPEIR_V_WIDTH                       (1U)
#define MCM_LMPEIR_V(x)                          (((uint32_t)(((uint32_t)(x)) << MCM_LMPEIR_V_SHIFT)) & MCM_LMPEIR_V_MASK)
/*! @} */

/*! @name LMFAR - LMEM Fault Address Register */
/*! @{ */

#define MCM_LMFAR_EFADD_MASK                     (0xFFFFFFFFU)
#define MCM_LMFAR_EFADD_SHIFT                    (0U)
#define MCM_LMFAR_EFADD_WIDTH                    (32U)
#define MCM_LMFAR_EFADD(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMFAR_EFADD_SHIFT)) & MCM_LMFAR_EFADD_MASK)
/*! @} */

/*! @name LMFATR - LMEM Fault Attribute Register */
/*! @{ */

#define MCM_LMFATR_PEFPRT_MASK                   (0xFU)
#define MCM_LMFATR_PEFPRT_SHIFT                  (0U)
#define MCM_LMFATR_PEFPRT_WIDTH                  (4U)
#define MCM_LMFATR_PEFPRT(x)                     (((uint32_t)(((uint32_t)(x)) << MCM_LMFATR_PEFPRT_SHIFT)) & MCM_LMFATR_PEFPRT_MASK)

#define MCM_LMFATR_PEFSIZE_MASK                  (0x70U)
#define MCM_LMFATR_PEFSIZE_SHIFT                 (4U)
#define MCM_LMFATR_PEFSIZE_WIDTH                 (3U)
#define MCM_LMFATR_PEFSIZE(x)                    (((uint32_t)(((uint32_t)(x)) << MCM_LMFATR_PEFSIZE_SHIFT)) & MCM_LMFATR_PEFSIZE_MASK)

#define MCM_LMFATR_PEFW_MASK                     (0x80U)
#define MCM_LMFATR_PEFW_SHIFT                    (7U)
#define MCM_LMFATR_PEFW_WIDTH                    (1U)
#define MCM_LMFATR_PEFW(x)                       (((uint32_t)(((uint32_t)(x)) << MCM_LMFATR_PEFW_SHIFT)) & MCM_LMFATR_PEFW_MASK)

#define MCM_LMFATR_PEFMST_MASK                   (0xFF00U)
#define MCM_LMFATR_PEFMST_SHIFT                  (8U)
#define MCM_LMFATR_PEFMST_WIDTH                  (8U)
#define MCM_LMFATR_PEFMST(x)                     (((uint32_t)(((uint32_t)(x)) << MCM_LMFATR_PEFMST_SHIFT)) & MCM_LMFATR_PEFMST_MASK)

#define MCM_LMFATR_OVR_MASK                      (0x80000000U)
#define MCM_LMFATR_OVR_SHIFT                     (31U)
#define MCM_LMFATR_OVR_WIDTH                     (1U)
#define MCM_LMFATR_OVR(x)                        (((uint32_t)(((uint32_t)(x)) << MCM_LMFATR_OVR_SHIFT)) & MCM_LMFATR_OVR_MASK)
/*! @} */

/*! @name LMFDHR - LMEM Fault Data High Register */
/*! @{ */

#define MCM_LMFDHR_PEFDH_MASK                    (0xFFFFFFFFU)
#define MCM_LMFDHR_PEFDH_SHIFT                   (0U)
#define MCM_LMFDHR_PEFDH_WIDTH                   (32U)
#define MCM_LMFDHR_PEFDH(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_LMFDHR_PEFDH_SHIFT)) & MCM_LMFDHR_PEFDH_MASK)
/*! @} */

/*! @name LMFDLR - LMEM Fault Data Low Register */
/*! @{ */

#define MCM_LMFDLR_PEFDL_MASK                    (0xFFFFFFFFU)
#define MCM_LMFDLR_PEFDL_SHIFT                   (0U)
#define MCM_LMFDLR_PEFDL_WIDTH                   (32U)
#define MCM_LMFDLR_PEFDL(x)                      (((uint32_t)(((uint32_t)(x)) << MCM_LMFDLR_PEFDL_SHIFT)) & MCM_LMFDLR_PEFDL_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MCM_Register_Masks */

/*!
 * @}
 */ /* end of group MCM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K116_MCM_H_) */
