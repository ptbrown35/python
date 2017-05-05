/*
 * Clawdius servo contoller.
 * Hardware:
 *          Servos connected to 5V, GND, and [D6 D9 D10 D11]
 *          Potentiometer connected to 5V, GND, and A0
 *          Buttons connected to 3.3V and [D1 D2 D3 D4]
*/

#include <Servo.h>

// Potentiometer controlled servo
Servo potServo; // initialize Servo
#define potPin        A0 // set potentiometer pin for servo control
#define potServoPin   11 // set potentiometer controlled servo to D5

// Button controlled servo #1
Servo buttonServo_1; // initialize Servo
int buttonServoPos_1 = 0; // initialize buttonServoPos at neutral position
#define buttonServoPin_1   9 // set button controlled servo to D6
#define buttonPin_1        1 // set button pin for servo control to D1
#define buttonPin_2        2 // set button pin for servo control to D2

// Button controlled servo #2
Servo buttonServo_2; // initialize Servo
int buttonServoPos_2 = 0; // initialize buttonServoPos at neutral position
#define buttonServoPin_2   10 // set button controlled servo to D9
#define buttonPin_3        3 // set button pin for servo control to D3
#define buttonPin_4        4 // set button pin for servo control to D4

#define plusIncrement    1 // set positive increment value
#define minusIncrement   -1 // set negative increment value

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 

// the setup routine runs once when you press reset:
void setup() {
  
  Serial.begin(9600); // initialize serial communication at 9600 bits per second:

  // Potentiometer controlled servo
  potServo.attach(potServoPin); // initialize servo on potServoPin

  // Button controlled servo #1
  pinMode(buttonPin_1, INPUT);
  pinMode(buttonPin_2, INPUT);
  buttonServo_1.attach(buttonServoPin_1); // initialize servo on buttonServoPin_1

  // Button controlled servo #2
  pinMode(buttonPin_3, INPUT);
  pinMode(buttonPin_4, INPUT);
  buttonServo_2.attach(buttonServoPin_2); // initialize servo on buttonServoPin_2
  
}

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 

// the loop routine runs over and over again forever:
void loop() {
  // Potentiometer controlled servo
  potServo.write(potCtrl(potPin));

  // Button controlled servo #1
  buttonServoPos_1 = buttonCtrlPlus(buttonPin_1, buttonServoPos_1, plusIncrement);
  buttonServoPos_1 = buttonCtrlMinus(buttonPin_2, buttonServoPos_1, minusIncrement);
  buttonServo_1.write(buttonServoPos_1);

  Serial.print("buttonServoPos_1\t");
  Serial.print(buttonServoPos_1);

  // Button controlled servo #2
  buttonServoPos_2 = buttonCtrlPlus(buttonPin_3, buttonServoPos_2, plusIncrement);
  buttonServoPos_2 = buttonCtrlMinus(buttonPin_4, buttonServoPos_2, minusIncrement);
  buttonServo_1.write(buttonServoPos_1);
  
  Serial.print("buttonServoPos_2\t");
  Serial.println(buttonServoPos_2);
  
  delay(50);
}

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 

int potCtrl(int analogPin){
  int potVal = analogRead(analogPin); // read potentiometer input
  int potServoCtrl = map(potVal, 0, 1023, 0, 180); // map 8-bit analog read to 0-180 servo control

  Serial.print("Servo Position\t");
  Serial.print(potServoCtrl);
  Serial.print("\t");
//  Serial.print("ADC Val\t");
//  Serial.println(potVal);
//  Serial.print("\t");
  
  return potServoCtrl;
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

    if (val == HIGH) {
      currentPos += decrement;
    }
  }

  return currentPos;

}

// . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 

