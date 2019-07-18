#include "Paddle.h"

void Paddle::changePaddlePosition(bool sdlKeyboardStateUp, bool sdlKeyBoardStateDown, float deltaTime) {

    // Implementing movement up and down for corresponding key presses
    _mPaddleDirection = 0;
    if (sdlKeyboardStateUp)
        _mPaddleDirection -= 1;
    if (sdlKeyBoardStateDown)
        _mPaddleDirection += 1;

    // Implementing paddle movement and clipping position if paddle reaches window border
    if (static_cast<int>(_position.y) + _length / 2 > _windowLimitY) {
        _position.y = static_cast<float>(_windowLimitY) - static_cast<float>(_length) / 2;
    }
    else if (static_cast<int>(_position.y) - _length / 2 < 0) {
        _position.y = 0 + static_cast<float>(_length) / 2;
    }
    else
        _position.y += static_cast<float>(_mPaddleDirection) * _mPaddleMovingSpeed * deltaTime;
}

short int* Paddle::getPaddleDirection() { return &_mPaddleDirection; }

float* Paddle::getPaddleMovingSpeed() { return &_mPaddleMovingSpeed; }
