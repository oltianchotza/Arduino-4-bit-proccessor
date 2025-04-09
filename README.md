4-Bit Processor
This is a simple 4-bit processor built with Arduino that performs basic arithmetic operations like addition and multiplication. It uses binary inputs, processes them, and displays the results using LEDs.

Features
Performs addition and multiplication of two 4-bit binary numbers.

Displays results in binary format using LEDs.

Uses a clock button to control the input and operation phases.

Handles overflow automatically (results are limited to 4 bits).

How It Works
Input Phase:

Use toggle switches to set the first binary number (Reg A).

Press the clock button to store this number in Reg A.

Use toggle switches to set the second binary number (Reg B).

Press the clock button again to store this number in Reg B.

Operation Phase:

Press the "Add" button to perform addition or the "Multiply" button to perform multiplication.

The processor calculates the result.

Output Phase:

The result is displayed on four LEDs in binary format.

Example Usage
Inputs:

Reg A: 0011 (3 in decimal)

Reg B: 0101 (5 in decimal)

Operations:

Add → Result: 1000 (8 in decimal)

Multiply → Result: 1111 (15 in decimal)

Setup Instructions
Connect your Arduino and components as described below:

4 LEDs for output (connected to pins 8, 9, 10, and 11).

4 toggle switches for binary input (connected to pins 2, 3, 4, and 5).

One button for addition (connected to pin 6).

One button for multiplication (connected to pin 7).

One button for the clock signal (connected to pin 13).

Open the .ino file in Arduino IDE.

Upload the code to your Arduino board.

Use the toggle switches and buttons as explained above.

Troubleshooting
If LEDs don’t light up, check your wiring and ensure resistors are properly connected.

If results are incorrect, double-check your input switches.

If buttons don’t respond, make sure they’re connected properly or replace them if necessary.
