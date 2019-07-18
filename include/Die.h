//
// Created by schab on 17.07.2019.
//

#ifndef GTESTTEMPLATE_DIE_H
#define GTESTTEMPLATE_DIE_H


class Die {
public:
    Die(int _type): type(_type){}
    int roll()
    {
        return (rand() % type) + 1;
    }
private:
    int type;
};


#endif //GTESTTEMPLATE_DIE_H
