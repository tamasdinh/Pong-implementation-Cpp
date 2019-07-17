#include <iostream>
#include "Game.h"

int main(int argc, char** argv) {
    Game game(1024, 700);
    bool success = game.Initialize();
    if (success)
        game.GameLoop();
    game.ShutDownGame();
    return 0;
}