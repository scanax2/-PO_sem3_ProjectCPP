#include <iostream>

#pragma once

using namespace std;

class Cell{
private:
    char symbol;
    int water;
    int food;
    int passengers;
    int damage;
//Uncommited change: encapsulation ensured
public:
    Cell();

    void setCellSymbol(char symbol);
    char getCellSymbol();

    void setCellWater(int water);
    int getCellWater();

    void setCellFood(int food);
    int getCellFood();

    void setCellPassengers(int passengers);
    int getCellPassengers();

    void setCellDamage(int damage);
    int getCellDamage();
};