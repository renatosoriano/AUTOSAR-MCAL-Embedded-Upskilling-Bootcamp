/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * This file contains the main function of the project, it is the entry point of the program.
 * 
 * ***********************************************************************************************************************
 * Exercise 8. 
 * Modify the previous program using two buttons. Pressing one button will rotate the LEDs from left to right, 
 * and pressing the other button will rotate them from right to left.
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

    while( 1u )
    {
        if( Dio_ReadChannel( DioConf_DioChannel_E12_SW1_BTN ) == 0x00 )   //0x1 = UNPRESSED, 0x0 = PRESSED
        {
            /*A led on will rotate from C8 to C15*/
            for( uint8 i = 0u ; i < 8u ; i++ )
            {
                Dio_WriteChannelGroup( DioConf_DioChannelGroup_PORTC_LEDS, 0x00u );
                Dio_WriteChannelGroup( DioConf_DioChannelGroup_PORTC_LEDS, ( 1u << i ) );
                /*dummy delay*/
                for( uint32 i = 0u ; i < 500000u ; i++ );
            }
        }

        if( Dio_ReadChannel( DioConf_DioChannel_D17_SW2_BTN ) == 0x00 )   //0x1 = UNPRESSED, 0x0 = PRESSED
        {
            /*A led on will rotate from C8 to C15*/
            for( uint8 i = 0u ; i < 8u ; i++ )
            {
                Dio_WriteChannelGroup( DioConf_DioChannelGroup_PORTC_LEDS, 0x00u );
                Dio_WriteChannelGroup( DioConf_DioChannelGroup_PORTC_LEDS, ( 1u << 7-i ) );
                /*dummy delay*/
                for( uint32 i = 0u ; i < 500000u ; i++ );
            }
        }

        if( Dio_ReadChannel( DioConf_DioChannel_A12_SW3_BTN ) == 0x00 )   //0x1 = UNPRESSED, 0x0 = PRESSED
        {
            /*A led on will rotate from C8 to C15*/
            for( uint8 i = 0u ; i < 8u ; i++ )
            {
                Dio_WriteChannelGroup( DioConf_DioChannelGroup_PORTC_LEDS, 0x00u );
                Dio_WriteChannelGroup( DioConf_DioChannelGroup_PORTC_LEDS, ( 1u << i ) );
                /*dummy delay*/
                for( uint32 i = 0u ; i < 100000u ; i++ );
            }
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
    port pins from C8 to C15 are configured as output and buttons E12, D17 and A12 as inputs*/
    Port_Init( &Port_Config );
}
