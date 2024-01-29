# PIC Microcontroller-Based Home Alarm System

## Description
This project is a home alarm system that uses a PIC microcontroller and SIM900 GSM module to detect motion and notify the user via phone call. The system is designed to be modular, with a main board and up to four motion sensor boards that can be placed in different rooms. When motion is detected, the system automatically calls a predefined phone number, allowing the user to listen in and assess the situation.

## Features
- Modular design with a main board and multiple sensor boards.
- Motion detection using PIR sensors.
- Automatic phone call notification using SIM900 GSM module.
- Ability to listen to live audio from the triggered location.
- Custom-designed PCBs for main and sensor boards.
- LED indicators for system status and alerts.
- Low power consumption design suitable for continuous operation.

## Hardware Requirements
- PIC16F877A microcontroller.
- SIM900 GSM module.
- PIR motion sensors.
- USB power supply for each board.
- Custom-designed PCBs for main and sensor boards.
- PICkit 3 programmer/debugger for firmware upload.

## Software Requirements
- MPLAB X IDE version 6.15.

## Installation
1. Assemble the main board and sensor boards.
2. Program the PIC16F877A microcontrollers using MPLAB X IDE and PICkit 3.
3. Attach the programmed PICs to their respective boards.
4. Connect each board to a USB power supply.
5. Insert a SIM card without a PIN into the SIM900A module on the main board.
6. Place the motion sensor boards in desired rooms and plug them in.
7. Synchronize each sensor board with the main board using a button on the boards.

## Usage
- Configure the GSM module with the user's phone number.
- Place sensor boards in different rooms and link them to the main board.
- Adjust sensitivity and alarm settings as needed.
- Receive automatic phone calls when motion is detected and listen to the environment.

## Contributing
Contributions to the project are welcome. This can include adding new features, optimizing the design, or fixing bugs. Please read the contributing guidelines before making a contribution.
