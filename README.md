# SONAR Logger

## Overview

SONAR Logger is a project designed to capture and log the distance of obstacles using an ultrasonic sensor mounted on a servo motor. The system utilizes an Arduino Mega for control and data collection, with Simulink and Matlab for processing and logging data. The servo motor rotates from 0 to 180 degrees, and at each degree, the distance to obstacles is measured and logged.

## Hardware Requirements

- **Arduino Mega**
- **Ultrasonic Sensor**
- **Servo Motor**
- **Green Breadboard**
- **Jumper Wires**
- **Connector**

## Setup

<img height=300 alt="hardware_setup" src="https://github.com/dheerajkallakuri/SONAR_Logger/assets/23552796/bedf2551-790f-43e4-b85b-6abe5f259c4f">

## Software Requirements

- **Simulink**
- **Matlab**

## Description

The system setup includes:
1. A green breadboard on which the ultrasonic sensor is mounted.
2. The entire setup is mounted on a servo motor, controlled by the Arduino Mega.
3. The system detects two types of obstacles: a brown box and a black object.

### System Operation

1. **Servo Motor Control**: The servo motor rotates from 0 to 180 degrees.
2. **Distance Measurement**: At each degree, the ultrasonic sensor measures the distance to any obstacles.
3. **Data Logging**: The distance measurements, along with the servo angle and obstacle status, are saved in a CSV file.

### Simulink Model

The Simulink model comprises two main nodes:
- **Servo Motor Control Node**: Controls the movement of the servo motor.
- **Distance Measurement Node**: Collects distance data using the ultrasonic sensor.

<img width="500" alt="sim_model" src="https://github.com/dheerajkallakuri/SONAR_Logger/assets/23552796/0f8ad98e-0872-427e-8be0-53174d7bcc33">

**Blocks Used**:
- **Ultrasonic Block**: Measures distance in meters, converts it to centimeters, and displays the value.
- **Gain Block**: Converts distance from meters to centimeters.
- **Display Block**: Shows the distance in centimeters.
- **To String Block**: Converts distance value to a string.
- **If Block**: Checks if the distance is greater than 15 cm.
- **String Concatenate Block**: Concatenates angle, distance, and obstacle status into a single string.
- **Desired Shaft Angle Block**: Generates the desired angle for the servo motor.
- **Servo Motor Write Block**: Writes the desired angle to the servo motor.

### Data Processing

1. **Data Collection**: The Simulink model collects data for 5 seconds.
2. **Data Preprocessing**:
   - ASCII values are converted to characters.
   - Characters are converted to strings.
   - Strings are split into cells in a table using a semicolon delimiter.
   - Data types are converted to appropriate formats.
   - A table with headers 'Angle', 'Distance', and 'Status' is created.
   - Data is saved in a CSV file named `obstacleLog.csv`.

## How to Run the Project

1. **Connect the Hardware**:
   - Connect the ultrasonic sensor, servo motor, and Arduino Mega as described.
   - Ensure all connections are secure and correct.

2. **Run Simulink Model**:
   - Open `final_project.slx` in Simulink.
   - Ensure the model is correctly configured for your hardware setup.
   - Run the model for 5 seconds to collect data.

3. **Run Matlab Script**:
   - Open `SonarDataCollection.m` in Matlab.
   - Run the script to start the data collection process.
   - The script will preprocess the data and save it as `obstacleLog.csv`.

## Output

The CSV file `obstacleLog.csv` will contain the following columns:
- **Angle**: The angle of the servo motor in degrees.
- **Distance**: The measured distance to obstacles in centimeters.
- **Status**: The status indicating 'Obstacle' or 'No obstacle' based on the distance.

## Video Demonstration

For a visual demonstration of this project, please refer to the video linked below:

[Project Video Demonstration](https://youtu.be/tW3jClIxz8g)

[![Project Video Demonstration](https://img.youtube.com/vi/VDk1paHKaMc/0.jpg)](https://www.youtube.com/watch?v=VDk1paHKaMc)
