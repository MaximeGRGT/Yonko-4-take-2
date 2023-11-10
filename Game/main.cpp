#include "GameLoop.hpp"
#include <iostream>
#include <random>
#include <time.h>
int main() {
    srand(time(NULL));
    GameLoop game;
    game.run();
    return 0;
}