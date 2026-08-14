# Eprom_USB
2716 through 27080 Eprom Programmer
A programmer for EPROMs with capacities between 2Kb (2716 series) and 1Mb (27C080 series).  
It uses an Arduino NANO and few other components.  
As a starting point I used the excelent [EpromProgrammer_ciprian-stingu](https://github.com/ciprian-stingu/EpromProgrammer) project

## My Usage
I need write eproms for pinball machines and I have two, actually (not working)
- parallel port (epromwillem) windows XP 32b
- serial port (PGM27) for DOS.

So, I need a new programmer (with a USB port).

That is why I started this project

my OS is Ubuntu 24.04 right now.

## Main features
* It supports a large number of EPROMs with different capacities
* 2 programming speeds (normal & fast). Fast programming speed is available if you configure the VCC correctly
* On fast programming alghoritm, writing a 27C040 EPROM takes around 290 seconds
* Error detection on writing
* Additional verify option

## GUI Software (Ubuntu Linux_x64)
Actualized "CMakeLists.txt" and code with AI help for Ubuntu 24.04 OS 
The complete source for project is in [soft_linux](soft_linux)
I have compiled for Ubuntu 24.04 and is included in folder [soft_linux/buid](soft_linux/build)

## GUI Software (windows_x64)
Actualized "CMakeLists.txt" for Windows 11 OS 
The complete source for project is in [soft_Win64](soft_Win64)

## Eprom_USB v1.0.0 - Multiplatform Release

This release contains the standalone, portable binaries for the Eprom USB Programmer software, 
fully compatible with both Windows and Linux. No external installation or build tools are required.

### 🪟 Windows Instructions (64-bit)
1. Download **`Eprom_USB_v1.0_Windows_x64.zip`**.
2. Extract the `.zip` file entirely into a folder of your choice.
3. Double-click **`Eprom_USB.exe`** to launch the graphical interface.
*Note: All required Qt, Gettext (`libintl`), and `libiconv` DLLs are included inside the package.*

### 🐧 Linux / Ubuntu Instructions (64-bit AppImage)
1. Download **`Eprom_USB-x86_64.AppImage`**.
2. Open your terminal, navigate to the folder where you downloaded the file, and grant it execution permissions:
   ```bash
   chmod +x Eprom_USB-x86_64.AppImage
   ```
3. Launch the application by double-clicking it or running:
   ```bash
   ./Eprom_USB-x86_64.AppImage
   ```

⚠️ **Important for Linux Users (Serial Port Permission):**
If the application cannot open or detect your USB serial port, your Linux user might lack dialout permissions. Fix this by running the following command once, then log out and log back into Ubuntu:
```bash
sudo usermod -a -G dialout \$USER
```

---
*Developed with Qt 5 and CMake. Built with native MinGW (Windows) and GCC (Linux) compiler suites.*


## Arduino Software
The sketch for arduino nano is here: [arduino_nano](arduino_nano)

## Hardware
New schematics and PCB into FreeCAD project, was modify for me are in [FreeCAD](FreeCAD) folder.

I add LM317 for the power of Vpp (12.5v - 12.75 - 21v - 25v) from 24Vac input

For non KiCad users, schematics and PCB [hardware](hardware) in PDF format

New v2 PCB make for Ivana, in PDF format [hardware/PCB_v2](hardware/PCB_v2) front, bottom and silk

## Images
The screenshots and images of PCB and others are available in [images](images) folder

## Supported EPROMs

### 2716 — 2 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 2716             |
| AMD              | 2716             |
| Intel            | 2716             |
| Hitachi          | HN462716         |
| Mitsubishi       | M5L2716K         |
| Fujitsu          | MBM2716          |
| Motorola         | MCM2716          |
| NEC              | µPD2716          |
| -                | ET2716           |
| -                | M2716            |

### 27C16 — 2 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 27C16            |
| National Semi    | 27C16            |
| AMD              | AM2716B          |
| National Semi    | NMC27C16B        |

### 2732 — 4 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 2732             |
| AMD              | AM2732           |
| AMD              | AM9732           |
| Fairchild        | F2732            |
| Hitachi          | HN462732         |
| Intel            | 2732A            |
| ST               | M2732A           |
| Fujitsu          | MBM2732          |
| NTE              | NTE2732A         |
| Toshiba          | TMM2732D         |
| NEC              | µPD2732A         |

### 27C32 — 4 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 27C32            |
| AMD              | AM2732B          |
| National Semi    | NMC27C32B        |
| WSI              | WS57C43C         |

### 2764 — 8 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 2764             |
| Intel            | 2764A            |
| ST               | M2764A           |
| Mitsubishi       | M5L2764K         |
| NTE              | NTE2764          |
| Toshiba          | TMM2764AD        |

### 27C64 — 8 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 27C64            |
| Microchip        | 27C64            |
| Cypress          | Cy7C266          |
| Fujitsu          | MBM27C64         |
| National Semi    | NMC27C64         |
| Texas Instruments| TMS27C64         |

### 27128 — 16 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 27128            |
| Hitachi          | HN4827128G       |
| Hitachi          | HN27128          |
| Intel            | M27128A          |
| ST               | M27128A          |
| Mitsubishi       | M5L27128K        |
| Mitsubishi       | M5M27C128K       |
| Fujitsu          | MBM27128         |
| NTE              | NTE21128         |
| Toshiba          | TMM27128AD       |
| Texas Instruments| TMS27128         |
| NEC              | µPD27128         |

### 27C128 — 16 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 27C128           |
| Microchip        | 27C128           |
| AMD              | AM27C128         |
| Atmel            | AT27C128         |
| Cypress          | CY27C128         |
| Sharp            | LH57126          |
| ST               | M27C128          |
| Oki              | MSM27C128        |
| Fairchild        | NM27C128         |
| National Semi    | NM27C128         |
| -                | QP27C128         |
| Texas Instruments| SMJ27C128        |
| Texas Instruments| TMS27C128        |

### 27256 — 32 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 27256            |
| -                | A68C256          |
| Atmel            | AT27256          |
| Intel            | 27256            |
| Mitsubishi       | M5L27256K        |
| Fujitsu          | MBM27256         |
| Oki              | MSM27256         |
| Toshiba          | TMM27256         |
| NEC              | µPD27256         |

### 27C256 — 32 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 27C256           |
| Microchip        | 27C256           |
| AMD              | AM27C256         |
| AMD              | AM27H256         |
| Sony             | CXK27C256DQ      |
| Cypress          | CY27C256         |
| Cypress          | CY27H256         |
| Cypress          | CY7C274          |
| -                | EM27C256         |
| -                | FM27C256         |
| Hitachi          | HN27C256A        |
| Hitachi          | HN27C256AG       |
| ISSI             | IS27C256         |
| ST               | M27C256B         |
| Mitsubishi       | M5M27C256K       |
| Fujitsu          | MBM27C256        |
| -                | 27HC256          |
| Oki              | MSM27C256H       |
| Fairchild        | NM27C256         |
| National Semi    | NM27C256         |
| National Semi    | NM27LC256        |
| National Semi    | NMC27C256        |
| National Semi    | NMC87C257        |
| -                | NPX27C256        |
| -                | QP27C256         |
| SEEQ             | 27C256           |
| SEEQ             | M27C256          |
| ASI              | SMJ27C256        |
| Texas Instruments| SMJ27C256        |
| -                | SPM27C256        |
| Toshiba          | TC57256          |
| Texas Instruments| TMS27C256        |
| Texas Instruments| TMS87C257        |
| NEC              | µPD27C256        |

### 27512 — 64 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 27512            |
| Intel            | 27512            |
| AMD              | AM27512          |
| Hitachi          | HN27512          |
| ST               | M27512           |
| Mitsubishi       | M5L27512K        |
| Oki              | MSM27512         |
| Toshiba          | TMM27512AD       |

### 27C512 — 64 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 27C512           |
| Microchip        | 27C512           |
| Intel            | 27C512           |
| Philips          | 27C512           |
| AMD              | AM27C512         |
| Sony             | CXK27C512DQ      |
| Cypress          | CY27C512         |
| Cypress          | CY27H512         |
| -                | EM27C512         |
| -                | FM27C512         |
| Hitachi          | HN27C512         |
| ISSI             | IS27HC512        |
| Fujitsu          | MBM27C512        |
| Macronix         | MX27C512         |
| National Semi    | NM27C512         |
| National Semi    | NM27P512         |
| ASI              | SMJ27C512        |
| Texas Instruments| SMJ27C512        |
| Toshiba          | TC57512AD        |
| Texas Instruments| TMS27C512        |
| NEC              | µPD27C512        |

### 27C010 — 128 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 27C010           |
| AMD              | AM27C010         |
| AMD              | AM27H010         |
| AMD              | AM27HB010        |
| Cypress          | CY27C010         |
| Cypress          | CY27H010         |
| Intel            | 27C010           |
| -                | EM27C010         |
| -                | FM27C010         |
| Hitachi          | HN27C101         |
| ISSI             | IS27C010         |
| Mitsubishi       | M5M27C101K       |
| Fairchild        | NM27C010         |
| National Semi    | NM27C010         |
| National Semi    | NMC27C010        |
| ASI              | SMJ27C010        |
| Texas Instruments| SMJ27C010        |
| Texas Instruments| TMS27C010        |

### 27C1001 — 128 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 27C1001          |
| Sony             | CXK27C1001DQ     |
| ST               | M27C1001         |
| Fujitsu          | MBM27C1001       |
| Oki              | MSM27C1000       |
| Macronix         | MX27C1000        |
| Toshiba          | TC57C1001        |
| Toshiba          | TC57H1001        |

### 27C020 — 256 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 27C020           |
| AMD              | AM27C020         |
| Cypress          | CY27C020         |
| Intel            | 27C020           |
| -                | EM27C020         |
| ISSI             | IS27C020         |
| National Semi    | NM27C020         |
| Texas Instruments| TMS27C020        |

### 27C2001 — 256 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 27C2001          |
| ST               | M27C2001         |
| Oki              | MSM27C2000       |
| NEC              | µPD27C2001       |

### 27C040 — 512 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 27C040           |
| AMD              | AM27C040         |
| Cypress          | CY27C040         |
| -                | EM27C040         |
| -                | FM27C040         |
| Intel            | 27C040           |
| National Semi    | NM27C040         |
| NXP              | NXP27C040        |
| ASI              | SMJ27C040        |
| Micross          | SMJ27C040        |
| Texas Instruments| SMJ27C040        |
| Texas Instruments| TMS27C040        |

### 27C4001 — 512 KB

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 27C4001          |
| Hitachi          | HN27C4001        |
| ST               | M27C4001         |
| Fujitsu          | MBM27C4001       |
| Oki              | MSM27C401        |
| Macronix         | MX27C4000        |
| Toshiba          | TC57C4000        |
| NEC              | µPD27C4001       |

### 27C080 — 1024 KB (1 MB)

| Manufacturer     | Part Number      |
|------------------|------------------|
| Generic          | 27C080           |
| AMD              | AM27C080         |
| Atmel            | AT27LV080        |
| ST               | M27C801          |
| Macronix         | MX27C8000        |
