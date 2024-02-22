/*
Reads the analog voltage beween the to CURRENT pins on the Powercore V1 from Rack robotics.
The default spark frequency should pe 2kHz Source: https://github.com/Rack-Robotics/Powercore-V1.0-Firmware

We want to log the successful sparks per second and plot that to the Serial plotter.

CODE UNCOMPLETE DO NOT RUN! 


*/
int pulses = 0;
unsigned long time = 0;
bool newPulse = true;
int pulseSpeed = 0;
// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to


int sensorValue = 0;  // value read from the pot


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(500000);
time = millis(); //time in millisecs
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);

//Sensorvalue should be 1.667 V High and 0.333V low. We have a 10 bit resolution (1024 steps) on 0-5V analog measurements
//So 1.667V will be read as step 341 and 0.333V as step 68 

if (sensorValue < 300 && newPulse)
{
pulses++;
newPulse = false;
} else {
  newPulse =true;
}

pulseSpeed = 
  // print the results to the Serial Monitor:


  Serial.println(sensorValue);


  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delayMicroseconds(1000);
}
