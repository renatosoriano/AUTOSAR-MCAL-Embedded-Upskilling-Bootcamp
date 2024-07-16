/**
 * @file HwIoAb_0_Buttons.c
 * @brief This is basically the implementation for the functions defined in the corresponding header file. 
 * Only three interfaces will be necessary. Mandatory to declare an internal pointer for the configuration 
 * structure that will be used by the rest of the interfaces. 
 * The use of the Scheduler timers and queues shall be avoided, instead of timer a simple variable counter 
 * can be used and the time can be calculated using the periodicity time of the main function.
 * @author Renato Soriano
*/

#include "Std_Types.h"
#include "Mcal.h"
#include "Mcu.h"
#include "OsIf.h"
#include "HwIoAb_0_Buttons.h"

/* Global data */
HwIoAb_Buttons_Ctrl ButtonsCtrl;                            /* Control structure instance */
HwIoAb_Buttons_Ctrl *ButtonsControl_Ptr = &ButtonsCtrl;     /* Pointer to control structure instance */ 

/**
 * @brief The init function shall accept the structure array with the button initial configuration 
 * and configure anything necessary for the software component to work accordingly. It is not under 
 * the responsibility of the function to initialize any hardware. 
 * 
 * @param Buttons_Config Pointer to configuration array.
 */
void HwIoAb_Buttons_Init( const HwIoAb_Buttons_Config * Buttons_Config )
{
    ButtonsControl_Ptr->Buttons = HWIOAB_BUTTONS_MAX;
    ButtonsControl_Ptr->ButtonsConfig_Ptr = Buttons_Config;

    for(uint8 i = 0; i < ButtonsControl_Ptr->Buttons; i++)   // All button states and events to IDLE.
    {
        ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_IDLE;
        ButtonsControl_Ptr->Events[i] = HWIOAB_BTN_EVENT_IDLE;
    }

    ButtonsControl_Ptr->Buttons_init = TRUE;
}

/**
 * @brief If upper layer wants to know the current event detected by the HwIoAb_Buttons_MainFunction(), 
 * the following runner shall be used in charge of returning the last event detected. The same function 
 * shall be responsible to clear the event with an IDLE such as if the function is called again, no event 
 * shall be reported until the main function detects again. No buffering mechanisms shall be added.
 * 
 * @param Button Button ID. 
 * @return event Last event detected in button.
 * 
 * @note The Button ID must be valid.
 */
uint8 HwIoAb_Buttons_GetEvent( uint8 Button )
{
    uint8 temp = 0;
    temp = ButtonsControl_Ptr->Events[Button];                      // Obtaining last event.
    ButtonsControl_Ptr->Events[Button] = HWIOAB_BTN_EVENT_IDLE;     // Clearing event of button.
    return temp;
}

/**
 * @brief This is the function that will carry out all the necessary detection and filtering for each button 
 * configured. It is basically a state machine that shall be polled every certain millisecond, the right 
 * amount of time shall be responsibility of the application and must be equal to HWIOAB_BUTTONS_PERIOD 
 * constant defined in HwIoAb_0_Buttons_Cfg.h. The software component itself is not responsible to ensure 
 * the timing period set has the right value.
 * 
 * @note This function is called every HWIOAB_BUTTONS_PERIOD.
 * @note Remember that the timeout count is for detecting a hold click when the button is pressed 1 and 2 times.
 * @note Each button has its own dedicated count.
 * 
 */
void HwIoAb_Buttons_MainFunction( void )
{
    static uint32 Counters[HWIOAB_BUTTONS_MAX] = {0, 0, 0};

    for( uint8 i = 0; i < ButtonsControl_Ptr->Buttons; i++ )    // Executing state machine for each button.
    {
        switch( ButtonsControl_Ptr->States[i] )
        {
            case HWIOAB_BTN_STATE_IDLE :
                // Query for the first time the button is pressed.
                if(Dio_ReadChannel( ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Button ) == ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Active)   // 0x0 = PRESSED
                {
                    // Start the 300ms counter if there is a press.
                    Counters[i] = 0;
                    ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_SINGLE_CLICK;

                }
            break;
            case HWIOAB_BTN_STATE_SINGLE_CLICK :
                Counters[i] += HWIOAB_BUTTONS_PERIOD;
                // Query if there is a timeout, if the elapsed time is already equal or bigger than the timeout.
                if(Counters[i] == ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Timeout)
                {
                    ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_HOLD_CLICK;
                }

                // Query if there is a release.
                if(Dio_ReadChannel( ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Button ) == !ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Active)   // 0x1 = UNPRESSED
                {
                    ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_RELEASE;
                }    
            break;
            case HWIOAB_BTN_STATE_RELEASE :
                Counters[i] += HWIOAB_BUTTONS_PERIOD;
                // Query if timeout, if timeout is a single click.
                if(Counters[i] == ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Timeout)
                {
                    ButtonsControl_Ptr->Events[i] = HWIOAB_BTN_EVENT_SINGLE_CLICK;
                    ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_IDLE;
                } 

                // Query if a press, if press start 300ms counter again.
                if(Dio_ReadChannel( ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Button ) == ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Active)   // 0x0 = PRESSED
                {
                    // Restart the 300ms counter if there is a press.
                    Counters[i] = 0;
                    ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_DOUBLE_CLICK;
                } 
            break;
            case HWIOAB_BTN_STATE_DOUBLE_CLICK :
                Counters[i] += HWIOAB_BUTTONS_PERIOD;
                // Query if timeout, if timeout is hold 
                if(Counters[i] == ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Timeout)
                {
                    ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_HOLD_CLICK;
                } 

                // Query if release, if release is a double click
                if(Dio_ReadChannel( ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Button ) == !ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Active)   // 0x1 = UNPRESSED
                {
                    ButtonsControl_Ptr->Events[i] = HWIOAB_BTN_EVENT_DOUBLE_CLICK;
                    ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_IDLE;
                } 
            break;
            case HWIOAB_BTN_STATE_HOLD_CLICK :
                ButtonsControl_Ptr->Events[i] = HWIOAB_BTN_EVENT_HOLD_CLICK;
                // If state jumps here is a hold click, wait until botton is released and go back to IDLE
                if(Dio_ReadChannel( ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Button ) == !ButtonsControl_Ptr->ButtonsConfig_Ptr[i].Active)   // 0x1 = UNPRESSED
                {
                    ButtonsControl_Ptr->Events[i] = HWIOAB_BTN_EVENT_RELEASE;
                    ButtonsControl_Ptr->States[i] = HWIOAB_BTN_STATE_IDLE;
                }
            break;
            default :
              // If jump here is an error
            break;
        }
    }
}   
