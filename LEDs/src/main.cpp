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
OOP LEDs ansteuern | V1.0 | 04/2022

*/

#include <Arduino.h>
#include <analogWrite.h>
#include "leds.h"

unsigned long previousMillis = 0;

const int LEDs_NUM = 15;
leds alleLEDs[LEDs_NUM] = {leds(12),leds(14),leds(27),leds(22),leds(21),leds(19),leds(18),leds(25),leds(26),leds(5),leds(17),leds(16),leds(4),leds(2),leds(15)};

// leds white1(12);
// leds white2(14);
// leds green1(26);
// leds green2(25);
// leds blue1(16);
// leds blue2(17);
// leds red1(15);
// leds red2(4);
// leds yellow1(19);
// leds yellow2(21);

void fadeIn(){
  for (int i = 0; i < LEDs_NUM; i++)
  {
    alleLEDs[i].fadeOn(150);
  }
}

void pulsate(){
  for (int i = 0; i < LEDs_NUM; i++)
  {
    alleLEDs[i].pulsate(20);
  }
}

void ledChasing(){
  for (int i = 0; i < LEDs_NUM; i++)
  {
    alleLEDs[i].turnOn();
    delay(50);
  }

  for (int i = 0; i < LEDs_NUM; i++)
  {
    alleLEDs[i].turnOffAfterDelay(50,false);
    delay(50);
  }

}


void setup()
{
  Serial.begin(115200);

  // white1.turnOn();
  // green1.turnOn();
  // red1.turnOn();

  // white2.turnOn();
  // blue1.turnOn();
  // yellow1.turnOn();
}

void loop()
{

  //fadeIn();
  //pulsate();

  ledChasing();



  // unsigned long currentMillis = millis();

  // if (currentMillis - previousMillis >= 2000)
  // {
  //   // save the last time you blinked the LED
  //   previousMillis = currentMillis;
  //   white1.toggle();
  //   green1.toggle();
  //   red1.toggle();
  // }

  // white2.turnOffAfterDelay(2000,false);
  // blue1.turnOffAfterDelay(4000,false);
  // yellow1.turnOffAfterDelay(10000,false);

  // green2.fadeOn(600);
  // blue2.fadeOn(200);

  // red2.pulsate(10);
  // yellow2.pulsate(50);
}
