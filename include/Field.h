//
// Created by schab on 17.07.2019.
//

#ifndef GTESTTEMPLATE_FIELD_H
#define GTESTTEMPLATE_FIELD_H

#include <iostream>
#include <vector>
#include <memory>

class Player;

class Field {
public:
    virtual void onEntry(Player* player) {}
    virtual void onPass(Player* player) {}
    virtual void resetPropertyIfOwnerIs(Player& player) {}
    virtual ~Field(){}
};

class StartField: public Field
{
  public:
    virtual void onPass(Player* player) override;
};

class PenaltyField: public Field
{
  public:
    virtual void onEntry(Player* player) override;
};

class AwardField: public Field
{
  public:
    virtual void onEntry(Player* player) override;
};

class DepositField: public Field
{
public:
  virtual void onEntry(Player* player) override;
  virtual void onPass(Player* player) override;
private:
  int deposit = 0;
};

class PropertyField: public Field {
public:
    PropertyField(int _rent, int _price): rent(_rent), price(_price), owner(nullptr){}

    int getRent(){
        return rent;
    }

    virtual void onEntry(Player* player) override;
    virtual void resetPropertyIfOwnerIs(Player& player) override;

private:
    bool hasOwner() const
    {
        return owner != nullptr;
    }

    void makePlayerPay(Player* player);

    void buyProperty(Player* player);
    void offerProperty(Player* player);
    void updateOwner(Player* player);

    Player* owner;
    int rent;
    int price;
};

class FieldIterator{
public:

    FieldIterator(std::vector< std::shared_ptr<Field> >& _fields): fields(_fields), current(_fields.begin()), counter(0){}

    FieldIterator& operator++()
    {
        //DON'T REMOVE, IMPORTANT DEBUG LOGS
        //std::cout << "iterator++: counter " << counter << " current " << (*current) << " fields.end() - 1 " << (*(fields.end() -1)) << " fields.begin() " << (*fields.begin()) << std::endl;
        if(*(current) == *(fields.end()- 1))
        {
          counter = 0;
          current = fields.begin();
        }
        else
        {
          ++current;
          ++counter;
        }
        return *this;
    }

    std::shared_ptr<Field> getCurrent(){return *current;}
    int getCurrentFieldNumber(){ return counter;}

private:
    std::vector< std::shared_ptr<Field> > fields;
    std::vector< std::shared_ptr<Field> >::iterator current;
    int counter;
};

#endif //GTESTTEMPLATE_FIELD_H
