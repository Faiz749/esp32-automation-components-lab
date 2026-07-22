# Day 6: PIR Security Alert Monitor

## Project Description

This project was designed to use an HC-SR501 PIR motion sensor with an ESP32 to detect human movement.

The program includes a 30-second non-blocking warm-up period using `millis()`. After the warm-up period, the ESP32 reads the PIR sensor every 100 milliseconds.

When motion is detected, the intended system behavior is:

```text
LED → ON
Buzzer → ON
Status → MOTION DETECTED
```

When no motion is detected, the intended behavior is:

```text
LED → OFF
Buzzer → OFF
Status → NO MOTION
```

The program only prints information when the sensor state changes, which avoids repeating the same message continuously in the Serial Monitor.

During hardware testing, the PIR sensor did not work consistently. Most of the time, the sensor stayed at value `0` and did not respond to movement.

When I shook the module or moved it sharply closer to me, it sometimes produced a signal for only a few milliseconds before returning to `0`.

This was not normal PIR sensor behavior, so the sensor was considered faulty or unreliable.

The ESP32 GPIO pins and the digital-input code were tested separately and worked correctly. Because of this, the problem was most likely caused by the PIR sensor and not the ESP32 code.

## Components Used

* ESP32 38-pin board
* HC-SR501 PIR motion sensor
* LED
* 220 Ω resistor
* Buzzer
* Breadboard
* Jumper wires
* USB cable

## Wiring

### PIR Sensor

```text
PIR VCC → ESP32 VIN/5V
PIR OUT → ESP32 GPIO 18
PIR GND → ESP32 GND
```

The PIR sensor was powered from the ESP32 VIN/5V pin.

### LED

```text
ESP32 GPIO 2 → 220 Ω resistor → LED anode
LED cathode → ESP32 GND
```

### Buzzer

```text
Buzzer positive pin → ESP32 GPIO 4
Buzzer negative pin → ESP32 GND
```

## Intended Sensor Logic

The expected PIR sensor behavior was:

```text
PIR Value 1 → MOTION DETECTED
PIR Value 0 → NO MOTION
```

The intended output behavior was:

```text
MOTION DETECTED → LED ON and buzzer ON
NO MOTION → LED OFF and buzzer OFF
```

## Concepts Learned

* Reading a digital sensor using `digitalRead()`
* Controlling an LED using `digitalWrite()`
* Controlling a buzzer using `digitalWrite()`
* Using `millis()` for a non-blocking warm-up period
* Using `millis()` for regular sensor sampling
* Comparing the current and previous sensor states
* Printing messages only when the state changes
* Dividing the program into simple functions
* Testing ESP32 GPIO pins separately
* Separating a hardware problem from a software problem
* Recognizing unstable sensor behavior
* Documenting an unsuccessful test honestly

## Intended Output

### Startup

```text
PIR Security Alert Monitor
Sensor warming up...
System is ready
```

### No Motion

```text
-----------------------------------
Status: NO MOTION
PIR Value: 0
LED: OFF
BUZZER: OFF
```

### Motion Detected

```text
-----------------------------------
Status: MOTION DETECTED
PIR Value: 1
LED: ON
BUZZER: ON
```

## GPIO Verification

The ESP32 GPIO input pins and digital-input code were tested separately from the PIR sensor.

GPIO 34 and GPIO 27 produced the expected results:

```text
GPIO connected to GND → Digital value 0
GPIO connected to 3.3V → Digital value 1
```

The 3.3V supply was used only for directly testing the ESP32 GPIO inputs.

The PIR sensor itself was powered from the ESP32 VIN/5V pin.

No 5V signal was connected directly to an ESP32 GPIO input.

This test confirmed that:

* The ESP32 was working correctly.
* The tested GPIO input pins were working correctly.
* The digital-input code was reading `HIGH` and `LOW` correctly.
* The constant PIR value was not caused by the ESP32 code.

## PIR Sensor Test Result

The PIR sensor did not respond reliably during the motion-detection test.

Different GPIO pins, jumper wires, wiring arrangements, and test programs were tried. The sensor was also given enough time to complete its warm-up period.

Even after these tests, the sensor usually stayed at value `0` and did not detect normal movement in front of it.

When I shook the sensor module or moved it sharply closer to me, it sometimes switched on for only a few milliseconds and then immediately returned to `0`.

A working PIR sensor should detect movement in front of it and keep its output active for a noticeable amount of time. It should not need to be physically shaken or moved sharply.

Because the signal was extremely brief and inconsistent, it could not be used as a reliable motion-detection input.

The PIR sensor was therefore considered faulty or unsuitable for the project.

The final motion-detection test could not be completed because of the sensor, not because of an error in the ESP32 code.

## Troubleshooting Performed

The following troubleshooting steps were completed:

* Checked the PIR sensor wiring
* Confirmed that PIR VCC was connected to ESP32 VIN/5V
* Confirmed that PIR GND was connected to ESP32 GND
* Tried different ESP32 GPIO input pins
* Tried different jumper wires
* Checked the breadboard connections
* Tested different sensor-reading programs
* Allowed the PIR sensor to complete its warm-up period
* Tested normal movement in front of the sensor
* Tested the ESP32 GPIO pins separately using GND and 3.3V
* Confirmed that the ESP32 correctly read known `LOW` and `HIGH` signals
* Observed that the PIR only produced a very brief signal when physically moved

## Engineering Outcome

Although the PIR sensor test was unsuccessful, the project still demonstrated useful embedded-systems troubleshooting.

The ESP32 code and GPIO inputs were tested separately, which helped show that the main problem was with the PIR sensor.

The test also showed the importance of checking whether a sensor output is stable and repeatable instead of assuming that any brief signal means the sensor is working.

The PIR sensor will not be used in Course 4 unless it is replaced with a verified working module.

## Mistakes Fixed

* Replaced the blocking warm-up delay with a 30-second `millis()` timer
* Added a 100-millisecond sensor-reading interval
* Added previous-state checking to prevent repeated Serial Monitor messages
* Corrected the function name from `sensor_funciton` to `sensor_function`
* Used `HIGH` and `LOW` for clearer digital logic
* Controlled the LED and buzzer before printing their states
* Verified the ESP32 GPIO pins separately from the PIR sensor
* Tried different GPIO pins, jumper wires, and wiring arrangements
* Confirmed that the PIR sensor was powered from VIN/5V
* Used 3.3V only for direct ESP32 GPIO verification
* Identified that the brief millisecond signals were not normal PIR behavior

## Hardware Limitation

The project could not demonstrate reliable motion detection because the available HC-SR501 PIR sensor did not work correctly.

The sensor normally stayed at value `0` and did not detect movement.

It only produced a very brief signal when the module was shaken or moved sharply, which was not stable or valid motion detection.

The code is still complete and can be tested later with a replacement PIR sensor.

For a future project, a working IR obstacle sensor can be used if a reliable PIR sensor is not available.

## Safety Notes

* The PIR sensor VCC pin was connected to the ESP32 VIN/5V supply.
* The PIR output pin was connected to an ESP32 GPIO input.
* Only 3.3V was applied directly during the separate GPIO verification test.
* No 5V signal was connected directly to an ESP32 GPIO pin.
* Wiring changes were made with power disconnected.
* The LED was connected through a 220 Ω resistor.
* The unreliable PIR sensor will not be used again unless it is replaced or properly verified.

## Test Results

| Test                     | Expected Result                   | Actual Result                          |
| ------------------------ | --------------------------------- | -------------------------------------- |
| GPIO connected to GND    | Digital value `0`                 | Passed                                 |
| GPIO connected to 3.3V   | Digital value `1`                 | Passed                                 |
| ESP32 digital-input code | Correct input reading             | Passed                                 |
| PIR sensor warm-up       | Sensor becomes stable             | Failed                                 |
| Motion in front of PIR   | Output changes reliably           | Failed                                 |
| Different GPIO input     | PIR output changes correctly      | Failed                                 |
| Different jumper wires   | Stable sensor output              | Failed                                 |
| PIR output stability     | Consistent `HIGH` or `LOW` signal | Failed                                 |
| Sensor moved sharply     | No false response                 | Failed — brief signal for milliseconds |

## Demo Files

* Circuit photo
* Serial Monitor screenshot showing PIR value `0`

No demo video was recorded because the PIR sensor did not detect movement reliably.

## Embedded Systems Relevance

Embedded-systems development does not always result in a successful hardware test.

This project shows how to test software separately, verify GPIO input behavior, identify a likely hardware problem, and record the results honestly.

Even though the PIR sensor did not work, the troubleshooting process was still useful because it helped confirm that the ESP32 and the digital-input code were functioning correctly.
