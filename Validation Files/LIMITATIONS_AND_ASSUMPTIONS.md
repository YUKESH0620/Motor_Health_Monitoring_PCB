# Limitations and Assumptions

## Assumptions
* Firmware logic is validated independently of physical hardware availability.
* Sensor behavior is emulated conceptually for fault-path validation.
* ADC thresholds are evaluated at firmware logic level
* UART output is considered a reliable indicator of system state
* Motor control is validated via enable signals, not physical motor dynamics

## Simulation Limitations
* Proteus does not reliably support GPIO-driven serial ADC communication with the 8051 core
* Electrical behavior of the ADC could not be observed accurately in simulation
* Real sensor noise, offset, and dynamic behavior are not modeled
* Motor electrical characteristics such as load and inertia are not simulated

## Impact on Validation
* Limitations do not affect validation of control flow or safety logic
* Core system behavior remains verifiable through firmware execution
* Electrical validation is deferred to the hardware testing phase

## Mitigation Strategy
* Firmware designed to be hardware-correct and portable
* Limitations clearly documented to avoid misinterpretation
* Planned hardware validation phase defined for future work
