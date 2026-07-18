# Day 4: Potentiometer-Controlled Servo Safety Gate

## Project Description

This project uses an SG90 servo motor, a potentiometer, and an ESP32 to simulate a manually controlled safety gate.

The potentiometer controls the servo angle in real time. The ESP32 reads the potentiometer value and maps it from the ADC range of `0–4095` to a safe servo range of `10°–170°`. The servo then moves to the calculated angle.

The Serial Monitor displays the potentiometer value, servo angle, and gate position every 500 milliseconds.

## Components Used

* ESP32 38-pin development board
* SG90 servo motor
* Potentiometer module
* Breadboard
* Jumper wires
* USB cable
* External 5V power supply, if required

## Wiring

### Potentiometer

```text
Potentiometer VCC → ESP32 3.3V
Potentiometer GND → ESP32 GND
Potentiometer OUT → ESP32 GPIO 34
```

### Servo Motor

```text
Servo signal wire → ESP32 GPIO 18
Servo red wire → 5V power supply
Servo brown/black wire → GND
ESP32 GND → Servo power supply GND
```

## Gate Positions

```text
Servo angle 10°–60° → CLOSED
Servo angle 61°–120° → HALF OPEN
Servo angle 121°–170° → OPEN
```

## How It Works

1. The ESP32 reads the potentiometer value using `analogRead()`.
2. The potentiometer produces an ADC value between `0` and `4095`.
3. The `map()` function converts the ADC value to a servo angle between `10°` and `170°`.
4. The ESP32 sends the calculated angle to the servo motor.
5. The servo position is classified as `CLOSED`, `HALF OPEN`, or `OPEN`.
6. Every 500 milliseconds, the Serial Monitor displays the current readings and gate position.

## Concepts Learned

* Controlling an SG90 servo motor with an ESP32
* Reading a potentiometer using `analogRead()`
* Mapping ADC values using `map()`
* Converting the ADC range of `0–4095` to an angle range of `10°–170°`
* Using safe servo angle limits
* Starting a servo at a known position
* Classifying the gate position as `CLOSED`, `HALF OPEN`, or `OPEN`
* Organizing a program using functions
* Using `millis()` for non-blocking Serial Monitor timing
* Updating `previousTime` correctly
* Printing sensor values and system states to the Serial Monitor
* Understanding the importance of a common ground

## Mistakes Fixed

* Added `previousTime = currentTime` inside the `millis()` timing condition.
* Replaced the timing interval with a constant value.
* Set the servo startup position to `90°`.
* Limited the servo range to `10°–170°` instead of using the full `0°–180°` range.
* Used `analogRead()` to read the potentiometer value.
* Used `map()` to convert the potentiometer value into a servo angle.
* Added separate functions for displaying readings and identifying the gate position.
* Added separators to improve Serial Monitor readability.

## Demo Files

* `servo-gate-photo.jpeg`
* `servo-gate-screenshot.png`
* `servo-gate-demo.mp4`

## Embedded Systems Relevance

Servo motors are commonly used in robotic arms, smart locks, gates, vents, valves, and other automated mechanical systems.

This project demonstrates how an analog input can be converted into physical movement. It also shows how an embedded controller can read user input, calculate an output position, control an actuator, and report the system state in real time.
