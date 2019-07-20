//
// Created by schab on 17.07.2019.
//

#include <Field.h>
#include <Player.h>

void StartField::onPass(Player* player){
  std::cout <<" pass  start:   +200" ;
  player->updateMoney(200);
}

void PenaltyField::onEntry(Player* player){
  std::cout << " ent  penalty: -500" ;
  player->updateMoney(-500);
}

void AwardField::onEntry(Player* player){
  std::cout << " ent  award:   +200" ;
  player->updateMoney(200);
}

void DepositField::onEntry(Player* player){
  std::cout << " ent  deposit: +" << deposit ;
  player->updateMoney(deposit);
  deposit = 0;
}

void DepositField::onPass(Player* player){
  std::cout << " pass deposit: -150";
  player->updateMoney(-150);
  deposit += 150;
}

std::string PropertyField::getOwnerName()
{
  return owner->getName();
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

