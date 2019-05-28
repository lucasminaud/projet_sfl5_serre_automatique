#include "RTClib.h"
//#include <Wire.h>
#define StationPin 3

void setup() 
{
  Serial.begin(9600);
  pinMode(StationPin, INPUT);
  //delay(2000);                    
  Serial.println("Ready!!!");   
}

void loop()
{
  if (digitalRead(StationPin) == HIGH)
  {
  Serial.println("blop");
  }
}
