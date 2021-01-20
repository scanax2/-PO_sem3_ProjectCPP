#include <iostream>
#include <cmath>        // std::abs
#include <string>

#pragma once

using namespace std;

class Colony{
private:
    int water;
    int food;
    int population;

    double progress;
    double waterConsumptionPerOne;
    double foodConsumptionPerOne;
    int goodPopulation[2];

    double calculateProgress();
    int calculateWaterConsumption();
    int calculateFoodConsumption();

    void calculateExpenses();
    void calculatePopulationGrowth();

public:
    Colony();
    void printStatus();
    // Unexpected changes: added constructor change: int cargo -> int* cargo
    void receiveCargo(int* cargo);
    double getColonyProgress();
    int getColonyPopulation();
    // Unexpected changes: added constructor change: new function
    int* getColonyGoodPopulation();
    void endOfTheDay();
};