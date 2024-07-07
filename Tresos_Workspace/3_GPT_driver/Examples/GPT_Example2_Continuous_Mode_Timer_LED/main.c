/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Modular-MX
 * 
 * ***********************************************************************************************************************
 * Example 2. 
 * Toggle one led every 100ms using continuous mode and notifications.
 * ***********************************************************************************************************************
*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Gpt.h"
#include "Platform.h"

void EcuM_Init( void );

/*This function is gonna be called on ISR from FTM0_CH0_CH1, it is basically a callback
called by FTM_0_CH_0_CH_1_ISR library function*/
void Gpt_Notification_0( void )
{
    /*here, we just toggle led connected to D0*/
    Dio_FlipChannel( DioConf_DioChannel_D0_BLUE_LED );
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
    /*Start the timer and set it to Running state with a timeout of 100ms*/
    /*  Counter = ( Timeout * Tfrec ) / Preescler
        Counter = ( 0.100 * 48MHz ) / 128 = 37,500      */
    Gpt_StartTimer( GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 37500u );
    /*Enable notifications, Gpt_TimeoutCallback will be called on each timeout*/
    Gpt_EnableNotification( GptConf_GptChannelConfiguration_GptChannelConfiguration_0 );

    while( 1u )
    {
  
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
    
    /*Enable and setup interrupts*/
    Platform_Init( NULL_PTR );

    /*Apply all the Pin Port microcontroller configuration, for this case
    ports D16 and D0 are configured as output*/
    Port_Init( &Port_Config );
    /*Apply Gpt configuration for FTM0 channel 0*/
    Gpt_Init( &Gpt_Config );
}
