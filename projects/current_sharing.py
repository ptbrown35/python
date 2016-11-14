import math

temp = range(20,176,1)

rdson = []
x = 20
m = 10.0*(3-1)/(175-20)
print m
b = 10

while x < 176:
	y = m * x + b
	rdson.append(y)	
	x += 1

