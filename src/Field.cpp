//
// Created by schab on 17.07.2019.
//

#include <Field.h>
#include <Player.h>

void StartField::onPass(Player* player){
  player->updateMoney(200);
}

void PenaltyField::onEntry(Player* player){
  player->updateMoney(-600);
}

void AwardField::onEntry(Player* player){
  player->updateMoney(200);
}

void DepositField::onEntry(Player* player){
  player->updateMoney(deposit);
  deposit = 0;
}

void DepositField::onPass(Player* player){
  player->updateMoney(-150);
}

void PropertyField::onEntry(Player* player){
if (hasOwner())
  makePlayerPay(player);
else
  offerProperty(player);
}

void PropertyField::makePlayerPay(Player* player) {
  player->updateMoney(-rent);
  owner->updateMoney(rent);
}

void PropertyField::buyProperty(Player* player){
  player->updateMoney(-price);
  owner = player;
}

void PropertyField::offerProperty(Player* player){
  if(player->getMoney() >= price && player->considerBuying(price))
  {
    player->updateMoney(-price);
    updateOwner(player);
  }
}

void PropertyField::updateOwner(Player* player){
  owner = player;
}

void PropertyField::resetPropertyIfOwnerIs(Player& player){
  if(owner == &player)
    owner = nullptr; 
}

