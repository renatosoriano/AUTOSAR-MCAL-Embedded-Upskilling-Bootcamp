/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * ***********************************************************************************************************************
 * Exercise 2. 
 * Configure baudrates for 100kbps, 250kbps and 500kbps and make them available for the CAN configurations to be used in the 
 * following exercises.
 * This specific exercise is from CAN_Example5_Transmission_Mailboxes_Buffers, with addition of DIO/PORT and CAN Baudrate
 * configurations. 
 * ***********************************************************************************************************************
*/
#include "Mcu.h"
#include "Port.h"
#include "Platform.h"
#include "Osif.h"
#include "Can_43_FLEXCAN.h"
#include "SEGGER_RTT.h"

/* 
************************************* BAUD RATE CALCULATION *************************************
Reference: https://www.youtube.com/watch?v=2nzkaYQK0YM

                    Nominal Bit Time (of one Bit), composed of 8 tq
|<------------------------------------------------------------------------------------->|
| SYNC_SEG | PROP_SEG |                 PHASE_SEG_1               |      PHASE_SEG_2    |
|<--------------------------------------------------------------->|<------------------->|
                                                     Sample point | at 75%
|----------|----------|----------|----------|----------|----------|----------|----------|
           |                                                    6 | 2
    1 Time Quanta tq

- From Tresos:
    Bus Freq Reference = 48MHz
    Prescaller = to be set for specific baud rate (range 1 to 1024).
- Time quanta value: 
    Tq = 1/(Bus Freq Reference/Prescaller)
- Number of time quantas: 
    Ntq = (1/BaudRate)/Tq 

- Sample_point: the moment of the bit period when the data bit will be detected. This value is always in terms of
  percentage which is recommended to be from 60% to 90%.

- Synchronization_Segment: 1 (Always)
- Propagation_Segment: this can be any value from 1 to Phase_Segment_1
- Phase_Segment_1: ( Ntq * (Sample_point / 100%) ) - (Propagation_Segment + Synchronization_Segment)
- Phase_Segment_2: (Ntq - Phase_Segment_1)
*Sum of the 4 values must not exceed the total amount of quantas (Ntq).
- Resynch_Jump_Width: compensation for the sample point. Typically, this value is set between 1 and (Phase_Segment_2 / 2), 
  but it should never exceed the value of Phase_Segment_2.

- To verify sample point:
( (Synchronization Segment + Propagation Segment + Phase Segment 1) / (Synchronization Segment + Propagation Segment + Phase Segment 1 + CAN Phase Segment 2) ) * 100

************************************* For 100Kbps *************************************
- Prescaller = 30
- Time quanta value: 
    1 Tq = 1/(48000000/30) = 0.625us
- Ntq = (1/100000)/0.000000625 = 16
- Sample_point: 62.5%
- Synchronization_Segment: 1 quanta (Always)
16 - 1 = 15
- Propagation_Segment: 4
- Phase_Segment_1: ( 16 * (62.5 / 100) ) - (4 + 1) = 5
- Phase_Segment_2: (16 - 5) = 6
- Resynch_Jump_Width: between 1 and (6 / 2) = between 1 and (3) = 1
4 + 5 + 6 = 15 ---> OK
- Sample_point verification: 
( (1 + 4 + 5) / (1 + 4 + 5 + 6) ) * 100 = ( (10) / (16) ) * 100 = 62.5% ---> OK

************************************* For 250Kbps *************************************
- Prescaller = 12
- Time quanta value: 
    1 Tq = 1/(48000000/12) = 0.25us
- Ntq = (1/250000)/0.00000025 = 16
- Sample_point: 62.5%
- Synchronization_Segment: 1 quanta (Always)
16 - 1 = 15
- Propagation_Segment: 4
- Phase_Segment_1: ( 16 * ( 62.5 / 100 ) ) - ( 4 + 1 ) = 5
- Phase_Segment_2: 16 - 5 = 6
- Resynch_Jump_Width: between 1 and ( 6 / 2) = between 1 and ( 3 ) = 1
4 + 5 + 6 = 15 ---> OK
- Sample_point verification: 
( (1 + 4 + 5) / (1 + 4 + 5 + 6) ) * 100 = ( (10) / (16) ) * 100 = 62.5% ---> OK

************************************* For 500Kbps *************************************
- Prescaller = 6
- Time quanta value: 
    1 Tq = 1/(48000000/6) = 0.125us
- Ntq = (1/500000)/0.000000125 = 16
- Sample_point: 62.5%
- Synchronization_Segment: 1 quanta (Always)
16 - 1 = 15
- Propagation_Segment: 4
- Phase_Segment_1: ( 16 * ( 62.5 / 100 ) ) - ( 4 + 1 ) = 5
- Phase_Segment_2: 16 - 5 = 6
- Resynch_Jump_Width: between 1 and ( 6 / 2) = between 1 and ( 3 ) = 1
4 + 5 + 6 = 15 ---> OK
- Sample_point verification: 
( (1 + 4 + 5) / (1 + 4 + 5 + 6) ) * 100 = ( (10) / (16) ) * 100 = 62.5% ---> OK

*************************************************************************************************

Results: In Tresos, the four Segment values can be left the same and Prescaller changes.
100Kbps ---> Prescaller = 30
250Kbps ---> Prescaller = 12
500Kbps ---> Prescaller = 6

************************************* BAUD RATE CALCULATION *************************************
*/

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
been transmitterd. In reality this function is already implemented in CanIf layer*/
void CanIf_TxConfirmation( PduIdType CanTxPduId )
{
    static uint8 counter = 0;
    counter++;
    if(counter == 3)
    {
        counter = 0;
        CanIf_bTxFlag = TRUE;
    }
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

    Can_PduType PduInfo1;
    Can_PduType PduInfo2;
    Can_PduType PduInfo3;

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

    /*Fill the first PDU structure with the information to be transmitted*/
    PduInfo1.id = 0x123u;
    PduInfo1.swPduHandle = 0u;
    PduInfo1.length = 8u;
    PduInfo1.sdu = Can_au8Sdu8bytes;
    /*Fill the second PDU structure with the information to be transmitted*/
    PduInfo2.id = 0x133u;
    PduInfo2.swPduHandle = 1u;
    PduInfo2.length = 8u;
    PduInfo2.sdu = Can_au8Sdu8bytes;
    /*Fill the third PDU structure with the information to be transmitted*/
    PduInfo3.id = 0x143u;
    PduInfo3.swPduHandle = 2u;
    PduInfo3.length = 8u;
    PduInfo3.sdu = Can_au8Sdu8bytes;

    while( 1u )
    {
        /*Set the three messages to be transmitted, all messages will be
        transmitted by the CAN interrupt*/
        Can_43_FLEXCAN_Write( CanHardwareObject_0, &PduInfo1 );
        Can_43_FLEXCAN_Write( CanHardwareObject_0, &PduInfo2 );
        Can_43_FLEXCAN_Write( CanHardwareObject_0, &PduInfo3 );

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
