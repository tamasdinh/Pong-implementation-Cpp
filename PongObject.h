#ifndef INC_26_PONG_CPP_PONGOBJECT_H
#define INC_26_PONG_CPP_PONGOBJECT_H

#include <array>
#include <SDL2/SDL.h>

struct XYPosition {
    float x;
    float y;
};

enum Color {
    black,
    white,
    red,
    green,
};

class PongObject {
    public:
        PongObject(): _thickness(15), _length(15), _position(), _color(white) {
            _position.x = 0;
            _position.y = 0;
        };
        ~PongObject() {};
        XYPosition getPosition() const { return _position; };
        unsigned short int getLength() const { return _length; };
        void setPosition(float x, float y);
        unsigned short int getThickness() const { return _thickness; };
        virtual void draw() const = 0;

    protected:
        XYPosition _position;
        unsigned short int _length;
        unsigned short int _thickness;
        Color _color;
};

#endif //INC_26_PONG_CPP_PONGOBJECT_H
