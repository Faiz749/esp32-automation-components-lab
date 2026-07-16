# Day 3: MQ-2 Gas Monitor

## Project Description

This project uses an MQ-2 gas sensor with an ESP32 to monitor changes in air quality through the sensor’s analog output.

The system first allows the sensor to warm up. After the warm-up period, the ESP32 takes multiple analog readings from the MQ-2 sensor and calculates their average.

The average reading is then compared with calibrated threshold values to classify the environment as `SAFE`, `WARNING`, or `DANGER`.

The LED remains off when the status is `SAFE`. It turns on when the sensor reading reaches the `WARNING` or `DANGER` threshold.

## Components Used

* ESP32 38-pin development board
* MQ-2 gas sensor module
* LED
* 220 Ω resistor
* Breadboard
* Jumper wires
* Perfume
* Tissue
* USB cable

## Wiring

### MQ-2 Sensor

```text
MQ-2 VCC → ESP32 3.3V
MQ-2 GND → ESP32 GND
MQ-2 AO  → ESP32 GPIO 34
MQ-2 DO  → Not used
```

### LED

```text
ESP32 GPIO 2 → 220 Ω resistor → LED anode
LED cathode   → ESP32 GND
```

## Calibration Values

The MQ-2 sensor was allowed to warm up in an air-conditioned room away from direct airflow.

After the sensor stabilized, the following calibration values were selected:

```text
Baseline:          2200
Warning Threshold: 2450
Danger Threshold:  2600
```

> These values are specific to the sensor, environment, power supply, and testing conditions used in this project. Other setups may require different threshold values.

## Concepts Learned

* Reading an analog sensor using `analogRead()`
* Understanding the MQ-2 sensor warm-up process
* Recording a clean-air baseline
* Creating warning and danger thresholds
* Comparing sensor readings with threshold values
* Classifying readings as `SAFE`, `WARNING`, or `DANGER`
* Averaging 15 analog readings to produce a more stable result
* Using `millis()` for non-blocking warm-up timing
* Using `millis()` for periodic Serial Monitor updates
* Controlling an LED using `digitalWrite()`
* Using functions to separate sensor reading, status logic, LED control, and serial output
* Keeping outputs off during the sensor warm-up period
* Adapting a project to the available testing environment
* Understanding that relative sensor readings are not the same as calibrated gas-concentration measurements

## Mistakes Fixed

* Initialized missing functions and variables.
* Corrected a naming error related to the sensor warm-up variables.
* Removed extra curly brackets that caused an incorrect code structure.
* Added missing brackets to the required conditions and functions.
* Changed the normal system status from `Normal` to `SAFE`.
* Kept the LED off during the sensor warm-up period.
* Corrected the threshold-checking order by checking `DANGER` before `WARNING`.

## Demo Files

* `mq2-gas-photo.jpeg`
* `mq2-gas-screenshot.png`
* `mq2-gas-demo.mp4`

## Demo Description

The demo video shows a tissue sprayed with perfume being brought near the MQ-2 sensor. The LED turns on when the sensor reading crosses the warning or danger threshold.

After the tissue is removed and the perfume vapour clears, the sensor reading returns to the safe range and the LED turns off.

When the tissue is brought near the sensor again, the reading increases and the LED turns on again.

## Embedded Systems Relevance

Gas and smoke sensors are commonly used as inputs in monitoring, automation, and safety systems.

This project demonstrates how an embedded controller can read an analog sensor, establish a baseline, apply threshold-based decision logic, and control a physical output.

It also demonstrates an important engineering skill: adapting the hardware and software design according to actual component behaviour, environmental conditions, and available testing resources.
