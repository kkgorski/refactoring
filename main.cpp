#include <iostream>
#include "MonopolyGame.h"
#include "Die.h"

int main()
{
    std::shared_ptr<DieInterface> die1 = std::make_shared<DieK6>();
    std::shared_ptr<DieInterface> die2 = std::make_shared<DieK10>();
    std::shared_ptr<DieBucket> dieBucket = std::make_shared<DieBucket>(die1, die2);
    MonopolyGame monopolyGame(40, dieBucket);
    monopolyGame.addPlayer("Kuba");
    monopolyGame.addPlayer("Olaf");
    monopolyGame.addPlayer("Stee");
    monopolyGame.addPlayer("Gome");
    monopolyGame.addPlayer("xdxd");
    monopolyGame.runGame();
    return 0;
}
