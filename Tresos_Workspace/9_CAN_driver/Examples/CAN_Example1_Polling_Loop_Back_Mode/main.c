/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Modular-MX
 * 
 * ***********************************************************************************************************************
 * Example 1. 
 * The example below sets the FlexCAN0 in classic mode and internal loop back mode, this means the internal Tx signal is 
 * connected to internal Rx signal and everything transmitted will be received on the same CAN module without an external hardware. 
 * The example is configured in polling mode making necessary to call the Main Function for read and write every 1ms until 
 * the message has been Transmitted and received, in real world application this function shall be polled by the Ecu driver state machine.
 * 
 * Another thing to keep in mind, the Can Driver is part of a group of drivers called CAN stack and is designed to work within 
 * the complete stack, but since we do not have such stack we need to declare some function from the upper layer CanIf. 
 * ***********************************************************************************************************************
*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Osif.h"
#include "Can_43_FLEXCAN.h"
#include "SchM_Can_43_FLEXCAN.h"

/*flags to indicate Transmition and reception*/
boolean CanIf_bTxFlag = FALSE;
boolean CanIf_bRxFlag = FALSE;
/*message to Tx and Rx*/
uint8 Can_au8Sdu8bytes[8U] = {0x01U, 0x02U, 0x03U, 0x04U, 0x05U, 0x06U, 0x11U, 0x12U};

void EcuM_Init( void );

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

    Can_PduType PduInfo;

    /*Start the CAN controller and make it active in the CAN bus network*/
    Can_43_FLEXCAN_SetControllerMode( CanController_0, CAN_CS_STARTED );

    /*Fill the structure with the information to be transmitted*/
    PduInfo.id = 0u;
    PduInfo.swPduHandle = 0u;
    PduInfo.length = 8u;
    PduInfo.sdu = Can_au8Sdu8bytes;

    while( 1u )
    {
        /*set the FlexCAN peripheral to transmit the message, the message will be
        transmitted by the Can_43_FLEXCAN_MainFunction_Write*/
        Can_43_FLEXCAN_Write( CanHardwareObject_1, &PduInfo );

        /*Transmit a single 8 byte message and wait until the message is transmited
        This is not the most suitable way, but good enough for ilustration
        purposes, flag is updated by the callback function CanIf_TxConfirmation*/
        while( CanIf_bTxFlag == FALSE )
        {
            /*In polling mode we need to call this function with the periodicity
            we set on CanMainFunctionRWPeriods->CanMainFunctionPeriod*/
            Can_43_FLEXCAN_MainFunction_Write();
            Delay( 1u );
        }
        /*Clear the Tx flag*/
        CanIf_bTxFlag = FALSE;

        /*wait here until the previous transmited message is received
        This is not the most suitable way, but good enough for ilustration
        purposes, flag is updated by the callback function CanIf_RxIndication*/
        while( CanIf_bRxFlag == FALSE )
        {
            /*In polling mode we need to call this function with the periodicity
            we set on CanMainFunctionRWPeriods->CanMainFunctionPeriod*/
            Can_43_FLEXCAN_MainFunction_Read();
            Delay( 1u );
        }
        /*Clear the Tx flag*/
        CanIf_bRxFlag = FALSE;

        /*increase some values just for ilustration purposes*/
        Can_au8Sdu8bytes[0]++;
        Can_au8Sdu8bytes[7]++;
        
        Delay( 5000u );
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
