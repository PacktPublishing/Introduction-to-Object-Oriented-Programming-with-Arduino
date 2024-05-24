#ifndef IRSensor_h
#define IRSensor_h

#include <Arduino.h>

class IRSensor
{
private:
    uint8_t sensorPin;
    uint8_t statusSensor;
    uint8_t prevState;
    int points;
    int cntIterations;
    long IRSensorTriggered;
    bool isMotorGateTriggered;

public:
    IRSensor(int gpioPin, int _points);
    int checkIRTrigger(bool motorGate);
    void calibration();
    bool getStatusMotorGate();
    void setStatusMotorGate(bool newValue);
};

#endif