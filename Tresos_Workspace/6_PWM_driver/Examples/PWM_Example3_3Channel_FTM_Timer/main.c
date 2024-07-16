/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Modular-MX
 * 
 * ***********************************************************************************************************************
 * Example 3. 
 * On this example we set three channels connected to RGB led with the PWM initially set with a duty cycle of 0, meaning 
 * the signal is equal to its state IDLE. Then in code the function Pwm_SetPeriodAndDuty() is called to set period and 
 * duty cycle. It is necessarily to enable this function and also the option Channel class: shall be set to PWM_VARIABLE_PERIOD.
 * ***********************************************************************************************************************
*/
#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Pwm.h"
#include "OsIf.h"

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

    Pwm_SetPeriodAndDuty( PwmChannel_0, 37500, 0x2000 );
    Pwm_SetPeriodAndDuty( PwmChannel_1, 37500, 0x4000 );
    Pwm_SetPeriodAndDuty( PwmChannel_2, 37500, 0x8000 );

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
    OsIf_Init(NULL_PTR);
    /*Apply all the Pin Port microcontroller configuration, for this case
    Port Pin D0 (FTM0-CH2), D15 (FTM0-CH1), D16 (FTM0-CH0) are configured as output*/
    Port_Init( &Port_Config );
    Pwm_Init( &Pwm_Config );
}
