//
// Created by schab on 17.07.2019.
//

#ifndef GTESTTEMPLATE_BOARD_H
#define GTESTTEMPLATE_BOARD_H

#include <iostream>
#include <vector>
#include <map>
#include "Player.h"
#include "Field.h"
#include <memory>
#include "math.h"


class Board {

public:
    Board(int _numberOfFields) : numberOfFields(40){
        fieldVector.reserve(numberOfFields);
        StartField* tmp = new StartField();
        fieldVector.push_back(std::make_shared<Field*>());
        for (auto i = 0 ; i <= _numberOfFields; ++i)
        {
            if(i%3)
            fieldVector.push_back(std::make_shared<Field*>());
            else
            fieldVector.push_back(std::make_shared<Field*>());
        }
    }
    void addPlayer(std::string name)
    {
        FieldIterator fieldIterator(fieldVector);
        Player _player(name, 1000, fieldIterator);
        players.push_back(_player);
    }

    void playRound(){
        for (auto& i: players)
        movePlayer(i);

    }
private:
    void movePlayer(Player& player){
        player.makeMove();

        std::cout<<player.getName() << " current position: "<< player.getPossition();
        std::cout<<" Current balance: "<<player.getMoney()<<std::endl;
    }
    std::vector< std::shared_ptr<Field*> > fieldVector;
    std::vector<Player> players;
    int numberOfFields;
};
#endif //GTESTTEMPLATE_BOARD_H
