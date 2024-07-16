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
==================================================================================================*/
/**
*   @file       Power_Ip_CotexM4.c
*   @version    2.0.0
*
*   @brief   POWER driver implementations.
*   @details POWER driver implementations.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_CortexM4.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_CORTEXM4_VENDOR_ID_C                      43
#define POWER_IP_CORTEXM4_AR_RELEASE_MAJOR_VERSION_C       4
#define POWER_IP_CORTEXM4_AR_RELEASE_MINOR_VERSION_C       7
#define POWER_IP_CORTEXM4_AR_RELEASE_REVISION_VERSION_C    0
#define POWER_IP_CORTEXM4_SW_MAJOR_VERSION_C               2
#define POWER_IP_CORTEXM4_SW_MINOR_VERSION_C               0
#define POWER_IP_CORTEXM4_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_CortexM4.c file and Power_Ip_CortexM4.h file are of the same vendor */
#if (POWER_IP_CORTEXM4_VENDOR_ID_C != POWER_IP_CORTEXM4_VENDOR_ID)
    #error "Power_Ip_CortexM4.c and Power_Ip_CortexM4.h have different vendor ids"
#endif

/* Check if Power_Ip_CortexM4.c file and Power_Ip_CortexM4.h file are of the same Autosar version */
#if ((POWER_IP_CORTEXM4_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_CORTEXM4_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_CORTEXM4_AR_RELEASE_MINOR_VERSION_C != POWER_IP_CORTEXM4_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_CORTEXM4_AR_RELEASE_REVISION_VERSION_C != POWER_IP_CORTEXM4_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_CortexM4.c and Power_Ip_CortexM4.h are different"
#endif

/* Check if Power_Ip_CortexM4.c file and Power_Ip_CortexM4.h file are of the same Software version */
#if ((POWER_IP_CORTEXM4_SW_MAJOR_VERSION_C != POWER_IP_CORTEXM4_SW_MAJOR_VERSION) || \
     (POWER_IP_CORTEXM4_SW_MINOR_VERSION_C != POWER_IP_CORTEXM4_SW_MINOR_VERSION) || \
     (POWER_IP_CORTEXM4_SW_PATCH_VERSION_C != POWER_IP_CORTEXM4_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_CortexM4.c and Power_Ip_CortexM4.h are different"
#endif
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

static Power_Ip_CM4_Type * Power_Ip_pxCM4 = (Power_Ip_CM4_Type *)CM4_AIRCR_BASEADDR;

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                     LOCAL FUNCTION
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

#if (POWER_IP_PERFORM_RESET_API == STD_ON)
 /**
* @brief        The function initiates a system reset request to reset the SoC.
* @details      The function initiates a system reset request to reset the SoC
*
* @param[in]    none
*
* @return void
*
*/
void Power_Ip_CM4_SystemReset(void)
{
    uint32 TmpValue;

    TmpValue = (Power_Ip_pxCM4->AIRCR) & (uint32)CM4_AIRCR_PRIGROUP_MASK;
    TmpValue |= (uint32)CM4_AIRCR_SYSRESETREQ_MASK;
    TmpValue |= (uint32)CM4_AIRCR_VECTKEY(0x5FAU);

    ASM_KEYWORD(" dsb");               /* All memory accesses have to be completed before reset */
    Power_Ip_pxCM4->AIRCR = TmpValue;
    ASM_KEYWORD(" dsb");               /* All memory accesses have to be completed */
}

#endif

#ifdef POWER_IP_SLEEPONEXIT_SUPPORT
#if (POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON)
 /**
* @brief        The function disable SLEEPONEXIT bit.
* @details      The function disable SLEEPONEXIT bit.
*
* @param[in]    none
*
* @return void
*/
void Power_Ip_CM4_DisableSleepOnExit(void)
{
    uint32 TempValue = 0;

    TempValue = Power_Ip_pxCM4->SCR;
    TempValue &= ~(CM4_SCR_SLEEPONEXIT_MASK32);
    Power_Ip_pxCM4->SCR = TempValue;
}
#endif
#endif


#ifdef POWER_IP_SLEEPONEXIT_SUPPORT
#if (POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON)
 /**
* @brief        The function enable SLEEPONEXIT bit.
* @details      The function enable SLEEPONEXIT bit.
*
* @param[in]    none
*
* @return void
*/
void Power_Ip_CM4_EnableSleepOnExit(void)
{
    uint32 TempValue = 0;

    TempValue = Power_Ip_pxCM4->SCR;
    TempValue |= (CM4_SCR_SLEEPONEXIT_MASK32);
    Power_Ip_pxCM4->SCR = TempValue;
}
#endif
#endif


/**
* @brief        The function enables DEEPSLEEP.
* @details      The function enables DEEPSLEEP.
*
* @param[in]    none
*
* @return void
*/
void Power_Ip_CM4_EnableDeepSleep(void)
{
    uint32 TempValue = 0;

    TempValue = Power_Ip_pxCM4->SCR;
    TempValue |= CM4_SCR_SLEEPDEEP_MASK32;
    Power_Ip_pxCM4->SCR = TempValue;
}


/**
* @brief        The function disables DEEPSLEEP.
* @details      The function disables DEEPSLEEP.
*
* @param[in]    none
*
* @return void
*/
void Power_Ip_CM4_DisableDeepSleep(void)
{
    uint32 TempValue = 0;

    TempValue = Power_Ip_pxCM4->SCR;
    TempValue &= ~(CM4_SCR_SLEEPDEEP_MASK32);
    Power_Ip_pxCM4->SCR = TempValue;
}


#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
