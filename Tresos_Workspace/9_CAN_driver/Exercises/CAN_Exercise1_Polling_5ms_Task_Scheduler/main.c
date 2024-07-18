/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * ***********************************************************************************************************************
 * Exercise 1. 
 * Take the first code example and place the Can_43_FLEXCAN_MainFunction_Read/Write in a 5ms task using the scheduler, you 
 * shall configure the POLLING time properly in Tresos, in a different task transmit a receive messages. 
 * ***********************************************************************************************************************
*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Osif.h"
#include "Can_43_FLEXCAN.h"
#include "SchM_Can_43_FLEXCAN.h"
#include "Scheduler.h"

/*flags to indicate Transmition and reception*/
boolean CanIf_bTxFlag = FALSE;
boolean CanIf_bRxFlag = FALSE;
/*message to Tx and Rx*/
uint8 Can_au8Sdu8bytes[8U] = {0x01U, 0x02U, 0x03U, 0x04U, 0x05U, 0x06U, 0x11U, 0x12U};
Can_PduType PduInfo;

void EcuM_Init( void );
void Os_50ms_Task( void );
void Os_CanTask( void );

/*this is dummy delay function prepare just for this example, in a real application 
no delay shall be used*/
void Delay( uint32 ms )
{
    uint32 Timeout = OsIf_MicrosToTicks( ms * 1000u, OSIF_COUNTER_SYSTEM );
    uint32 SeedTick = OsIf_GetCounter( OSIF_COUNTER_SYSTEM );
    uint32 ElapsedTime = 0u;
    do{
        ElapsedTime += OsIf_GetElapsed( &SeedTick, OSIF_COUNTER_SYSTEM );
    }
    while( ElapsedTime < Timeout );
}

/*CanIf callback function implementation, just to avoid compiler errors
in reality this function is already implemented in CanIf layer*/
void CanIf_ControllerBusOff(uint8 ControllerId)
{
    (void)ControllerId;
}

/*CanIf callback function implementation, just to avoid compiler errors
in reality this function is already implemented in CanIf layer*/
void CanIf_ControllerModeIndication(uint8 ControllerId, Can_ControllerStateType ControllerMode )
{
    (void)ControllerId;
    (void)ControllerMode;
}

/*CanIf callback function implementation to set the flag when a message is transmited
this function is called by the Can_43_FLEXCAN_MainFunction_Write function.
In reality this function is already implemented in CanIf layer*/
void CanIf_TxConfirmation( PduIdType CanTxPduId )
{
    CanIf_bTxFlag = TRUE;
    (void)CanTxPduId;
}

/*CanIf callback function implementation to set the flag when a message is received
this function is called by the Can_43_FLEXCAN_MainFunction_Read function.
In reality this function is already implemented in CanIf layer*/
void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr )
{
    CanIf_bRxFlag = TRUE;
    (void)Mailbox;
    /*the received message is store in PduInfoPtr->SduDataPtr*/
    (void)PduInfoPtr;
}

/**
 * @brief This is the main function of the project
 * 
 * This is the main function of the project, it is the entry point of the program
 * 
 * @return Always zero
*/
int main( void )
{
    EcuM_Init();

    /* Init the scheduler with two tasks */
    Scheduler_Init( &Scheduler_Config );

    /*Start the CAN controller and make it active in the CAN bus network*/
    Can_43_FLEXCAN_SetControllerMode( CanController_0, CAN_CS_STARTED );

    /*Fill the structure with the information to be transmitted*/
    PduInfo.id = 0u;
    PduInfo.swPduHandle = 0u;
    PduInfo.length = 8u;
    PduInfo.sdu = Can_au8Sdu8bytes;

    while( 1u )
    {
        /* Run the scheduler forever */
        Scheduler_MainFunction( );
    }

    return 0u;
}

/**
 * @brief This function initialize the microcontroller and the peripherals
 * 
 * it is just a temporary function, in the future this function will be replaced when the EcuM module 
 * is configured and implemented
*/
void EcuM_Init( void )
{
    /*Init Mcu module, including internal PLL, reference to Mcu Config structure can 
    be found at Mcu_PBcfg.h and PLL defines at Mcu_Cfg.h*/
    Mcu_Init( &Mcu_Config );
    Mcu_InitClock( McuClockSettingConfig_0 );
    Mcu_SetMode( McuModeSettingConf_0 );
    /*Init the internal tick reference Systick Timer*/
    OsIf_Init( NULL_PTR );

    /*init the FlexCAN0 with the paramters set in Tresos in loop back mode*/
    Can_43_FLEXCAN_Init( &Can_43_FLEXCAN_Config );
}

/**
 * @brief This is the function for the 50ms task.
 *
 * This function prepares to transmit messages.
 */
void Os_50ms_Task( void )
{
    /* Set the FlexCAN peripheral to transmit the message, the message will be
    transmitted by the Can_43_FLEXCAN_MainFunction_Write */
    Can_43_FLEXCAN_Write( CanHardwareObject_1, &PduInfo );

    /* Increase some values just for ilustration purposes */
    Can_au8Sdu8bytes[0]++;
    Can_au8Sdu8bytes[7]++;
}

/**
 * @brief This is the function for the 5ms task.
 *
 * This function calls Can_43_FLEXCAN_MainFunction_Write() and Can_43_FLEXCAN_MainFunction_Read().
 */
void Os_CanTask( void )
{
    /* Transmit a single 8 byte message and wait until the message is transmited
    This is not the most suitable way, but good enough for ilustration
    purposes, flag is updated by the callback function CanIf_TxConfirmation */
    while( CanIf_bTxFlag == FALSE )
    {
        /* In polling mode we need to call this function with the periodicity
        we set on CanMainFunctionRWPeriods->CanMainFunctionPeriod = 5ms */
        Can_43_FLEXCAN_MainFunction_Write();
    }
    /* Clear the Tx flag */
    CanIf_bTxFlag = FALSE;

    /* Wait here until the previous transmited message is received
    This is not the most suitable way, but good enough for ilustration
    purposes, flag is updated by the callback function CanIf_RxIndication */
    while( CanIf_bRxFlag == FALSE )
    {
        /* In polling mode we need to call this function with the periodicity
        we set on CanMainFunctionRWPeriods->CanMainFunctionPeriod = 5ms */
        Can_43_FLEXCAN_MainFunction_Read();
        Delay( 1u );
    }
    /* Clear the Tx flag */
    CanIf_bRxFlag = FALSE;
}
