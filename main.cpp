#include <iostream>
#include "MonopolyGame.h"

int main()
{
    MonopolyGame monopolyGame(40);
    monopolyGame.addPlayer("Kuba");
    monopolyGame.addPlayer("Olaf");
    monopolyGame.addPlayer("Stee");
    monopolyGame.addPlayer("Gome");
    monopolyGame.addPlayer("xdxd");
    monopolyGame.runGame();
    return 0;
}
