//
// Created by Tamás Dinh on 2019-07-17.
//

#include <SDL2/SDL_rect.h>
#include "Ball.h"
#include "Game.h"

void Ball::draw() const {
    SDL_Rect ball {
        static_cast<int>(_position.x - _thickness / 2),
        static_cast<int>(_position.y - _thickness / 2),
        _thickness,
        _thickness
    };
}
