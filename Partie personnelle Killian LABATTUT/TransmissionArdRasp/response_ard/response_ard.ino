#include <SoftwareSerial.h>
#define nbcapteur 7
#define id 0
#define temps 1
#define perAc 2
SoftwareSerial mySerial(10,11);

class PERIODE
{
  public :
    int timeBefore = 0;
    int timeNow;
    int perAcquisition;
    
  bool testPerAcquisition( int timeNow, int perAcquisition)
  {
    
    if ( timeNow - timeBefore >= perAcquisition )
    {
      Serial.println(timeNow - timeBefore);
      timeBefore = timeNow;
      return true;
    }
    else
    {
      return false;
    }
  }
};

PERIODE *tab[nbcapteur];
String infoTab[3];

void init_capteurs()
{
  for(int i=0;i<nbcapteur;i++)
    tab[i] = new PERIODE();  
}

char valCap[nbcapteur];

//Variables
double valeur_capteur;

int int_idCap;
int int_timeNow;
int int_perAcquisition;



void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  init_capteurs();
}
void loop()
{ 
      //String data = Serial.readString();
      String data = "3,1556876122.17,15";
      int slot = 0;
      infoTab[id] = "";
      infoTab[temps] = "";
      infoTab[perAc] = "";
      for(int i=0;i<data.length();i++){
        if(data[i] != ','){
          infoTab[slot] += data[i];
        }else{
          slot++;
        }
      }
      int_idCap = infoTab[id].toInt();
      int_timeNow = infoTab[temps].toInt();
      int_perAcquisition = infoTab[perAc].toInt();
      
      if(tab[int_idCap]->testPerAcquisition(int_timeNow, int_perAcquisition))
         {
            switch(int_idCap)
            {
        case 1:
            valeur_capteur = 1;//mettre la fonction rapportant la valeur du capteur 1
            break;
        case 2:
            valeur_capteur = 2;//mettre la fonction rapportant la valeur du capteur 2
            break;
        case 3:
            valeur_capteur = 3;//mettre la fonction rapportant la valeur du capteur 3
            break;
        case 4:
            valeur_capteur = 4;//mettre la fonction rapportant la valeur du capteur 4
            break;
        case 5:
            valeur_capteur = 5;//mettre la fonction rapportant la valeur du capteur 5
            break;
        case 6:
            valeur_capteur = 6;//mettre la fonction rapportant la valeur du capteur 6
            break;
        case 7:
            valeur_capteur = 7;//mettre la fonction rapportant la valeur du capteur 7
            break;
            }
      Serial.println(infoTab[id] + " " + valeur_capteur);
      digitalWrite(13, HIGH);  
      delay(50);     
      digitalWrite(13, LOW);
          }
      else
      {
      /*valeur_capteur = 0;
      Serial.println(infoTab[id] + " " + valeur_capteur);*/
      }
   
    /*digitalWrite(13, HIGH);  
    delay(10);     
    digitalWrite(13, LOW);*/
  }
