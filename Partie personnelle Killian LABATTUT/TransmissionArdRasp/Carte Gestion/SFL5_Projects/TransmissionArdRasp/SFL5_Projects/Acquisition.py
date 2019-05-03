#Programme Acquisition

#Connexion BDD
import sys
sys.path.append('/home/pi/Documents/SFL5_Projects')
from Classes import BDD
from Classes import CAPTEUR

MyDB = BDD("10.16.37.161","sfl5","sfl5db","BDD_Serre_Automatique")

#MyDB.insererEtatCapteurPeriodeAcquisition('4','1','120')

CapTempInt = CAPTEUR('3',"10.16.37.161","sfl5","sfl5db","BDD_Serre_Automatique")
print(CapTempInt.perAcquisition('3'))
