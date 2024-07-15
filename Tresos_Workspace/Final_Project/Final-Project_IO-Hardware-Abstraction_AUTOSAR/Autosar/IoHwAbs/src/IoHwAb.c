/**
 * @file IoHwAb.c
 * @brief This file contains the definition of the general configuration functions for the IO hardware abstractions with the module ID 0. 
 */

#include "IoHwAb.h"

/**
 * @brief This function initialices all the IO hardware abstractions.
 * 
 * @param ConfigPtr Pointer to configuration structure instance, in this case is not used.
 */
void IoHwAb_Init0( const IoHwAb0_ConfigType* ConfigPtr ) 
{
    /* Buttons init */
    HwIoAb_Buttons_Init( &ButtonsCfg );
    /* RGB Leds init */
    HwIoAb_Leds_Init( &LedsCfg );
    /* Pots init */
    HwIoAb_Pots_Init( NULL_PTR );
    /* Buzzer init */
    HwIoAb_Buzzer_Init( NULL_PTR );
}
