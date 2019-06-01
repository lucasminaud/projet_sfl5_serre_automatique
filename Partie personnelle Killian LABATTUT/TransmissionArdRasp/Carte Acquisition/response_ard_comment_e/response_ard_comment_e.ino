#include <SoftwareSerial.h>
#define nbcapteur 8
#define id 0
#define temps 1
#define perAc 2
SoftwareSerial mySerial(10,11);

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
    else
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
   String data = "";                      // La chaîne de caractère data est réinitialisé.
   data = Serial.readString();            // La chaîne de caractères data est initialisé à la lecture du port série.
   int slot = 0;                          // Déclaration d'un slot.
   infoTab[id] = "";                      //
   infoTab[temps] = "";                   // Initalisation des 3 champs du tableau infoTab
   infoTab[perAc] = "";                   //
   for(int i=0;i<data.length();i++){      // Cette boucle for découpe la chaîne de caractère et initialise une par une les cases de infoTab.
        if(data[i] != ',')
        {
          infoTab[slot] += data[i];       // La case du tableau correspondant à la position du slot est inialisé.
        }
        else
        {
          slot++;                         // Si le découpage rencontre une virgule le programme écrit dans la case suivante du tableau.
        }
      }
   int_idCap = infoTab[id].toInt();                                                   // Les informations sont convertit en int pour pouvoir effectuer le calcul de période
   int_timeNow = infoTab[temps].toInt();
   int_perAcquisition = infoTab[perAc].toInt();

    //Serial.println(int_idCap);
    //Serial.println(int_timeNow);
    //Serial.println(int_perAcquisition);
      
   if(tab[int_idCap]->testPerAcquisition(int_timeNow,int_perAcquisition))             // Une fois chaque informations découpés le calcul est effectué
       {
           switch(int_idCap)
           {
        case 1:
            valeur_capteur = rand() % 100;//mettre la fonction rapportant la valeur du capteur 1 //A ce stade du projet l'intégration des capteurs n'est pas réalisé.
            break;
        case 2:
            valeur_capteur = rand() % 100;//mettre la fonction rapportant la valeur du capteur 2 // Les valeurs sont choisis aléatoirement pour pouvoir effectué des tests.
            break;
        case 3:
            valeur_capteur = rand() % 100;//mettre la fonction rapportant la valeur du capteur 3
            break;
        case 4:
            valeur_capteur = rand() % 100;//mettre la fonction rapportant la valeur du capteur 4
            break;
        case 5:
            valeur_capteur = rand() % 100;//mettre la fonction rapportant la valeur du capteur 5
            break;
        case 6:
            valeur_capteur = rand() % 100;//mettre la fonction rapportant la valeur du capteur 6
            break;
        case 7:
            valeur_capteur = rand() % 100;//mettre la fonction rapportant la valeur du capteur 7
            break;
           }
      Serial.println(infoTab[id] + "," + valeur_capteur);           // La valeur du capteur est envoyée via le port série
      digitalWrite(13, HIGH);
      delay(50);                                                    // La led clignote on commentera ces lignes pour plus de rapidité   
      digitalWrite(13, LOW);
      }
      else
           {
            valeur_capteur = 0;
            Serial.println("Le capteur " + infoTab[id] + " doit encore attendre,");// Si la fonction de calcul retourne "false" un message d'attente envoyé ainsi qu'une valeur de 0
           }
   
    /*digitalWrite(13, HIGH);  
    delay(10);     
    digitalWrite(13, LOW);*/
   
  }
