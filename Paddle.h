#ifndef INC_26_PONG_CPP_PADDLE_H
#define INC_26_PONG_CPP_PADDLE_H

#include "PongObject.h"

class Paddle : public PongObject {
    public:
        Paddle(float movingSpeed, unsigned short int windowLimitX, unsigned short int windowLimitY):
            _mPaddleDirection(0),
            _mPaddleMovingSpeed(movingSpeed) {
                _length = 150;
                _position.x = 8;
                _position.y = 350;
                _windowLimitX = windowLimitX;
                _windowLimitY = windowLimitY;
        };
        virtual void draw() const override; // TODO: kill this?
        void changePaddlePosition(bool, bool, float);
        float getPaddleMovingSpeed() { return _mPaddleMovingSpeed; };
        short int getPaddleDirection() { return _mPaddleDirection; };
    private:
        short int _mPaddleDirection;
        float _mPaddleMovingSpeed;
};


#endif //INC_26_PONG_CPP_PADDLE_H
