/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * This file contains the main function of the project, it is the entry point of the program.
 * 
 * ***********************************************************************************************************************
 * Exercise 1. 
 * Blink the LEDs connected to port C alternately (turn on LEDs C8, C10, C12, C14 and then 9C, C11, C13, C15). 
 * Use the initial PortPin Level Value option.
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
        /*Write a value of four bits on a group of Dio channels*/
        Dio_WriteChannelGroup( DioConf_DioChannelGroup_PORTC_1HALF_LEDS, 0x5u );
        Dio_WriteChannelGroup( DioConf_DioChannelGroup_PORTC_2HALF_LEDS, 0x5u );
        /*dummy delay*/
        for( uint32 i = 0u ; i < 5000000u ; i++ );
        /*Write a value of four bits on a group of Dio channels*/
        Dio_WriteChannelGroup( DioConf_DioChannelGroup_PORTC_1HALF_LEDS, 0xAu );
        Dio_WriteChannelGroup( DioConf_DioChannelGroup_PORTC_2HALF_LEDS, 0xAu );
        /*dummy delay*/
        for( uint32 i = 0u ; i < 5000000u ; i++ );
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
