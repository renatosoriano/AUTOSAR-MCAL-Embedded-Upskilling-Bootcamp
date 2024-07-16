/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : S32K14X
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 2.0.0
* Build Version : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
* Copyright 2020-2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

/**
*   @file
*
*   @addtogroup osif_drv
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "OsIf_DeviceRegisters.h"
#include "OsIf_Cfg.h"
#include "OsIf_Timer_System_Internal_Systick.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_VENDOR_ID_C                    43
#define OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_MAJOR_VERSION_C     4
#define OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_MINOR_VERSION_C     7
#define OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_REVISION_VERSION_C  0
#define OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_MAJOR_VERSION_C             2
#define OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_MINOR_VERSION_C             0
#define OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if OsIf_Timer_System_Internal_Systick.c file and OsIf_DeviceRegisters.h file are of the same vendor */
#if (OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_VENDOR_ID_C != OSIF_DEVICE_REGISTERS_VENDOR_ID)
    #error "OsIf_Timer_System_Internal_Systick.c and OsIf_DeviceRegisters.h have different vendor ids"
#endif
/* Check if OsIf_Timer_System_Internal_Systick.c file and OsIf_DeviceRegisters.h file are of the same Autosar version */
#if ((OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_MAJOR_VERSION_C    != OSIF_DEVICE_REGISTERS_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_MINOR_VERSION_C    != OSIF_DEVICE_REGISTERS_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_REVISION_VERSION_C != OSIF_DEVICE_REGISTERS_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Timer_System_Internal_Systick.c and OsIf_DeviceRegisters.h are different"
#endif
/* Check if OsIf_Timer_System_Internal_Systick.c file and OsIf_DeviceRegisters.h file are of the same Software version */
#if ((OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_MAJOR_VERSION_C != OSIF_DEVICE_REGISTERS_SW_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_MINOR_VERSION_C != OSIF_DEVICE_REGISTERS_SW_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_PATCH_VERSION_C != OSIF_DEVICE_REGISTERS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Timer_System_Internal_Systick.c and OsIf_DeviceRegisters.h are different"
#endif

/* Check if OsIf_Timer_System_Internal_Systick.c file and OsIf_Cfg.h file are of the same vendor */
#if (OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_VENDOR_ID_C != OSIF_CFG_VENDOR_ID)
    #error "OsIf_Timer_System_Internal_Systick.c and OsIf_Cfg.h have different vendor ids"
#endif
/* Check if OsIf_Timer_System_Internal_Systick.c file and OsIf_Cfg.h file are of the same Autosar version */
#if ((OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_MAJOR_VERSION_C    != OSIF_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_MINOR_VERSION_C    != OSIF_CFG_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_REVISION_VERSION_C != OSIF_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Timer_System_Internal_Systick.c and OsIf_Cfg.h are different"
#endif
/* Check if OsIf_Timer_System_Internal_Systick.c file and OsIf_Cfg.h file are of the same Software version */
#if ((OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_MAJOR_VERSION_C != OSIF_CFG_SW_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_MINOR_VERSION_C != OSIF_CFG_SW_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_PATCH_VERSION_C != OSIF_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Timer_System_Internal_Systick.c and OsIf_Cfg.h are different"
#endif

/* Check if OsIf_Timer_System_Internal_Systick.c file and OsIf_Timer_System_Internal_Systick.h file are of the same vendor */
#if (OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_VENDOR_ID_C != OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_VENDOR_ID)
    #error "OsIf_Timer_System_Internal_Systick.c and OsIf_Timer_System_Internal_Systick.h have different vendor ids"
#endif
/* Check if OsIf_Timer_System_Internal_Systick.c file and OsIf_Timer_System_Internal_Systick.h file are of the same Autosar version */
#if ((OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_MAJOR_VERSION_C    != OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_MINOR_VERSION_C    != OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_REVISION_VERSION_C != OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_AR_RELEASE_REVISION_VERSION))
    #error "AUTOSAR Version Numbers of OsIf_Timer_System_Internal_Systick.c and OsIf_Timer_System_Internal_Systick.h are different"
#endif
/* Check if OsIf_Timer_System_Internal_Systick.c file and OsIf_Timer_System_Internal_Systick.h file are of the same Software version */
#if ((OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_MAJOR_VERSION_C != OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_MAJOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_MINOR_VERSION_C != OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_MINOR_VERSION) || \
     (OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_PATCH_VERSION_C != OSIF_TIMER_SYSTEM_INTERNAL_SYSTICK_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of OsIf_Timer_System_Internal_Systick.c and OsIf_Timer_System_Internal_Systick.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                          LOCAL MACROS
==================================================================================================*/
#if defined(OSIF_USE_SYSTICK)
#if (OSIF_USE_SYSTICK == STD_ON)

#define SYSTICK_GET_COUNTER() ((S32_SysTick->CVR) & S32_SysTick_CVR_CURRENT_MASK)
#define SYSTICK_DELTA_OUTER(high, low, max) ((max) - ((high) - (low)))
#define SYSTICK_DELTA_INNER(high, low) ((high) - (low))
#define SYSTICK_MAX (0xFFFFFFU)

#define SYSTICK_OVERFLOWED(curr, ref) (curr > ref)
/*==================================================================================================
*                                         LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                         LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define BASENXP_START_SEC_CODE
#include "BaseNXP_MemMap.h"

/*FUNCTION**********************************************************************
 *
 * Function Name : OsIf_Timer_System_Internal_Init.
 * Description   : Initialize systick timer.
 * 
 *END**************************************************************************/
void OsIf_Timer_System_Internal_Init(uint32 SystemCounterFreq)
{
    (void)SystemCounterFreq;

    /* For Cortex-M0 devices the systick counter is initialized with an undefined
     value, so make sure to initialize it to 0 before starting */
    S32_SysTick->CSRr = S32_SysTick_CSR_ENABLE(0u);
    S32_SysTick->RVR = S32_SysTick_RVR_RELOAD(SYSTICK_MAX);
    S32_SysTick->CVR = S32_SysTick_CVR_CURRENT(0U);
    S32_SysTick->CSRr = S32_SysTick_CSR_ENABLE(1u) | S32_SysTick_CSR_TICKINT(0u) | S32_SysTick_CSR_CLKSOURCE(1u);
}

/*FUNCTION**********************************************************************
 *
 * Function Name : OsIf_Timer_System_Internal_GetCounter.
 * Description   : Get systick counter value.
 * 
 *END**************************************************************************/
uint32 OsIf_Timer_System_Internal_GetCounter(void)
{
    return SYSTICK_GET_COUNTER();
}

/*FUNCTION**********************************************************************
 *
 * Function Name : OsIf_Timer_System_Internal_GetElapsed.
 * Description   : Get systick elapsed value.
 * 
 *END**************************************************************************/
uint32 OsIf_Timer_System_Internal_GetElapsed(uint32 * const CurrentRef)
{
    uint32 CurrentVal = SYSTICK_GET_COUNTER();
    uint32 dif = 0U;

    if (SYSTICK_OVERFLOWED((CurrentVal), (*CurrentRef)))
    {
        /* overflow occurred */
        dif = SYSTICK_DELTA_OUTER(CurrentVal, *CurrentRef, SYSTICK_MAX);
    }
    else
    {
        /* overflow did not occur */
        dif = SYSTICK_DELTA_INNER(*CurrentRef, CurrentVal);
    }
    *CurrentRef = CurrentVal;

    return dif;
}

#define BASENXP_STOP_SEC_CODE
#include "BaseNXP_MemMap.h"

#endif /* (OSIF_USE_SYSTICK == STD_ON) */
#endif /* defined(OSIF_USE_SYSTICK) */

#ifdef __cplusplus
}
#endif

/** @} */
