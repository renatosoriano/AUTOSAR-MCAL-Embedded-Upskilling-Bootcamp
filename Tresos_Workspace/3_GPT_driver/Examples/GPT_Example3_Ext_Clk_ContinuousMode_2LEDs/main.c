/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Modular-MX
 * 
 * ***********************************************************************************************************************
 * Example 3. 
 * Toggle two leds each of them in alternate way every 200ms using continuous mode and Notifications. 
 * The frequency feeding the FTM0 timer is the FIRCDIV1 with a preescaler of 2.
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
void Gpt_TimeoutCallback_0( void )
{
    /*here, we just toggle led connected to D0*/
    Dio_FlipChannel( DioConf_DioChannel_D0_BLUE_LED );
}

/*This function is gonna be called on ISR from FTM0_CH0_CH1, it is basically a callback
called by FTM_0_CH_0_CH_1_ISR library function*/
void Gpt_TimeoutCallback_1( void )
{
    /*here, we just toggle led connected to D16*/
    Dio_FlipChannel( DioConf_DioChannel_D16_GREEN_LED );
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
    /*Start the timer and set it to Running state with a timeout of 200ms*/
    /*  Counter = ( Timeout * Tfrec ) / Preescler
        Counter = ( 0.200 * (24MHz / 2) ) / 128 = 18,750      */
    Gpt_StartTimer( GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 37500u );
    Gpt_StartTimer( GptConf_GptChannelConfiguration_GptChannelConfiguration_1, 37500u );    
    
    /*Enable notifications, Gpt_TimeoutCallback will be called on each timeout*/
    Gpt_EnableNotification( GptConf_GptChannelConfiguration_GptChannelConfiguration_0 );
    Gpt_EnableNotification( GptConf_GptChannelConfiguration_GptChannelConfiguration_1 );

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
    ports D0 and D16 are configured as output*/
    Port_Init( &Port_Config );
    /*Apply Gpt configuration for FTM0 channel 0*/
    Gpt_Init( &Gpt_Config );
}
