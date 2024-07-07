/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Modular-MX
 * 
 * ***********************************************************************************************************************
 * Example 2. 
 * On this example we set the same channel connected to blue RGB led but the PWM is initially set with a duty cycle of 0 meaning 
 * the signal is equal to its state IDLE. Then apply variation on the duty cycle using the interface Pwm_SetDutyCycle() keeping 
 * in mind the potential values goes from 0x0 to 0x8000. The variation goes from 25%, 50% and 75% then to set the signal to its IDLE state.
 * ***********************************************************************************************************************
*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Pwm.h"
#include "OsIf.h"

void EcuM_Init( void );

/* This is dummy delay function prepare just for this example, in a real application 
no delay shall be used */
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
        /*Duty cycle set to 25%*/
        Pwm_SetDutyCycle( PwmChannel_0, 0x2000 );
        Delay( 10000 );
        /*Duty cycle set to 50%*/
        Pwm_SetDutyCycle( PwmChannel_0, 0x4000 );
        Delay( 10000 );
        /*Duty cycle set to 75%*/
        Pwm_SetDutyCycle( PwmChannel_0, 0x6000 );
        Delay( 10000 );
        /*Disable the PWM or set to IDLE*/
        Pwm_SetOutputToIdle( PwmChannel_0 );
        Delay( 20000 );
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
    OsIf_Init(NULL_PTR);
    /*Apply all the Pin Port microcontroller configuration, for this case
    only Port Pin D0 is configured as output*/
    Port_Init( &Port_Config );
    Pwm_Init( &Pwm_Config );
}
