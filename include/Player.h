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

    Player(std::string _name, int _money, FieldIterator _field, std::shared_ptr<DieBucket> bucket): name(_name), money(_money), field(_field), die(bucket) {}

    const std::string getName() const
    {
      return name;
    }
    int getMoney() const
    {
      return money;
    }

    void updateMoney(int value)
    {
        money += value;
    }

    void makeMove()
    {
        int roll = die.get()->rollTwice();
        while (roll--)
        {
            ++field;
            if (field.getCurrentFieldNumber() == 0)
                field.getCurrent()->onPass(this);
        }

        field.getCurrent()->onEntry(this);
    }
    int getPossition()
    {
      return field.getCurrentFieldNumber();
    }

    bool isBankrupt()
    {
      return money <= 0;
    }
    virtual bool considerBuying(int price)=0;
protected:
    const std::string name;
    int money;
    std::shared_ptr<DieBucket> die;
    FieldIterator field;
};


class RealPlayer : public Player
{
public:
    RealPlayer(std::string _name, int _money, FieldIterator _field, std::shared_ptr<DieBucket> bucket): Player( _name, _money, _field,  bucket) {}
      virtual bool considerBuying(int price);
};

class GreedyAIPlayer : public Player
{
public:
    GreedyAIPlayer(std::string _name, int _money, FieldIterator _field, std::shared_ptr<DieBucket> bucket): Player( _name, _money, _field,  bucket) {}

    virtual bool considerBuying(int price) { return 1;}
};

class RandomAIPlayer : public Player
{
public:

    RandomAIPlayer(std::string _name, int _money, FieldIterator _field, std::shared_ptr<DieBucket> bucket): Player( _name, _money, _field,  bucket) {}

    virtual bool considerBuying(int price) { return std::rand() % 2;}
};

#endif //GTESTTEMPLATE_PLAYER_H
