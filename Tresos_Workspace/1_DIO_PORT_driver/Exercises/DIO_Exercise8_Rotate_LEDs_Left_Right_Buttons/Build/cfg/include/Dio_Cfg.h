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

#ifndef DIO_CFG_H
#define DIO_CFG_H

/**
*   @file Dio_Cfg.h
*   @implements Dio_Cfg.h_Artifact
*
*   @defgroup DIO_CFG Dio Cfg
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
#include "Std_Types.h"
#include "Gpio_Dio_Ip_Cfg.h"


/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

#define DIO_VENDOR_ID_CFG_H                   43
#define DIO_AR_RELEASE_MAJOR_VERSION_CFG_H    4
#define DIO_AR_RELEASE_MINOR_VERSION_CFG_H    7
#define DIO_AR_RELEASE_REVISION_VERSION_CFG_H 0
#define DIO_SW_MAJOR_VERSION_CFG_H            2
#define DIO_SW_MINOR_VERSION_CFG_H            0
#define DIO_SW_PATCH_VERSION_CFG_H            0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* StandardTypes.h version check start */
    #if ((DIO_AR_RELEASE_MAJOR_VERSION_CFG_H != STD_AR_RELEASE_MAJOR_VERSION) ||   \
        (DIO_AR_RELEASE_MINOR_VERSION_CFG_H != STD_AR_RELEASE_MINOR_VERSION)       \
        )
        #error "AUTOSAR Version Numbers of Dio_Cfg.h and StandardTypes.h are different"
    #endif
    /* StandardTypes.h version check end */
#endif

/* Check if Dio_Cfg.h and Gpio_Dio_Ip_Cfg.h files are of the same vendor.*/
#if (DIO_VENDOR_ID_CFG_H != GPIO_DIO_IP_VENDOR_ID_CFG_H)
    #error "Dio_Cfg.h and Gpio_Dio_Ip_Cfg.h have different vendor ids"
#endif
/* Check if Dio_Cfg.h and Gpio_Dio_Ip_Cfg.h files are of the same Autosar version.*/
#if ((DIO_AR_RELEASE_MAJOR_VERSION_CFG_H    != GPIO_DIO_IP_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (DIO_AR_RELEASE_MINOR_VERSION_CFG_H    != GPIO_DIO_IP_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (DIO_AR_RELEASE_REVISION_VERSION_CFG_H != GPIO_DIO_IP_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
    #error "AutoSar Version Numbers of Dio_Cfg.h and Gpio_Dio_Ip_Cfg.h are different"
#endif
/* Check if Dio_Cfg.h and Gpio_Dio_Ip_Cfg.h files are of the same Software version.*/
#if ((DIO_SW_MAJOR_VERSION_CFG_H != GPIO_DIO_IP_SW_MAJOR_VERSION_CFG_H) || \
     (DIO_SW_MINOR_VERSION_CFG_H != GPIO_DIO_IP_SW_MINOR_VERSION_CFG_H) || \
     (DIO_SW_PATCH_VERSION_CFG_H != GPIO_DIO_IP_SW_PATCH_VERSION_CFG_H)    \
    )
    #error "Software Version Numbers of Dio_Cfg.h and Gpio_Dio_Ip_Cfg.h are different"
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/
/**
* @brief      Dio driver Channel Groups configuration switch.
*
*/
#define DIO_CHANNEL_GROUPS_AVAILABLE

/**
* @brief          Enable or Disable Development Error Detection.
*
* @implements     DIO_DEV_ERROR_DETECT_define
*/
#define DIO_DEV_ERROR_DETECT    (STD_OFF)

/**
* @brief          Function @p Dio_GetVersionInfo() enable switch.
*
* @implements DIO_VERSION_INFO_API_define
*/
#define DIO_VERSION_INFO_API    (STD_OFF)

/**
* @brief          Function @p Dio_FlipChannel() enable switch.
*/
#define DIO_FLIP_CHANNEL_API    (STD_OFF)

/**
* @brief          Function @p Dio_MaskedWritePort() enable switch.
*/
#define DIO_MASKEDWRITEPORT_API (STD_OFF)

/**
* @brief          Reversed port functionality enable switch.
*
* @implements DIO_REVERSEPORTBITS_define
*/
#define DIO_REVERSEPORTBITS     (STD_OFF)

/**
* @brief          Undefined pins masking enable switch.
*/
#define DIO_READZERO_UNDEFINEDPORTS (STD_OFF)



/**
* @brief          The number of partition on the platform.
*
* @note           Used for channel, port and channel group validation.
*/

/**
* @brief Enable/Disable multiocre function from the driver
*/
#define DIO_MULTICORE_ENABLED          (STD_OFF)

/**
* @brief          Number of implemented ports.
*
* @note           Used for channel, port and channel group validation.
*/
#define DIO_NUM_PORTS_U16               ((uint16)0x5)

/**
* @brief          The number of partition on the port
*
* @note           Used for port validation.
*/
#define DIO_PORT_PARTITION_U16          ((uint16)5U)

/**
* @brief          Number of channels available on the implemented ports.
*
* @note           Used for channel validation.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #define DIO_NUM_CHANNELS_U16            ((uint16)144U)
#endif

/**
* @brief The number of partition on the channel.
*
* @note           Used for channel validation.
*/
#define DIO_CHANNEL_PARTITION_U16            ((uint16)145U)

/**
* @brief          Mask representing no available channels on a port.
*
* @note           Used for channel validation.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #define DIO_NO_AVAILABLE_CHANNELS_U16   ((Dio_PortLevelType)0x0U)
#endif

/**
* @brief          Mask representing the maximum valid offset for a channel group.
*
* @note           Used for channel group validation.
*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)
    #define DIO_MAX_VALID_OFFSET_U8         ((uint8)0x1FU)
#endif

/**
*   @brief   Enables or disables the access to a hardware register from user mode
*            USER_MODE_SOFT_LOCKING:        All reads to hw registers will be done via REG_PROT, user mode access
*            SUPERVISOR_MODE_SOFT_LOCKING:  Locks the access to the registers only for supervisor mode
*
*   @note    Currently, no register protection mechanism is used for Dio driver.
*/
#define DIO_USER_MODE_SOFT_LOCKING      (STD_OFF)

/**
* @brief          Dio driver Pre-Compile configuration switch.
*/
#define DIO_PRECOMPILE_SUPPORT


/**
* @brief Support for User mode.
*        If this parameter has been configured to 'STD_ON', the Dio driver code can be executed from both supervisor and user mode.
*
*/

#define DIO_ENABLE_USER_MODE_SUPPORT   (STD_OFF)


#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
 #ifdef DIO_ENABLE_USER_MODE_SUPPORT
  #if (STD_ON == DIO_ENABLE_USER_MODE_SUPPORT)
    #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Dio in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
  #endif /* (STD_ON == DIO_ENABLE_USER_MODE_SUPPORT) */
 #endif /* ifdef DIO_ENABLE_USER_MODE_SUPPORT*/
#endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */

/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/

/**
* @brief          Symbolic name for the configuration Dio_ConfigPC.
*
*/
#define Dio_ConfigPC    (Dio_Config)

/* ========== DioConfig ========== */

/* ---------- PORTC ---------- */

/**
* @brief          Symbolic name for the port PORTC.
*
*/
#define DioConf_DioPort_PORTC  ((uint8)0x02U)

/**
* @brief        Symbolic name for the channel group PORTC_LEDS.
*
*/

#define DioConf_DioChannelGroup_PORTC_LEDS    \
(&DioConfig_aChannelGroupList[0])
/* ---------- PORTD ---------- */

/**
* @brief          Symbolic name for the port PORTD.
*
*/
#define DioConf_DioPort_PORTD  ((uint8)0x03U)



/**
* @brief          Symbolic name for the channel D17_SW2_BTN.
*
*/
#define  DioConf_DioChannel_D17_SW2_BTN ((uint16)0x0071U)

/* ---------- PORTE ---------- */

/**
* @brief          Symbolic name for the port PORTE.
*
*/
#define DioConf_DioPort_PORTE  ((uint8)0x04U)



/**
* @brief          Symbolic name for the channel E12_SW1_BTN.
*
*/
#define  DioConf_DioChannel_E12_SW1_BTN ((uint16)0x008cU)

/* ---------- PORTA ---------- */

/**
* @brief          Symbolic name for the port PORTA.
*
*/
#define DioConf_DioPort_PORTA  ((uint8)0x00U)



/**
* @brief          Symbolic name for the channel A12_SW3_BTN.
*
*/
#define  DioConf_DioChannel_A12_SW3_BTN ((uint16)0x000cU)


/*=================================================================================================
*                                             ENUMS
=================================================================================================*/

/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/

/**
* @brief          Type of a DIO port representation.
*
* @implements     Dio_PortType_typedef
*/
typedef uint8 Dio_PortType;

/**
* @brief          Type of a DIO channel representation.
*
* @implements     Dio_ChannelType_typedef
*/
typedef uint16 Dio_ChannelType;

/**
* @brief          Type of a DIO port levels representation.
*
* @implements     Dio_PortLevelType_typedef
*/
typedef uint32 Dio_PortLevelType;

/**
* @brief          Type of a DIO channel levels representation.
*
* @implements     Dio_LevelType_typedef
*/
typedef uint8 Dio_LevelType;

/**
* @brief          Type of a DIO channel group representation.
*
* @implements     Dio_ChannelGroupType_struct
*/
typedef struct
{
    Dio_PortType      port;      /**< @brief Port identifier.  */
    uint8             u8offset;    /**< @brief Bit offset within the port. */
    Dio_PortLevelType mask;      /**< @brief Group mask. */
} Dio_ChannelGroupType;

/**
* @brief          Type of a DIO configuration structure.
*
* @note           In this implementation there is no need for a configuration
*                 structure there is only a dummy field, it is recommended
*                 to initialize this field to zero.
*
* @implements     Dio_ConfigType_struct
*/
typedef struct
{
    uint8 u8NumChannelGroups; /**< @brief Number of channel groups in configuration */
    const Dio_ChannelGroupType * pChannelGroupList;  /**< @brief
                                               Pointer to list of channel groups in configuration */
    const uint32 * pau32Dio_ChannelToPartitionMap;      /**< @brief Pointer to channel to partition mapping */
    const uint32 * pau32Dio_PortToPartitionMap;         /**< @brief Pointer to port to partition mapping */
} Dio_ConfigType;

/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/
#define DIO_START_SEC_CONST_32
#include "Dio_MemMap.h"
/**
* @brief Array containing list of mapping channel for partition
*/
extern const uint32 Dio_au32ChannelToPartitionMap[DIO_CHANNEL_PARTITION_U16];

/**
* @brief Array containing list of mapping port for partition
*/
extern const uint32 Dio_au32PortToPartitionMap[DIO_PORT_PARTITION_U16];

/**
* @brief Array of bitmaps of output pins available per port
*/
extern const Dio_PortLevelType Dio_aAvailablePinsForWrite[DIO_NUM_PORTS_U16];

/**
* @brief Array of bitmaps of input pins available per port
*/
extern const Dio_PortLevelType Dio_aAvailablePinsForRead[DIO_NUM_PORTS_U16];

#define DIO_STOP_SEC_CONST_32
#include "Dio_MemMap.h"

#define DIO_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dio_MemMap.h"

/**
* @brief          List of channel groups in configuration DioConfig.
*/
extern const Dio_ChannelGroupType DioConfig_aChannelGroupList[1];

/**
* @brief          List of channel groups mapping with partition in configuration DioConfig.
*/
extern const Dio_ChannelGroupType * const Dio_pxChannelGroupsListForEachPartition[1][1];

#define DIO_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Dio_MemMap.h"
/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* DIO_CFG_H */

/** @} */
