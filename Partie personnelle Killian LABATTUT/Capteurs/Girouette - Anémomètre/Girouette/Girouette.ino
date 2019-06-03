int VaneValue;// raw analog value from wind vane
int Direction;// translated 0 - 360 direction
int CalDirection;// converted value with offset applied
int LastValue;

#define Offset 0;

class GIROUETTE
{
  public :
    int VaneValue = analogRead(A0);
    int Direction = map(VaneValue, 0, 1023, 0, 360);
    int CalDirection = Direction + Offset;
    int LastValue = 1;

  void init()
  {
  VaneValue = analogRead(A0);
  Direction = map(VaneValue, 0, 1023, 0, 360);
  CalDirection = Direction + Offset;
  if(CalDirection > 360)
  CalDirection = CalDirection - 360;

  if(CalDirection < 0)
  CalDirection = CalDirection + 360;
  }
  void getHeading(int direction)
  {
  if(direction < 22)
  Serial.println("N");
  else if (direction < 67)
  Serial.println("NE");
  else if (direction < 112)
  Serial.println("E");
  else if (direction < 157)
  Serial.println("SE");
  else if (direction < 212)
  Serial.println("S");
  else if (direction < 247)
  Serial.println("SW");
  else if (direction < 292)
  Serial.println("W");
  else if (direction < 337)
  Serial.println("NW");
  else
  Serial.println("N");
  } 
    
  void DirectionVent ()
  {
   init();
   getHeading(CalDirection);
   LastValue = CalDirection;
  }
  
};

GIROUETTE G1;
void setup() {
Serial.begin(9600);
G1.DirectionVent();
}

void loop() {
  //DirectionVent()
}
