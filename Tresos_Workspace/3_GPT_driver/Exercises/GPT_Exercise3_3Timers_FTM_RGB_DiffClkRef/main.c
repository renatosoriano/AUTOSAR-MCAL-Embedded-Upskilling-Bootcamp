/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * ***********************************************************************************************************************
 * Exercise 3. 
 * Configure three timers FTM with one channel each of them to toggle the three RGB leds at different frequencies, 
 * the most important is that each FTM timer shall be feed by a different clock reference. 
 * Remember to read the user manual to know where we can take those frequencies.
 * ***********************************************************************************************************************
*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Gpt.h"
#include "Platform.h"

void EcuM_Init( void );

/*This function is gonna be called on ISR from FTM0_CH0, it is basically a callback
called by FTM_0_CH_0_ISR library function*/
void Gpt_TimeoutCallback_0( void )
{
    /*here, we just toggle led connected to C8*/
    Dio_FlipChannel( DioConf_DioChannel_D0_BLUE_LED );
}

/*This function is gonna be called on ISR from FTM1_CH0, it is basically a callback
called by FTM_1_CH_0_ISR library function*/
void Gpt_TimeoutCallback_1( void )
{
    /*here, we just toggle led connected to C8*/
    Dio_FlipChannel( DioConf_DioChannel_D15_RED_LED );
}

/*This function is gonna be called on ISR from FTM2_CH0, it is basically a callback
called by FTM_2_CH_0_ISR library function*/
void Gpt_TimeoutCallback_2( void )
{
    /*here, we just toggle led connected to C9*/
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

    /*Start the timer and set it to Running state with a timeout of 100ms*/
    /*  Tick frequency = ( 12MHz / 128 prescaler) = 93,750Hz
        Counter = ( 0.100s * 93750Hz )  = 9,375      
        FTM counter max value (MOD register) is 65,535, so it fits within the 16-bit counter range. */
    Gpt_StartTimer( GptConf_GptChannelConfiguration_GptChannelConfiguration_0, 9375u );
    /*Start the timer and set it to Running state with a timeout of 400ms*/
    /*  Tick frequency = ( 4MHz / 128 prescaler) = 31,250Hz
        Counter = ( 0.400s * 31250Hz prescaler)  = 12,500      
        FTM counter max value (MOD register) is 65,535, so it fits within the 16-bit counter range. */
    Gpt_StartTimer( GptConf_GptChannelConfiguration_GptChannelConfiguration_1, 12500u );    
    /*Start the timer and set it to Running state with a timeout of 800ms*/
    /*  Tick frequency = ( 8MHz / 128 prescaler) = 62,500Hz
        Counter = ( 0.800s * 62500Hz )  = 50,000      
        FTM counter max value (MOD register) is 65,535, so it fits within the 16-bit counter range. */
    Gpt_StartTimer( GptConf_GptChannelConfiguration_GptChannelConfiguration_1, 50000u );    
    /*Enable notifications, Gpt_TimeoutCallback will be called on each timeout*/
    Gpt_EnableNotification( GptConf_GptChannelConfiguration_GptChannelConfiguration_0 );
    Gpt_EnableNotification( GptConf_GptChannelConfiguration_GptChannelConfiguration_1 );
    Gpt_EnableNotification( GptConf_GptChannelConfiguration_GptChannelConfiguration_2 );

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
    ports D0, D15 and D16 are configured as output*/
    Port_Init( &Port_Config );
    /*Apply Gpt configuration for FTM0 channel 0, FTM1 channel 0 and FTM2 channel 0*/
    Gpt_Init( &Gpt_Config );
}
