/*
*   Copyright 2021 NXP
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
#include "Mcl.h"
#include "Mcu.h"
#include "CDD_Uart.h"
#include "Port.h"
#include "Platform.h"
#include "Lpuart_Uart_Ip_Irq.h"
#include "Flexio_Uart_Ip_Irq.h"
#include "check_example.h"
#include <string.h>

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define UART_LPUART_INTERNAL_CHANNEL  0U
#define UART_FLEXIO_RX_CHANNEL  1U
#define UART_FLEXIO_TX_CHANNEL  2U

/* Welcome messages displayed at the console */
#define WELCOME_MSG_1 "Hello, This message is sent via Uart!\r\n"
#define WELCOME_MSG_2 "Have a nice day!\r\n"

/* Error message displayed at the console, in case data is received erroneously */
#define ERROR_MSG "An error occurred! The application will stop!\r\n"

/* Length of the message to be received from the console */
#define MSG_LEN  50U



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


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
boolean User_Str_Cmp(const uint8 * pBuffer1, const uint8 * pBuffer2, const uint32 length)
{
    uint32 idx = 0;
    for (idx = 0; idx < length; idx++)
    {
        if(pBuffer1[idx] != pBuffer2[idx])
        {
            return FALSE;
        }
    }
    return TRUE;
}


Std_ReturnType Send_Data(uint8 transChannel, uint8 recvChannel, const uint8* pBuffer, uint32 length)
{
    Std_ReturnType T_Uart_Status;
    Uart_StatusType Uart_ReceiveStatus = UART_STATUS_TIMEOUT;
    Uart_StatusType Uart_TransmitStatus = UART_STATUS_TIMEOUT;
    uint32 T_bytesRemaining;
    uint32 T_timeout = 0xFFFFFF;
    uint8 Rx_Buffer[MSG_LEN];

    /* Uart_AsyncReceive transmit data */
    T_Uart_Status = Uart_AsyncReceive(recvChannel, Rx_Buffer, length);
    if (E_OK != T_Uart_Status)
    {
        return E_NOT_OK;
    }
    /* Uart_AsyncSend transmit data */
    T_Uart_Status = Uart_AsyncSend(transChannel, pBuffer, length);
    if (E_OK != T_Uart_Status)
    {
        return E_NOT_OK;
    }

    /* Check for no on-going transmission */
    do
    {
        Uart_TransmitStatus = Uart_GetStatus(transChannel, &T_bytesRemaining, UART_SEND);
    } while (UART_STATUS_NO_ERROR != Uart_TransmitStatus && 0 < T_timeout--);

    T_timeout = 0xFFFFFF;

    do
    {
        Uart_ReceiveStatus = Uart_GetStatus(recvChannel, &T_bytesRemaining, UART_RECEIVE);
    } while (UART_STATUS_NO_ERROR != Uart_ReceiveStatus && 0 < T_timeout--);

    if ((UART_STATUS_NO_ERROR != Uart_TransmitStatus) || (UART_STATUS_NO_ERROR != Uart_ReceiveStatus))
    {
        return E_NOT_OK;
    }

    if(User_Str_Cmp(pBuffer, (const uint8 *)Rx_Buffer, length) == FALSE)
    {
        return E_NOT_OK;
    }

    return E_OK;
}


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/




/**
* @brief        Main function of the example
* @details      Initializez the used drivers and uses the Icu
*               and Dio drivers to toggle a LED on a push button
*/
int main(void)
{
    volatile Std_ReturnType T_Uart_Status1;
    volatile Std_ReturnType T_Uart_Status2;

    /* Initialize the Mcu driver */
    Mcu_Init(NULL_PTR);

    Mcu_InitClock(McuClockSettingConfig_0);
#if (MCU_NO_PLL == STD_OFF)
    while ( MCU_PLL_LOCKED != Mcu_GetPllStatus() )
    {
        /* Busy wait until the System PLL is locked */
    }

    Mcu_DistributePllClock();
#endif
    Mcu_SetMode(McuModeSettingConf_0);

    /* Initialize Mcl module */
    Mcl_Init(NULL_PTR);

    /* Initialize all pins using the Port driver */
    Port_Init(NULL_PTR);

    /* Initialize IRQs */
    Platform_Init(NULL_PTR);
    Platform_InstallIrqHandler(LPUART0_RxTx_IRQn, LPUART_UART_IP_0_IRQHandler, NULL_PTR);
    Platform_InstallIrqHandler(FLEXIO_IRQn, MCL_FLEXIO_ISR, NULL_PTR);

    /* Initializes an UART driver*/
    Uart_Init(NULL_PTR);

    /* Send greeting string 1 from Flexio_0_Tx to Lpuart_0 */
    T_Uart_Status1 = Send_Data(UART_FLEXIO_TX_CHANNEL, UART_LPUART_INTERNAL_CHANNEL, (const uint8 *)WELCOME_MSG_1, strlen(WELCOME_MSG_1));

    /* Send greeting string 2 from Lpuart_0 to Flexio_1_Rx */
    T_Uart_Status2 = Send_Data(UART_LPUART_INTERNAL_CHANNEL, UART_FLEXIO_RX_CHANNEL, (const uint8 *)WELCOME_MSG_2, strlen(WELCOME_MSG_2));

    Uart_Deinit();

    Mcl_DeInit();

    Exit_Example((T_Uart_Status1 == E_OK) && (T_Uart_Status2 == E_OK));

    return (0U);
}


#ifdef __cplusplus
}
#endif

/** @} */
