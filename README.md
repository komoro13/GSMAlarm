# GSM Alarm Project

## Description

The GSM Alarm project is written in C using the XC8 compiler and MPLAB X IDE. This system is designed to receive signals from sub-boards that track motion via RF transmission. It consists of a main board equipped with a SIM900A module for GSM communication, as well as interface components for user interaction. The sub-boards repository can be found [here](https://github.com/komoro13/ProximitySensor).

## Features

- Save and change the user's phone number for calls.
- Call system through the SIM900A GSM module.
- Motion detection and alarm triggering via RF transmission.
- User interface via a 4x4 matrix keyboard and a 16x2 LCD.
- Modular design for flexible implementation.

## Hardware Setup

### Components

1. **Main Board:**
   - SIM900A GSM module: For making calls.
   - 4x4 Matrix Keyboard: For user input.
   - 16x2 LCD: For status display.
   - RF Transmitter: For communication with sub-boards.

2. **Sub-boards:**
   - These track motion and communicate with the main board via RF.

### Wiring

- Ensure all components are connected according to the schematic provided to enable proper functionality.

### Testing

- After setting up the hardware, power on the system.
- Use the 4x4 matrix keyboard to save or change the phone number.
- The system will initiate a call to the saved phone number when motion is detected.

## Key Functionality

### Boot Function

The `boot` function initializes the system upon startup. Here is a brief overview of the function:

```c
void boot() {
    initialize_SIM900A();
    init_trisio();
    boot_led_blink();
}

- **Functionality**: This function sets up necessary components for the project to operate.
- **Initialization Steps**:
  - `initialize_SIM900A()`: Prepares the SIM900A module for communication.
  - `init_trisio()`: Sets up GPIO configurations.
  - `boot_led_blink()`: Provides visual feedback (e.g., blinking an LED) to indicate system booting.

### MakeCall Function

The `MakeCall` function initiates a call to the saved phone number using the SIM900A GSM module:

'''c
void MakeCall() {   
    char *AT_COMMAND = concatenate("ATD", read_saved_phone());
    AT_COMMAND = concatenate(AT_COMMAND, ";\r\n");
    _SIM900A_print(AT_COMMAND);
    BlinkMainLED();
}

- **Functionality**: Constructs an AT command to dial a saved phone number and sends it to the SIM900A module.
- **AT Command Format**: Formatted as `ATD<number>;\r\n`, where `<number>` is the saved phone number.
- **LED Indication**: The `BlinkMainLED()` function provides visual feedback when a call is being initiated.

### Keypad Modes

The `read_keypad` function supports two modes specific to the GSM Alarm project: **Canonical Mode** and **Raw Mode**.

'''c
char *read_keypad(int mode)
{
    char buffer[15];//Buffer has to be 15 char max
    if (mode == CANONICAL_MODE)
    {
        int i = 0;
        char ch;
        while (i<14)
        {
            ch = read_keypad_char();
            if ( ch == DELETE)
            {
                i--;
                buffer[i] = ''; 
                LCD_display(buffer);
                continue;
            }
            if (ch == CLEAR)
            {
                i = 0;
                buffer = 0;
                LCD_display(buffer);
            }
            if (ch != 0)
                buffer[i] = ch;
            LCD_display(buffer);
            i++;
        }
        
        return buffer;
    }
    buffer = read_keypad_char();
    return buffer;
}

#### Canonical Mode
- **Use Case**: Utilized when saving or changing the user's phone number.
- **Functionality**: Allows users to enter numbers with real-time feedback on the LCD. Users can delete mistakes or clear input, ensuring accurate phone numbers are stored for calling.

#### Raw Mode
- **Use Case**: Employed for quick command inputs, such as triggering alarms or responses that do not require editing.
- **Functionality**: Processes each keypress immediately, without modifications. Useful for situations where speed is essential and feedback is less critical.

## Parts List

- **Main Board Components:**
  - SIM900A GSM module
  - 4x4 Matrix Keyboard
  - 16x2 LCD
  - RF Transmitter

## Installation

### Prerequisites

- MPLAB X IDE
- XC8 Compiler
- Pad2Pad (for PCB design adjustments, if necessary)

### Steps

1. **Clone the repository:**
   ```bash
   git clone https://github.com/komoro13/GSMAlarm.git

2. **Open the project:**
*Launch MPLAB X IDE.
*Open the cloned project directory in MPLAB.

3. **Compile the code:**
*Ensure that the XC8 compiler is selected.
*Build the project using MPLAB X IDE.

## Contributing

Contributions are welcome! Here’s how you can help improve the project:

1. **Fork the repository**: Create your own copy of the project on your GitHub account.

2. **Make your changes**: Implement your improvements or fixes in a new branch.

3. **Test your changes**: Ensure that everything works as expected.

4. **Submit a pull request**: Submit your changes back to the main repository with a description of what you have done.

### Guidelines

- Follow the project’s coding style.
- Write clear and descriptive commit messages.
