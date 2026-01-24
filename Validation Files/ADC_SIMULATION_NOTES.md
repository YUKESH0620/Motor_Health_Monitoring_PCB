# ADC Simulation Notes

## Overview

The Motor Health Monitoring System uses an external SPI-based ADC to acquire current and temperature sensor data. During the current project phase, ADC behavior was evaluated primarily at the firmware and logic level using Proteus simulation.

This document clarifies the scope, approach, and limitations of ADC validation performed in simulation.

## ADC Interface in Firmware

The ADC is interfaced using bit-banged SPI driven by AT89C51 GPIO pins.

Chip Select (CS) is implemented as an active-low digital control signal.

Clock and data lines are controlled entirely by firmware.

ADC read routines follow correct transaction structure for real hardware operation.

The firmware implementation is considered hardware-correct and suitable for physical validation.
 

## Sensor Emulation in Simulation

Physical sensors were not electrically simulated.

Adjustable sources (potentiometers) were used to conceptually emulate sensor outputs.

These sources were intended to exercise:

* Overcurrent fault logic
 
* Overtemperature fault logic



The purpose was to validate fault detection, latching, and system response, not analog accuracy.


## Proteus Simulation Limitation

During simulation, it was observed that:

Proteus does not reliably support bit-banged SPI ADC communication with the 8051 core.

The MCP3008 ADC model requires strict protocol timing and framing.

GPIO-driven chip-select and clock signals from the AT89C51 are not consistently recognized by the ADC model.

Forcing chip-select low does not resolve this limitation.


### As a result:

* Real-time ADC value changes could not be reliably observed in simulation.

* This is a tool limitation, not a firmware or design error.


## Validation Scope Achieved

Despite the above limitation, the following were successfully validated:

* Correct firmware structure for ADC access

* Proper chip-select control logic

* Integration of ADC readings into sensor and fault management modules

* Fault triggering, latching, and motor shutdown behavior based on threshold logic

ADC functionality was therefore validated at the firmware logic level.


## Planned Hardware Validation

Full electrical validation of the ADC and sensor interfaces is planned on physical hardware, including:

* Verification of SPI timing

* Sensor voltage-to-physical unit accuracy

* Noise and dynamic behavior under real operating conditions

This will be addressed once the PCB is fabricated and assembled.


## Summary

Proteus simulation was used to validate ADC-related firmware logic and system behavior.

Due to known simulator limitations with mixed-signal SPI peripherals on the 8051 platform, electrical ADC behavior was not validated in simulation. This limitation has been identified, documented, and deferred to the hardware validation phase.

