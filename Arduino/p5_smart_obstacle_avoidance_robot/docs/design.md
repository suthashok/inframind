# Obstacle Avoidance Robot – Design Notes

## Project Goal

The goal of this project is to rebuild an existing robot platform (Atmega 8) using Arduino Uno as the new controller (brain) and implement autonomous obstacle avoidance behavior.

Instead of creating a robot from a fresh kit, the idea is to reuse an old robot chassis, understand its hardware, and replace the original control logic with a new system.

The objective is not only to make the robot move, but also to understand how a real robotic system is assembled and controlled.

This project follows a simple robotics cycle:

Sense → Decide → Act

---

## Background

An old robot platform with motors, chassis, motor driver hardware, and sensors was available from a previous build.

The original system used an ATmega8 based controller board.

Rather than discarding the platform, the decision was made to reuse the existing hardware and replace only the control layer.

The robot body remains the same.

Only the brain changes.

---

## Problem Statement

A mobile robot operating in an unknown environment should be able to move independently and react when obstacles appear in its path.

The challenge is not detecting an obstacle.

The challenge is deciding:

- Should the robot stop?
- Should it turn?
- Which direction is safer?
- When should it resume movement?

These decisions create robot behavior.

---

## Components Used

Reused Components:

- Existing robot chassis
- DC motors
- Wheels
- L293 motor driver
- Battery holder
- Existing frame structure

New Components:

- Arduino Uno
- Ultrasonic Sensor
- Servo Motor
- Jumper wires

---

## System Behavior

Under normal operation:

- Robot moves forward continuously
- Ultrasonic sensor monitors distance

When an obstacle enters the threshold range:

- Robot stops movement
- Sensor scans surrounding area
- Distance measurements are collected

Based on the measurements:

- Robot selects a better direction
- Performs turn operation
- Resumes forward movement

If no suitable direction is available:

- Robot reverses briefly
- Attempts another scan

---

## High-Level Control Logic

The robot operates using a simple state-based behavior model:

1. Move Forward

2. Detect Obstacle

3. Stop Robot

4. Scan Left and Right

5. Select Direction

6. Turn

7. Resume Movement

This keeps system behavior predictable and easier to modify later.

---

## Design Thinking

This project intentionally focuses on robot behavior rather than component testing.

The goal is to move beyond:

"Read sensor and stop motor"

towards:

"What information does the robot have and what action should it take?"

That small shift is important.

Robots are not collections of sensors.

Robots are systems that continuously observe, decide, and react.

---

## Future Improvements

Possible future extensions:

- Dynamic obstacle mapping
- Multiple ultrasonic sensors
- PID controlled movement
- Wheel encoder feedback
- Bluetooth control mode
- Camera based navigation
- ROS integration

---

## Notes

Current implementation uses fixed distance thresholds and simple decision rules.

The behavior is intentionally kept simple during the initial version.

Future versions can gradually move toward more autonomous decision making.