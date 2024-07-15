/**
 * @file HwIoAb_3_Buzzer_Cfg.h
 * @brief This header contains the configuration macros for the IO hardware abstraction for the buzzer on board.
 * @author Renato Soriano
*/

#ifndef HWIOAB_3_BUZZER_CFG_H
#define HWIOAB_3_BUZZER_CFG_H

#define HWIOAB_BUZZER_CH PwmChannel7   /* Pwm channel for the buzzer */

/* The Modular-S1 on board buzzer works with a 2.7 kHz to 10 kHz signal 
Buzzer type: 5V Magnetic Buzzer Transducer.
Frequency: 2.7kHz
Comparable Model: CMT-1032-85-SMT-TR
Reference Links: 
https://www.cuidevices.com/product/resource/cmt-1032-85-smt-tr.pdf
https://www.hnbuzzer.com/smd-magnetic-buzzer/57680264.html
*/

/*
 FREQUENCY CONVERSION:
 1. System Clock and PWM Frequency:
 System Clock Frequency (f_clk): 8 MHz (8,000,000 Hz)
 Desired Buzzer PWM Frequency (f_pwm): 2.7 kHz (2,700 Hz) to 10 kHz (10,000 Hz)
 
 2. Calculating the PWM Period:
 The PWM period is the inverse of the PWM frequency. The period specifies how many clock cycles occur within one PWM cycle.
 PWM Period = 1 / PWM Frequency

 3. Formula to Calculate the Period in Clock Cycles:
 PWM Period (in clock cycles) = System Clock Frequency / Desired PWM Frequency
 
 - PWM Period (in clock cycles) = 8,000,000 Hz / 2,700 Hz = 2,963
 - This means that to generate a 2.7 kHz PWM signal from a 8 MHz clock, each PWM cycle must be 2,963 clock cycles long.

 - PWM Period (in clock cycles) = 8,000,000 Hz / 3,000 Hz = 2,666.6
 - This means that to generate a 3 kHz PWM signal from a 8 MHz clock, each PWM cycle must be 2,666.6 clock cycles long.

 - PWM Period (in clock cycles) = 8,000,000 Hz / 5,000 Hz = 1,600
 - This means that to generate a 5 kHz PWM signal from a 8 MHz clock, each PWM cycle must be 1,600 clock cycles long.
 
 - PWM Period (in clock cycles) = 8,000,000 Hz / 7,500 Hz = 1,066.6
 - This means that to generate a 7.5 kHz PWM signal from a 8 MHz clock, each PWM cycle must be 1,066.6 clock cycles long.

 - PWM Period (in clock cycles) = 8,000,000 Hz / 10,000 Hz = 800
 - This means that to generate a 10 kHz PWM signal from a 8 MHz clock, each PWM cycle must be 800 clock cycles long.
*/
#define HWIOAB_BUZZER_PERIOD_0 2963     /* Period value for tone 0 ( 2.7 Khz ) */
#define HWIOAB_BUZZER_PERIOD_1 2666     /* Period value for tone 1 ( 3 Khz ) */
#define HWIOAB_BUZZER_PERIOD_2 1600     /* Period value for tone 2 ( 5 Khz ) */
#define HWIOAB_BUZZER_PERIOD_3 1066     /* Period value for tone 3 ( 7.5 Khz ) */
#define HWIOAB_BUZZER_PERIOD_4 800      /* Period value for tone 4 ( 10 Khz ) */

/*  GENERAL DEFAULT VALUES FROM TRESOS CONFIG
Default values for duty cycle of Pwm channel at initialization:
- 0     (0x0)       represents for 0% duty cycle
- 3277  (0xCCD)     represents for 10% duty cycle
- 8192  (0x2000)    represents for 25% duty cycle
- 16384 (0x4000)    represents for 50% duty cycle
- 24576 (0x6000)    represents for 75% duty cycle
- 29491 (0x7333)    represents for 90% duty cycle
- 32768 (0x8000)    represents for 100% duty cycle
*/
#define HWIOAB_BUZZER_0_DUTY_CYCLE 0x0           /* 0% duty cycle value */
#define HWIOAB_BUZZER_25_DUTY_CYCLE 0x2000       /* 25% duty cycle value */
#define HWIOAB_BUZZER_50_DUTY_CYCLE 0x4000       /* 50% duty cycle value */
#define HWIOAB_BUZZER_75_DUTY_CYCLE 0x6000       /* 75% duty cycle value */
#define HWIOAB_BUZZER_100_DUTY_CYCLE 0x8000      /* 100% duty cycle value */

#endif // HWIOAB_3_BUZZER_CFG_H