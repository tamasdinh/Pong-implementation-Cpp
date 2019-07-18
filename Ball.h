#ifndef INC_26_PONG_CPP_BALL_H
#define INC_26_PONG_CPP_BALL_H

#include "PongObject.h"

class Ball : public PongObject {
    public:
        Ball(unsigned short int &windowLimitX,
                unsigned short int &windowLimitY,
                unsigned short int &wallThickness,
                float movingSpeedX, float movingSpeedY) :
                PongObject(windowLimitX, windowLimitY, wallThickness),
                _velocityX(movingSpeedX),
                _velocityY(movingSpeedY),
                _startVelocityX(movingSpeedX),
                _startVelocityY(movingSpeedY),
                _hasBounced(false),
                _acceleration(0.02) {};

        void updatePosition(float &deltaTime, unsigned short int &wallThickness, float &paddlePositionY, unsigned short int &paddleLength);
        bool* hasBounced();
        bool ballOut();
        void resetVelocity();

    private:
        float _startVelocityX;
        float _startVelocityY;
        float _velocityX;
        float _velocityY;
        float _acceleration;
        bool _hasBounced;
    };


#endif //INC_26_PONG_CPP_BALL_H
