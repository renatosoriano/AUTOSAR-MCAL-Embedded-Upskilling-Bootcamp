/**
 * @file HwIoAb_2_Pots.c
 * @brief This is basically the implementation for the functions defined in the corresponding header file. 
 * Only three interfaces will be necessary. Mandatory to declare an internal pointer for the configuration 
 * structure that will be used by the rest of the interfaces. 
 * @author Renato Soriano
*/

#include "Std_Types.h"
#include "Mcal.h"
#include "Mcu.h"
#include "OsIf.h"
#include "HwIoAb_2_Pots.h"

/* Global data */
HwIoAb_Pots_Ctrl PotsCtrl;                         /* Control structure instance */
HwIoAb_Pots_Ctrl *PotsControl_Ptr = &PotsCtrl;     /* Pointer to control structure instance */ 

/**
 * @brief The init function shall accept the structure array with the pots initial configuration 
 * and configure anything necessary for the software component to work accordingly. It is not under 
 * the responsibility of the function to initialize any hardware.
 * It calibrates both ADC modules and initialices the raw results arrays for the conversions. 
 * 
 * @param Pots_Config Pointer to configuration array.
 * 
 * @note Hardware interleave for pins PTB1 and PTB13 is done in EcuM_Init(). 
 */
void HwIoAb_Pots_Init( const HwIoAb_Pots_Config * Pots_Config )
{
    Adc_CalibrationStatusType Calib_Status_ADC0;
    Adc_CalibrationStatusType Calib_Status_ADC1;

    /* Calibrating ADC modules */
    Adc_Calibrate( ADC0HwUnit, &Calib_Status_ADC0 );
    Adc_Calibrate( ADC1HwUnit, &Calib_Status_ADC1 );

    /* Initializing raw results array/buffer */
    Adc_SetupResultBuffer( ADC0Group_0, HWIOAB_POTS_MAIN_RAW_RESULTS );
    Adc_SetupResultBuffer( ADC1Group_0, HWIOAB_POTS_ALTER_RAW_RESULTS );

    PotsControl_Ptr->Pots = HWIOAB_POTS_MAX;
    PotsControl_Ptr->Pots_init = TRUE;
}

/**
 * @brief This function triggers the conversion of the group 0 of the main ADC0 for the Pots on board.
 * 
 * It calculates the resistance values of each pot.
 * 
 * @param Pots Pointer to array of results in Ohms.
 * 
 * @note The group uses hardware average of 4 samples. 
 * @note The total conversion time is 117.42us
 */
void HwIoAb_Pots_GetValue( uint16 *Pots ) 
{
    /* Software trigger conversion */
    Adc_StartGroupConversion( ADC0Group_0 );
    /* Wait until the conversion is done */
    while( Adc_GetGroupStatus( ADC0Group_0 ) == ADC_BUSY );
    /* Reading group conversion values and storing them to the raw result array */
    Adc_ReadGroup( ADC0Group_0, HWIOAB_POTS_MAIN_RAW_RESULTS ); 

    /* Calculating resistance of each Pot */
    for ( uint8 i = 0; i < PotsControl_Ptr->Pots; i++ ) 
    {
        Pots[i] = HWIOAB_POTS_TOTAL_RESISTANCE * 
        ( ( float ) PotsControl_Ptr->Raw_results_main[i] / HWIOAB_MAX_ADC_VALUE_12B_RES );

        /* Locking value if needed*/
        if ( Pots[i] > HWIOAB_POTS_TOTAL_RESISTANCE ) 
        { 
            Pots[i] = HWIOAB_POTS_TOTAL_RESISTANCE;
        }
    }
}

/**
 * @brief This function triggers the conversion of the group 0 of the alternate ADC1 for the Pots on board.
 * 
 * It calculates the resistance values of each pot.
 * 
 * @param AltPots Pointer to array of results in Ohms.
 * 
 * @note The group uses hardware average of 4 samples. 
 * @note The total conversion time is 117.42us
 */
void HwIoAb_Pots_GetAltValue( uint16 *AltPots ) 
{
    /* Software trigger conversion */
    Adc_StartGroupConversion( ADC1Group_0 );
    /* Wait until the conversion is done */
    while( Adc_GetGroupStatus( ADC1Group_0 ) == ADC_BUSY );
    /* Reading group conversion values and storing them to the raw result array */
    Adc_ReadGroup( ADC1Group_0, HWIOAB_POTS_ALTER_RAW_RESULTS ); 

    /* Calculating resistance of each Pot */
    for ( uint8 i = 0; i < PotsControl_Ptr->Pots; i++ ) 
    {
        AltPots[i] = HWIOAB_POTS_TOTAL_RESISTANCE * 
        ( ( float ) PotsControl_Ptr->Raw_results_alter[i] / HWIOAB_MAX_ADC_VALUE_12B_RES );

        /* Locking value if needed*/
        if ( AltPots[i] > HWIOAB_POTS_TOTAL_RESISTANCE ) 
        { 
            AltPots[i] = HWIOAB_POTS_TOTAL_RESISTANCE;
        }
    }
}



