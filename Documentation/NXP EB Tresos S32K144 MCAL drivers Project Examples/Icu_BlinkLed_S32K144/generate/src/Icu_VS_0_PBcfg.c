/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : Ftm Lpit Lptmr Port_Ci LpCmp
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : S32K1_RTD_2_0_0_P04_D2404_ASR_REL_4_7_REV_0000_20240417
*
*   Copyright 2020-2024 NXP Semiconductors
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
 *   @file       Icu_VS_0_PBcfg.c
 *   @version    2.0.0
 *
 *   @brief      AUTOSAR Icu - contains the data exported by the Icu module
 *   @details    Contains the information that will be exported by the module, as requested by Autosar.
 *
 *   @addtogroup icu Icu Driver
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
*================================================================================================*/
#include "Std_Types.h"
#include "Icu.h"
#include "Icu_Ipw_Types.h"
#include "Icu_Ipw_VS_0_PBcfg.h"

#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
#include "CDD_Mcl.h"
#endif

/*==================================================================================================
 *                              SOURCE FILE VERSION INFORMATION
 *================================================================================================*/
#define ICU_VS_0_PBCFG_VENDOR_ID_C                    43
#define ICU_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C     4
#define ICU_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C     7
#define ICU_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C  0
#define ICU_VS_0_PBCFG_SW_MAJOR_VERSION_C             2
#define ICU_VS_0_PBCFG_SW_MINOR_VERSION_C             0
#define ICU_VS_0_PBCFG_SW_PATCH_VERSION_C             0

/*==================================================================================================
 *                                      FILE VERSION CHECKS
 *================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_VS_0_PBcfg.c and Std_Types.h are different"
    #endif

    #if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
        #if ((ICU_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C != CDD_MCL_AR_RELEASE_MAJOR_VERSION) || \
             (ICU_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C != CDD_MCL_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Icu_VS_0_PBcfg.c and CDD_Mcl.h are different"
        #endif
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_VS_0_PBCFG_VENDOR_ID_C != ICU_VENDOR_ID)
    #error "Icu_VS_0_PBcfg.c and Icu.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION) || \
     (ICU_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_VS_0_PBcfg.c and Icu.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_VS_0_PBCFG_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION) || \
     (ICU_VS_0_PBCFG_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION) || \
     (ICU_VS_0_PBCFG_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_VS_0_PBcfg.c and Icu.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_VS_0_PBCFG_VENDOR_ID_C != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu_VS_0_PBcfg.c and Icu_Ipw_Types.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_VS_0_PBcfg.c and Icu_Ipw_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_VS_0_PBCFG_SW_MAJOR_VERSION_C != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_VS_0_PBCFG_SW_MINOR_VERSION_C != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_VS_0_PBCFG_SW_PATCH_VERSION_C != ICU_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_VS_0_PBcfg.c and Icu_Ipw_Types.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_VS_0_PBCFG_VENDOR_ID_C != ICU_IPW_VS_0_PBCFG_VENDOR_ID)
    #error "Icu_VS_0_PBcfg.c and Icu_Ipw_VS_0_PBcfg.h have different vendor IDs"
#endif
/* Check if source file and ICU header file are of the same AutoSar version */
#if ((ICU_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_VS_0_PBCFG_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_VS_0_PBCFG_AR_RELEASE_MINOR_VERSION) || \
     (ICU_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_VS_0_PBCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_VS_0_PBcfg.c and Icu_Ipw_VS_0_PBcfg.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_VS_0_PBCFG_SW_MAJOR_VERSION_C != ICU_IPW_VS_0_PBCFG_SW_MAJOR_VERSION) || \
     (ICU_VS_0_PBCFG_SW_MINOR_VERSION_C != ICU_IPW_VS_0_PBCFG_SW_MINOR_VERSION) || \
     (ICU_VS_0_PBCFG_SW_PATCH_VERSION_C != ICU_IPW_VS_0_PBCFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_VS_0_PBcfg.c and Icu_Ipw_VS_0_PBcfg.h are different"
#endif

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
 *================================================================================================*/

/*==================================================================================================
 *                                      LOCAL CONSTANTS
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                                       GLOBAL CONSTANTS
 *================================================================================================*/

#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

/**
* @brief External Notifications for Edge Detection
*
*/
extern void User_EdgeDetect0(void);
extern void User_EdgeDetect1(void);

#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"

#define ICU_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/*
*   @brief Translation LUT for Logical channel number to Partition Configuration indexed location
*/
const uint8 Icu_ChIndexMap_PB_VS_0[2U] = 
{
    0U,    /* IcuConfigSet has an index of 0 */
    1U    /* IcuConfigSet has an index of 1 */
};

/*
*  @brief    PB_VS_0 Configuration
*/
static const Icu_ChannelConfigType Icu_ChannelConfig_PB_VS_0[2U]=
{
    /* IcuChannel_0 */
    {
        (boolean)FALSE,    /* Wakeup capability */
        ICU_RISING_EDGE,    /* Edge used */
        ICU_MODE_SIGNAL_EDGE_DETECT,    /* Measurement mode */
        (Icu_MeasurementSubModeType)0U,    /* Icu_MeasurementSubModeType */
        &User_EdgeDetect0,    /* Icu_Channel_Notification */
#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
        (Mcl_ChannelType)NoMclDmaChannel,    /* Mcl_DmaChannel */
#endif
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
        NULL_PTR,    /* Icu_Channel_OverflowNotification */
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        (Icu_WakeupValueType)0U,    /* Icu_Channel_WakeupValue */
#endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        &Icu_Ipw_IpChannelConfig_PB_VS_0[0U] /* Ipw channel pointer */
    },
    /* IcuChannel_1 */
    {
        (boolean)FALSE,    /* Wakeup capability */
        ICU_RISING_EDGE,    /* Edge used */
        ICU_MODE_SIGNAL_EDGE_DETECT,    /* Measurement mode */
        (Icu_MeasurementSubModeType)0U,    /* Icu_MeasurementSubModeType */
        &User_EdgeDetect1,    /* Icu_Channel_Notification */
#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
        (Mcl_ChannelType)NoMclDmaChannel,    /* Mcl_DmaChannel */
#endif
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
        NULL_PTR,    /* Icu_Channel_OverflowNotification */
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
        (Icu_WakeupValueType)0U,    /* Icu_Channel_WakeupValue */
#endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        &Icu_Ipw_IpChannelConfig_PB_VS_0[1U] /* Ipw channel pointer */
    }
};

    



/*
*   @brief Postbuild Configuration for each Partition
*/
const Icu_ConfigType Icu_Config_VS_0=
{
    (uint8)2, 
    /** @brief The number of channels configured*/
    &Icu_ChannelConfig_PB_VS_0, 
    /** @brief Icu Channel Configuration Pointer */
    (uint8)2, /* The number of IP instances configured*/
    /** @brief Icu Instance Configuration Pointer */
    &Icu_Ipw_IpConfig_PB_VS_0,
    /** @brief Index of channel in each partition map table*/
    &Icu_ChIndexMap_PB_VS_0,
    /** @brief core index*/
    (uint8)0U
};


#define ICU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Icu_MemMap.h"

/*==================================================================================================
 *                                       GLOBAL VARIABLES
 *================================================================================================*/

/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
 *================================================================================================*/

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
 *================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
