/**
 * @file    Scheduler.h
 * @brief   **Cooperative round robin scheduler**
 *
 * This is a very simple but yet effective cooperative round robin scheduler, it is designed to 
 * register tasks in static memory that should be provided by the application in the form of
 * Task_TypeDef variable type, also the number of task should be specied at the beginning and
 * cannot be changed in running time. It is responsibility of the user to guaranty each task
 * does not consume more than the time required that could affect the other tasks.
 * 
 * Software timers are an optional resource that can be use with the scheduler, each timer
 * shall be register previous use, and those will decrement on each tick until reaching zero,
 * after that the timer will stop and can be re-started.
 * 
 * The systick timer is used trough the HAL_SysTick functions as a means of the tick counter
 * it is not advice to modify the default configuration that runs the tick each milliseconds 
 *
 */
#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#ifdef UTEST
#define STATIC    /*!< remove static qualifier*/
#define FOREVER 0 /*!< remove infinite loop */
#else
#define STATIC  static /*!< keep static qualifier*/
#define FOREVER 1      /*!< infinite loop */
#endif

#define SCHEDULER_QUEUE_EMPTY 0x00 /*!< full flag */
#define SCHEDULER_QUEUE_FULL 0x01 /*!< empty flag */

typedef uint32 TickType; /*!< type for the tick counter */
typedef uint8 TaskType; /*!< type for the number of task */
typedef uint8 TimerType; /*!< type for the number of software timers */
typedef uint8 QueueType; /*!< type for the number of queues */

/**
  * @brief   Task Control Block definition
  * 
  * This is the structure that will define the elements need to controll a given task, the elements
  * will be set using the HIL_SCHEDULER_Register function
  */
typedef struct _Task_ConfigType 
{
    uint32 InitPeriod;        /*!< How often the task should run in ms */
    uint8 InitFlag;     /*!< flag to start task execution */
    void(*TaskFunc)(void);  /*!< pointer to task function */
} Task_ConfigType;

/**
  * @brief   Software Timer definition
  * 
  * This is the structure that will define the elements need to controll a software timer, the elements
  * will be set using the extern function HIL_SCHEDULER_RegisterTimer function
  */
typedef struct _Timer_ConfigType
{
    uint32 InitTimeout;       /*!< timer timeout to decrement and reload when the timer is re-started */
    uint8 InitFlag;     /*!< flag to start timer execution */
    void(*CallbackFunc)(void);  /*!< pointer to callback function function */
} Timer_ConfigType;

/**
  * @brief   Queue definition
  * 
  * This is the structure that will define the elements need to controll a queue, the elements
  * will be set using the extern function HIL_SCHEDULER_RegisterQueue function
  */
typedef struct _Queue_ConfigType 
{
    uint8 Size;        /*!< How often the task should run in ms */
    uint32 Elements;     /*!< flag to start task execution */
    void *Buffer;    /*!< pointer to task function */
} Queue_ConfigType;

/**
  * @brief   Scheduler Control Block
  * 
  * This is the control structure to define the number of task to run and also the base time for the
  * system tick in milliseconds 
  */
typedef struct _Scheduler_ConfigType 
{
    TickType Tick;              /*!< the time base in ms */
    TaskType Tasks;             /*!< number of task to handle */
    const Task_ConfigType  *TaskPtr;      /*!< Pointer to TCB buffer */
    TimerType Timers;            /*!< number of software timer to use */
    const Timer_ConfigType *TimerPtr;    /*!< Pointer to buffer timer array */
    QueueType Queues;           /*!< number of queues to use */
    const Queue_ConfigType *QueuePtr;    /*!< Pointer to buffer queue array */
} Scheduler_ConfigType;

#include "Scheduler_Cfg.h"


void Scheduler_Init( const Scheduler_ConfigType *SchedulerPtr );
void Scheduler_MainFunction( void );

Std_ReturnType Scheduler_StopTask( TaskType Task );
Std_ReturnType Scheduler_StartTask( TaskType Task );
Std_ReturnType Scheduler_PeriodTask( TaskType Task, uint32 NewPeriod );

uint32 Scheduler_GetTimer( TimerType Timer );
Std_ReturnType Scheduler_ReloadTimer( TimerType Timer, uint32 NewTimeout );
Std_ReturnType Scheduler_StartTimer( TimerType Timer );
Std_ReturnType Scheduler_StopTimer( TimerType Timer );

Std_ReturnType Scheduler_WriteQueue( QueueType Queue, void *Data );
Std_ReturnType Scheduler_ReadQueue( QueueType Queue, void *Data );
Std_ReturnType Scheduler_FlushQueue( QueueType Queue );
uint8 Scheduler_GetStatusQueue( QueueType Queue, uint8 Status );

#endif
