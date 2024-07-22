/**
 * @file HwIoAb_1_Leds_Cfg.h
 * @brief This header contains the configuration macros for the IO hardware abstraction for the RGB LEDs on board.
 * @author Renato Soriano
*/

#ifndef HWIOAB_1_LEDS_CFG_H
#define HWIOAB_1_LEDS_CFG_H

#define HWIOAB_LEDS_MAX 3        /* Max number of leds to manage */

#define HWIOAB_LED_BLUE_ID 0u      /* RGB Led 1 ID */
#define HWIOAB_LED_RED_ID 1u      /* RGB Led 2 ID */
#define HWIOAB_LED_GREEN_ID 2u      /* RGB Led 3 ID */

#define HWIOAB_LEDS_1_CHANNEL DioConf_DioChannel_D0_BLUE_LED   /* Designated DIO channel where the led 1 is connected */
#define HWIOAB_LEDS_2_CHANNEL DioConf_DioChannel_D15_RED_LED   /* Designated DIO channel where the led 2 is connected */
#define HWIOAB_LEDS_3_CHANNEL DioConf_DioChannel_D16_GREEN_LED /* Designated DIO channel where the led 3 is connected */

#endif // HWIOAB_1_LEDS_CFG_H