#ifndef INC_26_PONG_CPP_PONGOBJECT_H
#define INC_26_PONG_CPP_PONGOBJECT_H

#include <vector>
#include <random>
#include <SDL2/SDL.h>

struct XYPosition {
    float x;
    float y;
};

class PongObject {
    public:
        PongObject(unsigned short int &windowLimitX, unsigned short int &windowLimitY, unsigned short int &wallThickness):
            _thickness(wallThickness),
            _length(wallThickness),
            _position({static_cast<float>(windowLimitX) / 2, static_cast<float>(windowLimitY) / 2}),
            _windowLimitX(windowLimitX),
            _windowLimitY(windowLimitY),
            _color({255, 255, 255}) {
                _drawingObject.x = _position.x - static_cast<float>(_thickness) / 2;
                _drawingObject.y = _position.y - static_cast<float>(_length) / 2;
                _drawingObject.w = _thickness;
                _drawingObject.h = _length;
            };
        ~PongObject() {};

        void updateDrawingObject();
        void switchColor();

        XYPosition* getPosition();
        SDL_Rect* getDrawingObject();
        std::vector<unsigned short int> getColor();

        unsigned short int* getLength();
        unsigned short int* getThickness();
        void setPosition(float x, float y);
        void setWindowLimits(unsigned short int, unsigned short int);

    protected:
        unsigned short int _windowLimitX;
        unsigned short int _windowLimitY;
        XYPosition _position;
        unsigned short int _length;
        unsigned short int _thickness;
        std::vector<unsigned short int> _color;
        SDL_Rect _drawingObject;
};

#endif //INC_26_PONG_CPP_PONGOBJECT_H
