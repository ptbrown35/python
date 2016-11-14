import time
import serial

# Establish the connection on a specific port
ser1 = serial.Serial('COM4', 9600) # Encoder Out - 2x12 Molex
# ser2 = serial.Serial('COM4', 9600) # Landing Controller In - Pickering
# counter = 32 # Below 32 everything in ASCII is gibberish

while True:
	#counter +=1
	#ser1.write('y') # Convert the decimal number to ASCII then send it to the Arduino
	print ser1.readline(1) # Read the newest output from the Arduino
	#time.sleep(.1) # Delay for one tenth of a second
	#if counter == 255:
	#	counter = 32