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

  double init()
  {
  VaneValue = analogRead(A0);
  Direction = map(VaneValue, 0, 1023, 0, 360);
  CalDirection = Direction + Offset;
  if(CalDirection > 360)
  CalDirection = CalDirection - 360;

  if(CalDirection < 0)
  CalDirection = CalDirection + 360;
  return CalDirection;
  }
     
  double DirectionVent()
  {
   double Dir = init();
   return Dir;
   LastValue = CalDirection;
  }
  
};

GIROUETTE G1;
void setup() {
Serial.begin(9600);
double Dir = G1.DirectionVent();
Serial.println(Dir);
}

void loop() {
  //DirectionVent()
}
