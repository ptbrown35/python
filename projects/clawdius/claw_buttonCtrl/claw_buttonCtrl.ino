/*
   Button controlled servo.
   Hardware:
            Servo connected to 5V, GND, and D10
            Button connected to 3.3V and D0
*/

#include <Servo.h>

#define buttonPin        4 // set button pin for servo control
#define buttonServoPin   10 // set button controlled servo to digital pin 9
#define plusIncrement    1 // set positive increment value
#define minusIncrement   -1 // set negative increment value

Servo buttonServo; // initialize Servo

int buttonServoPos = 0; // initialize buttonServoPos at neutral position

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 

// the setup routine runs once when you press reset:
void setup() {

  Serial.begin(9600); // initialize serial communication at 9600 bits per second:

  pinMode(buttonPin, INPUT);
  buttonServo.attach(buttonServoPin); // initialize servo on potServoPin

}

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 

// the loop routine runs over and over again forever:
void loop() {

  buttonServoPos = buttonCtrlPlus(buttonPin, buttonServoPos, plusIncrement);
  buttonServoPos = buttonCtrlMinus(buttonPin, buttonServoPos, minusIncrement);
  buttonServo.write(buttonServoPos);
  

  Serial.print("Current Position\t");
  Serial.println(buttonServoPos);

  delay(50);
}

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 

int buttonCtrlPlus(int digitalPin, int currentPos, int increment) {
  if (currentPos >= 180) {
    // do nothing
  } else {
    int val = digitalRead(digitalPin); // read button input

    if (val == HIGH) {
      currentPos += increment;
    }
  }

  return currentPos;
  
}

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 

int buttonCtrlMinus(int digitalPin, int currentPos, int decrement) {
  if (currentPos <= 0) {
    // do nothing
  } else {
    int val = digitalRead(digitalPin); // read button input

    if (val == LOW) {
      currentPos += decrement;
    }
  }

  return currentPos;

}

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 

