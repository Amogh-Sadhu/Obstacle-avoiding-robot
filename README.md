# Requirements :

## Arduino UNO Board
![](https://csg.tinkercad.com/things/4dpskvBvwBl/t725.png?rev=1548363269550000000&s=&v=1&type=circuits)

The  **Arduino Uno**  is an [open-source](https://en.wikipedia.org/wiki/Open-source) [microcontroller board](https://en.wikipedia.org/wiki/Microcontroller_board) based on the [Microchip](https://en.wikipedia.org/wiki/Microchip_Technology)[ATmega328P](https://en.wikipedia.org/wiki/ATmega328P) microcontroller and developed by [Arduino.cc](https://en.wikipedia.org/wiki/Arduino).[[2]](https://en.wikipedia.org/wiki/Arduino_Uno#cite_note-2)[[3]](https://en.wikipedia.org/wiki/Arduino_Uno#cite_note-What_is_Arduino?-3) The board is equipped with sets of digital and analog [input/output](https://en.wikipedia.org/wiki/Input/output) (I/O) pins that may be interfaced to various [expansion boards](https://en.wikipedia.org/wiki/Expansion_board) (shields) and other circuits.[[1]](https://en.wikipedia.org/wiki/Arduino_Uno#cite_note-Makerspace-1) The board has 14 Digital pins, 6 Analog pins, and programmable with the [Arduino IDE](https://en.wikipedia.org/wiki/Arduino#Software) (Integrated Development Environment) via a type B [USB cable](https://en.wikipedia.org/wiki/USB_cable).[[4]](https://en.wikipedia.org/wiki/Arduino_Uno#cite_note-priceton-4) It can be powered by the USB cable or by an external [9-volt battery](https://en.wikipedia.org/wiki/9-volt_battery), though it accepts voltages between 7 and 20 volts.

The ATmega328 on the board comes preprogrammed with a [bootloader](https://en.wikipedia.org/wiki/Bootloader) that allows uploading new code to it without the use of an external hardware programmer.

 ### Technical Specifications

- [Microcontroller](https://en.wikipedia.org/wiki/Microcontroller): [Microchip](https://en.wikipedia.org/wiki/Microchip_Technology) [ATmega328P](https://en.wikipedia.org/wiki/ATmega328P)
- Operating Voltage: 5 Volts
- Input Voltage: 7 to 20 Volts
- Digital I/O Pins: 14 (of which 6 provide PWM output)
- Analog Input Pins: 6
- DC Current per I/O Pin: 20 mA
- DC Current for 3.3V Pin: 50 mA
- [Flash Memory](https://en.wikipedia.org/wiki/Flash_Memory): 32 KB of which 0.5 KB used by [bootloader](https://en.wikipedia.org/wiki/Booting#BOOT-LOADER)
- [SRAM](https://en.wikipedia.org/wiki/Static_random-access_memory): 2 KB
- [EEPROM](https://en.wikipedia.org/wiki/EEPROM): 1 KB
- Clock Speed: 16 MHz
- Length: 68.6 mm
- Width: 53.4 mm
- Weight: 25 g 

<br/>

## Arduino IDE and Programming


<img src="https://www.arduino.cc/wiki/6c27bc3a77245e1c8d4fe8abea8002ff/arduino.svg" width="30%">

The [**Arduino**](https://en.wikipedia.org/wiki/Arduino)** integrated development environment (**[**IDE**](https://en.wikipedia.org/wiki/Integrated_development_environment)**)** is a [cross-platform](https://en.wikipedia.org/wiki/Cross-platform)application (for [Windows](https://en.wikipedia.org/wiki/Windows), [macOS](https://en.wikipedia.org/wiki/MacOS), [Linux](https://en.wikipedia.org/wiki/Linux)) that is written in the programming language [Java](https://en.wikipedia.org/wiki/Java_(programming_language)). It is used to write and upload programs to Arduino compatible boards, but also, with the help of 3rd party cores, other vendor development boards.

The source code for the IDE is released under the [GNU General Public License](https://en.wikipedia.org/wiki/GNU_General_Public_License), version 2.[[3]](https://en.wikipedia.org/wiki/Arduino_IDE#cite_note-3) The Arduino IDE supports the languages [C](https://en.wikipedia.org/wiki/C_(programming_language)) and [C++](https://en.wikipedia.org/wiki/C%2B%2B) using special rules of code structuring.[[4]](https://en.wikipedia.org/wiki/Arduino_IDE#cite_note-4) The Arduino IDE supplies a [software library](https://en.wikipedia.org/wiki/Software_library) from the [Wiring](https://en.wikipedia.org/wiki/Wiring_(development_platform)) project, which provides many common input and output procedures.

The Arduino IDE employs the program _avrdude_ to convert the executable code into a text file in hexadecimal encoding that is loaded into the Arduino board by a loader program in the board&#39;s firmware.

<br/>

## L293D Motor Driver Shield
<img src="https://images-na.ssl-images-amazon.com/images/I/51EkEcUpKwL.jpg" width="100">


A motor driver IC is an integrated circuit chip which is usually used to control motors in autonomous robots. Motor driver ICs act as an interface between microprocessors in robots and the motors in the robot. The most commonly used motor driver IC&#39;s are from the L293 series such as L293D, L293NE, etc.

**Need for motor driver IC:**

Motor Driver ICs are primarily used in autonomous robotics only. Also most microprocessors operate at low voltages and require a small amount of current to operate while  the motors require a relatively higher voltages and current . Thus current cannot be supplied to the motors from the microprocessor. This is the primary need for the  motor driver IC.

**The L293D** is quadruple high-current half-H drivers.It is designed to provide bidirectional drive currents of up to 600-mA at voltages from 4.5 V to 36 V. Both devices are designed to drive inductive loads such as relays, solenoids, dc and bipolar stepping motors, as well as other high-current/high-voltage loads in positive-supply applications

- **2 connections for 5V &#39;hobby&#39; servos**  connected to the Arduino&#39;s high-resolution dedicated timer - no jitter!
- **Up to 4 bi-directional DC**  motors with individual 8-bit speed selection (so, about 0.5% resolution)
- **Up to 2 stepper motors**  (unipolar or bipolar) with single coil, double coil, interleaved or micro-stepping.
- 4 H-Bridges: L293D chipset provides 0.6A per bridge (1.2A peak) with thermal shutdown protection, 4.5V to 25V

The servo motors use the +5V of the Arduino board. The voltage regulator on the Arduino board could get hot. To avoid this, the newer Motor Shields have connection points for a separate +5V for the servo motors.

<br/>

## SG90 Mini Servo Motor
<img src="https://images-na.ssl-images-amazon.com/images/I/41FgATzSHlL._SX425_.jpg" width="70%">

It is tiny and lightweight with high output power. This servo can rotate approximately 180 degrees (90 in each direction), and works just like the standard kinds but smaller. You can use any servo code, hardware or library to control these servos .It comes with a 3 horns (arms) and hardware.

**Specifications**

- Operating voltage: 4.8 V (~5V)
- Operating speed: 0.1 s/60 degree
- Stall torque: 1.8 kgf·cm
- Dead band width: 10 µs
- Temperature range: 0 ºC – 55 ºC

<br/>

## Ultrasonic Sensor HC-SR04
<img src="https://images-na.ssl-images-amazon.com/images/I/51gMbHIEy4L.jpg" width="50%">

Ultrasonic ranging module HC - SR04 provides 2cm - 700cm non-contact measurement function, the ranging accuracy can reach to 3mm.Ensured stable signal within 5m, gradually faded signal outside 5m till disappearing at 7m position.
 The modules includes ultrasonic transmitters, receiver and control circuit. The basic principle of work:
 (1) Using IO trigger for at least 10us high level signal；
 (2) The Module automatically sends eight 40 kHz and detect whether there is a pulse signal back.
 (3) IF the signal back, through high level , time of high output IO duration is the time from sending ultrasonic to returning. Test distance = (high level time×velocity of sound (340M/S) / 2.


### Pin Function

**TRIG** : Trigger Pulse Input
**ECHO** : Echo Pulse Output
**GND** : Ground
**VCC** : 5V Supply

    NOTE: In India wires are RGB mode i.e. Red Green Black

### Red – Red wire signifies the phase in electric circuit

### Black – Black wires signifies neutral wire in electric circuit

### Green – Green wire stands for grounding/ earthing in electric circuit.

<br/>

## Connections
![](https://github.com/Amogh-Sadhu/Obstacle-avoiding-robot/blob/main/Connection%20.PNG?raw=true)

# Notes
 - Use the right power supply for the motors according to weight of your robot.
 - Attach batteries nearer to motors(because batteries are usually heavy)
 - Test the Servo from the above and calibrate the zero postion of servo of it is changed.
 - You can change certain parametrs in the code to improve it for your design such as delays and PWM frequency of the motors.

<br/>

## Helpful Side-Note
### Pulse-width modulation (PWM)

**Pulse width modulation**  ( **PWM** ), or  **pulse-duration modulation**  ( **PDM** ), is a method of reducing the average power delivered by an electrical signal, by effectively chopping it up into discrete parts. The average value of [voltage](https://en.wikipedia.org/wiki/Volt) (and [current](https://en.wikipedia.org/wiki/Electric_current)) fed to the [load](https://en.wikipedia.org/wiki/Electrical_load) is controlled by turning the switch between supply and load on and off at a fast rate.


### Time proportioning

Many digital circuits can generate PWM signals (e.g., many [microcontrollers](https://en.wikipedia.org/wiki/Microcontrollers) have PWM outputs). They normally use a [counter](https://en.wikipedia.org/wiki/Counter_(digital)) that increments periodically (it is connected directly or indirectly to the [clock](https://en.wikipedia.org/wiki/Clock_signal) of the circuit) and is reset at the end of every period of the PWM. When the counter value is more than the reference value, the PWM output changes state from high to low (or low to high).This technique is referred to as  **time proportioning,**  particularly as  **time-proportioning control** – which _proportion_ of a fixed cycle time is spent in the high state.
