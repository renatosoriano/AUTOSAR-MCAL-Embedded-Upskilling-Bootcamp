#ifndef SCHEDULER_CFG_H_
#define SCHEDULER_CFG_H_

typedef struct _AppMsg
{
    uint8 Msg;
    uint8 Button;
} AppMsg;

#define SCHEDULER_TICK 10

#define SCHEDULER_MAX_TASKS     6
#define SCHEDULER_MAX_TIMERS    1
#define SCHEDULER_MAX_QUEUES    1

#define SCHEDULER_LEDS_TASK         0
#define SCHEDULER_BUTTONS_TASK      1
#define SCHEDULER_POTS_TASK         2
#define SCHEDULER_EEPROMS_TASK      3
#define SCHEDULER_CAN_TASK          4
#define SCHEDULER_BUZZER_TASK       5

#define SCHEDULER_LEDS_TASK_PERIOD      300
#define SCHEDULER_BUTTONS_TASK_PERIOD   50
#define SCHEDULER_POTS_TASK_PERIOD      1000
#define SCHEDULER_EEPROMS_TASK_PERIOD   3000
#define SCHEDULER_CAN_TASK_PERIOD       5000
#define SCHEDULER_BUZZER_TASK_PERIOD    3000

#define SCHEDULER_BUTTON1_TIMER       0

#define SCHEDULER_BUTTON1_TIMER_PERIOD 300

#define SCHEDULER_BUTTONS_QUEUE      sizeof( AppMsg )

#define SCHEDULER_BUTTONS_ELEMENTS   10

extern const Scheduler_ConfigType Scheduler_Config;

#endif
