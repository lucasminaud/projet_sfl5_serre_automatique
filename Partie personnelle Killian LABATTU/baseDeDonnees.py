
#!/usr/bin/python3.4
# coding: utf-8
"""
Programme : Application base de données
Auteur : L.Burban
Date : 26-02-2019
Fonction :
    gestion de la base de données
"""
import time
import mysql.connector 

class BDD:
    
    def __init__(self,hote,utilisateur,motDePasse,base):
        
        self.connexionBDD = mysql.connector.connect(host=hote,\
                                       user=utilisateur,\
                                       password=motDePasse,\
                                       database=base)
        
    def liretable(self,element,table):
        """
        permet de lire un element une table
        2 argument
        1er argument : element a lire
        2eme argument : nom de la table
        """
        curseur = self.connexionBDD.cursor()
        curseur.execute("SELECT %s FROM %s"%(element,table))
        for row in curseur.fetchall() :
            user = str(row[0])
            print(user)
        curseur.close()
    def liretout(self,table):
        """
        Permet de lire toute les données d'une table
        1 argument
        1er argument : nom de la table a lire
        """
        curseur = self.connexionBDD.cursor()
        curseur.execute("SELECT * FROM %s"%(table))
        for row in curseur.fetchall():
            result = str(row[0]), str(row[1]), str(row[2]),str(row[4]), str(row[5]), str(row[6])
            print(result)
        curseur.close()
    def insererAccident(self, degat,zone):
        """
        inserer un accident dans la base de donnees
        2 arguments
        1er argument : dégat
        2eme argument : zone du dégat
        """
        curseur = self.connexionBDD.cursor()
        curseur.execute("INSERT INTO `accident` (`idAccident`, `date`, `degat`, `zone`) VALUES (NULL, CURRENT_TIMESTAMP, '%s', '%s')"%(degat,zone))
        self.connexionBDD.commit()
        curseur.close()
    def insererCoordoneesGPS(self,posx,posy,vitesse,angle,direction):
        """
        inserer un accident dans la base de donnees
        3 arguments
        1er argument : position X
        2eme argument : position Y
        3eme argument : vitesse
        4eme argument : angle /!\ type int
        5eme argument : direction /!\ 4 charactère maximum (NORD,SUD,EST,OUEST)
        """
        curseur = self.connexionBDD.cursor()
        curseur.execute("INSERT INTO `gps` (`idGPS`,`pos_x`,`pos_y`,`vitesse`,`angle`,`direction`,`date`) VALUES (NULL,'%s','%s','%s','%d','%s',CURRENT_TIMESTAMP)"%(posx,posy,vitesse,angle,direction))
        self.connexionBDD.commit()
        curseur.close()
        
        
        
        
        
        
