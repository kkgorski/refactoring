//
// Created by schab on 17.07.2019.
//

#ifndef GTESTTEMPLATE_DIE_H
#define GTESTTEMPLATE_DIE_H

#include <memory>
#include "vector"

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
class DieCosmic: public DieInterface
{
    virtual int roll(){
        return ((rand() % 9) + 1)%8;
    }
};


class DieBucket {
public:
    int rollTwice(){
        int result = 0;
        for( auto i: dies)
            result += i.get()->roll();
        return result;
    }
    DieBucket(std::vector<std::shared_ptr<DieInterface>> die) {
        dies = die;
    }

private:
    std::vector<std::shared_ptr<DieInterface>> dies;

};



#endif //GTESTTEMPLATE_DIE_H

