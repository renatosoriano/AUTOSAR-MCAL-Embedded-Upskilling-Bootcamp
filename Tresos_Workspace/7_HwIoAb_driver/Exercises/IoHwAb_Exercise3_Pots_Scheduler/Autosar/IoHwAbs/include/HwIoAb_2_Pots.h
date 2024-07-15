/**
 * @file HwIoAb_2_Pots.h
 * @brief This header contains the declaration of the control structures, functions and global data related to 
 * the IO hardware abstraction for the potentiometers on board.
 * @author Renato Soriano
*/

#ifndef HWIOAB_2_POTS_H
#define HWIOAB_2_POTS_H

#include "Port.h"
#include "Dio.h"
#include "Adc.h"

/**
 * @brief Configuration structure for each pot.
 * 
 * @note Usually the instance of this struct is constant.
 */
typedef struct
{
    uint8 dummy;
} HwIoAb_Pots_Config;

#include "HwIoAb_2_Pots_Cfg.h"

/**
 * @brief Control/Config structure for the pots on board.
 * 
 * @note Usually the instance of this struct is variable.
 * @note Each element of the arrays is the conversion result of a pot.
 * @note Element n is pot n.
 * @note In this case we have only 2 ADC groups, one for ADC0 and the other for ADC1.
 * @note All pots have the same total resistance value.
 */
typedef struct  
{
    uint8 Pots;                                     /* Number of pots to handle */
    Adc_ValueGroupType Raw_results_main[ HWIOAB_POTS_MAX ];     /* Raw conversion results array for the main ADC0 */
    Adc_ValueGroupType Raw_results_alter[ HWIOAB_POTS_MAX ];    /* Raw conversion results array for the alternate ADC1 */
    Adc_ValueGroupType Ohms_results_main[ HWIOAB_POTS_MAX ];    /* Ohms conversion results array for the main ADC0 */
    Adc_ValueGroupType Ohms_results_alter[ HWIOAB_POTS_MAX ];   /* Ohms conversion results array for the alternate ADC1 */
    boolean Pots_init;                              /* Boolean flag that indicates if the control structure was initialized */
} HwIoAb_Pots_Ctrl;

/* External refrence to configuration structure array */
extern HwIoAb_Pots_Ctrl PotsCtrl;
extern HwIoAb_Pots_Ctrl *PotsControl_Ptr;

void HwIoAb_Pots_Init( const HwIoAb_Pots_Config *Pots_Config );
void HwIoAb_Pots_GetValue( uint16 *Pots );
void HwIoAb_Pots_GetAltValue( uint16 *AltPots );

#endif // HWIOAB_2_POTS_H