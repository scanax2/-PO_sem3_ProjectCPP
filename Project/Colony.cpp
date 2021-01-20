#include "Colony.h"

Colony::Colony(){
    water = 60;
    food = 40;
    // <350,1000>
    population = 600; 
    progress = 0;

    // 0.05,0.04 | 
    waterConsumptionPerOne = 0.05;
    foodConsumptionPerOne = 0.04;
    goodPopulation[0] = 350;
    goodPopulation[1] = 1000;
}

void Colony::printStatus(){
    cout << string(25, '-') << endl;
    cout << "Colony status:" << endl;
    cout << "Water: " << water << endl;
    cout << "Food: " << food << endl;
    cout << "Population: " << population << endl;
    cout << "Progress: " << progress << endl;
    cout << "Water consumption: " << population*waterConsumptionPerOne << endl;
    cout << "Food consumption: " << population*foodConsumptionPerOne << endl;
}

void Colony::receiveCargo(int* cargo){
    /*cargo[0] - water
      cargo[1] - food
      cargo[2] - passengers
      cargo[3] - damage
    */
   water += cargo[0];
   if (water > 100){
       water = 100;
   }
   food += cargo[1];
   if (food > 100){
       food = 100;
   }
   population += cargo[2];
   population -= cargo[3];
   if (population < 0){
       population = 0;
   }
}

int Colony::calculateWaterConsumption(){
    return population*waterConsumptionPerOne;
}
int Colony::calculateFoodConsumption(){
    return population*foodConsumptionPerOne;
}

int* Colony::getColonyGoodPopulation(){
    return goodPopulation; 
}

double Colony::calculateProgress(){
    double median = (goodPopulation[0]+goodPopulation[1])/2;
    double progressFactor = 1 - abs(population-median)/median; 
    if (progressFactor < 0){
        progressFactor = 0;
    }
    double progressUnit = 12;
    return progressUnit * progressFactor;
}

void Colony::calculatePopulationGrowth(){
    population += (int)((double)food / 100.0 * (double)population / 2.0);
    if (food <= 0){
        population -= population / 2.5; 
    }
    if (water <= 0){
        population -= population / 2;
    }
}

void Colony::calculateExpenses(){
    water -= calculateWaterConsumption();
    if (water <= 0){
        water = 0;
    }
    food -= calculateFoodConsumption();
    if (food <= 0){
        food = 0;
    }
}

double Colony::getColonyProgress(){
    return progress;
}

int Colony::getColonyPopulation(){
    return population;
}

void Colony::endOfTheDay(){
    progress += calculateProgress();
    if (progress > 100.0){
        progress = 100.0;
    }
    calculateExpenses();
    calculatePopulationGrowth();
}