/*
 * Potentiometer controlled servo.
 * Hardware:
 *          Servo connected to 5V, GND, and D9
 *          Potentiometer connected to 5V, GND, and A0
*/

#include <Servo.h>

#define potPin        A0 // set potentiometer pin for servo control
#define potServoPin   9 // set potentiometer controlled servo to digital pin 9

Servo potServo; // initialize Servo

// the setup routine runs once when you press reset:
void setup() {
  
  Serial.begin(9600); // initialize serial communication at 9600 bits per second:

  potServo.attach(potServoPin); // initialize servo on potServoPin
  
}

// the loop routine runs over and over again forever:
void loop() {
  potServo.write(potCtrl(potPin));
  
  delay(15);
}

int potCtrl(int analogPin){
  int potVal = analogRead(analogPin); // read potentiometer input
  int potServoCtrl = map(potVal, 0, 1023, 0, 180); // map 8-bit analog read to 0-180 servo control

  Serial.print("Servo Position\t");
  Serial.print(potServoCtrl);
  Serial.print("\t");
  Serial.print("ADC Val\t");
  Serial.println(potVal);
  Serial.print("\t");
  
  return potServoCtrl;
}

