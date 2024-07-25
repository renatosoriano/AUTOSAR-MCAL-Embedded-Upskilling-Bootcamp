/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : GPIO
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
*   @file Dio_Cfg.c
*   @implements Dio_Cfg.c_Artifact
*
*   @addtogroup DIO_CFG
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Dio.h"


#if (defined(DIO_PRECOMPILE_SUPPORT) || defined(DIO_LINKTIME_SUPPORT))
/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define DIO_VENDOR_ID_CFG_C                   43
#define DIO_AR_RELEASE_MAJOR_VERSION_CFG_C    4
#define DIO_AR_RELEASE_MINOR_VERSION_CFG_C    7
#define DIO_AR_RELEASE_REVISION_VERSION_CFG_C 0
#define DIO_SW_MAJOR_VERSION_CFG_C            2
#define DIO_SW_MINOR_VERSION_CFG_C            0
#define DIO_SW_PATCH_VERSION_CFG_C            0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
    /* Check if Dio_Cfg.c and Dio.h files are of the same Autosar version.*/
#if ((DIO_AR_RELEASE_MAJOR_VERSION_CFG_C != DIO_AR_RELEASE_MAJOR_VERSION)  ||  \
     (DIO_AR_RELEASE_MINOR_VERSION_CFG_C != DIO_AR_RELEASE_MINOR_VERSION)  ||  \
     (DIO_AR_RELEASE_REVISION_VERSION_CFG_C != DIO_AR_RELEASE_REVISION_VERSION)\
    )
    #error "AutoSar Version Numbers of Dio_Cfg.c and Dio.h are different"
#endif
    /* Check if Dio_Cfg.c and Dio.h files are of the same Software version.*/
#if ((DIO_SW_MAJOR_VERSION_CFG_C != DIO_SW_MAJOR_VERSION) || \
     (DIO_SW_MINOR_VERSION_CFG_C != DIO_SW_MINOR_VERSION) || \
     (DIO_SW_PATCH_VERSION_CFG_C != DIO_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Dio_Cfg.c and Dio.h are different"
#endif
    /* Check if Dio_Cfg.c and Dio.h files are of the same vendor.*/
#if ((DIO_VENDOR_ID_CFG_C != DIO_VENDOR_ID))
    #error "VENDOR ID for Dio_Cfg.c and Dio.h is different"
#endif
/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
#define DIO_START_SEC_CONST_32
#include "Dio_MemMap.h"

/**
* @brief Array containing list of mapping channel for partition
*/
const uint32 Dio_au32ChannelToPartitionMap[DIO_CHANNEL_PARTITION_U16] =
{
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001
};

/**
* @brief Array containing list of mapping port for partition
*/
const uint32 Dio_au32PortToPartitionMap[DIO_PORT_PARTITION_U16] =
{
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001,
    (uint32)0x0000000000000001
};


/**
* @brief          Platform implemented port pins representation.
* @details        Array of bit maps reflecting the available pins in each port.
*                 The number of elements in the array corresponds to the number of
*                 ports implemented in the platform package. Rightmost bit of each
*                 array element corresponds to channel 0 of the associated port,
*                 while leftmost bit of each array element corresponds to channel 31
*                 of the associated port. A 0 bit means that the correspondent channel
*                 is not available in the platform package, while a bit of 1 means
*                 that the correspondent channel is available in the platform package.
*
* @api
*/
const Dio_PortLevelType Dio_aAvailablePinsForWrite[DIO_NUM_PORTS_U16] =
{
    (Dio_PortLevelType)0x0003FFFFUL,
    (Dio_PortLevelType)0x0003FFFFUL,
    (Dio_PortLevelType)0x0003FFFFUL,
    (Dio_PortLevelType)0x0003FFFFUL,
    (Dio_PortLevelType)0x0001FFFFUL
};

const Dio_PortLevelType Dio_aAvailablePinsForRead[DIO_NUM_PORTS_U16] =
{
    (Dio_PortLevelType)0x0003FFFFUL,
    (Dio_PortLevelType)0x0003FFFFUL,
    (Dio_PortLevelType)0x0003FFFFUL,
    (Dio_PortLevelType)0x0003FFFFUL,
    (Dio_PortLevelType)0x0001FFFFUL
};


#define DIO_STOP_SEC_CONST_32
#include "Dio_MemMap.h"

#define DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dio_MemMap.h"

/* ========== DioConfig ========== */
/**
* @brief          Data structure for configuration DioConfig.
*/
const Dio_ConfigType Dio_Config =
{
    (uint8)0x0,
    NULL_PTR,
    Dio_au32ChannelToPartitionMap,
    Dio_au32PortToPartitionMap
};

#define DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dio_MemMap.h"

/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/


/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

#endif /* (defined(DIO_PRECOMPILE_SUPPORT) || defined(DIO_LINKTIME_SUPPORT))  */

#ifdef __cplusplus
}
#endif

/** @} */
