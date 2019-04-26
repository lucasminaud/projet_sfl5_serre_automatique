
#include "RTClib.h"
#include <Wire.h>
#define RainPin 2                         // The Rain input is connected to digital pin 2 on the arduino


bool bucketPositionA = false;             // one of the two positions of tipping-bucket               
const double bucketAmount = 0.254;   // inches equivalent of ml to trip tipping-bucket
double dailyRain = 0.0;                   // rain accumulated for the day
double hourlyRain = 0.0;                  // rain accumulated for one hour
double minutRain = 0.0;                   // rain accumulated for one minute
double impulsion = 0.0;                   // nombre d'impulsion
double dailyRain_till_LastHour = 0.0;     // rain accumulated for the day till the last hour          
bool first;                               // as we want readings of the (MHz) loops only at the 0th moment 

RTC_Millis rtc;                           // software RTC time


void setup(void) {
  Serial.begin(9600);                            // start the serial port
  rtc.begin(DateTime(__DATE__, __TIME__));       // start the RTC
  pinMode(RainPin, INPUT);                       // set the Rain Pin as input.
  delay(2000);                                   // i'm slow in starting the serial monitor (not necessary)
  Serial.println("Ready!!!");                    // not necessary too
}


void loop(void){
  DateTime now = rtc.now();
    
  // ++++++++++++++++++++++++ compte les impulsions ++++++++++++++++++++++++++++++++
  if ((bucketPositionA==false)&&(digitalRead(RainPin)==HIGH)){
    bucketPositionA=true;
    dailyRain+=bucketAmount;                               // met à jour la pluie journalière
    Serial.println();
    Serial.print(" Impulsion !" );
  }
  
  if ((bucketPositionA==true)&&(digitalRead(RainPin)==LOW)){
    bucketPositionA=false;  
  } 
  // +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  
  if(now.minute() != 0) first = true;                     // after the first minute is over, be ready for next read
  
  if(now.minute() == 0 && first == true){
 
    hourlyRain = dailyRain - dailyRain_till_LastHour;      // calculate the last hour's rain
    dailyRain_till_LastHour = dailyRain;                   // update the rain till last hour for next calculation
    
    // fancy display for humans to comprehend
    Serial.println();
    Serial.print(now.hour());
    Serial.print(":");
    Serial.print(now.minute());
    Serial.print(":  Quantité totale de pluie tombé dans la journée = ");
    Serial.print(dailyRain,8);                            // the '8' ensures the required accuracy
    Serial.println(" mm");
    Serial.println();
    Serial.print("     :  Quantité de pluie tombée dans la dernière heure = ");
    Serial.print(hourlyRain,8);
    Serial.println(" mm");
    Serial.println();
    
    first = false;                                        // execute calculations only once per hour
  }
  
  if(now.hour()== 0) {
    dailyRain = 0.0;                                      // clear daily-rain at midnight
    dailyRain_till_LastHour = 0.0;                        // we do not want negative rain at 01:00
  }  
}                                                        // end of loop
