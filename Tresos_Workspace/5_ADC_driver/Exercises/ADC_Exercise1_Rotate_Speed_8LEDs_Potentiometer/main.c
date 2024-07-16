/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * ***********************************************************************************************************************
 * Exercise 1. 
 * Vary the rotation speed of eight LEDs using one of the potentiometers on the board.
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

uint8 AdcFlag = FALSE;
Adc_ValueGroupType    AdcReadGroupBuffer[1];
uint32 adcvalue = 0;

/* This function is called when the ADC conversion is done and the result is ready to be read.
Name of the function can be anything but as per AUTOSAR shall be IoHwAb_AdcNotification_<groupID> */
void IoHwAb_AdcNotification_0( void )
{
    /* Read ready converSion*/
    AdcFlag = TRUE;
    Adc_ReadGroup( AdcGroup_0, AdcReadGroupBuffer );    
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
    Adc_CalibrationStatusType CalibStatus;
    Adc_ValueGroupType    ResultBuffer[1];

    EcuM_Init();

    /* Intiliaze RTT library */
    SEGGER_RTT_Init();

    /* Calibrate ADC module */
    Adc_Calibrate( AdcHwUnit_0, &CalibStatus );
    /* Set the memory buffer to store conversions */
    Adc_SetupResultBuffer(AdcGroup_0, ResultBuffer);
    /*Enable the notification function*/
    Adc_EnableGroupNotification( AdcGroup_0 );

    while( 1u )
    {
        /* Software trigger conversion */
        Adc_StartGroupConversion( AdcGroup_0 );
        /* Wait until the conversion is done, in real world application we shall not wait at all. */
        while( AdcFlag == FALSE );
        AdcFlag = FALSE;
        /* Display value */
        SEGGER_RTT_printf( 0, "Adc Channel value: %d\n", AdcReadGroupBuffer[0] );
        adcvalue = (uint32)AdcReadGroupBuffer[0];
        
        /*A led ON will rotate from C8 to C15*/
        for( uint8 i = 0u ; i < 8u ; i++ )
        {
            Dio_WriteChannelGroup( DioConf_DioChannelGroup_PORTC_LEDS, 0x00u );
            Dio_WriteChannelGroup( DioConf_DioChannelGroup_PORTC_LEDS, ( 1u << i ) );
            /*dummy delay*/
            for( uint32 i = 0u ; i < ((adcvalue * 200) + 50000u) ; i++ );   // Small calibration for leds delay
        }
        
        Delay( 30u );
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
    ports from C8 to C15 are configured as output and  Port Pin ADC0-SE5 (B1) */
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
