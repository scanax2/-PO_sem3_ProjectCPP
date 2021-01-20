#include "Spacecraft.h"

#pragma once

class Cargo : public Spacecraft{
private:
    int water;
    int food;
public:
    Cargo(int size);
    ~Cargo();

    void chooseOption() override;
    void loadCargo() override;
    void unloadCargo() override;
    void printSpacecraft() override;
    bool build() override;
    void launch(Colony& colony) override;
};