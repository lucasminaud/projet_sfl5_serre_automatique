

//Include this library for using current loop functions.
#include <currentLoop.h>
#define CHANNEL CHANNEL4


void setup()
{
  //Inits the Serial for viewing data in the serial monitor.
  Serial.begin(9600);

  //Switch ON the 24V DC-DC converter
  sensorBoard.ON();

  delay(100);
  Serial.println("Arduino 4-20mA board switched ON...");
}

float conversion (float current)
{
float Temp = 0;
Temp = 100*((current-4)/16);
return Temp;
}

float Get_temp ()
{
if (sensorBoard.isConnected(CHANNEL))
{
float current = sensorBoard.readCurrent(CHANNEL);
return (conversion (current));
}
else
{
  Serial.println("the sensor board is not connected ..."); 
}
}

void loop()
{
 Get_temp();
}



