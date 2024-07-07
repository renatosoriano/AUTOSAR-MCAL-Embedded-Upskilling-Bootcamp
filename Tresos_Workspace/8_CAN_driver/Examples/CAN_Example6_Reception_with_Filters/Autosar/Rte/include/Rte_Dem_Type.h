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

#ifndef RTE_DEM_TYPE_H
#define RTE_DEM_TYPE_H

/**
*   @file
*
*   @addtogroup RTE_MODULE
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RTE_DEM_TYPES_VENDOR_ID                     43
#define RTE_DEM_TYPES_MODULE_ID                     002

#define RTE_DEM_TYPES_AR_RELEASE_MAJOR_VERSION      4
#define RTE_DEM_TYPES_AR_RELEASE_MINOR_VERSION      7
#define RTE_DEM_TYPES_AR_RELEASE_REVISION_VERSION   0
#define RTE_DEM_TYPES_SW_MAJOR_VERSION              2
#define RTE_DEM_TYPES_SW_MINOR_VERSION              0
#define RTE_DEM_TYPES_SW_PATCH_VERSION              0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef uint16 Dem_EventIdType;                              /**< @brief dem event ID type */

typedef uint8 Dem_EventStatusType;                           /**< @brief dem event status type */

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define DEM_EVENT_STATUS_PASSED                 (Dem_EventStatusType)0x00U  /**< @brief dem event passed */
#define DEM_EVENT_STATUS_FAILED                 (Dem_EventStatusType)0x01U  /**< @brief dem event failed */
#define DEM_EVENT_STATUS_PREPASSED              (Dem_EventStatusType)0x02U  /**< @brief dem event pre-passed */
#define DEM_EVENT_STATUS_PREFAILED              (Dem_EventStatusType)0x03U  /**< @brief dem event pre-failed */
#define DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED  (Dem_EventStatusType)0x04U  /**< @brief dem event pre-failed */

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* RTE_DEM_TYPE_H */
