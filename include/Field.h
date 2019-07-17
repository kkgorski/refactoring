//
// Created by schab on 17.07.2019.
//

#ifndef GTESTTEMPLATE_FIELD_H
#define GTESTTEMPLATE_FIELD_H

#include <iostream>
#include <vector>
class Field {
public:
    virtual int onEntry(){return 0;}
    virtual int onPass(){return 0;}
};

class StartField: public Field{
    virtual int onPass() override {
        return 200;
    }
};

class PenaltyField: public Field{
    virtual int onEntry() override {
        return -150;
    }
};

class AwardField: public Field{
    virtual int onEntry() override {
        return 150;
    }
};





class FieldIterator{
public:

    FieldIterator(std::vector<Field*> fields){}

    FieldIterator& operator++(int)
    {
        ++current;
        ++counter;
        std::cout<<"ASD "<< current->onEntry();
        if(current == (*fields.end())) {
            counter = 0;
            current = start;
        }
    }
    Field* getCurrent(){return current;}
    int getCurrentFieldNumber(){ return counter;}

private:
    std::vector<Field*> fields;
    Field* current;
    int counter;

};

#endif //GTESTTEMPLATE_FIELD_H
