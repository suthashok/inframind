
## Municipal Water Supply Alarm System

---

## What This Project Does

In large part of India, municipal water comes once a day, without any fixed schedule.

The problem:

- We don’t know exactly when it starts.
    
- Pressure is high at first.
    
- Then neighbors start pumps and pressure drops.
    
- Sometimes supply stops and restarts for 20–30 seconds.
    
- Duration can be 30 minutes or up to 3 hours.
    

This project detects when water **first arrives** and triggers a buzzer inside the house.

It should:

- Alert only once per day.
    
- Not keep buzzing repeatedly.
    
- Not get confused by short pressure drops.
    
- Work using existing 220V switch wiring.
    

---

## Basic Idea

When water arrives:

- Pressure in the pipe rises suddenly.
    

So:

- Install a pressure sensor on a T-joint near the motor.
    
- Send signal to a controller inside the house (~30 feet away).
    
- Controller detects pressure rise.
    
- Buzzer alerts user.
    

That’s it.

---

## How It Will Be Installed

- Water line already has a T-joint.
    
- Pressure sensor goes there.
    
- Sensor wire runs ~30 ft to house.
    
- Controller replaces an existing bulb point.
    
- Powered from 220V mains using existing switch.
    
- User uses normal wall switch to enable/disable system.
    

If switch is OFF → system is OFF.  
If switch is ON → system is active.

---

## Hardware

### Pressure Sensor

- 0–10 bar range
    
- Prefer 4–20mA output (less noise over long wire)
    
- Mounted near pipe/motor
    

### Controller

- ESP32
    
- Reads pressure
    
- Runs simple logic
    
- Drives buzzer
    

### Power

- 220V AC → 5V SMPS
    
- Fully enclosed
    
- No mains outside the house
    

### Buzzer

- 5V active buzzer
    
- Loud enough to hear at night
    

---

## How The Logic Should Work

### 1. When Powered ON

- Wait 10 seconds.
    
- Measure current pressure.
    
- Assume that is baseline.
    

If pressure is already high:  
→ That means water is already available.  
→ Do NOT trigger buzzer.  
→ Just stay silent.

---

### 2. Detect Water Arrival

If pressure suddenly increases by a certain amount:

Example:

current_pressure - baseline > threshold

Then:

- Trigger buzzer.
    
- Mark that today’s supply has started.
    

---

### 3. During Supply

Once triggered:

- Ignore pressure drops for up to 60 seconds.
    
- Do NOT retrigger buzzer.
    
- Treat entire window as one event.
    

---

### 4. Detect End of Supply

If pressure stays near baseline for 10 continuous minutes:

- Assume supply is over.
    
- Lock system for the day.
    

No more alerts.

---

### 5. Reset For Next Day

After about 12 hours:

- Re-arm system automatically.
    

(No RTC for V1.)

---

## Expected Real-World Behavior

Example day:

6:05 AM – Water starts → buzzer rings  
6:20 AM – Pressure drops (neighbors) → ignored  
6:25 AM – Pressure returns → ignored  
7:30 AM – Short 30 sec stop → ignored  
8:10 AM – Final drop → after 10 min low → system locks

Next day → system works again.

---

## User Behavior

User may:

- Keep switch ON overnight.
    
- Turn it OFF once buzzer rings.
    
- Leave it ON whole day.
    

System must handle all of these cases.

If user turns it ON during active supply:

- It should NOT buzz again.
    

---

## Important Design Decisions

- Detect only rising edge, not constant pressure.
    
- Only one alert per day.
    
- Ignore short fluctuations.
    
- Keep wiring simple.
    
- Keep system safe (220V isolated).
    

---

## Things To Test After Building

- Actual baseline pressure before supply.
    
- Peak pressure at start.
    
- How much pressure fluctuates.
    
- How noisy signal is over 30 ft wire.
    
- What threshold works reliably.
    

---

## Future Improvements (Optional)

- Auto motor start.
    
- SMS notification.
    
- Pressure logging.
    
- RTC-based reset.
    
- Display screen.
    

---

## What This Is NOT

- Not a full smart water management system.
    
- Not measuring exact pressure trends.
    
- Not doing motor automation (yet).
    

It only answers one question:

**“Has today’s water supply started?”**

And rings once.

---

Your suggestions are most welcome to improve this system.