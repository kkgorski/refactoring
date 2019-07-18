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
    MonopolyGame(int numberOfFields): board(numberOfFields) {}
    void runGame(int turns = 100)
    {
      while(turns--){
        std::cout <<"turn "<< turns << std::endl;
        try{
        playRound();
        }
        catch (...)
        {
          break;
        }
    }
    }
    void addPlayer(std::string name)
    {
        FieldIterator fieldIterator(board.getFieldVector());
        players.push_back(std::make_shared<Player>(name, 1000, 6 /*dieType*/ , fieldIterator));
        std::cout<<" Adding player "<< players.back()->getName() << " position " << players.back()->getPossition() << std::endl;
    }
private:
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

    std::vector< std::shared_ptr<Player> > players;
    Board board;
};

#endif //GTESTTEMPLATE_MONOPOLYGAME_H
