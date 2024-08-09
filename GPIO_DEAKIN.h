#ifndef GPIO_DEAKIN_H
#define GPIO_DEAKIN_H

class GPIO_DEAKIN {
public:
    void GPIO_Configure_Pins(char* PinArray, char* DirectionArray);
    bool GPIO_Display_Pattern(char* PinArray, char GPIOPattern);
    void GPIO_Sequential_Control(char* PinArray, int delayTime);
};

#endif
