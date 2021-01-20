#include "Spacecraft.h"

#pragma once

class Passenger : public Spacecraft{
private:
    int passengers;
public:
    Passenger(int size);
    ~Passenger();

    void chooseOption() override;
    void loadCargo() override;
    void unloadCargo() override;
    void printSpacecraft() override;
    bool build() override;
    void launch(Colony& colony) override;
};