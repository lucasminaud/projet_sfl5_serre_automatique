#include <SoftwareSerial.h>
//String message = "Hello";
char message[6] = {'H','E','L','L','O','\n'};
/*
void envoyer(String stringData) { // Used to serially push out a String with Serial.write()
  char * buffer;
  buffer = (char *) malloc(stringData.length() + 1);
  int i;
  for (i = 0; i < stringData.length(); i++)
  {
     buffer[i] = stringData[i];
  }
  buffer[i] = '\n';

  Serial.write(buffer);   // Push each char 1 by 1 on each loop pass
}
*/
void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  while (true)
  {
    //envoyer(message);
    Serial.write(message);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
  }
}
