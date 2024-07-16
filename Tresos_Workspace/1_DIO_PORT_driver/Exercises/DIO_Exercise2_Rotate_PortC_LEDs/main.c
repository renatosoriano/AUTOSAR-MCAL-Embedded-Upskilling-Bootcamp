/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * This file contains the main function of the project, it is the entry point of the program.
 * 
 * ***********************************************************************************************************************
 * Exercise 2. 
 * Write a program that rotates a turned-off LED on port C at a speed that is perceptible to the human eye. 
 * Define a DioChannelGroup for leds in port C.
 * ***********************************************************************************************************************
*/

#include "Mcu.h"
#include "Port.h"
#include "Dio.h"

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
    EcuM_Init();

    while( 1u )
    {
        /*A led on will rotate from C8 to C15*/
        for( uint8 i = 0u ; i < 8u ; i++ )
        {
            Dio_WriteChannelGroup( DioConf_DioChannelGroup_PORTC_LEDS, 0x00u );
            Dio_WriteChannelGroup( DioConf_DioChannelGroup_PORTC_LEDS, ( 1u << i ) );
            /*dummy delay*/
            for( uint32 i = 0u ; i < 100000u ; i++ );
        }
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
    /*Apply all the Pin Port microcontroller configuration, for this case
    ports from C8 to C15 are configured as output*/
    Port_Init( &Port_Config );
}
