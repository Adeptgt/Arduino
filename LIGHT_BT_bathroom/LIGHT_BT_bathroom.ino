#include "sav_button.h"
SButton  lbut1(2,100,0,0,0);
SButton  lbut2(3,100,0,0,0);
int light1=4;
int light2=6;
int fan1=5;
int fan2=7;
int lstatus1=0;
int lstatus2=0;
int fanstatus1=0;
int fanstatus2=0;
unsigned long timer1=0;
unsigned long timer2=0;
unsigned long fan1_starttime=240000;
unsigned long fan2_starttime=120000;
unsigned long fan1_stoptime=60000;
unsigned long fan2_stoptime=120000;
void setup() {
  // put your setup code here, to run once:
   lbut1.begin();
   lbut2.begin();
   pinMode(light1, OUTPUT); // Ванная комната
   pinMode(light2, OUTPUT); // Туалт
   pinMode(fan1, OUTPUT); // Вентилятор в ванной комнате
   pinMode(fan2, OUTPUT); // Вентилятор в туалете
   Serial.begin(115200);
   Serial.println("Start light system V0.7 alpha ...");
}

void loop() {
  // put your main code here, to run repeatedly:
switch( lbut1.Loop() ){
  
      case SB_RELEASE: 
         Serial.println("BUTTON 1 RELEASE");timer1=millis();
         lstatus1=0;
         break;
      case SB_CLICK: 
         Serial.println("BUTTON 1 CLICK");timer1=millis();
         lstatus1=1;
         break;
   }
if(millis()-timer1>fan1_starttime && lstatus1==1 && fanstatus1==0){ fanstatus1=1;Serial.println("Start fan 1");}
else if(millis()-timer1>fan1_stoptime && lstatus1==0 && fanstatus1==1){fanstatus1=0;Serial.println("Stop fan 1");}

switch (lstatus1)
{
 case 0:
    digitalWrite(light1,LOW);
    break;
 case 1:
    digitalWrite(light1,HIGH);
    break;
                 
}

switch (fanstatus1)
{
 case 0:
    digitalWrite(fan1,LOW);
    break;
 case 1:
    digitalWrite(fan1,HIGH);
    break;                 
}






switch( lbut2.Loop() ){
  
      case SB_RELEASE: 
         Serial.println("BUTTON 2 RELEASE");timer2=millis();
         lstatus2=0;
         break;
      case SB_CLICK: 
         Serial.println("BUTTON 2 CLICK");timer2=millis();
         lstatus2=1;
         break;
   }
   
if(millis()-timer2>fan2_starttime && lstatus2==1 && fanstatus2==0 ){ fanstatus2=1;Serial.println("Start fan 2");}
else if(millis()-timer2>fan2_stoptime && lstatus2==0 && fanstatus2==1){fanstatus2=0;Serial.println("Stop fan 2");}

switch (lstatus2)
{
 case 0:
    digitalWrite(light2,LOW);
    break;
 case 1:
    digitalWrite(light2,HIGH);
    break;                 
}

switch (fanstatus2)
{
 case 0:
    digitalWrite(fan2,LOW);
    break;
 case 1:
    digitalWrite(fan2,HIGH);
    break;                 
}

  

}
