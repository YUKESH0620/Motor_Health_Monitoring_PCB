# Observations

## General Observations
* Firmware boots consistently and executes as expected
* UART output confirms correct startup and state transitions
* System enters fault state deterministically when conditions are met

## Fault Behavior
* Overcurrent and overtemperature faults trigger immediately
* Fault state is latched and persists until reset
* Motor enable signals are disabled during fault state
* Visual indicators correctly reflect system condition

## ADC and Sensor Observations
* ADC interface logic functions as intended in firmware
* Sensor emulation sufficient to exercise fault logic
* ADC electrical behavior could not be observed due to simulator constraints

## Simulation Stability
* System remains stable when ADC is treated at logic level
* Extended mixed-signal simulation causes instability
* Best results achieved by focusing on control logic validation

