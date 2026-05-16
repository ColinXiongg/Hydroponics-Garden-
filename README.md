# ESP32 Hydroponic Garden System

## Project Overview

This project is a compact NFT (Nutrient Film Technique) hydroponic garden system controlled by an ESP32 microcontroller. The system monitors electrical conductivity (EC) levels in the nutrient reservoir and automatically activates nutrient dosing pumps to maintain nutrient concentration within a target range.

The project was developed as part of an engineering design project focused on automation, embedded systems, sensing, and closed-loop control.

---

## Features

- ESP32-based control system
- EC sensor monitoring
- Automatic nutrient dosing
- Peristaltic pump control
- Closed-loop nutrient management
- Real-time sensor reading
- Compact hydroponic NFT design
- Automated nutrient adjustment logic

---

## System Overview

The ESP32 continuously reads EC sensor values from the nutrient reservoir using an analog EC sensor module. When the EC level drops below a target threshold, the system activates nutrient dosing pumps through an L298N motor driver.

A mixing delay is implemented after dosing to allow the nutrients to properly circulate before taking another sensor reading. This creates a simple closed-loop nutrient control system for maintaining hydroponic solution quality.

---

## Hardware Used

- ESP32 WROOM-32D
- EC sensor module
- Peristaltic dosing pumps
- L298N motor driver
- Hydroponic reservoir
- Tubing and fittings
- Power supply / battery pack
- NFT hydroponic channels

---

## Software Used

- Arduino IDE
- ESP32 Arduino framework
- Git
- GitHub

---

## Code Functionality

The program performs the following tasks:

1. Reads analog EC sensor data
2. Converts sensor values into EC measurements
3. Compares EC values to a target threshold
4. Activates nutrient dosing pumps when EC is too low
5. Implements delays for nutrient mixing
6. Repeats monitoring continuously

---

## Applications

This project demonstrates concepts related to:

- Embedded systems
- Automation
- Sensor integration
- Closed-loop control systems
- Hydroponic agriculture
- Smart agriculture systems
- IoT-based monitoring systems

---

## Future Improvements

Potential future improvements include:

- pH sensor integration
- WiFi monitoring dashboard
- Mobile app integration
- Data logging
- Improved EC calibration
- PID control implementation
- LCD/OLED status display
- Automated lighting control
- Machine learning based nutrient optimization

---

## Project Status

Current version includes:

- Functional EC monitoring
- Automated nutrient dosing
- Basic closed-loop control implementation

Future revisions will focus on improving reliability, calibration accuracy, and system scalability.

---

## Repository Structure

```text
FULL_HYDROPONIC_CODE/
│
├── FULL_HYDROPONIC_CODE.ino
└── README.md
