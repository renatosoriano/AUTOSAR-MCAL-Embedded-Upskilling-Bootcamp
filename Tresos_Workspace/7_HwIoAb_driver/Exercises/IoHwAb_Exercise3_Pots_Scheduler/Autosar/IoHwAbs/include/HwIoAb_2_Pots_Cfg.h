/**
 * @file HwIoAb_2_Pots_Cfg.h
 * @brief This header contains the configuration macros for the IO hardware abstraction for the potentiometers on board.
 * @author Renato Soriano
*/

#ifndef HWIOAB_2_POTS_CFG_H
#define HWIOAB_2_POTS_CFG_H

#define HWIOAB_POTS_MAX 2        /* Max number of pots to manage */

#define HWIOAB_POTS_TOTAL_RESISTANCE 10000  /* Total resistance in ohms of each pot */

/*
Voltage Disclaimer:
The NXP board microcontroller is VDD with 5V, but the Modular-S1 board (where the Potentiometers are located) 
assumes is 3.3V. Well, the only inconvenient will be the ADC can ONLY sample UP TO 3.3V, but it takes 5V as Upper reference.
So the ADC will never give the maximum value of 0xFFF in 12 bits or in any resolution.
2^12 = 4,096 for 5V
2^12 = 2,703 for 3.3V
*/

#define HWIOAB_MAX_ADC_VALUE_12B_RES 2703   /* Max adc value detected at 12 bits resolution */

#define HWIOAB_POTS_MAIN_RAW_RESULTS PotsControl_Ptr->Raw_results_main     /* Base address of the main raw results array for the Pots */
#define HWIOAB_POTS_ALTER_RAW_RESULTS PotsControl_Ptr->Raw_results_alter   /* Base address of the alternate raw results array for the Pots */ 

#define HWIOAB_POTS_MAIN_CONVERTED_RESULTS PotsControl_Ptr->Ohms_results_main    /* Base address of the main converted results array for the Pots */
#define HWIOAB_POTS_ALTER_CONVERTED_RESULTS PotsControl_Ptr->Ohms_results_alter  /* Base address of the alternate converted results array for the Pots */ 

#endif // HWIOAB_2_POTS_CFG_H