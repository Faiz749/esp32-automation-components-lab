# ESP32 Automation Components Lab

## About This Repository

This repository contains a nine-day ESP32 course built around hands-on sensor and actuator projects.

Each project focuses on a different component or embedded-systems concept, including sensor readings, output control, timing with `millis()`, troubleshooting, and combining multiple devices into one system.

The course finishes with a multi-sensor safety dashboard that brings several of the earlier projects together.

## Hardware and Tools

* ESP32 38-pin development board
* Arduino IDE
* Breadboard and jumper wires
* Digital and analog sensors
* LED, buzzer, servo motor, and relay
* Serial Monitor

## Projects

### Day 1: IR Obstacle Timer

Uses an IR obstacle sensor to detect an object and keep an LED on for a set period.

**Folder:** `01-ir-obstacle-timer`

### Day 2: Flame Alert Monitor

Uses a flame sensor to activate an LED and buzzer when a flame is detected.

**Folder:** `02-flame-alert-monitor`

### Day 3: MQ-2 Gas Monitor

Reads an MQ-2 gas sensor and classifies the gas level as safe, warning, or danger.

**Folder:** `03-mq2-gas-monitor`

### Day 4: Potentiometer-Controlled Servo Safety Gate

Uses a potentiometer to control the position of an SG90 servo motor.

**Folder:** `04-potentiometer-controlled-servo-safety-gate`

### Day 5: Relay Low-Voltage Control Lab

Uses the ESP32 to control a relay module and demonstrate basic switching.

**Folder:** `05-relay-low-voltage-control-lab`

### Day 6: PIR Motion Detector

Includes PIR motion-detection code and documents a faulty sensor found during testing.

**Folder:** `06-pir-motion-detector`

### Day 7: Joystick Manual Controller

Reads the joystick axes and button to detect direction and manual input.

**Folder:** `07-joystick-manual-controller`

### Day 8: MPU6050 Tilt Monitor

Includes accelerometer, gyroscope, and tilt-detection code for the MPU6050.

Testing could not be completed because the module’s header pins were not soldered, which caused an unreliable I2C connection.

**Folder:** `08-mpu6050-tilt-monitor`

### Day 9: Multi-Sensor Safety Dashboard

Combines the IR sensor, flame sensor, MQ-2 gas sensor, joystick, LED, and buzzer into one safety-monitoring system.

Main features include:

* Automatic and manual modes
* Hazard-priority handling
* Gas, flame, and obstacle detection
* Joystick-controlled outputs
* Non-blocking timing with `millis()`
* Serial Monitor status updates

**Folder:** `09-multi-sensor-safety-dashboard`

## Main Concepts Learned

* Digital and analog inputs
* Active-high and active-low logic
* Sensor calibration
* Non-blocking timing with `millis()`
* Button edge detection
* LED, buzzer, relay, and servo control
* Multi-sensor integration
* Hazard-priority logic
* Serial debugging
* Hardware troubleshooting
* GitHub project documentation

## Hardware Troubleshooting

Two hardware issues were found during the course.

### PIR Sensor

The PIR sensor was faulty during testing. A working IR obstacle sensor can be used as an alternative in future projects.

### MPU6050

The MPU6050 module could not communicate reliably because its header pins were not soldered. It can be tested again after proper soldering.

## Course Outcome

* Nine ESP32 projects completed
* Multi-sensor safety dashboard completed
* Non-blocking timing implemented
* Hardware problems identified and documented
* Automatic and manual control modes tested

## Next Step

The next stage will expand the safety dashboard into a larger ESP32 safety controller with:

* OLED display
* Servo actuator
* State-machine control
* Improved fault detection
* Automatic and manual modes
* Structured system testing
