#ifndef rpsw_h
#define rpsw_h

#include <Arduino.h>

class rpsw
{
private:
    String solutions[4][3] = {
        {"scissors", "paper", ""},
        {"stone", "scissors", ""},
        {"paper", "stone", "wells"},
        {"wells", "scissors", "stone"}};

    struct scores
    {
        String match;
        int score;
    };

    int previousScore;

    public:
    enum states{
        playing,
        waitForUserInput,
        end
    } state;

    String chosenInput[4]={"scissors","stone","paper","wells"};

    scores gameScore[3]{
        {"won",0},
        {"lost",0},
        {"tied",0}
    };
    void allLEDsOff();
    void displayLEDs();
    void checkGameplay();
    void checkUserWin(String user, String bot);
    void resetGame();
};

#endif