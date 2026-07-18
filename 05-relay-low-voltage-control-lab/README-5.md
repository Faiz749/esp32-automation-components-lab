# Day 5: Relay Low-Voltage Control Lab

## Project Description

This project uses an ESP32 to control one channel of a relay module through commands entered in the Serial Monitor.

The user enters `1` to turn the relay on and `0` to turn it off. The program also controls an LED connected directly to the ESP32, which acts as a low-voltage load-state indicator.

The program remembers the relay’s previous state. If the same command is entered again, the relay is not switched unnecessarily. Instead, the Serial Monitor reports that the relay is already in the requested state.

The relay module uses active-low logic:

```text
GPIO LOW  → Relay ON
GPIO HIGH → Relay OFF
```

## Components Used

* ESP32 38-pin development board
* 4-channel relay module
* LED
* 220 Ω resistor
* Breadboard
* Jumper wires
* USB cable

## Wiring

### Relay Module

Only relay channel 1 was used.

```text
Relay VCC → ESP32 VIN/5V
Relay GND → ESP32 GND
Relay IN1 → ESP32 GPIO 26
```

The remaining relay input channels were not connected.

```text
IN2 → Not connected
IN3 → Not connected
IN4 → Not connected
```

### LED Load-State Indicator

```text
ESP32 GPIO 2 → 220 Ω resistor → LED anode
LED cathode  → ESP32 GND
```

The LED was controlled directly by the ESP32 and represented the intended state of a low-voltage load.

## Relay Logic

The relay module was confirmed to use active-low logic.

```text
GPIO HIGH → Relay OFF
GPIO LOW  → Relay ON
```

The system starts in the following state:

```text
Relay OFF
LED OFF
```

The available Serial Monitor commands are:

```text
1 → Relay ON and LED ON
0 → Relay OFF and LED OFF
```

## Concepts Learned

* Controlling a relay module using `digitalWrite()`
* Understanding active-low relay logic
* Keeping a relay safely off during startup
* Reading Serial Monitor input using `Serial.available()`
* Reading a character using `Serial.read()`
* Comparing character commands such as `'1'` and `'0'`
* Using functions to organize relay-control logic
* Remembering the previous relay state
* Avoiding unnecessary relay switching
* Ignoring newline and carriage-return characters
* Handling invalid Serial Monitor input
* Using `millis()` to check Serial input at a fixed interval
* Controlling a visual load-state indicator
* Following safe low-voltage relay-testing practices

## Serial Monitor Output

### Relay Turned On

```text
Turning Relay ON
RELAY Status: ON
LED Status  : ON
```

### Relay Turned Off

```text
Turning Relay OFF
RELAY Status: OFF
LED Status  : OFF
```

### Repeated Command

```text
Relay is already in the requested state
```

### Invalid Command

```text
Enter a valid choice
```

## Mistakes Fixed

* Corrected `Serial.read(RELAY_PIN)` to `Serial.read()` because `Serial.read()` does not accept a GPIO pin argument.
* Reset `Value_Entered` after processing each Serial command.
* Ignored newline and carriage-return characters sent by the Serial Monitor.
* Changed `Serial.print()` to `Serial.println()` so output messages appear on separate lines.
* Confirmed that the relay module uses active-low logic.
* Added previous-state comparison to prevent unnecessary repeated relay switching.
* Kept the relay and LED off during system startup.
* Used only one relay channel for the first relay-control lab.

## Hardware Limitation

The relay screw terminals were not used because a suitable screwdriver was unavailable.

Relay operation was verified using:

* The onboard relay-channel indicator light
* The relay’s clicking sound
* Serial Monitor output
* A separate ESP32-controlled LED representing the low-voltage load state

The LED was not switched through the relay contacts. It was controlled directly by GPIO 2.

The `COM`, `NO`, and `NC` terminals will be tested later with a safe low-voltage load after obtaining the correct screwdriver.

## Safety Notes

* No AC mains voltage was used.
* No 220 V appliance was connected.
* No wall socket, fan, AC bulb, or extension board was used.
* Only the relay-control side and a separate low-voltage LED indicator were tested.
* The relay was kept off during ESP32 startup.
* The ESP32 and relay module shared a common ground.
* Future relay-contact testing will use only a safe low-voltage load.

## Demo Files

* `relay-control-photo.jpeg`
* `relay-control-screenshot.png`
* `relay-control-demo.mp4`

## Embedded-Systems Relevance

Relay modules allow a low-power microcontroller signal to control a separate electrical circuit.

This lab demonstrates how an ESP32 can safely control a relay channel, handle active-low logic, accept user commands through the Serial Monitor, and prevent unnecessary repeated switching.

The project also demonstrates safe startup design and accurate documentation of hardware limitations, both of which are important skills in embedded-systems development.
