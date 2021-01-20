#include <stdio.h>
#include "Game.h"

int main(){
    Game game;
    
    bool isFinished = false;
    while(!isFinished){
        isFinished = game.update();
    }
}

