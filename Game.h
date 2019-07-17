#ifndef INC_26_PONG_CPP_GAME_H
#define INC_26_PONG_CPP_GAME_H

#include <SDL2/SDL.h>
#include "Ball.h"
#include "Paddle.h"

class Game {
    public:
        Game(unsigned short int windowSizeX, unsigned short int windowSizeY);     // constructor
        bool Initialize();  // game initialization steps
        void GameLoop();    // main loop to perform continuous looping while game is running
        void ShutDownGame();    // shutting down game when exit key is pressed

    private:
        bool mIsRunning = true;    // boolean for indicating whether game should continue running
                                   // have to initialize to true otherwise initializes with value of 0

        void ProcessInput();    // first element of game loop - processes user inputs
        void UpdateGame();      // second element of game loop - updates game variables
        void GenerateOutput();  // third element of game loop - refreshes game outputs (graphics in this case)

        SDL_Window* mWindow;    // pointer to window instance initialized with SDL
        SDL_Renderer* mRenderer;    // pointer to SDL renderer object
        unsigned short int _windowSizeX;
        unsigned short int _windowSizeY;

        const Uint8* state;

        Uint32 mTicksCount;     // var to save elapsed game time

        std::shared_ptr<Ball> ball1;       // declaring ball1 as a private member of game TODO: expand this to have a vector of balls?
        std::shared_ptr<Paddle> paddle1;   // declaring paddle1 as written above
};


#endif //INC_26_PONG_CPP_GAME_H
