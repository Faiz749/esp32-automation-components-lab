# Day 1: PIR Motion Timer

## Project Description

This project uses an HC-SR501 PIR motion sensor with an ESP32 to detect movement. When motion is detected, the ESP32 turns on an LED and records the time of the latest motion event.

The LED remains on for five seconds after the most recent motion detection. If new motion is detected during this period, the timer resets. The LED turns off only after five seconds have passed without motion.

The Serial Monitor prints messages only when the LED state changes.

## Components Used

* ESP32 38-pin board
* HC-SR501 PIR motion sensor
* LED
* 220 Ω resistor
* Breadboard
* Jumper wires
* USB cable

## Wiring

### PIR Sensor

```text
PIR VCC → ESP32 VIN/5V
PIR OUT → ESP32 GPIO 25
PIR GND → ESP32 GND
```

### LED

```text
ESP32 GPIO 2 → 220 Ω resistor → LED anode
LED cathode → ESP32 GND
```

## Concepts Learned

* Reading a PIR sensor using `digitalRead()`
* Detecting digital `HIGH` and `LOW` signals
* Controlling an LED using `digitalWrite()`
* Using `millis()` for non-blocking timing
* Recording the latest motion detection time
* Keeping the LED on for five seconds after motion is detected
* Resetting the timeout when new motion is detected
* Comparing the current system state with the previous state
* Printing Serial messages only when the state changes
* Allowing the PIR sensor to warm up after startup

## Mistakes Fixed

* Updated the PIR input pin to GPIO 25.
* Updated the LED output pin to GPIO 2.
* Added a 220 Ω resistor to protect the LED.
* Corrected the capitalization of the LED-off message.
* Added previous-state checking to prevent repeated Serial Monitor messages.
* Used `millis()` for the five-second timeout instead of `delay()` in the main detection logic.
* Tested the PIR output logic to confirm whether motion produces a `HIGH` or `LOW` signal.

## Demo Files

* `pir-motion-photo.jpeg`
* `pir-motion-screenshot.png`
* `pir-motion-demo.mp4` 

## Embedded Systems Relevance

PIR sensors are commonly used in security systems, automatic lighting, occupancy detection, and smart-room automation.

The timeout logic is useful because an output often needs to remain active for a short period after an event.This is similar to automatic lights that remain on briefly after a person leaves the detection area.
