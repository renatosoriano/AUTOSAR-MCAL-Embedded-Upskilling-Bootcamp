/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * ***********************************************************************************************************************
 * Exercise 3. 
 * Modify the second example code (ADC_Example2_Two_CH_Single_Conver_SWTrigger) to have a 8-bit resolution for reading 
 * the potentiometers, and take three readings to display their average value.
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
    Adc_ValueGroupType    AdcReadGroupBuffer[2];
    Adc_ValueGroupType    ResultBuffer[2];

    uint16_t adcvalue1_Pot1 = 0;
    uint16_t adcvalue1_Pot2 = 0;
    uint16_t adcvalue2_Pot1 = 0;
    uint16_t adcvalue2_Pot2 = 0;
    uint16_t adcvalue3_Pot1 = 0;
    uint16_t adcvalue3_Pot2 = 0;
    uint16_t average_Pot1 = 0;
    uint16_t average_Pot2 = 0;

    EcuM_Init();

    /* Intiliaze RTT library */
    SEGGER_RTT_Init();

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

        /* Taking 3 samples */
        adcvalue1_Pot1 = AdcReadGroupBuffer[AdcChannel_0];
        adcvalue1_Pot2 = AdcReadGroupBuffer[AdcChannel_1];
        Delay( 100u );

        adcvalue2_Pot1 = AdcReadGroupBuffer[AdcChannel_0];
        adcvalue2_Pot2 = AdcReadGroupBuffer[AdcChannel_1];
        Delay( 100u );

        adcvalue3_Pot1 = AdcReadGroupBuffer[AdcChannel_0];
        adcvalue3_Pot2 = AdcReadGroupBuffer[AdcChannel_1];

        average_Pot1 = (adcvalue1_Pot1 + adcvalue2_Pot1 + adcvalue3_Pot1) / 3;
        average_Pot2 = (adcvalue1_Pot2 + adcvalue2_Pot2 + adcvalue3_Pot2) / 3;

        /* Display value */
        SEGGER_RTT_printf( 0, "ADC1 average value: %d, ADC2 average value: %d\n", 
            average_Pot1, average_Pot2 );        
        
        Delay( 500u );
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