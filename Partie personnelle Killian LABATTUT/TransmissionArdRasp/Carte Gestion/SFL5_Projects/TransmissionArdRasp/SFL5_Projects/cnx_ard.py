import sys
import serial
import time

message = "Hello"
mesrecu = "Goodbye"
code = 0
ser = serial.Serial('/dev/ttyACM0',baudrate=9600)
while (True):
	ser.write(message.encode())
	code = code + 1
	message = "Hello"+chr(code)
	mesrecu = ser.readline()
	time.sleep(0.5)
	print(mesrecu)




