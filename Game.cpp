/*
 * This source file implements the procedures for the Game class.
 */

#include "Game.h"

bool Game::Initialize() {
    // Initializing graphics functions
    int sdlInitializeResult = SDL_Init(SDL_INIT_VIDEO);     // initializing SDL with video only
    if (sdlInitializeResult != 0) {
        SDL_Log("Have not been able to initialize SDL; error message: %s", SDL_GetError());
        return false;
        // SDL_Init return int; if return value is non-zero, initialization failed.
    }

    // Initializing game window
    mWindow = SDL_CreateWindow("Ping Pong in C++ - first game implemented by Tamas Dinh", 100, 100, 1024, 768, 0);
        // a note to window settings: x, y sets top left coordinates; w, h sets size; flags 0 - window deliberately not set to full-screen in this case.
    if (mWindow == nullptr) {
        SDL_Log("Game window initialization failed! Error message: %s", SDL_GetError());
        return false;
        // checking whether game window creation succeeded - if not, return false from function
    }
}

void Game::ShutDownGame() {
    // simply destroys window and quits from SDL
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Game::GameLoop() {
    // Runs the main game loop in an infinite loop until mIsRunning becomes false. We have separate functions for
        // the three stages of the game loop, so this functions only calls these functions when running the loop.
    while(mIsRunning) {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}
