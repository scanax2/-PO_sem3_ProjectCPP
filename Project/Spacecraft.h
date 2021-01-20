#include "Cell.h"
#include "Colony.h"

#pragma once

class Spacecraft{
public:
    int availableSlots;
    Cell* cells;

    virtual void chooseOption() = 0;
    virtual void loadCargo() = 0;
    virtual void unloadCargo() = 0;
    virtual void printSpacecraft() = 0;
    virtual bool build() = 0;
    // Unexpected changes: added constructor change: launch() -> launch(Colony& colony)
    virtual void launch(Colony& colony) = 0;
};