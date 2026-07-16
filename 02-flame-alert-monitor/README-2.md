## Day 2: Flame Alert Monitor

## Project Description

This project uses a digital flame sensor with an ESP32 to detect the presence of a flame.

The available flame sensor module provides only a digital output pin. Therefore, the project performs threshold-based flame detection instead of measuring flame intensity through analog values.

When the sensor detects a flame, the ESP32 turns on an LED and buzzer. When no flame is detected, both outputs remain off.

The Serial Monitor displays the flame status, digital sensor value, LED state, and buzzer state every 500 milliseconds.

## Components Used

* ESP32 38-pin board
* Digital flame sensor module
* Active buzzer
* LED
* 220 Ω resistor
* Breadboard
* Jumper wires
* USB cable

## Wiring

## Flame Sensor

```text
Flame sensor VCC → ESP32 3.3V
Flame sensor DO → ESP32 GPIO 27
Flame sensor GND → ESP32 GND
```

## LED

```text
ESP32 GPIO 2 → 220 Ω resistor → LED anode
LED cathode → ESP32 GND
```

## Buzzer

```text
Buzzer positive pin → ESP32 GPIO 5
Buzzer negative pin → ESP32 GND
```

## Sensor Logic

The flame sensor uses active-low digital logic:

```text
Digital value 1 → SAFE
Digital value 0 → FLAME DETECTED
```

The LED and buzzer are controlled using the digital output from the flame sensor.

```text
SAFE → LED OFF and buzzer OFF
FLAME DETECTED → LED ON and buzzer ON
```

## Concepts Learned

* Reading a digital sensor using `digitalRead()`
* Understanding active-low sensor logic
* Detecting flame using a digital threshold
* Controlling an LED using `digitalWrite()`
* Controlling a buzzer using `digitalWrite()`
* Using functions to separate program tasks
* Using `millis()` for non-blocking Serial timing
* Printing sensor and output states on the Serial Monitor


## Mistakes Fixed

* Removed the analog sensor code because the available flame sensor only provides a digital output.
* Removed the undefined analog pin and analog value variables.
* Configured the flame sensor pin correctly as an input.
* Confirmed that the flame sensor uses active-low logic.
* Changed the flame-detection condition so digital value `0` means flame detected.
* Updated `previousTime` inside the `millis()` timing condition.
* Used separate functions for displaying readings and controlling devices.
* Set the LED and buzzer to OFF during startup.
* Increased the Serial printing interval to 500 milliseconds for clearer output.

## Demo Files

* `flame-alert-photo.jpeg`
* `flame-alert-screenshot.png`
* `flame-alert-demo.mp4`

## Embedded Systems Relevance

Digital flame sensors can be used as basic safety inputs in embedded alarm and automation systems.

This lab demonstrates how a microcontroller reads an active-low digital sensor, makes a safety decision, and activates visual and audible warning devices .

It also demonstrates an important embedded-systems skill: adapting the software design according to the capabilities and limitations of the available hardware.
