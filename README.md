# Alcohol-Detection-Based-Engine-Locking-System-Using-ESP32
📖 Overview

This project presents an Alcohol Detection Based Engine Locking System using ESP32. The system is designed to enhance vehicle safety by preventing engine ignition when alcohol is detected.

An alcohol gas sensor monitors the presence of alcohol vapors, and the ESP32 microcontroller processes the sensor data to control a relay that enables or disables the ignition load.

🎯 Objective

To develop a smart vehicle safety mechanism that:

Detects alcohol presence using a gas sensor

Prevents engine ignition when alcohol level exceeds a predefined threshold

Provides an alert using a buzzer

🧰 Components Used

ESP32 Development Board

4-Pin Alcohol Gas Sensor

5V SPDT Relay

BC547 NPN Transistor

1N4007 Flyback Diode

10kΩ Resistor (Sensor Load Resistor)

1kΩ Resistor (Transistor Base Resistor)

5V Active Buzzer

12V Battery

Buck Converter (12V to 5V)

⚙️ System Architecture

12V Battery → Buck Converter → 5V Supply

Alcohol Sensor → ESP32 (ADC Input)

ESP32 → Transistor Driver → Relay

Relay → Ignition Load

Buzzer → Alert Output

🔌 Circuit Description

The 12V battery supply is stepped down to 5V using a buck converter.

The alcohol sensor heater operates at 5V.

A 10kΩ resistor forms a voltage divider to generate analog output from the sensor.

The analog output is connected to ESP32 GPIO34 (ADC).

ESP32 processes the sensor value and compares it with a predefined threshold.

A BC547 transistor drives the relay coil.

A flyback diode protects the transistor from back EMF.

The relay controls the ignition load.

A 5V active buzzer provides an audible alert when alcohol is detected.

🔄 Working Principle

The alcohol sensor detects alcohol vapors.

The sensor resistance changes according to alcohol concentration.

The ESP32 reads the analog voltage from the sensor.

If alcohol level exceeds the threshold:

Relay is turned OFF

Ignition load is disconnected

Buzzer is activated

If alcohol level is below threshold:

Relay remains ON

Ignition system operates normally

📌 Pin Configuration
Alcohol Sensor

Pin 1 → 5V (Heater)

Pin 4 → GND (Heater)

Pin 2 → 5V

Pin 5 → 10kΩ to GND and GPIO34 (ADC Output)

Relay Driver

GPIO23 → 1kΩ → BC547 Base

BC547 Collector → Relay Coil –

Relay Coil + → 5V

Diode connected across relay coil

Buzzer

GPIO25 → Buzzer +

Buzzer – → GND

🛠 How to Use

Assemble the circuit as per the schematic diagram.

Upload the firmware to the ESP32.

Power the system using a 12V supply.

Allow the sensor to warm up (~30 seconds).

Test the system by introducing alcohol vapors near the sensor.

🚀 Future Improvements

GSM module for SMS alerts

GPS tracking integration

Mobile application monitoring

LCD display for alcohol level indication

Calibration for improved accuracy
