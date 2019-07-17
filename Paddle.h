#ifndef INC_26_PONG_CPP_PADDLE_H
#define INC_26_PONG_CPP_PADDLE_H

#include "PongObject.h"

class Paddle : public PongObject {
    public:
        Paddle(float movingSpeed): _mPaddleDirection(0), _mPaddleMovingSpeed(movingSpeed) {
            _length = 150;
            _position.x = 8;
            _position.y = 350;
        };
        virtual void draw() const override; // TODO: kill this?
        void changePaddlePosition(bool, bool, float);
        float getPaddleMovingSpeed() { return _mPaddleMovingSpeed; };
        short int getPaddleDirection() { return _mPaddleDirection; };
    private:
        short int _mPaddleDirection; // TODO: can we make this private?
        float _mPaddleMovingSpeed;
};


#endif //INC_26_PONG_CPP_PADDLE_H
