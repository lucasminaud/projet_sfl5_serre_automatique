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
  if(CalDirection > 360){
    CalDirection = CalDirection - 360;
    }
  if(CalDirection < 0){
    CalDirection = CalDirection + 360;
    }
  return CalDirection;
  }
  
    
  double DirectionVent()
  {
   double Direction = init();
   return Direction;
   LastValue = CalDirection;
  }
  
};
