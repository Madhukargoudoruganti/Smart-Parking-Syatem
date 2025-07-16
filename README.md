README.txt

# RFID-Based Parking System using Arduino


---.

## Features

* Register up to *10 RFID cards*
* Toggle between *registration* and *operation* modes using buttons
* Track *entry and exit times*
* Park fee automatically calculated (₹10 per minute)
* Show logs through *Serial Monitor*

---

## Hardware Specifications

* Arduino (i.e., Mega, Uno)
* MFRC522 RFID reader
* Tags or cards RFID
* 2 push buttons
* Jumper wires and breadboard
* USB cable upload code

---

## ⚙ Pin Configuration

| Component   | Arduino Pin |
| ------------ | ------------ |
| MFRC522 SS | D21          |
| MFRC522 RST | D22         |
| Button 1    | D4          |
| Button 2    | D5          |

---

## How It Works

1. *Startup:*

* Boots and goes directly to *registration mode*.

2. *Register Cards:*

* Press *Button 2* to enter registration mode. * Read one RFID tag at a time to enroll them.

* Registered UIDs are kept in RAM.

3. *Begin Parking Mode:*

* Press *Button 1* to exit registration mode.

* In this mode:

* *First scan* of a registered card = Entry

* *Second scan* = Exit, computed fee printed to Serial Monitor.

---

## Fee Calculation

* ₹10 per minute

* Minimum charged for *1 minute*

---

## How to Use

1. Open the Arduino IDE.

2. Install the *MFRC522* library (Sketch → Include Library → Manage Libraries → Search "MFRC522").

3. Upload code to your Arduino.

4. Open the *Serial Monitor* at 115200 baud.

5. Use the buttons and RFID cards as outlined above.

--- ## File Description * main.ino — Main logic for registration, entry/exiting logging, and fee calculation. --- ## ???? Notes * This uses *volatile memory*—data is lost on reset/power off. * You can add the use of *EEPROM* or *SD card* for permanent storage. --- ## ???? License This is an open-source and free project to use for educational and personal use.

---.

## Features

* Register up to *10 RFID cards*
* Toggle between *registration* and *operation* modes using buttons
* Track *entry and exit times*
* Park fee automatically calculated (₹10 per minute)
* Show logs through *Serial Monitor*

---

## Hardware Specifications

* Arduino (i.e., Mega, Uno)
* MFRC522 RFID reader
* Tags or cards RFID
* 2 push buttons
* Jumper wires and breadboard
* USB cable upload code

---

## ⚙ Pin Configuration

| Component   | Arduino Pin |
| ------------ | ------------ |
| MFRC522 SS | D21          |
| MFRC522 RST | D22         |
| Button 1    | D4          |
| Button 2    | D5          |

---

## How It Works

1. *Startup:*

* Boots and goes directly to *registration mode*.

2. *Register Cards:*

* Press *Button 2* to enter registration mode. * Read one RFID tag at a time to enroll them.

* Registered UIDs are kept in RAM.

3. *Begin Parking Mode:*

* Press *Button 1* to exit registration mode.

* In this mode:

* *First scan* of a registered card = Entry

* *Second scan* = Exit, computed fee printed to Serial Monitor.

---

## Fee Calculation

* ₹10 per minute

* Minimum charged for *1 minute*

---

## How to Use

1. Open the Arduino IDE.

2. Install the *MFRC522* library (Sketch → Include Library → Manage Libraries → Search "MFRC522").

3. Upload code to your Arduino.

4. Open the *Serial Monitor* at 115200 baud.

5. Use the buttons and RFID cards as outlined above.

--- ## File Description * main.ino — Main logic for registration, entry/exiting logging, and fee calculation. --- ##  Notes * This uses *volatile memory*—data is lost on reset/power off. * You can add the use of *EEPROM* or *SD card* for permanent storage. --- ##  License This is an open-source and free project to use for educational and personal use.
