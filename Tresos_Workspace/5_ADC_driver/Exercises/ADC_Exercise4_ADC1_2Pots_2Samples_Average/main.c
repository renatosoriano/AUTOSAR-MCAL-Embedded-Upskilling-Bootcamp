/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * ***********************************************************************************************************************
 * Exercise 4. 
 * Modify exercise 2, but this time to use the ADC1, remember pots are connected to interleave pins. 
 * Modify the program again to sample both pots using both ADCs, display the average of two measurements in each channels.
 * ***********************************************************************************************************************
*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Platform.h"
#include "Osif.h"
#include "Adc.h"
#include "SEGGER_RTT.h"
#include <stdio.h> 

/*
Voltage Disclaimer:
The NXP board microcontroller is VDD with 5V, but the Modular-S1 board (where the Potentiometers are located) 
assumes is 3.3V. Well, the only inconvenient will be the ADC can ONLY sample UP TO 3.3V, but it takes 5V as Upper reference.
So the ADC will never give the maximum value of 0xFFF in 12 bits or in any resolution.
2^12 = 4,095 for 5V
2^12 = 2,703 for 3.3V

Potentiometers Disclaimer:
Product Number: 3386P-1-103TLF
Description:    Trimpot 10K OHM 0.5W PC PIN TOP
Resistance:     10K Ohms
Power (Watts):  0.5W, 1/2W
Tolerance:      ±10%
Num of Turns:   1.0
*/

#define ADC_REF_VOLTAGE 3.3
#define ADC_REF_RESISTANCE 10000
#define ADC_MAX_VALUE_RESOLUTION 2703 // 12-bit ADC

void EcuM_Init( void );
void Delay( uint32 ms );
void ConvertAdcValue(uint16 adcValue, uint16* voltage, uint16* resistance);

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
    Adc_ValueGroupType    AdcReadGroupBuffer[2];
    Adc_ValueGroupType    ResultBuffer[2];

    uint16_t adcvalue1_Pot1 = 0;
    uint16_t adcvalue1_Pot2 = 0;
    uint16_t adcvalue2_Pot1 = 0;
    uint16_t adcvalue2_Pot2 = 0;
    uint16_t average_Pot1 = 0;
    uint16_t average_Pot2 = 0;

    uint16 adcValuePot1, adcValuePot2;
    uint16 voltagePot1, voltagePot2;
    uint16 resistancePot1, resistancePot2;

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

    /* By default ADC1-CH15 is not connected to B1, but with this function
    it will, this is called Interleave, read RM page 1194*/
    Port_Ci_Port_Ip_SetMuxModeSel( IP_PORTB, 1, PORT_MUX_ADC_INTERLEAVE );

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

        // ADC raw values for the two potentiometers
        /* Taking 2 samples */
        adcvalue1_Pot1 = AdcReadGroupBuffer[AdcChannel_0];
        adcvalue1_Pot2 = AdcReadGroupBuffer[AdcChannel_1];
        Delay( 100u );

        adcvalue2_Pot1 = AdcReadGroupBuffer[AdcChannel_0];
        adcvalue2_Pot2 = AdcReadGroupBuffer[AdcChannel_1];

        average_Pot1 = (adcvalue1_Pot1 + adcvalue2_Pot1) / 2;
        average_Pot2 = (adcvalue1_Pot2 + adcvalue2_Pot2) / 2;

        // Convert ADC values to voltage and resistance
        ConvertAdcValue(average_Pot1, &voltagePot1, &resistancePot1);
        ConvertAdcValue(average_Pot2, &voltagePot2, &resistancePot2);

        if(resistancePot1 > 10000)
        {
            resistancePot1 = 10000;
        }
        if(resistancePot2 > 10000)
        {
            resistancePot2 = 10000;
        }

        /* Adaptation for display to simulate the floating-point */
        SEGGER_RTT_printf( 0, "Pot1: Voltage = %d V, Resistance = %d Ohms\n", 
            (voltagePot1), (resistancePot1) );   
        SEGGER_RTT_printf( 0, "Pot2: Voltage = %d V, Resistance = %d Ohms\n", 
            (voltagePot2), (resistancePot2) );   

        Delay( 800u );
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

void ConvertAdcValue(uint16 adcValue, uint16* voltage, uint16* resistance) 
{
    *voltage = ((( float )adcValue) / ADC_MAX_VALUE_RESOLUTION) * (ADC_REF_VOLTAGE);
    *resistance = ((( float )adcValue) / ADC_MAX_VALUE_RESOLUTION) * ADC_REF_RESISTANCE;

}
