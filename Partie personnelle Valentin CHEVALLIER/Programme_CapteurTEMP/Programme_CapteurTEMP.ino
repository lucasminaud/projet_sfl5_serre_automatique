

//Librairie qui permet de communiquer avec le shield boucle 4-20 Ma
#include <currentLoop.h> 
#define CHANNEL CHANNEL4  //definition du Channel qu'on souhaite écouter


void setup()
{
  //Inits the Serial for viewing data in the serial monitor.
  Serial.begin(9600);

  //Switch ON the 24V DC-DC converter
  sensorBoard.ON();

  delay(100);
  Serial.println("Arduino 4-20mA board switched ON...");  //inform the user 
}

float conversion (float current)
{
  if(current >= 4 && current <= 20)
  {
    float Temp = 0;     
 Temp = 100*((current-4)/16);  //formule de conversion
return Temp;
}

else {return(200);}
}

int Get_temp ()
{
if (sensorBoard.isConnected(CHANNEL))
{
   float current = sensorBoard.readCurrent(CHANNEL);
   return (conversion (current));
   //Serial.println(conversion (current));
}
else
{
  Serial.println("the sensor board is not connected ..."); 
}
}

void Test_conversion()
{
  int Test = 0;
float courant1 = 20;
if(conversion(courant1) == 100)
  {
    Serial.println("TEST[SUCESS]");
    Test ++;
    Serial.println("Test 1/3");
  }
  else
  {
    Serial.println("TEST[FAILURE] Expected :100 °C");
  }
  float courant2 = 4;
if(conversion(courant2) == 0)
{
    Serial.println("TEST[SUCESS]");
    Test ++;
    Serial.println("Test 2/3");
  }
  else{
    Serial.println("TEST[FAILURE] Expected :0 °C");
  }
  float courant3 = 50;
if(conversion(courant3) == 200)
{
    Serial.println("TEST[SUCESS]");
    Test ++;
    Serial.println("Test 3/3");
  }
  else
  {
    Serial.println("TEST[FAILURE] Must be :200 -> Error ");
  }
  if(Test == 3)
  {
    Serial.println("Tout les test ont été reussi");
    exit;
  }
}
void loop()
{
 //Get_temp();
 //delay(100);
 Test_conversion();
 delay(100000);
}



