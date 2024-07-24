/**
 * @file HwIoAb_1_Leds.h
 * @brief This header contains the declaration of the control structures, functions and global data related to 
 * the IO hardware abstraction for the RGB LEDs on board.
 * @author Renato Soriano
*/

#ifndef HWIOAB_1_LEDS_H
#define HWIOAB_1_LEDS_H

#include "Port.h"
#include "Dio.h"

typedef enum
{
    HWIOAB_LED_ACTIVE_LOW,         /* LED is active low */
    HWIOAB_LED_ACTIVE_HIGH         /* LED is active high */
} LedActive;

/**
 * @brief Configuration structure for each LED.
 * 
 * @note Usually the instance of this struct is constant.
 * 
 */
typedef struct
{
    Dio_ChannelType Led;         /* Designated DIO channel where the LED is connected */
    uint8 Active;                /* If the LED is active low or high */
} HwIoAb_Leds_Config;

#include "HwIoAb_1_Leds_Cfg.h"

/**
 * @brief Control/Config structure for the leds on board.
 * 
 * @note Usually the instance of this struct is variable.
 */
typedef struct
{
    uint8 Leds;                                 /* Number of leds to handle */
    const HwIoAb_Leds_Config *LedsConfig_Ptr;   /* Ptr to configuration array */
    boolean Leds_init;                          /* Boolean flag that indicates if the control structure was initialized */
} HwIoAb_Leds_Ctrl;

/* External refrence to configuration structure array */
extern const HwIoAb_Leds_Config LedsCfg[HWIOAB_LEDS_MAX];  /* Configuration array */
extern HwIoAb_Leds_Ctrl LedsCtrl;                      /* Control structure instance */
extern HwIoAb_Leds_Ctrl *LedsControl_Ptr;              /* Pointer to control structure instance */

void HwIoAb_Leds_Init( const HwIoAb_Leds_Config *Leds_Config );
void HwIoAb_Leds_TurnOn( uint8 Led );
void HwIoAb_Leds_TurnOff( uint8 Led );
void HwIoAb_Leds_TurnToggle( uint8 Led );

#endif // HWIOAB_1_LEDS_H