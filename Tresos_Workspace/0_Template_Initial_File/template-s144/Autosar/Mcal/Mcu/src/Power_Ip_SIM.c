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
*   @file       Power_Ip_SIM.c
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
#include "Power_Ip_SIM.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define Power_Ip_SIM_VENDOR_ID_C                      43
#define Power_Ip_SIM_AR_RELEASE_MAJOR_VERSION_C       4
#define Power_Ip_SIM_AR_RELEASE_MINOR_VERSION_C       7
#define Power_Ip_SIM_AR_RELEASE_REVISION_VERSION_C    0
#define Power_Ip_SIM_SW_MAJOR_VERSION_C               2
#define Power_Ip_SIM_SW_MINOR_VERSION_C               0
#define Power_Ip_SIM_SW_PATCH_VERSION_C               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if Power_Ip_SIM.c file and Power_Ip_SIM.h file are of the same vendor */
#if (Power_Ip_SIM_VENDOR_ID_C != POWER_IP_SIM_VENDOR_ID)
    #error "Power_Ip_SIM.c and Power_Ip_SIM.h have different vendor ids"
#endif

/* Check if Power_Ip_SIM.c file and Power_Ip_SIM.h file are of the same Autosar version */
#if ((Power_Ip_SIM_AR_RELEASE_MAJOR_VERSION_C != POWER_IP_SIM_AR_RELEASE_MAJOR_VERSION) || \
     (Power_Ip_SIM_AR_RELEASE_MINOR_VERSION_C != POWER_IP_SIM_AR_RELEASE_MINOR_VERSION) || \
     (Power_Ip_SIM_AR_RELEASE_REVISION_VERSION_C != POWER_IP_SIM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Power_Ip_SIM.c and Power_Ip_SIM.h are different"
#endif

/* Check if Power_Ip_SIM.c file and Power_Ip_SIM.h file are of the same Software version */
#if ((Power_Ip_SIM_SW_MAJOR_VERSION_C != POWER_IP_SIM_SW_MAJOR_VERSION) || \
     (Power_Ip_SIM_SW_MINOR_VERSION_C != POWER_IP_SIM_SW_MINOR_VERSION) || \
     (Power_Ip_SIM_SW_PATCH_VERSION_C != POWER_IP_SIM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Power_Ip_SIM.c and Power_Ip_SIM.h are different"
#endif

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

#ifdef POWER_IP_SRAM_RETEN_CONFIG_API
#if (POWER_IP_SRAM_RETEN_CONFIG_API == STD_ON)
/**
 * @brief   Configuration for SRAM retention.
 * @details This function configure for both SRAML_RETEN and SRAMU_RETEN bits.
 *                   Called by:
 *                       - Power_Ip_SRAMRetentionConfig() from IPW
 * @param[in] SRAMRetenConfig       The value will be configured to SRAML_RETEN and SRAMU_RETEN bits.
 *                                  MCU_SRAML_RETEN - SRAML will be retain only.
 *                                  MCU_SRAMU_RETEN - SRAMU will be retain only.
 *                                  MCU_SRAMLU_RETEN - Both SRAML and SRAMU will be retain.
 *                                  MCU_NO_SRAMLU_RETEN - Both SRAML and SRAMU will not be retain.
 *
 * @return                   void
 *
 */
void Power_Ip_SIM_SRAMRetentionConfig(Power_Ip_SRAMRetenConfigType SRAMRetenConfig)
{
    uint32 TempValue;

#ifdef MCAL_PLATFORM_ARM
    /* add dsb to guarantee that there are no delayed writes to SRAM */
    MCAL_DATA_SYNC_BARRIER();
#endif

    /* Configure to both SRAML_RETEN and SRAMU_RETEN bits */
    TempValue = IP_SIM->CHIPCTL;
    TempValue &= ~(SIM_CHIPCTL_SRAML_RETEN_MASK | SIM_CHIPCTL_SRAMU_RETEN_MASK);
    TempValue |= (uint32)SRAMRetenConfig;
    IP_SIM->CHIPCTL = TempValue;

#ifdef MCAL_PLATFORM_ARM
    MCAL_DATA_SYNC_BARRIER();
#endif
}
#endif
#endif

#define MCU_STOP_SEC_CODE

#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
