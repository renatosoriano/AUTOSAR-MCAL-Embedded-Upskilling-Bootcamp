/*
** ###################################################################
**     Processor:           S32K118_M0P
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K1XX RM Rev.14
**     Version:             rev. 1.1, 2022-01-24
**     Build:               b220124
**
**     Abstract:
**         Peripheral Access Layer for S32K118_M0P
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
 * @file S32K118.h
 * @version 1.1
 * @date 2022-01-24
 * @brief Peripheral Access Layer for S32K118
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


/* ----------------------------------------------------------------------------
   -- MCU activation
   ---------------------------------------------------------------------------- */

/* Prevention from multiple including the same memory map */
#if !defined(S32K118_COMMON_H_)  /* Check if memory map has not been already included */
#define S32K118_COMMON_H_
#define MCU_S32K118

/* Check if another memory map has not been also included */
#if (defined(MCU_ACTIVE))
  #error S32K118 memory map: There is already included another memory map. Only one memory map can be included.
#endif /* (defined(MCU_ACTIVE)) */
#define MCU_ACTIVE

#include "BasicTypes.h"

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100U
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0001U

/* ----------------------------------------------------------------------------
   -- Generic macros
   ---------------------------------------------------------------------------- */

/* IO definitions (access restrictions to peripheral registers) */
/**
*   IO Type Qualifiers are used
*   \li to specify the access to peripheral variables.
*   \li for automatic generation of peripheral register debug information.
*/
#ifndef __IO
#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions                 */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions                 */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions                */
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */
#endif


/**
* @brief 32 bits memory read macro.
*/
#if !defined(REG_READ32)
  #define REG_READ32(address)               (*(volatile uint32_t*)(address))
#endif

/**
* @brief 32 bits memory write macro.
*/
#if !defined(REG_WRITE32)
  #define REG_WRITE32(address, value)       ((*(volatile uint32_t*)(address))= (uint32_t)(value))
#endif

/**
* @brief 32 bits bits setting macro.
*/
#if !defined(REG_BIT_SET32)
  #define REG_BIT_SET32(address, mask)      ((*(volatile uint32_t*)(address))|= (uint32_t)(mask))
#endif

/**
* @brief 32 bits bits clearing macro.
*/
#if !defined(REG_BIT_CLEAR32)
  #define REG_BIT_CLEAR32(address, mask)    ((*(volatile uint32_t*)(address))&= ((uint32_t)~((uint32_t)(mask))))
#endif

/**
* @brief 32 bit clear bits and set with new value
* @note It is user's responsability to make sure that value has only "mask" bits set - (value&~mask)==0
*/
#if !defined(REG_RMW32)
  #define REG_RMW32(address, mask, value)   (REG_WRITE32((address), ((REG_READ32(address)& ((uint32_t)~((uint32_t)(mask))))| ((uint32_t)(value)))))
#endif


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 48                 /**< Number of interrupts in the Vector table */

typedef enum {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M0 SV Hard Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M0 SV Call Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M0 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M0 System Tick Interrupt */

  /* Device specific interrupts */
  DMA0_IRQn                    = 0,                /**< DMA channel 0 transfer complete */
  DMA1_IRQn                    = 1,                /**< DMA channel 1 transfer complete */
  DMA2_IRQn                    = 2,                /**< DMA channel 2 transfer complete */
  DMA3_IRQn                    = 3,                /**< DMA channel 3 transfer complete */
  DMA_Error_IRQn               = 4,                /**< DMA error interrupt channels 0-3 */
  ERM_IRQn                     = 5,                /**< ERM single bit error correction, ERM double bit error correction */
  RTC_IRQn                     = 6,                /**< RTC alarm interrupt */
  RTC_Seconds_IRQn             = 7,                /**< RTC seconds interrupt */
  LPTMR0_IRQn                  = 8,                /**< LPTIMER interrupt request */
  PORT_IRQn                    = 9,                /**< PORTA Interrupt,PORTB Interrupt,PORTC Interrupt,PORTD Interrupt,PORTE Interrupt */
  CAN0_ORed_IRQn               = 10,               /**< CAN0 OR'ed Bus in Off State,Interrupt indicating Transmit Error Counter transition from less than 96 to greater and equal to 96,Interrupt indicating Receive Error Counter transition from less than to greater and equal to 96,Interrupt indicating that errors were detected on the CAN bus, Interrupt indicating that errors were detected on the CAN bus for FD messages in the Fast Bit Rate region,Interrupt asserted when Pretended Networking operation is enabled, and a valid message matches the selected filter criteria during Low Power mode */
  CAN0_ORed_0_31_MB_IRQn       = 11,               /**< CAN0 OR'ed Message buffer (0-15),CAN0 OR'ed Message buffer (16-31) */
  FTM0_Ch0_Ch7_IRQn            = 12,               /**< FTM0 Channel 0 and 7 interrupt */
  FTM0_Fault_IRQn              = 13,               /**< FTM0 Fault interrupt */
  FTM0_Ovf_Reload_IRQn         = 14,               /**< FTM0 Counter overflow and Reload interrupt */
  FTM1_Ch0_Ch7_IRQn            = 15,               /**< FTM1 Channel 0 and 7 interrupt */
  FTM1_Fault_IRQn              = 16,               /**< FTM1 Fault interrupt */
  FTM1_Ovf_Reload_IRQn         = 17,               /**< FTM1 Counter overflow and Reload interrupt */
  FTFC_IRQn                    = 18,               /**< FTFC Command complete,Read collision,Double bit */
  PDB0_IRQn                    = 19,               /**< PDB0 interrupt */
  LPIT_IRQn                    = 20,               /**< LPIT interrupt */
  PMC_SCG_CMU_IRQn             = 21,               /**< PMC Low voltage detect interrupt, SCG bus interrupt request,CMU loss of range interrupt */
  WDOG_IRQn                    = 22,               /**< Interrupt request out before WDOG reset out */
  RCM_IRQn                     = 23,               /**< RCM Asynchronous Interrupt */
  LPI2C0_Master_Slave_IRQn     = 24,               /**< LPI2C0 Master and Slave Interrupt */
  FLEXIO_IRQn                  = 25,               /**< FLEXIO interrupt */
  LPSPI0_IRQn                  = 26,               /**< LPSPI0 Interrupt */
  LPSPI1_IRQn                  = 27,               /**< LPSPI1 Interrupt */
  ADC0_IRQn                    = 28,               /**< ADC0 interrupt request */
  CMP0_IRQn                    = 29,               /**< CMP0 interrupt request */
  LPUART1_RxTx_IRQn            = 30,               /**< LPUART1 Transmit / Receive Interrupt / Error / Overrun */
  LPUART0_RxTx_IRQn            = 31                /**< LPUART0 Transmit / Receive Interrupt / Error / Overrun */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M0 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M0 Core Configuration
 * @{
 */

#define __CM0PLUS_REV                  0x0000    /**< Core revision r0p0 */
#define __MPU_PRESENT                  1         /**< Defines if an MPU is present or not */
#define __VTOR_PRESENT                 1         /**< Defines if VTOR is present or not */
#define __NVIC_PRIO_BITS               4         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */


/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


/* ----------------------------------------------------------------------------
   -- SDK Compatibility
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SDK_Compatibility_Symbols SDK Compatibility
 * @{
 */

/* No SDK compatibility issues. */

/*!
 * @}
 */ /* end of group SDK_Compatibility_Symbols */


#endif  /* #if !defined(S32K118_COMMON_H_) */

