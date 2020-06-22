#include "sav_button.h"
#include "Led.h"
SButton  but_mainlight(2,100,500,1000,500);
SButton  but_led(3,100,0,0,0);
SButton  but_spot(4,100,0,0,0);
Led ledlight(5,3);
int spotlight=6;
int mlight1=8;
int mlight2=9;
int mlight3=10;
int mlight4=11;
int lstatus=0;
int ldirection=1; 
void setup() {
  // put your setup code here, to run once:
   but_mainlight.begin();
   but_led.begin();
   but_spot.begin();
   ledlight.begin();
   pinMode(spotlight, OUTPUT);
   pinMode(mlight1, OUTPUT);
   pinMode(mlight2, OUTPUT);
   pinMode(mlight3, OUTPUT);
   pinMode(mlight4, OUTPUT);

   
   Serial.begin(115200);
   Serial.println("Start light system V0.7 alpha ...");
}

void loop() {
ledlight.Loop();
switch( but_led.Loop() ){
      case SB_RELEASE: 
         Serial.println("BUTTON led RELEASE");    
         ledlight.OFF();
         break;
      case SB_CLICK: 
         Serial.println("BUTTON led CLICK");
         ledlight.ON();
         break;
   }

switch( but_spot.Loop() ){  
      case SB_RELEASE: 
         Serial.println("BUTTON spotlight RELEASE");
         digitalWrite(spotlight,LOW);
         break;
      case SB_CLICK: 
         Serial.println("BUTTON spotlight CLICK");
         digitalWrite(spotlight,HIGH);
         break;
   }




switch( but_mainlight.Loop() ){
      case SB_AUTO_CLICK:
         Serial.print("BUTTON 1 SB_AUTO_CLICK ");
         if(ldirection==0 && lstatus>1){lstatus--;}
         else if(ldirection==1 && lstatus<4){lstatus++;}
         Serial.println(lstatus);
         break;
      case SB_RELEASE: 
         Serial.println("BUTTON 1 RELEASE");
         if(ldirection==0){ldirection=1;}
         else if(ldirection==1){ldirection=0;}
         break;
      case SB_CLICK: 
         Serial.println("BUTTON 1 CLICK");
         if(lstatus==0){lstatus=4; ldirection=0;}
         else {lstatus=0; ldirection=1;}
         break;  
   }

switch (lstatus)
{
 case 0:
    digitalWrite(mlight1,LOW);
    digitalWrite(mlight2,LOW);
    digitalWrite(mlight3,LOW);
    digitalWrite(mlight4,LOW);
    break;
 case 1:
    digitalWrite(mlight1,HIGH);
    digitalWrite(mlight2,LOW);
    digitalWrite(mlight3,LOW);
    digitalWrite(mlight4,LOW);
    break;
 case 2:
    digitalWrite(mlight1,HIGH);
    digitalWrite(mlight2,LOW);
    digitalWrite(mlight3,LOW);
    digitalWrite(mlight4,HIGH);
    break;
 case 3:
    digitalWrite(mlight1,HIGH);
    digitalWrite(mlight2,HIGH);
    digitalWrite(mlight3,LOW);
    digitalWrite(mlight4,HIGH);
    break;
 case 4:
    digitalWrite(mlight1,HIGH);
    digitalWrite(mlight2,HIGH);
    digitalWrite(mlight3,HIGH);
    digitalWrite(mlight4,HIGH);
    break;                    
}


  

}
