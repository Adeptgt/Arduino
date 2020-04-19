#include "Led.h"

Led::Led(byte pin, unsigned long interval)
{
  Pin = pin;
  Interval = interval;
  Level = 0;
  ask_level = 0;
}

void Led::begin()
{
  pinMode(Pin, OUTPUT);
}

void Led::ON()
{
  ask_level = 255;
}
void Led::OFF()
{
  ask_level = 0;
}
void Led::SET(unsigned int level)
{
  ask_level = level;
  if (ask_level>255){ask_level=255;}
}



int Led::Loop()
{

  if (millis() - time > Interval)
  {
    if (ask_level> Level)
    {
        Level++;
        analogWrite(Pin, Level);
        time = millis();
    }
    else if (ask_level < Level)
    {
      Level--;
        analogWrite(Pin, Level);
        time = millis();
    }

  }
  return Level;
}
