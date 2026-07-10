# 2. Traffic Signal Lights Simulation - Design Document

## Problem

This project simulates a real-world traffic signal system using an Arduino microcontroller. The goal is to:

- **Control multiple LED lights** (Red, Yellow, Green) to mimic standard traffic signals
- **Implement timing sequences** that reflect real traffic signal patterns
- **Handle state transitions** smoothly and predictably
- **Provide an educational foundation** for understanding embedded systems, timing control, and hardware interfacing

The advanced version builds upon the basic traffic signal by potentially adding features like:
- Pedestrian crossing signals
- Adaptive timing based on conditions
- Multiple intersection coordination
- Emergency vehicle override capabilities

---

## Hardware

**Primary Component:**
- **Arduino Uno** - Microcontroller for logic and control

**Required Components:**
- 3x LEDs (Red, Yellow, Green)
- 3x 220Ω Resistors (current limiting for LEDs)
- Breadboard and jumper wires
- USB cable for programming

**Optional Enhancements:**
- Push buttons for pedestrian crossing
- Sound buzzer for alerts
- 7-segment display for timing feedback

---

## Design Decisions

### 1. **State Machine Approach**
- Implemented using discrete states: `RED`, `GREEN`, `YELLOW`
- Each state has a defined duration and transition rules
- Clear separation of concerns for easier maintenance and testing

### 2. **Timing Configuration**
- **Red Light Duration:** 30 seconds (standard cycle)
- **Green Light Duration:** 25 seconds (allowing traffic flow)
- **Yellow Light Duration:** 5 seconds (warning period)
- Configurable via constants for different scenarios

### 3. **Pin Assignment**
- Red LED on Digital Pin 13
- Yellow LED on Digital Pin 12
- Green LED on Digital Pin 11
- *(Adjust based on your actual wiring)*

### 4. **Non-blocking Implementation**
- Used `millis()` instead of `delay()` to avoid blocking the main loop
- Allows for responsive state transitions and future sensor integration

### 5. **Modular Code Structure**
- Separate functions for LED control, state management, and timing
- Easy to extend with additional features (pedestrian crossing, sensors)

---

## Lessons Learned

### 1. **Timing Precision**
- Arduino's `millis()` function provides better timing accuracy than `delay()`
- Non-blocking approach essential for responsive systems

### 2. **Current Management**
- **Resistor selection is critical** - Improper values can damage LEDs or Arduino pins
- Standard 220Ω resistors work well for typical 5mm LEDs on 5V Arduino

### 3. **Real-World Complexity**
- Traffic signals have many edge cases (emergency vehicles, pedestrians, weather)
- Starting with a simple state machine makes scaling easier

### 4. **Testing and Validation**
- Testing timing sequences manually is tedious - consider adding a speed-up mode for testing
- Serial output for debugging state transitions is invaluable

### 5. **Hardware Reliability**
- Always use breadboards with good contact points
- Loose connections can cause intermittent failures that are hard to debug

### 6. **Code Organization**
- Defining magic numbers as named constants improves readability
- Separating concerns (timing, control, UI) from the start pays off later

---

## Future Enhancements

- [ ] Add pedestrian crossing button with dedicated signal
- [ ] Implement adaptive timing based on traffic sensors
- [ ] Add LCD/OLED display showing current state and remaining time
- [ ] Create multi-intersection coordination logic
- [ ] Add emergency vehicle detection and override
- [ ] Build a web-based simulator for testing sequences
