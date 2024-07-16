#include "Std_Types.h"
#include "Scheduler.h"

//extern void Os_LedsTask( void );
//extern void Os_ButtonsTask( void );
//extern void Os_PotsTask( void );
//extern void Os_EepromsTask( void );
//extern void Os_CanTask( void );
//extern void Os_BuzzerTask( void );

void Os_LedsTask( void );
void Os_ButtonsTask( void );
void Os_PotsTask( void );
void Os_EepromsTask( void );
void Os_CanTask( void );
void Os_BuzzerTask( void );

extern void Os_50ms_Task( void );
extern void Os_100ms_Task( void );

const Task_ConfigType Task_Config[ SCHEDULER_MAX_TASKS ] = 
{
    {
        //.InitPeriod = SCHEDULER_LEDS_TASK_PERIOD,
        .InitPeriod = SCHEDULER_TASK1_PERIOD_50MS,
        .InitFlag = TRUE,
        //.TaskFunc = Os_LedsTask
        .TaskFunc = Os_50ms_Task
    },
    {
        //.InitPeriod = SCHEDULER_BUTTONS_TASK_PERIOD,
        .InitPeriod = SCHEDULER_TASK2_PERIOD_100MS,
        .InitFlag = TRUE,
        //.TaskFunc = Os_ButtonsTask
        .TaskFunc = Os_100ms_Task
    },
    {
        .InitPeriod = SCHEDULER_POTS_TASK_PERIOD,
        .InitFlag = FALSE,
        .TaskFunc = Os_PotsTask
    },
    {
        .InitPeriod = SCHEDULER_EEPROMS_TASK_PERIOD,
        .InitFlag = FALSE,
        .TaskFunc = Os_EepromsTask
    },
    {
        .InitPeriod = SCHEDULER_CAN_TASK_PERIOD,
        .InitFlag = FALSE,
        .TaskFunc = Os_CanTask
    },
    {
        .InitPeriod = SCHEDULER_BUZZER_TASK_PERIOD,
        .InitFlag = FALSE,
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
