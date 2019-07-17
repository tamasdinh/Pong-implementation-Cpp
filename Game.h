#ifndef INC_26_PONG_CPP_GAME_H
#define INC_26_PONG_CPP_GAME_H

#include <SDL2/SDL.h>

class Game {
    public:
        Game();     // constructor
        bool Initialize();  // game initialization steps
        void GameLoop();    // main loop to perform continuous looping while game is running
        void ShutDownGame();    // shutting down game when exit key is pressed TODO: check this for consistency with final implementation

    private:
        bool mIsRunning;    // boolean for indicating whether game should continue running

        void ProcessInput();    // first element of game loop - processes user inputs
        void UpdateGame();      // second element of game loop - updates game variables
        void GenerateOutput();  // third element of game loop - refreshes game outputs (graphics in this case)

        SDL_Window* mWindow;    // pointer to window instance initialized with SDL
};


#endif //INC_26_PONG_CPP_GAME_H
