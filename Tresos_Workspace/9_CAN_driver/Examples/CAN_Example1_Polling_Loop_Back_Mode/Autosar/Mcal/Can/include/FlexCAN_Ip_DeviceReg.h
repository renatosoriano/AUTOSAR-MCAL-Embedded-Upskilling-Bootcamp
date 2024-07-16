/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : FLEXCAN
*   Dependencies         : 
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
*   (c) Copyright 2020-2023 NXP Semiconductors
*   All Rights Reserved.
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
* @file
*
* @brief FlexCAN Registers and Default Reg Values
* @details <File details>
*
* @addtogroup FlexCAN
* @{
*/
#ifndef FLEXCAN_IP_DEVICEREG_H_
#define FLEXCAN_IP_DEVICEREG_H_

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "FlexCAN_Ip_CfgDefines.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLEXCAN_IP_DEVICEREG_VENDOR_ID_H                      43
#define FLEXCAN_IP_DEVICEREG_AR_RELEASE_MAJOR_VERSION_H       4
#define FLEXCAN_IP_DEVICEREG_AR_RELEASE_MINOR_VERSION_H       7
#define FLEXCAN_IP_DEVICEREG_AR_RELEASE_REVISION_VERSION_H    0
#define FLEXCAN_IP_DEVICEREG_SW_MAJOR_VERSION_H               2
#define FLEXCAN_IP_DEVICEREG_SW_MINOR_VERSION_H               0
#define FLEXCAN_IP_DEVICEREG_SW_PATCH_VERSION_H               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and FlexCAN_Ip_CfgDefines header file are of the same vendor */
#if (FLEXCAN_IP_DEVICEREG_VENDOR_ID_H != FLEXCAN_IP_CFGDEFINES_VENDOR_ID_H)
    #error "FlexCAN_Ip_DeviceReg.h and FlexCAN_Ip_CfgDefines.h have different vendor ids"
#endif
/* Check if current file and FlexCAN_Ip_CfgDefines header file are of the same Autosar version */
#if ((FLEXCAN_IP_DEVICEREG_AR_RELEASE_MAJOR_VERSION_H    != FLEXCAN_IP_CFGDEFINES_AR_RELEASE_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_DEVICEREG_AR_RELEASE_MINOR_VERSION_H    != FLEXCAN_IP_CFGDEFINES_AR_RELEASE_MINOR_VERSION_H) || \
     (FLEXCAN_IP_DEVICEREG_AR_RELEASE_REVISION_VERSION_H != FLEXCAN_IP_CFGDEFINES_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of FlexCAN_Ip_DeviceReg.h and FlexCAN_Ip_CfgDefines.h are different"
#endif
/* Check if current file and FlexCAN_Ip_CfgDefines header file are of the same Software version */
#if ((FLEXCAN_IP_DEVICEREG_SW_MAJOR_VERSION_H != FLEXCAN_IP_CFGDEFINES_SW_MAJOR_VERSION_H) || \
     (FLEXCAN_IP_DEVICEREG_SW_MINOR_VERSION_H != FLEXCAN_IP_CFGDEFINES_SW_MINOR_VERSION_H) || \
     (FLEXCAN_IP_DEVICEREG_SW_PATCH_VERSION_H != FLEXCAN_IP_CFGDEFINES_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of FlexCAN_Ip_DeviceReg.h and FlexCAN_Ip_CfgDefines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and StandardTypes header file are of the same Autosar version */
    #if ((FLEXCAN_IP_DEVICEREG_AR_RELEASE_MAJOR_VERSION_H    != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLEXCAN_IP_DEVICEREG_AR_RELEASE_MINOR_VERSION_H    != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of FlexCAN_Ip_DeviceReg.h and StandardTypes.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* Default value for register */
/**
* @brief Default value for the MCR register
*/
#define FLEXCAN_IP_MCR_DEFAULT_VALUE_U32               ((uint32)0xD890000FU)

/**
* @brief Default value for the CTRL1 register
*/
#define FLEXCAN_IP_CTRL1_DEFAULT_VALUE_U32             ((uint32)0x00000000U)

/**
* @brief Default value for the TIMER register
*/
#define FLEXCAN_IP_TIMER_DEFAULT_VALUE_U32             ((uint32)0x00000000U)

/**
* @brief Default value for the ECR register
*/
#define FLEXCAN_IP_ECR_DEFAULT_VALUE_U32               ((uint32)0x00000000U)

/**
* @brief Default value for the ESR1 register
*/
#define FLEXCAN_IP_ESR1_DEFAULT_VALUE_U32              ((uint32)0x0003B006U)

/**
* @brief Default value for the IMASK2 register
*/
#define FLEXCAN_IP_IMASK_DEFAULT_VALUE_U32             ((uint32)0x00000000U)

/**
* @brief Default value for the IFLAG4 register
*/
#define FLEXCAN_IP_IFLAG_DEFAULT_VALUE_U32             ((uint32)0xFFFFFFFFU)

/**
* @brief Default value for the CTRL2 register
*/
#define FLEXCAN_IP_CTRL2_DEFAULT_VALUE_U32             ((uint32)0x00100000U)

/**
* @brief Default value for the CTRL2 register
*/
#define FLEXCAN_IP_CBT_DEFAULT_VALUE_U32               ((uint32)0x00000000U)

/**
* @brief Default value for the FDCTRL register
*/
#define FLEXCAN_IP_FDCTRL_DEFAULT_VALUE_U32            ((uint32)0x80004100U)

/**
* @brief Default value for the FDCBT register
*/
#define FLEXCAN_IP_FDCBT_DEFAULT_VALUE_U32             ((uint32)0x00000000U)

#define CAN_FEATURE_S32K1XX                     TRUE

/** Array init has of CAN Peripheral base address has FD capability */
#if defined(S32K148)
    #define CAN_FEATURE_FD_INSTANCES         (3U)
    #define CAN_BASE_PTRS_HAS_FD    { IP_FLEXCAN0, IP_FLEXCAN1, IP_FLEXCAN2 }
#elif (defined(S32K146) || defined(S32K144W) || defined(S32K142W))
    #define CAN_FEATURE_FD_INSTANCES         (2U)
    #define CAN_BASE_PTRS_HAS_FD    { IP_FLEXCAN0,  IP_FLEXCAN1}
#else
    #define CAN_BASE_PTRS_HAS_FD    { IP_FLEXCAN0 }
    #define CAN_FEATURE_FD_INSTANCES         (1U)
#endif

#if (defined(S32K116) || defined(S32K118))
#define FLEXCAN_IP_FEATURE_BUSOFF_ERROR_INTERRUPT_UNIFIED      (STD_ON)
#else
#define FLEXCAN_IP_FEATURE_BUSOFF_ERROR_INTERRUPT_UNIFIED      (STD_OFF)
#endif

#define FLEXCAN_0_BASE IP_FLEXCAN0_BASE

#if FLEXCAN_INSTANCE_COUNT > 1U
#define FLEXCAN_1_BASE IP_FLEXCAN1_BASE
#endif
#if FLEXCAN_INSTANCE_COUNT > 2U
#define FLEXCAN_2_BASE IP_FLEXCAN2_BASE
#endif

#endif /* FLEXCAN_IP_DEVICEREG_H_ */
/** @} */
