#include <iostream>
#include "MonopolyGame.h"
#include "Die.h"
#include "vector"

int main()
{

    std::shared_ptr<DieInterface> die1 = std::make_shared<DieK6>();
    std::shared_ptr<DieInterface> die2 = std::make_shared<DieK6>();
    std::vector< std::shared_ptr<DieInterface>> dies;
    dies.push_back(die1);
    dies.push_back(die2);
    std::shared_ptr<DieBucket> dieBucket = std::make_shared<DieBucket>(dies);

    std::unique_ptr<MonopolyGame> game = std::make_unique<MonopolyGame>();
    game->buildBoard(10)
        ->addDieBucket(dieBucket)
        ->addPlayer<RealPlayer>("Olaf")
        ->addPlayer<GreedyAIPlayer>("Stee")
        ->addPlayer<RandomAIPlayer>("xdxd");
    game->run();
    return 0;
}
