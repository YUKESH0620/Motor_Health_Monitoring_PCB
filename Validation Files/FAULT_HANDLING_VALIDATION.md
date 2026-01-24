# Fault Handling Validation

## Objective

   To validate the correctness of fault detection, latching, and safety response logic implemented in firmware for the Motor Health Monitoring System.

   The validation focuses on system behavior and safety logic, independent of physical hardware availability.

## Faults Implemented

 The firmware implements the following fault conditions:

  1. Overcurrent Fault (OC)

    Sensor: ACS770 (emulated in simulation)

    Threshold: 15 A

    Detection type: Instantaneous

    Latching: Yes

    Recovery: System reset (RESET command / RESET key)

  2. Overtemperature Fault (OT)

    Sensor: LM35 (emulated in simulation)

    Threshold: 70 °C

    Detection type: Instantaneous

    Latching: Yes

    Recovery: System reset (RESET command / RESET key)

## Global Fault Behavior

 The following global behaviors were validated:

 * Fault detection is global (single current and temperature source)

 * Any fault disables all motor outputs

 * Fault condition remains latched until reset

 * START or run commands are ignored during FAULT state

 * Visual fault indication is provided via a dedicated fault LED

## Validation Method

 * Fault logic was exercised using emulated sensor inputs in Proteus.

 * Sensor values were varied conceptually to cross defined thresholds.

 * UART output and LED indicators were used to observe system state transitions.

 * Motor behavior was verified logically through motor enable control signals.

 This approach validates decision-making and safety enforcement, not sensor electrical accuracy.

## Test Scenarios and Observations

 Normal Operation

 * Sensor values below thresholds

 * Motor enable signals active

 * Fault LED OFF

 * System remains in RUN state

 Result: Pass

## Overcurrent Fault Trigger

 * Emulated current exceeds 15 A threshold

 * Fault detected immediately

 Observed behavior:

 * Fault LED ON

 * Motor enable signals disabled

 * Fault state latched

 Result: Pass

## Overtemperature Fault Trigger

 * Emulated temperature exceeds 70 °C threshold

 * Fault detected immediately

 Observed behavior:

 * Fault LED ON

 * Motor enable signals disabled

 * Fault state latched

 Result: Pass

## Fault Latching Verification

 * After fault occurrence, sensor values returned to safe range

 * System remained in FAULT state

 * Motor outputs remained disabled

 Result: Pass

## Fault Recovery

 * System reset issued

 * Fault latch cleared

 * System returned to normal operation

 Result: Pass

## Key Observations

 * Fault handling logic behaves deterministically and safely

 * Motor shutdown is enforced immediately upon fault detection

 * Latching prevents unsafe automatic recovery

 * Visual and control indicators correctly reflect fault state

## Validation Scope and Limitations

 * Fault handling was validated at firmware and system logic level

 * Electrical accuracy of sensors was not validated in simulation

 * Real-world sensor dynamics and noise are deferred to hardware testing

## Conclusion

 Fault detection, latching, and global shutdown behavior were successfully validated using simulation-based logic testing. The implemented fault handling mechanism meets the defined safety requirements and provides a robust foundation for subsequent hardware validation.