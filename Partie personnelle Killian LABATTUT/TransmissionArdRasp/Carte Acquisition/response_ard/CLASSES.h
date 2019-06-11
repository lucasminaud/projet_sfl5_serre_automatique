#include <RTClib.h>

class PERIODE
{
  public :
    int timeBefore = 0;
    int timeNow = 0;
    int perAcquisition;

  bool testPerAcquisition( int timeNow, int perAcquisition)
  {
    
    if ( timeNow - timeBefore >= perAcquisition )
    {
      
      timeBefore = timeNow;
      return true;
    }
    if ( timeNow - timeBefore < perAcquisition )
    {
      return false;
    }
    if ( timeNow - timeBefore <= 0 )
    {
      
      timeBefore = 0;
      return true;
    }
  }
};
