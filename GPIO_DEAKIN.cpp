#include "GPIO_DEAKIN.h"
#include <Arduino.h>

// Method to configure GPIO pins as inputs or outputs
void GPIO_DEAKIN::GPIO_Configure_Pins(char* PinArray, char* DirectionArray) {
    for (int i = 0; i < 6; i++) {
        if (DirectionArray[i] == 'O') {
            pinMode(PinArray[i], OUTPUT);
        } else if (DirectionArray[i] == 'I') {
            pinMode(PinArray[i], INPUT);
        }
    }
}

// Method to display a pattern on the GPIO pins
bool GPIO_DEAKIN::GPIO_Display_Pattern(char* PinArray, char GPIOPattern) {
    for (int i = 0; i < 6; i++) {
        if ((GPIOPattern >> i) & 0x01) {
            digitalWrite(PinArray[i], HIGH);
        } else {
            digitalWrite(PinArray[i], LOW);
        }
    }
    return true;
}

// Method to control the pins sequentially
void GPIO_DEAKIN::GPIO_Sequential_Control(char* PinArray, int delayTime) {
    while (true) {
        // Turn on LEDs from Pin 1 to Pin 6
        for (int i = 0; i < 6; i++) {
            digitalWrite(PinArray[i], HIGH);
            delay(delayTime);
            digitalWrite(PinArray[i], LOW);
        }
        // Turn off LEDs from Pin 6 back to Pin 1
        for (int i = 5; i >= 0; i--) {
            digitalWrite(PinArray[i], HIGH);
            delay(delayTime);
            digitalWrite(PinArray[i], LOW);
        }
    }
}
