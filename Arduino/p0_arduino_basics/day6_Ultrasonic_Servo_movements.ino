//This project moves Servo Arm based on Utrasonic distance
#include <Servo.h>

Servo myServo;

int ledG=13; //Green LED Pin
int ledR=12; //Red LED Pin

int trig=10; //Ultrasonic trigger to Pin 10
int echo=11; //Ultrasonic Echo to Pin 11

long duration; //time taken for sound wave to travel
float distance;//distance of the object

int angle;
int prevAngle=0;

float avgDist;

void setup() {
  // put your setup code here, to run once:
myServo.attach(9);//attach Pin 9 to Servo Signal

pinMode(ledG,OUTPUT); //LED Brightens
pinMode(ledR,OUTPUT); //LED Brightens
pinMode(trig,OUTPUT); //Sends sound wave
pinMode(echo,INPUT); //Read duration

Serial.begin(9600); //Initiate Serial Display

digitalWrite(ledG,LOW);
digitalWrite(ledR,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

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

  avgDist=avgDist/5;
  
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
  myServo.write(angle);

  Serial.print("Avg Distance: ");
  Serial.print(avgDist);
  Serial.print("  Servo Angle: ");
  Serial.print(angle);

  delay(100);
}
