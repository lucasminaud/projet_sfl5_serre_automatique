import sys
import datetime
import time
import serial
sys.path.append('/home/pi/Documents/SFL5_Projects')
from Classes import BDD
from Classes import CAPTEUR
from Classes import SERIAL

#Cap = SERIAL(1,30)
#Cap.envoiMessage()

while True:
	ser = serial.Serial('/dev/ttyACM0',baudrate=9600)
	valeur = ser.readline()
	print (valeur)
