/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * This file contains the main function of the project, it is the entry point of the program.
 * 
 * ***********************************************************************************************************************
 * Example 2. 
 * Create an I/O Hardware Abstraction for the 3 RGB LEDs on the board, initializing the module first and then running its
 * main functions.
 * Files:
 * - HwIoAb_1_Leds_Cfg.h
 * - HwIoAb_1_Leds.h
 * - HwIoAb_1_Leds_Cfg.c
 * - HwIoAb_1_Leds.c
 * ***********************************************************************************************************************
*/

#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Osif.h"
#include "SEGGER_RTT.h"
#include "HwIoAb_0_Buttons.h"
#include "HwIoAb_1_Leds.h"

void EcuM_Init( void );
void Delay( uint32 ms );

/* This is dummy delay function prepare just for this example, in a real application 
no delay shall be used*/
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
    uint8 RealEvent = 0;    // Actual event of button.

    EcuM_Init();

    /* Intiliaze RTT library */
    SEGGER_RTT_Init();

    while( 1u )
    {
        HwIoAb_Buttons_MainFunction();
        Delay( 10 );   

        for ( uint8 CurrentButton = 0; CurrentButton < HWIOAB_BUTTONS_MAX; CurrentButton++ )    // Checking each button and its event detected.
        {  
            RealEvent =  HwIoAb_Buttons_GetEvent( CurrentButton );   // Obtaining event of actual button.

            if ( RealEvent != HWIOAB_BTN_EVENT_IDLE )    // A click was detected
            {
                switch( CurrentButton )
                {
                    case HWI0AB_BUTTONS_1_ID :
                        switch( RealEvent )
                        {
                            case HWIOAB_BTN_EVENT_SINGLE_CLICK :
                                HwIoAb_Leds_TurnToggle( HWI0AB_LED_BLUE_ID );
                                SEGGER_RTT_printf( 0, "Button 1 action: SINGLE_CLICK \n" );
                            break;
                            case HWIOAB_BTN_EVENT_DOUBLE_CLICK :
                                HwIoAb_Leds_TurnToggle( HWIOAB_LED_RED_ID );
                                SEGGER_RTT_printf( 0, "Button 1 action: DOUBLE_CLICK \n" );
                            break;
                            case HWIOAB_BTN_EVENT_HOLD_CLICK :
                                HwIoAb_Leds_TurnToggle( HWIOAB_LED_GREEN_ID );
                                SEGGER_RTT_printf( 0, "Button 1 action: HOLD_CLICK \n" );
                            break;
                            case HWIOAB_BTN_EVENT_RELEASE :
                                HwIoAb_Leds_TurnOff( HWI0AB_LED_BLUE_ID );
                                HwIoAb_Leds_TurnOff( HWIOAB_LED_RED_ID );
                                HwIoAb_Leds_TurnOff( HWIOAB_LED_GREEN_ID );
                                SEGGER_RTT_printf( 0, "Button 1 action: RELEASE \n" );
                            break;
                            default :
                              // If jump here is an error
                            break;
                        }
                    break;
                    case HWIOAB_BUTTONS_2_ID :
                        switch( RealEvent )
                        {
                            case HWIOAB_BTN_EVENT_SINGLE_CLICK :
                                HwIoAb_Leds_TurnToggle( HWI0AB_LED_BLUE_ID );
                                SEGGER_RTT_printf( 0, "Button 2 action: SINGLE_CLICK \n" );
                            break;
                            case HWIOAB_BTN_EVENT_DOUBLE_CLICK :
                                HwIoAb_Leds_TurnToggle( HWIOAB_LED_RED_ID );
                                SEGGER_RTT_printf( 0, "Button 2 action: DOUBLE_CLICK \n" );
                            break;
                            case HWIOAB_BTN_EVENT_HOLD_CLICK :
                                HwIoAb_Leds_TurnToggle( HWIOAB_LED_GREEN_ID );
                                SEGGER_RTT_printf( 0, "Button 2 action: HOLD_CLICK \n" );
                            break;
                            case HWIOAB_BTN_EVENT_RELEASE :
                                HwIoAb_Leds_TurnOff( HWI0AB_LED_BLUE_ID );
                                HwIoAb_Leds_TurnOff( HWIOAB_LED_RED_ID );
                                HwIoAb_Leds_TurnOff( HWIOAB_LED_GREEN_ID );
                                SEGGER_RTT_printf( 0, "Button 2 action: RELEASE \n" );
                            break;
                            default :
                              // If jump here is an error
                            break;
                        }
                    break;
                    case HWIOAB_BUTTONS_3_ID :
                        switch( RealEvent )
                        {
                            case HWIOAB_BTN_EVENT_SINGLE_CLICK :
                                HwIoAb_Leds_TurnToggle( HWI0AB_LED_BLUE_ID );
                                SEGGER_RTT_printf( 0, "Button 3 action: SINGLE_CLICK \n" );
                            break;
                            case HWIOAB_BTN_EVENT_DOUBLE_CLICK :
                                HwIoAb_Leds_TurnToggle( HWIOAB_LED_RED_ID );
                                SEGGER_RTT_printf( 0, "Button 3 action: DOUBLE_CLICK \n" );
                            break;
                            case HWIOAB_BTN_EVENT_HOLD_CLICK :
                                HwIoAb_Leds_TurnToggle( HWIOAB_LED_GREEN_ID );
                                SEGGER_RTT_printf( 0, "Button 3 action: HOLD_CLICK \n" );
                            break;
                            case HWIOAB_BTN_EVENT_RELEASE :
                                HwIoAb_Leds_TurnOff( HWI0AB_LED_BLUE_ID );
                                HwIoAb_Leds_TurnOff( HWIOAB_LED_RED_ID );
                                HwIoAb_Leds_TurnOff( HWIOAB_LED_GREEN_ID );
                                SEGGER_RTT_printf( 0, "Button 3 action: RELEASE \n" );
                            break;
                            default :
                              // If jump here is an error
                            break;
                        }
                    break;
                    default :
                      // If jump here is an error
                    break;
                }  
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
    /* Init Mcu module, including internal PLL, reference to Mcu Config structure can 
    be found at Mcu_PBcfg.h and PLL defines at Mcu_Cfg.h */
    Mcu_Init( &Mcu_Config );
    Mcu_InitClock( McuClockSettingConfig_0 );
    Mcu_SetMode( McuModeSettingConf_0 );

    /* Init the internal tick reference Systick Timer */
    OsIf_Init( NULL_PTR );
    
    /* Apply all the Pin Port microcontroller configuration, for this case
    ports D0, D15 and D16 for RGB LEDs and A12, D17, E12 for Buttons. */
    Port_Init( &Port_Config );

    /* Buttons init */
    HwIoAb_Buttons_Init( &ButtonsCfg );
    /* RGB Leds init */
    HwIoAb_Leds_Init( &LedsCfg );
}
