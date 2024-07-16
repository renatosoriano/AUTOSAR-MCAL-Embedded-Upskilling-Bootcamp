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

#ifndef PORT_CI_PORT_IP_TYPES_H
#define PORT_CI_PORT_IP_TYPES_H

/**
*   @file    Port_Ci_Port_Ip_Types.h
*
*   @addtogroup Port_IPL
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
#include "Port_Ci_Port_Ip_Defines.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief        Parameters that shall be published within the Port driver header file and also in the
*               module description file
* @details      The integration of incompatible files shall be avoided.
*
*/
#define PORT_CI_PORT_IP_VENDOR_ID_TYPES_H                       43
#define PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_TYPES_H        4
#define PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_TYPES_H        7
#define PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_TYPES_H     0
#define PORT_CI_PORT_IP_SW_MAJOR_VERSION_TYPES_H                2
#define PORT_CI_PORT_IP_SW_MINOR_VERSION_TYPES_H                0
#define PORT_CI_PORT_IP_SW_PATCH_VERSION_TYPES_H                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if the files Port_Ci_Port_Ip_Types.h and Port_Ci_Port_Ip_Defines.h are of the same vendor */
#if (PORT_CI_PORT_IP_VENDOR_ID_TYPES_H != PORT_CI_PORT_IP_VENDOR_ID_DEFINES_H)
    #error "Port_Ci_Port_Ip_Types.h and Port_Ci_Port_Ip_Defines.h have different vendor ids"
#endif
/* Check if the files Port_Ci_Port_Ip_Types.h and Port_Ci_Port_Ip_Defines.h are of the same Autosar version */
#if ((PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_TYPES_H    != PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_DEFINES_H)  || \
     (PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_TYPES_H    != PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_DEFINES_H)  || \
     (PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_TYPES_H != PORT_CI_PORT_IP_AR_RELEASE_REVISION_VERSION_DEFINES_H)  \
    )
    #error "AutoSar Version Numbers of Port_Ci_Port_Ip_Types.h and Port_Ci_Port_Ip_Defines.h are different"
#endif
/* Check if the files Port_Ci_Port_Ip_Types.h and Port_Ci_Port_Ip_Defines.h are of the same software version */
#if ((PORT_CI_PORT_IP_SW_MAJOR_VERSION_TYPES_H != PORT_CI_PORT_IP_SW_MAJOR_VERSION_DEFINES_H) || \
     (PORT_CI_PORT_IP_SW_MINOR_VERSION_TYPES_H != PORT_CI_PORT_IP_SW_MINOR_VERSION_DEFINES_H) || \
     (PORT_CI_PORT_IP_SW_PATCH_VERSION_TYPES_H != PORT_CI_PORT_IP_SW_PATCH_VERSION_DEFINES_H)    \
    )
    #error "Software Version Numbers of Port_Ci_Port_Ip_Types.h and Port_Ci_Port_Ip_Defines.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the files Port_Ci_Port_Ip_Types.h and StandardTypes.h are of the same version */
    #if ((PORT_CI_PORT_IP_AR_RELEASE_MAJOR_VERSION_TYPES_H != STD_AR_RELEASE_MAJOR_VERSION) || \
         (PORT_CI_PORT_IP_AR_RELEASE_MINOR_VERSION_TYPES_H  != STD_AR_RELEASE_MINOR_VERSION)   \
        )
        #error "AutoSar Version Numbers of Port_Ci_Port_Ip_Types.h and StandardTypes.h are different"
    #endif
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#define GPIO_PORT_U32(channel)                     ((uint32)((uint32)(channel) >> 5))
#define GPIO_CHANNEL_U32(channel)                  ((uint32)((uint32)(channel) & (uint32)31))
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/*!
 * @brief Type of a port levels representation.
 * Implements : Port_Ci_Port_Ip_PortPinsLevelType
 */
typedef uint8 Port_Ci_Port_Ip_PortPinsLevelType;

/*!
 * @brief Internal resistor pull feature selection
 * Implements : Port_Ci_Port_Ip_PortPullConfig
 */
typedef enum
{
    PORT_INTERNAL_PULL_DOWN_ENABLED      = 0U,  /*!< internal pull-down resistor is enabled.     */
    PORT_INTERNAL_PULL_UP_ENABLED        = 1U,  /*!< internal pull-up resistor is enabled.       */
    PORT_INTERNAL_PULL_NOT_ENABLED       = 2U   /*!< internal pull-down/up resistor is disabled. */
} Port_Ci_Port_Ip_PortPullConfig;

/*!
 * @brief Configures the slew rate control.
 * Implements : Port_Ci_Port_Ip_PortSlewRateControl
 */
#ifdef FEATURE_PORT_CI_PORT_IP_HAS_SLEW_RATE
typedef enum
{
    PORT_FAST_SLEW_RATE                = 0U, /*!< Fast slew rate is configured on the corresponding pin, if the pin is configured as a digital output.  */
    PORT_SLOW_SLEW_RATE                = 1U  /*!< Slow slew rate is configured on the corresponding pin, if the pin is configured as a digital output.  */
} Port_Ci_Port_Ip_PortSlewRateControl;
#endif /* FEATURE_PORT_CI_PORT_IP_HAS_SLEW_RATE */

/*!
 * @brief Configures the Pin output muxing selection
 * Implements : Port_Ci_Port_Ip_PortMux
 */
typedef enum
{
    PORT_MUX_ALT0               = 0U,   /*!< DISABLED or ALT0 mode */
    PORT_MUX_AS_GPIO            = 1U,   /*!< corresponding pin is configured as GPIO */
    PORT_MUX_ALT2               = 2U,   /*!< chip-specific                           */
    PORT_MUX_ALT3               = 3U,   /*!< chip-specific                           */
    PORT_MUX_ALT4               = 4U,   /*!< chip-specific                           */
    PORT_MUX_ALT5               = 5U,   /*!< chip-specific                           */
    PORT_MUX_ALT6               = 6U,   /*!< chip-specific                           */
    PORT_MUX_ALT7               = 7U,   /*!< chip-specific                           */
    PORT_MUX_ADC_INTERLEAVE     = 8U    /*!< chip-specific                           */
} Port_Ci_Port_Ip_PortMux;

typedef enum
{
    PORT_GLOBAL_CONTROL_LOWER_HALF_PINS = 0U, /*!< the lower of pins is configured */
    PORT_GLOBAL_CONTROL_UPPER_HALF_PINS = 1U  /*!< the upper of pins is configured */
} Port_Ci_Port_Ip_PortGlobalControlPins;

#ifdef FEATURE_PORT_CI_PORT_IP_HAS_LOCK_REGISTER
/*!
 * @brief Configures the Lock Register enable
 * Implements : Port_Ci_Port_Ip_PortLockRegister
 */
typedef enum
{
    PORT_LOCK_REGISTER_DISABLED     = 0U, /*!< IFE OFF*/
    PORT_LOCK_REGISTER_ENABLED      = 1U  /*!< IFE ON*/
} Port_Ci_Port_Ip_PortLockRegister;
#endif /* FEATURE_PORT_CI_PORT_IP_HAS_LOCK_REGISTER */

#ifdef FEATURE_PORT_CI_PORT_IP_HAS_OPEN_DRAIN
/*!
 * @brief Configures the Open Drain Enable field.
 * Implements : Port_Ci_Port_Ip_PortOpenDrain
 */
typedef enum
{
    PORT_OPEN_DRAIN_DISABLED     = 0U, /*!< ODE OFF */
    PORT_OPEN_DRAIN_ENABLED      = 1U  /*!< ODE ON */
} Port_Ci_Port_Ip_PortOpenDrain;
#endif /* FEATURE_PORT_CI_PORT_IP_HAS_OPEN_DRAIN */

#ifdef FEATURE_PORT_CI_HAS_INPUT_HYSTERESYS
/*!
 * @brief Configures the Hysteresis Enable field.
 * Implements : Port_Ci_Port_Ip_PortHysteresis
 */
typedef enum
{
    PORT_HYSTERESYS_DISABLED     = 0U, /*!< Input Hysteresis disabled */
    PORT_HYSTERESYS_ENABLED      = 1U  /*!< Input Hysteresis enabled  */
} Port_Ci_Port_Ip_PortHysteresis;
#endif /* FEATURE_PORT_CI_HAS_INPUT_HYSTERESYS */

#ifdef FEATURE_PORT_CI_HAS_AE_INSTANCE
/*!
 * @brief Configures the Analog Pad Control.
 * Implements : Port_Ci_Port_Ip_PortAnalogPad
 */
typedef enum
{
    PORT_ANALOG_PAD_CONTROL_DISABLED = 0U, /*!< Disable (the switch is off)                                 */
    PORT_ANALOG_PAD_CONTROL_ENABLED  = 1U  /*!< Enable (another module can control the state of the switch) */
} Port_Ci_Port_Ip_PortAnalogPad;
#endif /* FEATURE_PORT_CI_HAS_AE_INSTANCE */

#ifdef FEATURE_PORT_CI_PORT_IP_HAS_DRIVE_STRENGTH
/*!
 * @brief Configures the drive strength.
 * Implements : Port_Ci_Port_Ip_PortDriveStrength
 */
typedef enum
{
    PORT_DRIVE_STRENGTH_LOW    = 0U, /*!< Enables DSE. */
    PORT_DRIVE_STRENGTH_HIGH   = 1U  /*!< Enables DSE.*/
} Port_Ci_Port_Ip_PortDriveStrength;
#endif /* FEATURE_PORT_CI_PORT_IP_HAS_DRIVE_STRENGTH */

typedef enum
{
   PORT_CI_PORT_SUCCESS = E_OK,
   PORT_CI_PORT_ERROR = E_NOT_OK
}Port_Ci_Port_Ip_PortStatusType;

typedef struct
{
    uint8   u8Port;                         /**< Digital Filter Port */
    uint8   u8Clock;                        /**< Digital Filter Clock */
    uint8   u8Width;                        /**< Digital Filter Width */
    uint32  u32PinMask;                     /**< Mask of pins for which digital filter is enabled */
} Port_Ci_Port_Ip_DigitalFilterConfigType;

/*!
 * @brief Configures port direction.
 */
typedef enum
{
    PORT_CI_PORT_PIN_DISABLED  = 0U,        /**< @brief Sets port pin as disable or ALT0 mode. */
    PORT_CI_PORT_PIN_IN        = 1U,        /**< @brief Sets port pin as output. */
    PORT_CI_PORT_PIN_OUT       = 2U,        /**< @brief Sets port pin as bidirectional. */
    PORT_CI_PORT_PIN_HIGH_Z    = 3U         /**< @brief Sets port pin as high_z. */
} Port_Ci_Port_Ip_PortDirectionType;

/*!
 * @brief Defines the converter configuration
 *
 * This structure is used to configure the pins
 * Implements : Port_Ci_Port_Ip_PinSettingsConfig
 */
typedef struct
{
    PORT_Type                             *portBase;          /*!< The main PORT base pointer.                                */
    GPIO_Type                             *gpioBase;          /*!< The main GPIO base pointer.                                */
    uint32                                 pinPortIdx;        /*!< Port pin number in a port.                                 */
    Port_Ci_Port_Ip_PortPullConfig         pullConfig;        /*!< Internal resistor pull feature selection.                  */
    Port_Ci_Port_Ip_PortMux                mux;               /*!< Pin output muxing selection.                               */
    Port_Ci_Port_Ip_PortDirectionType      direction;         /*!< Pin output muxing selection.                               */
#ifdef FEATURE_PORT_CI_PORT_IP_HAS_DRIVE_STRENGTH
    Port_Ci_Port_Ip_PortDriveStrength      driveStrength;     /*!< Configures DSE.                                            */
#endif /* FEATURE_PORT_CI_PORT_IP_HAS_DRIVE_STRENGTH */
    boolean                                passiveFilter;     /*!< Configures DFE.                                            */
#ifdef FEATURE_PORT_CI_PORT_IP_HAS_SLEW_RATE
    Port_Ci_Port_Ip_PortSlewRateControl    slewRateCtrlSel;   /*!< Configures SRE.                                            */
#endif /* FEATURE_PORT_CI_PORT_IP_HAS_SLEW_RATE */

#ifdef FEATURE_PORT_CI_PORT_IP_HAS_LOCK_REGISTER
    Port_Ci_Port_Ip_PortLockRegister       lockRegister;      /*!< Configures LK.                                             */
#endif /* FEATURE_PORT_CI_PORT_IP_HAS_LOCK_REGISTER */

#ifdef FEATURE_PORT_CI_PORT_IP_HAS_OPEN_DRAIN
    Port_Ci_Port_Ip_PortOpenDrain          openDrain;         /*!< Configures ODE.                                            */
#endif /* FEATURE_PORT_CI_PORT_IP_HAS_OPEN_DRAIN */

    boolean                                digitalFilter;     /*!< Configures digitalFilter.                                  */
    Port_Ci_Port_Ip_PortPinsLevelType      initValue;         /*!< Initial value.                                             */
} Port_Ci_Port_Ip_PinSettingsConfig;

#ifdef FEATURE_PORT_CI_PORT_IP_HAS_ADC_INTERLEAVE
typedef enum
{
    PIN_ADC_INTERLEAVE_DISABLE0    = 0xEU,   /*!< xxx0b ADC1_SE14 channel is connected to PTB15 */
    PIN_ADC_INTERLEAVE_DISABLE1    = 0xDU,   /*!< xx0xb ADC1_SE15 channel is connected to PTB16 */
    PIN_ADC_INTERLEAVE_DISABLE2    = 0xBU,   /*!< x0xxb ADC0_SE8  channel is connected to PTC0  */
    PIN_ADC_INTERLEAVE_DISABLE3    = 0x7U,   /*!< 0xxxb ADC0_SE9  channel is connected to PTC1  */
    PIN_ADC_INTERLEAVE_ENABLE0     = 0x1U,   /*!< xxx1b ADC1_SE14 channel is connected to PTB0  */
    PIN_ADC_INTERLEAVE_ENABLE1     = 0x2U,   /*!< xx1xb ADC1_SE15 channel is connected to PTB1  */
    PIN_ADC_INTERLEAVE_ENABLE2     = 0x4U,   /*!< x1xxb ADC0_SE8  channel is connected to PTB13 */
    PIN_ADC_INTERLEAVE_ENABLE3     = 0x8U,   /*!< 1xxxb ADC0_SE9  channel is connected to PTB14 */
    PIN_ADC_INTERLEAVE_INVALID     = 0xFFU   /*!< ADC interleave is invalid                     */
} Port_Ci_Port_Ip_InterleaveMux;
#endif /* FEATURE_PORT_CI_PORT_IP_HAS_ADC_INTERLEAVE */

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#if defined(__cplusplus)
}
#endif

/** @} */

#endif /* PORT_CI_PORT_IP_TYPES_H */
