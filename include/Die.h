//
// Created by schab on 17.07.2019.
//

#ifndef GTESTTEMPLATE_DIE_H
#define GTESTTEMPLATE_DIE_H


class Die {
public:
    int roll()
    {
        return (rand() % 6) + 1;
    }
};


#endif //GTESTTEMPLATE_DIE_H
