# AUTOSAR MCAL Embedded Upskilling Bootcamp

This repo contains the projects, codes, examples, exercises and results for the "[AUTOSAR MCAL Embedded Upskilling Bootcamp](https://embedded-house.ghost.io/tag/autosar-mcal-with-nxp-s32k1xx/)" by [Modular MX](https://www.linkedin.com/company/modular-mx/).

![AUTOSAR_MCAL_Upskilling.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/AUTOSAR_MCAL_Upskilling.png)

Date: July, 2024.

- The [**Certificate**](https://www.acreditta.com/credential/e82a8595-ae1b-4ffb-b578-efea011bb781?utm_source=copy&resource_type=badge&resource=e82a8595-ae1b-4ffb-b578-efea011bb781) is available.

## Description

This AUTOSAR Upskilling Bootcamp, focused on MCAL layer, shows how to configure multiple peripherals that can be found in the microcontroller hardware by making use of Automotive industry tools.
This Upskilling consists on 6 weeks, where 10% is theory and the 90% remaining is practice and hands-on.

By working through examples and exercises that use the NXP S32K144 board, the Modular MX Modular-S1 board and tools like Elektrobit Tresos, SEGGER Ozone debugger, and SavvyCAN, you'll gain an understanding on configuring, generating, and developing highly efficient low-level drivers and analyze their utilization in Classic AUTOSAR.

The Upskilling Bootcamp covers:
1. Introduction to AUTOSAR MCAL and EB Tresos.
2. PORT driver.
3. DIO driver.
4. MCU driver.
5. GPT Driver.
6. Platform Driver.
7. ADC driver.
8. PWM driver.
9. SPI driver.
10. I/O Hardware Abstraction.
11. CAN driver.
12. CANIF driver.

## Hardware Requirements

**[NXP S32K144-Q100 Evaluation Board for Automotive General Purpose](https://www.nxp.com/design/design-center/development-boards-and-designs/automotive-development-platforms/s32k-mcu-platforms/s32k144-q100-evaluation-board-for-automotive-general-purpose:S32K144EVB)** - Based on the 32-bit Arm® Cortex®-M4F S32K14 MCU, this is the base board used in this bootcamp. \
![S32K144_pinout.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/S32K144_pinout.png)

**[Modular-S1 Board](https://embedded-house.ghost.io/tag/autosar-mcal-with-nxp-s32k1xx/)** - Board developed by Modular MX, comes with a whole new layer of additional peripherals customized specifically for NXP S32K144. Contains 2 potentiometers, 1 buzzer, 3 push buttons, 8 leds, general purpose inputs-outputs, USB Hub, CAN analyzer, 24 MHz logic analyzer, SPI display, 2 SPI Eeproms, and external CAN & LIN analyzer connectors.   \
![Modular-S1_Board.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/Modular-S1_Board.png)

**NXP S32K144 Board + Modular-S1 Board:**
![NXP-S32K144_Modular-S1.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/NXP-S32K144_Modular-S1.png)

## Software Requirements

**[EB Tresos Studio](https://www.elektrobit.com/products/ecu/eb-tresos/studio/)** - Tool environment for electronic control unit (ECU) development with AUTOSAR. EB tresos Studio lets you configure, validate, and generate your ECU basic software (BSW). EB tresos Studio is the industry-standard tool for microcontroller abstraction layer (MCAL) development by semiconductor suppliers such as NXP, STM, and Infineon. Works on Windows and is free. \
**[SEGGER Ozone](https://www.segger.com/products/development-tools/ozone-j-link-debugger/)** - Full-featured graphical debugger for embedded applications. It is possible to debug any embedded application on C/C++ source and assembly level, as well as loading applications built with any tool chain / IDE or debug the target's resident application without any source. Ozone includes all well-known debug controls and information windows and makes use of the best performance of J-Link and J-Trace debug probes. Works on Windows/Linux/Mac and is free. \
**[SavvyCAN](https://www.savvycan.com/)** - It is a CAN bus reverse engineering and capture tool. SavvyCAN can use any CAN interface supported by QT's SerialBus system (PeakCAN, Vector, SocketCAN, J2534, etc). It can capture and send to multiple buses and CAN capture devices at once. Works on Windows/Linux/Mac and is free. 

## Notes

You can find the [**Setup AUTOSAR Tools**](https://embedded-house.ghost.io/part-0-setup-your-autosar-tools/) section where Modular MX explains the right procedure to download, install and configure all needed tools, including its dependencies, how to import the template project file and flash it to the device.

## Results (In progress)

### Output from one of the CAN module's example:

![SavvyCAN_Ozone_Example.png](https://github.com/renatosoriano/AUTOSAR-MCAL-Embedded-Upskilling-Bootcamp/blob/main/Images/SavvyCAN_Ozone_Example.png)
