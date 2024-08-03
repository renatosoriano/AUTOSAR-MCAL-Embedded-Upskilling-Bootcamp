/*
*   Copyright 2022 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be used strictly
*   in accordance with the applicable license terms.  By expressly accepting
*   such terms or by downloading, installing, activating and/or otherwise using
*   the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms.  If you do not agree to
*   be bound by the applicable license terms, then you may not retain,
*   install, activate or otherwise use the software.
*
*   This file contains sample code only. It is not part of the production code deliverables.
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
#include "Mcu.h"
#include "Mcl.h"
#include "Crc.h"

#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define CRC_DATA_SIZE                 (544U)        /* Define CRC data size */
#define RESULT_CRC_8BIT_SAE_J1850     (0x46U)       /* Define result CRC calculator with protocol CRC_PROTOCOL_8BIT_SAE_J1850 */
#define RESULT_CRC_16BIT_CCITT_FALSE  (0x268EU)     /* Define result CRC calculator with protocol CRC_PROTOCOL_16BIT_CCITT_FALSE */
#define RESULT_CRC_32BIT_ETHERNET     (0x497AE6F5U) /* Define result CRC calculator with protocol CRC_PROTOCOL_32BIT_ETHERNET */

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
__attribute__(( aligned(32) )) const uint8_t CRC_data[] = {
    0x94U, 0x21U, 0xFFU, 0xE0U, 0x7CU, 0x08U, 0x02U, 0xA6U, 0xBFU, 0xC1U, 0x00U, 0x18U, 0x90U,
    0x01U, 0x00U, 0x24U, 0x3BU, 0xE0U, 0x00U, 0x00U, 0x93U, 0xE1U, 0x00U, 0x0CU, 0x88U, 0x03U,
    0x00U, 0x34U, 0x2CU, 0x00U, 0x00U, 0x00U, 0x41U, 0x82U, 0x00U, 0x4CU, 0x80U, 0x03U, 0x00U,
    0x00U, 0x90U, 0x01U, 0x00U, 0x08U, 0x80U, 0x03U, 0x00U, 0x38U, 0x54U, 0x00U, 0x00U, 0x01U,
    0x41U, 0x82U, 0x00U, 0x44U, 0x81U, 0x63U, 0x00U, 0x00U, 0x54U, 0x80U, 0x06U, 0x3EU, 0x2CU,
    0x00U, 0x00U, 0x01U, 0x80U, 0x0BU, 0x00U, 0x0CU, 0x54U, 0x00U, 0x00U, 0x3AU, 0x90U, 0x0BU,
    0x00U, 0x0CU, 0x40U, 0x82U, 0x00U, 0x28U, 0x81U, 0x63U, 0x00U, 0x00U, 0x80U, 0x0BU, 0x00U,
    0x0CU, 0x54U, 0x00U, 0x07U, 0xBFU, 0x41U, 0x82U, 0x01U, 0x84U, 0x3FU, 0xE0U, 0x00U, 0x20U,
    0x48U, 0x00U, 0x01U, 0x7CU, 0x81U, 0x63U, 0x00U, 0x00U, 0x38U, 0x0BU, 0x00U, 0x04U, 0x90U,
    0x01U, 0x00U, 0x08U, 0x81U, 0x61U, 0x00U, 0x08U, 0x80U, 0x0BU, 0x00U, 0x00U, 0x54U, 0x0BU,
    0x07U, 0xBDU, 0x41U, 0x82U, 0x00U, 0x14U, 0x54U, 0x0BU, 0xEFU, 0xFEU, 0x38U, 0x0BU, 0x00U,
    0x02U, 0x90U, 0x01U, 0x00U, 0x0CU, 0x48U, 0x00U, 0x00U, 0x14U, 0x54U, 0x00U, 0x07U, 0x39U,
    0x41U, 0x82U, 0x00U, 0x0CU, 0x38U, 0x00U, 0x00U, 0x01U, 0x90U, 0x01U, 0x00U, 0x0CU, 0x80U,
    0x01U, 0x00U, 0x0CU, 0x54U, 0x00U, 0x07U, 0xFFU, 0x41U, 0x82U, 0x00U, 0x48U, 0x81U, 0x61U,
    0x00U, 0x08U, 0x80U, 0x0BU, 0x00U, 0x00U, 0x54U, 0x00U, 0x05U, 0x6BU, 0x41U, 0x82U, 0xFFU,
    0xF4U, 0x81U, 0x61U, 0x00U, 0x08U, 0x3CU, 0x00U, 0xFFU, 0xFFU, 0x60U, 0x00U, 0x1FU, 0xF7U,
    0x81U, 0x81U, 0x00U, 0x08U, 0x81U, 0x8CU, 0x00U, 0x00U, 0x61U, 0x8CU, 0x00U, 0x01U, 0x7DU,
    0x8CU, 0x00U, 0x38U, 0x91U, 0x8BU, 0x00U, 0x00U, 0x81U, 0x81U, 0x00U, 0x08U, 0x81U, 0x61U,
    0x00U, 0x08U, 0x81U, 0x6BU, 0x00U, 0x00U, 0x7CU, 0x00U, 0x58U, 0x38U, 0x90U, 0x0CU, 0x00U,
    0x00U, 0x80U, 0x01U, 0x00U, 0x0CU, 0x54U, 0x00U, 0x07U, 0xBDU, 0x41U, 0x82U, 0x00U, 0x80U,
    0x81U, 0x61U, 0x00U, 0x08U, 0x3CU, 0x00U, 0xFFU, 0xFFU, 0x60U, 0x00U, 0x1FU, 0xFEU, 0x81U,
    0x81U, 0x00U, 0x08U, 0x81U, 0x8CU, 0x00U, 0x00U, 0x7CU, 0x00U, 0x60U, 0x38U, 0x90U, 0x0BU,
    0x00U, 0x00U, 0x81U, 0x61U, 0x00U, 0x08U, 0x80U, 0x0BU, 0x00U, 0x00U, 0x54U, 0x00U, 0x05U,
    0x6BU, 0x41U, 0x82U, 0xFFU, 0xF4U, 0x81U, 0x61U, 0x00U, 0x08U, 0x3CU, 0x00U, 0xFFU, 0xFFU,
    0x60U, 0x00U, 0x1FU, 0xEFU, 0x3FU, 0xC0U, 0xFFU, 0xFFU, 0x63U, 0xDEU, 0x1FU, 0xFDU, 0x81U,
    0x81U, 0x00U, 0x08U, 0x81U, 0x8CU, 0x00U, 0x00U, 0x7CU, 0x00U, 0x60U, 0x38U, 0x90U, 0x0BU,
    0x00U, 0x00U, 0x81U, 0x81U, 0x00U, 0x08U, 0x81U, 0x61U, 0x00U, 0x08U, 0x80U, 0x0BU, 0x00U,
    0x00U, 0x60U, 0x00U, 0x00U, 0x01U, 0x7CU, 0x00U, 0xF0U, 0x38U, 0x90U, 0x0CU, 0x00U, 0x00U,
    0x81U, 0x81U, 0x00U, 0x08U, 0x81U, 0x61U, 0x00U, 0x08U, 0x80U, 0x0BU, 0x00U, 0x00U, 0x7CU,
    0x00U, 0xF0U, 0x38U, 0x90U, 0x0CU, 0x00U, 0x00U, 0x81U, 0x61U, 0x00U, 0x08U, 0x3CU, 0x00U,
    0xFFU, 0xFFU, 0x60U, 0x00U, 0x1FU, 0xFEU, 0x81U, 0x81U, 0x00U, 0x08U, 0x81U, 0x8CU, 0x00U,
    0x00U, 0x7CU, 0x00U, 0x60U, 0x38U, 0x90U, 0x0BU, 0x00U, 0x00U, 0x81U, 0x61U, 0x00U, 0x08U,
    0x80U, 0x0BU, 0x00U, 0x00U, 0x54U, 0x00U, 0x05U, 0x6BU, 0x41U, 0x82U, 0xFFU, 0xF4U, 0x81U,
    0x61U, 0x00U, 0x08U, 0x3FU, 0xC0U, 0xFFU, 0xFFU, 0x63U, 0xDEU, 0x1FU, 0xEFU, 0x3CU, 0x00U,
    0xFFU, 0xFFU, 0x60U, 0x00U, 0x1FU, 0xFBU, 0x81U, 0x81U, 0x00U, 0x08U, 0x81U, 0x8CU, 0x00U,
    0x00U, 0x7DU, 0x8CU, 0xF0U, 0x38U, 0x91U, 0x8BU, 0x00U, 0x00U, 0x81U, 0x81U, 0x00U, 0x08U,
    0x81U, 0x61U, 0x00U, 0x08U, 0x81U, 0x6BU, 0x00U, 0x00U, 0x7CU, 0x00U, 0x58U, 0x38U, 0x90U,
    0x0CU, 0x00U, 0x00U, 0x88U, 0x03U, 0x00U, 0x3CU, 0x2CU, 0x00U, 0x00U, 0x00U, 0x41U, 0x82U,
    0x00U, 0x14U, 0x7FU, 0xE3U, 0xFBU, 0x78U, 0x60U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,
    0x00U, 0x60U, 0x00U, 0x00U, 0x00U, 0x7FU, 0xE3U, 0xFBU, 0x78U, 0x80U, 0x01U, 0x00U, 0x24U,
    0xBBU, 0xC1U, 0x00U, 0x18U, 0x7CU, 0x08U, 0x03U, 0xA6U, 0x38U, 0x21U, 0x00U, 0x20U, 0x4EU,
    0x80U, 0x00U, 0x20U, 0x4DU, 0x50U, 0x43U, 0x35U, 0x35U, 0x46U, 0x41U, 0x31U,
};

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    boolean Status     = TRUE;
    uint32 TimeOut     = 4800000U;
    uint32 Index       = 0U;
    volatile uint32_t CrcResult;
    Dma_Ip_LogicChannelStatusType DmaChannelStatus;
    Crc_ChannelConfigType LogicChannelCfg_32bit_Ethernet = {
        /* Crc_Ip_ProtocolType Protocol */ CRC_PROTOCOL_32BIT_ETHERNET,
        /* uint32  PolynomialValue      */ 0U,    /* For non-custom protocol, this value doesn't need initialization */
        /* boolean WriteBitSwap         */ FALSE, /* For non-custom protocol, this value doesn't need initialization */
        /* boolean WriteByteSwap        */ FALSE, /* For non-custom protocol, this value doesn't need initialization */
        /* boolean ReadBitSwap          */ FALSE, /* For non-custom protocol, this value doesn't need initialization */
        /* boolean ReadByteSwap         */ FALSE, /* For non-custom protocol, this value doesn't need initialization */
        /* boolean InverseEnable        */ FALSE,  /* For non-custom protocol, this value doesn't need initialization */
        /* Look-Up Table Address        */ NULL_PTR  /* For non-custom protocol, this value doesn't need initialization */
    };

    /* Initialize the clock driver */
#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#elif (MCU_PRECOMPILE_SUPPORT == STD_OFF)
    Mcu_Init(&Mcu_Config);
#endif /* (MCU_PRECOMPILE_SUPPORT == STD_ON) */

    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuClockSettingConfig_0);

#if (MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }

    Mcu_DistributePllClock();
#endif

    /* Apply a mode configuration */
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize Mcl driver */
    Mcl_Init(NULL_PTR);

    /* Initialize CRC driver */
    Crc_Init(NULL_PTR);

    /* Start calculate with CRC_PROTOCOL_8BIT_SAE_J1850 with LOOKUP_TABLES_CALCULATION.
       The CRC Autosar function shall use the preconfigured Logic Channel in Autosar Mode */
    CrcResult = Crc_CalculateCRC8(&CRC_data[0], CRC_DATA_SIZE, 0U, TRUE);
    if (CrcResult != RESULT_CRC_8BIT_SAE_J1850)
    {
        Status = FALSE;
    }

    /* Start calculate with CRC_PROTOCOL_16BIT_CCITT_FALSE with SOFTWARE_CALCULATION */
    CrcResult = Crc_SetChannelCalculate(CRC_LOGIC_CHANNEL_1, &CRC_data[0], CRC_DATA_SIZE, 0U, TRUE);
    if (CrcResult != RESULT_CRC_16BIT_CCITT_FALSE)
    {
        Status = FALSE;
    }

    /* Config HARDWARE_CALCULATION with CRC_PROTOCOL_32BIT_ETHERNET */
    Crc_SetChannelConfig(CRC_LOGIC_CHANNEL_2, &LogicChannelCfg_32bit_Ethernet);
    /* Start calculate with CRC_PROTOCOL_32BIT_ETHERNET with HARDWARE_CALCULATION */
    CrcResult = Crc_SetChannelCalculate(CRC_LOGIC_CHANNEL_2, &CRC_data[0], CRC_DATA_SIZE, 0U, TRUE);
    /* Wait DMA transfer Done */
    while (Index++ < TimeOut)
    {
        Dma_Ip_GetLogicChannelStatus(DMA_LOGIC_CH_0, &DmaChannelStatus);
        if (TRUE == DmaChannelStatus.Done)
        {
            /* Get CRC result */
            CrcResult = Crc_GetChannelResult(CRC_LOGIC_CHANNEL_2);
            if (CrcResult != RESULT_CRC_32BIT_ETHERNET)
            {
                Status = FALSE;
            }
            break;
        }
    }

    Exit_Example(Status);

    return (0U);
}

#ifdef __cplusplus
}
#endif

/** @} */
