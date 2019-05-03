				#Programme Acquisition

#Connexion BDD
import sys
import datetime
import time
sys.path.append('/home/pi/Documents/SFL5_Projects')
from Classes import BDD
from Classes import CAPTEUR
from Classes import SERIAL

MyDB = BDD("10.16.37.161","sfl5","sfl5db","BDD_Serre_Automatique")

				#Boucle Demande Valeurs Capteur

i = 1

while True :
	valeur = 10
	perAcqu = MyDB.recuperationPeriodeAcquisition(i)
	
	Cap = SERIAL(i, perAcqu)
	Cap.envoiMessage()

	valeur = Cap.recupereValeur()
	print (valeur)
	if valeur != 0:
#		MyDB.insererReleve(i,valeur)
#		MyDB.insererEtatCapteurPeriodeAcquisition(i, 1, perAcqu)

		if i == 7:
			i = 1
		else:
			i += 1

