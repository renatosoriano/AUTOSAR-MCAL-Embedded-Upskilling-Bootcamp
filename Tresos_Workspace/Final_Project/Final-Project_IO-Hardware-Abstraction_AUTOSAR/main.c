/**
 * @file main.c
 * @brief This file contains the main function of the project
 * @author Renato Soriano
 * 
 * This file contains the main function of the project, it is the entry point of the program.
 * 
 * ***********************************************************************************************************************
 * Final Project. 
 * Use previously created I/O Hardware Abstraction modules for the on board Buttons, RGB LEDs, Potentiometers and Buzzer, 
 * all together with the Scheduler, to create an application with the following requirements:
 * 
 *  1. Update the Dio/Port Tresos configuration as well as HwIoAb_1_Leds_Cfg.h and HwIoAb_1_Leds_Cfg.c files in order to add
 *  the Port C eight leds (0-7) found in the Modular S-1 board.
 * 
 *  2. Create two files IoHwAb.h and IoHwAb.c in folder HwIoAbs: 
 *  Initialize all the Init functions of the different Hardware I/Os in a single interface, following the naming convention 
 *  'void IoHwAb_Init<Init_Id>(const IoHwAb{Init_Id}_ConfigType* ConfigPtr)' where init ID is the module ID. 
 *  Final name: 'IoHwAb_Init0( const IoHwAb0_ConfigType* ConfigPtr )'.
 * 
 *  3. For the Os_100ms_Task, create a state machine to detect multiple I/O Hardware Abstraction events.
 *   - Button 1: 
 *      - Single click: shall toggle ON/OFF RGB_LED_BLUE (D0) and C10_LED2 (as SINGLE_CLICK visual indicator). 
 *      - Double click: shall display (SEGGER_RTT_printf) Pot 1 ADC0 value in ohms, toggle C13_LED5 (as DOUBLE_CLICK visual 
 *                      indicator), and toggle C14_LED6 (as Pot 1 visual indicator). 
 *      - Hold click:   buzzer shall start to beep and play Tone 1.  
 *      - Release:      buzzer shall stop.
 *   - Button 2: 
 *      - Single click: shall toggle ON/OFF RGB_LED_RED (D15) and C9_LED1 (as SINGLE_CLICK visual indicator). 
 *      - Double click: shall display (SEGGER_RTT_printf) Pot 2 ADC0 value in ohms, toggle C12_LED4 (as DOUBLE_CLICK visual 
 *                      indicator), and toggle C15_LED7 (as Pot 2 visual indicator). 
 *      - Hold click:   buzzer shall start to beep and play Tone 2.  
 *      - Release:      buzzer shall stop.
 *   - Button 3: 
 *      - Single click: shall toggle ON/OFF RGB_LED_GREEN (D16) and C8_LED0 (as SINGLE_CLICK visual indicator). 
 *      - Double click: shall display (SEGGER_RTT_printf) Pot 1 and Pot 2 ADC1 alternate values in ohms, toggle C11_LED3 
 *                      (as DOUBLE_CLICK visual indicator), toggle C14_LED6 (as Pot 1 visual indicator), and toggle C15_LED7 
 *                      (as Pot 2 visual indicator). 
 *      - Hold click:   buzzer shall start to beep and play Tone 3.  
 *      - Release:      buzzer shall stop.
 * ***********************************************************************************************************************
*/

#include "Mcu.h"
#include "Port.h"
#include "Dio.h"
#include "Osif.h"
#include "SEGGER_RTT.h"
#include "IoHwAb.h"
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

    /* Initializing IO Hardware Abstractions with the module ID 0 */
    IoHwAb_Init0( NULL_PTR );
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
 * @note Button 1: 
 *  - Single click: shall toggle ON/OFF RGB_LED_BLUE (D0) and C10_LED2 (as SINGLE_CLICK visual indicator). 
 *  - Double click: shall display (SEGGER_RTT_printf) Pot 1 ADC0 value in ohms, toggle C13_LED5 (as DOUBLE_CLICK visual 
 *                  indicator), and toggle C14_LED6 (as Pot 1 visual indicator). 
 *  - Hold click:   buzzer shall start to beep and play Tone 1.  
 *  - Release:      buzzer shall stop.
 * @note Button 2: 
 *  - Single click: shall toggle ON/OFF RGB_LED_RED (D15) and C9_LED1 (as SINGLE_CLICK visual indicator). 
 *  - Double click: shall display (SEGGER_RTT_printf) Pot 2 ADC0 value in ohms, toggle C12_LED4 (as DOUBLE_CLICK visual 
 *                  indicator), and toggle C15_LED7 (as Pot 2 visual indicator). 
 *  - Hold click:   buzzer shall start to beep and play Tone 2.  
 *  - Release:      buzzer shall stop.
 * @note Button 3: 
 *  - Single click: shall toggle ON/OFF RGB_LED_GREEN (D16) and C8_LED0 (as SINGLE_CLICK visual indicator). 
 *  - Double click: shall display (SEGGER_RTT_printf) Pot 1 and Pot 2 ADC1 alternate values in ohms, toggle C11_LED3 
 *                  (as DOUBLE_CLICK visual indicator), toggle C14_LED6 (as Pot 1 visual indicator), and toggle C15_LED7 
 *                  (as Pot 2 visual indicator). 
 *  - Hold click:   buzzer shall start to beep and play Tone 3.  
 *  - Release:      buzzer shall stop.
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
                            SEGGER_RTT_printf( 0, "Button 1 action: SINGLE_CLICK \n" );
                            HwIoAb_Leds_TurnToggle( HWI0AB_LED_BLUE_ID );
                            SEGGER_RTT_printf( 0, "Blue RGB LED Toggle \n" );
                            HwIoAb_Leds_TurnToggle( HWIOAB_C10_LED2_ID );    // SINGLE_CLICK visual indicator
                        break;
                        case HWIOAB_BTN_EVENT_DOUBLE_CLICK :
                            SEGGER_RTT_printf( 0, "Button 1 action: DOUBLE_CLICK \n" );
                            HwIoAb_Pots_GetValue( HWIOAB_POTS_MAIN_CONVERTED_RESULTS );
                            SEGGER_RTT_printf( 0, "Pot 1 ADC0 resistance value in ohms: %d\n", PotsControl_Ptr->Ohms_results_main[0] );
                            HwIoAb_Leds_TurnToggle( HWIOAB_C13_LED5_ID );    // DOUBLE_CLICK visual indicator
                            HwIoAb_Leds_TurnToggle( HWIOAB_C14_LED6_ID );    // Pot 1 visual indicator
                        break;
                        case HWIOAB_BTN_EVENT_HOLD_CLICK :
                            SEGGER_RTT_printf( 0, "Button 1 action: HOLD_CLICK \n" );
                            HwIoAb_Buzzer_Beep( HWIOAB_BUZZER_TONE_1 );
                            SEGGER_RTT_printf( 0, "Buzzer playing Tone 1 at 3Khz \n" );
                        break;
                        case HWIOAB_BTN_EVENT_RELEASE :
                            SEGGER_RTT_printf( 0, "Button 1 action: RELEASE \n" );
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
                            SEGGER_RTT_printf( 0, "Button 2 action: SINGLE_CLICK \n" );
                            HwIoAb_Leds_TurnToggle( HWIOAB_LED_RED_ID );
                            SEGGER_RTT_printf( 0, "Red RGB LED Toggle \n" );
                            HwIoAb_Leds_TurnToggle( HWIOAB_C9_LED1_ID );    // SINGLE_CLICK visual indicator
                        break;
                        case HWIOAB_BTN_EVENT_DOUBLE_CLICK :
                            SEGGER_RTT_printf( 0, "Button 2 action: DOUBLE_CLICK \n" );
                            HwIoAb_Pots_GetValue( HWIOAB_POTS_MAIN_CONVERTED_RESULTS );
                            SEGGER_RTT_printf( 0, "Pot 2 ADC0 resistance value in ohms: %d\n", PotsControl_Ptr->Ohms_results_main[1] );
                            HwIoAb_Leds_TurnToggle( HWIOAB_C12_LED4_ID );    // DOUBLE_CLICK visual indicator
                            HwIoAb_Leds_TurnToggle( HWIOAB_C15_LED7_ID );    // Pot 2 visual indicator
                        break;
                        case HWIOAB_BTN_EVENT_HOLD_CLICK :
                            SEGGER_RTT_printf( 0, "Button 2 action: HOLD_CLICK \n" );
                            HwIoAb_Buzzer_Beep( HWIOAB_BUZZER_TONE_2 );
                            SEGGER_RTT_printf( 0, "Buzzer playing Tone 2 at 5Khz \n" );
                        break;
                        case HWIOAB_BTN_EVENT_RELEASE :
                            SEGGER_RTT_printf( 0, "Button 2 action: RELEASE \n" );
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
                            SEGGER_RTT_printf( 0, "Button 3 action: SINGLE_CLICK \n" );
                            HwIoAb_Leds_TurnToggle( HWIOAB_LED_GREEN_ID );
                            SEGGER_RTT_printf( 0, "Green RGB LED Toggle \n" );
                            HwIoAb_Leds_TurnToggle( HWIOAB_C8_LED0_ID );    // SINGLE_CLICK visual indicator
                        break;
                        case HWIOAB_BTN_EVENT_DOUBLE_CLICK :
                            SEGGER_RTT_printf( 0, "Button 3 action: DOUBLE_CLICK \n" );
                            HwIoAb_Pots_GetAltValue( HWIOAB_POTS_ALTER_CONVERTED_RESULTS );
                            SEGGER_RTT_printf( 0, "Pot 1 ADC1 resistance value in ohms: %d\n", PotsControl_Ptr->Ohms_results_alter[0] );
                            SEGGER_RTT_printf( 0, "Pot 2 ADC1 resistance value in ohms: %d\n", PotsControl_Ptr->Ohms_results_alter[1] );
                            HwIoAb_Leds_TurnToggle( HWIOAB_C11_LED3_ID );    // DOUBLE_CLICK visual indicator
                            HwIoAb_Leds_TurnToggle( HWIOAB_C14_LED6_ID );    // Pot 1 visual indicator
                            HwIoAb_Leds_TurnToggle( HWIOAB_C15_LED7_ID );    // Pot 2 visual indicator
                        break;
                        case HWIOAB_BTN_EVENT_HOLD_CLICK :
                            SEGGER_RTT_printf( 0, "Button 3 action: HOLD_CLICK \n" );
                            HwIoAb_Buzzer_Beep( HWIOAB_BUZZER_TONE_3 );
                            SEGGER_RTT_printf( 0, "Buzzer playing Tone 3 at 7.5Khz \n" );
                        break;
                        case HWIOAB_BTN_EVENT_RELEASE :
                            SEGGER_RTT_printf( 0, "Button 3 action: RELEASE \n" );
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

void Os_LedsTask( void ){}
void Os_ButtonsTask( void ){}
void Os_PotsTask( void ){}
void Os_EepromsTask( void ){}
void Os_CanTask( void ){}
void Os_BuzzerTask( void ){}