/**
 * @file HwIoAb_0_Buttons_Cfg.c
 * @brief This file contains the declaration and definition of the instances of the control and config
 * structures related to the IO hardware abstraction for the buttons on board.
 * @author Renato Soriano
*/

#include "Std_Types.h"
#include "HwIoAb_0_Buttons.h"

/* Configuration array */
const HwIoAb_Buttons_Config ButtonsCfg[HWIOAB_BUTTONS_MAX] =
{
    {
        .Button = HWIOAB_BUTTONS_1_CHANNEL,
        .Active = HWIOAB_BTN_ACTIVE_LOW,
        .Timeout = HWIOAB_BUTTONS_1_TIMEOUT
    },
    {
        .Button = HWIOAB_BUTTONS_2_CHANNEL,
        .Active = HWIOAB_BTN_ACTIVE_LOW,
        .Timeout = HWIOAB_BUTTONS_2_TIMEOUT
    },
    {
        .Button = HWIOAB_BUTTONS_3_CHANNEL,
        .Active = HWIOAB_BTN_ACTIVE_LOW,
        .Timeout = HWIOAB_BUTTONS_3_TIMEOUT
    }
};
