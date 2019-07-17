//
// Created by Tamás Dinh on 2019-07-17.
//

#include <SDL2/SDL_rect.h>
#include "Paddle.h"

void Paddle::draw() const {
    SDL_Rect paddle {
        static_cast<int>(_position.x - _thickness / 2),
        static_cast<int>(_position.x - _thickness / 2),
        _thickness,
        _thickness
    };
}

void Paddle::changePaddlePosition(bool sdlKeyboardStateUp, bool sdlKeyBoardStateDown, float deltaTime) {
    _mPaddleDirection = 0;
    if (sdlKeyboardStateUp)
        _mPaddleDirection -= 1;
    if (sdlKeyBoardStateDown)
        _mPaddleDirection += 1;
    _position.y += _mPaddleDirection * _mPaddleMovingSpeed * deltaTime;
}
