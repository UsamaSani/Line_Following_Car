# Line-Following Car with EDIVO Board and Arduino Uno

This project is a guide for building a line-following car using the EDIVO Board by EDVON and an Arduino Uno-based microcontroller. The car is designed to autonomously track lines on the ground using infrared sensors and motors. This README provides step-by-step instructions for assembling the hardware components, uploading the code, and accessing EDIVO Board's motor pins via the corresponding digital pins on the Arduino Uno.

## Hardware Requirements

- EDIVO Board by EDVON
- Infrared sensors
- Motors
- Chassis and wheels
- Jumper wires
- Power source (battery pack or power supply)

## Assembly Instructions

1. **Assemble the Chassis:** Attach motors and wheels to the chassis according to the manufacturer's instructions.

2. **Mount Sensors:** Install infrared sensors on the front of the chassis. Ensure they are positioned to detect lines on the ground.

3. **Connect Motors to Motor Driver:** Use jumper wires to connect the motors to the motor driver. Refer to the motor driver datasheet for pinout details.

4. **Connect Sensors to EDIVO Board:** Wire the infrared sensors to the EDIVO Board's sensor input pins. Refer to the EDIVO Board documentation for pin mappings.

5. **Power Supply:** Connect a suitable power source to the EDIVO Board and the motor driver. Ensure the voltage is within the operating range of all components.

## Uploading the Code

1. Clone or download the code repository to your local machine.

2. Open the Arduino IDE and load the provided Arduino sketch.

3. Verify and upload the sketch to the Arduino Uno board.

## Accessing EDIVO Board's Motor Pins

The EDIVO Board's motor pins can be controlled using the corresponding digital pins on the Arduino Uno. Here's the pin configuration:

- **Left Motor:**
  - Enable Pin: `LM_EN` (PWM) - Connected to pin 2 on the Arduino Uno
  - Input 1: `LM_IN1` - Connected to pin 3 on the Arduino Uno
  - Input 2: `LM_IN2` - Connected to pin 4 on the Arduino Uno

- **Right Motor:**
  - Enable Pin: `RM_EN` (PWM) - Connected to pin 5 on the Arduino Uno
  - Input 1: `RM_IN1` - Connected to pin 6 on the Arduino Uno
  - Input 2: `RM_IN2` - Connected to pin 7 on the Arduino Uno

These pins can be controlled using digital output functions such as `digitalWrite()` to control the direction and speed of the motors.
