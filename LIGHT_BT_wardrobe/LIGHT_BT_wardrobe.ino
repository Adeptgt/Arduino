#include "sav_button.h"
SButton  lbut1(2,100,500,1000,500);
SButton  lbut_sauna(3,100,0,0,0);
int light1=4;
int light2=5;
int light_sauna=6;
//int light3=6;
int lstatus=0;
int lstatus_sauna=0;
int ldirection=1; 
int ldirection_sauna=1; 
void setup() {
  // put your setup code here, to run once:
   lbut1.begin();
   lbut_sauna.begin();
   pinMode(light1, OUTPUT);
   pinMode(light2, OUTPUT);
   pinMode(light_sauna, OUTPUT);

   
   Serial.begin(115200);
   Serial.println("Start light system V0.7 alpha ...");
}

void loop() {
switch( lbut_sauna.Loop() ){
      case SB_AUTO_CLICK:
      Serial.println("BUTTON 1 SB_AUTO_CLICK");
      if(ldirection_sauna==0 && lstatus_sauna>1){lstatus_sauna--;}
      else if(ldirection_sauna==1 && lstatus_sauna<1){lstatus_sauna++;}
      break;
      case SB_RELEASE: 
         Serial.println("BUTTON 1 RELEASE");
         if(ldirection_sauna==0){ldirection_sauna=1;}
         else if(ldirection_sauna==1){ldirection_sauna=0;}
         break;
      case SB_CLICK: 
         Serial.println("BUTTON 1 CLICK");
         if(lstatus_sauna==0){lstatus_sauna=1; ldirection_sauna=0;}
         else {lstatus_sauna=0; ldirection_sauna=1;}
         break; 
   }


  // put your main code here, to run repeatedly:
switch( lbut1.Loop() ){
      case SB_AUTO_CLICK:
      Serial.println("BUTTON 1 SB_AUTO_CLICK");
      if(ldirection==0 && lstatus>1){lstatus--;}
      else if(ldirection==1 && lstatus<2){lstatus++;}
      break;
      case SB_RELEASE: 
         Serial.println("BUTTON 1 RELEASE");
         if(ldirection==0){ldirection=1;}
         else if(ldirection==1){ldirection=0;}
         break;
      case SB_CLICK: 
         Serial.println("BUTTON 1 CLICK");
         if(lstatus==0){lstatus=2; ldirection=0;}
         else {lstatus=0; ldirection=1;}
         break;  
   }

switch (lstatus)
{
 case 0:
    digitalWrite(light1,LOW);
    digitalWrite(light2,LOW);
    break;
 case 1:
    digitalWrite(light1,HIGH);
    digitalWrite(light2,LOW);

    break;
 case 2:
    digitalWrite(light1,HIGH);
    digitalWrite(light2,HIGH);
    break;
              
}

switch (lstatus_sauna)
{
 case 0:
    digitalWrite(light_sauna,LOW);
    break;
 case 1:
    digitalWrite(light_sauna,HIGH);
    break;

              
}



  

}
