# Motor Health Monitoring System using 8051

**Embedded Hardware–Firmware Co-Design Project**

---

## Project Overview

The **Motor Health Monitoring System** is an embedded systems project designed to monitor the operational health of an electric motor and protect it from unsafe conditions.

The project integrates:

* A structured hardware design
* Bare-metal embedded control logic
* Simulation-based validation
* Professional documentation practices

The focus is on **learning, reliability, and design clarity**, following workflows commonly used in industry and academia.

---

## System Purpose

* Monitor key motor parameters
* Detect abnormal operating conditions
* Automatically disable the motor under fault
* Provide clear visual and UART-based feedback
* Enable validation without physical hardware

---

## System Operation Flow

* System initialization

* Peripheral setup

* Sensor sampling

* Data filtering

* Threshold comparison

* Fault decision

* Motor control update

* Display & UART update

* Continuous monitoring loop

## Block Diagram

```
Power Input
    │
    V
Voltage Regulation
    │
    V
Microcontroller (8051)
 |--> Sensor Interface
 |   |--> Current
 |   |--> Temperature
 |   |--> Vibration
 |   |--> IR Sensor
 |--> Motor Driver (PWM Control)
 |--> Display (OLED)
 |--> Keypad Interface
 |--> UART Debug Interface
```

---

## System Summary

| Aspect         | Description                         |
| -------------- | ----------------------------------- |
| Controller     | AT89C51 (8051 architecture)         |
| Control Method | Bare-metal                          |
| Sensors        | Current, Temperature, Vibration, IR |
| Motor Control  | PWM-based with fault shutdown       |
| Display        | OLED (I²C)                          |
| User Input     | 4×4 Keypad                          |
| Communication  | UART                                |
| Validation     | Proteus Simulation                  |
| PCB Status     | Not fabricated                      |

---

## Design Artifacts

The repository contains:

* Complete hardware schematics

* PCB layout and 3D models (design stage)

* Proteus simulation files

* Modular firmware source code

* Structured documentation

---

# Schematic Diagram

<img width="1012" height="694" alt="Screenshot 2026-01-11 205045" src="https://github.com/user-attachments/assets/dd92cfed-d5e5-414e-993b-beaea53d33ed" />

<img width="1014" height="692" alt="Screenshot 2026-01-11 205103" src="https://github.com/user-attachments/assets/534106fb-10a4-4574-bfbd-5778506d9a2b" />

<img width="1000" height="690" alt="Screenshot 2026-01-11 205225" src="https://github.com/user-attachments/assets/7400bf5f-28e6-4d26-82e9-790c7ab72637" />

# PCB Layout

<img width="1919" height="1019" alt="Screenshot 2026-01-16 142352" src="https://github.com/user-attachments/assets/31d809bf-2b5e-43c0-b747-9d0f88695648" />

<img width="1577" height="809" alt="Screenshot 2026-01-16 144337" src="https://github.com/user-attachments/assets/01d9fc1c-7285-41e9-8bcf-b005fe36ed3c" />

# 3D PCB View

<img width="1542" height="831" alt="Screenshot 2026-01-16 144525" src="https://github.com/user-attachments/assets/4333e3ac-ce9f-4074-a83d-be8e0e0daa23" />

<img width="1452" height="793" alt="Screenshot 2026-01-16 144549" src="https://github.com/user-attachments/assets/a0f4e7b1-e554-4f81-8d07-0b1aabfacfc3" />

<img width="1678" height="799" alt="Screenshot 2026-01-16 144806" src="https://github.com/user-attachments/assets/809cec17-71db-42df-afd7-1bbe25b1415e" />

<img width="1286" height="765" alt="Screenshot 2026-01-16 144700" src="https://github.com/user-attachments/assets/c9fa1efd-86eb-4929-9543-9118d8d67109" />

---

## Electrical Specifications

| Parameter                  | Value                         |
|----------------------------|-------------------------------|
| Supply Voltage             | 5 V DC                        |
| MCU Logic Level            | 5 V                           |
| Over-Current Threshold     | 15 A                          |
| Over-Temperature Threshold | 70 °C                         |
| Communication Baud Rate    | Configurable (UART)           |
| Fault Response Time        | Deterministic (loop-based)    |

---

## Validation Strategy

* Hardware behavior validated using **Proteus simulation**
* Sensor outputs emulated for fault testing
* UART used as primary observation interface
* Motor behavior verified logically
* No dependency on physical PCB availability

---

## Repository Organization

* **Hardware**
  Contains schematic, PCB, simulation files, and hardware documentation

* **Firmware**
  Contains source code, configuration files, and firmware documentation

Each section includes its own detailed README.

---

## Current Project Status

*  Requirements defined
*  Hardware designed
*  Simulation validated
*  Firmware structured and built
*  PCB fabrication pending

---

## Future Enhancements

* Physical PCB manufacturing
* Bench testing with real motors
* Data logging and diagnostics
* IoT expansion via external gateway
* Advanced fault analytics

---

## Author

**YUKESH**
B.E. Electrical and Electronics Engineering

---

## License

This project is intended for **educational and non-commercial use**.
All materials are shared to support learning, experimentation, and academic review.

---

## Closing Note

This project demonstrates a **complete embedded system lifecycle** - from concept and schematic design to firmware integration and simulation-based validation - following practices aligned with real-world engineering workflows.
