/** 
 *Управление светом
*/
#include "Led.h"
#include "sav_button.h"
Led Led2(11,1);
Led Led1(10,1);
SButton  lbut1(2,100,0,0,0);
SButton  lbut2(3,100,0,0,0);
int Level;
void setup()
{
 Serial.begin(115200);
 Serial.println("Test Led ...");
 Led1.begin();
 lbut1.begin();
 lbut2.begin();
}

void loop()
{  
   
switch( lbut1.Loop() ){
  
      case SB_RELEASE: 
         Serial.println("BUTTON 1 RELEASE");
         Led1.OFF();
         break;
      case SB_CLICK: 
         Serial.println("BUTTON 1 CLICK");
         Led1.ON();
         break;
   }
  
switch( lbut2.Loop() ){
  
      case SB_RELEASE: 
         Serial.println("BUTTON 1 RELEASE");
         Level = 40;
         break;
      case SB_CLICK: 
         Serial.println("BUTTON 1 CLICK");
         Level = 500;
         break;
   }
Led2.SET(Level);
 
 Serial.print("Led 1 level: ");
  Serial.println(Led1.Loop());
   Serial.print("Led 2 level: ");
    Serial.println(Led2.Loop());


}