/**
 * @file HwIoAb_0_Buttons.h
 * @brief This header contains the declaration of the control structures, functions and global data related to 
 * the IO hardware abstraction for the buttons on board.
 * @author Renato Soriano
*/

#ifndef HWIOAB_0_BUTTONS_H
#define HWIOAB_0_BUTTONS_H

#include "Port.h"
#include "Dio.h"

typedef enum
{
    HWIOAB_BTN_STATE_IDLE,         /* None activation has happened yet */
    HWIOAB_BTN_STATE_SINGLE_CLICK, /* Single click */
    HWIOAB_BTN_STATE_DOUBLE_CLICK, /* Double click */
    HWIOAB_BTN_STATE_HOLD_CLICK,   /* Hold click */
    HWIOAB_BTN_STATE_RELEASE       /* Release */
} ButtonState;

typedef enum
{
    HWIOAB_BTN_EVENT_IDLE,         /* None activation has happened yet */
    HWIOAB_BTN_EVENT_SINGLE_CLICK, /* Single click */
    HWIOAB_BTN_EVENT_DOUBLE_CLICK, /* Double click */
    HWIOAB_BTN_EVENT_HOLD_CLICK,   /* Hold click */
    HWIOAB_BTN_EVENT_RELEASE       /* Release */
} ButtonEvent;

typedef enum
{
    HWIOAB_BTN_ACTIVE_LOW,         /* Button is active low */
    HWIOAB_BTN_ACTIVE_HIGH         /* Button is active high */
} ButtonActive;

/**
 * @brief Configuration structure for each button.
 * 
 * @note Usually the instance of this struct is constant.
 */
typedef struct
{
    Dio_ChannelType Button;         /* Designated DIO channel where the button is connected */
    uint8 Active;                   /* If the button is active low or high */
    uint32 Timeout;                 /* Timeout for the button press in ms */
} HwIoAb_Buttons_Config;

#include "HwIoAb_0_Buttons_Cfg.h"

/**
 * @brief Control/Config structure for the double click state machine for the buttons on board.
 * 
 * @note Usually the instance of this struct is variable.
 */
typedef struct
{
    uint8 Buttons;                                  /* Number of buttons to handle */
    const HwIoAb_Buttons_Config *ButtonsConfig_Ptr; /* Ptr to configuration array */
    uint8 States[ HWIOAB_BUTTONS_MAX ];             /* Actual state of each button */
    uint8 Events[ HWIOAB_BUTTONS_MAX ];             /* Actual event of each button */
    boolean Buttons_init;                           /* Boolean flag that indicates if the control structure was initialized */
} HwIoAb_Buttons_Ctrl;

/* External refrence to configuration structure array */
extern const HwIoAb_Buttons_Config ButtonsCfg[HWIOAB_BUTTONS_MAX];  /* Configuration array */
extern HwIoAb_Buttons_Ctrl ButtonsCtrl;                             /* Control structure instance */
extern HwIoAb_Buttons_Ctrl *ButtonsControl_Ptr;                     /* Pointer to control structure instance */

void HwIoAb_Buttons_Init( const HwIoAb_Buttons_Config *Buttons_Config );
uint8 HwIoAb_Buttons_GetEvent( uint8 Button );
void HwIoAb_Buttons_MainFunction( void );

#endif // HWIOAB_0_BUTTONS_H