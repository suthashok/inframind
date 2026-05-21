// Language : C++
// Author : Ashok Suthar
// Build Command:- arduino-cli compile --fqbn arduino:avr:uno --output-dir ./build .
// Project :- Arduino based Servo Radar Scanner

// Component Used:- Servo Motor, UltraSonic Sensor, Uno

#include <Servo.h>

Servo myservo;

const int trig=10;//trig Pin will never change
const int echo=11;//echo Pin will never change

long duration; //Duration for sound to go and return back
float distance; //Distance measured by Ultrasonic

float avgDist; //Averaging out distance to reduce jitters


void setup()
{
    myservo.attach(9);
    Serial.begin(9600);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
}

void loop()
{
myservo.write(0);//Set it to zero angle at the beginning
delay(500); // Give the servo time to reach the starting position


for (int i=0;i<180;i++)
{
    myservo.write(i);
    avgDist=0;

    for (int j=0; j<5; j++)
    {
        digitalWrite(trig, LOW);
        delayMicroseconds(2);

        //Send Ultrasonic Wave
        digitalWrite(trig, HIGH);
        delayMicroseconds(10);
        digitalWrite(trig, LOW);
        
        //Read the Signal, adding 30ms timeout
        duration=pulseIn(echo, HIGH, 30000); // Added 30ms timeout to prevent freezing
        distance=duration*0.034/2; //Conversion of sound travel time to distance

        avgDist+=distance;
    }

    avgDist=avgDist/5;
    Serial.print("Angle: ");
    Serial.print(i);
    Serial.print(" Distance: ");
    Serial.print(avgDist);
    Serial.print("\n");
    delay(100);
}
    // Trap execution in an infinite loop so it doesn't run again
    while (true) {
    }
}