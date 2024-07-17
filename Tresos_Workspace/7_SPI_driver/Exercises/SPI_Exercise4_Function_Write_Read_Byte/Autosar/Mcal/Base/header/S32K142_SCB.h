/*
** ###################################################################
**     Processor:           S32K142_M4
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K1XX RM Rev.13
**     Version:             rev. 1.0, 2021-02-18
**     Build:               b210218
**
**     Abstract:
**         Peripheral Access Layer for S32K142_M4
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2021 NXP
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
 * @file S32K142_SCB.h
 * @version 1.0
 * @date 2021-02-18
 * @brief Peripheral Access Layer for S32K142_SCB
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
#if !defined(S32K142_SCB_H_)  /* Check if memory map has not been already included */
#define S32K142_SCB_H_

#include "S32K142_COMMON.h"

/* ----------------------------------------------------------------------------
   -- S32_SCB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S32_SCB_Peripheral_Access_Layer S32_SCB Peripheral Access Layer
 * @{
 */


/** S32_SCB - Size of Registers Arrays */

/** S32_SCB - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __IO uint32_t ACTLR;                             /**< Auxiliary Control Register,, offset: 0x8 */
       uint8_t RESERVED_1[3316];
  __I  uint32_t CPUID;                             /**< CPUID Base Register, offset: 0xD00 */
  __IO uint32_t ICSR;                              /**< Interrupt Control and State Register, offset: 0xD04 */
  __IO uint32_t VTOR;                              /**< Vector Table Offset Register, offset: 0xD08 */
  __IO uint32_t AIRCR;                             /**< Application Interrupt and Reset Control Register, offset: 0xD0C */
  __IO uint32_t SCR;                               /**< System Control Register, offset: 0xD10 */
  __IO uint32_t CCR;                               /**< Configuration and Control Register, offset: 0xD14 */
  __IO uint32_t SHPR1;                             /**< System Handler Priority Register 1, offset: 0xD18 */
  __IO uint32_t SHPR2;                             /**< System Handler Priority Register 2, offset: 0xD1C */
  __IO uint32_t SHPR3;                             /**< System Handler Priority Register 3, offset: 0xD20 */
  __IO uint32_t SHCSR;                             /**< System Handler Control and State Register, offset: 0xD24 */
  __IO uint32_t CFSR;                              /**< Configurable Fault Status Registers, offset: 0xD28 */
  __IO uint32_t HFSR;                              /**< HardFault Status register, offset: 0xD2C */
  __IO uint32_t DFSR;                              /**< Debug Fault Status Register, offset: 0xD30 */
  __IO uint32_t MMFAR;                             /**< MemManage Address Register, offset: 0xD34 */
  __IO uint32_t BFAR;                              /**< BusFault Address Register, offset: 0xD38 */
  __IO uint32_t AFSR;                              /**< Auxiliary Fault Status Register, offset: 0xD3C */
       uint8_t RESERVED_2[72];
  __IO uint32_t CPACR;                             /**< Coprocessor Access Control Register, offset: 0xD88 */
       uint8_t RESERVED_3[424];
  __IO uint32_t FPCCR;                             /**< Floating-point Context Control Register, offset: 0xF34 */
  __IO uint32_t FPCAR;                             /**< Floating-point Context Address Register, offset: 0xF38 */
  __IO uint32_t FPDSCR;                            /**< Floating-point Default Status Control Register, offset: 0xF3C */
} S32_SCB_Type, *S32_SCB_MemMapPtr;

 /** Number of instances of the S32_SCB module. */
#define S32_SCB_INSTANCE_COUNT                   (1u)


/* S32_SCB - Peripheral instance base addresses */
/** Peripheral S32_SCB base address */
#define S32_SCB_BASE                             (0xE000E000u)
/** Peripheral S32_SCB base pointer */
#define S32_SCB                                  ((S32_SCB_Type *)S32_SCB_BASE)
/** Array initializer of S32_SCB peripheral base addresses */
#define S32_SCB_BASE_ADDRS                       { S32_SCB_BASE }
/** Array initializer of S32_SCB peripheral base pointers */
#define S32_SCB_BASE_PTRS                        { S32_SCB }

/* ----------------------------------------------------------------------------
   -- S32_SCB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup S32_SCB_Register_Masks S32_SCB Register Masks
 * @{
 */

/* ACTLR Bit Fields */
#define S32_SCB_ACTLR_DISMCYCINT_MASK            0x1u
#define S32_SCB_ACTLR_DISMCYCINT_SHIFT           0u
#define S32_SCB_ACTLR_DISMCYCINT_WIDTH           1u
#define S32_SCB_ACTLR_DISMCYCINT(x)              (((uint32_t)(((uint32_t)(x))<<S32_SCB_ACTLR_DISMCYCINT_SHIFT))&S32_SCB_ACTLR_DISMCYCINT_MASK)
#define S32_SCB_ACTLR_DISDEFWBUF_MASK            0x2u
#define S32_SCB_ACTLR_DISDEFWBUF_SHIFT           1u
#define S32_SCB_ACTLR_DISDEFWBUF_WIDTH           1u
#define S32_SCB_ACTLR_DISDEFWBUF(x)              (((uint32_t)(((uint32_t)(x))<<S32_SCB_ACTLR_DISDEFWBUF_SHIFT))&S32_SCB_ACTLR_DISDEFWBUF_MASK)
#define S32_SCB_ACTLR_DISFOLD_MASK               0x4u
#define S32_SCB_ACTLR_DISFOLD_SHIFT              2u
#define S32_SCB_ACTLR_DISFOLD_WIDTH              1u
#define S32_SCB_ACTLR_DISFOLD(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_ACTLR_DISFOLD_SHIFT))&S32_SCB_ACTLR_DISFOLD_MASK)
#define S32_SCB_ACTLR_DISFPCA_MASK               0x100u
#define S32_SCB_ACTLR_DISFPCA_SHIFT              8u
#define S32_SCB_ACTLR_DISFPCA_WIDTH              1u
#define S32_SCB_ACTLR_DISFPCA(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_ACTLR_DISFPCA_SHIFT))&S32_SCB_ACTLR_DISFPCA_MASK)
#define S32_SCB_ACTLR_DISOOFP_MASK               0x200u
#define S32_SCB_ACTLR_DISOOFP_SHIFT              9u
#define S32_SCB_ACTLR_DISOOFP_WIDTH              1u
#define S32_SCB_ACTLR_DISOOFP(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_ACTLR_DISOOFP_SHIFT))&S32_SCB_ACTLR_DISOOFP_MASK)
/* CPUID Bit Fields */
#define S32_SCB_CPUID_REVISION_MASK              0xFu
#define S32_SCB_CPUID_REVISION_SHIFT             0u
#define S32_SCB_CPUID_REVISION_WIDTH             4u
#define S32_SCB_CPUID_REVISION(x)                (((uint32_t)(((uint32_t)(x))<<S32_SCB_CPUID_REVISION_SHIFT))&S32_SCB_CPUID_REVISION_MASK)
#define S32_SCB_CPUID_PARTNO_MASK                0xFFF0u
#define S32_SCB_CPUID_PARTNO_SHIFT               4u
#define S32_SCB_CPUID_PARTNO_WIDTH               12u
#define S32_SCB_CPUID_PARTNO(x)                  (((uint32_t)(((uint32_t)(x))<<S32_SCB_CPUID_PARTNO_SHIFT))&S32_SCB_CPUID_PARTNO_MASK)
#define S32_SCB_CPUID_VARIANT_MASK               0xF00000u
#define S32_SCB_CPUID_VARIANT_SHIFT              20u
#define S32_SCB_CPUID_VARIANT_WIDTH              4u
#define S32_SCB_CPUID_VARIANT(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_CPUID_VARIANT_SHIFT))&S32_SCB_CPUID_VARIANT_MASK)
#define S32_SCB_CPUID_IMPLEMENTER_MASK           0xFF000000u
#define S32_SCB_CPUID_IMPLEMENTER_SHIFT          24u
#define S32_SCB_CPUID_IMPLEMENTER_WIDTH          8u
#define S32_SCB_CPUID_IMPLEMENTER(x)             (((uint32_t)(((uint32_t)(x))<<S32_SCB_CPUID_IMPLEMENTER_SHIFT))&S32_SCB_CPUID_IMPLEMENTER_MASK)
/* ICSR Bit Fields */
#define S32_SCB_ICSR_VECTACTIVE_MASK             0x1FFu
#define S32_SCB_ICSR_VECTACTIVE_SHIFT            0u
#define S32_SCB_ICSR_VECTACTIVE_WIDTH            9u
#define S32_SCB_ICSR_VECTACTIVE(x)               (((uint32_t)(((uint32_t)(x))<<S32_SCB_ICSR_VECTACTIVE_SHIFT))&S32_SCB_ICSR_VECTACTIVE_MASK)
#define S32_SCB_ICSR_RETTOBASE_MASK              0x800u
#define S32_SCB_ICSR_RETTOBASE_SHIFT             11u
#define S32_SCB_ICSR_RETTOBASE_WIDTH             1u
#define S32_SCB_ICSR_RETTOBASE(x)                (((uint32_t)(((uint32_t)(x))<<S32_SCB_ICSR_RETTOBASE_SHIFT))&S32_SCB_ICSR_RETTOBASE_MASK)
#define S32_SCB_ICSR_VECTPENDING_MASK            0x3F000u
#define S32_SCB_ICSR_VECTPENDING_SHIFT           12u
#define S32_SCB_ICSR_VECTPENDING_WIDTH           6u
#define S32_SCB_ICSR_VECTPENDING(x)              (((uint32_t)(((uint32_t)(x))<<S32_SCB_ICSR_VECTPENDING_SHIFT))&S32_SCB_ICSR_VECTPENDING_MASK)
#define S32_SCB_ICSR_ISRPENDING_MASK             0x400000u
#define S32_SCB_ICSR_ISRPENDING_SHIFT            22u
#define S32_SCB_ICSR_ISRPENDING_WIDTH            1u
#define S32_SCB_ICSR_ISRPENDING(x)               (((uint32_t)(((uint32_t)(x))<<S32_SCB_ICSR_ISRPENDING_SHIFT))&S32_SCB_ICSR_ISRPENDING_MASK)
#define S32_SCB_ICSR_ISRPREEMPT_MASK             0x800000u
#define S32_SCB_ICSR_ISRPREEMPT_SHIFT            23u
#define S32_SCB_ICSR_ISRPREEMPT_WIDTH            1u
#define S32_SCB_ICSR_ISRPREEMPT(x)               (((uint32_t)(((uint32_t)(x))<<S32_SCB_ICSR_ISRPREEMPT_SHIFT))&S32_SCB_ICSR_ISRPREEMPT_MASK)
#define S32_SCB_ICSR_PENDSTCLR_MASK              0x2000000u
#define S32_SCB_ICSR_PENDSTCLR_SHIFT             25u
#define S32_SCB_ICSR_PENDSTCLR_WIDTH             1u
#define S32_SCB_ICSR_PENDSTCLR(x)                (((uint32_t)(((uint32_t)(x))<<S32_SCB_ICSR_PENDSTCLR_SHIFT))&S32_SCB_ICSR_PENDSTCLR_MASK)
#define S32_SCB_ICSR_PENDSTSET_MASK              0x4000000u
#define S32_SCB_ICSR_PENDSTSET_SHIFT             26u
#define S32_SCB_ICSR_PENDSTSET_WIDTH             1u
#define S32_SCB_ICSR_PENDSTSET(x)                (((uint32_t)(((uint32_t)(x))<<S32_SCB_ICSR_PENDSTSET_SHIFT))&S32_SCB_ICSR_PENDSTSET_MASK)
#define S32_SCB_ICSR_PENDSVCLR_MASK              0x8000000u
#define S32_SCB_ICSR_PENDSVCLR_SHIFT             27u
#define S32_SCB_ICSR_PENDSVCLR_WIDTH             1u
#define S32_SCB_ICSR_PENDSVCLR(x)                (((uint32_t)(((uint32_t)(x))<<S32_SCB_ICSR_PENDSVCLR_SHIFT))&S32_SCB_ICSR_PENDSVCLR_MASK)
#define S32_SCB_ICSR_PENDSVSET_MASK              0x10000000u
#define S32_SCB_ICSR_PENDSVSET_SHIFT             28u
#define S32_SCB_ICSR_PENDSVSET_WIDTH             1u
#define S32_SCB_ICSR_PENDSVSET(x)                (((uint32_t)(((uint32_t)(x))<<S32_SCB_ICSR_PENDSVSET_SHIFT))&S32_SCB_ICSR_PENDSVSET_MASK)
#define S32_SCB_ICSR_NMIPENDSET_MASK             0x80000000u
#define S32_SCB_ICSR_NMIPENDSET_SHIFT            31u
#define S32_SCB_ICSR_NMIPENDSET_WIDTH            1u
#define S32_SCB_ICSR_NMIPENDSET(x)               (((uint32_t)(((uint32_t)(x))<<S32_SCB_ICSR_NMIPENDSET_SHIFT))&S32_SCB_ICSR_NMIPENDSET_MASK)
/* VTOR Bit Fields */
#define S32_SCB_VTOR_TBLOFF_MASK                 0xFFFFFF80u
#define S32_SCB_VTOR_TBLOFF_SHIFT                7u
#define S32_SCB_VTOR_TBLOFF_WIDTH                25u
#define S32_SCB_VTOR_TBLOFF(x)                   (((uint32_t)(((uint32_t)(x))<<S32_SCB_VTOR_TBLOFF_SHIFT))&S32_SCB_VTOR_TBLOFF_MASK)
/* AIRCR Bit Fields */
#define S32_SCB_AIRCR_VECTRESET_MASK             0x1u
#define S32_SCB_AIRCR_VECTRESET_SHIFT            0u
#define S32_SCB_AIRCR_VECTRESET_WIDTH            1u
#define S32_SCB_AIRCR_VECTRESET(x)               (((uint32_t)(((uint32_t)(x))<<S32_SCB_AIRCR_VECTRESET_SHIFT))&S32_SCB_AIRCR_VECTRESET_MASK)
#define S32_SCB_AIRCR_VECTCLRACTIVE_MASK         0x2u
#define S32_SCB_AIRCR_VECTCLRACTIVE_SHIFT        1u
#define S32_SCB_AIRCR_VECTCLRACTIVE_WIDTH        1u
#define S32_SCB_AIRCR_VECTCLRACTIVE(x)           (((uint32_t)(((uint32_t)(x))<<S32_SCB_AIRCR_VECTCLRACTIVE_SHIFT))&S32_SCB_AIRCR_VECTCLRACTIVE_MASK)
#define S32_SCB_AIRCR_SYSRESETREQ_MASK           0x4u
#define S32_SCB_AIRCR_SYSRESETREQ_SHIFT          2u
#define S32_SCB_AIRCR_SYSRESETREQ_WIDTH          1u
#define S32_SCB_AIRCR_SYSRESETREQ(x)             (((uint32_t)(((uint32_t)(x))<<S32_SCB_AIRCR_SYSRESETREQ_SHIFT))&S32_SCB_AIRCR_SYSRESETREQ_MASK)
#define S32_SCB_AIRCR_PRIGROUP_MASK              0x700u
#define S32_SCB_AIRCR_PRIGROUP_SHIFT             8u
#define S32_SCB_AIRCR_PRIGROUP_WIDTH             3u
#define S32_SCB_AIRCR_PRIGROUP(x)                (((uint32_t)(((uint32_t)(x))<<S32_SCB_AIRCR_PRIGROUP_SHIFT))&S32_SCB_AIRCR_PRIGROUP_MASK)
#define S32_SCB_AIRCR_ENDIANNESS_MASK            0x8000u
#define S32_SCB_AIRCR_ENDIANNESS_SHIFT           15u
#define S32_SCB_AIRCR_ENDIANNESS_WIDTH           1u
#define S32_SCB_AIRCR_ENDIANNESS(x)              (((uint32_t)(((uint32_t)(x))<<S32_SCB_AIRCR_ENDIANNESS_SHIFT))&S32_SCB_AIRCR_ENDIANNESS_MASK)
#define S32_SCB_AIRCR_VECTKEY_MASK               0xFFFF0000u
#define S32_SCB_AIRCR_VECTKEY_SHIFT              16u
#define S32_SCB_AIRCR_VECTKEY_WIDTH              16u
#define S32_SCB_AIRCR_VECTKEY(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_AIRCR_VECTKEY_SHIFT))&S32_SCB_AIRCR_VECTKEY_MASK)
/* SCR Bit Fields */
#define S32_SCB_SCR_SLEEPONEXIT_MASK             0x2u
#define S32_SCB_SCR_SLEEPONEXIT_SHIFT            1u
#define S32_SCB_SCR_SLEEPONEXIT_WIDTH            1u
#define S32_SCB_SCR_SLEEPONEXIT(x)               (((uint32_t)(((uint32_t)(x))<<S32_SCB_SCR_SLEEPONEXIT_SHIFT))&S32_SCB_SCR_SLEEPONEXIT_MASK)
#define S32_SCB_SCR_SLEEPDEEP_MASK               0x4u
#define S32_SCB_SCR_SLEEPDEEP_SHIFT              2u
#define S32_SCB_SCR_SLEEPDEEP_WIDTH              1u
#define S32_SCB_SCR_SLEEPDEEP(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_SCR_SLEEPDEEP_SHIFT))&S32_SCB_SCR_SLEEPDEEP_MASK)
#define S32_SCB_SCR_SEVONPEND_MASK               0x10u
#define S32_SCB_SCR_SEVONPEND_SHIFT              4u
#define S32_SCB_SCR_SEVONPEND_WIDTH              1u
#define S32_SCB_SCR_SEVONPEND(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_SCR_SEVONPEND_SHIFT))&S32_SCB_SCR_SEVONPEND_MASK)
/* CCR Bit Fields */
#define S32_SCB_CCR_NONBASETHRDENA_MASK          0x1u
#define S32_SCB_CCR_NONBASETHRDENA_SHIFT         0u
#define S32_SCB_CCR_NONBASETHRDENA_WIDTH         1u
#define S32_SCB_CCR_NONBASETHRDENA(x)            (((uint32_t)(((uint32_t)(x))<<S32_SCB_CCR_NONBASETHRDENA_SHIFT))&S32_SCB_CCR_NONBASETHRDENA_MASK)
#define S32_SCB_CCR_USERSETMPEND_MASK            0x2u
#define S32_SCB_CCR_USERSETMPEND_SHIFT           1u
#define S32_SCB_CCR_USERSETMPEND_WIDTH           1u
#define S32_SCB_CCR_USERSETMPEND(x)              (((uint32_t)(((uint32_t)(x))<<S32_SCB_CCR_USERSETMPEND_SHIFT))&S32_SCB_CCR_USERSETMPEND_MASK)
#define S32_SCB_CCR_UNALIGN_TRP_MASK             0x8u
#define S32_SCB_CCR_UNALIGN_TRP_SHIFT            3u
#define S32_SCB_CCR_UNALIGN_TRP_WIDTH            1u
#define S32_SCB_CCR_UNALIGN_TRP(x)               (((uint32_t)(((uint32_t)(x))<<S32_SCB_CCR_UNALIGN_TRP_SHIFT))&S32_SCB_CCR_UNALIGN_TRP_MASK)
#define S32_SCB_CCR_DIV_0_TRP_MASK               0x10u
#define S32_SCB_CCR_DIV_0_TRP_SHIFT              4u
#define S32_SCB_CCR_DIV_0_TRP_WIDTH              1u
#define S32_SCB_CCR_DIV_0_TRP(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_CCR_DIV_0_TRP_SHIFT))&S32_SCB_CCR_DIV_0_TRP_MASK)
#define S32_SCB_CCR_BFHFNMIGN_MASK               0x100u
#define S32_SCB_CCR_BFHFNMIGN_SHIFT              8u
#define S32_SCB_CCR_BFHFNMIGN_WIDTH              1u
#define S32_SCB_CCR_BFHFNMIGN(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_CCR_BFHFNMIGN_SHIFT))&S32_SCB_CCR_BFHFNMIGN_MASK)
#define S32_SCB_CCR_STKALIGN_MASK                0x200u
#define S32_SCB_CCR_STKALIGN_SHIFT               9u
#define S32_SCB_CCR_STKALIGN_WIDTH               1u
#define S32_SCB_CCR_STKALIGN(x)                  (((uint32_t)(((uint32_t)(x))<<S32_SCB_CCR_STKALIGN_SHIFT))&S32_SCB_CCR_STKALIGN_MASK)
/* SHPR1 Bit Fields */
#define S32_SCB_SHPR1_PRI_4_MASK                 0xFFu
#define S32_SCB_SHPR1_PRI_4_SHIFT                0u
#define S32_SCB_SHPR1_PRI_4_WIDTH                8u
#define S32_SCB_SHPR1_PRI_4(x)                   (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHPR1_PRI_4_SHIFT))&S32_SCB_SHPR1_PRI_4_MASK)
#define S32_SCB_SHPR1_PRI_5_MASK                 0xFF00u
#define S32_SCB_SHPR1_PRI_5_SHIFT                8u
#define S32_SCB_SHPR1_PRI_5_WIDTH                8u
#define S32_SCB_SHPR1_PRI_5(x)                   (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHPR1_PRI_5_SHIFT))&S32_SCB_SHPR1_PRI_5_MASK)
#define S32_SCB_SHPR1_PRI_6_MASK                 0xFF0000u
#define S32_SCB_SHPR1_PRI_6_SHIFT                16u
#define S32_SCB_SHPR1_PRI_6_WIDTH                8u
#define S32_SCB_SHPR1_PRI_6(x)                   (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHPR1_PRI_6_SHIFT))&S32_SCB_SHPR1_PRI_6_MASK)
/* SHPR2 Bit Fields */
#define S32_SCB_SHPR2_PRI_11_MASK                0xFF000000u
#define S32_SCB_SHPR2_PRI_11_SHIFT               24u
#define S32_SCB_SHPR2_PRI_11_WIDTH               8u
#define S32_SCB_SHPR2_PRI_11(x)                  (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHPR2_PRI_11_SHIFT))&S32_SCB_SHPR2_PRI_11_MASK)
/* SHPR3 Bit Fields */
#define S32_SCB_SHPR3_PRI_12_MASK                0xFFu
#define S32_SCB_SHPR3_PRI_12_SHIFT               0u
#define S32_SCB_SHPR3_PRI_12_WIDTH               8u
#define S32_SCB_SHPR3_PRI_12(x)                  (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHPR3_PRI_12_SHIFT))&S32_SCB_SHPR3_PRI_12_MASK)
#define S32_SCB_SHPR3_PRI_14_MASK                0xFF0000u
#define S32_SCB_SHPR3_PRI_14_SHIFT               16u
#define S32_SCB_SHPR3_PRI_14_WIDTH               8u
#define S32_SCB_SHPR3_PRI_14(x)                  (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHPR3_PRI_14_SHIFT))&S32_SCB_SHPR3_PRI_14_MASK)
#define S32_SCB_SHPR3_PRI_15_MASK                0xFF000000u
#define S32_SCB_SHPR3_PRI_15_SHIFT               24u
#define S32_SCB_SHPR3_PRI_15_WIDTH               8u
#define S32_SCB_SHPR3_PRI_15(x)                  (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHPR3_PRI_15_SHIFT))&S32_SCB_SHPR3_PRI_15_MASK)
/* SHCSR Bit Fields */
#define S32_SCB_SHCSR_MEMFAULTACT_MASK           0x1u
#define S32_SCB_SHCSR_MEMFAULTACT_SHIFT          0u
#define S32_SCB_SHCSR_MEMFAULTACT_WIDTH          1u
#define S32_SCB_SHCSR_MEMFAULTACT(x)             (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHCSR_MEMFAULTACT_SHIFT))&S32_SCB_SHCSR_MEMFAULTACT_MASK)
#define S32_SCB_SHCSR_BUSFAULTACT_MASK           0x2u
#define S32_SCB_SHCSR_BUSFAULTACT_SHIFT          1u
#define S32_SCB_SHCSR_BUSFAULTACT_WIDTH          1u
#define S32_SCB_SHCSR_BUSFAULTACT(x)             (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHCSR_BUSFAULTACT_SHIFT))&S32_SCB_SHCSR_BUSFAULTACT_MASK)
#define S32_SCB_SHCSR_USGFAULTACT_MASK           0x8u
#define S32_SCB_SHCSR_USGFAULTACT_SHIFT          3u
#define S32_SCB_SHCSR_USGFAULTACT_WIDTH          1u
#define S32_SCB_SHCSR_USGFAULTACT(x)             (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHCSR_USGFAULTACT_SHIFT))&S32_SCB_SHCSR_USGFAULTACT_MASK)
#define S32_SCB_SHCSR_SVCALLACT_MASK             0x80u
#define S32_SCB_SHCSR_SVCALLACT_SHIFT            7u
#define S32_SCB_SHCSR_SVCALLACT_WIDTH            1u
#define S32_SCB_SHCSR_SVCALLACT(x)               (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHCSR_SVCALLACT_SHIFT))&S32_SCB_SHCSR_SVCALLACT_MASK)
#define S32_SCB_SHCSR_MONITORACT_MASK            0x100u
#define S32_SCB_SHCSR_MONITORACT_SHIFT           8u
#define S32_SCB_SHCSR_MONITORACT_WIDTH           1u
#define S32_SCB_SHCSR_MONITORACT(x)              (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHCSR_MONITORACT_SHIFT))&S32_SCB_SHCSR_MONITORACT_MASK)
#define S32_SCB_SHCSR_PENDSVACT_MASK             0x400u
#define S32_SCB_SHCSR_PENDSVACT_SHIFT            10u
#define S32_SCB_SHCSR_PENDSVACT_WIDTH            1u
#define S32_SCB_SHCSR_PENDSVACT(x)               (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHCSR_PENDSVACT_SHIFT))&S32_SCB_SHCSR_PENDSVACT_MASK)
#define S32_SCB_SHCSR_SYSTICKACT_MASK            0x800u
#define S32_SCB_SHCSR_SYSTICKACT_SHIFT           11u
#define S32_SCB_SHCSR_SYSTICKACT_WIDTH           1u
#define S32_SCB_SHCSR_SYSTICKACT(x)              (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHCSR_SYSTICKACT_SHIFT))&S32_SCB_SHCSR_SYSTICKACT_MASK)
#define S32_SCB_SHCSR_USGFAULTPENDED_MASK        0x1000u
#define S32_SCB_SHCSR_USGFAULTPENDED_SHIFT       12u
#define S32_SCB_SHCSR_USGFAULTPENDED_WIDTH       1u
#define S32_SCB_SHCSR_USGFAULTPENDED(x)          (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHCSR_USGFAULTPENDED_SHIFT))&S32_SCB_SHCSR_USGFAULTPENDED_MASK)
#define S32_SCB_SHCSR_MEMFAULTPENDED_MASK        0x2000u
#define S32_SCB_SHCSR_MEMFAULTPENDED_SHIFT       13u
#define S32_SCB_SHCSR_MEMFAULTPENDED_WIDTH       1u
#define S32_SCB_SHCSR_MEMFAULTPENDED(x)          (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHCSR_MEMFAULTPENDED_SHIFT))&S32_SCB_SHCSR_MEMFAULTPENDED_MASK)
#define S32_SCB_SHCSR_BUSFAULTPENDED_MASK        0x4000u
#define S32_SCB_SHCSR_BUSFAULTPENDED_SHIFT       14u
#define S32_SCB_SHCSR_BUSFAULTPENDED_WIDTH       1u
#define S32_SCB_SHCSR_BUSFAULTPENDED(x)          (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHCSR_BUSFAULTPENDED_SHIFT))&S32_SCB_SHCSR_BUSFAULTPENDED_MASK)
#define S32_SCB_SHCSR_SVCALLPENDED_MASK          0x8000u
#define S32_SCB_SHCSR_SVCALLPENDED_SHIFT         15u
#define S32_SCB_SHCSR_SVCALLPENDED_WIDTH         1u
#define S32_SCB_SHCSR_SVCALLPENDED(x)            (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHCSR_SVCALLPENDED_SHIFT))&S32_SCB_SHCSR_SVCALLPENDED_MASK)
#define S32_SCB_SHCSR_MEMFAULTENA_MASK           0x10000u
#define S32_SCB_SHCSR_MEMFAULTENA_SHIFT          16u
#define S32_SCB_SHCSR_MEMFAULTENA_WIDTH          1u
#define S32_SCB_SHCSR_MEMFAULTENA(x)             (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHCSR_MEMFAULTENA_SHIFT))&S32_SCB_SHCSR_MEMFAULTENA_MASK)
#define S32_SCB_SHCSR_BUSFAULTENA_MASK           0x20000u
#define S32_SCB_SHCSR_BUSFAULTENA_SHIFT          17u
#define S32_SCB_SHCSR_BUSFAULTENA_WIDTH          1u
#define S32_SCB_SHCSR_BUSFAULTENA(x)             (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHCSR_BUSFAULTENA_SHIFT))&S32_SCB_SHCSR_BUSFAULTENA_MASK)
#define S32_SCB_SHCSR_USGFAULTENA_MASK           0x40000u
#define S32_SCB_SHCSR_USGFAULTENA_SHIFT          18u
#define S32_SCB_SHCSR_USGFAULTENA_WIDTH          1u
#define S32_SCB_SHCSR_USGFAULTENA(x)             (((uint32_t)(((uint32_t)(x))<<S32_SCB_SHCSR_USGFAULTENA_SHIFT))&S32_SCB_SHCSR_USGFAULTENA_MASK)
/* CFSR Bit Fields */
#define S32_SCB_CFSR_IACCVIOL_MASK               0x1u
#define S32_SCB_CFSR_IACCVIOL_SHIFT              0u
#define S32_SCB_CFSR_IACCVIOL_WIDTH              1u
#define S32_SCB_CFSR_IACCVIOL(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_IACCVIOL_SHIFT))&S32_SCB_CFSR_IACCVIOL_MASK)
#define S32_SCB_CFSR_DACCVIOL_MASK               0x2u
#define S32_SCB_CFSR_DACCVIOL_SHIFT              1u
#define S32_SCB_CFSR_DACCVIOL_WIDTH              1u
#define S32_SCB_CFSR_DACCVIOL(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_DACCVIOL_SHIFT))&S32_SCB_CFSR_DACCVIOL_MASK)
#define S32_SCB_CFSR_MUNSTKERR_MASK              0x8u
#define S32_SCB_CFSR_MUNSTKERR_SHIFT             3u
#define S32_SCB_CFSR_MUNSTKERR_WIDTH             1u
#define S32_SCB_CFSR_MUNSTKERR(x)                (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_MUNSTKERR_SHIFT))&S32_SCB_CFSR_MUNSTKERR_MASK)
#define S32_SCB_CFSR_MSTKERR_MASK                0x10u
#define S32_SCB_CFSR_MSTKERR_SHIFT               4u
#define S32_SCB_CFSR_MSTKERR_WIDTH               1u
#define S32_SCB_CFSR_MSTKERR(x)                  (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_MSTKERR_SHIFT))&S32_SCB_CFSR_MSTKERR_MASK)
#define S32_SCB_CFSR_MLSPERR_MASK                0x20u
#define S32_SCB_CFSR_MLSPERR_SHIFT               5u
#define S32_SCB_CFSR_MLSPERR_WIDTH               1u
#define S32_SCB_CFSR_MLSPERR(x)                  (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_MLSPERR_SHIFT))&S32_SCB_CFSR_MLSPERR_MASK)
#define S32_SCB_CFSR_MMARVALID_MASK              0x80u
#define S32_SCB_CFSR_MMARVALID_SHIFT             7u
#define S32_SCB_CFSR_MMARVALID_WIDTH             1u
#define S32_SCB_CFSR_MMARVALID(x)                (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_MMARVALID_SHIFT))&S32_SCB_CFSR_MMARVALID_MASK)
#define S32_SCB_CFSR_IBUSERR_MASK                0x100u
#define S32_SCB_CFSR_IBUSERR_SHIFT               8u
#define S32_SCB_CFSR_IBUSERR_WIDTH               1u
#define S32_SCB_CFSR_IBUSERR(x)                  (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_IBUSERR_SHIFT))&S32_SCB_CFSR_IBUSERR_MASK)
#define S32_SCB_CFSR_PRECISERR_MASK              0x200u
#define S32_SCB_CFSR_PRECISERR_SHIFT             9u
#define S32_SCB_CFSR_PRECISERR_WIDTH             1u
#define S32_SCB_CFSR_PRECISERR(x)                (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_PRECISERR_SHIFT))&S32_SCB_CFSR_PRECISERR_MASK)
#define S32_SCB_CFSR_IMPRECISERR_MASK            0x400u
#define S32_SCB_CFSR_IMPRECISERR_SHIFT           10u
#define S32_SCB_CFSR_IMPRECISERR_WIDTH           1u
#define S32_SCB_CFSR_IMPRECISERR(x)              (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_IMPRECISERR_SHIFT))&S32_SCB_CFSR_IMPRECISERR_MASK)
#define S32_SCB_CFSR_UNSTKERR_MASK               0x800u
#define S32_SCB_CFSR_UNSTKERR_SHIFT              11u
#define S32_SCB_CFSR_UNSTKERR_WIDTH              1u
#define S32_SCB_CFSR_UNSTKERR(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_UNSTKERR_SHIFT))&S32_SCB_CFSR_UNSTKERR_MASK)
#define S32_SCB_CFSR_STKERR_MASK                 0x1000u
#define S32_SCB_CFSR_STKERR_SHIFT                12u
#define S32_SCB_CFSR_STKERR_WIDTH                1u
#define S32_SCB_CFSR_STKERR(x)                   (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_STKERR_SHIFT))&S32_SCB_CFSR_STKERR_MASK)
#define S32_SCB_CFSR_LSPERR_MASK                 0x2000u
#define S32_SCB_CFSR_LSPERR_SHIFT                13u
#define S32_SCB_CFSR_LSPERR_WIDTH                1u
#define S32_SCB_CFSR_LSPERR(x)                   (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_LSPERR_SHIFT))&S32_SCB_CFSR_LSPERR_MASK)
#define S32_SCB_CFSR_BFARVALID_MASK              0x8000u
#define S32_SCB_CFSR_BFARVALID_SHIFT             15u
#define S32_SCB_CFSR_BFARVALID_WIDTH             1u
#define S32_SCB_CFSR_BFARVALID(x)                (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_BFARVALID_SHIFT))&S32_SCB_CFSR_BFARVALID_MASK)
#define S32_SCB_CFSR_UNDEFINSTR_MASK             0x10000u
#define S32_SCB_CFSR_UNDEFINSTR_SHIFT            16u
#define S32_SCB_CFSR_UNDEFINSTR_WIDTH            1u
#define S32_SCB_CFSR_UNDEFINSTR(x)               (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_UNDEFINSTR_SHIFT))&S32_SCB_CFSR_UNDEFINSTR_MASK)
#define S32_SCB_CFSR_INVSTATE_MASK               0x20000u
#define S32_SCB_CFSR_INVSTATE_SHIFT              17u
#define S32_SCB_CFSR_INVSTATE_WIDTH              1u
#define S32_SCB_CFSR_INVSTATE(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_INVSTATE_SHIFT))&S32_SCB_CFSR_INVSTATE_MASK)
#define S32_SCB_CFSR_INVPC_MASK                  0x40000u
#define S32_SCB_CFSR_INVPC_SHIFT                 18u
#define S32_SCB_CFSR_INVPC_WIDTH                 1u
#define S32_SCB_CFSR_INVPC(x)                    (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_INVPC_SHIFT))&S32_SCB_CFSR_INVPC_MASK)
#define S32_SCB_CFSR_NOCP_MASK                   0x80000u
#define S32_SCB_CFSR_NOCP_SHIFT                  19u
#define S32_SCB_CFSR_NOCP_WIDTH                  1u
#define S32_SCB_CFSR_NOCP(x)                     (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_NOCP_SHIFT))&S32_SCB_CFSR_NOCP_MASK)
#define S32_SCB_CFSR_UNALIGNED_MASK              0x1000000u
#define S32_SCB_CFSR_UNALIGNED_SHIFT             24u
#define S32_SCB_CFSR_UNALIGNED_WIDTH             1u
#define S32_SCB_CFSR_UNALIGNED(x)                (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_UNALIGNED_SHIFT))&S32_SCB_CFSR_UNALIGNED_MASK)
#define S32_SCB_CFSR_DIVBYZERO_MASK              0x2000000u
#define S32_SCB_CFSR_DIVBYZERO_SHIFT             25u
#define S32_SCB_CFSR_DIVBYZERO_WIDTH             1u
#define S32_SCB_CFSR_DIVBYZERO(x)                (((uint32_t)(((uint32_t)(x))<<S32_SCB_CFSR_DIVBYZERO_SHIFT))&S32_SCB_CFSR_DIVBYZERO_MASK)
/* HFSR Bit Fields */
#define S32_SCB_HFSR_VECTTBL_MASK                0x2u
#define S32_SCB_HFSR_VECTTBL_SHIFT               1u
#define S32_SCB_HFSR_VECTTBL_WIDTH               1u
#define S32_SCB_HFSR_VECTTBL(x)                  (((uint32_t)(((uint32_t)(x))<<S32_SCB_HFSR_VECTTBL_SHIFT))&S32_SCB_HFSR_VECTTBL_MASK)
#define S32_SCB_HFSR_FORCED_MASK                 0x40000000u
#define S32_SCB_HFSR_FORCED_SHIFT                30u
#define S32_SCB_HFSR_FORCED_WIDTH                1u
#define S32_SCB_HFSR_FORCED(x)                   (((uint32_t)(((uint32_t)(x))<<S32_SCB_HFSR_FORCED_SHIFT))&S32_SCB_HFSR_FORCED_MASK)
#define S32_SCB_HFSR_DEBUGEVT_MASK               0x80000000u
#define S32_SCB_HFSR_DEBUGEVT_SHIFT              31u
#define S32_SCB_HFSR_DEBUGEVT_WIDTH              1u
#define S32_SCB_HFSR_DEBUGEVT(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_HFSR_DEBUGEVT_SHIFT))&S32_SCB_HFSR_DEBUGEVT_MASK)
/* DFSR Bit Fields */
#define S32_SCB_DFSR_HALTED_MASK                 0x1u
#define S32_SCB_DFSR_HALTED_SHIFT                0u
#define S32_SCB_DFSR_HALTED_WIDTH                1u
#define S32_SCB_DFSR_HALTED(x)                   (((uint32_t)(((uint32_t)(x))<<S32_SCB_DFSR_HALTED_SHIFT))&S32_SCB_DFSR_HALTED_MASK)
#define S32_SCB_DFSR_BKPT_MASK                   0x2u
#define S32_SCB_DFSR_BKPT_SHIFT                  1u
#define S32_SCB_DFSR_BKPT_WIDTH                  1u
#define S32_SCB_DFSR_BKPT(x)                     (((uint32_t)(((uint32_t)(x))<<S32_SCB_DFSR_BKPT_SHIFT))&S32_SCB_DFSR_BKPT_MASK)
#define S32_SCB_DFSR_DWTTRAP_MASK                0x4u
#define S32_SCB_DFSR_DWTTRAP_SHIFT               2u
#define S32_SCB_DFSR_DWTTRAP_WIDTH               1u
#define S32_SCB_DFSR_DWTTRAP(x)                  (((uint32_t)(((uint32_t)(x))<<S32_SCB_DFSR_DWTTRAP_SHIFT))&S32_SCB_DFSR_DWTTRAP_MASK)
#define S32_SCB_DFSR_VCATCH_MASK                 0x8u
#define S32_SCB_DFSR_VCATCH_SHIFT                3u
#define S32_SCB_DFSR_VCATCH_WIDTH                1u
#define S32_SCB_DFSR_VCATCH(x)                   (((uint32_t)(((uint32_t)(x))<<S32_SCB_DFSR_VCATCH_SHIFT))&S32_SCB_DFSR_VCATCH_MASK)
#define S32_SCB_DFSR_EXTERNAL_MASK               0x10u
#define S32_SCB_DFSR_EXTERNAL_SHIFT              4u
#define S32_SCB_DFSR_EXTERNAL_WIDTH              1u
#define S32_SCB_DFSR_EXTERNAL(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_DFSR_EXTERNAL_SHIFT))&S32_SCB_DFSR_EXTERNAL_MASK)
/* MMFAR Bit Fields */
#define S32_SCB_MMFAR_ADDRESS_MASK               0xFFFFFFFFu
#define S32_SCB_MMFAR_ADDRESS_SHIFT              0u
#define S32_SCB_MMFAR_ADDRESS_WIDTH              32u
#define S32_SCB_MMFAR_ADDRESS(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_MMFAR_ADDRESS_SHIFT))&S32_SCB_MMFAR_ADDRESS_MASK)
/* BFAR Bit Fields */
#define S32_SCB_BFAR_ADDRESS_MASK                0xFFFFFFFFu
#define S32_SCB_BFAR_ADDRESS_SHIFT               0u
#define S32_SCB_BFAR_ADDRESS_WIDTH               32u
#define S32_SCB_BFAR_ADDRESS(x)                  (((uint32_t)(((uint32_t)(x))<<S32_SCB_BFAR_ADDRESS_SHIFT))&S32_SCB_BFAR_ADDRESS_MASK)
/* AFSR Bit Fields */
#define S32_SCB_AFSR_AUXFAULT_MASK               0xFFFFFFFFu
#define S32_SCB_AFSR_AUXFAULT_SHIFT              0u
#define S32_SCB_AFSR_AUXFAULT_WIDTH              32u
#define S32_SCB_AFSR_AUXFAULT(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_AFSR_AUXFAULT_SHIFT))&S32_SCB_AFSR_AUXFAULT_MASK)
/* CPACR Bit Fields */
#define S32_SCB_CPACR_CP10_MASK                  0x300000u
#define S32_SCB_CPACR_CP10_SHIFT                 20u
#define S32_SCB_CPACR_CP10_WIDTH                 2u
#define S32_SCB_CPACR_CP10(x)                    (((uint32_t)(((uint32_t)(x))<<S32_SCB_CPACR_CP10_SHIFT))&S32_SCB_CPACR_CP10_MASK)
#define S32_SCB_CPACR_CP11_MASK                  0xC00000u
#define S32_SCB_CPACR_CP11_SHIFT                 22u
#define S32_SCB_CPACR_CP11_WIDTH                 2u
#define S32_SCB_CPACR_CP11(x)                    (((uint32_t)(((uint32_t)(x))<<S32_SCB_CPACR_CP11_SHIFT))&S32_SCB_CPACR_CP11_MASK)
/* FPCCR Bit Fields */
#define S32_SCB_FPCCR_LSPACT_MASK                0x1u
#define S32_SCB_FPCCR_LSPACT_SHIFT               0u
#define S32_SCB_FPCCR_LSPACT_WIDTH               1u
#define S32_SCB_FPCCR_LSPACT(x)                  (((uint32_t)(((uint32_t)(x))<<S32_SCB_FPCCR_LSPACT_SHIFT))&S32_SCB_FPCCR_LSPACT_MASK)
#define S32_SCB_FPCCR_USER_MASK                  0x2u
#define S32_SCB_FPCCR_USER_SHIFT                 1u
#define S32_SCB_FPCCR_USER_WIDTH                 1u
#define S32_SCB_FPCCR_USER(x)                    (((uint32_t)(((uint32_t)(x))<<S32_SCB_FPCCR_USER_SHIFT))&S32_SCB_FPCCR_USER_MASK)
#define S32_SCB_FPCCR_THREAD_MASK                0x8u
#define S32_SCB_FPCCR_THREAD_SHIFT               3u
#define S32_SCB_FPCCR_THREAD_WIDTH               1u
#define S32_SCB_FPCCR_THREAD(x)                  (((uint32_t)(((uint32_t)(x))<<S32_SCB_FPCCR_THREAD_SHIFT))&S32_SCB_FPCCR_THREAD_MASK)
#define S32_SCB_FPCCR_HFRDY_MASK                 0x10u
#define S32_SCB_FPCCR_HFRDY_SHIFT                4u
#define S32_SCB_FPCCR_HFRDY_WIDTH                1u
#define S32_SCB_FPCCR_HFRDY(x)                   (((uint32_t)(((uint32_t)(x))<<S32_SCB_FPCCR_HFRDY_SHIFT))&S32_SCB_FPCCR_HFRDY_MASK)
#define S32_SCB_FPCCR_MMRDY_MASK                 0x20u
#define S32_SCB_FPCCR_MMRDY_SHIFT                5u
#define S32_SCB_FPCCR_MMRDY_WIDTH                1u
#define S32_SCB_FPCCR_MMRDY(x)                   (((uint32_t)(((uint32_t)(x))<<S32_SCB_FPCCR_MMRDY_SHIFT))&S32_SCB_FPCCR_MMRDY_MASK)
#define S32_SCB_FPCCR_BFRDY_MASK                 0x40u
#define S32_SCB_FPCCR_BFRDY_SHIFT                6u
#define S32_SCB_FPCCR_BFRDY_WIDTH                1u
#define S32_SCB_FPCCR_BFRDY(x)                   (((uint32_t)(((uint32_t)(x))<<S32_SCB_FPCCR_BFRDY_SHIFT))&S32_SCB_FPCCR_BFRDY_MASK)
#define S32_SCB_FPCCR_MONRDY_MASK                0x100u
#define S32_SCB_FPCCR_MONRDY_SHIFT               8u
#define S32_SCB_FPCCR_MONRDY_WIDTH               1u
#define S32_SCB_FPCCR_MONRDY(x)                  (((uint32_t)(((uint32_t)(x))<<S32_SCB_FPCCR_MONRDY_SHIFT))&S32_SCB_FPCCR_MONRDY_MASK)
#define S32_SCB_FPCCR_LSPEN_MASK                 0x40000000u
#define S32_SCB_FPCCR_LSPEN_SHIFT                30u
#define S32_SCB_FPCCR_LSPEN_WIDTH                1u
#define S32_SCB_FPCCR_LSPEN(x)                   (((uint32_t)(((uint32_t)(x))<<S32_SCB_FPCCR_LSPEN_SHIFT))&S32_SCB_FPCCR_LSPEN_MASK)
#define S32_SCB_FPCCR_ASPEN_MASK                 0x80000000u
#define S32_SCB_FPCCR_ASPEN_SHIFT                31u
#define S32_SCB_FPCCR_ASPEN_WIDTH                1u
#define S32_SCB_FPCCR_ASPEN(x)                   (((uint32_t)(((uint32_t)(x))<<S32_SCB_FPCCR_ASPEN_SHIFT))&S32_SCB_FPCCR_ASPEN_MASK)
/* FPCAR Bit Fields */
#define S32_SCB_FPCAR_ADDRESS_MASK               0xFFFFFFF8u
#define S32_SCB_FPCAR_ADDRESS_SHIFT              3u
#define S32_SCB_FPCAR_ADDRESS_WIDTH              29u
#define S32_SCB_FPCAR_ADDRESS(x)                 (((uint32_t)(((uint32_t)(x))<<S32_SCB_FPCAR_ADDRESS_SHIFT))&S32_SCB_FPCAR_ADDRESS_MASK)
/* FPDSCR Bit Fields */
#define S32_SCB_FPDSCR_RMode_MASK                0xC00000u
#define S32_SCB_FPDSCR_RMode_SHIFT               22u
#define S32_SCB_FPDSCR_RMode_WIDTH               2u
#define S32_SCB_FPDSCR_RMode(x)                  (((uint32_t)(((uint32_t)(x))<<S32_SCB_FPDSCR_RMode_SHIFT))&S32_SCB_FPDSCR_RMode_MASK)
#define S32_SCB_FPDSCR_FZ_MASK                   0x1000000u
#define S32_SCB_FPDSCR_FZ_SHIFT                  24u
#define S32_SCB_FPDSCR_FZ_WIDTH                  1u
#define S32_SCB_FPDSCR_FZ(x)                     (((uint32_t)(((uint32_t)(x))<<S32_SCB_FPDSCR_FZ_SHIFT))&S32_SCB_FPDSCR_FZ_MASK)
#define S32_SCB_FPDSCR_DN_MASK                   0x2000000u
#define S32_SCB_FPDSCR_DN_SHIFT                  25u
#define S32_SCB_FPDSCR_DN_WIDTH                  1u
#define S32_SCB_FPDSCR_DN(x)                     (((uint32_t)(((uint32_t)(x))<<S32_SCB_FPDSCR_DN_SHIFT))&S32_SCB_FPDSCR_DN_MASK)
#define S32_SCB_FPDSCR_AHP_MASK                  0x4000000u
#define S32_SCB_FPDSCR_AHP_SHIFT                 26u
#define S32_SCB_FPDSCR_AHP_WIDTH                 1u
#define S32_SCB_FPDSCR_AHP(x)                    (((uint32_t)(((uint32_t)(x))<<S32_SCB_FPDSCR_AHP_SHIFT))&S32_SCB_FPDSCR_AHP_MASK)

/*!
 * @}
 */ /* end of group S32_SCB_Register_Masks */


/*!
 * @}
 */ /* end of group S32_SCB_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K142_SCB_H_) */
