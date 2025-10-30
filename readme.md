# 🔐 RFID-Based Employee Attendance System

An embedded systems project that implements a smart employee attendance tracking solution using RFID technology, ARM7 microcontroller, and Linux-based data logging.

---

## 📖 Overview

This project implements a **smart employee attendance system** using an **RFID reader (EM-18)** interfaced with an **LPC2129 microcontroller** and a **Linux-based data logging program**.

When an employee scans their RFID card, the system identifies the user, displays a confirmation message on the LCD, and logs attendance details such as **Name, ID, Timestamp, and IN/OUT status** into a text file on the Linux terminal.

The embedded firmware runs on **Keil µVision 5**, while the Linux-side program (`linux.c`) executes on **Ubuntu** for data validation and attendance record management.

---

## ⚙️ System Architecture

| Component                 | Function                                                   |
|---------------------------|------------------------------------------------------------|
| **LPC2129 (ARM7)**        | Controls RFID scanning, LCD, and RTC modules               |
| **EM-18 RFID Reader**     | Reads employee card UID via UART                           |
| **DS1307 RTC**            | Provides real-time clock for attendance logging            |
| **16x2 LCD (4-bit mode)** | Displays status and scanned ID messages                    |
| **Ubuntu (Linux C App)**  | Validates employee IDs and logs attendance into `data.txt` |

---

## 🔌 Pin Configuration

| Peripheral | Signal | LPC2129 Pin | Description               |
|------------|--------|-------------|---------------------------|
| **UART0**  | TXD0   | **P0.0**    | Transmit data to Linux    |
| **UART0**  | RXD0   | **P0.1**    | Receive data from Linux   |
| **I2C0**   | SDA0   | **P0.3**    | Data line for RTC DS1307  |
| **I2C0**   | SCL0   | **P0.2**    | Clock line for RTC DS1307 |

---

## 📁 Project File Structure

```
rfid-attendance-system/
├── embedded/
│   ├── main.c                  # Main control logic and RFID handling
│   ├── uart0_driver.c          # UART0 initialization and transmission
│   ├── uart0_interrupt.c       # Interrupt-based UART receive handling
│   ├── i2c_driver.c            # I2C communication driver for DS1307 RTC
│   ├── lcd_4bit.c              # LCD initialization and display functions
│   ├── delay.c                 # Software delay routines
│   └── header.h                # Global declarations and function prototypes
├── linux/
│   └── linux.c                 # Linux-side attendance logging program
├── data/
│   ├── data.txt                # Employee database (ID and names)
│   └── attendance_log.txt      # Daily attendance records
└── README.md
```

### File Descriptions

| File Name          | Description                                                           |
|--------------------|-----------------------------------------------------------------------|
| `main.c`           | Main control logic: initializes peripherals and handles RFID scanning |
| `uart0_driver.c`   | UART0 initialization and transmission routines                        |
| `uart0_interrupt.c`| Interrupt-based UART receive handling                                 |
| `i2c_driver.c`     | I2C communication driver for DS1307 RTC                               |
| `lcd_4bit.c`       | Functions for LCD initialization and display handling                 |
| `delay.c`          | Software delay routines                                               |
| `header.h`         | Global declarations, macros, and function prototypes                  |
| `linux.c`          | Linux-side C program for processing RFID data and logging attendance  |

---

## 🧠 Working Principle

1. **RFID Scan**: When an RFID card is scanned on the **EM-18** reader, the card's unique ID is received by the **LPC2129** via UART0
2. **LCD Confirmation**: The microcontroller confirms the scan by displaying **"ID Scanned"** on the **LCD**
3. **Data Transfer**: The scanned RFID ID is transmitted to the **Linux terminal** through UART serial communication
4. **ID Validation**: The `linux.c` program searches the scanned ID in the `data.txt` file
5. **Attendance Logging**: If the ID exists, it retrieves the employee name and logs:
   - Employee Name
   - RFID ID
   - Timestamp (from RTC DS1307)
   - Status (IN/OUT)
6. **Record Storage**: The system appends this record to `log.txt` for maintaining daily logs

---

## 🧰 Hardware Components

| Component               | Description                             |
|-------------------------|-----------------------------------------|
| LPC2129 Microcontroller | ARM7 MCU used as system controller      |
| EM-18 RFID Reader       | Reads RFID tags via UART                |
| RTC DS1307              | Provides real-time clock data using I2C |
| 16x2 LCD                | Displays messages and scan confirmation |
| RFID Tags               | Multiple | Unique IDs for employees     |
| USB-to-Serial Cable     | Connects LPC2129 to Ubuntu system       |
| Connecting Wires        | As needed | For circuit connections     |


---

## 💻 Software Requirements

| Tool                  | Purpose                                       | Version/Notes             |
|-----------------------|-----------------------------------------------|---------------------------|
| **Keil µVision 5**    | Develop, compile, and debug embedded firmware | For ARM7 development      |
| **Flash Magic / ISP** | Upload compiled code to LPC2129               | USB bootloader            |
| **Ubuntu / Linux**    | Run `linux.c` program for ID validation       | Any recent version        |
| **GCC Compiler**      | Compile `linux.c` on Linux                    | `sudo apt install gcc`    |
| **Text Editor**       | Edit `data.txt` (employee database)           | nano, vim, or any editor  |
| **Serial Terminal**   | Monitor UART communication                    | PuTTY, Minicom, or screen |

---

## 🚀 Getting Started

### Prerequisites

**Hardware Setup:**
- Assemble the circuit according to the pin configuration table
- Connect LPC2129 to Ubuntu via USB-to-Serial converter

**Software Setup:**
- Install Keil µVision 5 on Windows (for firmware development)
- Install GCC compiler on Ubuntu: `sudo apt install gcc`


### Installation

#### 1. Embedded Firmware (LPC2129)

# Open the project in Keil µVision 5
# Build the project 
# Flash the hex file to LPC2129 using Flash Magic

```

#### 2. Linux Application

# Compile the Linux program
cc linux.c 

# Create necessary data files
data.txt
log.txt

```

#### 3. Employee Database Setup

Edit `data.txt` and add employee records in the format:
```
4500A26F,RAVI KUMAR
4500B37A,PRIYA SHARMA
4500C48B,AMIT PATEL
```

## 🖨️ Sample Output

### Terminal Output

Scanned ID: 4500A26F
Employee Found: RAVI KUMAR
Attendance Logged: RAVI KUMAR | 4500A26F | 2025-10-30 09:12:56 | IN

Scanned ID: 4500B37A
Employee Found: PRIYA SHARMA
Attendance Logged: PRIYA SHARMA | 4500B37A | 2025-10-30 09:15:23 | IN

Scanned ID: 4500C48B
Employee Not Found! Unknown ID
```

### LCD Display
```
Line 1: ID Scanned
Line 2: RAVI KUMAR
```

### Attendance Log File (`attendance_log.txt`)
```
RAVI KUMAR   | 4500A26F | 2025-10-30 09:12:56 | IN
PRIYA SHARMA | 4500B37A | 2025-10-30 09:15:23 | IN
AMIT PATEL   | 4500C48B | 2025-10-30 09:18:45 | IN
RAVI KUMAR   | 4500A26F | 2025-10-30 05:07:12 | OUT

```

---

## 🔧 Configuration

### UART Configuration (in `uart0_driver.c`)
- **Baud Rate**: 9600 bps 
- **Data Bits**: 8
- **Stop Bits**: 1
- **Parity**: None

### I2C Configuration (in `i2c_driver.c`)
- **Speed**: 100 kHz
- **DS1307 Address**: 0x68

### LCD Configuration (in `lcd_4bit.h`)
- **Mode**: 4-bit
- **Display**: 16x2 characters

---

## 📊 Features

- ✅ Real-time RFID card scanning
- ✅ Employee identification and validation
- ✅ Automatic timestamp logging using RTC
- ✅ IN/OUT status tracking
- ✅ LCD visual feedback
- ✅ Persistent attendance records
- ✅ Cross-platform communication (Embedded ↔ Linux)
- ✅ Expandable employee database

---

## 👨‍💻 Author

** Vijay Magadum **

** Vector India **

---
