/**
 * @file HwIoAb_1_Leds_Cfg.c
 * @brief This file contains the declaration and definition of the instances of the control and config
 * structures related to the IO hardware abstraction for the leds on board.
 * @author Renato Soriano
*/

#include "Std_Types.h"
#include "HwIoAb_1_Leds.h"

/* Configuration array */
const HwIoAb_Leds_Config LedsCfg[ HWIOAB_LEDS_MAX ] = {
    {
        .Led = HWIOAB_LEDS_0_CHANNEL,
        .Active = HWIOAB_LED_ACTIVE_LOW
    },
    {
        .Led = HWIOAB_LEDS_1_CHANNEL,
        .Active = HWIOAB_LED_ACTIVE_LOW
    },
    {
        .Led = HWIOAB_LEDS_2_CHANNEL,
        .Active = HWIOAB_LED_ACTIVE_LOW
    },
    {
        .Led = HWIOAB_LEDS_3_CHANNEL,
        .Active = HWIOAB_LED_ACTIVE_HIGH
    },
    {
        .Led = HWIOAB_LEDS_4_CHANNEL,
        .Active = HWIOAB_LED_ACTIVE_HIGH
    },
    {
        .Led = HWIOAB_LEDS_5_CHANNEL,
        .Active = HWIOAB_LED_ACTIVE_HIGH
    },
    {
        .Led = HWIOAB_LEDS_6_CHANNEL,
        .Active = HWIOAB_LED_ACTIVE_HIGH
    },
    {
        .Led = HWIOAB_LEDS_7_CHANNEL,
        .Active = HWIOAB_LED_ACTIVE_HIGH
    },
    {
        .Led = HWIOAB_LEDS_8_CHANNEL,
        .Active = HWIOAB_LED_ACTIVE_HIGH
    },
    {
        .Led = HWIOAB_LEDS_9_CHANNEL,
        .Active = HWIOAB_LED_ACTIVE_HIGH
    },
    {
        .Led = HWIOAB_LEDS_10_CHANNEL,
        .Active = HWIOAB_LED_ACTIVE_HIGH
    }
};
