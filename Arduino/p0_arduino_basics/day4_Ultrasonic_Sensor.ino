//int ledPin=11; //LED Pin
int trigPin=9; // Trigger Pin
int echoPin=10; //Echo Pin

long duration; //duration for sound wave to travel to and fro
float distance; //distance of the object

void setup() {
  // put your setup code here, to run once:

//pinMode(ledPin,OUTPUT); //LED Brightens
pinMode(trigPin,OUTPUT); //Sends sound wave
pinMode(echoPin,INPUT); //Read duration

Serial.begin(9600); //Initialize Serial Monitor
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(trigPin,LOW);
delayMicroseconds(2);

//Sends 10 micro sec Trigger
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);

digitalWrite(trigPin,LOW);

//Read the Signal
duration=pulseIn(echoPin,HIGH);

distance=duration * 0.034/2; //duration * speed divide by 2 because to and fro

Serial.print("Distance: ");
Serial.print(distance);
Serial.print(" cm\n");
delay(100);

}
