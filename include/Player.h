//
// Created by schab on 17.07.2019.
//

#ifndef GTESTTEMPLATE_PLAYER_H
#define GTESTTEMPLATE_PLAYER_H

#include "Die.h"
#include "Field.h"

class Player
{
public:

    Player(std::string _name, int _money, FieldIterator _field): name(_name), money(_money), field(_field){}

    const std::string getName() const
    {
      return name;
    }
    int getMoney() const
    {
      return money;
    }
    void makeMove()
    {
        int roll = rollDice();
        while (roll--)
        {
            money += field.getCurrent()->onPass();
            ++field;
        }
        money += field.getCurrent()->onEntry();
    }
    int getPossition()
    {
      return field.getCurrentFieldNumber();
    }
 
    bool isBankrupt()
    {
      return money < 0;
    }
private:
    int rollDice()
    {
      return die.roll() + die.roll();
    }
    const std::string name;
    int money;
    Die die;
    FieldIterator field;
};
#endif //GTESTTEMPLATE_PLAYER_H
