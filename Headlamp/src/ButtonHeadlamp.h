#ifndef ButtonHeadlamp_h
#define ButtonHeadlamp_h

#include "button.h"
#include "analogWrite.h"
#include <Arduino.h>

class ButtonHeadlamp : public Button{

    public:
        //we are using the constructor from the base class
        using Button::Button;
        void checkFade();
};

#endif