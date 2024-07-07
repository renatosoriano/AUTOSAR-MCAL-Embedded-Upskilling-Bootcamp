/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Modular-MX
 * 
 * ***********************************************************************************************************************
 * Example 1. 
 * Toggle one led each 100ms.
 * ***********************************************************************************************************************
*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Gpt.h"

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
    /*Start the timer and set it to Running state*/
    /*  Counter = ( Timeout * Tfrec ) / Preescler
        Counter = ( 0.100 * 48MHz ) / 128 = 37,500      */
    Gpt_StartTimer( GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 37500u );

    while( 1u )
    {
        if( Gpt_GetTimeRemaining( GptConf_GptChannelConfiguration_GptChannelConfiguration_0 ) == 0u )
        {
            /*if we are not using notifications it is neceseary to change the channel status from running
            manually, we can use the Stop function for that purpose, otherwise the Start function will 
            never reload the timer with a new count again */
            Gpt_StopTimer( GptConf_GptChannelConfiguration_GptChannelConfiguration_0 );
            //Dio_FlipChannel( DioConf_DioChannel_D16_GREEN_LED );
            Dio_FlipChannel( DioConf_DioChannel_D0_BLUE_LED );
            /*start the timer again*/
            Gpt_StartTimer( GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 37500u );
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
    ports D16 and D0 are configured as output*/
    Port_Init( &Port_Config );
    /*Apply Gpt configuration for FTM0 channel 0*/
    Gpt_Init( &Gpt_Config );
}
