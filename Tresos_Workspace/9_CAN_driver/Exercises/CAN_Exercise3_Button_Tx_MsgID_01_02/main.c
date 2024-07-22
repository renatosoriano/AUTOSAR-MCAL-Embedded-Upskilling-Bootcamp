/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * ***********************************************************************************************************************
 * Exercise 3. 
 * Create a program that, upon pressing the button on the board, transmits a message with an identifier of 0x001 to the 
 * CAN bus, and upon releasing it, transmits a message with an identifier of 0x002. Use the previous exercise as starting point. 
 * ***********************************************************************************************************************
*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Platform.h"
#include "Osif.h"
#include "Can_43_FLEXCAN.h"
#include "SEGGER_RTT.h"
#include "IoHwAb.h"

#define CAN_BAUDRATE_100kbps_ID 0   // CanControllerBaudRateConfigID set to 0 in Tresos (CanControllerBaudrateConfig_100kbps)
#define CAN_BAUDRATE_250kbps_ID 1   // CanControllerBaudRateConfigID set to 1 in Tresos (CanControllerBaudrateConfig_250kbps)
#define CAN_BAUDRATE_500kbps_ID 2   // CanControllerBaudRateConfigID set to 2 in Tresos (CanControllerBaudrateConfig_500kbps)

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
this function is called by the interrupt function three times, once every message has
been transmitted. In reality this function is already implemented in CanIf layer*/
void CanIf_TxConfirmation( PduIdType CanTxPduId )
{
    /*
    static uint8 counter = 0;
    counter++;
    if(counter == 3)
    {
        counter = 0;
        CanIf_bTxFlag = TRUE;
    }
    */
    /* In this case will set the flag upon every time each message is transmitted, 
       instead of waiting until all 3 are transmitted first, like previous examples.
    */ 
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

    /* Intiliaze RTT library */
    SEGGER_RTT_Init();

    Can_PduType PduInfo1;
    Can_PduType PduInfo2;
    Can_PduType PduInfo3;

    uint8 RealEvent = 0;     // Actual event of button.
    uint8 ButtonFlag = 0;    // Button Flag for Msg Tx

    /* Set the specified baudrate */
    if (Can_43_FLEXCAN_SetBaudrate(CanController_0, CAN_BAUDRATE_500kbps_ID ) == E_OK) {
        SEGGER_RTT_printf( 0, "CAN baud rate set successfully. \n" );

    } else {
        SEGGER_RTT_printf( 0, "Failed to set CAN baud rate. \n" );
    }

    /* Start the CAN controller and make it active in the CAN bus network */

    /* The CAN module notifies the upper layer (CanIf_ControllerModeIndication) after 
    a successful state transition about the new state. The monitoring whether the 
    requested state is achieved is part of an upper layer module and is not part of 
    the Can module. */
    if (Can_43_FLEXCAN_SetControllerMode( CanController_0, CAN_CS_STARTED ) == E_OK) {
        SEGGER_RTT_printf( 0, "CAN controller state machine set successfully. \n" );

    } else {
        SEGGER_RTT_printf( 0, "Failed to set CAN controller state machine. \n" );
    }

    /* Fill the first PDU structure with the information to be transmitted */
    PduInfo1.id = 0x001u;
    PduInfo1.swPduHandle = 0u;
    PduInfo1.length = 8u;
    PduInfo1.sdu = Can_au8Sdu8bytes;
    /* Fill the second PDU structure with the information to be transmitted */
    PduInfo2.id = 0x002u;
    PduInfo2.swPduHandle = 1u;
    PduInfo2.length = 8u;
    PduInfo2.sdu = Can_au8Sdu8bytes;
    /* Fill the third PDU structure with the information to be transmitted */
    PduInfo3.id = 0x143u;
    PduInfo3.swPduHandle = 2u;
    PduInfo3.length = 8u;
    PduInfo3.sdu = Can_au8Sdu8bytes;

    while( 1u )
    {
        HwIoAb_Buttons_MainFunction();
        Delay( 10 ); 

        for ( uint8 CurrentButton = 0; CurrentButton < HWIOAB_BUTTONS_MAX; CurrentButton++ )    // Checking each button and its event detected.
        {  
            RealEvent =  HwIoAb_Buttons_GetEvent( CurrentButton );   // Obtaining event of actual button.

            if ( RealEvent != HWIOAB_BTN_EVENT_IDLE )    // A click was detected
            {
                switch( CurrentButton )
                {
                    case HWI0AB_BUTTONS_1_ID :
                        switch( RealEvent )
                        {
                            case HWIOAB_BTN_EVENT_SINGLE_CLICK :
                                HwIoAb_Leds_TurnToggle( HWI0AB_LED_BLUE_ID );
                                SEGGER_RTT_printf( 0, "Button 1 action: SINGLE_CLICK \n" );
                                ButtonFlag = 1;
                                SEGGER_RTT_printf( 0, "CAN msg 0x001 transmitted at 500kbps \n" );
                            break;
                            case HWIOAB_BTN_EVENT_DOUBLE_CLICK :
                                SEGGER_RTT_printf( 0, "Button 1 action: DOUBLE_CLICK \n" );
                            break;
                            case HWIOAB_BTN_EVENT_HOLD_CLICK :
                                SEGGER_RTT_printf( 0, "Button 1 action: HOLD_CLICK \n" );
                            break;
                            break;
                            case HWIOAB_BTN_EVENT_RELEASE :
                                HwIoAb_Leds_TurnToggle( HWIOAB_LED_GREEN_ID );
                                SEGGER_RTT_printf( 0, "Button 1 action: RELEASE \n" );
                                ButtonFlag = 2;
                                SEGGER_RTT_printf( 0, "CAN msg 0x002 transmitted at 500kbps \n" );
                            break;
                            default :
                              // If jump here is an error
                            break;
                        }
                    break;
                    case HWIOAB_BUTTONS_2_ID :
                        switch( RealEvent )
                        {
                            case HWIOAB_BTN_EVENT_SINGLE_CLICK :
                                SEGGER_RTT_printf( 0, "Button 2 action: SINGLE_CLICK \n" );
                            break;
                            case HWIOAB_BTN_EVENT_DOUBLE_CLICK :
                                SEGGER_RTT_printf( 0, "Button 2 action: DOUBLE_CLICK \n" );
                            break;
                            case HWIOAB_BTN_EVENT_HOLD_CLICK :
                                SEGGER_RTT_printf( 0, "Button 2 action: HOLD_CLICK \n" );
                            break;
                            case HWIOAB_BTN_EVENT_RELEASE :
                                SEGGER_RTT_printf( 0, "Button 2 action: RELEASE \n" );
                            break;
                            default :
                              // If jump here is an error
                            break;
                        }
                    break;
                    case HWIOAB_BUTTONS_3_ID :
                        switch( RealEvent )
                        {
                            case HWIOAB_BTN_EVENT_SINGLE_CLICK :
                                SEGGER_RTT_printf( 0, "Button 3 action: SINGLE_CLICK \n" );
                            break;
                            case HWIOAB_BTN_EVENT_DOUBLE_CLICK :
                                SEGGER_RTT_printf( 0, "Button 3 action: DOUBLE_CLICK \n" );
                            break;
                            case HWIOAB_BTN_EVENT_HOLD_CLICK :
                                SEGGER_RTT_printf( 0, "Button 3 action: HOLD_CLICK \n" );
                            break;
                            case HWIOAB_BTN_EVENT_RELEASE :
                                SEGGER_RTT_printf( 0, "Button 3 action: RELEASE \n" );
                            break;
                            default :
                              // If jump here is an error
                            break;
                        }
                    break;
                    default :
                      // If jump here is an error
                    break;
                }  
            }
        }

        if(ButtonFlag == 1)
        {
            ButtonFlag = 0; 
            /* Set the message to be transmitted, all messages will be
            transmitted by the CAN interrupt */
            Can_43_FLEXCAN_Write( CanHardwareObject_0, &PduInfo1 );
        }
        if(ButtonFlag == 2)
        {
            ButtonFlag = 0; 
            /* Set the message to be transmitted, all messages will be
            transmitted by the CAN interrupt */
            Can_43_FLEXCAN_Write( CanHardwareObject_0, &PduInfo2 );
        }

        /* Set the message to be transmitted, all messages will be
        transmitted by the CAN interrupt */
        Can_43_FLEXCAN_Write( CanHardwareObject_0, &PduInfo3 );

        /* Wait until the CAN interrupt transmit message, waiting is not the
        suitable way, but good enough for ilustration purposes, flag is 
        updated by the callback function CanIf_TxConfirmation */
        while( CanIf_bTxFlag == FALSE );
        /*Clear the Tx flag*/
        CanIf_bTxFlag = FALSE;

        /* Increase some values just for ilustration purposes */
        Can_au8Sdu8bytes[0]++;
        Can_au8Sdu8bytes[7]++;
        
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
    /* Init Mcu module, including internal PLL, reference to Mcu Config structure can 
    be found at Mcu_PBcfg.h and PLL defines at Mcu_Cfg.h */
    Mcu_Init( &Mcu_Config );
    Mcu_InitClock( McuClockSettingConfig_0 );
    Mcu_SetMode( McuModeSettingConf_0 );
    /* Init the internal tick reference Systick Timer */
    OsIf_Init( NULL_PTR );
    
    /* Enable and setup interrupts in use by the Can Driver */
    Platform_Init( NULL_PTR );

    /* Apply all the Pin Port microcontroller configuration */
    Port_Init( &Port_Config );

    /* Init the FlexCAN2 with the paramters set in Tresos WITHOUT loop back mode */
    Can_43_FLEXCAN_Init( &Can_43_FLEXCAN_Config );

    /* Initializing IO Hardware Abstractions with the module ID 0 */
    IoHwAb_Init0( NULL_PTR );
}
