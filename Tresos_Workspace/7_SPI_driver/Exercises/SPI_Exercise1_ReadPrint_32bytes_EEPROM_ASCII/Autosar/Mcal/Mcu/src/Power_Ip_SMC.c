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
*   @file       Power_Ip_SMC.c
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
extern "C"{
#endif





/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Power_Ip_SMC.h"
#include "Power_Ip_CortexM4.h"
#include "Power_Ip_Private.h"

#if (defined(POWER_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT))
  #if (defined(MCAL_SMC_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_SMC_REG_PROT_AVAILABLE)
      #define USER_MODE_REG_PROT_ENABLED      (STD_ON)
      #include "RegLockMacros.h"
    #endif /* (STD_ON == MCAL_PMC_REG_PROT_AVAILABLE) */
  #endif
#endif /* (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT) */


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define POWER_IP_SMC_VENDOR_ID_C                      43
#define POWER_IP_SMC_AR_RELEASE_MAJOR_VERSION_C       4
#define POWER_IP_SMC_AR_RELEASE_MINOR_VERSION_C       7
#define POWER_IP_SMC_AR_RELEASE_REVISION_VERSION_C    0
#define POWER_IP_SMC_SW_MAJOR_VERSION_C               2
#define POWER_IP_SMC_SW_MINOR_VERSION_C               0
#define POWER_IP_SMC_SW_PATCH_VERSION_C               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_SMC.c file and Power_Ip_SMC.h file are of the same vendor */
#if (POWER_IP_SMC_VENDOR_ID_C != POWER_IP_SMC_VENDOR_ID)
    #error "Power_Ip_SMC.c and Power_Ip_SMC.h have different vendor ids"
#endif

/* Check if Power_Ip_SMC.c file and Power_Ip_SMC.h file are of the same Autosar version */
#if ((POWER_IP_SMC_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_SMC_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_SMC_AR_RELEASE_MINOR_VERSION_C != POWER_IP_SMC_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_SMC_AR_RELEASE_REVISION_VERSION_C != POWER_IP_SMC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_SMC.c and Power_Ip_SMC.h are different"
#endif

/* Check if Power_Ip_SMC.c file and Power_Ip_SMC.h file are of the same Software version */
#if ((POWER_IP_SMC_SW_MAJOR_VERSION_C != POWER_IP_SMC_SW_MAJOR_VERSION) || \
     (POWER_IP_SMC_SW_MINOR_VERSION_C != POWER_IP_SMC_SW_MINOR_VERSION) || \
     (POWER_IP_SMC_SW_PATCH_VERSION_C != POWER_IP_SMC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_SMC.c and Power_Ip_SMC.h are different"
#endif

/* Check if Power_Ip_SMC.c file and Power_Ip_Private.h file are of the same vendor */
#if (POWER_IP_SMC_VENDOR_ID_C != POWER_IP_PRIVATE_VENDOR_ID)
    #error "Power_Ip_SMC.c and Power_Ip_Private.h have different vendor ids"
#endif

/* Check if Power_Ip_SMC.c file and Power_Ip_Private.h file are of the same Autosar version */
#if ((POWER_IP_SMC_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_SMC_AR_RELEASE_MINOR_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_SMC_AR_RELEASE_REVISION_VERSION_C != POWER_IP_PRIVATE_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_SMC.c and Power_Ip_Private.h are different"
#endif

/* Check if Power_Ip_SMC.c file and Power_Ip_Private.h file are of the same Software version */
#if ((POWER_IP_SMC_SW_MAJOR_VERSION_C != POWER_IP_PRIVATE_SW_MAJOR_VERSION) || \
     (POWER_IP_SMC_SW_MINOR_VERSION_C != POWER_IP_PRIVATE_SW_MINOR_VERSION) || \
     (POWER_IP_SMC_SW_PATCH_VERSION_C != POWER_IP_PRIVATE_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_SMC.c and Power_Ip_Private.h are different"
#endif

/* Check if Power_Ip_SMC.c file and Power_Ip_CortexM4.h file are of the same vendor */
#if (POWER_IP_SMC_VENDOR_ID_C != POWER_IP_CORTEXM4_VENDOR_ID)
    #error "Power_Ip_SMC.c and Power_Ip_CortexM4.h have different vendor ids"
#endif

/* Check if Power_Ip_SMC.c file and Power_Ip_CortexM4.h file are of the same Autosar version */
#if ((POWER_IP_SMC_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_CORTEXM4_AR_RELEASE_MAJOR_VERSION) || \
     (POWER_IP_SMC_AR_RELEASE_MINOR_VERSION_C != POWER_IP_CORTEXM4_AR_RELEASE_MINOR_VERSION) || \
     (POWER_IP_SMC_AR_RELEASE_REVISION_VERSION_C != POWER_IP_CORTEXM4_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_SMC.c and Power_Ip_CortexM4.h are different"
#endif

/* Check if Power_Ip_SMC.c file and Power_Ip_CortexM4.h file are of the same Software version */
#if ((POWER_IP_SMC_SW_MAJOR_VERSION_C != POWER_IP_CORTEXM4_SW_MAJOR_VERSION) || \
     (POWER_IP_SMC_SW_MINOR_VERSION_C != POWER_IP_CORTEXM4_SW_MINOR_VERSION) || \
     (POWER_IP_SMC_SW_PATCH_VERSION_C != POWER_IP_CORTEXM4_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_SMC.c and Power_Ip_CortexM4.h are different"
#endif

#if (defined(POWER_IP_ENABLE_USER_MODE_SUPPORT) && (STD_ON == POWER_IP_ENABLE_USER_MODE_SUPPORT))
  #if (defined(MCAL_SMC_REG_PROT_AVAILABLE))
    #if (STD_ON == MCAL_SMC_REG_PROT_AVAILABLE)
        #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
        /* Check if SMC.c file and RegLockMacros.h file are of the same Autosar version */
            #if ((POWER_IP_SMC_AR_RELEASE_MAJOR_VERSION_C    != REGLOCKMACROS_AR_RELEASE_MAJOR_VERSION) || \
                (POWER_IP_SMC_AR_RELEASE_MINOR_VERSION_C    != REGLOCKMACROS_AR_RELEASE_MINOR_VERSION))
                #error "AutoSar Version Numbers of SMC.c and RegLockMacros.h are different"
            #endif
        #endif
    #endif /* (STD_ON == MCAL_SMC_REG_PROT_AVAILABLE) */
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

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE

#include "Mcu_MemMap.h"

#ifdef POWER_IP_VLPSA_NOTIFICATION

static Power_Ip_SMC_VLPSA_StatusType Power_Ip_SMC_Get_VLPSA_Status(void);

#endif

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (defined(POWER_IP_DISABLE_SMC_INIT) && (STD_OFF == POWER_IP_DISABLE_SMC_INIT))
/**
* @brief            This function will configure the allowed modes
*
* @details          This function is only called at Mcu initialization
*
*/
void Power_Ip_SMC_AllowedModesConfig(const Power_Ip_SMC_ConfigType * ConfigPtr)
{
    IP_SMC->PMPROT = ConfigPtr->AllowedModes & SMC_PMPROT_RWBITS_MASK32;
}
#endif
/**
* @brief            This function check the mode invalid before swith mode.
* @details          This function check the current mode with previous mode.
*
*                   Called by:
*                       - Power_Ip_SetMode() from Power_Ip.
*
* @param[in]        PowerMode   Mode from configuration structure.
*
* @return           Power_Ip_SMC_ModeStatusType
*
*/
Power_Ip_SMC_ModeStatusType Power_Ip_SMC_ModeCheckEntry(Power_Ip_PowerModeType PowerMode)
{
    Power_Ip_SMC_ModeStatusType PowerModeCheck = POWER_IP_MODE_NOT_OK;
    /* Contains the code of the Power Mode (based PowerModeType enumeration). */
    uint32 CurrentPowerMode;

    CurrentPowerMode = IP_SMC->PMSTAT & SMC_PMSTAT_PMSTAT_MASK;

    switch (PowerMode)
    {
        case (POWER_IP_RUN_MODE):
        {
            PowerModeCheck = POWER_IP_MODE_OK;
            break;
        }
        case (POWER_IP_HSRUN_MODE):
        {
            if (SMC_PMSTAT_RUN_U32 == CurrentPowerMode)
            {
                PowerModeCheck = POWER_IP_MODE_OK;
            }
            break;
        }
        case (POWER_IP_VLPR_MODE):
        {
            if ((SMC_PMSTAT_RUN_U32 == CurrentPowerMode) || (SMC_PMSTAT_VLPS_U32 == CurrentPowerMode))
            {
                PowerModeCheck = POWER_IP_MODE_OK;
            }
            break;
        }

#if (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON)
        case (POWER_IP_VLPS_MODE):
        {
            if ((SMC_PMSTAT_RUN_U32 == CurrentPowerMode) || (SMC_PMSTAT_VLPR_U32 == CurrentPowerMode))
            {
                PowerModeCheck = POWER_IP_MODE_OK;
            }
            break;
        }
        case (POWER_IP_STOP1_MODE):
        {
            if (SMC_PMSTAT_RUN_U32 == CurrentPowerMode)
            {
                PowerModeCheck = POWER_IP_MODE_OK;
            }
            break;
        }
        case (POWER_IP_STOP2_MODE):
        {
            if (SMC_PMSTAT_RUN_U32 == CurrentPowerMode)
            {
                PowerModeCheck = POWER_IP_MODE_OK;
            }
            break;
        }
#endif /* (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON) */
        default:
        {
            /* Do nothing */
            break;
        }
    }

    return PowerModeCheck;
}

/**
* @brief            This function switches the mode by writing SMC_PMCTRL and SMC_STOPCTRL.
* @details          This function configures the mode settings by writing the
*                   SMC_PMCTRL and SMC_STOPCTRL registers.
*
*                   Called by:
*                       - Power_Ip_SetMode() from Power_Ip.
*
* @param[in]        ModeConfigPtr   Pointer to mode configuration structure.
*
* @return           uint32
*
*/
uint32 Power_Ip_SMC_ModeConfig(const Power_Ip_ModeConfigType * ModeConfigPtr)
{
    uint32 PowerSwitchMode = POWER_IP_SWITCH_MODE_SUCCESS;
    /* Contains the code of the Power Mode (based PowerModeType enumeration). */
    Power_Ip_PowerModeType PowerMode = POWER_IP_RUN_MODE;
    uint32 TempValue;
    uint32 PowerModeStatus;
#if (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON)
    /* Contains value of latest written register before executing WFI instruction */
    uint32 RegValue = (uint32)0U;
#endif
    uint32 StartTime;
    uint32 ElapsedTime;
    uint32 TimeoutTicks;
    boolean TimeoutOccurred = FALSE;

    PowerMode = ModeConfigPtr->PowerMode;

    switch (PowerMode)
    {
        case (POWER_IP_RUN_MODE):
        {
            /* Set RUN mode */
            TempValue = IP_SMC->PMCTRL;
            TempValue &= ~SMC_PMCTRL_RUNM_MASK;
            TempValue |= SMC_PMCTRL_RUN_MODE_U32;
            IP_SMC->PMCTRL = TempValue;

            /* Read back to make sure that mode changed successfuly */
            Power_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, POWER_IP_TIMEOUT_VALUE_US);
            do
            {
                TimeoutOccurred = Power_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
                PowerModeStatus = (IP_SMC->PMSTAT & SMC_PMSTAT_RUN_U32);
            } while ( (SMC_PMSTAT_RUN_U32 != PowerModeStatus) && (!TimeoutOccurred) );
            if(TimeoutOccurred)
            {
                PowerSwitchMode = POWER_IP_SWITCH_MODE_FAIL;
                Power_Ip_ReportPowerErrors(POWER_IP_REPORT_TIMEOUT_ERROR, POWER_IP_ERR_CODE_RESERVED);
            }

            break;
        }
        case (POWER_IP_HSRUN_MODE):
        {
            /* Set HSRUN mode. */
            TempValue = IP_SMC->PMCTRL;
            TempValue &= ~SMC_PMCTRL_RUNM_MASK;
            TempValue |= SMC_PMCTRL_HSRUN_MODE_U32;
            IP_SMC->PMCTRL = TempValue;

            /* Read back to make sure that mode changed successfuly */
            Power_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, POWER_IP_TIMEOUT_VALUE_US);
            do
            {
                TimeoutOccurred = Power_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
                PowerModeStatus = (IP_SMC->PMSTAT & SMC_PMSTAT_HSRUN_U32);
            } while ( (SMC_PMSTAT_HSRUN_U32 != PowerModeStatus) && (!TimeoutOccurred) );
            if(TimeoutOccurred)
            {
                PowerSwitchMode = POWER_IP_SWITCH_MODE_FAIL;
                Power_Ip_ReportPowerErrors(POWER_IP_REPORT_TIMEOUT_ERROR, POWER_IP_ERR_CODE_RESERVED);
            }

            break;
        }
        case (POWER_IP_VLPR_MODE):
        {
            /* Set VLPR mode. */
            TempValue = IP_SMC->PMCTRL;
            TempValue &= ~SMC_PMCTRL_RUNM_MASK;
            TempValue |= SMC_PMCTRL_VLPR_MODE_U32;
            IP_SMC->PMCTRL = TempValue;

            /* Read back to make sure that mode changed successfuly */
            Power_Ip_StartTimeout(&StartTime, &ElapsedTime, &TimeoutTicks, POWER_IP_TIMEOUT_VALUE_US);
            do
            {
                TimeoutOccurred = Power_Ip_TimeoutExpired(&StartTime, &ElapsedTime, TimeoutTicks);
                PowerModeStatus = (IP_SMC->PMSTAT & SMC_PMSTAT_VLPR_U32);
            } while ( (SMC_PMSTAT_VLPR_U32 != PowerModeStatus) && (!TimeoutOccurred) );
            if(TimeoutOccurred)
            {
                PowerSwitchMode = POWER_IP_SWITCH_MODE_FAIL;
                Power_Ip_ReportPowerErrors(POWER_IP_REPORT_TIMEOUT_ERROR, POWER_IP_ERR_CODE_RESERVED);
            }

            break;
        }

#if (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON)
        case (POWER_IP_VLPS_MODE):
        {
            /* Set VLPS mode. */
            TempValue = IP_SMC->PMCTRL;
            TempValue &= ~SMC_PMCTRL_STOPM_MASK;
            TempValue |= SMC_PMCTRL_VLPS_U32;
            IP_SMC->PMCTRL = TempValue;
            /* This read ensure transistion mode successful before executing WFI instruction */
            RegValue = IP_SMC->PMCTRL;

#ifdef POWER_IP_SLEEPONEXIT_SUPPORT
#if (POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON)
            if (0U != ModeConfigPtr->SleepOnExit)
            {
                /* Enable Sleep On Exit */
                Power_Ip_CM4_EnableSleepOnExit();
            }
#endif
#endif
            EXECUTE_WAIT();

#ifdef POWER_IP_VLPSA_NOTIFICATION
            if(POWER_IP_STOP_ABORTED == Power_Ip_SMC_Get_VLPSA_Status())
            {
                Power_Ip_ReportPowerErrors(POWER_IP_REPORT_VLPSA_NOTIFICATION, POWER_IP_ERR_CODE_RESERVED);
            }
#endif
            break;
        }
        case (POWER_IP_STOP1_MODE):
        {
            /* Set STOP1 mode. */
            IP_SMC->STOPCTRL = SMC_STOPCTRL_STOP1_U32;

            TempValue = IP_SMC->PMCTRL;
            TempValue &= ~SMC_PMCTRL_STOPM_MASK;
            TempValue |= SMC_PMCTRL_STOP_U32;
            IP_SMC->PMCTRL = TempValue;

            /* This read ensures the transition was successful before executing WFI instruction */
            RegValue = IP_SMC->STOPCTRL;

#ifdef POWER_IP_SLEEPONEXIT_SUPPORT
#if (POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON)
            if (0U != ModeConfigPtr->SleepOnExit)
            {
                /* Enable Sleep On Exit */
                Power_Ip_CM4_EnableSleepOnExit();
            }
#endif
#endif
            EXECUTE_WAIT();

            break;
        }
        case (POWER_IP_STOP2_MODE):
        {
            /* Set STOP2 mode. */
            IP_SMC->STOPCTRL = SMC_STOPCTRL_STOP2_U32;

            TempValue = IP_SMC->PMCTRL;
            TempValue &= ~SMC_PMCTRL_STOPM_MASK;
            TempValue |= SMC_PMCTRL_STOP_U32;
            IP_SMC->PMCTRL = TempValue;

            /* This read ensures the transition was successful before executing WFI instruction */
            RegValue = IP_SMC->STOPCTRL;

#ifdef POWER_IP_SLEEPONEXIT_SUPPORT
#if (POWER_IP_SLEEPONEXIT_SUPPORT == STD_ON)
            if (0U != ModeConfigPtr->SleepOnExit)
            {
                /* Enable Sleep On Exit */
                Power_Ip_CM4_EnableSleepOnExit();
            }
#endif
#endif
            EXECUTE_WAIT();

            break;
        }
#endif /* (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON) */
        default:
        {
            /*Only the above modes are allowed when this function is called*/
            PowerSwitchMode = POWER_IP_SWITCH_MODE_FAIL;
            break;
        }
    }
#if (POWER_IP_ENTER_LOW_POWER_MODE == STD_ON)
    /* Avoid compiler warning */
    (void)RegValue;
#endif

    return PowerSwitchMode;
}

#ifdef POWER_IP_POWERMODE_STATE_API
#if (STD_ON == POWER_IP_POWERMODE_STATE_API)
/**
* @brief            This function return current power mode.
* @details          Return value:
*                       0000_0001b = RUN
*                       0000_0100b = VLPR
*                       0001_0000b = VLPS
*                       1000_0000b = HSRUN
*
* @param[in]        None
*
* @return           Power_Ip_PowerModeStateType
*/
Power_Ip_PowerModeStateType Power_Ip_SMC_GetPowerModeState(void)
{
    Power_Ip_PowerModeStateType State ;

    State = ((IP_SMC->PMSTAT) & SMC_PMSTAT_PMSTAT_MASK);
    return State;
}
#endif
#endif

#ifdef POWER_IP_VLPSA_NOTIFICATION
 /**
* @brief        The function get status of Very Low Power Stop Aborted bit in SMC_PMCTRL register.
* @details      The function get status of Very Low Power Stop Aborted bit in SMC_PMCTRL register when processor enter VLPS.
*               Function return POWER_IP_STOP_SUCCESSFUL if enter VLPS was successfully, POWER_IP_STOP_ABORTED if enter VLPS was Aborted.
*
* @param[in]    none
*
* @return       Std_ReturnType
*
*/
static Power_Ip_SMC_VLPSA_StatusType Power_Ip_SMC_Get_VLPSA_Status(void)
{
    Power_Ip_SMC_VLPSA_StatusType AbortStatus = POWER_IP_STOP_ABORTED;
    uint32 RegValue;

    RegValue = ((IP_SMC->PMCTRL) & SMC_PMCTRL_VLPSA_MASK);
    if(0x00U == RegValue)
    {
        AbortStatus = POWER_IP_STOP_SUCCESSFUL;
    }
    else
    {
        AbortStatus = POWER_IP_STOP_ABORTED;
    }
    return AbortStatus;
}
#endif

#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
