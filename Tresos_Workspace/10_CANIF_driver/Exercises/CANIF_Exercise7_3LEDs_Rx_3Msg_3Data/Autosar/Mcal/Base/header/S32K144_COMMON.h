/*
** ###################################################################
**     Processor:           S32K144_M4
**     Compiler:            Keil ARM C/C++ Compiler
**     Reference manual:    S32K1XX RM Rev.14
**     Version:             rev. 1.1, 2022-02-07
**     Build:               b220207
**
**     Abstract:
**         Peripheral Access Layer for S32K144_M4
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
 * @file S32K144.h
 * @version 1.1
 * @date 2022-02-07
 * @brief Peripheral Access Layer for S32K144
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
#if !defined(S32K144_COMMON_H_)  /* Check if memory map has not been already included */
#define S32K144_COMMON_H_
#define MCU_S32K144

/* Check if another memory map has not been also included */
#if (defined(MCU_ACTIVE))
  #error S32K144 memory map: There is already included another memory map. Only one memory map can be included.
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
#define NUMBER_OF_INT_VECTORS 139                /**< Number of interrupts in the Vector table */

typedef enum {
  /* Auxiliary constants */
  NotAvail_IRQn                = -128,             /**< Not available device specific interrupt */

  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M4 SV Hard Fault Interrupt */
  MemoryManagement_IRQn        = -12,              /**< Cortex-M4 Memory Management Interrupt */
  BusFault_IRQn                = -11,              /**< Cortex-M4 Bus Fault Interrupt */
  UsageFault_IRQn              = -10,              /**< Cortex-M4 Usage Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M4 SV Call Interrupt */
  DebugMonitor_IRQn            = -4,               /**< Cortex-M4 Debug Monitor Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M4 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M4 System Tick Interrupt */

  /* Device specific interrupts */
  DMA0_IRQn                    = 0,                /**< DMA channel 0 transfer complete */
  DMA1_IRQn                    = 1,                /**< DMA channel 1 transfer complete */
  DMA2_IRQn                    = 2,                /**< DMA channel 2 transfer complete */
  DMA3_IRQn                    = 3,                /**< DMA channel 3 transfer complete */
  DMA4_IRQn                    = 4,                /**< DMA channel 4 transfer complete */
  DMA5_IRQn                    = 5,                /**< DMA channel 5 transfer complete */
  DMA6_IRQn                    = 6,                /**< DMA channel 6 transfer complete */
  DMA7_IRQn                    = 7,                /**< DMA channel 7 transfer complete */
  DMA8_IRQn                    = 8,                /**< DMA channel 8 transfer complete */
  DMA9_IRQn                    = 9,                /**< DMA channel 9 transfer complete */
  DMA10_IRQn                   = 10,               /**< DMA channel 10 transfer complete */
  DMA11_IRQn                   = 11,               /**< DMA channel 11 transfer complete */
  DMA12_IRQn                   = 12,               /**< DMA channel 12 transfer complete */
  DMA13_IRQn                   = 13,               /**< DMA channel 13 transfer complete */
  DMA14_IRQn                   = 14,               /**< DMA channel 14 transfer complete */
  DMA15_IRQn                   = 15,               /**< DMA channel 15 transfer complete */
  DMA_Error_IRQn               = 16,               /**< DMA error interrupt channels 0-15 */
  MCM_IRQn                     = 17,               /**< FPU sources */
  FTFC_CMD_IRQn                = 18,               /**< FTFC Command complete */
  FTFC_Read_Collision_IRQn     = 19,               /**< FTFC Read collision */
  LVD_LVW_IRQn                 = 20,               /**< PMC Low voltage detect interrupt */
  FTFC_Fault_IRQn              = 21,               /**< FTFC Double bit fault detect */
  WDOG_EWM_IRQn                = 22,               /**< Interrupt request out before WDOG reset out, EWM output as interrupt */
  RCM_IRQn                     = 23,               /**< RCM Asynchronous Interrupt */
  LPI2C0_Master_IRQn           = 24,               /**< LPI2C0 Master Interrupt */
  LPI2C0_Slave_IRQn            = 25,               /**< LPI2C0 Slave Interrupt */
  LPSPI0_IRQn                  = 26,               /**< LPSPI0 Interrupt */
  LPSPI1_IRQn                  = 27,               /**< LPSPI1 Interrupt */
  LPSPI2_IRQn                  = 28,               /**< LPSPI2 Interrupt */
  LPUART0_RxTx_IRQn            = 31,               /**< LPUART0 Transmit / Receive Interrupt / Error / Overrun */
  LPUART1_RxTx_IRQn            = 33,               /**< LPUART1 Transmit / Receive Interrupt / Error / Overrun */
  LPUART2_RxTx_IRQn            = 35,               /**< LPUART2 Transmit / Receive Interrupt / Error / Overrun */
  ADC0_IRQn                    = 39,               /**< ADC0 interrupt request */
  ADC1_IRQn                    = 40,               /**< ADC1 interrupt request */
  CMP0_IRQn                    = 41,               /**< CMP0 interrupt request */
  ERM_single_fault_IRQn        = 44,               /**< ERM single bit error correction */
  ERM_double_fault_IRQn        = 45,               /**< ERM double bit error non-correctable */
  RTC_IRQn                     = 46,               /**< RTC alarm interrupt */
  RTC_Seconds_IRQn             = 47,               /**< RTC seconds interrupt */
  LPIT0_Ch0_IRQn               = 48,               /**< LPIT0 channel 0 overflow interrupt */
  LPIT0_Ch1_IRQn               = 49,               /**< LPIT0 channel 1 overflow interrupt */
  LPIT0_Ch2_IRQn               = 50,               /**< LPIT0 channel 2 overflow interrupt */
  LPIT0_Ch3_IRQn               = 51,               /**< LPIT0 channel 3 overflow interrupt */
  PDB0_IRQn                    = 52,               /**< PDB0 interrupt */
  SCG_IRQn                     = 57,               /**< SCG bus interrupt request */
  LPTMR0_IRQn                  = 58,               /**< LPTIMER interrupt request */
  PORTA_IRQn                   = 59,               /**< Port A pin detect interrupt */
  PORTB_IRQn                   = 60,               /**< Port B pin detect interrupt */
  PORTC_IRQn                   = 61,               /**< Port C pin detect interrupt */
  PORTD_IRQn                   = 62,               /**< Port D pin detect interrupt */
  PORTE_IRQn                   = 63,               /**< Port E pin detect interrupt */
  SWI_IRQn                     = 64,               /**< Software interrupt */
  PDB1_IRQn                    = 68,               /**< PDB1 interrupt */
  FLEXIO_IRQn                  = 69,               /**< Software interrupt */
  CAN0_ORed_IRQn               = 78,               /**< CAN0 OR'ed Bus in Off State. */
  CAN0_Error_IRQn              = 79,               /**< CAN0 Interrupt indicating that errors were detected on the CAN bus */
  CAN0_Wake_Up_IRQn            = 80,               /**< CAN0 Interrupt asserted when Pretended Networking operation is enabled, and a valid message matches the selected filter criteria during Low Power mode */
  CAN0_ORed_0_15_MB_IRQn       = 81,               /**< CAN0 OR'ed Message buffer (0-15) */
  CAN0_ORed_16_31_MB_IRQn      = 82,               /**< CAN0 OR'ed Message buffer (16-31) */
  CAN1_ORed_IRQn               = 85,               /**< CAN1 OR'ed Bus in Off State */
  CAN1_Error_IRQn              = 86,               /**< CAN1 Interrupt indicating that errors were detected on the CAN bus */
  CAN1_ORed_0_15_MB_IRQn       = 88,               /**< CAN1 OR'ed Message buffer (0-15) */
  CAN2_ORed_IRQn               = 92,               /**< CAN2 OR'ed Bus in Off State */
  CAN2_Error_IRQn              = 93,               /**< CAN2 Interrupt indicating that errors were detected on the CAN bus */
  CAN2_ORed_0_15_MB_IRQn       = 95,               /**< CAN2 OR'ed Message buffer (0-15) */
  FTM0_Ch0_Ch1_IRQn            = 99,               /**< FTM0 Channel 0 and 1 interrupt */
  FTM0_Ch2_Ch3_IRQn            = 100,              /**< FTM0 Channel 2 and 3 interrupt */
  FTM0_Ch4_Ch5_IRQn            = 101,              /**< FTM0 Channel 4 and 5 interrupt */
  FTM0_Ch6_Ch7_IRQn            = 102,              /**< FTM0 Channel 6 and 7 interrupt */
  FTM0_Fault_IRQn              = 103,              /**< FTM0 Fault interrupt */
  FTM0_Ovf_Reload_IRQn         = 104,              /**< FTM0 Counter overflow and Reload interrupt */
  FTM1_Ch0_Ch1_IRQn            = 105,              /**< FTM1 Channel 0 and 1 interrupt */
  FTM1_Ch2_Ch3_IRQn            = 106,              /**< FTM1 Channel 2 and 3 interrupt */
  FTM1_Ch4_Ch5_IRQn            = 107,              /**< FTM1 Channel 4 and 5 interrupt */
  FTM1_Ch6_Ch7_IRQn            = 108,              /**< FTM1 Channel 6 and 7 interrupt */
  FTM1_Fault_IRQn              = 109,              /**< FTM1 Fault interrupt */
  FTM1_Ovf_Reload_IRQn         = 110,              /**< FTM1 Counter overflow and Reload interrupt */
  FTM2_Ch0_Ch1_IRQn            = 111,              /**< FTM2 Channel 0 and 1 interrupt */
  FTM2_Ch2_Ch3_IRQn            = 112,              /**< FTM2 Channel 2 and 3 interrupt */
  FTM2_Ch4_Ch5_IRQn            = 113,              /**< FTM2 Channel 4 and 5 interrupt */
  FTM2_Ch6_Ch7_IRQn            = 114,              /**< FTM2 Channel 6 and 7 interrupt */
  FTM2_Fault_IRQn              = 115,              /**< FTM2 Fault interrupt */
  FTM2_Ovf_Reload_IRQn         = 116,              /**< FTM2 Counter overflow and Reload interrupt */
  FTM3_Ch0_Ch1_IRQn            = 117,              /**< FTM3 Channel 0 and 1 interrupt */
  FTM3_Ch2_Ch3_IRQn            = 118,              /**< FTM3 Channel 2 and 3 interrupt */
  FTM3_Ch4_Ch5_IRQn            = 119,              /**< FTM3 Channel 4 and 5 interrupt */
  FTM3_Ch6_Ch7_IRQn            = 120,              /**< FTM3 Channel 6 and 7 interrupt */
  FTM3_Fault_IRQn              = 121,              /**< FTM3 Fault interrupt */
  FTM3_Ovf_Reload_IRQn         = 122               /**< FTM3 Counter overflow and Reload interrupt */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M4 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M4 Core Configuration
 * @{
 */

#define __MPU_PRESENT                  1         /**< Defines if an MPU is present or not */
#define __NVIC_PRIO_BITS               4         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */
#define __FPU_PRESENT                  1         /**< Defines if an FPU is present or not */


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


#endif  /* #if !defined(S32K144_COMMON_H_) */

