#include "Passenger.h"

Passenger::Passenger(int size){
    availableSlots = size;
    cells = new Cell[size];
}

Passenger::~Passenger(){
    
}

void Passenger::printSpacecraft(){
    cout << string(10, ' ') << string(6, '-') << endl;
    cout << string(9, ' ') << '/' << string(6,'#') << "\\" << endl;
    int cellIndex = 0;
    for (int i = 1; i < 9; i++){
        if (i % 3 == 0){
            cout << string(9, ' ') << '|' << string(6, '#') << '|' << endl;
            cellIndex++;
        }
        else{
            string cellLine = string(2, cells[cellIndex].getCellSymbol());
            cout << string(9, ' ') << '|' << string(2,'#') << cellLine << string(2,'#') <<'|' << endl;
        }
    }  
    cout << string(8, ' ') << '/' << string(8,'#') << "\\" << endl;
    cout << string(7, ' ') << '/' << string(10,'#') << "\\" << endl;
}

void Passenger::loadCargo(){
    availableSlots--;
}

void Passenger::unloadCargo(){
    availableSlots++;
}


void Passenger::chooseOption(){
    cout << "Choose option:" << endl;
    cout << "1 - Passengers" << endl;
    cout << "2 - Empty" << endl;

    int cellIndex = 0;
    
    string answer;
    while(availableSlots > 0){
        cout << "$RocketBuilder> ";
        cin >> answer;

        if (answer == "1"){
            cells[cellIndex].setCellSymbol('P');
            cells[cellIndex].setCellPassengers(50);
            cellIndex++;
            loadCargo();
        }
        else if (answer == "2"){
            cellIndex++;
            loadCargo();
        }
        else{
            cout << "Unknown command: " << answer << endl;
        }
        printSpacecraft();
    }
}

void Passenger::launch(Colony& colony){
    int cargo[3];
    for( int i = 0; i < 3; i++){
        cargo[i] = 0;
    }
    for (int i = 0; i < 3; i++){
        cargo[2] += cells[i].getCellPassengers();
    }
    colony.receiveCargo(cargo);
}

bool Passenger::build(){
    printSpacecraft();
    chooseOption();
    return true;
}