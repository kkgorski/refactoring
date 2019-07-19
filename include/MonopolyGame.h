//
// Created by schab on 17.07.2019.
//

#ifndef GTESTTEMPLATE_MONOPOLYGAME_H
#define GTESTTEMPLATE_MONOPOLYGAME_H

#include "Board.h"
#include "Die.h"

using Players = std::shared_ptr<Player>;
class MonopolyGame
{
public:
    MonopolyGame(int numberOfFields, std::shared_ptr<DieBucket> bucket): board(numberOfFields), dieBucket(bucket)
    {    }
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
    template <typename T>
    void addPlayer(std::string name)
    {
        FieldIterator fieldIterator(board.getFieldVector());
        players.push_back(std::make_shared<T>(name, 1000, fieldIterator,dieBucket));
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

    void resetPropertyOwnedBy(Players& player)
    {
      std::vector< FieldPtr > fieldVector = board.getFieldVector();
      for (auto& field : fieldVector)
      {
        field->resetPropertyIfOwnerIs(*player);
      }
    }

    void playRound(){
      for (auto& player: players)
      {
        player->makeMove();
        std::cout<< player->getName() << "\t current position: "<< player->getPossition();
        std::cout<<" Current balance: "<<player->getMoney()<<std::endl;
        if(player->isBankrupt())
        {
          resetPropertyOwnedBy(player);
        }
      }
      removeLosers();
      terminateIfOnlyOnePlayerExists();
    }

    std::vector< Players > players;
    std::shared_ptr<DieBucket> dieBucket;
    Board board;
};

#endif //GTESTTEMPLATE_MONOPOLYGAME_H
