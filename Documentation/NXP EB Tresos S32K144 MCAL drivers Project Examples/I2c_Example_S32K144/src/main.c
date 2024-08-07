/*
*   Copyright 2020-2021 NXP
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
#include "Mcal.h"
#include "Platform.h"
#include "Port.h"
#include "CDD_I2c.h"
#include "CDD_Mcl.h"
#include "check_example.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

#define TRANSFER_SIZE 8U

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#define I2C_START_SEC_VAR_INIT_UNSPECIFIED
#include "I2c_MemMap.h"

I2c_DataType rxBufferSlave[TRANSFER_SIZE] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
I2c_DataType rxBufferMaster[TRANSFER_SIZE] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
I2c_DataType txBuffer[TRANSFER_SIZE] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7};

#define I2C_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "I2c_MemMap.h"

I2c_RequestType pRequest[2] =
{
    /* Slave address */ /*10 bit address*/ /*high speed */ /* expect Nack */ /*repeated start */ /*buffer size */ /*Data direction */ /*Buffer*/
{   0x32,               FALSE,             FALSE,          FALSE,            FALSE,              8U,              I2C_SEND_DATA,      txBuffer},
{   0x32,               FALSE,             FALSE,          FALSE,            FALSE,              8U,              I2C_RECEIVE_DATA,   rxBufferMaster}

};

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        Slave callback for i2c
* @details      Prepare slave's buffer for transfer
*/
void I2c_Callback(uint8 u8Event, uint8 u8Channel)
{
    switch(u8Event)
    {
        case I2C_EVENT_RX_REQ_SLAVE:
            I2c_PrepareSlaveBuffer(u8Channel, TRANSFER_SIZE, rxBufferSlave);
            break;

        case I2C_EVENT_TX_REQ_SLAVE:
            I2c_PrepareSlaveBuffer(u8Channel, TRANSFER_SIZE, txBuffer);
            break;

        default:
            (void) u8Channel;
    }
}

/**
* @brief        Main function of the example
* @details      Initializez the LPI2C driver to asynchronous data.
*/
int main(void)
{
    uint32 timeout = 0xFFFF;
    boolean checkOk = TRUE;
    uint8 i;
    I2c_StatusType status;

    /* Init system clock */
#if (MCU_PRECOMPILE_SUPPORT == STD_ON)
    Mcu_Init(NULL_PTR);
#elif (MCU_PRECOMPILE_SUPPORT == STD_OFF)
    Mcu_Init(&Mcu_Config_VS_0);
#endif

    /* Initialize the clock tree and apply PLL as system clock */
    Mcu_InitClock(McuClockSettingConfig_0);
#if (MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
      /* Busy wait until the System PLL is locked */
    }
    Mcu_DistributePllClock();
#endif

    Mcu_SetMode(McuModeSettingConf_0);

    /* Init Pins for Flexio and LPI2C */
    Port_Init(NULL_PTR);
    /* Install interrupt handlers */
    Platform_Init(NULL_PTR);

    /* Init Mcl for FlexIO chanel */
#if (MCL_PRECOMPILE_SUPPORT == STD_ON)
    Mcl_Init(NULL_PTR);
#elif (MCL_PRECOMPILE_SUPPORT == STD_OFF)
    Mcl_Init(&Mcl_Config_VS_0);
#endif

    /* Init master and slave */
#if (I2C_PRECOMPILE_SUPPORT == STD_ON)
    I2c_Init(NULL_PTR);
#elif (I2C_PRECOMPILE_SUPPORT == STD_OFF)
    I2c_Init(&I2c_Config_VS_0);
#endif

    /* Slave listening */
    I2c_StartListening(1U);

    /* Master send data */
    I2c_AsyncTransmit(0U, &pRequest[0]);

    /* Wait until master is ready */
    while (((status = I2c_GetStatus(0U)) == I2C_CH_SEND) && (timeout > 0))
    {
        timeout--;
    }

    /* Wait until slave is ready */
    while (((status = I2c_GetStatus(1U)) == I2C_CH_RECEIVE) && (timeout > 0))
    {
        timeout--;
    }

    /* Verify data received */
    for (i = 0; i < TRANSFER_SIZE; i ++)
    {
        if (txBuffer[i] != rxBufferSlave[i])
        {
            checkOk = FALSE;
        }
    }

    I2c_StartListening(1U);
    /* Master send data */
    I2c_AsyncTransmit(0U, &pRequest[1]);

    /* Wait until master is ready */
    while (((status = I2c_GetStatus(0U)) == I2C_CH_RECEIVE) && (timeout > 0))
    {
        timeout--;
    }

    /* Wait until slave is ready */
    while (((status = I2c_GetStatus(1U)) == I2C_CH_SEND) && (timeout > 0))
    {
        timeout--;
    }

    /* Verify data received */
    for (i = 0; i < TRANSFER_SIZE; i ++)
    {
        if (txBuffer[i] != rxBufferMaster[i])
        {
            checkOk = FALSE;
        }
    }
    Exit_Example(checkOk);

    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
