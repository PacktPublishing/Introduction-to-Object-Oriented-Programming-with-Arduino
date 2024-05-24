/*
        _          _ ______ _____ _____
       (_)        | |  ____|  __ \_   _|
  _ __  ___  _____| | |__  | |  | || |
  | '_ \| \ \/ / _ \ |  __| | |  | || |
  | |_) | |>  <  __/ | |____| |__| || |_
  | .__/|_/_/\_\___|_|______|_____/_____|
  | |
  |_|

  www.pixeledi.eu | twitter.com/pixeledi
  IR Sensors | V1.0 | 05/2022

*/

#include <Arduino.h>
#include "IRSensor.h"

const int NUM_IRSensors=4;
IRSensor IRarray[NUM_IRSensors]={{14,10},{27,20},{26,50},{25,100}};
IRSensor MotorGate = IRSensor(33,0);

int led = 13;
int btn = 12;

// IRSensor IRSensor1 = IRSensor(14,10);
// IRSensor IRSensor2 = IRSensor(27,20);
// IRSensor IRSensor3 = IRSensor(26,50);
// IRSensor IRSensor4 = IRSensor(25,100);



void checkPoints(){

  for (int i = 0; i < NUM_IRSensors; i++)
  {
    int galtonPoints = IRarray[i].checkIRTrigger(false);
    if(galtonPoints >0){
      // MQTT 
      // Server Side Events
      Serial.printf("Points: %d",galtonPoints);
    }
  }
  
  MotorGate.checkIRTrigger(true);

  // IRSensor1.checkIRTrigger(false);
  // IRSensor2.checkIRTrigger(false);
  // IRSensor3.checkIRTrigger(false);
  // IRSensor4.checkIRTrigger(false);
  // IRSensor5.checkIRTrigger(true);
}

void setup() {
  Serial.begin(115200);
  pinMode(btn, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  checkPoints();

  if(digitalRead(btn)==LOW){
    digitalWrite(led, HIGH);
  }
}