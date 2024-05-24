#include "leds.h"
#include <analogWrite.h>
#include <Arduino.h>

leds::leds(int pin)
{
    pinLED = pin;
    pinMode(pinLED, OUTPUT);
}

void leds::turnOn()
{
    digitalWrite(pinLED, HIGH);
}

void leds::turnOff(bool analgOff)
{
    if (analgOff)
    {
        analogWrite(pinLED, 0);
    }
    else
    {
        digitalWrite(pinLED, LOW);
    }
}

void leds::toggle()
{
    digitalWrite(pinLED, !digitalRead(pinLED));
}

void leds::turnOffAfterDelay(int millisec, bool analogOff)
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillisTurnOff <= (millisec))
    {
        // we dont't reset previousMillisTurnOff

        // digitalWrite(pinLED, HIGH);
    }
    else
    {
        turnOff(analogOff);
        previousMillisTurnOff = millis();
    }
}

void leds::fadeOn(int millisec)
{
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillisFadeOn >= millisec)
    {
        previousMillisFadeOn = currentMillis;
        if (brightness <= 255)
        {
            Serial.println(brightness);
            analogWrite(pinLED, brightness);
            brightness += fadeAmount;
        }
    }
}

void leds::pulsate(int delay_ms)
{
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillisPulsate >= delay_ms)
    {
        previousMillisPulsate = currentMillis;
        brightness += fadeAmount;
        if (brightness == 0 || brightness == 255)
        {
            fadeAmount = -fadeAmount;
        }
        analogWrite(pinLED, brightness);
    }
}