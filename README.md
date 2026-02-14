
# GloveForDeaf
![project](https://github.com/user-attachments/assets/36d280a1-c900-40b7-803e-451a5c6976fe)


## Table of Contents
- [Overview](#overview)
- [Hardware Components](#hardware-components)

- [How it works](#how-it-works)
- [Simulation](#simulation)

---
##  Overview
GloveForDeaf is an embedded systems project designed to bridge the communication gap between the deaf/mute community and the general public. This smart glove detects hand gestures and translates them into readable text, acting as an automated sign-language translator.

The glove utilizes flex sensors to detect finger positions and displays predefined messages on LCD screen based on detected combination.

---
## Hardware Components
#### The project is built using:
- ATmega32A Microcontroller(Running at 16 MHz).
-  4x Flex Sensors(connected to ADC pins `A0`, `A1`, `A2`, `A3`).
- 16x2 LCD Display(connected to pins `A7`, `A6`, `A5`, `A4`, `B1`, `B2`).
- External EEPROM (I2C).
- Power supply (5V).

---
## How It Works


### 1. Dynamic Calibration Sequence
When powered on, the microcontroller initializes the LCD and walks the user through a calibration phase:
* It prompts the user to **"Open Hand Widely"** and records the baseline ADC values for all 4 fingers (`RES_OPEN`).
* It then prompts the user to **"Close Hand Firmly"** and records the compressed values (`RES_CLOSED`).
* These dynamic thresholds ensure the glove works accurately for different hand sizes and sensor wear-and-tear.

### 2. Data Acquisition & Filtering


The 4 flex sensors act as variable resistors in a voltage divider circuit connected to pins `A0` through `A3`. 
* **Oversampling:** The `getFilteredADC()` function takes 16 rapid samples from the ADC channel and averages them. This smooths out any small hand twitches or electrical noises, ensuring a highly stable reading.

### 3. Gesture Classification (Base-3 Logic)
Instead of simple binary (bent/straight), the system calculates dynamic margins (`range/6`) based on the calibration data to classify each finger into one of three states:
1. `FLEX_STATE_OPEN`
2. `FLEX_STATE_HALF`
3. `FLEX_STATE_CLOSED`

### 4. Memory Hashing & Output


To translate the gesture, the system converts the array of 4 finger states into a unique memory address using a custom hashing algorithm. Treating the states as a Base-3 number system, the algorithm applies weights:

$Address = \left( \sum_{i=0}^{3} State_i \times 3^{3-i} \right) \times 60$
---


This calculated address points directly to a pre-programmed phrase in the EEPROM (e.g., "I Love U", "Hello", "Good job!"). If the new state differs from the previous state, the phrase is fetched and displayed on the 16x2 LCD.

---
##  Simulation

<img width="1361" height="752" alt="Screenshot (1129)" src="https://github.com/user-attachments/assets/b5963649-7c5e-4640-bb3b-98ba15be6a51" />

