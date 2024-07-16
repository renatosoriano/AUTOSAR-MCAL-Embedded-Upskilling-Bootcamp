/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Modular-MX
 * 
 * This file contains the main function of the project, it is the entry point of the program
 * it contains a simple program that toggles a pin of the microcontroller
*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
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
    EcuM_Init();

    /* Intiliaze RTT library*/
    SEGGER_RTT_Init();

    while( 1u )
    {
        Dio_FlipChannel( DioConf_DioChannel_DioChannel_0 );
        /* Send a message to Ozone using the Jlink debugger */
        SEGGER_RTT_printf( 0, "Hello World\n" );
        /*dummy delay*/
        for( uint32 i = 0u ; i < 1000000u ; i++ );
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
    only Port Pin 122  (D16) is configured as output*/
    Port_Init( &Port_Config );
}
