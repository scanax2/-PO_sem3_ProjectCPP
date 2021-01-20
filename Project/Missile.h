#include "Spacecraft.h"

#pragma once

class Missile : public Spacecraft{
private:
    int damage;
public:
    Missile(int size);
    ~Missile();

    void chooseOption() override;
    void loadCargo() override;
    void unloadCargo() override;
    void printSpacecraft() override;
    bool build() override;
    void launch(Colony& colony) override;
};