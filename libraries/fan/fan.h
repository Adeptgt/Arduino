#ifndef Fan_h
#define Fan_h
#include "Arduino.h"


class Fan{
private:
byte Pin;
unsigned long start_time;
unsigned long pause_time;
unsigned long timeout;
unsigned long resttime;
unsigned int ask_status;
unsigned int   state; // 0 - OFF; 1 - ON ; 2 - PAUSE;
public:
unsigned long working_time;
unsigned long on_time;
Fan(byte pin,unsigned long tm1=120000,unsigned long tm2=60000);
void start();
void stop();
int  status();
int wtime();
void begin();
void Loop();
};

#endif