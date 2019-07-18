//
// Created by schab on 17.07.2019.
//

#ifndef GTESTTEMPLATE_BOARD_H
#define GTESTTEMPLATE_BOARD_H

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <algorithm>
#include "math.h"
#include "Field.h"
#include "Player.h"

using FieldPtr = std::shared_ptr<Field>;
class Board {
public:
    Board(int _numberOfFields) : numberOfFields(_numberOfFields)
    {
        fieldVector.reserve(numberOfFields);
        fieldVector.push_back(std::make_shared<StartField>());
        for (auto i = 1 ; i < _numberOfFields - 1; ++i)
        {
            if(i%3)
            {
              fieldVector.push_back(std::make_shared<AwardField>());
            }
            else
            {
              fieldVector.push_back(std::make_shared<PenaltyField>());
            }
        }
        fieldVector.push_back(std::make_shared<DepositField>());
        std::cout<<"Fields size "<< fieldVector.size() << std::endl;
    }

    std::vector< FieldPtr >& getFieldVector()
    {
      return fieldVector;
    }

private:
    std::vector< FieldPtr > fieldVector;
    int numberOfFields;
};
#endif //GTESTTEMPLATE_BOARD_H
