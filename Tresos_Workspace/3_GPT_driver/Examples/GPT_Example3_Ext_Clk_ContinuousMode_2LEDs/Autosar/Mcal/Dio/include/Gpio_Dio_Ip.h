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

#ifndef GPIO_DIO_IP_H
#define GPIO_DIO_IP_H

/**
*   @file @file Gpio_Dio_Ip.h
*
*   @defgroup DIO_IPL Dio IPL
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
#include "Gpio_Dio_Ip_Cfg.h"

/*=================================================================================================
*                               SOURCE FILE VERSION INFORMATION
=================================================================================================*/

#define GPIO_DIO_IP_VENDOR_ID_H                     43
#define GPIO_DIO_IP_AR_RELEASE_MAJOR_VERSION_H      4
#define GPIO_DIO_IP_AR_RELEASE_MINOR_VERSION_H      7
#define GPIO_DIO_IP_AR_RELEASE_REVISION_VERSION_H   0
#define GPIO_DIO_IP_SW_MAJOR_VERSION_H              2
#define GPIO_DIO_IP_SW_MINOR_VERSION_H              0
#define GPIO_DIO_IP_SW_PATCH_VERSION_H              0

/*=================================================================================================
                                      FILE VERSION CHECKS
=================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Gpio_Dio_Ip header file and StandardTypes.h header file are of the same release version */
    #if ((GPIO_DIO_IP_AR_RELEASE_MAJOR_VERSION_H != STD_AR_RELEASE_MAJOR_VERSION) || \
        (GPIO_DIO_IP_AR_RELEASE_MINOR_VERSION_H != STD_AR_RELEASE_MINOR_VERSION)     \
        )
        #error "AutoSar Version Numbers of Gpio_Dio_Ip.h and StandardTypes.h are different"
    #endif
#endif

/* Check if Gpio_Dio_Ip header file and Gpio_Dio_Ip_Cfg configuration header file are of the same vendor */
#if (GPIO_DIO_IP_VENDOR_ID_H != GPIO_DIO_IP_VENDOR_ID_CFG_H)
    #error "Gpio_Dio_Ip.h and Gpio_Dio_Ip_Cfg.h have different vendor ids"
#endif

/* Check if Gpio_Dio_Ip header file and Gpio_Dio_Ip_Cfg configuration header file are of the same Autosar version */
#if ((GPIO_DIO_IP_AR_RELEASE_MAJOR_VERSION_H    != GPIO_DIO_IP_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (GPIO_DIO_IP_AR_RELEASE_MINOR_VERSION_H    != GPIO_DIO_IP_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (GPIO_DIO_IP_AR_RELEASE_REVISION_VERSION_H != GPIO_DIO_IP_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
    #error "AutoSar Version Numbers of Gpio_Dio_Ip.h and Gpio_Dio_Ip_Cfg.h are different"
#endif

/* Check if Gpio_Dio_Ip header file and Gpio_Dio_Ip_Cfg configuration header file are of the same Software version */
#if ((GPIO_DIO_IP_SW_MAJOR_VERSION_H != GPIO_DIO_IP_SW_MAJOR_VERSION_CFG_H) || \
     (GPIO_DIO_IP_SW_MINOR_VERSION_H != GPIO_DIO_IP_SW_MINOR_VERSION_CFG_H) || \
     (GPIO_DIO_IP_SW_PATCH_VERSION_H != GPIO_DIO_IP_SW_PATCH_VERSION_CFG_H)    \
    )
    #error "Software Version Numbers of Gpio_Dio_Ip.h and Gpio_Dio_Ip_Cfg.h are different"
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/
#define GPIO_DIO_IP_CHANNEL_MASK_U32                                ((uint32)0x1F)
#define GPIO_DIO_IP_PORTID_SHIFT_U8                                 ((uint8)5U)

#define GPIO_DIO_IP_PORT_U32(channel)                               ((uint32)((uint32)(channel)>>GPIO_DIO_IP_PORTID_SHIFT_U8))

#define GPIO_DIO_IP_CHANNEL_U32(channel)                            ((uint32)((uint32)(channel)&GPIO_DIO_IP_CHANNEL_MASK_U32))

/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/
/*!
 * @brief Type of a GPIO channel representation
 * Implements : Gpio_Dio_Ip_PinsChannelType_Class
 */
typedef uint32 Gpio_Dio_Ip_PinsChannelType;

/*!
 * @brief Type of a port levels representation.
 * Implements : Gpio_Dio_Ip_PinsLevelType_Class
 */
typedef uint8 Gpio_Dio_Ip_PinsLevelType;

/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/
#define DIO_START_SEC_VAR_INIT_32
#include "Dio_MemMap.h"

extern uint32 GpioBaseAdresses[GPIO_INSTANCE_COUNT];

#define DIO_STOP_SEC_VAR_INIT_32
#include "Dio_MemMap.h"

/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
/*!
 * @brief Write a pin of a port with a given value
 *
 * This function writes the given pin from a port, with the given value
 * ('0' represents LOW, '1' represents HIGH).
 *
 * @param base  GPIO base pointer (PTA, PTB, PTC, etc.)
 * @param pin pin number to be written
 * @param value pin value to be written
 *        - 0: corresponding pin is set to LOW
 *        - 1: corresponding pin is set to HIGH
 */
void Gpio_Dio_Ip_WritePin
(
    GPIO_Type * const base,
    Gpio_Dio_Ip_PinsChannelType pin,
    Gpio_Dio_Ip_PinsLevelType value
);

/*!
 * @brief Write all pins of a port
 *
 * This function writes all pins configured as output with the values given in
 * the parameter pins. '0' represents LOW, '1' represents HIGH.
 *
 * @param[in] base GPIO base pointer (PTA, PTB, PTC, etc.)
 * @param[in] pins Pin mask to be written
 *        - 0: corresponding pin is set to LOW
 *        - 1: corresponding pin is set to HIGH
 */
void Gpio_Dio_Ip_WritePins
(
    GPIO_Type * const base,
    Gpio_Dio_Ip_PinsChannelType pins
);

/*!
 * @brief Get the current output from a port
 *
 * This function returns the current output that is written to a port. Only pins
 * that are configured as output will have meaningful values.
 *
 * @param[in] base GPIO base pointer (PTA, PTB, PTC, etc.)
 * @return GPIO outputs. Each bit represents one pin (LSB is pin 0, MSB is pin
 * 31). For each bit:
 *        - 0: corresponding pin is set to LOW
 *        - 1: corresponding pin is set to HIGH
 */
Gpio_Dio_Ip_PinsChannelType Gpio_Dio_Ip_GetPinsOutput(const GPIO_Type * const base);

/*!
 * @brief Write pins with 'Set' value
 *
 * This function configures output pins listed in parameter pins (bits that are
 * '1') to have a value of 'set' (HIGH). Pins corresponding to '0' will be
 * unaffected.
 *
 * @param[in] base GPIO base pointer (PTA, PTB, PTC, etc.)
 * @param[in] pins Pin mask of bits to be set. Each bit represents one pin (LSB is
 * pin 0, MSB is pin 31). For each bit:
 *        - 0: corresponding pin is unaffected
 *        - 1: corresponding pin is set to HIGH
 */
void Gpio_Dio_Ip_SetPins
(
    GPIO_Type * const base,
    Gpio_Dio_Ip_PinsChannelType pins
);

/*!
 * @brief Write pins to 'Clear' value
 *
 * This function configures output pins listed in parameter pins (bits that are
 * '1') to have a 'cleared' value (LOW). Pins corresponding to '0' will be
 * unaffected.
 *
 * @param[in] base GPIO base pointer (PTA, PTB, PTC, etc.)
 * @param[in] pins Pin mask of bits to be cleared. Each bit represents one pin (LSB
 * is pin 0, MSB is pin 31). For each bit:
 *        - 0: corresponding pin is unaffected
 *        - 1: corresponding pin is cleared(set to LOW)
 */
void Gpio_Dio_Ip_ClearPins
(
    GPIO_Type * const base,
    Gpio_Dio_Ip_PinsChannelType pins
);

/*!
 * @brief Toggle pins value
 *
 * This function toggles output pins listed in parameter pins (bits that are
 * '1'). Pins corresponding to '0' will be unaffected.
 *
 * @param[in] base GPIO base pointer (PTA, PTB, PTC, etc.)
 * @param[in] pins Pin mask of bits to be toggled.  Each bit represents one pin (LSB
 * is pin 0, MSB is pin 31). For each bit:
 *        - 0: corresponding pin is unaffected
 *        - 1: corresponding pin is toggled
 */
void Gpio_Dio_Ip_TogglePins
(
    GPIO_Type * const base,
    Gpio_Dio_Ip_PinsChannelType pins
);

/*!
 * @brief Read input pins
 *
 * This function returns the current input values from a port. Only pins
 * configured as input will have meaningful values.
 *
 * @param[in] base GPIO base pointer (PTA, PTB, PTC, etc.)
 * @return GPIO inputs. Each bit represents one pin (LSB is pin 0, MSB is pin
 * 31). For each bit:
 *        - 0: corresponding pin is read as LOW
 *        - 1: corresponding pin is read as HIGH
 */
Gpio_Dio_Ip_PinsChannelType Gpio_Dio_Ip_ReadPins(const GPIO_Type * const base);

/*!
 * @brief Read input pin
 *
 * This function returns the current  input value of the given pin from port. Only pin
 * configured as input will have meaningful value.
 *
 * @param[in] base GPIO base pointer (PTA, PTB, PTC, etc.)
 * @param[in] pin Pin index (0,1,2,3,..,15)
 * @return GPIO input value for coressponding pin
 *        - 0: corresponding pin is read as LOW
 *        - 1: corresponding pin is read as HIGH
 */
Gpio_Dio_Ip_PinsLevelType Gpio_Dio_Ip_ReadPin(const GPIO_Type * const base, Gpio_Dio_Ip_PinsChannelType pin);


#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DIO_GPIO_H */
/** @} */
