#include <iostream>
#include "Colony.h"
#include "Spacecraft.h"
#include "Cargo.h"
#include "Passenger.h"
#include "Missile.h"

#pragma once

using namespace std;

class Game{
private:
    Colony colony;
    // Unexpected changes: added constructor change: 1..* -> 1
    Spacecraft* spacecraft;

    int score;
    int turns;

    // Unexpected changes: added constructor change printStatus() -> printStatus(string msg) 
    void printStatus(string msg);
    // Unexpected changes: added constructor change void -> bool
    bool chooseOption();
    bool checkWin();
    bool checkLose();
public:
    Game();
    // Unexpected changes: added constructor change: void -> bool
    bool update();
};