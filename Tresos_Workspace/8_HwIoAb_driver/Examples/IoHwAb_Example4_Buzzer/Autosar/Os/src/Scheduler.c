/**
 * @file    Scheduler.c
 * @brief   **Cooperative round robin scheduler**
 *
 * This is a very simple but yet effective cooperative round robin scheduler, it is designed to
 * register tasks in static memory that should be provided by the application in the form of
 * Task_ConfigType variable type, also the number of task should be specied at the beginning and
 * cannot be changed in running time. It is responsibility of the user to guaranty each task
 * does not consume more than the time required that could affect the other tasks.
 *
 * Software timers are an optional resource that can be use with the schedulerm, each timer
 * shall be register previous use, and those will decrement on each tick until reaching zero,
 * after that the timer will stop and can be re-started.
 *
 * The systick timer is used trough the OsIf functions as a means of the tick counter
 * it is not advice to modify the default configuration that runs the tick each milliseconds
 *
 */
#include "Std_Types.h"
#include "Scheduler.h"
#include "OsIf.h"
#include "Bfx.h"

#if SCHEDULER_MAX_TIMERS == 0
    #define SCHEDULER_MAX_TIMERS 1
#endif

#if SCHEDULER_MAX_QUEUES == 0
    #define SCHEDULER_MAX_QUEUES 1
#endif

typedef struct _SchedulerCtrl
{
    uint32 TaskElapsed[ SCHEDULER_MAX_TASKS ];
    uint32 TaskPeriod[ SCHEDULER_MAX_TASKS ];
    uint32 TimerCount[ SCHEDULER_MAX_TIMERS ];
    uint32 TimerTimeout[ SCHEDULER_MAX_TIMERS ];
    uint32 QueueHeads[ SCHEDULER_MAX_QUEUES ];
    uint32 QueueTails[ SCHEDULER_MAX_QUEUES ];
    uint32 TaskFlags;
    uint32 TimerFlags;
    uint32 QueueEmpties;
    uint32 QueueFulls;
} SchedulerCtrl;

static const Scheduler_ConfigType *SchedulerLocal = NULL_PTR;
static SchedulerCtrl SchedulerControl;

STATIC void Tasks_Dispatch( void );
STATIC void Timers_Dispatch( void );
STATIC void MemCopy( void *Dest, void *Src, uint32 Size );

/**
 * @brief   **Initialization Scheduler Function**
 *
 * The function will set-up the main scheduler characteristics like the number of task to run,
 * the tick base time and the static memory to allocate the task control blocks, it is mandatory
 * to call this function before any other in this driver, the user is responsible to pass the right
 * value for the arguments.
 *
 * @param   scheduler  Scheduler control structure
 */
void Scheduler_Init( const Scheduler_ConfigType *SchedulerPtr )
{
    SchedulerControl.TaskFlags = 0u;
    SchedulerControl.TimerFlags = 0u;
    
    for( uint8 i = 0u; i < SchedulerPtr->Tasks; i++ )
    {
        SchedulerControl.TaskElapsed[ i ] = 0u;
        SchedulerControl.TaskPeriod[ i ] = SchedulerPtr->TaskPtr[ i ].InitPeriod;
        Bfx_PutBit_u32u8u8( &SchedulerControl.TaskFlags, i, SchedulerPtr->TaskPtr[ i ].InitFlag );
    }

    for( uint8 i = 0u; i < SchedulerPtr->Timers; i++ )
    {
        SchedulerControl.TimerCount[ i ] = 0u;
        SchedulerControl.TimerTimeout[ i ] = SchedulerPtr->TimerPtr[ i ].InitTimeout;
        Bfx_PutBit_u32u8u8( &SchedulerControl.TimerFlags, i, SchedulerPtr->TimerPtr[ i ].InitFlag );
    }

    for( uint8 i = 0u; i < SchedulerPtr->Queues; i++ )
    {
        SchedulerControl.QueueHeads[ i ] = 0u;
        SchedulerControl.QueueTails[ i ] = 0u;
        Bfx_SetBit_u32u8( &SchedulerControl.QueueEmpties, i );
        Bfx_ClrBit_u32u8( &SchedulerControl.QueueFulls, i );
    }
    
    SchedulerLocal = SchedulerPtr;
}

/**
 * @brief   **Scheduler Periodic Function**
 *
 * The main scheduler function, it is in charge of running the initialization functions just one time
 * before the tasks. After this step the function will loop through the tasks to run previously asking
 * if it is time to run accordingly to the period registered on each of them. The function won't return
 * by any means since it is looping inside a __while(1u)__ forever. The algorithm is pretty simple since
 * first task to dispatch will be the first registered in the **Scheduler_ConfigType** array
 */
void Scheduler_MainFunction( void )
{
    uint32 Timeout = OsIf_MicrosToTicks( ( SchedulerLocal->Tick * 1000 ), OSIF_COUNTER_SYSTEM );
    /*get the Systic Timer count for the first time*/
    uint32 SeedTick = OsIf_GetCounter( OSIF_COUNTER_SYSTEM );
    /*We need to count the elapsed time from zero*/
    uint32 ElapsedTime = 0u;
    
    do /* cppcheck-suppress misra-c2012-14.4 ; this is an infinite loop */
    {
        /* get the elapsed time count from the seed tick value*/
        ElapsedTime += OsIf_GetElapsed( &SeedTick, OSIF_COUNTER_SYSTEM );
        /*query if the elapsed time is already equal or bigger than the timeout*/
        if( ElapsedTime >= Timeout )
        {
            /*reset the elapsed time */
            ElapsedTime = 0u;
            /*Scan all registered timers*/
            Timers_Dispatch( );
            /*Scan all registered task*/
            Tasks_Dispatch( );
        }
    } while( FOREVER );
}



/**
 * @brief   **Stop Task**
 *
 * This is the function that will allow to register a task to stop from running within the scheduler.
 * the function only set the __StartFlag__ to __FALSE__ which is used internally by the scheduler to
 * decided if a task runs or not
 *
 * @param   task        The task ID, it shall be number from 1 to n task registered
 *
 * @return  A E_OK is returned if the task was stop was registered otherwise it will return a
 * E_NOT_OK
 *
 * @note the Scheduler shall be initialized prior to call this function
 */
Std_ReturnType Scheduler_StopTask( TaskType Task )
{
    Std_ReturnType Error = E_NOT_OK;

    if( Task < SchedulerLocal->Tasks )
    {
        Bfx_ClrBit_u32u8( &SchedulerControl.TaskFlags, Task );
        Error = E_OK;
    }
    return Error;
}

/**
 * @brief   **Start Tasks**
 *
 * This is the function that will allow to register a task to run after been stop from running within
 * the scheduler. the function only set the __StartFlag__ to __TRUE__ which is used internally by the
 * scheduler to decided if a task runs or not. By default the flag is set when a task is been registered
 * succsefully.
 *
 * @return  A E_OK is returned if the task was stop was registered otherwise it will return a
 * E_NOT_OK
 *
 * @note the Scheduler shall be initialized prior to call this function
 */
Std_ReturnType Scheduler_StartTask( TaskType Task )
{
    Std_ReturnType Error = E_NOT_OK;

    if( Task < SchedulerLocal->Tasks )
    {
        Bfx_SetBit_u32u8( &SchedulerControl.TaskFlags, Task );
        Error = E_OK;
    }
    return Error;
}

/**
 * @brief   **Update task period**
 *
 * This is the function that will allow to register a task to change its periodicity from the one
 * that was set before. The function only set the __period__ and __elapsed__ with the new period.
 *
 * @param   Task        The task ID, it shall be number from 1 to n task registered
 * @param   Period      New period time in milliseconds
 *
 * @return  A E_OK is returned if the task was stop was registered otherwise it will return a
 * E_NOT_OK
 *
 * @note the Scheduler shall be initialized prior to call this function
 */
Std_ReturnType Scheduler_PeriodTask( TaskType Task, uint32 NewPeriod )
{
    Std_ReturnType Error = E_NOT_OK;

    if( Task <= SchedulerLocal->Tasks )
    {
        SchedulerControl.TaskPeriod[ Task ]  = NewPeriod;
        SchedulerControl.TaskElapsed[ Task ] = NewPeriod;
        Error = E_OK;
    }
    return Error;
}


/**
 * @brief   **Get the current timer time**
 *
 * The function will return the current decremented time in milisecond for the asked timer, if no
 * valid timer is requested a value of zero will be returned.
 *
 * @param   Timer     The timer to get its current time a number from 0 to SCHEDULER_HandleTypeDef.timers
 *
 * @return A value betwen zero and the timeout registered for the requested timer
 */
uint32 Scheduler_GetTimer( TimerType Timer )
{
    uint32 Time = 0u;

    if( Timer < SchedulerLocal->Timers )
    {
        Time = SchedulerControl.TimerCount[ Timer ];
    }

    return Time;
}

/**
 * @brief   **Set a new timer timeout value**
 *
 * The function will set a new timeout for an already registered timer, if no valid timer or a valid
 * timeout is set the function wont take any effect, also this function wont stop the timer count
 * neither start the count.
 *
 * @param   timeout     The new timer timeout value to decrement
 * 
 * @retval  E_OK if the timer was reloaded otherwise E_NOT_OK
 */
Std_ReturnType Scheduler_ReloadTimer( TimerType Timer, uint32 NewTimeout )
{
    Std_ReturnType Error = E_NOT_OK;

    if( Timer < SchedulerLocal->Timers )
    {
        SchedulerControl.TimerTimeout[ Timer ] = NewTimeout;
        /*reload current count if timer is active*/
        if( Bfx_GetBit_u32u8_u8( SchedulerControl.TimerFlags, Timer ) == TRUE )
        {
            SchedulerControl.TimerCount[ Timer ] = SchedulerControl.TimerTimeout[ Timer ];
        }
        Error = E_OK;
    }
    return Error;
}

/**
 * @brief   **Start decrementing the timer count**
 *
 * The function will start the timer decrement count on each tick only if the timer is registered,
 * This is the only mechanism to start a timer, when a timer reach its count to zero the timer will
 * stop nad only this function can re-start the count again.
 *
 * @param   Timer     The timer to start, any number from 0 to SCHEDULER_HandleTypeDef.timers
 * 
 * @retval  E_OK if the timer was started otherwise E_NOT_OK
 */
Std_ReturnType Scheduler_StartTimer( TimerType Timer )
{
    Std_ReturnType Error = E_NOT_OK;

    if( Timer < SchedulerLocal->Timers )
    {
        SchedulerControl.TimerCount[ Timer ] = SchedulerControl.TimerTimeout[ Timer ];
        Bfx_SetBit_u32u8( &SchedulerControl.TimerFlags, Timer );
        Error = E_OK;
    }
    return Error;
}

/**
 * @brief   **Stop decrementing the timer count**
 *
 * The function will stop the timer decrement count on each tick only if the timer is registered,
 * This is the only mechanism to stop a timer. The function only set the flag TimerFlags to FALSE.
 *
 * @param   Timer     The timer to start, any number from 0 to SchedulerLocal->Timers
 *
 * @return  A E_OK is returned if the stoped timer was registered otherwise it will return a
 * E_NOT_OK
 */
Std_ReturnType Scheduler_StopTimer( TimerType Timer )
{
    Std_ReturnType Error = E_NOT_OK;
    
    if( Timer < SchedulerLocal->Timers )
    {
        Bfx_ClrBit_u32u8( &SchedulerControl.TimerFlags, Timer );
        Error = E_OK;
    }
    return Error;
}

/**
 * @brief   **Write one siongle data into the queue**
 * 
 * The function will write a single data into the queue, if the queue is full the function will return
 * a E_NOT_OK, otherwise the data will be copied into the queue and the queue head will be incremented
 * to the next position.
 * 
 * @param   Queue   The queue to write the data, any number from 0 to SchedulerLocal->Queues
 * @param   Data    The data to write into the queue
 * 
 * @return A E_OK is returned if the data was written otherwise it will return a E_NOT_OK
 */
Std_ReturnType Scheduler_WriteQueue( QueueType Queue, void *Data )
{
    Std_ReturnType Error = E_NOT_OK;

    if( Bfx_GetBit_u32u8_u8( SchedulerControl.QueueFulls, Queue ) )
    {
        
        uint8 Offset = SchedulerControl.QueueHeads[ Queue ] * SchedulerLocal->QueuePtr[ Queue ].Size;
        /* cppcheck-suppress misra-c2012-11.5 ; convertion is neccesary to supress compiler warning */
        MemCopy( &( (uint8 *)SchedulerLocal->QueuePtr[ Queue ].Buffer )[ Offset ], Data, SchedulerLocal->QueuePtr[ Queue ].Size );
        /*clear the queue flag empty*/
        Bfx_ClrBit_u32u8( &SchedulerControl.QueueEmpties, Queue );
        /*increment the queue head*/
        SchedulerControl.QueueHeads[ Queue ]++;
        SchedulerControl.QueueHeads[ Queue ] %= SchedulerLocal->QueuePtr[ Queue ].Elements;
        
        if( SchedulerControl.QueueHeads[ Queue ] == SchedulerControl.QueueTails[ Queue ] )
        {
            /*Set queue FULL*/
            Bfx_SetBit_u32u8( &SchedulerControl.QueueFulls, Queue );
        }

        Error = E_OK;
    }

    return Error; 
}

/**
 * @brief   **Read one siongle data from the queue**
 * 
 * The function will read a single data from the queue, if the queue is empty the function will return
 * a E_NOT_OK, otherwise the data will be copied from the queue and the queue tail will be incremented
 * to the next position.
 * 
 * @param   Queue   The queue to read the data, any number from 0 to SchedulerLocal->Queues
 * @param   Data    The data to read from the queue
 * 
 * @return A E_OK is returned if the data was read otherwise it will return a E_NOT_OK
*/
Std_ReturnType Scheduler_ReadQueue( QueueType Queue, void *Data )
{
    Std_ReturnType Error = E_NOT_OK;

    if( Bfx_GetBit_u32u8_u8( SchedulerControl.QueueEmpties, Queue ) )
    {
        uint8 Offset = SchedulerControl.QueueTails[ Queue ] * SchedulerLocal->QueuePtr[ Queue ].Size;
        /* cppcheck-suppress misra-c2012-11.5 ; convertion is neccesary to supress compiler warning */
        MemCopy( Data, &( (uint8 *)SchedulerLocal->QueuePtr[ Queue ].Buffer )[ Offset ], SchedulerLocal->QueuePtr[ Queue ].Size );
        /*clear the queue flag empty*/
        Bfx_ClrBit_u32u8( &SchedulerControl.QueueFulls, Queue );
        /*increment the queue head*/
        SchedulerControl.QueueTails[ Queue ]++;
        SchedulerControl.QueueTails[ Queue ] %= SchedulerLocal->QueuePtr[ Queue ].Elements;
        
        if( SchedulerControl.QueueTails[ Queue ] == SchedulerControl.QueueHeads[ Queue ] )
        {
            /*Set queue FULL*/
            Bfx_SetBit_u32u8( &SchedulerControl.QueueEmpties, Queue );
        }

        Error = E_OK;
    }

    return Error; 
}

Std_ReturnType Scheduler_FlushQueue( QueueType Queue )
{
    Std_ReturnType Error = E_NOT_OK;

    if( Bfx_GetBit_u32u8_u8( SchedulerControl.QueueFulls, Queue ) )
    {
        SchedulerControl.QueueHeads[ Queue ] = 0u;
        SchedulerControl.QueueTails[ Queue ] = 0u;
        Bfx_SetBit_u32u8( &SchedulerControl.QueueEmpties, Queue );
        Bfx_ClrBit_u32u8( &SchedulerControl.QueueFulls, Queue );
        Error = E_OK;
    }

    return Error; 
}

/**
 * @brief   **Get the status of the queue**
 * 
 * The function will return the status of the queue, if the queue is empty the function will return
 * a SCHEDULER_QUEUE_EMPTY, if the queue is full the function will return a SCHEDULER_QUEUE_FULL.
 * 
 * @param   Queue   The queue to read the data, any number from 0 to SchedulerLocal->Queues
 * @param   Status  The status to get, it could be SCHEDULER_QUEUE_EMPTY or SCHEDULER_QUEUE_FULL
 * 
 * @return a TRUE is returned if the queue is empty or full otherwise it will return a
 *          FALSE
*/
uint8 Scheduler_GetStatusQueue( QueueType Queue, uint8 Status )
{
    uint8 Result = 0u;

    if( Status == SCHEDULER_QUEUE_EMPTY )
    {
        Result = Bfx_GetBit_u32u8_u8( SchedulerControl.QueueEmpties, Queue );
    }
    else if( Status == SCHEDULER_QUEUE_FULL )
    {
        Result = Bfx_GetBit_u32u8_u8( SchedulerControl.QueueFulls, Queue );
    }

    return Result;
}

/**
 * @brief   **Stop decrementing the timer count**
 *
 * The function will stop the timer decrement count on each tick only if the timer is registered,
 * This is the only mechanism to stop a timer. The function only set the flag startFlag to FALSE.
 *
 * @param   scheduler  Scheduler control structure
 */
STATIC void Tasks_Dispatch( void )
{
    /*Scan all registered task*/
    for( uint8 i = 0u; i < SchedulerLocal->Tasks; i++ )
    {
        /*Only run those tasks that are started*/
        if( Bfx_GetBit_u32u8_u8( SchedulerControl.TaskFlags, i ) == TRUE )
        {
            /*Only run those tasks that already has its elapsed time*/
            if( SchedulerControl.TaskElapsed[ i ] >= SchedulerControl.TaskPeriod[ i ] )
            {
                SchedulerControl.TaskElapsed[ i ] = 0u;
                /*Run task*/
                SchedulerLocal->TaskPtr[ i ].TaskFunc( );
            }
        }
        /*Increment the task elapsed time in ticks*/
        SchedulerControl.TaskElapsed[ i ] += SchedulerLocal->Tick;
    }
}

STATIC void Timers_Dispatch( void )
{
    /*Scan all registered timers*/
    for( uint8 i = 0u; i < SchedulerLocal->Timers; i++ )
    {
        /*Only run those timers that are started*/
        if( Bfx_GetBit_u32u8_u8( SchedulerControl.TimerFlags, i ) == TRUE )
        {
            /*Decrement timer count by one tick*/
            SchedulerControl.TimerCount[ i ] -= SchedulerLocal->Tick;
            /*Only run those timers that already has its elapsed time*/
            if( SchedulerControl.TimerCount[ i ] == 0u )
            {
                /*Prevent timer from running again*/
                Bfx_ClrBit_u32u8( &SchedulerControl.TimerFlags, i );
                /*Check if the timer has a callback assosiate*/
                if( SchedulerLocal->TimerPtr[ i ].CallbackFunc != NULL )
                {
                    /*Run callback*/
                    SchedulerLocal->TimerPtr[ i ].CallbackFunc( );
                }
            }
        }
    }
}

STATIC void MemCopy( void *Dest, void *Src, uint32 Size )
{
    uint8 *DestPtr = (uint8 *)Dest;
    uint8 *SrcPtr = (uint8 *)Src;

    for( uint32 i = 0u; i < Size; i++ )
    {
        DestPtr[ i ] = SrcPtr[ i ];
    }
}
