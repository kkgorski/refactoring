//
// Created by schab on 17.07.2019.
//

#ifndef GTESTTEMPLATE_FIELD_H
#define GTESTTEMPLATE_FIELD_H

#include <iostream>
#include <vector>
#include <memory>

class Guest;

class Field {
public:
    virtual int onEntry(Guest* guest) {return 0;}
    virtual int onPass(Guest* guest) {return 0;}
    virtual ~Field(){}
};

class StartField: public Field
{
  public:
    virtual int onPass(Guest* guest) override {
        return 200;
    }
};

class PenaltyField: public Field
{
  public:
    virtual int onEntry(Guest* guest) override {
        return -700;
    }
};

class AwardField: public Field
{
  public:
    virtual int onEntry(Guest* guest) override {
        return 150;
    }
};

class DepositField: public Field
{
  public:
    virtual int onEntry(Guest* guest) override {
        int value = deposit;
        deposit = 0;
        return value;
    }
    virtual int onPass(Guest* guest) override {
        deposit =+150;
        return -150;
    }
private:
    int deposit = 0;
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
