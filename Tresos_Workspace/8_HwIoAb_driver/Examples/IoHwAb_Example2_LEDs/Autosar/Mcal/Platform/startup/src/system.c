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
/*================================================================================================
*   @file    system.c
*   @version 2.0.0
*
*   @brief   AUTOSAR Platform - SYSTEM
*   @details SYSTEM
*            This file contains sample code only. It is not part of the production code deliverables.
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
#include "Platform_Types.h"
#include "Mcal.h"
#include "system.h"

#ifdef S32K116
    #include "S32K116.h"
#endif
#ifdef S32K118
    #include "S32K118.h"
#endif
#ifdef S32K142
    #include "S32K142.h"
    #define ENABLE_THREAD_MODE_ENTRY_CONFIGURATION
#endif
#ifdef S32K142W
    #include "S32K142W.h"
    #define ENABLE_THREAD_MODE_ENTRY_CONFIGURATION
#endif
#ifdef S32K144
    #include "S32K144.h"
    #define ENABLE_THREAD_MODE_ENTRY_CONFIGURATION
#endif
#ifdef S32K144W
    #include "S32K144W.h"
    #define ENABLE_THREAD_MODE_ENTRY_CONFIGURATION
#endif
#ifdef S32K146
    #include "S32K146.h"
    #define ENABLE_THREAD_MODE_ENTRY_CONFIGURATION    
#endif
#ifdef S32K148
    #include "S32K148.h"
    #define ENABLE_THREAD_MODE_ENTRY_CONFIGURATION    
#endif
#if (defined(S32M244) || defined(S32M242) || defined(S32M241) || defined(S32M243))
    #include "S32M24x.h"
    #define ENABLE_THREAD_MODE_ENTRY_CONFIGURATION
#endif

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
*                                       LOCAL MACROS
==================================================================================================*/
#define SVC_GoToSupervisor()      ASM_KEYWORD("svc 0x0")
#define SVC_GoToUser()            ASM_KEYWORD("svc 0x1")

#define S32_SCB_CPACR_CPx_MASK(CpNum)             (0x3U << S32_SCB_CPACR_CPx_SHIFT(CpNum))
#define S32_SCB_CPACR_CPx_SHIFT(CpNum)            ((uint32)(2U*((uint32)CpNum)))
#define S32_SCB_CPACR_CPx(CpNum, x)               (((uint32)(((uint32)(x))<<S32_SCB_CPACR_CPx_SHIFT((CpNum))))&S32_SCB_CPACR_CPx_MASK((CpNum)))

#define CODE_CACHE      0u

#define CACHE_OK               0u
#define CACHE_INVALID_PARAM    1u
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================-
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
/* Allocate a global variable which will be overwritten by the debugger if attached(in CMM), to catch the core after reset. */
uint32 RESET_CATCH_CORE=0x00U;

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/*  Instruction cache initialization
 *  sys_m4_cache_init(CODE_CACHE);
 */
#ifdef I_CACHE_ENABLE  
static uint8 sys_m4_cache_init(uint8 cache);
#endif
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
LOCAL_INLINE void Direct_GoToUser(void);
#endif
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/*  Instruction cache initialization
 *  sys_m4_cache_init(CODE_CACHE);
 */
#ifdef I_CACHE_ENABLE  
static uint8 sys_m4_cache_init(uint8 cache)
{
    uint8 RetValue = CACHE_OK;

  if (cache == CODE_CACHE)
  {
      /* Code Cache Init */

      /* Cache Set Command: set command bits in CCR */
      /* set invalidate way 1 and invalidate way 0 bits */
      IP_LMEM->PCCCR = 0x05000000UL;

      /* set ccr[go] bit to initiate command to invalidate cache */
      IP_LMEM->PCCCR |= LMEM_PCCCR_GO(1);

      /* wait until the ccr[go] bit clears to indicate command complete */
      while((IP_LMEM->PCCCR & LMEM_PCCCR_GO_MASK) == LMEM_PCCCR_GO_MASK){};

      /* enable cache */
      IP_LMEM->PCCCR |= LMEM_PCCCR_ENCACHE(1);
  } 
  else
  {
     RetValue = CACHE_INVALID_PARAM;
  }

  return RetValue;
}
#endif

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
LOCAL_INLINE void Direct_GoToUser(void)
{
    ASM_KEYWORD("push {r0}");
    ASM_KEYWORD("ldr r0, =0x1");
    ASM_KEYWORD("msr CONTROL, r0");
    ASM_KEYWORD("pop {r0}");
}
#endif
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT  
    extern uint32 startup_getControlRegisterValue(void);
    extern uint32 startup_getAipsRegisterValue(void);
    extern void Suspend_Interrupts(void);
    extern void Resume_Interrupts(void);
#endif /*MCAL_ENABLE_USER_MODE_SUPPORT*/


/*================================================================================================*/
/**
* @brief    startup_go_to_user_mode
* @details  Function called from startup.s to switch to user mode if MCAL_ENABLE_USER_MODE_SUPPORT
*           is defined
*/
/*================================================================================================*/
void startup_go_to_user_mode(void);
void startup_go_to_user_mode(void)
{
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    ASM_KEYWORD("svc 0x1");
#endif
}

/*================================================================================================*/
/**
* @brief   Default IRQ handler
* @details Infinite Loop
*/
/*================================================================================================*/
void default_interrupt_routine(void)
{
    while(TRUE){};
}

/*================================================================================================*/
/**
* @brief Sys_GoToSupervisor
* @details function used to enter to supervisor mode.
*           check if it's needed to switch to supervisor mode and make the switch.
*           Return 1 if switch was done
*/
/*================================================================================================*/

#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
uint32 Sys_GoToSupervisor(void)
{
    uint32 u32ControlRegValue;
    uint32 u32AipsRegValue;
    uint32 u32SwitchToSupervisor;

    /* if it's 0 then Thread mode is already in supervisor mode */
    u32ControlRegValue = startup_getControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    u32AipsRegValue = startup_getAipsRegisterValue();

    /* if core is already in supervisor mode for Thread mode, or running form Handler mode, there is no need to make the switch */
    if((0U == (u32ControlRegValue & 1u)) || (0u < (u32AipsRegValue & 0xFFu)))
    {
        u32SwitchToSupervisor = 0U;
    }
    else
    {
        u32SwitchToSupervisor = 1U;
        SVC_GoToSupervisor();
    }

    return u32SwitchToSupervisor;
}

/*================================================================================================*/
/**
* @brief Sys_GoToUser_Return
* @details function used to switch back to user mode for Thread mode, return a uint32 value passed as parameter
*/
/*================================================================================================*/
uint32 Sys_GoToUser_Return(uint32 u32SwitchToSupervisor, uint32 u32returnValue)
{
    if (1UL == u32SwitchToSupervisor)
    {
        Direct_GoToUser();
    }

    return u32returnValue;
}

uint32 Sys_GoToUser(void)
{
    Direct_GoToUser();
    return 0UL;
}

/*================================================================================================*/
/**
* @brief Sys_SuspendInterrupts
* @details Suspend Interrupts
*/
/*================================================================================================*/
void Sys_SuspendInterrupts(void)
{
    uint32 u32ControlRegValue;
    uint32 u32AipsRegValue;

    /* if it's 0 then Thread mode is already in supervisor mode */
    u32ControlRegValue = startup_getControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    u32AipsRegValue = startup_getAipsRegisterValue();

    if((0U == (u32ControlRegValue & 1u)) || (0u < (u32AipsRegValue & 0xFFu)))
    {
        Suspend_Interrupts();
    }
    else
    {
        ASM_KEYWORD(" svc 0x3");
    }
}


/*================================================================================================*/
/**
* @brief Sys_ResumeInterrupts
* @details Resume Interrupts
*/
/*================================================================================================*/
void Sys_ResumeInterrupts(void)
{
    uint32 u32ControlRegValue;
    uint32 u32AipsRegValue;

    /* if it's 0 then Thread mode is already in supervisor mode */
    u32ControlRegValue = startup_getControlRegisterValue();
    /* if it's 0 the core is in Thread mode, otherwise in Handler mode */
    u32AipsRegValue = startup_getAipsRegisterValue();

    if((0U == (u32ControlRegValue & 1u)) || (0u < (u32AipsRegValue & 0xFFu)))
    {
        Resume_Interrupts();
    }
    else
    {
        ASM_KEYWORD(" svc 0x2");
    }
}
#endif


/*================================================================================================*/
/**
* @brief Sys_GetCoreID
* @details Function used to get the ID of the currently executing thread
*/
/*================================================================================================*/
#if !defined(USING_OS_AUTOSAROS)
uint8 Sys_GetCoreID(void)
{
    return 0U;
}
#endif

/*================================================================================================*/
/*
 * system initialization : system clock, interrupt router ...
 */
#ifdef __ICCARM__ 
    #pragma default_function_attributes = @ ".systeminit"
#else
    __attribute__ ((section (".systeminit")))
#endif 

void SystemInit(void)
{
/**************************************************************************/
                      /* FPU ENABLE*/
/**************************************************************************/
#ifdef ENABLE_FPU
    /* Enable CP10 and CP11 coprocessors */
    S32_SCB->CPACR |= (S32_SCB_CPACR_CPx(10U, 3U) | S32_SCB_CPACR_CPx(11U, 3U)); 

    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");
#endif /* ENABLE_FPU */

#ifdef ENABLE_THREAD_MODE_ENTRY_CONFIGURATION
    S32_SCB->CCR    |=  1u;       /**< processor can enter Thread mode from any level under the 
                                   control of an EXC_RETURN value, PendSV priority set to 0*/
#endif
    S32_SCB->SHPR3 &= ~S32_SCB_SHPR3_PRI_14_MASK; 
    
    /* enable the AIPS */
    IP_AIPS->MPRA = 0x77777777;      
    IP_AIPS->PACRA  = 0x0; 
    IP_AIPS->PACRB  = 0x0; 
    IP_AIPS->PACRD  = 0x0;
    IP_AIPS->OPACR[0] = 0x0; 
    IP_AIPS->OPACR[1] = 0x0; 
    IP_AIPS->OPACR[2] = 0x0; 
    IP_AIPS->OPACR[3] = 0x0; 
    IP_AIPS->OPACR[4] = 0x0; 
    IP_AIPS->OPACR[5] = 0x0; 
    IP_AIPS->OPACR[6] = 0x0; 
    IP_AIPS->OPACR[7] = 0x0; 
    IP_AIPS->OPACR[8] = 0x0; 
    IP_AIPS->OPACR[9] = 0x0; 
    IP_AIPS->OPACR[10] = 0x0;
    IP_AIPS->OPACR[11] = 0x0;

/**************************************************************************/
                      /* DEFAULT MEMORY ENABLE*/
/**************************************************************************/
    ASM_KEYWORD("dsb");
    ASM_KEYWORD("isb");

#ifdef I_CACHE_ENABLE  
/**************************************************************************/
            /* ENABLE CACHE */
/**************************************************************************/
    (void)sys_m4_cache_init(CODE_CACHE);    
#endif
}

#ifdef __ICCARM__ 
    #pragma default_function_attributes =
#endif

#ifdef __cplusplus
}
#endif
