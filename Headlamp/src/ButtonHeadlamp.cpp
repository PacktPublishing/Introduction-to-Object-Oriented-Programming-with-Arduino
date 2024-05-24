#include "ButtonHeadlamp.h"
#include <Arduino.h>

extern int ledRed;
extern int ledGreen;

void ButtonHeadlamp::checkFade()
{

    // here comes my fancy code
    if (state == LOW && millis() - buttonclickedMS > 2000)
    {

        static int cnt = 0;

        analogWrite(ledGreen, cnt);
        Serial.println(cnt);
        delay(20);
        cnt++;

        if (cnt >= 255)
        {
            cnt = 0;
            analogWrite(ledGreen, 0);
            delay(2000);
        }
    }
}