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
Cap = SERIAL()

while True :
	perAcqu = MyDB.recuperationPeriodeAcquisition(i)
	Cap.envoiMessage(i,perAcqu)
	valeur = Cap.recupereValeur()
	tab = valeur.split(',')
	if (len(valeur) > 5):
		if (len(tab[0]) > 0 and len(tab[1]) > 2):
#			print(tab[0])
#			print(tab[1])
			print (valeur)
			MyDB.insererReleve(tab[0],tab[1])
			MyDB.insererEtatCapteurPeriodeAcquisition(i, 1, perAcqu)
		else:
			if(len(tab[0]) >= 30):
				print (valeur)

	if i == 7:
		i = 1
	else:
		i += 1

