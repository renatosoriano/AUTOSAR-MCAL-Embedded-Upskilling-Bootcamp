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
*   @file       Power_Ip_RCM.c
*   @version    2.0.0
*
*   @brief
*   @brief   POWER driver implementations.
*   @details POWER driver implementations.
*
*   @addtogroup POWER_DRIVER Power Ip Driver
*   @{
*/


#ifdef __cplusplus
extern "C"
{
#endif



/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_RCM.h"
#include "Power_Ip_Private.h"

#if (defined(POWER_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT))
  #if (defined(MCAL_RCM_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_RCM_REG_PROT_AVAILABLE)
      #define USER_MODE_REG_PROT_ENABLED      (STD_ON)
      #include "RegLockMacros.h"
    #endif /* (STD_ON == MCAL_RCM_REG_PROT_AVAILABLE) */
  #endif
#endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_RCM_VENDOR_ID_C                      43
#define POWER_IP_RCM_AR_RELEASE_MAJOR_VERSION_C       4
#define POWER_IP_RCM_AR_RELEASE_MINOR_VERSION_C       7
#define POWER_IP_RCM_AR_RELEASE_REVISION_VERSION_C    0
#define POWER_IP_RCM_SW_MAJOR_VERSION_C               2
#define POWER_IP_RCM_SW_MINOR_VERSION_C               0
#define POWER_IP_RCM_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Power_Ip_RCM header file are of the same Autosar version */
#if (POWER_IP_RCM_VENDOR_ID_C != POWER_IP_RCM_VENDOR_ID)
    #error "Power_Ip_RCM.c and Power_Ip_RCM.h have different vendor ids"
#endif
/* Check if current file and Power_Ip_RCM header file are of the same Autosar version */
#if ((POWER_IP_RCM_AR_RELEASE_MAJOR_VERSION_C    != POWER_IP_RCM_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_RCM_AR_RELEASE_MINOR_VERSION_C    != POWER_IP_RCM_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_RCM_AR_RELEASE_REVISION_VERSION_C != POWER_IP_RCM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_RCM.c and Power_Ip_RCM.h are different"
#endif
/* Check if current file and Power_Ip_RCM header file are of the same Software version */
#if ((POWER_IP_RCM_SW_MAJOR_VERSION_C != POWER_IP_RCM_SW_MAJOR_VERSION) || \
     (POWER_IP_RCM_SW_MINOR_VERSION_C != POWER_IP_RCM_SW_MINOR_VERSION) || \
     (POWER_IP_RCM_SW_PATCH_VERSION_C != POWER_IP_RCM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_RCM.c and Power_Ip_RCM.h are different"
#endif

/* Check if current file and Power_Ip_Private header file are of the same Autosar version */
#if (POWER_IP_RCM_VENDOR_ID_C != POWER_IP_PRIVATE_VENDOR_ID)
    #error "Power_Ip_RCM.c and Power_Ip_Private.h have different vendor ids"
#endif
/* Check if current file and Power_Ip_Private header file are of the same Autosar version */
#if ((POWER_IP_RCM_AR_RELEASE_MAJOR_VERSION_C    != POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_RCM_AR_RELEASE_MINOR_VERSION_C    != POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_RCM_AR_RELEASE_REVISION_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_RCM.c and Power_Ip_Private.h are different"
#endif
/* Check if current file and Power_Ip_Private header file are of the same Software version */
#if ((POWER_IP_RCM_SW_MAJOR_VERSION_C != POWER_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (POWER_IP_RCM_SW_MINOR_VERSION_C != POWER_IP_PRIVATE_SW_MINOR_VERSION) || \
     (POWER_IP_RCM_SW_PATCH_VERSION_C != POWER_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_RCM.c and Power_Ip_Private.h are different"
#endif

#if (defined(POWER_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT))
  #if (defined(MCAL_RCM_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_RCM_REG_PROT_AVAILABLE)
        #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if Power_Ip_RCM.c file and RegLockMacros.h file are of the same Autosar version */
            #if ((POWER_IP_RCM_AR_RELEASE_MAJOR_VERSION_C    != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
                (POWER_IP_RCM_AR_RELEASE_MINOR_VERSION_C    != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of Power_Ip_RCM.c and RegLockMacros.h are different"
            #endif
        #endif
    #endif /* (STD_ON == MCAL_RCM_REG_PROT_AVAILABLE) */
  #endif
#endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#define MCU_START_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"


static uint32 Power_Ip_u32ResetStatus;

#define MCU_STOP_SEC_VAR_CLEARED_32
#include "Mcu_MemMap.h"

#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"

#if (defined(POWER_IP_RESET_ALTERNATE_ISR_USED) && (POWER_IP_RESET_ALTERNATE_ISR_USED == STD_ON))
static volatile Power_Ip_RCM_StatusType Power_Ip_RCM_Status = POWER_IP_RCM_UNINIT;
#endif

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if (defined(POWER_IP_DISABLE_RCM_INIT) && (STD_OFF == POWER_IP_DISABLE_RCM_INIT))
/**
* @brief            This function initializes the Reset parameters.
* @details          Conigures the threshold reset value.
*                   Called by:
*                       - Mcu_IPW_Init() from IPW.
*
* @param[in]        ConfigPtr   Pointer to the RCM configuration structure.
*
* @return           void
*
*/
void Power_Ip_RCM_ResetInit(const Power_Ip_RCM_ConfigType * ConfigPtr)
{
    IP_RCM->RPC = (uint32)(ConfigPtr->ResetPinControlConfig & RCM_RPC_RWBITS_MASK32);

    IP_RCM->SRIE = (uint32)(ConfigPtr->ResetInterruptEnableConfig & RCM_SRIE_RWBITS_MASK32);
#if (defined(POWER_IP_RESET_ALTERNATE_ISR_USED) && (POWER_IP_RESET_ALTERNATE_ISR_USED == STD_ON))
    Power_Ip_RCM_Status = POWER_IP_RCM_INIT;
#endif
}
#endif

/**
* @brief            This function returns the Reset reason.
* @details          This routine returns the Reset reason that is read from the hardware.
*                   Called by:
*                       - Mcu_IPW_GetResetReason() from IPW.
*
* @return           Reason of the Reset event.
*
* @note             The User should ensure that the reset reason is cleared once it has been read
*                   out to avoid multiple reset reasons. The function Mcu_GetResetReason shall
*                   return MCU_RESET_UNDEFINED if this function is called prior to calling of the
*                   function Mcu_Init, and if supported by the hardware.
*/
uint32 Power_Ip_RCM_GetResetReason(void)
{
    /* Code for the Reset event returned by this function. */
    uint32 ResetReason = (uint32)MCU_NO_RESET_REASON;
    /* Temporary variable for RCM_RSR register value. */
    uint32 RegValue = 0U;
    uint32 ActiveValue;
    uint32 Index;
    uint32 DynamicMask;
    uint32 Position = (uint32)0x00U;
    uint32 NumberOfFlags = 0U;

    /* Check reset reasons from SSRS Status Register. */
    RegValue = (uint32) IP_RCM->SSRS & RCM_SSRS_RWBITS_MASK32;

    /* Store the content of RSR */
    if ((uint32)0U != RegValue)
    {
        /* Clear the flags if any flag is set */
        IP_RCM->SSRS = (uint32)(RegValue & RCM_SSRS_RWBITS_MASK32);

        Power_Ip_u32ResetStatus = RegValue;
    }
    ActiveValue = Power_Ip_u32ResetStatus;

    if((RCM_SSRS_SLVD_MASK | RCM_SSRS_SPOR_MASK) == (ActiveValue & RCM_SSRS_RWBITS_MASK32))
    {
        ResetReason = (uint32)MCU_POWER_ON_RESET;
    }
    else
    {
        for (Index = 0x00U; Index < 0x20U; Index++)
        {
            DynamicMask = ((uint32)0x80000000U >> Index);
            if ((uint32)0x00U != (DynamicMask & RCM_SSRS_RESET_SOURCES_MASK32))
            {
                if ((uint32)0x00U != (DynamicMask & ActiveValue))
                {
                    ResetReason = Position;
                    NumberOfFlags++;
                    /* MCU_MULTIPLE_RESET_REASON returned if more than one reset reason in this case use function Mcu_GetRawValue to determine. */
                    if (NumberOfFlags >= (uint32)2)
                    {
                        ResetReason = (uint32)MCU_MULTIPLE_RESET_REASON;
                        break;
                    }
                }
                Position++;
            }
        }
    }
    return ResetReason;
}

/**
* @brief            This function returns the Raw Reset value.
* @details          This routine returns the Raw Reset value that is read from the hardware.
*                   Called by:
*                       - Mcu_IPW_GetResetRawValue() from IPW.
*
* @return           Register value with the Reset status.
* @retval           uint32   Code of the Raw reset value.
*
* @note             The User should ensure that the reset reason is cleared once it has been read
*                   out to avoid multiple reset reasons.
*
*/
Power_Ip_RawResetType Power_Ip_RCM_GetResetRawValue(void)
{
    uint32 RawReset;
    uint32 RegValue;

    RegValue = IP_RCM->SSRS & RCM_SSRS_RWBITS_MASK32;

    if ((uint32)0U != RegValue)
    {
        /* Clear the flags if any flag is set */
        IP_RCM->SSRS = (uint32)(RegValue & RCM_SSRS_RWBITS_MASK32);

        Power_Ip_u32ResetStatus = RegValue;
    }

    RawReset = Power_Ip_u32ResetStatus;

    return (Power_Ip_RawResetType)RawReset;
}

#if (defined(POWER_IP_RESET_ALTERNATE_ISR_USED) && (POWER_IP_RESET_ALTERNATE_ISR_USED == STD_ON))
/**
* @brief            This function handles the Reset Alternate Event Interrupts.
* @details          Only the following reset events support interrupt reaction:
*                       - SACKERR (Stop Acknowledge Error)
*                       - MDM_AP (MDP-AP System Reset Request)
*                       - SW (Software Reset)
*                       - LOCKUP (Core Lockup)
*                       - JTAG (JTAG Generated Reset)
*                       - GIE (Global Interrupt Enable)
*                       - PIN (External Reset Pin)
*                       - WDOG (Watchdog)
*                       - CMU_LOC (CMU Loss-Of-Clock)
*                       - LOL (Loss-Of-Lock)
*                       - LOC (Loss-Of-Clock)
*
* @return           void
* @implements Power_Ip_RCM_ResetAltInt_Activity
*/
void Power_Ip_RCM_ResetAltInt(void)
{
    uint32 ResetInterruptStatus = 0U;
    uint32 ResetInterruptEnable = 0U;

    if (POWER_IP_RCM_UNINIT != Power_Ip_RCM_Status)
    {
        /* Read Sticky System Reset Status */
        ResetInterruptStatus = (uint32)(IP_RCM->SSRS & RCM_SSRS_RWBITS_MASK32);
        
        /* Read System Reset Interrupt Enable */
        ResetInterruptEnable = (uint32)(IP_RCM->SRIE & RCM_SRIE_RWBITS_MASK32);
        
        if ( (uint32)0U != (ResetInterruptStatus & ResetInterruptEnable))
        {
            /* Clear the status flags */
            IP_RCM->SSRS = ResetInterruptStatus;
#ifdef POWER_IP_ERROR_ISR_NOTIFICATION
            POWER_IP_ERROR_ISR_NOTIFICATION(POWER_IP_E_ISR_RESET_ALT_FAILURE);
#else
            Power_Ip_ReportPowerErrors(POWER_IP_ISR_ERROR, POWER_IP_E_ISR_RESET_ALT_FAILURE);
#endif
        }
    }
    else
    {
        /* Clear the status flags */
        IP_RCM->SSRS = ResetInterruptStatus;
    }
}
#endif /* ( POWER_IP_RESET_ALTERNATE_ISR_USED == STD_ON ) */

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
