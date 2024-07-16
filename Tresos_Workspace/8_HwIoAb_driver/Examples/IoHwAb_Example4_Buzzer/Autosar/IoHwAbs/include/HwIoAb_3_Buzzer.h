/**
 * @file HwIoAb_3_Buzzer.h
 * @brief This header contains the declaration of the control structures, functions and global data related to 
 * the IO hardware abstraction for the buzzer on board.
 * @author Renato Soriano
*/

#ifndef HWIOAB_3_BUZZER_H
#define HWIOAB_3_BUZZER_H

#include "Port.h"
#include "Dio.h"
#include "Pwm.h"

typedef enum {
    HWIOAB_BUZZER_TONE_1,   /* Tone 1 for buzzer */
    HWIOAB_BUZZER_TONE_2,   /* Tone 2 for buzzer */
    HWIOAB_BUZZER_TONE_3    /* Tone 3 for buzzer */
} BuzzerTones;

/**
 * @brief Configuration structure for the buzzer.
 * 
 * @note Usually the instance of this struct is constant.
 */
typedef struct _HwIoAb_Buzzer_Config 
{
    uint8 dummy;
} HwIoAb_Buzzer_Config;

#include "HwIoAb_3_Buzzer_Cfg.h"

void HwIoAb_Buzzer_Init( const HwIoAb_Buzzer_Config *Buzzer_Config );
void HwIoAb_Buzzer_Beep( uint8 Tone );
void HwIoAb_Buzzer_Stop( void );

#endif // HWIOAB_3_BUZZER_H