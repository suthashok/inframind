//Language C++
//Author : Ashok Suthar

// Project :- Traffic Light Simulator - with Pedestrian Switch

//Don't use 0 and 1 for LED Output, as 0 and 1 are Serial RX/TX

// Define Lane Structure, which has three lights

struct Lane{
  int green;
  int yellow;
  int red;
};

Lane lanes[4]; // 0 - Lane A, 1 - Lane B, 2 - Lane C, 3 - Lane D

//Define Pin of each LED on the board
int greenPins[4]={2,5,8,11};
int yellowPins[4]={3,6,9,12};
int redPins[4]={4,7,10,13};

int current_lane=0; // 0 - Lane A, 1 - Lane B, 2 - Lane C, 3 - Lane D
int led_phase=0; //0 - Green, 1 - Yellow, 2 - Red

int led_interval[3]={10000,2000,3000};

unsigned long prevTime=0;

//Lane change function
void lanechange()
{
  current_lane++;
  if (current_lane>3) current_lane=0;
}

//LED Lighting
void ledlights()
{
  //Now only turn on for the lane and phase
  if (led_phase==0)
  {

    digitalWrite(lanes[current_lane].red, LOW);
    digitalWrite(lanes[current_lane].yellow, LOW);
    digitalWrite(lanes[current_lane].green, HIGH);
  }
  else if (led_phase==1)
  {
    digitalWrite(lanes[current_lane].red, LOW);
    digitalWrite(lanes[current_lane].green, LOW);
    digitalWrite(lanes[current_lane].yellow, HIGH);
  }
  else if (led_phase==2)
  {
    digitalWrite(lanes[current_lane].yellow, LOW);
    digitalWrite(lanes[current_lane].green, LOW);
    digitalWrite(lanes[current_lane].red, HIGH);
  }
}


void setup()
{
  for (int i=0;i<4;i++)
  {
    //Map each lane LEDs to their respective Pin on the board
    lanes[i].green=greenPins[i];
    lanes[i].yellow=yellowPins[i];
    lanes[i].red=redPins[i];

    pinMode(lanes[i].green,OUTPUT);
    pinMode(lanes[i].yellow,OUTPUT);
    pinMode(lanes[i].red,OUTPUT);

    //First we need to switch all LEDs to RED

    digitalWrite(lanes[i].green, LOW);
    digitalWrite(lanes[i].yellow, LOW);
    digitalWrite(lanes[i].red, HIGH);
  }
}


//main loop function

void loop()
{

  unsigned long currentTime=millis(); //Time since Arduino start
  
  //Define which state should be triggered
  if (currentTime - prevTime >= led_interval[led_phase])
  {
    prevTime=currentTime;
    led_phase++;
    if (led_phase>2)
    {
    //Move next lane
    lanechange();
    led_phase=0;
    }
  }
  //Always Call LED logic everytime
  ledlights();
}