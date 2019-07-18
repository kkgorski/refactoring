//
// Created by schab on 17.07.2019.
//

#ifndef GTESTTEMPLATE_BOARD_H
#define GTESTTEMPLATE_BOARD_H

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include "math.h"
#include "Field.h"
#include "Player.h"

class StartField;

class Board {
public:
    Board(int _numberOfFields) : numberOfFields(_numberOfFields)
    {
        std::shared_ptr<DieInterface> die1 = std::make_shared<DieK6>();
        std::shared_ptr<DieInterface> die2 = std::make_shared<DieK10>();
        dieBucket = std::make_shared<DieBucket>(die1, die2);
        fieldVector.reserve(numberOfFields);
        fieldVector.push_back(std::make_shared<StartField>());
        for (auto i = 1 ; i < _numberOfFields - 1; ++i)
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
        fieldVector.push_back(std::make_shared<DepositField>());
        std::cout<<"Fields size "<< fieldVector.size() << std::endl;
    }

    void addPlayer(std::string name)
    {
        FieldIterator fieldIterator(fieldVector);
        players.push_back(std::make_shared<Player>(name, 1000, fieldIterator,dieBucket));
        std::cout<<" Adding player "<< players.back()->getName() << " position " << players.back()->getPossition() << std::endl;
    }

    void removeLosers()
    {
      players.erase(std::remove_if(players.begin(), players.end(),
             [](std::shared_ptr<Player> player) {return player->isBankrupt();}), players.end());
    }

    void terminateIfOnlyOnePlayerExists()
    {
      if (players.size() == 1)
      {
        std::cout << players.front()->getName() << " WON !!!!" << std::endl;
        throw "game is over";
      }
    }

    void playRound(){
      for (auto& player: players)
      {
        player->makeMove();
        std::cout<< player->getName() << "\t current position: "<< player->getPossition();
        std::cout<<" Current balance: "<<player->getMoney()<<std::endl;
      }
      removeLosers();
      terminateIfOnlyOnePlayerExists();
    }

private:

    std::vector< std::shared_ptr<Field> > fieldVector;
    std::vector< std::shared_ptr<Player> > players;
    int numberOfFields;
    std::shared_ptr<DieBucket> dieBucket;
};
#endif //GTESTTEMPLATE_BOARD_H
