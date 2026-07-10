## Project 1: Traffic Signal Lights Simulation

---

## What This Project Does

This project starts with basic building blocks of robotics and aims to help users complete traffic signal light automation tasks:

1. **Traffic Signal Lights** - Simulating a real-world traffic signal system with automated light sequencing
2. **Hardware Integration** - Learning to control LED outputs with Arduino microcontrollers
3. **State Management** - Understanding timing and control flow for sequential operations

---

## Problem

**What is this robot trying to do?**

The goal of this project is to simulate a real-world traffic signal system that automatically cycles through Red → Yellow → Green light sequences with appropriate timing intervals. 
This teaches fundamental concepts of:
- Digital output control
- Time-based state transitions
- Automation logic
- Hardware-software integration

**Real-world Application:**
Automating traffic signals at intersections to manage vehicle and pedestrian flow safely and efficiently for one path.

---

## Hardware

**Arduino Uno**

**Components Used:**
- 3× LEDs (Red, Yellow, Green)
- 3× 220Ω Resistors (current limiting)
- 1× Breadboard
- Jumper wires
- USB cable for programming

---

## Design Decisions

1. **LED Pin Assignment:**
   - Red LED → Digital Pin 8
   - Yellow LED → Digital Pin 9
   - Green LED → Digital Pin 10
   - *Reasoning:* Grouped pins for easier code management and future expansion

2. **Timing Sequence:**
   - Green: 5 seconds (pedestrian crossing time + vehicle movement)
   - Yellow: 2 seconds (warning period for vehicles)
   - Red: 7 seconds (cross-traffic movement time)
   - *Reasoning:* Realistic timing mimics standard traffic signals

3. **Code Structure:**
   - Used functions for each light state to maintain modularity
   - Simple `loop()` structure for continuous cycling
   - *Reasoning:* Easy to understand, modify, and scale

4. **No External Libraries:**
   - Only using Arduino core functions (`digitalWrite()`, `delay()`)
   - *Reasoning:* Keeps project lightweight and beginner-friendly

---

## Lessons Learned

1. **Digital Logic & Control:**
   - Understanding HIGH/LOW states and their mapping to physical outputs
   - Importance of proper current limiting with resistors to protect LEDs

2. **Timing & Synchronization:**
   - Using `delay()` for simple sequential timing works for basic projects
   - Learned the limitations of blocking delays for more complex multi-task scenarios

3. **Hardware-Software Integration:**
   - Real-world timing differs from simulation; accounted for startup/shutdown delays
   - Proper voltage management is critical for LED longevity

4. **Modular Code Design:**
   - Breaking down traffic signal logic into separate functions improves readability
   - Easy to test individual states independently

5. **Scalability Considerations:**
   - This simple design can be extended with:
     - Multiple intersections (using more pins or multiplexing)
     - Sensor inputs (traffic detection, pedestrian buttons)
     - Real-time clock for adaptive timing
     - IoT connectivity for centralized traffic management

---

**Your suggestions are most welcome to improve this repo!**
