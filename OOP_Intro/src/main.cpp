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
OOP Introduction | V1.0 | 05/2022

*/
#include <Arduino.h>
#include "person.h"
#include "customer.h"

person edi = person("markus","edi","m",180);
person bot = person("bot","pixeledi","x",25);
person julia = person("Julia","Rohrer","f",175);

customer robert = customer("Robert","Frenius","m",195);

void setup() {
  Serial.begin(115200);

  bot.setAge(155);
  julia.setLastname("Maurer");

  edi.printPersonDetails();
  bot.printPersonDetails();
  julia.printPersonDetails();

  robert.sumSales(150);
  robert.sumSales(50);
  robert.sumSales(200);
  robert.sumSales(150);

  robert.printPersonDetails();
  robert.setCustomerID(255);

}

void loop() {
  // put your main code here, to run repeatedly:
}