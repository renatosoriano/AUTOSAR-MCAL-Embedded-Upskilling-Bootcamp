/**
 * @file HwIoAb_1_Leds.c
 * @brief This is basically the implementation for the functions defined in the corresponding header file. 
 * Only three interfaces will be necessary. Mandatory to declare an internal pointer for the configuration 
 * structure that will be used by the rest of the interfaces. 
 * @author Renato Soriano
*/

#include "Std_Types.h"
#include "Mcal.h"
#include "Mcu.h"
#include "OsIf.h"
#include "HwIoAb_1_Leds.h"

/* Global data */
HwIoAb_Leds_Ctrl LedsCtrl;                         /* Control structure instance */
HwIoAb_Leds_Ctrl *LedsControl_Ptr = &LedsCtrl;     /* Pointer to control structure instance */ 

/**
 * @brief The init function shall accept the structure array with the leds initial configuration 
 * and configure anything necessary for the software component to work accordingly. It is not under 
 * the responsibility of the function to initialize any hardware. 
 * 
 * @param Leds_Config Pointer to configuration array.
 */
void HwIoAb_Leds_Init( const HwIoAb_Leds_Config * Leds_Config )
{
    LedsControl_Ptr->Leds = HWIOAB_LEDS_MAX;
    LedsControl_Ptr->LedsConfig_Ptr = Leds_Config;
    LedsControl_Ptr->Leds_init = TRUE;
}

/**
 * @brief This function turns on a given led.
 * 
 * @param Led Led ID.
 * 
 * @note The led ID must be valid.
 */
void HwIoAb_Leds_TurnOn( uint8 Led ) 
{
    Dio_WriteChannel( LedsControl_Ptr->LedsConfig_Ptr[ Led ].Led, LedsControl_Ptr->LedsConfig_Ptr[ Led ].Active );
    
}

/**
 * @brief This function turns off a given led.
 * 
 * @param Led Led ID.
 * 
 * @note The led ID must be valid.
 */
void HwIoAb_Leds_TurnOff( uint8 Led ) 
{
    Dio_WriteChannel( LedsControl_Ptr->LedsConfig_Ptr[ Led ].Led, !LedsControl_Ptr->LedsConfig_Ptr[ Led ].Active );
}

/**
 * @brief This function toggles a given led.
 * 
 * @param Led Led ID.
 * 
 * @note The led ID must be valid.
 */
void HwIoAb_Leds_TurnToggle( uint8 Led ) 
{
    Dio_FlipChannel( LedsControl_Ptr->LedsConfig_Ptr[ Led ].Led );
}
