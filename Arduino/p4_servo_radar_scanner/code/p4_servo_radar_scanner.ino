// Language : C++
// Author : Ashok Suthar
// Build Command:- arduino-cli compile --fqbn arduino:avr:uno --output-dir ./build .
// Project :- Arduino based Servo Radar Scanner

// Component Used:- Servo Motor, UltraSonic Sensor, Uno

#include <Servo.h>

Servo myservo;

const int trig=10;//trig Pin will never change
const int echo=11;//echo Pin will never change

const int ledPin=12; //LED Pin

long duration; //Duration for sound to go and return back
float distance; //Distance measured by Ultrasonic

float medDist; //Median distance to reduce jitters

int angle = 0; //Servo angle => 0 to 180
int direction = 1; //Servo direction => State (-1/+1)

float calculateMedian(float arr[], int size)
{
    // Sort the array in ascending order
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                float temp = arr[j]; //assign higher value to temp
                arr[j] = arr[j + 1]; //move lower value at higher value's place
                arr[j + 1] = temp;
            }
        }
    }
    
    // Check if the array size is even or odd
    if (size % 2 == 0) {
        return (arr[(size / 2) - 1] + arr[size / 2]) / 2.0; // Average of two middle elements
    } else {
        return arr[size / 2]; // Exact middle element
    }
}


void setup()
{
    myservo.attach(9);
    Serial.begin(9600);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
}

void loop()
{

    // Move servo to current angle
    myservo.write(angle);

    // Measure Distance
    float readings[5]; // Array to store 5 readings
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

        readings[j] = distance;
        delay(100);
    }

    medDist = calculateMedian(readings, 5);
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print(" Distance: ");
    Serial.print(medDist);
    Serial.print("\n");

    //Typical range of ultrasonic sensor is 4m, so I will define
    //if distance is less than 50cm then there is an obstacle
    //RED LED On

    if (medDist>5 && medDist<50)
    {
        digitalWrite(ledPin,HIGH);
    }
    else
    {
        digitalWrite(ledPin, LOW); // Turn off LED when clear
    }

    // Update Servo Angle for next loop iteration
    angle = angle + direction;
    if (angle >= 180 || angle <= 0)
    {
        direction = -direction; // Change direction at extreme points
    }
}