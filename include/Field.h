//
// Created by schab on 17.07.2019.
//

#ifndef GTESTTEMPLATE_FIELD_H
#define GTESTTEMPLATE_FIELD_H

#include <iostream>
#include <vector>
#include <memory>

class Field {
public:
    virtual int onEntry() {return 0;}
    virtual int onPass() {return 0;}
    virtual ~Field(){}
};

class StartField: public Field
{
  public:
    virtual int onPass() override {
        return 200;
    }
};

class PenaltyField: public Field
{
  public:
    virtual int onEntry() override {
        return -150;
    }
};

class AwardField: public Field
{
  public:
    virtual int onEntry() override {
        return 150;
    }
};

class FieldIterator{
public:

    FieldIterator(std::vector< std::shared_ptr<Field> >& _fields): fields(_fields), current(fields.begin()), counter(0){}

    FieldIterator& operator++(int)
    {
        ++current;
        ++counter;
        if(current == fields.end()) {
            counter = 0;
            current = fields.begin();
        }
        std::cout << "iterator++: counter " << counter << " current " << (*current) << std::endl;
    }
    std::shared_ptr<Field> getCurrent(){return *current;}
    int getCurrentFieldNumber(){ return counter;}

private:
    std::vector< std::shared_ptr<Field> > fields;
    std::vector< std::shared_ptr<Field> >::iterator current;
    int counter;
};

#endif //GTESTTEMPLATE_FIELD_H
