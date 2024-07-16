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

#ifdef __cplusplus
extern "C" {
#endif

/**
*   @file Dio_Ipw.c
*
*   @internal
*   @addtogroup DIO_IPW
*   @{
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Dio_Cfg.h"
#include "Dio_Ipw.h"
#include "Gpio_Dio_Ip_Cfg.h"
/*=================================================================================================
                               SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define DIO_IPW_VENDOR_ID_C                    43
#define DIO_IPW_AR_RELEASE_MAJOR_VERSION_C     4
#define DIO_IPW_AR_RELEASE_MINOR_VERSION_C     7
#define DIO_IPW_AR_RELEASE_REVISION_VERSION_C  0
#define DIO_IPW_SW_MAJOR_VERSION_C             2
#define DIO_IPW_SW_MINOR_VERSION_C             0
#define DIO_IPW_SW_PATCH_VERSION_C             0
/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if Dio_Ipw source file and Dio_Ipw header file are of the same vendor */
#if (DIO_IPW_VENDOR_ID_C != DIO_IPW_VENDOR_ID_H)
    #error "Dio_Ipw.c and Dio_Ipw.h have different vendor ids"
#endif

/* Check if  Dio_Ipw source file and Dio_Ipw header file are of the same Autosar version */
#if ((DIO_IPW_AR_RELEASE_MAJOR_VERSION_C    != DIO_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (DIO_IPW_AR_RELEASE_MINOR_VERSION_C    != DIO_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (DIO_IPW_AR_RELEASE_REVISION_VERSION_C != DIO_IPW_AR_RELEASE_REVISION_VERSION_H) \
    )
    #error "AutoSar Version Numbers of Dio_Ipw.c and Dio_Ipw.h are different"
#endif

/* Check if Dio_Ipw source file and Dio_Ipw header file are of the same Software version */
#if ((DIO_IPW_SW_MAJOR_VERSION_C != DIO_IPW_SW_MAJOR_VERSION_H) || \
     (DIO_IPW_SW_MINOR_VERSION_C != DIO_IPW_SW_MINOR_VERSION_H) || \
     (DIO_IPW_SW_PATCH_VERSION_C != DIO_IPW_SW_PATCH_VERSION_H)    \
    )
    #error "Software Version Numbers of Dio_Ipw.c and Dio_Ipw.h are different"
#endif

/* Check if Dio_Ipw source file and Dio_Cfg header file are of the same vendor */
#if (DIO_IPW_VENDOR_ID_C != DIO_VENDOR_ID_CFG_H)
    #error "Dio_Ipw.c and Dio_Cfg.h have different vendor ids"
#endif

/* Check if  Dio_Ipw source file and Dio_Cfg header file are of the same Autosar version */
#if ((DIO_IPW_AR_RELEASE_MAJOR_VERSION_C    != DIO_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (DIO_IPW_AR_RELEASE_MINOR_VERSION_C    != DIO_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (DIO_IPW_AR_RELEASE_REVISION_VERSION_C != DIO_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
    #error "AutoSar Version Numbers of Dio_Ipw.c and Dio_Cfg.h are different"
#endif

/* Check if Dio_Ipw source file and Dio_Cfg header file are of the same Software version */
#if ((DIO_IPW_SW_MAJOR_VERSION_C != DIO_SW_MAJOR_VERSION_CFG_H) || \
     (DIO_IPW_SW_MINOR_VERSION_C != DIO_SW_MINOR_VERSION_CFG_H) || \
     (DIO_IPW_SW_PATCH_VERSION_C != DIO_SW_PATCH_VERSION_CFG_H)    \
    )
    #error "Software Version Numbers of Dio_Ipw.c and Dio_Cfg.h are different"
#endif

/* Check if Dio_Ipw source file and Gpio_Dio_Ip_Cfg header file are of the same vendor */
#if (DIO_IPW_VENDOR_ID_C != GPIO_DIO_IP_VENDOR_ID_CFG_H)
    #error "Dio_Ipw.c and Gpio_Dio_Ip_Cfg.h have different vendor ids"
#endif

/* Check if  Dio_Ipw source file and Gpio_Dio_Ip_Cfg header file are of the same Autosar version */
#if ((DIO_IPW_AR_RELEASE_MAJOR_VERSION_C    != GPIO_DIO_IP_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (DIO_IPW_AR_RELEASE_MINOR_VERSION_C    != GPIO_DIO_IP_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (DIO_IPW_AR_RELEASE_REVISION_VERSION_C != GPIO_DIO_IP_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
    #error "AutoSar Version Numbers of Dio_Ipw.c and Gpio_Dio_Ip_Cfg.h are different"
#endif

/* Check if Dio_Ipw source file and Gpio_Dio_Ip_Cfg header file are of the same Software version */
#if ((DIO_IPW_SW_MAJOR_VERSION_C != GPIO_DIO_IP_SW_MAJOR_VERSION_CFG_H) || \
     (DIO_IPW_SW_MINOR_VERSION_C != GPIO_DIO_IP_SW_MINOR_VERSION_CFG_H) || \
     (DIO_IPW_SW_PATCH_VERSION_C != GPIO_DIO_IP_SW_PATCH_VERSION_CFG_H)    \
    )
    #error "Software Version Numbers of Dio_Ipw.c and Gpio_Dio_Ip_Cfg.h are different"
#endif

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/

/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/
#if (STD_ON == DIO_REVERSEPORTBITS)
    #define GPIO_DIO_REVERSE_BITS_SHIFT            ((Dio_PortLevelType)1U)
    #define GPIO_DIO_REVERSE_BITS_MASK             ((Dio_PortLevelType)0x1U)
    #define GPIO_DIO_REVERSE_BITS_NUMBER           ((Dio_PortLevelType)((Dio_PortLevelType)((Dio_PortLevelType)(sizeof(Dio_PortLevelType)) << 0x3U) - 1U))
#endif /* (STD_ON == DIO_REVERSEPORTBITS) */

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


/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/

#define DIO_START_SEC_CODE
#include "Dio_MemMap.h"

#if (STD_ON == DIO_REVERSEPORTBITS)
static Dio_PortLevelType Dio_Ipw_ReverseBits
(
    Dio_PortLevelType Level
);
#endif /* (STD_ON == DIO_REVERSEPORTBITS) */

/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/

#if (STD_ON == DIO_REVERSEPORTBITS)
/**
* @brief          Reverses bits.
*
* @param[in]      Level       Bits to be reversed.
*
* @return         The reversed bits.
*
* @pre            This function can be used only if @p DIO_REVERSEPORTBITS is
*                 enabled.
*/
static Dio_PortLevelType Dio_Ipw_ReverseBits
(
    Dio_PortLevelType Level
)
{
    /* RevLevel will be reversed bits of Level */
    Dio_PortLevelType TempLevel = Level;
    Dio_PortLevelType RevLevel = TempLevel;
    Dio_PortLevelType NumShifts = GPIO_DIO_REVERSE_BITS_NUMBER; /* number of shifts needed due to trailing 0s */

    for (TempLevel = (Dio_PortLevelType)(TempLevel >> GPIO_DIO_REVERSE_BITS_SHIFT); (Dio_PortLevelType)STD_LOW != TempLevel; TempLevel = (Dio_PortLevelType)(TempLevel >> GPIO_DIO_REVERSE_BITS_SHIFT))
    {
        RevLevel = (Dio_PortLevelType)(RevLevel << GPIO_DIO_REVERSE_BITS_SHIFT);
        RevLevel = (Dio_PortLevelType)(RevLevel | ((Dio_PortLevelType)(TempLevel & GPIO_DIO_REVERSE_BITS_MASK)));
        NumShifts--;
    }

    RevLevel = (Dio_PortLevelType)((uint32)RevLevel << NumShifts); /* Remaining shifts when Level's highest bits are zero */

    return RevLevel;
}
#endif /* (STD_ON == DIO_REVERSEPORTBITS) */

/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

/*===============================================================================================*/
/**
* @brief          Returns the value of the specified DIO channel.
* @details        This function returns the value of the specified DIO channel.
*
* @param[in]      ChannelId   Specifies the required channel id.
*
* @return                     Returns the level of the corresponding pin as
*                             @p STD_HIGH or @p STD_LOW.
* @retval STD_HIGH            The logical level of the corresponding pin is 1.
* @retval STD_LOW             The logical level of the corresponding Pin is 0.
*/
Dio_LevelType Dio_Ipw_ReadChannel
(
    Dio_ChannelType ChannelId
)
{
    Dio_LevelType ChannelLevel = (Dio_LevelType) STD_LOW;
    uint32 u32GpioInstance;
    uint32 u32PinIndex;

    u32GpioInstance = GPIO_DIO_IP_PORT_U32(ChannelId);
    u32PinIndex = GPIO_DIO_IP_CHANNEL_U32(ChannelId);
    const GPIO_Type * GpioBase = (GPIO_Type *)GpioBaseAdresses[u32GpioInstance];

    ChannelLevel = Gpio_Dio_Ip_ReadPin(GpioBase, u32PinIndex);
    return ChannelLevel;
}

/*===============================================================================================*/
/**
* @brief          Sets the level of a channel.
* @details        If the specified channel is configured as an output channel,
*                 this function shall set the specified level on the
*                 specified channel. If the specified channel is configured
*                 as an input channel, this function shall have no influence
*                 on the physical output and on the result of the next read
*                 service.
*
* @param[in]      ChannelId   Specifies the required channel id.
* @param[in]      Level       Specifies the channel desired level.
*/
void Dio_Ipw_WriteChannel
(
    Dio_ChannelType ChannelId,
    Dio_LevelType Level
)
{
    uint32 u32GpioInstance;
    uint32 u32PinIndex;

    u32GpioInstance = GPIO_DIO_IP_PORT_U32(ChannelId);
    u32PinIndex = GPIO_DIO_IP_CHANNEL_U32(ChannelId);
    GPIO_Type * GpioBase = (GPIO_Type *)GpioBaseAdresses[u32GpioInstance];

    Gpio_Dio_Ip_WritePin(GpioBase, u32PinIndex, Level);
}

#if (STD_ON == DIO_FLIP_CHANNEL_API)
/*===============================================================================================*/
/**
* @brief          Inverts the level of a channel.
* @details        If the specified channel is configured as an output channel,
*                 this function shall invert the level of the specified
*                 channel. If the specified channel is configured as an
*                 input channel, this function shall have no influence
*                 on the physical output and on the result of the next
*                 read service.
*
* @param[in]      ChannelId   Specifies the required channel id.
*
* @return                     Returns the level of the corresponding pin as
*                             @p STD_HIGH or @p STD_LOW.
* @retval STD_HIGH            The logical level of the corresponding pin is 1.
* @retval STD_LOW             The logical level of the corresponding Pin is 0.
*
* @pre            This function can be used only if @p DIO_FLIP_CHANNEL_API
*                 has been enabled.

*/
Dio_LevelType Dio_Ipw_FlipChannel
(
    Dio_ChannelType ChannelId
)
{
    Dio_LevelType ChannelLevel = (Dio_LevelType)STD_LOW;
    uint32 u32GpioInstance;
    uint32 u32PinIndex;
    uint32 u32PortOutPutLevel;
    u32GpioInstance = GPIO_DIO_IP_PORT_U32(ChannelId);
    u32PinIndex = GPIO_DIO_IP_CHANNEL_U32(ChannelId);
    GPIO_Type * GpioBase = (GPIO_Type *)GpioBaseAdresses[u32GpioInstance];

    Gpio_Dio_Ip_TogglePins(GpioBase, ((uint32)1U << u32PinIndex));

    u32PortOutPutLevel = Gpio_Dio_Ip_GetPinsOutput(GpioBase);
    ChannelLevel = (Dio_LevelType)((u32PortOutPutLevel & ((uint32)1U << u32PinIndex)) >> u32PinIndex);

    return ChannelLevel;
}
#endif /* (STD_ON == DIO_FLIP_CHANNEL_API) */

/*===============================================================================================*/
/**
* @brief          Returns the level of all channels of specified port.
* @details        This function will return the level of all channels
*                 belonging to the specified port.
*
* @param[in]      PortId      Specifies the required port id.
*
* @return                     Levels of all channels of specified port.
*/
Dio_PortLevelType Dio_Ipw_ReadPort
(
    Dio_PortType PortId
)
{
    Dio_PortLevelType PortLevel = (Dio_PortLevelType)STD_LOW;
    const GPIO_Type * GpioBase = (GPIO_Type *)GpioBaseAdresses[PortId];

    PortLevel = (Dio_PortLevelType)(Gpio_Dio_Ip_ReadPins(GpioBase));

#if (STD_ON == DIO_READZERO_UNDEFINEDPORTS)
    PortLevel =(Dio_PortLevelType)(PortLevel & Dio_aAvailablePinsForRead[PortId]);
#endif
#if (STD_ON == DIO_REVERSEPORTBITS)
    PortLevel = (Dio_PortLevelType)(Dio_Ipw_ReverseBits(PortLevel));
#endif

    return PortLevel;
}

/*===============================================================================================*/
/**
* @brief          Sets the value of a port.
* @details        This function will set the specified value on the specified
*                 port.
*
* @param[in]      PortId      Specifies the required port id.
* @param[in]      Level       Specifies the required levels for the port pins.
*/
void Dio_Ipw_WritePort
(
    Dio_PortType PortId,
    Dio_PortLevelType Level
)
{
    Dio_PortLevelType CrtLevel = Level;
    GPIO_Type * GpioBase = (GPIO_Type *)GpioBaseAdresses[PortId];

#if (STD_ON == DIO_REVERSEPORTBITS)
    CrtLevel = (Dio_PortLevelType)(Dio_Ipw_ReverseBits(CrtLevel));
#endif /* STD_ON == DIO_REVERSEPORTBITS */
    Gpio_Dio_Ip_WritePins(GpioBase, CrtLevel);
}

/*===============================================================================================*/
/**
* @brief          This service reads a subset of the adjoining bits of a port.
* @details        This function will read a subset of adjoining bits of a
*                 port (channel group).
*
* @param[in]      pChannelGroupIdPtr Pointer to the channel group.
* @return                     The channel group levels.
*/
Dio_PortLevelType Dio_Ipw_ReadChannelGroup
(
    const Dio_ChannelGroupType * pChannelGroupIdPtr
)
{
    Dio_PortLevelType PortLevel = (Dio_PortLevelType)STD_LOW;
    Dio_PortLevelType pinsValue;
    const GPIO_Type * GpioBase = (GPIO_Type *)GpioBaseAdresses[pChannelGroupIdPtr->port];

    pinsValue = (Dio_PortLevelType)(Gpio_Dio_Ip_ReadPins(GpioBase));

#if (STD_ON == DIO_REVERSEPORTBITS)
    PortLevel = (Dio_PortLevelType)((pinsValue & (pChannelGroupIdPtr->mask)) << (pChannelGroupIdPtr->u8offset));
    PortLevel = (Dio_PortLevelType)(Dio_Ipw_ReverseBits(PortLevel));
#else
    PortLevel = (Dio_PortLevelType)((pinsValue & (pChannelGroupIdPtr->mask)) >> (pChannelGroupIdPtr->u8offset));
#endif

    return PortLevel;
}

/*===============================================================================================*/
/**
* @brief          Sets a subset of the adjoining bits of a port to the
*                 specified levels.
* @details        This function will set a subset of adjoining bits of a port
*                 (channel group) to the specified levels without changing
*                 the remaining channels of the port and channels that
*                 are configured as input.
*                 This function will do the masking of the channels and will
*                 do the shifting so that the values written by the function
*                 are aligned to the LSB.
*
* @param[in]      pChannelGroupIdPtr Pointer to the channel group.
* @param[in]      Level       Desired levels for the channel group.
*/
void Dio_Ipw_WriteChannelGroup
(
    const Dio_ChannelGroupType * pChannelGroupIdPtr,
    Dio_PortLevelType                 Level
)
{
    Dio_PortLevelType ValueSet;
    Dio_PortLevelType ValueClear;

    GPIO_Type * GpioBase = (GPIO_Type *)GpioBaseAdresses[pChannelGroupIdPtr->port];

#if (STD_ON == DIO_REVERSEPORTBITS)
    ValueSet = (((Dio_PortLevelType)(Dio_Ipw_ReverseBits(Level)) >> (pChannelGroupIdPtr->u8offset)) & (((Dio_PortLevelType)(pChannelGroupIdPtr->mask) )));
#else
    ValueSet = (((Dio_PortLevelType)(Level) << (pChannelGroupIdPtr->u8offset)) & (((Dio_PortLevelType)(pChannelGroupIdPtr->mask) )));
#endif

    Gpio_Dio_Ip_SetPins(GpioBase, ValueSet);
    ValueClear = (~ValueSet) & pChannelGroupIdPtr->mask;
    Gpio_Dio_Ip_ClearPins(GpioBase, ValueClear);

}

#if ((STD_ON == DIO_MASKEDWRITEPORT_API) || defined(__DOXYGEN__))
/*===============================================================================================*/
/**
* @brief          DIO Mask write port using mask.
* @details        Writes a DIO port with masked value.
*
* @param[in]      PortId      Specifies the required port id.
* @param[in]      Level       Specifies the required levels for the port pins.
* @param[in]      Mask        Specifies the Mask value of the port.
*
* @pre            This function can be used only if @p DIO_MASKEDWRITEPORT_API
*                 has been enabled.
*/

void Dio_Ipw_MaskedWritePort
(
    Dio_PortType PortId,
    Dio_PortLevelType Level,
    Dio_PortLevelType Mask
)
{
    Dio_PortLevelType Value;
    GPIO_Type * GpioBase = (GPIO_Type *)GpioBaseAdresses[PortId];

    Value = ((uint32)Mask) & ((uint32)(Level));
    Gpio_Dio_Ip_SetPins(GpioBase, Value);
    Value = (~Level) & Mask;
    Gpio_Dio_Ip_ClearPins(GpioBase, Value);
}
#endif /* (STD_ON == DIO_MASKEDWRITEPORT_API) || defined(__DOXYGEN__) */

#define DIO_STOP_SEC_CODE

#include "Dio_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */
