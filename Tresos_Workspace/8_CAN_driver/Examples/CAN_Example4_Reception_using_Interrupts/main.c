/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Modular-MX
 * 
 * ***********************************************************************************************************************
 * Example 4. 
 * The example below sets the FlexCAN2 in classic mode plus interrupt. Pins 81 and 80 configured as CAN Tx and Rx. 
 * The example below only waits until a single, 8 bytes, message is received. The callback CanIf_RxIndication function is 
 * called when the message arrives. The parameters Mailbox and PduInfoPtr store the information from the received message, 
 * we can backup this info in the callback and use a global flag to communicate the message arrival to the main application.
 * 
 * Another thing to keep in mind, the Can Driver is part of a group of drivers called CAN stack and is designed to work within 
 * the complete stack, but since we do not have such stack we need to declare some function from the upper layer CanIf. 
 * ***********************************************************************************************************************
*/
#include "Mcu.h"
#include "Port.h"
#include "Platform.h"
#include "Can_43_FLEXCAN.h"

/*message to Tx and Rx*/
uint8 Can_au8Sdu8bytes[8U];

void EcuM_Init( void );

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
    (void)CanTxPduId;
}

/*CanIf callback function implementation to set the flag when a message is received
this function is called by the CAN interrupt.
In reality this function is already implemented in CanIf layer*/
void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType* PduInfoPtr )
{
    (void)Mailbox;
    /*the received message is store in PduInfoPtr->SduDataPtr*/
    if(PduInfoPtr->SduDataPtr[0] == 0x32)
    {
        /*do soemthing in case the first byte received is equal to 0x32*/
        for(uint8 i = 0; i < 8 ; i++)
        {
            Can_au8Sdu8bytes[i] = PduInfoPtr->SduDataPtr[i];
        }
    }
    //CanId is stored in Mailbox->CanId}
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

    /*Start the CAN controller and make it active in the CAN bus network*/
    Can_43_FLEXCAN_SetControllerMode( CanController_0, CAN_CS_STARTED );

    while( 1u )
    {

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
    
    /*enable and setup interrupts in use by the Can Driver*/
    Platform_Init( NULL_PTR );

    /*Apply all the Pin Port microcontroller configuration*/
    Port_Init( &Port_Config );

    /*init the FlexCAN2 with the paramters set in Tresos WITHOUT loop back mode*/
    Can_43_FLEXCAN_Init( &Can_43_FLEXCAN_Config );
}
