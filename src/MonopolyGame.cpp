//
// Created by schab on 17.07.2019.
//

#ifndef GTESTTEMPLATE_MONOPOLYGAME_CPP
#define GTESTTEMPLATE_MONOPOLYGAME_CPP

#include "Board.h"
#include "Die.h"
#include "MonopolyGame.h"

MonopolyGame* MonopolyGame::buildBoard(int numberOfFields)
{
  board = Board(numberOfFields);
  return this;
}

MonopolyGame* MonopolyGame::addDieBucket(std::shared_ptr<DieBucket> bucket)
{
  dieBucket = bucket;
  return this;
}

void MonopolyGame::run(int turns)
{
  while(turns--)
  {
    std::cout <<"TURN "<< turns << std::endl << std::endl;
    try
    {
      playRound();
    }
    catch (...)
    {
      break;
    }
  }
}

void MonopolyGame::removeLosers()
{
  players.erase(std::remove_if(players.begin(), players.end(),
        [](std::shared_ptr<Player> player) {return player->isBankrupt();}), players.end());
}

void MonopolyGame::terminateIfOnlyOnePlayerExists()
{
  if (players.size() == 1)
  {
    std::cout << players.front()->getName() << " WON !!!!" << std::endl;
    throw "game is over";
  }
}

void MonopolyGame::resetPropertyOwnedBy(Players& player)
{
  std::vector< FieldPtr > fieldVector = board.getFieldVector();
  std::cout << "Resetting properties owned by: " << player->getName() << std::endl;
  for (auto& field : fieldVector)
  {
    field->resetPropertyIfOwnerIs(*player);
  }
}

void MonopolyGame::printProperties()
{
  std::vector< FieldPtr > fieldVector = board.getFieldVector();
  int counter = 0;
  std::string propertyOwners ="";
  for (auto& field : fieldVector)
  {
    propertyOwners += std::to_string(counter); //TODO should be field name
    propertyOwners += "[";
    propertyOwners += field->getOwnerName();
    propertyOwners += "] ";
    counter++;
  }
  std::cout << propertyOwners << std::endl;
}

void MonopolyGame::playRound(){
  for (auto& player: players)
  {
    player->makeMove();
    if(player->isBankrupt())
    {
      resetPropertyOwnedBy(player);
    }
  }

  printProperties();
  removeLosers();
  terminateIfOnlyOnePlayerExists();
}

#endif //GTESTTEMPLATE_MONOPOLYGAME_CPP
