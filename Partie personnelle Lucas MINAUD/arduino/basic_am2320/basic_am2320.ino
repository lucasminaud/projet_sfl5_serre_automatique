#include "Adafruit_Sensor.h"
#include "Adafruit_AM2320.h"

Adafruit_AM2320 am2320 = Adafruit_AM2320();

int sensorPin = A0;
int sensorValue = 0;
int finalValue = 0;

void setup() {
    Serial.begin(9600);
}
void loop() {
    // read the value from the sensor:
    sensorValue = analogRead(sensorPin);
    finalValue = (sensorValue-49)*100/171;
    Serial.print("Moisture = " );
    Serial.println(finalValue);
    Serial.print("Valeur brute : ");
    Serial.println(sensorValue);
    delay(1000);
}
