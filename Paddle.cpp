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

    // Implementing movement up and down for corresponding key presses
    _mPaddleDirection = 0;
    if (sdlKeyboardStateUp)
        _mPaddleDirection -= 1;
    if (sdlKeyBoardStateDown)
        _mPaddleDirection += 1;

    // Implementing paddle movement and clipping position if paddle reaches window border
    if (static_cast<int>(_position.y + _length / 2) > _windowLimitY) {
        _position.y = _windowLimitY - _length / 2;
    }
    else if (static_cast<int>(_position.y - _length / 2) < 0) {
        _position.y = 0 + _length / 2;
    }
    else
        _position.y += _mPaddleDirection * _mPaddleMovingSpeed * deltaTime;

}
