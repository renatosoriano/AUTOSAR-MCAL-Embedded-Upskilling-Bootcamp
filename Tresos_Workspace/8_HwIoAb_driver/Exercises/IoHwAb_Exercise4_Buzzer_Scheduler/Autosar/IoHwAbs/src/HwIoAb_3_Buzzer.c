/**
 * @file HwIoAb_3_Buzzer.c
 * @brief This is basically the implementation for the functions defined in the corresponding header file. 
 * Only three interfaces will be necessary. Mandatory to declare an internal pointer for the configuration 
 * structure that will be used by the rest of the interfaces. 
 * @author Renato Soriano
*/

#include "Std_Types.h"
#include "Mcal.h"
#include "Mcu.h"
#include "OsIf.h"
#include "HwIoAb_3_Buzzer.h"

/**
 * @brief The init function shall accept the structure array with the buzzer initial configuration 
 * and configure anything necessary for the software component to work accordingly. It is not under 
 * the responsibility of the function to initialize any hardware. 
 * 
 * @param Buzzer_Config Pointer to configuration array, in this case is not used.
 * 
 * @note In this case no configurations are needeed.
 */
void HwIoAb_Buzzer_Init( const HwIoAb_Buzzer_Config *Buzzer_Config )
{

}

/**
 * @brief This function beeps the buzzer according to the tone given.
 * 
 * @param Tone Tone of interest.
 */
void HwIoAb_Buzzer_Beep( uint8 Tone ) 
{
    switch ( Tone ) 
    {
        case HWIOAB_BUZZER_TONE_1:  /* Setting frequency to 3 Khz and 50% duty cycle */
            Pwm_SetPeriodAndDuty( HWIOAB_BUZZER_CH, HWIOAB_BUZZER_PERIOD_1, HWIOAB_BUZZER_50_DUTY_CYCLE );
        break;
        case HWIOAB_BUZZER_TONE_2:  /* Setting frequency to 5 Khz and 50% duty cycle */
            Pwm_SetPeriodAndDuty( HWIOAB_BUZZER_CH, HWIOAB_BUZZER_PERIOD_2, HWIOAB_BUZZER_50_DUTY_CYCLE );
        break;
        case HWIOAB_BUZZER_TONE_3:  /* Setting frequency to 7.5 Khz and 50% duty cycle */
            Pwm_SetPeriodAndDuty( HWIOAB_BUZZER_CH, HWIOAB_BUZZER_PERIOD_3, HWIOAB_BUZZER_50_DUTY_CYCLE );
        break;
        default:    
        /* Invalid tone */
        break;
    }
}

/**
 * @brief This function stops the beep of the buzzer.
 * 
 */
void HwIoAb_Buzzer_Stop( void ) 
{
    Pwm_SetOutputToIdle( HWIOAB_BUZZER_CH );    /* Stopping buzzer */
}
