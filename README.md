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

<h2>2. App structure and implementation logic</h2>
The app is implemented in an object-oriented fashion, with operation
factored into separate classes with an efficient inheritance structure.

- __class ```PongObject``` (PongObject.h):__
    - Base class for all moving objects (```Paddle``` and ```Ball```) in the game.
    - Implements a ```base constructor```.
    - Encapsulates data members for ```windowLimit```, ```position```, ```length```, ```thickness```, ```color``` and ```drawingObject```.
    - Declares and defines suitable ```getter``` and ```setter``` functions for data members.
    - Implements ```updateDrawingObject``` and ```switchColor``` as common methods for ```PongObject``` objects.

- __class ```Paddle``` (Paddle.h):__
    - Child class of ```PongObject```
    - Declares data members unique to ```Paddle```: ```paddleDirection``` and ```paddleMovingSpeed``` and declares and defines appropriate ```getter``` functions for them (setters not needed)
    - Overrides ```base constructor``` in ```PongObject``` to add initialization for data members unique to ```Paddle```
    - Declares and defines ```changePaddlePosition``` method (caters for handling paddle movements based on user input)

- __class ```Ball``` (Ball.h):__
    - Child class of ```PongObject```
    - Declares data members unique to ```Ball```: ```startVelocity (x and y)```, ```velocity```, ```acceleration``` and ```hasBounced``` (getters and setters not needed as they are catered for in ```PongObject```)
    - Overrides ```base constructor``` in ```PongObject``` to add initialization for data members unique to ```Ball```
    - Declares and defines ```updatePosition``` method (caters for handling ball movements, including bouncing) as well as helper methods ```hasBounced``` (getter for ```hasBounced``` data member), ```ballOut``` (signals if ball left game area) and ```resetVelocity```.

- __class ```Game``` (Game.h):__
    - Encapsulates the whole logic for the game
    - _public methods:_
        - ```Initialize()```:
        - ```GameLoop()```:
        - ```ShutDownGame()```:
    - The ```Game Loop``` is implemented via the following methods:
        - ```ProcessInput()```:
        - ```UpdateGame()```:
        - ```GenerateOutput()```:

<h2>3. Methodological notes</h2>

- ___```Object-oriented Programming (OOP)```:___
- ___```Loops, function, I/O```:___
- ___```Memory management```:___
- ___```Concurrency```:___


