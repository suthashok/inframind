# Servo Radar Scanner – Design Notes

## Project Goal

The goal of this project is to simulate a basic radar scanning system using Arduino components. 
The idea is to build a small system that mechanically sweeps its environment, senses distances, and reports the data.

The project follows a simple data acquisition loop:

**Position → Sense → Report**

* Position the sensor at a specific angle using a servo motor
* Sense distance to any objects using an ultrasonic sensor
* Report the angle and averaged distance via Serial communication

---

## Problem Statement

In many robotics and automation applications, a system needs to map its surroundings to navigate or detect obstacles. A single fixed distance sensor only provides a narrow line of sight.

The challenge is not just moving a sensor. The challenge is acquiring stable, accurate readings while in motion and syncing mechanical position with sensor data.

---

## Components Used

* Arduino Uno
* Ultrasonic Sensor
* Servo Motor (Scanner Base)

---

## System Behavior

Under normal operation, the controller executes a 180-degree scanning sweep.

During the sweep operation:

* Servo increments its angle step-by-step from 0 to 180 degrees
* At each step, the ultrasonic sensor fires multiple pulses
* The system computes an average distance to reduce jitter and false readings
* Angle and distance pairs are sent over the Serial monitor

After completing the sweep:

* The system halts execution (enters an infinite loop) to prevent continuous uncontrolled spinning, completing a single comprehensive scan.

---

## Control Logic

The controller continuously loops through these high-level steps during the scan:

1. Positioning
   Servo moves to the target angle and waits.

2. Data Acquisition & Smoothing
   Sensor takes 5 consecutive readings and calculates the average distance.

3. Data Transmission
   The formatted result (Angle + Distance) is printed to the Serial port.

This design keeps data acquisition predictable and minimizes erroneous spikes in distance measurements.

---

## Design Thinking

This project intentionally focuses on data reliability and system integration instead of just component testing.

The objective is to think beyond:

"Move servo → read sensor"

and instead think:

"How can we ensure the data collected at each angle is accurate and free from noise?"

That mindset is very important for building real-world mapping robots, autonomous vehicles, and larger perception systems.

---

## Future Improvements

Possible extensions:

* Radar visualization UI on a connected PC (e.g., using Processing or Python)
* Continuous 360-degree scanning using a slip-ring and stepper motor
* 3D spatial mapping by adding a second servo for pan-and-tilt
* Object tracking and following (locking onto the closest detected object)
* Motion-triggered alerts when an object enters a specific proximity zone

---

## Notes

Current implementation performs a single 180-degree sweep, uses a 30ms timeout on the pulse to prevent freezing, and applies a 5-sample averaging filter for noise reduction.

These parameters are intentionally kept simple during initial development and can later be tuned for faster or smoother scanning based on real-world testing.
