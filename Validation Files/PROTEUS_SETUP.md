# Proteus Setup

## Simulation Tool
* Proteus 8.1 Professional used for system-level simulation

## Core Components
* AT89C51 microcontroller
* Virtual Terminal for UART observation
* GPIO indicators for motor status and fault indication
* Emulated sensor inputs using adjustable sources

## Firmware Integration
* Firmware compiled using SDCC
* Compiled output loaded into MCU program memory
* Clock and reset configured as per schematic

## Usage Notes
* Virtual Terminal must be opened manually during simulation
* Simulation reset used to validate system re-initialization
