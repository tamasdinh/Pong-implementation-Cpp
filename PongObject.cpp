//
// Created by Tamás Dinh on 2019-07-17.
//

#include "PongObject.h"

void PongObject::setPosition(float x, float y) {
    _position.x = x;
    _position.y = y;
};

void PongObject::setWindowLimits(unsigned short int windowLimitX, unsigned short int windowLimitY) {
    _windowLimitX = windowLimitX;
    _windowLimitY = windowLimitY;
}