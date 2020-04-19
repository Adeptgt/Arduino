#include "sav_button.h"
#include "Led.h"
SButton  but_mainlight(2,100,0,0,0);
SButton  but_islandlight(3,100,0,0,0);
SButton  but_illum(4,100,0,0,0);
Led ledmainlight(10,1);
Led ledillum(11,2);
int mainlight=5;
int islandlight=6;
int fan=7;


void setup() {
  // put your setup code here, to run once:
   but_mainlight.begin();
   but_islandlight.begin();
   but_illum.begin();
   ledmainlight.begin();
   ledillum.begin();
   pinMode(mainlight, OUTPUT); // Основной свет
   pinMode(islandlight, OUTPUT); // Островной светильник
   pinMode(fan, OUTPUT); // Вентилятор
   
   Serial.begin(115200);
   Serial.println("Start light system V0.7 alpha ...");
}

void loop() {
ledmainlight.Loop();
ledillum.Loop();



  // put your main code here, to run repeatedly:
switch( but_mainlight.Loop() ){
      case SB_RELEASE: 
         Serial.println("BUTTON mainlight RELEASE");
         digitalWrite(mainlight,LOW);
         ledmainlight.OFF();
         break;
      case SB_CLICK: 
         Serial.println("BUTTON mainlight CLICK");
         digitalWrite(mainlight,HIGH);
         ledmainlight.ON();
         break;
   }

switch( but_islandlight.Loop() ){  
      case SB_RELEASE: 
         Serial.println("BUTTON islandlight RELEASE");
         digitalWrite(islandlight,LOW);
         break;
      case SB_CLICK: 
         Serial.println("BUTTON islandlight CLICK");
         digitalWrite(islandlight,HIGH);
         break;
   }

switch( but_illum.Loop() ){
      case SB_RELEASE: 
         Serial.println("BUTTON illum RELEASE");    
         ledillum.OFF();
         break;
      case SB_CLICK: 
         Serial.println("BUTTON illum CLICK");
         ledillum.ON();
         break;
   }




}
