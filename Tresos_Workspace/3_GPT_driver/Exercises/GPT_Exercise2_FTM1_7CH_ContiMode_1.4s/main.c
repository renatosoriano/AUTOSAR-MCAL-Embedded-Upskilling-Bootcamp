/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * ***********************************************************************************************************************
 * Exercise 2. 
 * Configure all seven channels of timer FTM1 as Gpt timers in continuous mode with notifications, 
 * all of them somehow shall be make a period of 1.4 second to toggle a led, use the notifications for that purpose.
 * ***********************************************************************************************************************
*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Gpt.h"
#include "Platform.h"

void EcuM_Init( void );

/*This function is gonna be called on ISR from FTM1_CH0, it is basically a callback
called by FTM_1_CH_0_ISR library function*/
void Gpt_TimeoutCallback_0( void )
{
    /*Here, we just continue the next 200ms timer*/
    Gpt_StartTimer( GptConf_GptChannelConfiguration_GptChannelConfiguration_1, 18750u );
    Gpt_EnableNotification( GptConf_GptChannelConfiguration_GptChannelConfiguration_1 );
}

/*This function is gonna be called on ISR from FTM1_CH1, it is basically a callback
called by FTM_1_CH_1_ISR library function*/
void Gpt_TimeoutCallback_1( void )
{
    /*Here, we just continue the next 200ms timer*/
    Gpt_StartTimer( GptConf_GptChannelConfiguration_GptChannelConfiguration_2, 18750u );
    Gpt_EnableNotification( GptConf_GptChannelConfiguration_GptChannelConfiguration_2 );
}

/*This function is gonna be called on ISR from FTM1_CH2, it is basically a callback
called by FTM_1_CH_2_ISR library function*/
void Gpt_TimeoutCallback_2( void )
{
    /*Here, we just continue the next 200ms timer*/
    Gpt_StartTimer( GptConf_GptChannelConfiguration_GptChannelConfiguration_3, 18750u );
    Gpt_EnableNotification( GptConf_GptChannelConfiguration_GptChannelConfiguration_3 );
}

/*This function is gonna be called on ISR from FTM1_CH3, it is basically a callback
called by FTM_1_CH_3_ISR library function*/
void Gpt_TimeoutCallback_3( void )
{
    /*Here, we just continue the next 200ms timer*/
    Gpt_StartTimer( GptConf_GptChannelConfiguration_GptChannelConfiguration_4, 18750u );
    Gpt_EnableNotification( GptConf_GptChannelConfiguration_GptChannelConfiguration_4 );
}

/*This function is gonna be called on ISR from FTM1_CH4, it is basically a callback
called by FTM_1_CH_4_ISR library function*/
void Gpt_TimeoutCallback_4( void )
{
    /*Here, we just continue the next 200ms timer*/
    Gpt_StartTimer( GptConf_GptChannelConfiguration_GptChannelConfiguration_5, 18750u );
    Gpt_EnableNotification( GptConf_GptChannelConfiguration_GptChannelConfiguration_5 );
}

/*This function is gonna be called on ISR from FTM1_CH5, it is basically a callback
called by FTM_1_CH_5_ISR library function*/
void Gpt_TimeoutCallback_5( void )
{
    /*Here, we just continue the next 200ms timer*/
    Gpt_StartTimer( GptConf_GptChannelConfiguration_GptChannelConfiguration_6, 18750u );
    Gpt_EnableNotification( GptConf_GptChannelConfiguration_GptChannelConfiguration_6 );
}

/*This function is gonna be called on ISR from FTM1_CH6, it is basically a callback
called by FTM_1_CH_6_ISR library function*/
void Gpt_TimeoutCallback_6( void )
{
    /*Here, we finally toggle led connected to C8*/
    Dio_FlipChannel( DioConf_DioChannel_C8_BIT0 );
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

    /*Start the timer and set it to Running state with a timeout of 1.4s / 7 channels = 200ms*/
    /*  Tick frequency = ( 12MHz / 128 prescaler) = 93,750Hz
        Counter = ( 0.200s * 93750Hz )  = 18,750      
        FTM counter max value (MOD register) is 65,535, so it fits within the 16-bit counter range. */
    Gpt_StartTimer( GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 18750u );
    
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
    ports C8 and C9 are configured as output*/
    Port_Init( &Port_Config );
    /*Apply Gpt configuration for FTM1 channel 0 and FTM2 channel 0*/
    Gpt_Init( &Gpt_Config );
}
