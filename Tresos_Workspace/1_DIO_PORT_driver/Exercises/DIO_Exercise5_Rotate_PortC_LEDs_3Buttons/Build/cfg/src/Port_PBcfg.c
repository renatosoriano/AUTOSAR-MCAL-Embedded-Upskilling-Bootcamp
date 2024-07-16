/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : PORT_CI
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
*   @file    Port_PBcfg.c
*
*   @implements Port_PBcfg.c_Artifact
*   @addtogroup Port_CFG
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
#include "Port.h"


/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module description file
* @details      The integration of incompatible files shall be avoided.
*
*/
#define PORT_VENDOR_ID_PBCFG_C                       43
#define PORT_AR_RELEASE_MAJOR_VERSION_PBCFG_C        4
#define PORT_AR_RELEASE_MINOR_VERSION_PBCFG_C        7
#define PORT_AR_RELEASE_REVISION_VERSION_PBCFG_C     0
#define PORT_SW_MAJOR_VERSION_PBCFG_C                2
#define PORT_SW_MINOR_VERSION_PBCFG_C                0
#define PORT_SW_PATCH_VERSION_PBCFG_C                0

/*=================================================================================================
*                                      FILE VERSION CHECKS
=================================================================================================*/
/* Check if the files Port_PBcfg.c and Port.h are of the same vendor */
#if (PORT_VENDOR_ID_PBCFG_C != PORT_VENDOR_ID)
    #error "Port_PBcfg.c and Port.h have different vendor ids"
#endif
/* Check if the files Port_PBcfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != PORT_AR_RELEASE_MAJOR_VERSION)  || \
     (PORT_AR_RELEASE_MINOR_VERSION_PBCFG_C    != PORT_AR_RELEASE_MINOR_VERSION)  || \
     (PORT_AR_RELEASE_REVISION_VERSION_PBCFG_C != PORT_AR_RELEASE_REVISION_VERSION)  \
    )
    #error "AutoSar Version Numbers of Port_PBcfg.c and Port.h are different"
#endif
/* Check if the files Port_PBcfg.c and Port.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_PBCFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_PBCFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_PBCFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_PBcfg.c and Port.h are different"
#endif

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/
/**
* @brief The number of configured Digital Filter Ports
*/
#define PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS_U8         (0U)

/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/

#define PORT_START_SEC_CONFIG_DATA_8
#include "Port_MemMap.h"
/**
* @brief Array containing list of partition which used in driver
*/
static const uint8 au8Port_PartitionList[PORT_MAX_PARTITION] =
{
    (uint8)1
};
#define PORT_STOP_SEC_CONFIG_DATA_8
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_32
#include "Port_MemMap.h"
/**
* @brief Array containing list of mapping information for mappable elements
*/
static const uint32 au32Port_PinToPartitionMap[PORT_MAX_CONFIGURED_PADS_U16] =
{
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001,
    (uint32)0x00000001
};
#define PORT_STOP_SEC_CONFIG_DATA_32
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_16
#include "Port_MemMap.h"

#if (0UL != PORT_MAX_UNUSED_PADS_U16)
/**
* @brief NoDefaultPadsArray is an array containing Unimplemented pads and User pads
*/
static const uint16 Port_au16NoUnUsedPadsArrayDefault[PORT_MAX_UNUSED_PADS_U16]=
{
    (uint16)0,
    (uint16)1,
    (uint16)2,
    (uint16)3,
    (uint16)6,
    (uint16)7,
    (uint16)8,
    (uint16)9,
    (uint16)11,
    (uint16)13,
    (uint16)14,
    (uint16)15,
    (uint16)16,
    (uint16)17,
    (uint16)32,
    (uint16)33,
    (uint16)34,
    (uint16)35,
    (uint16)36,
    (uint16)37,
    (uint16)38,
    (uint16)39,
    (uint16)40,
    (uint16)41,
    (uint16)42,
    (uint16)43,
    (uint16)44,
    (uint16)45,
    (uint16)46,
    (uint16)47,
    (uint16)48,
    (uint16)49,
    (uint16)64,
    (uint16)65,
    (uint16)66,
    (uint16)67,
    (uint16)70,
    (uint16)71,
    (uint16)80,
    (uint16)81,
    (uint16)96,
    (uint16)97,
    (uint16)98,
    (uint16)99,
    (uint16)100,
    (uint16)101,
    (uint16)102,
    (uint16)103,
    (uint16)104,
    (uint16)105,
    (uint16)106,
    (uint16)107,
    (uint16)108,
    (uint16)109,
    (uint16)110,
    (uint16)111,
    (uint16)112,
    (uint16)128,
    (uint16)129,
    (uint16)130,
    (uint16)131,
    (uint16)132,
    (uint16)133,
    (uint16)134,
    (uint16)135,
    (uint16)136,
    (uint16)137,
    (uint16)138,
    (uint16)139,
    (uint16)141,
    (uint16)142,
    (uint16)143,
    (uint16)144
};
#endif

#define PORT_STOP_SEC_CONFIG_DATA_16
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"
/**
 * @brief Default Configuration for Pins not initialized
 */
static const Port_UnUsedPinConfigType Port_UnUsedPin =
{
    /* @note: Configuration of Default pin */
    (uint32)0x00000100, (Port_PinDirectionType)1, (uint8)0
};

/**
* @brief Pin default configuration data for configPB
*/
static const Port_PinConfigType Port_aPinConfigDefault[PORT_MAX_CONFIGURED_PADS_U16]=
{
    /* PCR Id, PCR Value, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable */
    {(uint16)72, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)2, (boolean)TRUE, (boolean)FALSE, (boolean)TRUE},
    /* PCR Id, PCR Value, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable */
    {(uint16)73, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)2, (boolean)TRUE, (boolean)FALSE, (boolean)TRUE},
    /* PCR Id, PCR Value, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable */
    {(uint16)74, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)2, (boolean)TRUE, (boolean)FALSE, (boolean)TRUE},
    /* PCR Id, PCR Value, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable */
    {(uint16)75, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)2, (boolean)TRUE, (boolean)FALSE, (boolean)TRUE},
    /* PCR Id, PCR Value, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable */
    {(uint16)76, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)2, (boolean)TRUE, (boolean)FALSE, (boolean)TRUE},
    /* PCR Id, PCR Value, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable */
    {(uint16)77, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)2, (boolean)TRUE, (boolean)FALSE, (boolean)TRUE},
    /* PCR Id, PCR Value, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable */
    {(uint16)78, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)2, (boolean)TRUE, (boolean)FALSE, (boolean)TRUE},
    /* PCR Id, PCR Value, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable */
    {(uint16)79, (uint32)0x00000100, (uint8)0, (Port_PinDirectionType)2, (boolean)TRUE, (boolean)FALSE, (boolean)TRUE},
    /* PCR Id, PCR Value, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable */
    {(uint16)113, (uint32)0x00000102, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)FALSE, (boolean)TRUE},
    /* PCR Id, PCR Value, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable */
    {(uint16)140, (uint32)0x00000102, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)FALSE, (boolean)TRUE},
    /* PCR Id, PCR Value, Output Level, Direction, IsGpio, Direction Configurable, Mode Changeable */
    {(uint16)12, (uint32)0x00000102, (uint8)0, (Port_PinDirectionType)1, (boolean)TRUE, (boolean)FALSE, (boolean)TRUE}

};

#if (0UL != PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS_U8)
static const Port_Ci_Port_Ip_DigitalFilterConfigType Port_aDigitalFilter[PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS_U8]=
{

};
#endif /* (0UL != PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS_U8) */

/**
* @brief This table contains all the Configured Port Pin parameters and the
*        number of Port Pins configured by the tool for the post-build mode
* that will be used by the upper layers.
*/
const Port_ConfigType Port_Config =
{
    PORT_MAX_CONFIGURED_PADS_U16,
    PORT_MAX_UNUSED_PADS_U16,
#if (0UL != PORT_MAX_UNUSED_PADS_U16)
    Port_au16NoUnUsedPadsArrayDefault,
#else
    NULL_PTR,
#endif
    &Port_UnUsedPin,
    Port_aPinConfigDefault,
    PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS_U8,
#if (0UL != PORT_MAX_CONFIGURED_DIGITAL_FILTER_PORTS_U8)
    Port_aDigitalFilter,
#else
    NULL_PTR,
#endif
    au32Port_PinToPartitionMap,
    au8Port_PartitionList,
    g_pin_mux_InitConfigArr
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "Port_MemMap.h"
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


#ifdef __cplusplus
}
#endif
/** @} */

/* End of File */
