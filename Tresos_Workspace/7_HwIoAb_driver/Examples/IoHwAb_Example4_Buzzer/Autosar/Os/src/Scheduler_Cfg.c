#include "Std_Types.h"
#include "Scheduler.h"


extern void Os_LedsTask( void );
extern void Os_ButtonsTask( void );
extern void Os_PotsTask( void );
extern void Os_EepromsTask( void );
extern void Os_CanTask( void );
extern void Os_BuzzerTask( void );

const Task_ConfigType Task_Config[ SCHEDULER_MAX_TASKS ] = 
{
    {
        .InitPeriod = SCHEDULER_LEDS_TASK_PERIOD,
        .InitFlag = TRUE,
        .TaskFunc = Os_LedsTask
    },
    {
        .InitPeriod = SCHEDULER_BUTTONS_TASK_PERIOD,
        .InitFlag = FALSE,
        .TaskFunc = Os_ButtonsTask
    },
    {
        .InitPeriod = SCHEDULER_POTS_TASK_PERIOD,
        .InitFlag = FALSE,
        .TaskFunc = Os_PotsTask
    },
    {
        .InitPeriod = SCHEDULER_EEPROMS_TASK_PERIOD,
        .InitFlag = TRUE,
        .TaskFunc = Os_EepromsTask
    },
    {
        .InitPeriod = SCHEDULER_CAN_TASK_PERIOD,
        .InitFlag = FALSE,
        .TaskFunc = Os_CanTask
    },
    {
        .InitPeriod = SCHEDULER_BUZZER_TASK_PERIOD,
        .InitFlag = TRUE,
        .TaskFunc = Os_BuzzerTask
    }
};

const Timer_ConfigType Timer_Config[ SCHEDULER_MAX_TIMERS ] = 
{
    {
        .InitTimeout = SCHEDULER_BUTTON1_TIMER,
        .InitFlag = FALSE,
        .CallbackFunc = NULL
    }
};

const Queue_ConfigType Queue_Config[ SCHEDULER_MAX_QUEUES ] = 
{
    {
        .Size = SCHEDULER_BUTTONS_QUEUE,
        .Elements = SCHEDULER_BUTTONS_ELEMENTS,
        .Buffer = NULL
    }
};

const Scheduler_ConfigType Scheduler_Config = 
{
    .Tick = SCHEDULER_TICK,
    .Tasks = SCHEDULER_MAX_TASKS,
    .TaskPtr = Task_Config,
    .Timers = SCHEDULER_MAX_TIMERS,
    .TimerPtr = Timer_Config,
    .Queues = SCHEDULER_MAX_QUEUES,
    .QueuePtr = Queue_Config
};
