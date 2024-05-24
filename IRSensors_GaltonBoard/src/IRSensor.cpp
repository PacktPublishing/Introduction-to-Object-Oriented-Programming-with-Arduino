#include "IRSensor.h"
#include <Arduino.h>

extern int led;

IRSensor::IRSensor(int gpioPin, int _points)
{
    sensorPin = gpioPin;
    points = _points;
    pinMode(sensorPin, INPUT);
    statusSensor = 1;
}

int IRSensor::checkIRTrigger(bool motorGate)
{

    int output=0;

    prevState = statusSensor;
    statusSensor = digitalRead(sensorPin);

    if (prevState == HIGH && statusSensor == LOW)
    {
        IRSensorTriggered = millis();
    }
    else if (prevState == LOW && statusSensor == HIGH)
    {
        if (millis() - IRSensorTriggered < 10)
        {
            // Nothing should happend
        }
        else
        {
            if (motorGate)
            {
                Serial.print("Motorgate");
                digitalWrite(led, LOW);
            }
            
            output=points;
            //calibration();
            //Serial.println(sensorPin);
        }
    }

    return output;
}

void IRSensor::calibration(){
    cntIterations++;
    Serial.printf("Sensorpin %d | Points: %d | Iterations: %d \n",sensorPin, points, cntIterations);
}