int message = 5;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  
  while (Serial.available())
  {
    message = Serial.read()-'0';  // on soustrait le caractère 0, qui vaut 48 en ASCII
    Serial.println(message);
  }
  Serial.println(message);
  delay(5000);
}
