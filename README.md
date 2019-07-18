<h1>Pong game implementation in C++</h1>

<h2>1. Game overview</h2>

The app implements a simple game of ```Pong```. At startup, the app initializes
a window that has a paddle on the right side, a ball in the middle and three walls
around.  The paddle can be controlled by keyboard presses on ```W(up)```
and ```S(down)```. The ball automatically starts travelling and when it hits a wall
or the paddle, it bounces and accelerates.

In the meantime, the app keeps track of the player's score and sends related messages
via the standard text output device (the terminal):
- 1 point is awarded for
each bounce of the ball (wall or paddle), and
- 10 points are deducted if the ball leaves the game area ("goes out" of the window on the paddle's side).

If the ball leaves the game area, it is placed back in the center and its
color is changed. The app pauses for 2 seconds, then the game restarts,
with the ball's travelling speed reset to the initial speed.

The game can be played infinitely, with the app keeping track of the player's score in the terminal.
The app can be terminated by pressing the ```Esc``` key or closing the window.

<h2>2. Installation instructions</h2>

- Depending on your system, install a C++ compiler (macOS has g++ built-in with XCode Command Line Developer Tools, or alternatively you can use clang++ etc.) [GCC](https://gcc.gnu.org) -- [Clang](https://clang.llvm.org/get_started.html)
- You must have CMake and Make installed to be able to build the app from source: [Cmake install](https://cmake.org/install/) -- [GNU page for Make](https://www.gnu.org/software/make/)
- please install ```git``` if you don't have it (macOS has it by default): [Git installation](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)
- You have to have SDL 2.0 installed (see [SDL's download page](https://libsdl.org/download-2.0.php)) for source code or binaries for  different OSes. Place the SDL 2.0 files somewhere where your compiler looks for third-party libraries
- The app folder is set up to use ```CMake``` and ```make```; you can compile the app with via the following steps:
    - open a new ```terminal```
    - ```cd``` into the folder where you would like to clone the repository
    - run ```git clone https://github.com/tamasdinh/Pong-implementation-Cpp``` - this will download the whole project folder for you from my GitHub repository
    - ```cd``` to the ```Pong-implementation-Cpp``` directory
    - run ```mkdir build``` (or whatever command creates a directory in your OS)
    - run ```cmake ..```
    - run ```make```
    - the executable binary file will appear in the ```build``` directory (this is your current working directory). You can run the app by running ```./26_Pong_Cpp``` in the terminal.
- Play in the game window and read the messages in the terminal! See if you can beat yourself - as the old samurai saying goes: ```True victory is victory over the self.```

<h2>3. App structure and implementation logic</h2>
The app is implemented in an object-oriented fashion, with operation
factored into separate classes with an efficient inheritance structure.

- __class ```PongObject``` (PongObject.h):__
    - Base class for all moving objects (```Paddle``` and ```Ball```) in the game.
    - Implements a ```base constructor```.
    - Encapsulates data members for ```windowLimit (x and y)```, ```position (x and y)```, ```length```, ```thickness```, ```color``` and ```drawingObject```.
    - Declares and defines suitable ```getter``` and ```setter``` functions for data members.
    - Implements ```updateDrawingObject``` and ```switchColor``` as common methods for ```PongObject``` objects.

- __class ```Paddle``` (Paddle.h):__
    - Child class of ```PongObject```
    - Declares data members unique to ```Paddle```: ```paddleDirection``` and ```paddleMovingSpeed``` and declares and defines appropriate ```getter``` functions for them (setters not needed)
    - Overrides ```base constructor``` in ```PongObject``` to add initialization for data members unique to ```Paddle```
    - Declares and defines ```changePaddlePosition``` method (caters for handling paddle movements based on user input)

- __class ```Ball``` (Ball.h):__
    - Child class of ```PongObject```
    - Declares data members unique to ```Ball```: ```startVelocity (x and y)```, ```velocity (x and y)```, ```acceleration``` and ```hasBounced``` (getters and setters not needed as they are catered for in ```PongObject```)
    - Overrides ```base constructor``` in ```PongObject``` to add initialization for data members unique to ```Ball```
    - Declares and defines ```updatePosition``` method (caters for handling ball movements, including bouncing) as well as helper methods ```hasBounced``` (getter for ```hasBounced``` data member), ```ballOut``` (signals if ball left game area) and ```resetVelocity```.

- __class ```Game``` (Game.h):__
    - Encapsulates the whole logic for the game
    - _public methods:_
        - ```Initialize()```: Initializes ```SDL``` graphic objects.
        - ```GameLoop()```: executes private member functions ```ProcessInput()```, ```UpdateGame()``` and ```GenerateOutput()``` in a while loop that runs until the ```mIsRunning``` data member becomes ```false```.
        - ```ShutDownGame()```: destructs previously created ```SDL``` objects and terminates ```SDL``` session.
    - The ```Game Loop``` is implemented via the following methods:
        - ```ProcessInput()```:
            - Responsible for handling user inputs during the game.
            - Utilizes ```SDL_event``` and ```SDL_GetKeyBoardState()``` to continuously query for user inputs on the keyboard. Saves keyboard state to data member ```state``` and sets ```mIsRunning``` to ```false``` if the ```Esc``` key is pressed, thereby halting the ```game loop```.
        - ```UpdateGame()```:
            - Responsible for updating the game state in every iteration of the ```game loop```.
            - Calculates ```deltaTime``` - time passed since last loop, and also caps it so that if game pauses no "jumps" occur
            - updates the paddle's position by envoking ```Paddle::changePaddlePosition()```, which takes inputs for the keyboard state corresponding to the ```"Up" key (W)``` and the ```"Down" key (S)``` and ```deltaTime```
            - updates the ball's position by envoking ```Ball::updatePosition()```, which takes ```deltaTime``` as input as well as relevant other parameters
            - checks whether the ball has left the game area - if so, deducts score and resets ball state to the center (and also indicates via a data member that the ball's color has to be changed)
            - checks whether the ball has bounced - if so, awards a point and outputs message to terminal
            - updates the ```SDL``` drawing objects in ```Paddle``` and ```Ball```.
        - ```GenerateOutput()```:
            - Responsible for updating graphics, based on the updated game state.
            - Redraws background, walls, paddle and ball in each iteration of the ```game loop```.
            - If ball recoloring need was indicated, switches ball color via ```Ball::switchColor()``` (inherited from ```PongObject```) and makes the app pause for 2 seconds.

<h2>4. Methodological notes</h2>

___NOTE:___ I made 2 small modifications to the code, in order for it to be able to run on a Linux remote VM:

* I changed renderer options from SDL_RENDERER_ACCELERATED to 0 (system chooses) as the Linux remote machine >came back with "Cannot find suitable renderer" error
* I commented out the line in ```Game::UpdateGame()``` in which I am guarding against too fast execution compared to the frame rate of the machine.
* The two changes above enabled the remote Linux VM to run the program, albeit with a little lagging

- ___```Loops, function, I/O```:___
    - The app utilizes a main while loop for the implementation of the ```game loop``` and certainly there are a number of ```if``` statements governing the logic of the app.
    - User input (keystrokes during gameplay) is handled via ```Game::ProcessInput()``` as part of the main ```game loop```.
    - The app does not read in data from any persistent data sources and only outputs non-persistent graphics and text via the output device (main display).
- ___```Object-oriented Programming (OOP)```:___
    - All operations are encapsulated in classes and corresponding member functions; state is monitored via data members of the respective classes.
    - I used inheritance between the ```PongObject``` base class and its specific children ```Paddle``` and ```Ball```, as described above in ___2. App structure and implementation logic___
    - ```Base constructor``` is overriden in both child classes as appropriate; I didn't see a need for any further application of polymorphism (as this is a game - not a user program -, there is no user who would want to e.g. call a function differently than I did in the implementation). Also, ```PongObject``` is not implemented as an ```abstract class``` as most of the functionality that it provides can be shared (inherited) to its child classes. As such, I didn't use virtual functions or templates.
    - Member initialization lists are utilized as fully as possible (a number of data members could not have been initialized via initialization lists)
- ___```Memory management```:___
    - ```Game``` is envoked on the stack in ```main```, so I decided that no destructor was needed.
    - ```Ball``` and ```Paddle``` are initialized on the heap, and ```shared_ptr```s pointing to their memory addresses are included as members in the ```Game``` class. As such, no destructors for these classes were deemed necessary as the ```shared_ptr```s go out of scope in ```main()``` when the app finished running and with that, free up the memory allocated for ```Ball``` and ```Paddle``` objects.
    - ```SDL``` objects that are created, are destructed with corresponding ```SDL``` methods.
    - I utilized references to variables and data members everywhere possible to avoid unnecessarily copying variables between functions.
- ___```Concurrency```:___
    - ```Concurrency``` was not used explicitly in the program. (SDL uses multithreading within its own methods.)


