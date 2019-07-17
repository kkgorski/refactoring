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
    Board(int _numberOfFields) : numberOfFields(40){        std::cout<<"DDDDDDDDDD";
    fieldVector.reserve(40);
        StartField* tmp = new StartField();
        fieldVector.push_back(tmp);
        for (auto i = 0 ; i <= _numberOfFields; ++i)
        {
            std::cout<<"XXXXXXXXXXXXXXXX";

            AwardField* dd = new AwardField();

//            if(i%3)
//            fieldVector.push_back(PenaltyField());
//            else
            fieldVector.push_back(dd);


        }
    }
    void addPlayer(std::string name)
    {
        FieldIterator fieldIterator(fieldVector.begin());
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
    std::vector<Field*> fieldVector;
    std::vector<Player> players;
    int numberOfFields;

};


#endif //GTESTTEMPLATE_BOARD_H
