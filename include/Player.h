//
// Created by schab on 17.07.2019.
//

#ifndef GTESTTEMPLATE_PLAYER_H
#define GTESTTEMPLATE_PLAYER_H

#include "Die.h"
#include "Field.h"

class Guest;

class Player
{
public:

    Player(std::string _name, int _money, FieldIterator _field, std::shared_ptr<DieBucket> bucket): name(_name), money(_money), field(_field), die(bucket) {}

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
        int roll = die.get()->rollTwice();
        while (roll--)
        {
            ++field;
            if (field.getCurrentFieldNumber() == 0)
                money += field.getCurrent()->onPass(reinterpret_cast<Guest *>(this));
        }

        money += field.getCurrent()->onEntry(reinterpret_cast<Guest *>(this));
    }
    int getPossition()
    {
      return field.getCurrentFieldNumber();
    }
 
    bool isBankrupt()
    {
      return money <= 0;
    }
private:
    const std::string name;
protected:
    int money;
private:
    FieldIterator field;
    std::shared_ptr<DieBucket> die;
};

class Guest : private Player
{
  void incrementMoney(int amount)
  {
    money += amount;
  }
  void decrementMoney(int amount)
  {
    money += amount;
  }
};

#endif //GTESTTEMPLATE_PLAYER_H
