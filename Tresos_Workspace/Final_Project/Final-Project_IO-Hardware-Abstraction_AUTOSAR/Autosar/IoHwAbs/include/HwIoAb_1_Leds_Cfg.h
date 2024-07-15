/**
 * @file HwIoAb_1_Leds_Cfg.h
 * @brief This header contains the configuration macros for the IO hardware abstraction for the RGB LEDs on board.
 * @author Renato Soriano
*/

#ifndef HWIOAB_1_LEDS_CFG_H
#define HWIOAB_1_LEDS_CFG_H

#define HWIOAB_LEDS_MAX 11          /* Max number of leds to manage, only 6 needed now */

#define HWI0AB_LED_BLUE_ID  0u     /* RGB Led 1 ID */
#define HWIOAB_LED_RED_ID   1u     /* RGB Led 2 ID */
#define HWIOAB_LED_GREEN_ID 2u     /* RGB Led 3 ID */
#define HWIOAB_C8_LED0_ID   3u     /* PORTC8 Led 0 ID */
#define HWIOAB_C9_LED1_ID   4u     /* PORTC9 Led 1 ID */
#define HWIOAB_C10_LED2_ID  5u     /* PORTC10 Led 2 ID */
#define HWIOAB_C11_LED3_ID  6u     /* PORTC11 Led 3 ID */
#define HWIOAB_C12_LED4_ID  7u     /* PORTC12 Led 4 ID */
#define HWIOAB_C13_LED5_ID  8u     /* PORTC13 Led 5 ID */
#define HWIOAB_C14_LED6_ID  9u     /* PORTC14 Led 6 ID */
#define HWIOAB_C15_LED7_ID  10u    /* PORTC15 Led 7 ID */

#define HWIOAB_LEDS_0_CHANNEL DioConf_DioChannel_D0_BLUE_LED   /* Designated DIO channel where the RGB led 1 is connected */
#define HWIOAB_LEDS_1_CHANNEL DioConf_DioChannel_D15_RED_LED   /* Designated DIO channel where the RGB led 2 is connected */
#define HWIOAB_LEDS_2_CHANNEL DioConf_DioChannel_D16_GREEN_LED /* Designated DIO channel where the RGB led 3 is connected */
#define HWIOAB_LEDS_3_CHANNEL DioConf_DioChannel_C8_LED0       /* Designated DIO channel where the PORTC8 led 0 is connected */
#define HWIOAB_LEDS_4_CHANNEL DioConf_DioChannel_C9_LED1       /* Designated DIO channel where the PORTC9 led 1 is connected */
#define HWIOAB_LEDS_5_CHANNEL DioConf_DioChannel_C10_LED2      /* Designated DIO channel where the PORTC10 led 2 is connected */
#define HWIOAB_LEDS_6_CHANNEL DioConf_DioChannel_C11_LED3      /* Designated DIO channel where the PORTC11 led 3 is connected */
#define HWIOAB_LEDS_7_CHANNEL DioConf_DioChannel_C12_LED4      /* Designated DIO channel where the PORTC12 led 4 is connected */
#define HWIOAB_LEDS_8_CHANNEL DioConf_DioChannel_C13_LED5      /* Designated DIO channel where the PORTC13 led 5 is connected */
#define HWIOAB_LEDS_9_CHANNEL DioConf_DioChannel_C14_LED6      /* Designated DIO channel where the PORTC14 led 6 is connected */
#define HWIOAB_LEDS_10_CHANNEL DioConf_DioChannel_C15_LED7     /* Designated DIO channel where the PORTC15 led 7 is connected */


#endif // HWIOAB_1_LEDS_CFG_H