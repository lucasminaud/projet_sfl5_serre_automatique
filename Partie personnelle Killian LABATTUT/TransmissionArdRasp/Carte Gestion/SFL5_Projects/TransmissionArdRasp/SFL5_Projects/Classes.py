#!/usr/bin/python3.4
# coding: utf-8
#Programme : Librairies et classes


import time
import mysql.connector 

class CAPTEUR:

    def __init__(self, idCap, hote, utilisateur, motDePasse, base):
	self.connexionBDD = mysql.connector.connect(host=hote,\
                                       user=utilisateur,\
                                       password=motDePasse,\
                                       database=base)
    def perAcquisition(self,idCap):
	curseur = self.connexionBDD.cursor()		
	data  = curseur.execute("SELECT `Periode_Acquisition` FROM `Capteur` WHERE `id` = %s " %(idCap))
	perAcquisition = curseur.fetchall()	
	return perAcquisition[0][0]	

class BDD:
    
    def __init__(self,hote,utilisateur,motDePasse,base):
        
        self.connexionBDD = mysql.connector.connect(host=hote,\
                                       user=utilisateur,\
                                       password=motDePasse,\
                                       database=base)

    def insererReleve(self, capVal, idCap):
        
        #inserer un releve dans la base de donnees
        #3 arguments : id du capteur valeur du capteur
        
        curseur = self.connexionBDD.cursor()
        curseur.execute("INSERT INTO `Releve` (`Valeur`,`Date`,`Capteur_id`) VALUES (%s,NOW(),%s)"%(capVal,idCap))
        self.connexionBDD.commit()
        curseur.close()
    def insererEtatCapteurPeriodeAcquisition(self, idCap, etat, perAcquisition):

        #inserer etat et période d'acquistion du capteur dans la base donnees
        #3 arguments : idcapteur etat et periode
        
        curseur = self.connexionBDD.cursor()
        curseur.execute("UPDATE `Capteur` SET `Etat_capteur`= %s,`Periode_Acquisition`= %s WHERE `id`=%s"%(etat,perAcquisition,idCap))
        self.connexionBDD.commit()
        curseur.close()

