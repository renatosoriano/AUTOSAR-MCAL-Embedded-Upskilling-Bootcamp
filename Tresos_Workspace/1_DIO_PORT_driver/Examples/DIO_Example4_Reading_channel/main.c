/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Modular-MX
 * 
 * ***********************************************************************************************************************
 * Example 4. 
 * Read one pin and toggle another led.
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

    /*Another way to set default/startup LEDs values*/
    //Dio_WriteChannel( DioConf_DioChannel_D16_GREEN_LED, 0x1 );    //0x1 OFF, 0x0 ON
    //Dio_WriteChannel( DioConf_DioChannel_D15_RED_LED, 0x1 );    //0x1 OFF, 0x0 ON

    while( 1u )
    {
        /*Inquire the pin state where the button is connected*/
        if( Dio_ReadChannel( DioConf_DioChannel_D17_SW2_BTN ) != STD_ON )   //0x1 or == UNPRESSED, 0x0 or != PRESSED
        {
            //Dio_FlipChannel( DioConf_DioChannel_D16_GREEN_LED );
            Dio_FlipChannel( DioConf_DioChannel_D15_RED_LED );
        }
        /*dummy delay to avoid polling the btn to often*/
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
    ports D16 and E8*/
    Port_Init( &Port_Config );
}
