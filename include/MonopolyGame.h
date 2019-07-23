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
    MonopolyGame(){}
    MonopolyGame* buildBoard(int);
    MonopolyGame* addDieBucket(std::shared_ptr<DieBucket>);
    template <typename T>
    MonopolyGame* addPlayer(std::string name)
    {
      FieldIterator fieldIterator(board.getFieldVector());
      players.push_back(std::make_shared<T>(name, 1000, fieldIterator,dieBucket));
      std::cout<<" Adding player "<< players.back()->getName() << " position " << players.back()->getPossition() << " money " << players.back()->getMoney() << std::endl;
      return this;
    }
    void run(int turns = 100);
  private:
    void removeLosers();
    void terminateIfOnlyOnePlayerExists();
    void resetPropertyOwnedBy(Players&);
    void printProperties();
    void playRound();

    std::vector< Players > players;
    std::shared_ptr<DieBucket> dieBucket;
    Board board;
};

#endif //GTESTTEMPLATE_MONOPOLYGAME_H
