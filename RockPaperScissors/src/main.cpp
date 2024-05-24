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
  Rock Paper Scissor Well | V1.0 | 05/2022

*/

#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include <ESP32Servo.h>

#include "rpsw.h"
#include "credentials.h"
#include "my_wifi.h"

int initialPosition=70;
const int SERVO_NUM=4;
Servo servoArray[SERVO_NUM];
int servoPins[SERVO_NUM]={14,27,26,25};

  unsigned long previousMillis=0;

rpsw Game = rpsw();
String userinput = "";
int rndNbr=0;
//prototyp
void checkParams(AsyncWebServerRequest *request);

void setup()
{
  Serial.begin(115200);

  if (!SPIFFS.begin(true))
  {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  connectAP();

   // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    request->send(SPIFFS, "/index.html", String(), false, processor);
    checkParams(request); 
    });
  // Lade CSS File
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/style.css", "text/css"); });
  // jQuery laden
  server.on("/jquery.min.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/jquery.min.js", "text/javascript"); });

  server.begin();

// Handle Web Server Events
  events.onConnect([](AsyncEventSourceClient *client)
                   {
    if(client->lastId()){
      Serial.printf("Client reconnected!");
    }
    // send event with message "hello!", id current millis
    // and set reconnect delay to 1 second
    client->send("hello!", NULL, millis(), 10000); });
  server.addHandler(&events);


  for (int i = 0; i < SERVO_NUM; i++)
  {
    servoArray[i].setPeriodHertz(50);
    servoArray[i].attach(servoPins[i]);
    servoArray[i].write(initialPosition);
    Serial.printf("Servo NR %d is ready \n",i);
  }

  Game.state = Game.waitForUserInput;

}

void loop()
{

  String bot="";

  switch(Game.state){
    case Game.playing:

      rndNbr = random(0,4);
      bot = Game.chosenInput[rndNbr];
      servoArray[rndNbr].write(0);

      Serial.print("Userinput: ");
      Serial.print(userinput);
      Serial.print(" Bot: ");
      Serial.println(bot);

      Game.checkUserWin(userinput, bot);
      Game.checkGameplay();

      previousMillis = millis();
    break;

    case Game.waitForUserInput:
      //we are waiting for user input
    break;

    case Game.end:

        //sending results to website
        events.send(String(Game.gameScore[0].score).c_str(),"won",millis());
        events.send(String(Game.gameScore[1].score).c_str(),"lost",millis());
        events.send(String(Game.gameScore[2].score).c_str(),"tied",millis());

      delay(3000);

      Game.resetGame();
    break;

  }


  unsigned long currentMillis=millis();
  if(currentMillis - previousMillis >=3000){  
      servoArray[rndNbr].write(initialPosition);
  }

  // String userInput = Game.chosenInput[random(0, 4)];
  // Serial.println(userInput);
  // Game.checkUserWin(userInput, "paper");
  // Serial.printf("Won: %d | Lost: %d | Tied: %d \n",
  //               Game.gameScore[0].score,
  //               Game.gameScore[1].score,
  //               Game.gameScore[2].score);
  // delay(2000);
}

void checkParams(AsyncWebServerRequest *request){

  if(request->hasParam("sspb")){
    userinput=request->getParam("sspb")->value();
    
    Game.state = Game.playing;
  }

}