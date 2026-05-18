# Smart Parking Barrier System – Design Notes

## Project Goal

The goal of this project is to simulate an automatic parking barrier system using Arduino components. 
Instead of treating individual components separately, the idea is to build a small system that senses its environment, makes a decision, and performs an action.

The project follows a simple robotics loop:

**Sense → Decide → Act**

* Sense vehicle presence using an ultrasonic sensor (incoming Car/Bike)
* Decide whether the vehicle is close enough
* Act by controlling a barrier arm and status indicators using LEDs

---

## Problem Statement

In many parking areas, access gates need to react automatically when a vehicle approaches. The system should allow entry without manual intervention while also preventing unnecessary gate movement.

The challenge is not opening a gate. The challenge is creating predictable behavior and handling state transitions safely.

---

## Components Used

* Arduino Uno
* Ultrasonic Sensor
* Servo Motor (Barrier Arm)
* LEDs (Status Indicators)
* Buzzer

---

## System Behavior

Under normal operation, the controller continuously measures distance using the ultrasonic sensor.

If no object is detected within the configured threshold:

* Barrier remains closed
* System stays in monitoring mode
* LED Red (when barrier is closed)

When an object moves within the threshold distance:

* Vehicle presence is detected
* Barrier arm opens
* Entry signal becomes active (LED Green)

After a fixed duration or after the vehicle passes:

* Barrier closes again
* System returns to monitoring mode
* LED Red

---

## Control Logic

The controller continuously loops through three high-level states:

1. Monitoring
   System checks for objects in front of the barrier

2. Vehicle Detected
   Distance threshold condition becomes true

3. Barrier Active
   Gate opens and system waits before returning

This design keeps behavior predictable and makes future modifications easier.

---

## Design Thinking

This project intentionally focuses on system behavior instead of component testing.

The objective is to think beyond:

"Read sensor → move servo"

and instead think:

"What state is the system currently in and what should happen next?"

That mindset is very important for building real world robots and larger automation systems.

---

## Future Improvements

Possible extensions:

* Check & Verify Company Issued Parking Badges (No Authotised Access, ex. RFID based access control)
* Vehicle counting & LCD display for slot availability
* ML model to detect objext type and register it
* FaceID recognition for registered users to avoid Unauthorised Access
* Integrating parking payment along with auto barrier opening (Fastag Style)

---

## Notes

Current implementation uses fixed thresholds and timing values.

These values are intentionally kept simple during initial development and can later be tuned based on real-world testing.
