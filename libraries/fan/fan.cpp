#include "fan.h"

 Fan::Fan(byte pin,unsigned long tm1,unsigned long tm2){
    Pin=pin;
    timeout=tm1;
    resttime=tm2;
    start_time=0;
    pause_time=0;
    working_time=0;
    on_time=0;
    state=0;
    ask_status=0;
}

void Fan::begin(){
 pinMode(Pin, OUTPUT);
}

void Fan::start()
{ 
 ask_status=1;
}
void Fan::stop()
{
ask_status=0; 
digitalWrite(Pin,LOW);
state=ask_status;
working_time=0;   
Serial.println("Fan stopt work");
}


int Fan::status()
{  
   return state;
} 

int Fan::wtime()
{ if(state>0){ return (millis()-working_time)/1000;}
  else {return 0;}
}

void Fan::Loop()
{


if( millis()-start_time>timeout && state==1)
{
 digitalWrite(Pin,LOW);
 state=2;
 pause_time=millis();
 Serial.println("Fan paused to rest");
}

if(millis()-pause_time>resttime && state==2 )
{ 
 digitalWrite(Pin,HIGH);
 state=1;
 start_time=millis();
 Serial.println("Fan resume work");
}


if(ask_status==1 && state!=ask_status && state!=2)
 { 
   digitalWrite(Pin,HIGH);
   state=ask_status; 
   start_time=millis();
   working_time=start_time;
   Serial.println("Fan start work");
 }



}

