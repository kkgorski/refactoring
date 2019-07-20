//
// Created by schab on 17.07.2019.
//

#include <Field.h>
#include <Player.h>

void StartField::onPass(Player* player){
  std::cout << player->getName() << " passing start field: +200" << std::endl;
  player->updateMoney(200);
}

void PenaltyField::onEntry(Player* player){
  std::cout << player->getName() << " entering penalty field: -200" << std::endl;
  player->updateMoney(-1000);
}

void AwardField::onEntry(Player* player){
  std::cout << player->getName() << " entering award field: +200" << std::endl;
  player->updateMoney(200);
}

void DepositField::onEntry(Player* player){
  std::cout << player->getName() << " entering deposit field: +" << deposit << std::endl;
  player->updateMoney(deposit);
  deposit = 0;
}

void DepositField::onPass(Player* player){
  std::cout << player->getName() << " passsing deposit field: -150" << std::endl;
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

