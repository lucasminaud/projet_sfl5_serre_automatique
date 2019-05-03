import serial
import time

ser = serial.Serial('/dev/ttyACM0',9600)

while(True):
	
	mesrecu = ser.readline()
	print (mesrecu)	
