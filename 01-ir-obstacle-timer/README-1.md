# Day 1: IR Obstacle Detection Timer

## Project Description

This project uses an IR obstacle sensor with an ESP32 to detect nearby objects.

When an obstacle is detected, the ESP32 turns on an LED and records the time of the most recent detection. The LED remains on for five seconds after the latest obstacle detection.

If another obstacle is detected during this period, the timer resets. The LED turns off only after five seconds have passed without another detection.

The Serial Monitor displays a message only when the LED state changes.

## Components Used

* ESP32 38-pin development board
* IR obstacle sensor module
* LED
* 220 Ω resistor
* Breadboard
* Jumper wires
* USB cable

## Wiring

### IR Obstacle Sensor

```text
IR sensor VCC → ESP32 3.3V
IR sensor OUT → ESP32 GPIO 25
IR sensor GND → ESP32 GND
```

### LED

```text
ESP32 GPIO 2 → 220 Ω resistor → LED anode
LED cathode → ESP32 GND
```

## Sensor Logic

The IR obstacle sensor provides a digital output signal:

```text
Obstacle detected → Digital output changes state
No obstacle detected → Digital output returns to its normal state
```

Depending on the sensor module, obstacle detection may produce either a `HIGH` or `LOW` signal. The active-high or active-low behavior used in this project was confirmed through hardware testing.

## How It Works

1. The ESP32 continuously reads the IR sensor output using `digitalRead()`.
2. When an obstacle is detected, the LED turns on.
3. The current value of `millis()` is stored as the latest detection time.
4. Each new detection resets the five-second timer.
5. The LED turns off after five seconds have passed without another obstacle detection.
6. Serial Monitor messages are printed only when the LED changes state.

## Concepts Learned

* Reading a digital sensor using `digitalRead()`
* Detecting `HIGH` and `LOW` signals
* Understanding active-high and active-low sensor behavior
* Detecting nearby objects using reflected infrared light
* Controlling an LED using `digitalWrite()`
* Using `millis()` for non-blocking timing
* Recording the latest obstacle detection time
* Keeping an LED on for a fixed period after an event
* Resetting a timeout when a new event occurs
* Comparing the current system state with the previous state
* Printing Serial Monitor messages only when the state changes
* Adjusting sensor sensitivity using the onboard potentiometer

## Mistakes Fixed

* Correctly identified the component as an IR obstacle sensor rather than a PIR motion sensor.
* Updated the project name and documentation to match the actual sensor.
* Changed the sensor description from motion detection to obstacle detection.
* Used GPIO 25 for the IR sensor’s digital output.
* Used GPIO 2 for the LED output.
* Added a 220 Ω resistor to protect the LED.
* Corrected the capitalization of the LED-off message.
* Added previous-state checking to prevent repeated Serial Monitor messages.
* Used `millis()` instead of `delay()` for the five-second timeout.
* Tested the sensor output to determine whether obstacle detection produces a `HIGH` or `LOW` signal.

## Demo Files

* `ir-obstacle-photo.jpeg`
* `ir-obstacle-screenshot.png`
* `ir-obstacle-demo.mp4`

## Embedded Systems Relevance

IR obstacle sensors are commonly used in:

* Mobile robots
* Obstacle-avoidance systems
* Automatic doors
* Object counters
* Proximity-detection systems
* Safety zones

The timeout logic is useful when an output must remain active briefly after an event. For example, an indicator or safety light may need to stay on for a few seconds after an object leaves the detection area.
