/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   Copyright 2020-2023 NXP Semiconductors
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
*/
/*==================================================================================================
*   @file    sys_init.c
*   @version 2.0.0
*
*   @brief   AUTOSAR Platform - RTD auxiliary APIs used for RTD testing
*   @details RTD auxiliary APIs used for RTD testing
*            This file contains sample code only. It is not part of the production code deliverables
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "sys_init.h"
#include "system.h"
#include "Mcal.h"

#ifdef S32K116
    #include "S32K116.h"
#endif
#ifdef S32K118
    #include "S32K118.h"
#endif
#ifdef S32K142
    #include "S32K142.h"
#endif
#ifdef S32K142W
    #include "S32K142W.h"
#endif
#ifdef S32K144
    #include "S32K144.h"
#endif
#ifdef S32K144W
    #include "S32K144W.h"
#endif
#ifdef S32K146
    #include "S32K146.h"
#endif
#ifdef S32K148
    #include "S32K148.h"
#endif
#if (defined(S32M244) || defined(S32M242) || defined(S32M243) || defined(S32M241))
    #include "S32M24x.h"
#endif

#include "nvic.h"
/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief sys_enableAllInterrupts
* @details function used to enable all interrupts
*/
/*================================================================================================*/
void sys_enableAllInterrupts(void)
{
    OsIf_ResumeAllInterrupts();
}
/*================================================================================================*/
/**
* @brief sys_disableAllInterrupts
* @details function used to disable all interrupts
*/
/*================================================================================================*/
void sys_disableAllInterrupts(void)
{
    OsIf_SuspendAllInterrupts();
}
/*================================================================================================*/
/**
* @brief sys_disableIsrSource
* @details function used to disable the interrupt number id
*/
/*================================================================================================*/
void sys_disableIsrSource(uint8 id)
{
    NVIC_DisableIRQ(id);
}
/*================================================================================================*/
/**
* @brief sys_init
* @details function used to enable the interrupt number id and set up the priority
*/
/*================================================================================================*/
void sys_enableIsrSource(uint8 id, uint8 prio)
{
    NVIC_SetPriority(id, prio);
    NVIC_EnableIRQ(id);
}
/*================================================================================================*/
/**
* @brief sys_init
* @details function used to register the interrupt handler in the interrupt vector
*/
/*================================================================================================*/
void sys_registerIsrHandler(uint8 irq_id, int_function_t isr_handler)
{
    OsIf_SuspendAllInterrupts();
    *(volatile uint32*)((*(volatile uint32*)(0xE000ED08u)) + (uint32)(((uint32)16u + irq_id) << 2u)) = (uint32)isr_handler;
    OsIf_ResumeAllInterrupts();
}

/*================================================================================================*/
/*
 * system initialization : system clock, interrupt router ...
 */
#ifdef __ICCARM__
    #pragma default_function_attributes = @ ".systeminit"
#else
    __attribute__ ((section (".systeminit")))
#endif
/**
* @brief sys_init
* @details function used to initiatialize clocks
* @return E_NOT_OK/E_OK
*/
/*================================================================================================*/
Std_ReturnType sys_init(void)
{
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    (void)Sys_GoToSupervisor();
#endif

    /* trimmed LPO to have 128Khz*/

    /* System clock initialization */


    /* FIRC Configuration */
    IP_SCG->FIRCDIV=0x000201u;   /* SCG_FIRCDIV: FIRCDIV2=2, FIRCDIV1=1 */
    IP_SCG->FIRCCFG=0x00u;        /* SCG_FIRCCFG: RANGE=0 */
    while(0u!=(IP_SCG->FIRCCSR & 0x00800000u)){};
    IP_SCG->FIRCCSR=0x00000001u;   /* SCG_FIRCCSR: FIRCEN=1 */
    while(0u == (IP_SCG->FIRCCSR & 0x01000000u)){};

    /* SIRC Configuration */
    IP_SCG->SIRCDIV=0x00201u;   /* SCG_SIRCDIV: SIRCDIV2=2, SIRCDIV1=1 */
    IP_SCG->SIRCCFG=0x01u;       /* SCG_SIRCCFG: RANGE=1 */
    while(0u!=(IP_SCG->SIRCCSR & 0x00800000u)){};
    IP_SCG->SIRCCSR=0x1u;       /* SCG_SIRCCSR: SIRCEN=1 */
    while(0u == (IP_SCG->SIRCCSR & 0x01000000u)){};
#ifndef FIRC_ENABLE
    /* SOSC Configuration */
    IP_SCG->SOSCDIV = 0x00010101u;  /* SCG_SOSCDIV: SOSCDIV3=1, SOSCDIV2=1, SOSCDIV1=1 */
    IP_SCG->SOSCCFG = 0x00000034u;  /* SCG_SOSCCFG: RANGE=3, EREFS=1 */
    while(0u!=(IP_SCG->SOSCCSR & 0x00800000u)){};
    IP_SCG->SOSCCSR= 0x5u;           /* SCG_SOSCCSR: SOSCLPEN=1, SOSCEN=1 */
    while(0u == (IP_SCG->SOSCCSR & 0x01000000u)){};
#endif

#if (defined(S32K118))||(defined(S32K116))
    IP_SCG->RCCR=0x03000001U;
    IP_SCG->VCCR=0x02010003U;
#endif

#if defined(S32K142)||defined(S32K144)||defined(S32K144W)||defined(S32K146)||defined(S32K148)||defined(S32M244)||defined(S32M242)||defined(S32M241)||defined(S32M243)
    while(0u!=(IP_SCG->SPLLCSR & 0x00800000u)){};
    IP_SCG->SPLLCSR=0x0U;

#ifndef FIRC_ENABLE
    /* SPLL Configuration 160MHz =  PLLCLK= ((IN_CLK/(PREDIV+1))*(MULT+16))/2 */
    IP_SCG->SPLLDIV = 0x00201u;
    IP_SCG->SPLLCFG = 0x40000u;     /* SCG_SPLLCFG: MULT=4, PREDIV=0, SOURCE=0(IN_CLK=SOSC=16MHz) */
    IP_SCG->SPLLCSR=0x01;           /* SCG_SPLLCSR: SPLLEN=1 */
    while(0u == (IP_SCG->SPLLCSR & 0x01000000u)){};
#else
    IP_SCG->SPLLCFG = 0x40001u;     /* SCG_SPLLCFG: MULT=4, PREDIV=0, SOURCE=1(IN_CLK=FIRC=16MHz) */
#endif
#endif

#if defined(S32K142)||defined(S32K144)||defined(S32K144W)||defined(S32K146)||defined(S32K148)||defined(S32M244)||defined(S32M242)||defined(S32M241)||defined(S32M243)
    IP_SCG->RCCR=0x06010013U;  /* RUN Mode Configuration - DIVCORE=1(SYS_CLK=PLL/2=80MHz), DIVBUS=1(BUSCLK=SYS_CLK/2=40MHz), DIVSLOW=3(FLASHCLK=SYS_CLK/4=20MHz) */
    IP_SCG->VCCR=0x02010003U;  /* VLPR Mode Configuration */
#endif
#if defined(S32K142)||defined(S32K144)||defined(S32K146)||defined(S32K148)
    IP_SCG->HCCR=0x06010012U;  /* HSPR Mode Configuration 80MHz */
#endif
#if 0
    SMC->PMPROT = 0x80; /* Allow high speed run */
    SMC->PMCTRL = 0x60; /* Switch to high speed run */
#endif

/* disable peripherals clock */
    IP_PCC->PCCn[PCC_DMAMUX_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_FlexCAN0_INDEX] &= ~PCC_PCCn_CGC_MASK;
#if defined(S32K142)||defined(S32K144)||defined(S32K144W)||defined(S32K146)||defined(S32K148)||defined(S32M244)||defined(S32M242)||defined(S32M241)||defined(S32M243)
    IP_PCC->PCCn[PCC_FlexCAN1_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_ADC1_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_FTM2_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_FTM3_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_PDB1_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_EWM_INDEX] &= ~PCC_PCCn_CGC_MASK;
#endif
#if defined(S32K144)||defined(S32K146)||defined(S32K148)
    IP_PCC->PCCn[PCC_FlexCAN2_INDEX] &= ~PCC_PCCn_CGC_MASK;
#endif
    IP_PCC->PCCn[PCC_LPSPI0_INDEX] &= ~PCC_PCCn_CGC_MASK;
#if(!defined(S32K116))
    IP_PCC->PCCn[PCC_LPSPI1_INDEX] &= ~PCC_PCCn_CGC_MASK;
#endif
#if defined(S32K144)||defined(S32K144W)||defined(S32K146)|| defined(S32K148)||defined(S32M244)||defined(S32M243)
    IP_PCC->PCCn[PCC_LPSPI2_INDEX] &= ~PCC_PCCn_CGC_MASK;
#endif
    IP_PCC->PCCn[PCC_CRC_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_PDB0_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_LPIT_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_FTM0_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_FTM1_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_ADC0_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_RTC_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_LPTMR0_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_PORTA_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_PORTB_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_PORTC_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_PORTD_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_PORTE_INDEX] &= ~PCC_PCCn_CGC_MASK;
#if defined(S32K148)
    IP_PCC->PCCn[PCC_SAI0_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_SAI1_INDEX] &= ~PCC_PCCn_CGC_MASK;
#endif
    IP_PCC->PCCn[PCC_FlexIO_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_LPI2C0_INDEX] &= ~PCC_PCCn_CGC_MASK;
#if defined(S32K148)
    IP_PCC->PCCn[PCC_LPI2C1_INDEX] &= ~PCC_PCCn_CGC_MASK;
#endif
    IP_PCC->PCCn[PCC_LPUART0_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_LPUART1_INDEX] &= ~PCC_PCCn_CGC_MASK;
#if defined(S32K144)||defined(S32K144W)||defined(S32K146)||defined(S32K148)||defined(S32M244)||defined(S32M243)
    IP_PCC->PCCn[PCC_LPUART2_INDEX] &= ~PCC_PCCn_CGC_MASK;
#endif
#if defined(S32K146)||defined(S32K148)
    IP_PCC->PCCn[PCC_FTM4_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_FTM5_INDEX] &= ~PCC_PCCn_CGC_MASK;
#endif
#if defined(S32K148)
    IP_PCC->PCCn[PCC_FTM6_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_FTM7_INDEX] &= ~PCC_PCCn_CGC_MASK;
#endif
    IP_PCC->PCCn[PCC_CMP0_INDEX] &= ~PCC_PCCn_CGC_MASK;
#if defined(S32K148)
    IP_PCC->PCCn[PCC_QSPI_INDEX] &= ~PCC_PCCn_CGC_MASK;
    IP_PCC->PCCn[PCC_ENET_INDEX] &= ~PCC_PCCn_CGC_MASK;
#endif

    /* enable and set peripherals clock */
    IP_PCC->PCCn[PCC_DMAMUX_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_FlexCAN0_INDEX]= 0x43000000u;

#if defined(S32K142)||defined(S32K144)||defined(S32K144W)||defined(S32K146)||defined(S32K148)||defined(S32M244)||defined(S32M242)||defined(S32M241)||defined(S32M243)
    IP_PCC->PCCn[PCC_FlexCAN1_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_ADC1_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_FTM2_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_FTM3_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_PDB1_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_EWM_INDEX]= 0x43000000u;
#endif
#if defined(S32K144)||defined(S32K146)||defined(S32K148)
    IP_PCC->PCCn[PCC_FlexCAN2_INDEX]= 0x43000000u;
#endif
    IP_PCC->PCCn[PCC_LPSPI0_INDEX]= 0x43000000u;
#if(!defined(S32K116))
    IP_PCC->PCCn[PCC_LPSPI1_INDEX]= 0x43000000u;
#endif
#if defined(S32K144)||defined(S32K144W)||defined(S32K146)|| defined(S32K148)||defined(S32M244)||defined(S32M243)
    IP_PCC->PCCn[PCC_LPSPI2_INDEX]= 0x43000000u;
#endif
    IP_PCC->PCCn[PCC_CRC_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_PDB0_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_LPIT_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_FTM0_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_FTM1_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_ADC0_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_RTC_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_LPTMR0_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_PORTA_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_PORTB_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_PORTC_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_PORTD_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_PORTE_INDEX]= 0x43000000u;
#if defined(S32K148)
    IP_PCC->PCCn[PCC_SAI0_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_SAI1_INDEX]= 0x43000000u;
#endif
    IP_PCC->PCCn[PCC_FlexIO_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_LPI2C0_INDEX]= 0x43000000u;
#if defined(S32K148)
    IP_PCC->PCCn[PCC_LPI2C1_INDEX]= 0x43000000u;
#endif
    IP_PCC->PCCn[PCC_LPUART0_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_LPUART1_INDEX]= 0x43000000u;
#if defined(S32K144)||defined(S32K144W)||defined(S32K146)||defined(S32K148)||defined(S32M244)||defined(S32M243)
    IP_PCC->PCCn[PCC_LPUART2_INDEX]= 0x43000000u;
#endif
#if defined(S32K146)||defined(S32K148)
    IP_PCC->PCCn[PCC_FTM4_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_FTM5_INDEX]= 0x43000000u;
#endif
#if defined(S32K148)
    IP_PCC->PCCn[PCC_FTM6_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_FTM7_INDEX]= 0x43000000u;
#endif
    IP_PCC->PCCn[PCC_CMP0_INDEX]= 0x43000000u;
#if defined(S32K148)
    IP_PCC->PCCn[PCC_QSPI_INDEX]= 0x43000000u;
    IP_PCC->PCCn[PCC_ENET_INDEX]= 0x43000000u;
#endif

    /* Disable MPU */
    IP_MPU->CESR = 0x00815200u;

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    (void)Sys_GoToUser();
#endif
    return E_OK;
}

/*================================================================================================*/
/**
* @brief sys_halt
* @details function used to enter halt mode
*/
/*================================================================================================*/
void sys_halt(void)
{

    EXECUTE_WAIT();
}

/*================================================================================================*/
/**
* @brief sys_stop
* @details function used to enter stop mode
*/
/*================================================================================================*/
void sys_stop(void)
{
    EXECUTE_WAIT();
}

uint8 EUnit_GetCoreID(void)
{
    return OsIf_GetCoreID();
}


#ifdef __ICCARM__
    #pragma default_function_attributes =
#endif

#ifdef __cplusplus
}
#endif
