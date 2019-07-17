/*
 * This source file implements the procedures for the Game class.
 */

#include <iostream>
#include "Game.h"

Game::Game(unsigned short int windowSizeX, unsigned short int windowSizeY) :
        _windowSizeX(windowSizeX),
        _windowSizeY(windowSizeY),
        ball1(new Ball),
        paddle1(new Paddle(300.0f, windowSizeX, windowSizeY)) {};

bool Game::Initialize() {
    // Initializing graphics functions
    int sdlInitializeResult = SDL_Init(SDL_INIT_VIDEO);     // initializing SDL with video only
    if (sdlInitializeResult != 0) {
        SDL_Log("Have not been able to initialize SDL; error message: %s", SDL_GetError());
        return false;
        // SDL_Init return int; if return value is non-zero, initialization failed.
    }

    // Initializing game window
    mWindow = SDL_CreateWindow("Ping Pong in C++ - first game implemented by Tamas Dinh", 100, 100, _windowSizeX, _windowSizeY, 0);
        // a note to window settings: x, y sets top left coordinates; w, h sets size; flags 0 - window deliberately not set to full-screen in this case.
    if (mWindow == nullptr) {
        SDL_Log("Game window initialization failed! Error message: %s", SDL_GetError());
        return false;
        // checking whether game window creation succeeded - if not, return false from function
    }

    // Initializing renderer
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (mRenderer == nullptr) {
        SDL_Log("Game renderer initialization failed! Error message: %s", SDL_GetError());
        return false;
    }

    // Setting base color of game window
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);     // clearing back buffer to current draw color
    SDL_RenderPresent(mRenderer);   // swap front and back buffers

    return true;
}

void Game::ShutDownGame() {
    // simply destroys previously created objects and quits from SDL
    SDL_DestroyWindow(mWindow);
    SDL_DestroyRenderer(mRenderer);
    SDL_Quit();
}

void Game::GameLoop() {
    // Runs the main game loop in an infinite loop until mIsRunning becomes false. We have separate functions for
        // the three stages of the game loop, so this functions only calls these functions when running the loop.
    while (mIsRunning) {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

// IKEA reklamacio: 2502934

void Game::ProcessInput() {
    // Continuously polling SDL event queue - if window is closed, game quits
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                mIsRunning = false;
                break;
        }
    }
    // Checking for keyboard state - if Esc is pressed, game quits
    state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_ESCAPE])
        mIsRunning = false;
}

void Game::UpdateGame() {
    // Guarding against too fast refresh
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));

    // Establishing delta time
    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
    mTicksCount = SDL_GetTicks();

    // Clipping delta time
    if (deltaTime > 0.05f)
        deltaTime = 0.05f;

    // Handling paddle movements
    paddle1->changePaddlePosition(state[SDL_SCANCODE_W], state[SDL_SCANCODE_S], deltaTime);
    std::cout << "Paddle direction: " << paddle1->getPaddleDirection() << std::endl;
    std::cout << "Paddle position y: " << paddle1->getPosition().y << std::endl;
    // TODO: limit so that paddle cannot go out of window
}

void Game::GenerateOutput() {

    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 0);  // setting draw color
    SDL_RenderClear(mRenderer);

    const int thickness = 15;
    // Drawing top wall
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);  // setting draw color
    SDL_Rect wallTop {0, 0, 1024, thickness};
    SDL_RenderFillRect(mRenderer, &wallTop);

    // Drawing bottom wall
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);  // setting draw color
    SDL_Rect wallBottom {0, 685, 1024, thickness};
    SDL_RenderFillRect(mRenderer, &wallBottom);

    // Drawing ball and paddle
    SDL_Rect ball {
            static_cast<int>(512 - thickness / 2),
            static_cast<int>(350 - thickness / 2),
            thickness,
            thickness
    };

    SDL_Rect paddle {
            static_cast<int>(8 - thickness / 2),
            static_cast<int>(paddle1->getPosition().y - paddle1->getLength() / 2),
            thickness,
            paddle1->getLength()
    };

    SDL_RenderFillRect(mRenderer, &ball);
    SDL_RenderFillRect(mRenderer, &paddle);

    SDL_RenderPresent(mRenderer);   // swap front and back buffers
}

