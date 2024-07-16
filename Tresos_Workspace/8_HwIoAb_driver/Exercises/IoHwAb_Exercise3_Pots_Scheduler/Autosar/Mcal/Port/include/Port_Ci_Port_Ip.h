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

#ifndef PORT_CI_PORT_IP_H
#define PORT_CI_PORT_IP_H

/**
*   @file    Port_Ci_Port_Ip.h
*
*   @defgroup Port_IPL Port IPL
*   @{
*/

#if defined(__cplusplus)
extern "C" {
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Std_Types.h"
#include "Port_Ci_Port_Ip_Cfg.h"
#include "Port_Ci_Port_Ip_Types.h"
#include "Port_Ci_Port_Ip_Defines.h"
#include "Devassert.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module description file
* @details      The integration of incompatible files shall be avoided.
*
*/
#define PORT_CI_PORT_IP_VENDOR_ID_H                       43
#define PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_H        4
#define PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_H        7
#define PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_H     0
#define PORT_CI_PORT_IP_SW_MAJOR_VERSION_H                2
#define PORT_CI_PORT_IP_SW_MINOR_VERSION_H                0
#define PORT_CI_PORT_IP_SW_PATCH_VERSION_H                0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Cfg.h are of the same vendor */
#if (PORT_CI_PORT_IP_VENDOR_ID_H != PORT_CI_PORT_IP_VENDOR_ID_CFG_H)
    #error "Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Cfg.h have different vendor ids"
#endif
/* Check if the files Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Cfg.h are of the same Autosar version */
#if ((PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_H    != PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_CFG_H)  || \
     (PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_H    != PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_CFG_H)  || \
     (PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_H != PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_CFG_H)  \
    )
    #error "AutoSar Version Numbers of Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Cfg.h are different"
#endif
/* Check if the files Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Cfg.h are of the same software version */
#if ((PORT_CI_PORT_IP_SW_MAJOR_VERSION_H != PORT_CI_PORT_IP_SW_MAJOR_VERSION_CFG_H) || \
     (PORT_CI_PORT_IP_SW_MINOR_VERSION_H != PORT_CI_PORT_IP_SW_MINOR_VERSION_CFG_H) || \
     (PORT_CI_PORT_IP_SW_PATCH_VERSION_H != PORT_CI_PORT_IP_SW_PATCH_VERSION_CFG_H)    \
    )
    #error "Software Version Numbers of Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Cfg.h are different"
#endif

/* Check if the files Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Types.h are of the same vendor */
#if (PORT_CI_PORT_IP_VENDOR_ID_H != PORT_CI_PORT_IP_VENDOR_ID_TYPES_H)
    #error "Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Types.h have different vendor ids"
#endif
/* Check if the files Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Types.h are of the same Autosar version */
#if ((PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_H    != PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_TYPES_H)  || \
     (PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_H    != PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_TYPES_H)  || \
     (PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_H != PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_TYPES_H)  \
    )
    #error "AutoSar Version Numbers of Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Types.h are different"
#endif
/* Check if the files Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Types.h are of the same software version */
#if ((PORT_CI_PORT_IP_SW_MAJOR_VERSION_H != PORT_CI_PORT_IP_SW_MAJOR_VERSION_TYPES_H) || \
     (PORT_CI_PORT_IP_SW_MINOR_VERSION_H != PORT_CI_PORT_IP_SW_MINOR_VERSION_TYPES_H) || \
     (PORT_CI_PORT_IP_SW_PATCH_VERSION_H != PORT_CI_PORT_IP_SW_PATCH_VERSION_TYPES_H)    \
    )
    #error "Software Version Numbers of Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Types.h are different"
#endif

/* Check if the files Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Defines.h are of the same vendor */
#if (PORT_CI_PORT_IP_VENDOR_ID_H != PORT_CI_PORT_IP_VENDOR_ID_DEFINES_H)
    #error "Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Defines.h have different vendor ids"
#endif
/* Check if the files Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Defines.h are of the same Autosar version */
#if ((PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_H    != PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_DEFINES_H)  || \
     (PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_H    != PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_DEFINES_H)  || \
     (PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_H != PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_DEFINES_H)  \
    )
    #error "AutoSar Version Numbers of Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Defines.h are different"
#endif
/* Check if the files Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Defines.h are of the same software version */
#if ((PORT_CI_PORT_IP_SW_MAJOR_VERSION_H != PORT_CI_PORT_IP_SW_MAJOR_VERSION_DEFINES_H) || \
     (PORT_CI_PORT_IP_SW_MINOR_VERSION_H != PORT_CI_PORT_IP_SW_MINOR_VERSION_DEFINES_H) || \
     (PORT_CI_PORT_IP_SW_PATCH_VERSION_H != PORT_CI_PORT_IP_SW_PATCH_VERSION_DEFINES_H)    \
    )
    #error "Software Version Numbers of Port_Ci_Port_Ip.h and Port_Ci_Port_Ip_Defines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the files Port_Ci_Port_Ip.h and StandardTypes.h are of the same version */
    #if ((PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_H != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_H  != STD_AR_RELEASE_MINOR_VERSION)   \
        )
        #error "AutoSar Version Numbers of Port_Ci_Port_Ip.h and StandardTypes.h are different"
    #endif

    /* Check if the files Port_Ci_Port_Ip.h and Devassert.h are of the same version */
    #if ((PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_H != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
         (PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_H  != DEVASSERT_AR_RELEASE_MINOR_VERSION)   \
        )
        #error "AutoSar Version Numbers of Port_Ci_Port_Ip.h and Devassert.h are different"
    #endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
#define PORT_START_SEC_CONST_32
#include "Port_MemMap.h"

extern PORT_Type * const Port_au32PortCiPortBaseAddr[PORT_INSTANCE_COUNT];
extern GPIO_Type * const Port_au32PortCiGpioBaseAddr[PORT_INSTANCE_COUNT];

#define PORT_STOP_SEC_CONST_32
#include "Port_MemMap.h"

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#if (PORT_CI_PORT_IP_DEV_ERROR_DETECT == STD_ON)
#define PORT_CI_PORT_DEV_ASSERT(par) DevAssert(par)
#else
#define PORT_CI_PORT_DEV_ASSERT(par)
#endif

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/
/* @brief Allocate defined section for PORT code. */
#define PORT_START_SEC_CODE
#include "Port_MemMap.h"

/*!
 * @brief Initializes the pins with the given configuration structure
 *
 * This function configures the pins with the options provided in the
 * provided structure.
 *
 * @param[in] pinCount The number of configured pins in structure
 * @param[in] config The configuration structure
 * @return The status of the operation
 */
Port_Ci_Port_Ip_PortStatusType Port_Ci_Port_Ip_Init
(
    uint32 pinCount,
    const Port_Ci_Port_Ip_PinSettingsConfig config[]
);

/*!
 * @brief Configures the pin muxing.
 *
 * This function configures the pin muxing.
 *
 * @param[in] base Port base pointer (PORTA, PORTB, PORTC, etc.)
 * @param[in] pin Port pin number
 * @param[in] mux Pin muxing slot selection
 */
void Port_Ci_Port_Ip_SetMuxModeSel
(
    PORT_Type * const base,
    uint32 pin,
    Port_Ci_Port_Ip_PortMux mux
);

/*!
 * @brief Enables digital filter for digital pin muxing
 *
 * This function enables digital filter feature for digital pin muxing
 *
 * @param[in] base Port base pointer (PORTA, PORTB, PORTC, etc.)
 * @param[in] pin Port pin number
 */
void Port_Ci_Port_Ip_EnableDigitalFilter
(
    PORT_Type * const base,
    uint32 pin
);

/*!
 * @brief Disables digital filter for digital pin muxing
 *
 * This function disables digital filter feature for digital pin muxing
 *
 * @param[in] base Port base pointer (PORTA, PORTB, PORTC, etc.)
 * @param[in] pin Port pin number
 */
void Port_Ci_Port_Ip_DisableDigitalFilter
(
    PORT_Type * const base,
    uint32 pin
);

/*!
 * @brief Configures digital filter for port with given configuration
 *
 * This function configures digital filter for port with given configuration
 *
 * Note: Updating the filter configuration must be done only after all filters are disabled.
 *
 * @param[in] base Port base pointer (PORTA, PORTB, PORTC, etc.)
 * @param[in] config the digital filter configuration struct
 */
void Port_Ci_Port_Ip_ConfigDigitalFilter
(
    PORT_Type * const base,
    const Port_Ci_Port_Ip_DigitalFilterConfigType * config
);

/*!
 * @brief Quickly configures multiple pins with the same pin configuration.
 *
 * This function quickly configures multiple pins within the one port for the same peripheral
 * function with the same pin configuration. Supports up to 16 pins with the lower or upper
 * half of pin registers at the same port.
 *
 * @param[in] base Port base pointer (PORTA, PORTB, PORTC, etc.)
 * @param[in] pins Pin mask where each bit represents one pin. For each bit:
 *        - 0: pins corresponding to bits with value of '1' is updated with the value input
 *        - 1: pins corresponding to bits with value of '0' is not updated with the value input
 * @param[in] value the config value will be updated for the pins are set to '1'
 * @param[in] halfPort the lower or upper half of pin registers at the same port
 */
void Port_Ci_Port_Ip_SetGlobalPinControl
(
    PORT_Type * const base,
    uint16 pins,
    uint16 value,
    Port_Ci_Port_Ip_PortGlobalControlPins halfPort
);
#define PORT_STOP_SEC_CODE
#include "Port_MemMap.h"

#if defined(__cplusplus)
}
#endif

/** @} */

#endif /* PORT_CI_PORT_IP_H */
