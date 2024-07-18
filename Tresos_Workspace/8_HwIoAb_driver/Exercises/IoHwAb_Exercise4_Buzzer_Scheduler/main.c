/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * This file contains the main function of the project, it is the entry point of the program.
 * 
 * ***********************************************************************************************************************
 * Exercise 4. 
 * Create an I/O Hardware Abstraction for the Buzzer on the board, initializing the module first and then running its main 
 * function. Use now an Scheduler where HwIoAb_Buzzer_Beep() and HwIoAb_Buzzer_Stop() are executed within the 100ms task. 
 * Play different tones for the buttons cases single click, double click, hold and stop tone sound at buttons release.
 * ***********************************************************************************************************************
*/

#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Osif.h"
#include "SEGGER_RTT.h"
#include "HwIoAb_0_Buttons.h"
#include "HwIoAb_1_Leds.h"
#include "HwIoAb_2_Pots.h"
#include "HwIoAb_3_Buzzer.h"
#include "Scheduler.h"

void EcuM_Init( void );
void Os_50ms_Task( void );
void Os_100ms_Task( void );

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

    /* Intiliaze RTT library */
    SEGGER_RTT_Init();

    /* Init the scheduler with two tasks */
    Scheduler_Init( &Scheduler_Config );

    while( 1u ) 
    {
        /* Run the scheduler forever */
        Scheduler_MainFunction( );
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
    Mcu_SetMode( McuModeSettingConf_0 );
    Mcu_InitClock( McuClockSettingConfig_0 );

    /* Init the internal tick reference Systick Timer */
    OsIf_Init( NULL_PTR );
    /* Enable and setup interrupts */
    Platform_Init( NULL_PTR );

    /* Apply all the Pin Port microcontroller configuration, for this case
    ports D0, D15 and D16 for RGB LEDs and A12, D17, E12 for Buttons. */
    Port_Init( &Port_Config );

    /* Init the ADC with the parameters set in Tresos*/
    Adc_Init( &Adc_Config );

    /*
    The hardware Interleave (Reference Manual page 1194) implementation 
    for ADC on this device is as following:
    • ADC0_SE4 and ADC1_SE14 channels are interleaved on PTB0 pin 
    • ADC0_SE5 and ADC1_SE15 channels are interleaved on PTB1 pin 
    • ADC1_SE8 and ADC0_SE8 channels are interleaved on PTB13 pin 
    • ADC1_SE9 and ADC0_SE9 channels are interleaved on PTB14 pin
    */
    /* By default ADC0-CH5 is not connected to B1, but with this function it will */
    Port_Ci_Port_Ip_SetMuxModeSel( IP_PORTB, 1, PORT_MUX_ADC_INTERLEAVE );
    /* By default ADC0-CH8 is not connected to B13, but with this function it will */
    Port_Ci_Port_Ip_SetMuxModeSel( IP_PORTB, 13, PORT_MUX_ADC_INTERLEAVE );

    /* Init Pwm driver and configuration for FTM1-CH7 */
    Pwm_Init( &Pwm_Config );   

    /* Buttons init */
    HwIoAb_Buttons_Init( &ButtonsCfg );
    /* RGB Leds init */
    HwIoAb_Leds_Init( &LedsCfg );
    /* Pots init */
    HwIoAb_Pots_Init( NULL_PTR );
    /* Buzzer init */
    HwIoAb_Buzzer_Init( NULL_PTR );
}

/**
 * @brief This is the function for the 50ms task.
 *
 * This function executes the state machine every 50ms.
 */
void Os_50ms_Task( void )
{
    HwIoAb_Buttons_MainFunction();
}

/**
 * @brief This is the function for the 100ms task.
 *
 * This function is called every 100ms and gets the last event detected for each button for executing a certain action.
 * 
 * @note Button 1, Button 2, Button 3: 
 * - Single click: toggle only RGB_LED_BLUE (D0), print Pot 1 ADC0 value in ohms, and play Tone 1 in Buzzer. 
 * - Double click: toggle only RGB_LED_RED (D15), print Pot 2 ADC0 value in ohms, and play Tone 2 in Buzzer. 
 * - Hold click:   toggle only RGB_LED_GREEN (D16), print Pot 1 ADC1 (alternate) value in ohms, and play Tone 3 in Buzzer.  
 * - Release:      turn OFF all RGB LEDs, print Pot 2 ADC1 (alternate) value in ohms, and stop Tones in Buzzer. 
 */
void Os_100ms_Task( void )
{
    uint8 RealEvent = 0;    // Actual event of button.

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
                            HwIoAb_Pots_GetValue( HWIOAB_POTS_MAIN_CONVERTED_RESULTS );
                            SEGGER_RTT_printf( 0, "Pot 1 ADC0 resistance value in ohms: %d\n", PotsControl_Ptr->Ohms_results_main[0] );
                            HwIoAb_Buzzer_Beep( HWIOAB_BUZZER_TONE_1 );
                            SEGGER_RTT_printf( 0, "Buzzer playing Tone 1 at 3Khz \n" );
                        break;
                        case HWIOAB_BTN_EVENT_DOUBLE_CLICK :
                            HwIoAb_Leds_TurnToggle( HWIOAB_LED_RED_ID );
                            SEGGER_RTT_printf( 0, "Button 1 action: DOUBLE_CLICK \n" );
                            HwIoAb_Pots_GetValue( HWIOAB_POTS_MAIN_CONVERTED_RESULTS );
                            SEGGER_RTT_printf( 0, "Pot 2 ADC0 resistance value in ohms: %d\n", PotsControl_Ptr->Ohms_results_main[1] );
                            HwIoAb_Buzzer_Beep( HWIOAB_BUZZER_TONE_2 );
                            SEGGER_RTT_printf( 0, "Buzzer playing Tone 2 at 5Khz \n" );
                        break;
                        case HWIOAB_BTN_EVENT_HOLD_CLICK :
                            HwIoAb_Leds_TurnToggle( HWIOAB_LED_GREEN_ID );
                            SEGGER_RTT_printf( 0, "Button 1 action: HOLD_CLICK \n" );
                            HwIoAb_Pots_GetAltValue( HWIOAB_POTS_ALTER_CONVERTED_RESULTS );
                            SEGGER_RTT_printf( 0, "Pot 1 ADC1 resistance value in ohms: %d\n", PotsControl_Ptr->Ohms_results_alter[0] );
                            HwIoAb_Buzzer_Beep( HWIOAB_BUZZER_TONE_3 );
                            SEGGER_RTT_printf( 0, "Buzzer playing Tone 3 at 7.5Khz \n" );
                        break;
                        case HWIOAB_BTN_EVENT_RELEASE :
                            HwIoAb_Leds_TurnOff( HWI0AB_LED_BLUE_ID );
                            HwIoAb_Leds_TurnOff( HWIOAB_LED_RED_ID );
                            HwIoAb_Leds_TurnOff( HWIOAB_LED_GREEN_ID );
                            SEGGER_RTT_printf( 0, "Button 1 action: RELEASE \n" );
                            HwIoAb_Pots_GetAltValue( HWIOAB_POTS_ALTER_CONVERTED_RESULTS );
                            SEGGER_RTT_printf( 0, "Pot 2 ADC1 resistance value in ohms: %d\n", PotsControl_Ptr->Ohms_results_alter[1] );
                            HwIoAb_Buzzer_Stop();
                            SEGGER_RTT_printf( 0, "Buzzer stopped \n" );
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
                            HwIoAb_Pots_GetValue( HWIOAB_POTS_MAIN_CONVERTED_RESULTS );
                            SEGGER_RTT_printf( 0, "Pot 1 ADC0 resistance value in ohms: %d\n", PotsControl_Ptr->Ohms_results_main[0] );
                            HwIoAb_Buzzer_Beep( HWIOAB_BUZZER_TONE_1 );
                            SEGGER_RTT_printf( 0, "Buzzer playing Tone 1 at 3Khz \n" );
                        break;
                        case HWIOAB_BTN_EVENT_DOUBLE_CLICK :
                            HwIoAb_Leds_TurnToggle( HWIOAB_LED_RED_ID );
                            SEGGER_RTT_printf( 0, "Button 2 action: DOUBLE_CLICK \n" );
                            HwIoAb_Pots_GetValue( HWIOAB_POTS_MAIN_CONVERTED_RESULTS );
                            SEGGER_RTT_printf( 0, "Pot 2 ADC0 resistance value in ohms: %d\n", PotsControl_Ptr->Ohms_results_main[1] );
                            HwIoAb_Buzzer_Beep( HWIOAB_BUZZER_TONE_2 );
                            SEGGER_RTT_printf( 0, "Buzzer playing Tone 2 at 5Khz \n" );
                        break;
                        case HWIOAB_BTN_EVENT_HOLD_CLICK :
                            HwIoAb_Leds_TurnToggle( HWIOAB_LED_GREEN_ID );
                            SEGGER_RTT_printf( 0, "Button 2 action: HOLD_CLICK \n" );
                            HwIoAb_Pots_GetAltValue( HWIOAB_POTS_ALTER_CONVERTED_RESULTS );
                            SEGGER_RTT_printf( 0, "Pot 1 ADC1 resistance value in ohms: %d\n", PotsControl_Ptr->Ohms_results_alter[0] );
                            HwIoAb_Buzzer_Beep( HWIOAB_BUZZER_TONE_3 );
                            SEGGER_RTT_printf( 0, "Buzzer playing Tone 3 at 7.5Khz \n" );
                        break;
                        case HWIOAB_BTN_EVENT_RELEASE :
                            HwIoAb_Leds_TurnOff( HWI0AB_LED_BLUE_ID );
                            HwIoAb_Leds_TurnOff( HWIOAB_LED_RED_ID );
                            HwIoAb_Leds_TurnOff( HWIOAB_LED_GREEN_ID );
                            SEGGER_RTT_printf( 0, "Button 2 action: RELEASE \n" );
                            HwIoAb_Pots_GetAltValue( HWIOAB_POTS_ALTER_CONVERTED_RESULTS );
                            SEGGER_RTT_printf( 0, "Pot 2 ADC1 resistance value in ohms: %d\n", PotsControl_Ptr->Ohms_results_alter[1] );
                            HwIoAb_Buzzer_Stop();
                            SEGGER_RTT_printf( 0, "Buzzer stopped \n" );
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
                            HwIoAb_Pots_GetValue( HWIOAB_POTS_MAIN_CONVERTED_RESULTS );
                            SEGGER_RTT_printf( 0, "Pot 1 ADC0 resistance value in ohms: %d\n", PotsControl_Ptr->Ohms_results_main[0] );
                            HwIoAb_Buzzer_Beep( HWIOAB_BUZZER_TONE_1 );
                            SEGGER_RTT_printf( 0, "Buzzer playing Tone 1 at 3Khz \n" );
                        break;
                        case HWIOAB_BTN_EVENT_DOUBLE_CLICK :
                            HwIoAb_Leds_TurnToggle( HWIOAB_LED_RED_ID );
                            SEGGER_RTT_printf( 0, "Button 3 action: DOUBLE_CLICK \n" );
                            HwIoAb_Pots_GetValue( HWIOAB_POTS_MAIN_CONVERTED_RESULTS );
                            SEGGER_RTT_printf( 0, "Pot 2 ADC0 resistance value in ohms: %d\n", PotsControl_Ptr->Ohms_results_main[1] );
                            HwIoAb_Buzzer_Beep( HWIOAB_BUZZER_TONE_2 );
                            SEGGER_RTT_printf( 0, "Buzzer playing Tone 2 at 5Khz \n" );
                        break;
                        case HWIOAB_BTN_EVENT_HOLD_CLICK :
                            HwIoAb_Leds_TurnToggle( HWIOAB_LED_GREEN_ID );
                            SEGGER_RTT_printf( 0, "Button 3 action: HOLD_CLICK \n" );
                            HwIoAb_Pots_GetAltValue( HWIOAB_POTS_ALTER_CONVERTED_RESULTS );
                            SEGGER_RTT_printf( 0, "Pot 1 ADC1 resistance value in ohms: %d\n", PotsControl_Ptr->Ohms_results_alter[0] );
                            HwIoAb_Buzzer_Beep( HWIOAB_BUZZER_TONE_3 );
                            SEGGER_RTT_printf( 0, "Buzzer playing Tone 3 at 7.5Khz \n" );
                        break;
                        case HWIOAB_BTN_EVENT_RELEASE :
                            HwIoAb_Leds_TurnOff( HWI0AB_LED_BLUE_ID );
                            HwIoAb_Leds_TurnOff( HWIOAB_LED_RED_ID );
                            HwIoAb_Leds_TurnOff( HWIOAB_LED_GREEN_ID );
                            SEGGER_RTT_printf( 0, "Button 3 action: RELEASE \n" );
                            HwIoAb_Pots_GetAltValue( HWIOAB_POTS_ALTER_CONVERTED_RESULTS );
                            SEGGER_RTT_printf( 0, "Pot 2 ADC1 resistance value in ohms: %d\n", PotsControl_Ptr->Ohms_results_alter[1] );
                            HwIoAb_Buzzer_Stop();
                            SEGGER_RTT_printf( 0, "Buzzer stopped \n" );
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
