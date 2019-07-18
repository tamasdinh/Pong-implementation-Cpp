#ifndef INC_26_PONG_CPP_PADDLE_H
#define INC_26_PONG_CPP_PADDLE_H

#include "PongObject.h"

class Paddle : public PongObject {
    public:
        Paddle(unsigned short int &windowLimitX, unsigned short int &windowLimitY, unsigned short int &wallThickness, float movingSpeed, unsigned short int length):
                PongObject(windowLimitX, windowLimitY, wallThickness), _mPaddleMovingSpeed(movingSpeed), _mPaddleDirection(0) {
            _length = length;
            _position.x = static_cast<float>(_thickness) / 2;
            _position.y = static_cast<float>(_windowLimitY) / 2;
        };

        void changePaddlePosition(bool, bool, float);

        short int* getPaddleDirection();
        float* getPaddleMovingSpeed();;

    private:
        short int _mPaddleDirection;
        float _mPaddleMovingSpeed;
};


#endif //INC_26_PONG_CPP_PADDLE_H
