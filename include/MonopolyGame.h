//
// Created by schab on 17.07.2019.
//

#ifndef GTESTTEMPLATE_MONOPOLYGAME_H
#define GTESTTEMPLATE_MONOPOLYGAME_H

#include "Board.h"
#include "Die.h"

class MonopolyGame
{
public:
    MonopolyGame(int numberOfFields = 40): board(numberOfFields) {}
    void runGame(int turns = 100);
    void addPlayer(std::string name);
private:
    void playRound();
    Board board;
};

void MonopolyGame::addPlayer(std::string name) {
    board.addPlayer(name);
}

void MonopolyGame::runGame(int turns) {
    while(turns--){
        std::cout<<"turn " << turns;
        board.playRound();
    }
}
#endif //GTESTTEMPLATE_MONOPOLYGAME_H
