# Test Cases

## Test Case 1: System Startup
* Condition: Power-on reset
* Expected: UART startup message, no fault
* Result: Pass

## Test Case 2: Normal Operation
* Condition: Sensor values below thresholds
* Expected: Motor enabled, fault LED OFF
* Result: Pass

## Test Case 3: Overcurrent Fault
* Condition: Emulated current exceeds threshold
* Expected: Fault latched, motor disabled
* Result: Pass

## Test Case 4: Overtemperature Fault
* Condition: Emulated temperature exceeds threshold
* Expected: Fault latched, motor disabled
* Result: Pass

## Test Case 5: Fault Latching
* Condition: Sensor values return to safe range after fault
* Expected: System remains in fault state
* Result: Pass

## Test Case 6: Fault Recovery
* Condition: System reset
* Expected: Fault cleared, normal operation restored
* Result: Pass
