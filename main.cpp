#include "Game.h"

int main(int argc, char** argv) {
    Game game(600, 500, 100, true);
    bool success = game.Initialize();
    if (success)
        game.GameLoop();
    game.ShutDownGame();
    return 0;
}