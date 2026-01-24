# Firmware to Simulation Mapping

## Purpose
This document describes how firmware modules and signals are mapped to
Proteus simulation elements. The intent is to clearly show how firmware
behavior was observed and validated in the absence of physical hardware.

---

## Microcontroller Mapping
* MCU: AT89C51
* Clock frequency configured as per schematic
* Firmware built using SDCC and loaded into Proteus MCU model
* All GPIO usage follows pin_config.h without modification

---

## UART Interface Mapping
* Firmware module: Drivers/uart.c
* MCU pins mapped to Proteus Virtual Terminal
* UART used for:
  * Startup confirmation
  * State indication
  * Debug and observation output
* UART acts as the primary external visibility interface in simulation

---

## Motor Control Mapping
* Firmware modules:
  * Drivers/gpio.c
  * Application/fault_manager.c
* Motor enable signals generated on PWM/enable pins
* In simulation:
  * Motor behavior verified logically
  * Enable/disable action observed via GPIO states and LEDs
* Physical motor dynamics not simulated

---

## Fault Indicator Mapping
* Fault LED mapped directly to MCU GPIO pin
* LED polarity implemented in firmware based on schematic wiring
* Fault LED used to confirm:
  * Fault detection
  * Fault latching
  * Persistent fault state until reset

---

## Sensor Input Mapping
* Firmware module: Application/sensor_manager.c
* Sensor values conceptually provided via simulation inputs
* Potentiometers used to emulate sensor output levels
* Mapping used to exercise:
  * Overcurrent fault logic
  * Overtemperature fault logic
* Electrical sensor accuracy not modeled

---

## ADC Interface Mapping
* Firmware module: Drivers/adc.c
* GPIO-driven serial ADC interface implemented in firmware
* ADC read function integrated into sensor management logic
* In simulation:
  * ADC interface validated at firmware logic level
  * Electrical ADC behavior not reliably observable due to tool limitations

---

## IR Sensor Mapping
* IR sensor treated as a digital input signal
* Logic-level changes used to emulate sensor events
* IR input not part of fault handling path
* Used only for state or event-based logic (if applicable)

---

## Reset and Recovery Mapping
* Firmware reset logic clears fault latch
* Simulation reset used to validate:
  * Fault recovery
  * System re-initialization
* Reset behavior matches intended system design

---

## Summary
* Firmware modules were mapped directly to simulation elements
* Simulation focused on validating control flow and safety behavior
* All mappings reflect intended hardware connections
* Any limitations in electrical behavior are documented separately
