import serial
import time
ser = serial.Serial('/dev/ttyACM0',9600)

idCap = 0
capVal = 0
perAcquisition = 0
compteur = 0

def SerialReponse()
	mesrecu = ser.readline()
	return mesrecu	

while(True):
	trame = SerialReponse()
	for i in trame
		if compteur = 0	
			idCap = i
		if compteur = 1
			valCap = i
		if compteur = 2
			perAcquision = i
	
