/**
 * @file IoHwAb.h
 * @brief This header contains the declaration of general config structures and functions 
 * for the I/O hardware abstractions with the module ID 0.
 * @author Renato Soriano
*/

#ifndef IOHWAB_H
#define IOHWAB_H

#include "HwIoAb_0_Buttons.h"
#include "HwIoAb_1_Leds.h"
//#include "HwIoAb_2_Pots.h"
//#include "HwIoAb_3_Buzzer.h"

/**
 * @brief This is the configuration structure of the I/O hardware abstractions with the module ID 0.
 * 
 * @note In this case is not used, every hardware io abstraction has its own config structure.
 */
typedef struct 
{
    uint8 dummy;
} IoHwAb0_ConfigType;

void IoHwAb_Init0( const IoHwAb0_ConfigType* ConfigPtr );

#endif // IOHWAB_H