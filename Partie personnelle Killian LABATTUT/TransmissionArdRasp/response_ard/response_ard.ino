#include <SoftwareSerial.h>

SoftwareSerial mySerial(10,11);
char message[6];

void setup()
{
  pinMode(13, OUTPUT);
  mySerial.begin(9600);
}
void loop()
{
  //while (Serial.available())
  
  while (true)
  {
    for (int i=1 ; i<6 ; ++i)
    {
      message[i] = mySerial.read();
    }
    Serial.write(message);
    digitalWrite(13, HIGH);  
    delay(500);     
    digitalWrite(13, LOW);
  }
}
