#ifndef Led_h
#define Led_h
#include "Arduino.h"

class Led
{
private:
    byte Pin;
    unsigned int Level;
    unsigned int ask_level;
    unsigned long Interval; // время между изменениями яркости в миллисикундах
    unsigned long time;

public:
    Led(byte pin,unsigned long interval);
    void SET(unsigned int level);
    void ON();
    void OFF();
    void begin();
    int Loop();
};

#endif