/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * ***********************************************************************************************************************
 * Exercise 2. 
 * Generate two complement PWM signal with dead time insertion of around 1% of the period of the signal.
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
    
    /* Start the period and set it with a timeout of 100ms:
    Tick frequency = ( 48MHz / 128 ) = 375,000Hz
    Counter = ( 0.100s * 375000Hz )  = 37500     --> 37500 * 1% = 375
    FTM counter max value (MOD register) is 65,535, so it fits within the 16-bit counter range. 
    */

    /*
    In this case the pair is Red RGB Led (FTM0-CH0) for 'channel n' and Green RGB Led (FTM0-CH1) for 'channel n+1'.
    In Complementary mode, the channel (n+1) output (Green RGB Led) is the inverse of the channel (n) output (Red RGB Led).
    
    The desired mode is 'Invert Output'. Hence by now we should see on the board as visible output that, when one RGB Led 
    goes OFF the other goes ON and viceversa. They toggle each other.
    *See Channel (n+1) output in Complementary mode diagram from NXP S32K1xx Reference Manual Rev. 13, page 1448.

    The deadtime delay insertion ensures that no two complementary signals (channels n and n+1) drive the 
    active state at the same time.

    So deadtime delay insertion of 1% means 375 ticks value, is the 1% of the 37500 period value configured for the channels.
    */

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
