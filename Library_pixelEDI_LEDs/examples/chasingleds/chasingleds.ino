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
OOP LEDs ansteuern | V1.0 | 05/2022

*/

#include <Arduino.h>
#include <analogWrite.h>
#include <leds.h>

unsigned long previousMillis = 0;

const int LEDs_NUM = 15;
leds allLEDs[LEDs_NUM] = {leds(12),leds(14),leds(27),leds(22),leds(21),leds(19),leds(18),leds(25),leds(26),leds(5),leds(17),leds(16),leds(4),leds(2),leds(15)};

void fadeIn(){
  for (int i = 0; i < LEDs_NUM; i++)
  {
    allLEDs[i].fadeOn(150);
  }
}

void pulsateAll(){
  for (int i = 0; i < LEDs_NUM; i++)
  {
    allLEDs[i].pulsate(20);
  }
}

void ledChasing(){

  for (int i = 0; i < LEDs_NUM; i++)
  {
    allLEDs[i].turnOn();
    delay(50);
  }

  for (int i = 0; i < LEDs_NUM; i++)
  {
    allLEDs[i].turnOffAfterDelay(50,false);
    delay(50);
  }

}



void setup()
{
  
}

void loop()
{

  ledChasing();


  //other examples
  
  //fadeIn();
  //pulsateAll();


}
