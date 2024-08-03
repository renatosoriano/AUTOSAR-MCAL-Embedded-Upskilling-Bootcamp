/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : IPV_FTFC
*   Dependencies         : 
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
#ifndef FTFC_MEM_EEP_IP_TYPES_H
#define FTFC_MEM_EEP_IP_TYPES_H

/**
*   @file Ftfc_Mem_Eep_Ip_Types.h
*
*   @addtogroup FTFC_MEM_EEP_IP
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
#include "StandardTypes.h"

#include "Mcal.h"
/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FTFC_MEM_EEP_IP_TYPES_VENDOR_ID_H                    43
#define FTFC_MEM_EEP_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H     4
#define FTFC_MEM_EEP_IP_TYPES_AR_RELEASE_MINOR_VERSION_H     7
#define FTFC_MEM_EEP_IP_TYPES_AR_RELEASE_REVISION_VERSION_H  0
#define FTFC_MEM_EEP_IP_TYPES_SW_MAJOR_VERSION_H             2
#define FTFC_MEM_EEP_IP_TYPES_SW_MINOR_VERSION_H             0
#define FTFC_MEM_EEP_IP_TYPES_SW_PATCH_VERSION_H             0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Mcal header file are of the same Autosar version */
    #if ((FTFC_MEM_EEP_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (FTFC_MEM_EEP_IP_TYPES_AR_RELEASE_MINOR_VERSION_H != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Ftfc_Mem_Eep_Ip_Types.h and Mcal.h are different"
    #endif
    /* Version checks for StandardTypes.h */
    #if ((FTFC_MEM_EEP_IP_TYPES_AR_RELEASE_MAJOR_VERSION_H != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FTFC_MEM_EEP_IP_TYPES_AR_RELEASE_MINOR_VERSION_H != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "Ftfc_Mem_Eep_Ip_Types.h and StandardTypes.h are for different AUTOSAR versions!"
    #endif

#endif

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/** Return values for a FTFC operation. */
typedef enum
{
    FTFC_MEM_EEP_IP_STATUS_OK,                      /**< success */
    FTFC_MEM_EEP_IP_STATUS_FAILED,                  /**< failure */
    FTFC_MEM_EEP_IP_STATUS_BLOCK_INCONSISTENT,      /**< the Compare API found a difference in the memory contents */
    FTFC_MEM_EEP_IP_STATUS_PENDING,                 /**< the async job is pending */
    FTFC_MEM_EEP_IP_STATUS_TIMEOUT,                 /**< a timeout has occured */

} Ftfc_Mem_Eep_Ip_StatusType;

/** Brown-out detection code found after a reset */
typedef enum
{
    FTFC_MEM_EEP_IP_NO_BO_DETECTED          = 0x00,     /**< No EEPROM issues detected */
    FTFC_MEM_EEP_IP_BO_DURING_MAINTENANCE   = 0x01,     /**< Quick write maintenance has to be completed. */
    FTFC_MEM_EEP_IP_BO_DURING_QUICK_WRITES  = 0x02,     /**< Quick writes were discarded due to a reset. */
    FTFC_MEM_EEP_IP_BO_DURING_NORMAL_WRITES = 0x04      /**< A normal write was interrupted by reset. */
} Ftfc_Mem_Eep_Ip_BrownOutCodeType;

/** Accepted values for an operation's page size */
typedef enum
{
    FTFC_MEM_EEP_IP_PAGE_BYTE       = 1,    /**< 8-bit  unaligned operation */
    FTFC_MEM_EEP_IP_PAGE_WORD       = 2,    /**< 16-bit aligned   operation */
    FTFC_MEM_EEP_IP_PAGE_LONGWORD   = 4,    /**< 32-bit aligned   operation */
} Ftfc_Mem_Eep_Ip_PageSizeType;

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

/** Mapped to the Access Code Callback provided by some upper layer module. */
typedef void (*Ftfc_Mem_Eep_Ip_Ac_Callback_Type)                  (void);

/** pointer to start eeprom access notification */
typedef void (*Ftfc_Mem_Eep_Ip_StartEepromAccessNotif_Type)       (void);

/** pointer to finished eeprom access notification */
typedef void (*Ftfc_Mem_Eep_Ip_FinishedEepromAccessNotif_Type)    (void);

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/** Configuration structure for the FTFC IP driver. */
typedef struct
{
    Ftfc_Mem_Eep_Ip_Ac_Callback_Type                  acCallBackPtr;
    Ftfc_Mem_Eep_Ip_StartEepromAccessNotif_Type       startEepromAccessNotifPtr;
    Ftfc_Mem_Eep_Ip_FinishedEepromAccessNotif_Type    finishedEepromAccessNotifPtr;
} Ftfc_Mem_Eep_Ip_ConfigType;

/** The module's address type. */
typedef uint32 Ftfc_Mem_Eep_Ip_AddressType;

/** Type mainly used for storing offsets from a given address. */
typedef uint32 Ftfc_Mem_Eep_Ip_LengthType;

/*==================================================================================================
*                                       
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */

#endif /* FTFC_MEM_EEP_IP_TYPES_H */
