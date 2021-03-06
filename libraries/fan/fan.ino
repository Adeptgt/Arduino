/** 
 *Управление насосом
*/
#include "Fan.h"

Fan Fan1(7,20000,10000);
int state=0;
unsigned int checkint=1000;
unsigned long checktime;
unsigned long timeout=60000;
unsigned long wtime=0;

void setup()
{
 Serial.begin(9600);
 Serial.println("Test Fan ...");
 Fan1.begin();
}

void loop()
{  
   

  if(millis()-wtime>timeout)
  { 
    
    if(Fan1.status()>0){Fan1.stop(); 
    Serial.print(wtime); 
    Serial.println(" send comand Fan stop"); 
    } 
    else {Fan1.start(); Serial.print(wtime); Serial.println(" send comand  Fan start");}
    wtime=millis();
  }
  if(millis()-checktime>checkint)
  { Fan1.Loop();
    Serial.print("Status: ");
    Serial.println(Fan1.status());
    Serial.print("time left: ");
    Serial.println(millis()-wtime);
    Serial.print(" for timeout: ");
    Serial.println(timeout-(millis()-wtime));
    checktime=millis();
  }

}