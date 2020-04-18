/** 
 *Управление насосом
*/
#include "ledlight.h"

Light Light1(7,20000,10000);
int state=0;
unsigned int checkint=1000;
unsigned long checktime;
unsigned long timeout=60000;
unsigned long wtime=0;

void setup()
{
 Serial.begin(9600);
 Serial.println("Test Light ...");
 Light1.begin();
}

void loop()
{  
   

  if(millis()-wtime>timeout)
  { 
    
    if(Light1.status()>0){Light1.stop(); 
    Serial.print(wtime); 
    Serial.println(" send comand Light stop"); 
    } 
    else {Light1.start(); Serial.print(wtime); Serial.println(" send comand  Light start");}
    wtime=millis();
  }
  if(millis()-checktime>checkint)
  { Light1.Loop();
    Serial.print("Status: ");
    Serial.println(Light1.status());
    Serial.print("time left: ");
    Serial.println(millis()-wtime);
    Serial.print(" for timeout: ");
    Serial.println(timeout-(millis()-wtime));
    checktime=millis();
  }

}