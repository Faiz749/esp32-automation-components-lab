# Day 9: Multi-Sensor Safety Dashboard

## Project Description

This project combines several ESP32 sensors and output devices into one safety monitoring system.

The system monitors an IR obstacle sensor, flame sensor, MQ-2 gas sensor, and joystick module. It selects the highest-priority condition, controls an LED and buzzer, and displays the system status on the Serial Monitor.

The joystick button switches between automatic and manual modes. The project uses `millis()` for non-blocking operation.

## Components Used

* ESP32 38-pin development board
* IR obstacle sensor
* Flame sensor module
* MQ-2 gas sensor
* Joystick module
* LED
* 220 Ω resistor
* Buzzer
* Breadboard
* Jumper wires
* USB cable

## Wiring

### IR Obstacle Sensor

```text
IR VCC → ESP32 3.3V
IR GND → ESP32 GND
IR DO  → ESP32 GPIO 18
```

### Flame Sensor

```text
Flame VCC → ESP32 3.3V
Flame GND → ESP32 GND
Flame DO  → ESP32 GPIO 17
```

### MQ-2 Gas Sensor

```text
MQ-2 VCC → Supply used during testing
MQ-2 GND → ESP32 GND
MQ-2 AO  → ESP32 GPIO 4
```

The MQ-2 analog output must remain within the ESP32 safe input-voltage range.

### Joystick Module

```text
Joystick VCC → ESP32 3.3V
Joystick GND → ESP32 GND
Joystick VRX → ESP32 GPIO 34
Joystick VRY → ESP32 GPIO 35
Joystick SW  → ESP32 GPIO 13
```

The joystick button uses `INPUT_PULLUP`.

```text
Released → HIGH
Pressed  → LOW
```

### LED

```text
ESP32 GPIO 12 → 220 Ω resistor → LED anode
LED cathode → ESP32 GND
```

### Buzzer

```text
Buzzer positive → ESP32 GPIO 14
Buzzer negative → ESP32 GND
```

## Operating Modes

The system supports two operating modes.

### Automatic Mode

The sensors are monitored automatically. The LED and buzzer respond to the highest-priority detected condition.

### Manual Mode

Pressing the joystick button changes the operating mode.

```text
First press  → MANUAL
Second press → AUTOMATIC
```

In manual mode:

```text
Joystick LEFT  → Buzzer ON
Joystick RIGHT → LED ON
```

Critical hazards such as flame or dangerous gas levels can still override manual control.

## System States

```text
NORMAL
OBSTACLE DETECTED
GAS WARNING
GAS DANGER
FLAME ALERT
MANUAL INPUT
```

## Hazard Priority

When multiple conditions occur at the same time, the system selects the highest-priority state.

```text
1. FLAME ALERT
2. GAS DANGER
3. GAS WARNING
4. OBSTACLE DETECTED
5. MANUAL INPUT
6. NORMAL
```

For example, if flame and an obstacle are detected together, the overall status becomes `FLAME ALERT`.

## Sensor Logic

### IR Sensor

```text
IR value 1 → Object detected
IR value 0 → Clear
```

### Flame Sensor

The flame sensor uses active-low logic.

```text
Flame value 0 → FLAME DETECTED
Flame value 1 → SAFE
```

### MQ-2 Gas Sensor

```text
Below 2600      → SAFE
2600 to 2799    → GAS WARNING
2800 or greater → GAS DANGER
```

These thresholds can be adjusted using actual sensor readings.

### Joystick Direction

```text
X above 2800 → UP
X below 1200 → DOWN
Y above 2800 → RIGHT
Y below 1000 → LEFT
Otherwise    → CENTER
```

The direction labels may change depending on the physical orientation of the joystick.

## Mistakes Fixed

* Corrected the MQ-2 threshold order so `GAS DANGER` is checked before `GAS WARNING`.
* Removed the unnecessary time-based debounce that caused joystick button problems.
* Used button edge detection so one press changes the mode only once.
* Confirmed the joystick button uses active-low logic.
* Separated automatic and manual operating modes.
* Added joystick controls in manual mode.
* Confirmed the flame sensor uses active-low logic.
* Verified the IR sensor output logic using actual hardware readings.
* Added a 30-second MQ-2 warm-up period before using its gas readings.
* Kept the MQ-2 warm-up status separate from the main safety status.
* Used `millis()` instead of `delay()` for repeated sensor readings.
* Divided sensor reading, status detection, device control, and Serial output into separate functions.
* Resolved GPIO conflicts by assigning separate pins to every sensor and output.
* Tested joystick thresholds and adjusted the direction labels according to the actual module orientation.

## Output Behaviour

### Normal

```text
NORMAL
LED: OFF
Buzzer: OFF
```

### Obstacle Detected

```text
OBSTACLE DETECTED
LED: ON
Buzzer: ON
```

### Gas Warning

```text
GAS WARNING
LED: ON
Buzzer: ON
```

### Gas Danger

```text
GAS DANGER
LED: ON
Buzzer: ON
```

### Flame Alert

```text
FLAME ALERT
LED: ON
Buzzer: ON
```

### Manual Mode

```text
MANUAL MODE
Joystick LEFT  → Buzzer ON
Joystick RIGHT → LED ON
```

## Serial Monitor Output

```text
===================================
MULTI-SENSOR SAFETY DASHBOARD
IR Status: Object detected
Flame Status: SAFE
Gas Value: 1524
Gas Status: SAFE
Button: RELEASED
Joystick Direction: CENTER
Overall Status: OBSTACLE DETECTED
===================================
```

## Concepts Learned

* Multi-sensor integration
* Digital and analog sensor inputs
* Active-low sensor logic
* MQ-2 warm-up handling
* Joystick direction detection
* Button edge detection
* Automatic and manual modes
* Hazard-priority logic
* LED and buzzer control
* Non-blocking timing with `millis()`
* Function-based code organization
* Structured Serial Monitor output

## Demo Files

```text
main.ino
README-9.md
dashboard-photo.jpeg
dashboard-screenshot.png
dashboard-demo.mp4
```

## Embedded Systems Relevance

This project demonstrates how an embedded controller can monitor several inputs, assign condition priorities, select an operating state, and control physical outputs.

It also provides a foundation for Course 4, where the system can be expanded with a larger state machine, improved fault handling, display control, and additional actuators.
