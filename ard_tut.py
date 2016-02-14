import serial

connected = False

ser = serial.Serial('COM1')

while not connected:
	serin = ser.read()
	connected = True

ser.write('1')

while ser.read() == '1':
    ser.read()

## close the port and end the program
ser.close()
