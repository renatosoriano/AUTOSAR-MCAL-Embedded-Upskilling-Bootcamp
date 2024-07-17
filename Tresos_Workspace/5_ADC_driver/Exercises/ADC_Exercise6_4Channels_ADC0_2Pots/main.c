/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * ***********************************************************************************************************************
 * Exercise 6. 
 * Using a jumper wire to connect another channels available (ADC0) to pot 1 and then another one to pot 2, 
 * so you can have four channels to sample. Also configure the hardware average sample with a value of 8, 
 * you should also calculate the total timing conversion for the entire group of channels.
 * 
 * ADC TOTAL CONVERSION TIME = Sample Phase Time + Hold Phase + Compare Phase Time + Single or First continuous time adder
 * 
 * Sample Phase Time => set by CFG2[SMPLTS + 1] 
 * Hold Phase => 1 ADC Cycle 
 * Compare Phase Time => 8-bit Mode = 20 ADC Cycles, 10-bit Mode = 24 ADC Cycles, 12-bit Mode = 28 ADC Cycles 
 * Single or First continuous time adder => 5 ADC cycles + 5 bus clock cycles
 * 
 * ADC TOTAL CONVERSION TIME = ((200*8) + 1 + 28 + 5) + 5 bus clocks 
 * ADC TOTAL CONVERSION TIME = 1,634 adc clocks + 5 bus clock
 * for this example we use a ADC preescaler of 1 so Adc clocks = bus clocks = 1/24MHz = 0.041us
 * ADC TOTAL CONVERSION TIME = 1,639 * 0.041us = 67.199 us
 * 
 * ***********************************************************************************************************************
*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Platform.h"
#include "Osif.h"
#include "Adc.h"
#include "SEGGER_RTT.h"

void EcuM_Init( void );

/**
 * @brief This is the main function of the project
 * 
 * This is the main function of the project, it is the entry point of the program
 * 
 * @return Always zero
*/
int main( void )
{
    Adc_CalibrationStatusType CalibStatus;
    Adc_ValueGroupType    AdcReadGroupBuffer[4];
    Adc_ValueGroupType    ResultBuffer[4];

    EcuM_Init();

    /* Intiliaze RTT library */
    SEGGER_RTT_Init();

    /*
    The hardware interleave implementation on this device is as following:
    • ADC0_SE4 and ADC1_SE14 channels are interleaved on PTB0 pin 
    • ADC0_SE5 and ADC1_SE15 channels are interleaved on PTB1 pin 
    • ADC1_SE8 and ADC0_SE8 channels are interleaved on PTB13 pin 
    • ADC1_SE9 and ADC0_SE9 channels are interleaved on PTB14 pin
    */
   
    /* By default ADC0-CH8 is not connected to B13, but with this function
    it will, this is called Interleave, read RM page 1194*/
    Port_Ci_Port_Ip_SetMuxModeSel( IP_PORTB, 13, PORT_MUX_ADC_INTERLEAVE );

    /* Calibrate ADC module */
    Adc_Calibrate( AdcHwUnit_0, &CalibStatus );
    /* Set the memory buffer to store conversions */
    Adc_SetupResultBuffer(AdcGroup_0, ResultBuffer);

    while( 1u )
    {
        /* Software trigger conversion */
        Adc_StartGroupConversion( AdcGroup_0 );
        /* Wait until the conversion is done */
        while( Adc_GetGroupStatus( AdcGroup_0 ) == ADC_BUSY );
        /* Read ready conversion */
        Adc_ReadGroup( AdcGroup_0, AdcReadGroupBuffer );
        /* Display value */
        SEGGER_RTT_printf( 0, "Pot1 CH5 value: %d, Pot2 CH8 value: %d, Pot1 CH4 value: %d, Pot2 CH9 value: %d \n", 
            AdcReadGroupBuffer[AdcChannel_0], AdcReadGroupBuffer[AdcChannel_1], AdcReadGroupBuffer[AdcChannel_2], AdcReadGroupBuffer[AdcChannel_3] );
        Delay( 1000u );
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
    /*Enable and setup interrupts*/
    Platform_Init( NULL_PTR );

    /*Apply all the Pin Port microcontroller configuration, for this case
    only Port Pin ADC0-SE5 (B1) and ADC0-SE8 (B13) */
    Port_Init( &Port_Config );

    /* Init the ADC with the paramters set in Tresos*/
    Adc_Init( &Adc_Config );
}

/* This is dummy delay function prepared just for this example, in a real application 
no delay shall be used*/
void Delay( uint32 ms )
{
    uint32 Timeout = OsIf_MicrosToTicks( ms * 1000u, OSIF_COUNTER_SYSTEM );
    uint32 SeedTick = OsIf_GetCounter( OSIF_COUNTER_SYSTEM );
    uint32 ElapsedTime = 0u;
    do
    {
        ElapsedTime += OsIf_GetElapsed( &SeedTick, OSIF_COUNTER_SYSTEM );
    }while( ElapsedTime < Timeout );
}