
#include <Wire.h>
#include <TH02_dev.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_TSL2591.h"
#include "Arduino.h"
#include "Wire.h" 

class HYGRO

{
  public :  
  void init_()
  {
    Serial.begin(9600);
    TH02.begin();
  }
  
  
  double ReadHumidite()
  {
     init_();
     /*Serial.begin(9600);
     TH02.begin();*/
     float humidity = TH02.ReadHumidity(); //HYGRO
     return humidity;
  }
};
