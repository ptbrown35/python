import time
import serial

ser = serial.Serial('COM3', 9600) # Establish the connection on a specific port

def serial_killer():
	counter = 32 # Below 32 everything in ASCII is gibberish
	while True:
		counter += 1
		ser.write(str(chr(counter))) # Convert the decimal number to ASCII then send it to the Arduino
		print ser.readline() # Read the newest output from the Arduino
		time.sleep(.1) # Delay for one tenth of a second
		if counter == 255:
			counter = 32
