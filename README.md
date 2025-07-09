# 4servo_sweep_hold_90deg_after_2seconds
## Project Description

This project demonstrates how to control four servo motors using an Arduino Uno board. All four servos perform a sweeping motion (from 0 to 180 degrees and back) for exactly two seconds. After the time elapses, the servos stop and hold their position at 90 degrees (or the nearest accurate angle based on calibration).

---

## Components Used

- Arduino Uno board  
- 4 × Servo motors (e.g., SG90)  
- Jumper wires

---

## Wiring and Connections

All servo motors are connected directly to the Arduino board, without using a breadboard.

| Servo   | Signal (Control) | Power (5V) | Ground (GND) |
|---------|------------------|------------|----------------|
| Servo 1 | Digital Pin 9     | 5V         | GND            |
| Servo 2 | Digital Pin 10    | 5V         | GND            |
| Servo 3 | Digital Pin 11    | 5V         | GND            |
| Servo 4 | Digital Pin 6     | 5V         | GND            |

All GND wires from the servos are connected to a common GND pin on the Arduino. Similarly, all 5V wires are connected to the Arduino’s 5V output.

---

## Code Behavior

- All four servos start sweeping between 0 and 180 degrees.
- The sweeping continues for **2 seconds only**.
- After two seconds, the motion stops and all servos hold position at **90 degrees**.

> Note: Due to manufacturing tolerances, some servo motors may not stop precisely at 90 degrees. You may manually fine-tune the angle in code (e.g., using `servo.write(87)`) to achieve the correct alignment.

---

## Expected Result

- All servos sweep in sync for exactly two seconds.
- Then they stop and hold at a fixed position (typically 90 degrees).

---

## Illustrative Images

### Before Starting:
![Screenshot 2025-07-10 013629](https://github.com/user-attachments/assets/1d3db722-4b6a-4cbe-8c0d-fd2a3f1069ee)

### After 2 Seconds (at 90 degrees):
![Screenshot 2025-07-10 013645](https://github.com/user-attachments/assets/08b047cf-e017-4e68-832c-5c78e9f2f81a)


## Algorithm

**Objective:** Control four servo motors using Arduino. Perform a sweep motion for 2 seconds, then hold all servos at 90 degrees.

### Steps:

1. Start the system.

2. Initialize four servo motor objects:
   - Attach each servo motor to its assigned digital pin.

3. Record the start time using `millis()`.

4. Begin sweeping motion:
   - While elapsed time is less than 2000 milliseconds:
     - a. Sweep from 0 to 180 degrees in steps of 1 degree.
     - b. Sweep back from 180 to 0 degrees.
     - c. At each step, write the current angle to all servos.
     - d. Apply a small delay after each step (e.g., 15 ms).
     - e. Continuously check elapsed time.

5. Once 2 seconds have passed, exit the sweeping loop.

6. Write a value of 90 (or adjusted angle) to all four servos to hold position.

7. Stop further execution (e.g., using an infinite loop or `while(true)`).


