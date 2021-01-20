#include "Game.h"
#include "Cargo.h"

Game::Game(){
    score = 0;
    turns = 1;

    colony = Colony();
    cout << "Welcome to the Mars Colony !" << endl;
}

bool Game::chooseOption(){
    cout << string(25, '-') << endl;
    cout << "Select option (1,2,3,4):" << endl;
    cout << "1 - Cargo" << endl;
    cout << "2 - Passenger" << endl;
    cout << "3 - Missile" << endl;
    cout << "4 - Skip" << endl;

    string answer;
    while(true){
        cout << "$> ";
        cin >> answer;

        if (answer == "1"){
            spacecraft = new Cargo(4);
            break;
        }
        else if (answer == "2"){
            spacecraft = new Passenger(3);
            break;
        }
        else if (answer == "3"){
            spacecraft = new Missile(2);
            break;
        }
        else if (answer == "4"){
            return true;
        }
        else if (answer == "exit"){
            return false;
        }
        else{
            cout << "Unknown option: " << answer << endl;
        }
    }

    spacecraft->build();
    spacecraft->launch(colony);
    return true;
}

bool Game::checkWin(){
    if (colony.getColonyProgress() >= 100.0){
        return true;
    }
    else{
        return false;
    }
}



bool Game::checkLose(){
    bool isLow = colony.getColonyPopulation() <= colony.getColonyGoodPopulation()[0];
    bool isHigh = colony.getColonyPopulation() >= colony.getColonyGoodPopulation()[1];
    if (isLow || isHigh){
        return true;
    }
    else{
        return false;
    }
}

void Game::printStatus(string msg){
    cout << string(25, '-') << endl;
    cout << "Day: " << turns << msg << endl;
    colony.printStatus();
}

bool Game::update(){
    if (turns == 1){
        printStatus(" (Type 'exit' to close the game)");
    }
    else{
        printStatus("");
    }

    bool isGame = chooseOption();
    if (!isGame){
        return true;
    }
    colony.endOfTheDay();
    turns++;

    bool isWin = checkWin();
    bool isLose = checkLose();

    if (isWin || isLose){
        if (isLose){
            double scoreFactor = 1000 - (turns-1)*20;  // If Day 1 - 1000, Day 50 - 0
            if (scoreFactor < 0){
                scoreFactor = 0;
            }
            score = colony.getColonyProgress()*scoreFactor; // Best score (impossible) 100.000 pkt    
            printStatus(" - You lost, your score: "+to_string(score));
        }
        else if (isWin){
            double scoreFactor = 1000 - (turns-1)*20; 
            if (scoreFactor < 0){
                scoreFactor = 0;
            }
            score = (10*colony.getColonyProgress())*scoreFactor;  // Best score (impossible) 1.000.000 pkt  
            printStatus(" - You won, your score: "+to_string(score));
        }
        return true;
    }
    else{
        return false;
    }
}