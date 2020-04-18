#include "ledlight.h"

 Light::Light(byte pin,){
    Pin=pin;
    working_time=0;
    state=0;
    ask_status=0;
}

void Light::begin(){
 pinMode(Pin, OUTPUT);
}

void Light::on()
{ 
 ask_status=1;
}
void Light::off()
{
ask_status=0; 

}


int Light::status()
{  
   return state;
} 

int Light::wtime()
{ if(state>0){ return (millis()-working_time)/1000;}
  else {return 0;}
}

void Light::Loop()
{


if(ask_status==1 && state!=ask_status)
 { 
   AnalogWrite(Pin,HIGH);
  
   state=ask_status; 
   start_time=millis();
   working_time=start_time;
   Serial.println("Light start work");
 }



}

