//
// Created by schab on 17.07.2019.
//

#ifndef GTESTTEMPLATE_BOARD_H
#define GTESTTEMPLATE_BOARD_H

#include <iostream>
#include <vector>
#include <map>
#include "Field.h"
#include <memory>
#include "math.h"
#include "Player.h"

class StartField;

class Board {
public:
    Board(int _numberOfFields) : numberOfFields(40)
    {
        fieldVector.reserve(numberOfFields);
        fieldVector.push_back(std::make_shared<StartField>());
        for (auto i = 1 ; i < _numberOfFields; ++i)
        {
            if(i%3)
            {
              fieldVector.push_back(std::make_shared<AwardField>());
            }
            else
            {
              fieldVector.push_back(std::make_shared<PenaltyField>());
            }
        }
        std::cout<<"Fields size "<< fieldVector.size();
    }
    void addPlayer(std::string name)
    {
        FieldIterator fieldIterator(fieldVector);
        Player _player(name, 1000, fieldIterator);
        players.push_back(_player);
        std::cout<<" Adding player "<< _player.getName() << " position " << _player.getPossition();
    }

    void playRound(){
      for (auto& player: players)
      {
        player.makeMove();
        std::cout<<player.getName() << " current position: "<< player.getPossition();
        std::cout<<" Current balance: "<<player.getMoney()<<std::endl;
      }
    }

private:

    std::vector< std::shared_ptr<Field> > fieldVector;
    std::vector<Player> players;
    int numberOfFields;
};
#endif //GTESTTEMPLATE_BOARD_H
