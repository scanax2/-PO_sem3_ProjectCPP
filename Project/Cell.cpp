#include "Cell.h"

Cell::Cell(){
    symbol = '.';
    water = 0;
    food = 0;
    passengers = 0;
    damage = 0;
}

void Cell::setCellSymbol(char symbol){
    this->symbol = symbol;
}
char Cell::getCellSymbol(){
    return symbol;
}

void Cell::setCellWater(int water){
    this->water = water;
}
int Cell::getCellWater(){
    return water;
}

void Cell::setCellFood(int food){
    this->food = food;
}
int Cell::getCellFood(){
    return food;
}

void Cell::setCellPassengers(int passengers){
    this->passengers = passengers;
}
int Cell::getCellPassengers(){
    return passengers;
}

void Cell::setCellDamage(int damage){
    this->damage = damage;
}
int Cell::getCellDamage(){
    return damage;
}
