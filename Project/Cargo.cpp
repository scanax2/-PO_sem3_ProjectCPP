#include "Cargo.h"

Cargo::Cargo(int size){
    availableSlots = size;
    cells = new Cell[size];
}

Cargo::~Cargo(){
    
}

void Cargo::printSpacecraft(){
    cout << string(9, ' ') << string(8,'=') << endl;
    int cellIndex = 0;
    for (int i = 1; i < 12; i++){
        if (i % 3 == 0){
            cout << string(9, ' ') << '|' << string(6, '#') << '|' << endl;
            cellIndex++;
        }
        else{
            string cellLine = string(2, cells[cellIndex].getCellSymbol());
            cout << string(9, ' ') << '|' << string(2,'#') << cellLine << string(2,'#') <<'|' << endl;
        }
    }
    cout << string(9, ' ') << '/' << string(6, '#') << "\\" << endl;
}

void Cargo::loadCargo(){
    availableSlots--;
}

void Cargo::unloadCargo(){
    availableSlots++;
}


void Cargo::chooseOption(){
    cout << "Choose option:" << endl;
    cout << "1 - Water cargo" << endl;
    cout << "2 - Food cargo" << endl;
    cout << "3 - Empty" << endl;

    int cellIndex = 0;
    
    string answer;
    while(availableSlots > 0){
        cout << "$RocketBuilder> ";
        cin >> answer;

        if (answer == "1"){
            cells[cellIndex].setCellSymbol('W');
            cells[cellIndex].setCellWater(40);
            cellIndex++;
            loadCargo();
        }
        else if (answer == "2"){
            cells[cellIndex].setCellSymbol('F');
            cells[cellIndex].setCellFood(35);
            cellIndex++;
            loadCargo();
        }
        else if (answer == "3"){
            cellIndex++;
            loadCargo();
        }
        else{
            cout << "Unknown command: " << answer << endl;
        }
        printSpacecraft();
    }
}

void Cargo::launch(Colony& colony){
    int cargo[4];
    for( int i = 0; i < 4; i++){
        cargo[i] = 0;
    }
    for (int i = 0; i < 4; i++){
        cargo[0] += cells[i].getCellWater();
        cargo[1] += cells[i].getCellFood();
    }
    colony.receiveCargo(cargo);
}

bool Cargo::build(){
    printSpacecraft();
    chooseOption();
    return true;
}