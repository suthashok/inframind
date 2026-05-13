int led=11;
int button=2;
int old_button_state=1; //Not pressed
int new_button_state=1; //Not pressed

bool led_state=false;

void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(button,INPUT_PULLUP);
}

void loop() {
//button state
new_button_state=digitalRead(button);

//if button is pressed, when it was not pressed last time => change LED state
if (new_button_state==LOW and old_button_state==HIGH)
{
  led_state=!led_state;
}
digitalWrite(led,led_state);
old_button_state=new_button_state;
}
