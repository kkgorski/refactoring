#include <iostream>
#include "MonopolyGame.h"
#include "Die.h"

int main()
{

    std::shared_ptr<DieInterface> die1 = std::make_shared<DieK6>();
    std::shared_ptr<DieInterface> die2 = std::make_shared<DieK6>();
    std::vector< std::shared_ptr<DieInterface>> dies;
    std::shared_ptr<DieBucket> dieBucket = std::make_shared<DieBucket>(dies);

    MonopolyGame monopolyGame(40, dieBucket);
    monopolyGame.addPlayer<RealPlayer>("Kuba");
    monopolyGame.addPlayer<RealPlayer>("Olaf");
    monopolyGame.addPlayer<GreedyAIPlayer>("Stee");
    monopolyGame.addPlayer<GreedyAIPlayer>("Gome");
    monopolyGame.addPlayer<RandomAIPlayer>("xdxd");
    monopolyGame.runGame();
    return 0;
}
