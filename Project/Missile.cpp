#include "Missile.h"

Missile::Missile(int size){
    availableSlots = size;
    cells = new Cell[size];
}

Missile::~Missile(){
    
}

void Missile::printSpacecraft(){
    cout << string(12, ' ') << '/' << "\\" << endl;
    cout << string(11, ' ') << '/' << string(2, '-') << "\\" << endl;
    cout << string(10, ' ') << '/' << string(4, '-') << "\\" << endl;
    int cellIndex = 0;
    for (int i = 1; i < 8; i++){
        if (i % 4 == 0){
            cout << string(10, ' ') << '|' << string(4, '-') << '|' << endl;
            cellIndex++;
        }
        else{
            string cellLine = string(2, cells[cellIndex].getCellSymbol());
            cout << string(10, ' ') << '|' << string(1,'-') << cellLine << string(1,'-') <<'|' << endl;
        }
    }  
    cout << string(9, ' ') << '/' << string(6, '-') << "\\" << endl;
}

void Missile::loadCargo(){
    availableSlots--;
}

void Missile::unloadCargo(){
    availableSlots++;
}


void Missile::chooseOption(){
    cout << "Select option:" << endl;
    cout << "1 - Uranium charge" << endl;
    cout << "2 - Empty" << endl;

    int cellIndex = 0;
    
    string answer;
    while(availableSlots > 0){
        cout << "$RocketBuilder> ";
        cin >> answer;

        if (answer == "1"){
            cells[cellIndex].setCellSymbol('U');
            cells[cellIndex].setCellDamage(50);
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

void Missile::launch(Colony& colony){
    int cargo[2];
    for( int i = 0; i < 2; i++){
        cargo[i] = 0;
    }
    for (int i = 0; i < 2; i++){
        cargo[3] += cells[i].getCellDamage();
    }
    colony.receiveCargo(cargo);
}

bool Missile::build(){
    printSpacecraft();
    chooseOption();
    return true;
}