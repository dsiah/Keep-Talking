# from time import sleep

import serial

ser = serial.Serial('/dev/cu.usbmodem1421', 9600) # Establish the connection on a specific port
c1, c2 = 0, 0 # Below 32 everything in ASCII is gibberish
# Example of Writing to the serial
# ser.write('string here')

while True:
	text = ser.readline()
	
	# Determine message
	if ('1: ON' in text):
		c1 += 1
		print('1: ON', c1)

	if ('2: ON' in text):
		c2 += 1
		print('2: ON', c2)
	# sleep(.1) # Delay for one tenth of a second