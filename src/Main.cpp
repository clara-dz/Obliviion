#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


int main() {

    std::srand(std::time(nullptr));
    Game game;
    game.run();
    return 0;
}