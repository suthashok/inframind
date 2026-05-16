#include <Servo.h>

Servo myServo; //initialize servo variable

int potPin=A0;
int potVal;
int angle;

int oldangle=0;

void setup() {
  // put your setup code here, to run once:
myServo.attach(9);//attach Pin 9 to Servo Signal

Serial.begin(9600); //Initiate Serial Display
}

void loop() {
  // put your main code here, to run repeatedly:

potVal=analogRead(potPin); //Reads from 0 to 1023

// Serial.println(potVal);

angle=map(potVal,0,1023,0,180); //map Potentiometer value to angle

if (abs(angle-oldangle)>2) //making a move only if there is a input change for more than 2* to avoid noise
{
myServo.write(angle);
oldangle=angle;
}

Serial.print("Pot : ");
Serial.print(potVal);
Serial.print("Angle : ");
Serial.print(angle);
Serial.print("\n");

delay(20);

}
