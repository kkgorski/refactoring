//
// Created by schab on 17.07.2019.
//

#ifndef GTESTTEMPLATE_DIE_H
#define GTESTTEMPLATE_DIE_H

#include <memory>

class DieInterface {
public:
    virtual int roll()=0;
};

class DieK6: public DieInterface
{
    virtual int roll(){
        return (std::rand() % 6) + 1;
    }
};

class DieK10: public DieInterface
{
    virtual int roll(){
        return (rand() % 10) + 1;
    }
};


class DieBucket {
public:
    DieBucket(std::shared_ptr<DieInterface> _die1, std::shared_ptr<DieInterface> _die2):die1(_die1),die2(_die2){}
    int rollTwice(){
        return die1.get()->roll() + die2.get()->roll();
    }

private:
    std::shared_ptr<DieInterface> die1;
    std::shared_ptr<DieInterface> die2;
};
#endif //GTESTTEMPLATE_DIE_H

