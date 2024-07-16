/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Modular-MX
 * 
 * ***********************************************************************************************************************
 * Example 1. 
 * This is the most simple ADC configuration to take one single conversion from one single channel. 
 * The Modular-S1 on board Pot1 is connected to channel 5 from the ADC0, the activation conversion is perform by 
 * the calling of function Adc_StartGroupConversion(). Remember that AUTOSAR only specifies channels conversion in groups.
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
    Adc_ValueGroupType    AdcReadGroupBuffer[1];
    Adc_ValueGroupType    ResultBuffer[1];

    EcuM_Init();

    /* Intiliaze RTT library */
    SEGGER_RTT_Init();

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
        SEGGER_RTT_printf( 0, "Adc Channel value: %d\n", AdcReadGroupBuffer[0] );
        Delay( 2000u );
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
    only Port Pin ADC0-SE5  (B1) */
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