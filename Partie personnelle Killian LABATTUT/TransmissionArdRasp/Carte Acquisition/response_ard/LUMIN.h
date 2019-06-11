#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_TSL2591.h"
#include "Arduino.h"
#include "Wire.h" 

Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591);

class LUMIN
{
  public :
  double value;
  void init_()
  {
    Serial.begin(9600);
    sensor_t sensor;
    tsl.getSensor(&sensor);
    tsl.setGain(TSL2591_GAIN_MED);
    tsl.setTiming(TSL2591_INTEGRATIONTIME_100MS);
  }
  
  
  double unifiedSensorAPIRead()
  {
    /* Get a new sensor event */ 
    sensors_event_t event;
    tsl.getEvent(&event);
   
    if ((event.light == 0) |
        (event.light > 4294966000.0) | 
        (event.light <-4294966000.0))
    {
      /* If event.light = 0 lux the sensor is probably saturated */
      /* and no reliable data could be generated! */
      /* if event.light is +/- 4294967040 there was a float over/underflow */
    }
    else
    {
      value = (event.light);
      return value;
    }
  }
  
  double getHumidite() 
  {
   init_();
   unifiedSensorAPIRead();  
  }
};
