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
  Stirnlampe | V1.0 | 05/2022

*/

int ledRed = 25;
int ledGreen = 12;

#include <Arduino.h>
#include "ButtonHeadlamp.h"
#include "leds.h"

ButtonHeadlamp btn_led(13);
leds ledRED(25);
leds ledGREEN(12);
bool pulsateOn=false;

void setup()
{
  Serial.begin(115200);
  btn_led.start();
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
}

void loop()
{
  switch (btn_led.checkBTN())
  {
  case 1:
    // digitalWrite(ledGreen, !digitalRead(ledGreen));

    static int cnt=0;

    if(cnt%2==0) pulsateOn=true;
    else {
      pulsateOn=false;
      ledGREEN.turnOff(true);
    }

    cnt++;
    
    Serial.println("short klick from main.cpp");
    break;
  case 2:
    Serial.println("long klick from main.cpp");
    ledRED.turnOn();
    break;
  }

  ledRED.turnOffAfterDelay(2500,false);

  if(pulsateOn) ledGREEN.pulsate(20);

  btn_led.checkFade();
}