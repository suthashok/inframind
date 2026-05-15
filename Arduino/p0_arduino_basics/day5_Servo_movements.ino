#include <Servo.h>

Servo myServo; //initialize servo variable

int potPin=A0;
int potVal;
int angle;

void setup() {
  // put your setup code here, to run once:
myServo.attach(9);//attach Pin 9 to Servo Signal

Serial.begin(9600); //Initiate Serial Display
}

void loop() {
  // put your main code here, to run repeatedly:

potVal=analogRead(potPin); //Reads from 0 to 1023

angle=map(potVal,0,1023,0,180); //map Potentiometer value to angle

myServo.write(angle);

Serial.print("Pot : ");
Serial.print(potVal);
Serial.print("Angle : ");
Serial.print(angle);
Serial.print("\n");

delay(20);
}
