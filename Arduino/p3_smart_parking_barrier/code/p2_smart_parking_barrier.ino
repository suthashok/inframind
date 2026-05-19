//Language C++
//Author : Ashok Suthar
// Build Command:- arduino-cli compile --fqbn arduino:avr:uno --output-dir ./build .
// Project :- Arduino based Smart Parking Barrier System


//This project uses Servo library
#include <Servo.h>

Servo myServo; //Create Servo variable

int ledG=13; //Green LED Pin
int ledR=12; //Red LED Pin

int trig=10; //Ultrasonic trigger to Pin 10
int echo=11; //Ultrasonic Echo to Pin 11

long duration; //time taken for sound wave to travel
float distance;//distance of the object

int angle; //Desired Servo Angle
int prevAngle=0;//Previous Servo Angle

float avgDist; //Avg distance of the vehicle approaching


void setup() {

myServo.attach(9);//attach Pin 9 to Servo Signal

pinMode(ledG,OUTPUT); //LED Brightens
pinMode(ledR,OUTPUT); //LED Brightens
pinMode(trig,OUTPUT); //Sends sound wave
pinMode(echo,INPUT); //Read duration

Serial.begin(9600); //Initiate Serial Display

digitalWrite(ledG,LOW); //Initialize Red LED as ON
digitalWrite(ledR,HIGH); //Initialize Greeen LED as OFF
}



void loop() {

//First need to read ultrasonic input

  avgDist=0;

  for (int i=0;i<=4;i++)
  {
    digitalWrite(trig,LOW);
    delayMicroseconds(2);

    //Sends 10 micro sec Trigger
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);

    digitalWrite(trig,LOW);

    //Read the Signal
    duration=pulseIn(echo,HIGH);

    distance=duration * 0.034/2; //duration * speed divide by 2 because to and fro
    Serial.print(distance);
    Serial.print("\n");
    avgDist+=distance;
  }

  //Calculate average distance
  avgDist=avgDist/5;
  
//Cap the distance to avoid Servo jitters
  if (avgDist>50) avgDist=50;
  if (avgDist<5) avgDist=5; 


//Based on distance change state

  if (avgDist<15 && prevAngle==0)
  {
    angle=prevAngle+90;
    prevAngle=angle;
    digitalWrite(ledG,HIGH);
    digitalWrite(ledR,LOW);
  }
  else if (avgDist>=15 && prevAngle==90)
  {
    angle=prevAngle-90;
    prevAngle=angle;
    digitalWrite(ledG,LOW);
    digitalWrite(ledR,HIGH);
  }

//Change Servo angle
  myServo.write(angle);

  Serial.print("Avg Distance: ");
  Serial.print(avgDist);
  Serial.print("  Servo Angle: ");
  Serial.print(angle);

  delay(100);
}