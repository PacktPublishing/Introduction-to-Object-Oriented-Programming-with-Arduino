#include "button.h"
#include <Arduino.h>
#include "analogWrite.h"


Button::Button(int pin){
    btnPin=pin;
}

void Button::start(){
    pinMode(btnPin, INPUT_PULLUP);
    state=HIGH;
}

int Button::checkBTN(){

    // return 0 = nothing to do
    // return 1 = short klick
    // return 2 = long klick
    result=0;

    int prevState = state;
    state = digitalRead(btnPin);

    if(prevState == HIGH && state == LOW){
        buttonclickedMS=millis();
        result=0;
    }
    else if( prevState == LOW && state == HIGH){
        //here comes the logic 
     
        if(millis()- buttonclickedMS < 50){
            //debounce area - nothing to do
            result=0;
        }
        else if(millis() - buttonclickedMS > 50 &&  millis() - buttonclickedMS < 200) {
            //Serial.println("short click");
            result=1;
        }
        else if(millis() - buttonclickedMS > 200 &&  millis() - buttonclickedMS < 900) {
            //Serial.println("long click");
            result=2;
        }
    }

    return result;
}