int ledPin=11; //LED is connected to Pin 11, for analog output only Pins with ~ symbols are compatible
int potPin=A0; //Potentiometer is connected to Pin A0

int potVal=0; //Reading of potentiometer
int brightnessVal=0; //Output to LED

void setup() {
  // put your setup code here, to run once:
pinMode(ledPin,OUTPUT);//It is un-necessary as Analog Pin will be by defult reading analog input
pinMode(potPin,INPUT); //It is un-necessary as Analog Pin will be by defult reading analog input
Serial.begin(9600);//Start communication
}

void loop() {
// put your main code here, to run repeatedly:
potVal=analogRead(potPin); //Reading Knob position and analog input between 0 and 1023

brightnessVal=map(potVal,0,1023,0,255); //We need to map 10-bit potValue to PWM value 8-bit

analogWrite(ledPin,brightnessVal); //This is major difference between digitalWrite (0/1) and AnalogWrite (0 to 255)

Serial.print("Pot Value: "); //Output on Serial Monitor
Serial.print(potVal); //Output on Serial Monitor
Serial.print("\n");

Serial.print("  Brightness  "); //Output on Serial Monitor
Serial.print(brightnessVal); //Output on Serial Monitor
Serial.print("\n");

delay(10);

}
