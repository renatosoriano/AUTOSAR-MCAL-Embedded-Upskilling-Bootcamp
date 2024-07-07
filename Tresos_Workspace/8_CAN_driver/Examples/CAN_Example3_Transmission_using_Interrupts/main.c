/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Modular-MX
 * 
 * ***********************************************************************************************************************
 * Example 3. 
 * The example below sets the FlexCAN2 in classic mode plus interrupt. Pins 81 and 80 configured as CAN Tx and Rx. 
 * The example below only transmits one single, 8 bytes, message every 5 seconds at 100Kpbs. To identify when the message 
 * has been transmitted we use the callback CanIf_TxConfirmation where we set one global flag later polled by the main function. 
 * In a real world application we shall not poll anything because that means to lock the CPU.
 * 
 * Another thing to keep in mind, the Can Driver is part of a group of drivers called CAN stack and is designed to work within 
 * the complete stack, but since we do not have such stack we need to declare some function from the upper layer CanIf. 
 * ***********************************************************************************************************************
*/
#include "Mcu.h"
#include "Port.h"
#include "Platform.h"
#include "Osif.h"
#include "Can_43_FLEXCAN.h"

/*flags to indicate Transmition*/
boolean CanIf_bTxFlag = FALSE;
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
this function is called by the CAN interrupt.
In reality this function is already implemented in CanIf layer*/
void CanIf_TxConfirmation( PduIdType CanTxPduId )
{
    CanIf_bTxFlag = TRUE;
    (void)CanTxPduId;
}

/*CanIf callback function implementation to set the flag when a message is received
this function is called by the CAN interrupt.
In reality this function is already implemented in CanIf layer*/
void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr )
{
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
    PduInfo.id = 0x123u;
    PduInfo.swPduHandle = 0u;
    PduInfo.length = 8u;
    PduInfo.sdu = Can_au8Sdu8bytes;

    while( 1u )
    {
        /*set the FlexCAN peripheral to transmit the message, the message will be
        transmitted by the CAN interrupt*/
        Can_43_FLEXCAN_Write( CanHardwareObject_0, &PduInfo );

        /*wait until the CAN interrupt transmit message, waiting is not the
        suitable way, but good enough for ilustration purposes, flag is 
        updated by the callback function CanIf_TxConfirmation*/
        while( CanIf_bTxFlag == FALSE );
        /*Clear the Tx flag*/
        CanIf_bTxFlag = FALSE;

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
    
    /*enable and setup interrupts in use by the Can Driver*/
    Platform_Init( NULL_PTR );

    /*Apply all the Pin Port microcontroller configuration*/
    Port_Init( &Port_Config );

    /*init the FlexCAN2 with the paramters set in Tresos WITHOUT loop back mode*/
    Can_43_FLEXCAN_Init( &Can_43_FLEXCAN_Config );
}
