//
// Created by schab on 17.07.2019.
//
#include "Player.h"
#include "Field.h"

bool RealPlayer::considerBuying(int price)
{
        std::cout<<"Want to buy field"<< field.getCurrentFieldNumber()<< "? 1 - Yes, 0 - No"<<std::endl;
      int decision = 0;
      std::cin>>decision;
      return decision;
}

