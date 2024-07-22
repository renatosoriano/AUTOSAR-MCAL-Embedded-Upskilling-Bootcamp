/**
 * @file HwIoAb_0_Buttons.h
 * @brief This header contains the configuration macros for the IO hardware abstraction for the buttons on board.
 * @author Renato Soriano
*/

#ifndef HWIOAB_0_BUTTONS_CFG_H
#define HWIOAB_0_BUTTONS_CFG_H

#define HWIOAB_BUTTONS_MAX 3        /* Max number of buttons to manage */

#define HWIOAB_BUTTONS_PERIOD 50    /* Periodicity for the main function in milliseconds */

#define HWIOAB_BUTTONS_1_ID 0u      /* Button 1 ID */
#define HWIOAB_BUTTONS_2_ID 1u      /* Button 2 ID */
#define HWIOAB_BUTTONS_3_ID 2u      /* Button 3 ID */

#define HWIOAB_BUTTONS_1_TIMEOUT 300    /* Timeout for the button 1 press in ms */
#define HWIOAB_BUTTONS_2_TIMEOUT 300    /* Timeout for the button 2 press in ms */
#define HWIOAB_BUTTONS_3_TIMEOUT 300    /* Timeout for the button 3 press in ms */

#define HWIOAB_BUTTONS_1_CHANNEL DioConf_DioChannel_E12_SW1_BTN   /* Designated DIO channel where the button 1 is connected */
#define HWIOAB_BUTTONS_2_CHANNEL DioConf_DioChannel_D17_SW2_BTN   /* Designated DIO channel where the button 2 is connected */
#define HWIOAB_BUTTONS_3_CHANNEL DioConf_DioChannel_A12_SW3_BTN   /* Designated DIO channel where the button 3 is connected */

#endif // HWIOAB_0_BUTTONS_CFG_H