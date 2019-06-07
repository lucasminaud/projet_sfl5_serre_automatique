#define WindSensorPin (2) // The pin location of the anemometer sensor

    
class ANEMOM
{
    public :
      float WindSpeed; // speed miles per hour

      static unsigned long Rotations; // cup rotation counter used in interrupt routine
      static unsigned long ContactBounceTime; // Timer to avoid contact bounce in interrupt routine
  
  double getSpeed()
  {
   Rotations = 0; // Set Rotations count to 0 ready for calculations
  sei(); // Enables interrupts
  delay (1000); // Wait 1 seconds to average
  cli(); // Disable interrupts
  WindSpeed = Rotations * 2.25;
  WindSpeed = WindSpeed * 1.60934; //to m/s
  return WindSpeed;
  }


 static void isr_rotation () 
  {
   if ((millis() - ContactBounceTime) > 15 ) // debounce the switch contact.
    {
      Rotations++;
      ContactBounceTime = millis();
    }
  }

  void init()
  {
    pinMode(WindSensorPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(WindSensorPin), isr_rotation, FALLING);
  }

  double Speed()
  {
    init();
    double Speed = getSpeed();
    return Speed;
  }
 
};

unsigned long ANEMOM::Rotations = 0; // Déclaration des variable : static
unsigned long ANEMOM::ContactBounceTime = 0; 