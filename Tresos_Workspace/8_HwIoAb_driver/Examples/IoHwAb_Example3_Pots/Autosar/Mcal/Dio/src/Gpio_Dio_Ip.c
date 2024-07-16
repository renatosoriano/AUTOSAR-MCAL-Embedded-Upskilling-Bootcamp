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

/**
*   @file Gpio_Dio_Ip.c
*
*   @addtogroup DIO_IPL
*   @{
*/

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gpio_Dio_Ip.h"
#include "SchM_Dio.h"
#if (STD_ON == GPIO_DIO_IP_DEV_ERROR_DETECT)
    #include "Devassert.h"
#endif /* (STD_ON == GPIO_DIO_IP_DEV_ERROR_DETECT) */

/*=================================================================================================
                               SOURCE FILE VERSION INFORMATION
=================================================================================================*/

#define GPIO_DIO_IP_VENDOR_ID_C                    43
#define GPIO_DIO_IP_AR_RELEASE_MAJOR_VERSION_C     4
#define GPIO_DIO_IP_AR_RELEASE_MINOR_VERSION_C     7
#define GPIO_DIO_IP_AR_RELEASE_REVISION_VERSION_C  0
#define GPIO_DIO_IP_SW_MAJOR_VERSION_C             2
#define GPIO_DIO_IP_SW_MINOR_VERSION_C             0
#define GPIO_DIO_IP_SW_PATCH_VERSION_C             0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if Gpio_Dio_Ip source file and Gpio_Dio_Ip header file are of the same vendor */
#if (GPIO_DIO_IP_VENDOR_ID_C != GPIO_DIO_IP_VENDOR_ID_H)
    #error "Gpio_Dio_Ip.c and Gpio_Dio_Ip.h have different vendor ids"
#endif

/* Check if  Gpio_Dio_Ip source file and Gpio_Dio_Ip header file are of the same Autosar version */
#if ((GPIO_DIO_IP_AR_RELEASE_MAJOR_VERSION_C    != GPIO_DIO_IP_AR_RELEASE_MAJOR_VERSION_H) || \
     (GPIO_DIO_IP_AR_RELEASE_MINOR_VERSION_C    != GPIO_DIO_IP_AR_RELEASE_MINOR_VERSION_H) || \
     (GPIO_DIO_IP_AR_RELEASE_REVISION_VERSION_C != GPIO_DIO_IP_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Gpio_Dio_Ip.c and Gpio_Dio_Ip.h are different"
#endif

/* Check if Gpio_Dio_Ip source file and Gpio_Dio_Ip header file are of the same Software version */
#if ((GPIO_DIO_IP_SW_MAJOR_VERSION_C != GPIO_DIO_IP_SW_MAJOR_VERSION_H) || \
     (GPIO_DIO_IP_SW_MINOR_VERSION_C != GPIO_DIO_IP_SW_MINOR_VERSION_H) || \
     (GPIO_DIO_IP_SW_PATCH_VERSION_C != GPIO_DIO_IP_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Gpio_Dio_Ip.c and Gpio_Dio_Ip.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if Gpio_Dio_Ip source file and Devassert.h header file are of the same release version */
    #if (STD_ON == GPIO_DIO_IP_DEV_ERROR_DETECT)
        #if ((GPIO_DIO_IP_AR_RELEASE_MAJOR_VERSION_C != DEVASSERT_AR_RELEASE_MAJOR_VERSION) || \
            (GPIO_DIO_IP_AR_RELEASE_MINOR_VERSION_C != DEVASSERT_AR_RELEASE_MINOR_VERSION)     \
            )
            #error "AutoSar Version Numbers of Gpio_Dio_Ip.c and Devassert.h are different"
        #endif
    #endif /* (STD_ON == GPIO_DIO_IP_DEV_ERROR_DETECT) */
    /* SchM_Dio.h version check start */
    #if ((GPIO_DIO_IP_AR_RELEASE_MAJOR_VERSION_C != SCHM_DIO_AR_RELEASE_MAJOR_VERSION) ||   \
        (GPIO_DIO_IP_AR_RELEASE_MINOR_VERSION_C != SCHM_DIO_AR_RELEASE_MINOR_VERSION)       \
        )
        #error "AUTOSAR Version Numbers of Gpio_Dio_Ip.c and SchM_Dio.h are different"
    #endif
    /* SchM_Dio.h version check end */
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

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


/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/
#define DIO_START_SEC_VAR_INIT_32
#include "Dio_MemMap.h"

uint32 GpioBaseAdresses[GPIO_INSTANCE_COUNT] = IP_GPIO_BASE_ADDRS;

#define DIO_STOP_SEC_VAR_INIT_32
#include "Dio_MemMap.h"

/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/
#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"
/**
 *Function Name : Gpio_Dio_Ip_WritePin
 * Description   : This function writes the given pin from a port, with the given value
 * ('0' represents LOW, '1' represents HIGH).
 *
 * @implements    Gpio_Dio_Ip_WritePin_Activity
 */
void Gpio_Dio_Ip_WritePin
(
    GPIO_Type * const base,
    Gpio_Dio_Ip_PinsChannelType pin,
    Gpio_Dio_Ip_PinsLevelType value
)
{
    /* Enter critical region */
    SchM_Enter_Dio_DIO_EXCLUSIVE_AREA_00();
    Gpio_Dio_Ip_PinsChannelType pinsValues = (Gpio_Dio_Ip_PinsChannelType)base->PDOR;
    pinsValues &= (Gpio_Dio_Ip_PinsChannelType)(~((Gpio_Dio_Ip_PinsChannelType)1U << pin));
    pinsValues |= (Gpio_Dio_Ip_PinsChannelType)((Gpio_Dio_Ip_PinsChannelType)value << pin);
    base->PDOR = GPIO_PDOR_PDO(pinsValues);
    /* Exit critical region */
    SchM_Exit_Dio_DIO_EXCLUSIVE_AREA_00();
}

/**
 * Function Name : Gpio_Dio_Ip_WritePins
 * Description   : This function writes all pins configured as output with the values given in
 * the parameter pins. '0' represents LOW, '1' represents HIGH.
 *
 * @implements    Gpio_Dio_Ip_WritePins_Activity
 */
void Gpio_Dio_Ip_WritePins
(
    GPIO_Type * const base,
    Gpio_Dio_Ip_PinsChannelType pins
)
{
    base->PDOR = GPIO_PDOR_PDO(pins);
}


/**
 * Function Name : Gpio_Dio_Ip_GetPinsOutput
 * Description   : This function returns the current output that is written to a port. Only pins
 * that are configured as output will have meaningful values.
 *
 * @implements    Gpio_Dio_Ip_GetPinsOutput_Activity
 */
Gpio_Dio_Ip_PinsChannelType Gpio_Dio_Ip_GetPinsOutput(const GPIO_Type * const base)
{
    Gpio_Dio_Ip_PinsChannelType returnValue = 0U;
    returnValue = (Gpio_Dio_Ip_PinsChannelType)(base->PDOR);
    return returnValue;
}

/**
 * Function Name : Gpio_Dio_Ip_SetPins
 * Description   : This function configures output pins listed in parameter pins (bits that are
 * '1') to have a value of 'set' (HIGH). Pins corresponding to '0' will be
 * unaffected.
 *
 * @implements    Gpio_Dio_Ip_SetPins_Activity
 */
void Gpio_Dio_Ip_SetPins
(
    GPIO_Type * const base,
    Gpio_Dio_Ip_PinsChannelType pins
)
{
    base->PSOR = GPIO_PSOR_PTSO(pins);
}

/**
 * Function Name : Gpio_Dio_Ip_ClearPins
 * Description   : This function configures output pins listed in parameter pins (bits that are
 * '1') to have a 'cleared' value (LOW). Pins corresponding to '0' will be
 * unaffected.
 *
 * @implements    Gpio_Dio_Ip_ClearPins_Activity
 */
void Gpio_Dio_Ip_ClearPins
(
    GPIO_Type * const base,
    Gpio_Dio_Ip_PinsChannelType pins
)
{
    base->PCOR = GPIO_PCOR_PTCO(pins);
}

/**
 * Function Name : Gpio_Dio_Ip_TogglePins
 * Description   : This function toggles output pins listed in parameter pins (bits that are
 * '1'). Pins corresponding to '0' will be unaffected.
 *
 * @implements    Gpio_Dio_Ip_TogglePins_Activity
 */
void Gpio_Dio_Ip_TogglePins
(
    GPIO_Type * const base,
    Gpio_Dio_Ip_PinsChannelType pins
)
{
    base->PTOR = GPIO_PTOR_PTTO(pins);
}

/**
 * Function Name : Gpio_Dio_Ip_ReadPins
 * Description   : This function returns the current input values from a port. Only pins
 * configured as input will have meaningful values.
 *
 * @implements    Gpio_Dio_Ip_ReadPins_Activity
 */
Gpio_Dio_Ip_PinsChannelType Gpio_Dio_Ip_ReadPins(const GPIO_Type * const base)
{
    Gpio_Dio_Ip_PinsChannelType returnValue = 0U;
    returnValue = (Gpio_Dio_Ip_PinsChannelType)(base->PDIR);
    return returnValue;
}

/**
 * Function Name : Gpio_Dio_Ip_ReadPin
 * Description   : This function returns the current  input value of the given pin from port. Only pin
 * configured as input will have meaningful value.
 *
 * @implements    Gpio_Dio_Ip_ReadPin_Activity
 */
Gpio_Dio_Ip_PinsLevelType Gpio_Dio_Ip_ReadPin(const GPIO_Type * const base, Gpio_Dio_Ip_PinsChannelType pin)
{
    Gpio_Dio_Ip_PinsLevelType returnValue = 0U;
    returnValue  = (Gpio_Dio_Ip_PinsLevelType)(((base->PDIR)&((uint32)1<<pin))>>(pin));

    return returnValue;
}

#define DIO_STOP_SEC_CODE
#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

/******************************************************************************
 * EOF
 *****************************************************************************/
