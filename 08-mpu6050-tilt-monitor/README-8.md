# Day 8: MPU6050 Tilt Monitor

## Project Description

This project was designed to use an ESP32 and an MPU6050 motion sensor to monitor acceleration, rotation, and tilt direction.

The ESP32 communicates with the MPU6050 using the I2C protocol. The program reads the accelerometer and gyroscope values and classifies the module orientation as level, tilted left, tilted right, tilted forward, or tilted backward.

The software and tilt-detection logic were completed successfully. However, the MPU6050 module did not have soldered header pins, and a reliable I2C connection could not be established during physical testing.

## Components Used

* ESP32 38-pin development board
* MPU6050 accelerometer and gyroscope module
* Breadboard
* Jumper wires
* Loose header pins
* Non-conductive paper support
* USB cable

## Wiring

### MPU6050 Module

```text
MPU6050 VCC → ESP32 3.3V
MPU6050 GND → ESP32 GND
MPU6050 SDA → ESP32 GPIO 21
MPU6050 SCL → ESP32 GPIO 22
```

## Required Libraries

The following Arduino libraries were used:

```text
Adafruit MPU6050
Adafruit Unified Sensor
Adafruit BusIO
Wire
```

`Wire` is included with the Arduino framework and is used for I2C communication.

## Project Operation

The program performs the following operations:

* Starts Serial communication at 115200 baud
* Attempts to initialize the MPU6050
* Stops the program if the sensor is not detected
* Reads accelerometer values along the X, Y, and Z axes
* Reads gyroscope values along the X, Y, and Z axes
* Determines the tilt direction using acceleration thresholds
* Displays all readings on the Serial Monitor
* Uses `millis()` for non-blocking sensor-reading intervals

## Example Expected Serial Monitor Output

The following values are illustrative examples and were not captured during physical testing.

### Sensor Detected

```text
MPU6050 Tilt Monitor started
-----------------------------------
Acceleration X: 0.25
Acceleration Y: -0.30
Acceleration Z: 9.72
Gyroscope X: 0.01
Gyroscope Y: -0.02
Gyroscope Z: 0.00
Orientation: LEVEL
```

### Tilted Position

```text
-----------------------------------
Acceleration X: 5.20
Acceleration Y: 0.40
Acceleration Z: 8.15
Gyroscope X: 0.03
Gyroscope Y: 0.01
Gyroscope Z: -0.02
Orientation: TILTED RIGHT
```

### Sensor Not Detected

```text
MPU6050 sensor not found
```

## Hardware Test Result

The red power LED on the MPU6050 turned on, confirming that the module received electrical power.

However, the ESP32 could not detect the MPU6050 through I2C communication. An I2C scanner was also tested, but no device address was found.

The expected MPU6050 I2C address was:

```text
0x68
```

The most likely cause was that the module did not have soldered header pins. The loose temporary connection did not provide reliable electrical contact for the SDA and SCL communication lines.

## Temporary Connection Attempt

Loose header pins were placed between the MPU6050 and the breadboard.

Folded paper was used only as mechanical support to keep the module elevated and pressed against the pins.

This method successfully powered the module but was not reliable enough for I2C communication.

## Troubleshooting and Design Changes

* Confirmed that the red power LED only indicates power and not successful communication
* Checked that SDA and SCL were connected to GPIO 21 and GPIO 22
* Confirmed that SDA and SCL were not reversed
* Tested the module using an I2C scanner
* Avoided shaking or moving the unsoldered module
* Removed sudden-movement detection because the temporary connection was unsuitable for motion testing
* Renamed the project from a movement monitor to a tilt monitor
* Excluded the unreliable MPU6050 from the final Course 4 project

## Concepts Learned

* I2C communication
* SDA and SCL connections
* MPU6050 initialization
* Accelerometer readings
* Gyroscope readings
* Three-axis motion data
* Threshold-based tilt detection
* Non-blocking timing using `millis()`
* Function-based code organization
* Hardware fault diagnosis
* Difference between power and communication
* Importance of reliable soldered connections

## Testing Summary

| Test                    | Expected Result              | Actual Result         |
| ----------------------- | ---------------------------- | --------------------- |
| MPU6050 power test      | Red LED turns on             | Passed                |
| ESP32 initialization    | Sensor detected              | Failed                |
| I2C scanner             | Address `0x68` found         | Failed                |
| Accelerometer reading   | X, Y, and Z values displayed | Not completed         |
| Gyroscope reading       | X, Y, and Z values displayed | Not completed         |
| Tilt classification     | Orientation displayed        | Not physically tested |
| Source-code compilation | Code compiles successfully   | Completed             |

## Final Result

```text
Software: Completed
Tilt logic: Completed but not physically tested
millis() timing: Completed
Hardware power test: Passed
I2C communication test: Failed
Physical tilt test: Not completed
Likely cause: Unstable connection from unsoldered MPU6050 header pins
Course 4 integration: Excluded
Future use: Planned after soldering
```

## Course 4 Decision

The MPU6050 was excluded from the Course 4 Multi-Hazard Safety Controller because its temporary connection was not mechanically or electrically reliable.

The final project will prioritize stable components and consistent operation.

The MPU6050 may be reused later after its header pins are properly soldered, especially for future motion-recognition, gesture-classification, or TinyML projects.

## Demo Files

```text
main.ino
README-8.md
```

No successful Serial Monitor screenshot or physical demonstration video was recorded because the ESP32 could not establish I2C communication with the unsoldered MPU6050.

## Embedded Systems Relevance

This project demonstrates that embedded systems development includes both software implementation and hardware troubleshooting.

Although the sensor could not be physically tested, the project provided experience with I2C communication, motion-sensor programming, tilt-classification logic, non-blocking timing, and hardware fault isolation.

The decision to exclude an unreliable component from the final integrated system reflects an important engineering principle: system reliability is more important than increasing the number of components.
