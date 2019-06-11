#include <Wire.h>
#include <TH02_dev.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_TSL2591.h"
#include "Arduino.h"
#include "Wire.h" 

void init()
{
  Serial.begin(9600);
  TH02.begin();
}


void setup() {
   void init();
   float humidity = TH02.ReadHumidity(); //HYGRO
   Serial.print(humidity);
}

void loop() {
  // put your main code here, to run repeatedly:

}
