# Motor Health Monitoring System – Firmware



## Overview

This firmware is developed for an 8051-based Motor Health Monitoring System.

It monitors motor current and temperature, controls motor operation via PWM,

and provides fault protection with UART, keypad, and OLED interfaces.



The firmware is designed to be **hardware-independent during development**

and supports **simulation-based validation** prior to PCB manufacturing.



---



## Features

- Motor control using PWM

- Overcurrent and overtemperature protection

- Fault latch mechanism

- UART command interface

- 4×4 keypad control

- OLED (SSD1306) display support

- Simulation mode for pre-hardware testing



---



## Firmware Architecture

Firmware/

|--> Core/ --> main loop, system init

|--> Drivers/ --> UART, ADC, Timer, PWM, GPIO, Keypad

|--> Application/ --> motor state, fault logic, command handling

|--> Middleware/ --> OLED driver

|--> Utils/ --> filtering, delay, numeric print helpers

|--> Config/ --> pin and threshold configuration

|--> Debug/ --> reserved for logging (currently empty)

|--> Docs/ --> flowchart, protocol, fault table

|--> sdcc\_build/ --> SDCC build scripts



---

## System States

- **IDLE**  : Motor stopped, safe state

- **RUN**   : Motor running with PWM control

- **FAULT** : Motor disabled due to fault (latched)



---



## Build Environment

- Compiler: SDCC (mcs51)

- Target MCU: AT89C51

- Build Method: `build.bat`

- Output: `motor\_health\_fw.ihx`



---



## Simulation Mode

This firmware supports simulation mode to validate logic without hardware.



Simulated features:

- ADC values

- Fault injection

- UART command handling

- OLED content updates



This allows full firmware validation before PCB manufacturing.



---



## Notes

- Hardware testing will be performed after PCB fabrication

- Firmware is structured for easy extension and maintenance

- Code is written to be portable and standards-compliant



---



## Author

Motor Health Monitoring System  

Firmware by Yukesh







