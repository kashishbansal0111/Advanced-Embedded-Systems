#include "GPIO_DEAKIN.h"

GPIO_DEAKIN gpio;
char pins[6] = {2, 3, 4, 5, 6, 7}; // Example GPIO pins used

void setup() {
    char directions[6] = {'O', 'O', 'O', 'O', 'O', 'O'}; // Set all pins as outputs
    gpio.GPIO_Configure_Pins(pins, directions);
}

void loop() {
    char pattern = 0b00101101; // Example pattern
    gpio.GPIO_Display_Pattern(pins, pattern);
    delay(1000);

    int delayTime = 500; // Example delay time in ms
    gpio.GPIO_Sequential_Control(pins, delayTime);
}
