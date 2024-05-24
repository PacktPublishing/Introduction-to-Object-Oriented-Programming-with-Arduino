#include <Arduino.h>
#include "rpsw.h"
#include "leds.h"

leds ledYellow1 = leds(5);
leds ledYellow2 = leds(18);
leds ledRed1 = leds(17);
leds ledRed2 = leds(16);
leds ledBlue = leds(19);

void rpsw::allLEDsOff(){
    ledYellow1.turnOff(false);
    ledYellow2.turnOff(false);
    ledRed1.turnOff(false);
    ledRed2.turnOff(false);
    ledBlue.turnOff(false);
}

void rpsw::displayLEDs(){

    if(gameScore[0].score==1){
        //first led on
        ledYellow1.turnOn();
    }
    else if(gameScore[0].score==2){
        ledYellow1.turnOn();
        ledYellow2.turnOn();
    }

    if(gameScore[1].score==1){
        ledRed1.turnOn();
    }
    else if(gameScore[1].score==2){
        ledRed1.turnOn();
        ledRed2.turnOn();
    }

    if(gameScore[2].score==1){
        ledBlue.turnOn();
    }

}


void rpsw::resetGame(){
    for (int i = 0; i < 3; i++)
    {
        gameScore[i].score=0;
    }
    
    state=waitForUserInput;
    allLEDsOff();
}

void rpsw::checkGameplay(){

    if(gameScore[0].score >= 2 || gameScore[1].score >=2){
        state = end;
    }
    else {
        state = waitForUserInput;
    }

    Serial.print("result");
    Serial.print(" Won:");
    Serial.print(gameScore[0].score);
    Serial.print(" lost:");
    Serial.print(gameScore[1].score);
    Serial.print(" teid:");
    Serial.print(gameScore[2].score);
    Serial.println("---------------");

    displayLEDs();

}

void rpsw::checkUserWin(String user, String bot){
    if(user == bot){
        //tied
        gameScore[2].score +=1;
    }
    else {
        for (int i = 0; i < 4; i++)
        {
            if(solutions[i][0]==user){
                if(solutions[i][1]==bot || solutions[i][2]==bot){
                    //we have won
                    gameScore[0].score +=1;
                }
                else{
                    //we have lost
                    gameScore[1].score +=1;
                }
            }
        }
        


    }

}