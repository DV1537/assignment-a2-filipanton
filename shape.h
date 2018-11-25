#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>

struct ReturnCords
{
    float x;
    float y;
    ReturnCords(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
};

class Shape
{
private:

public:
    virtual std::string getType() = 0;
    virtual float area() = 0;
    virtual float circumference() = 0;
    virtual ReturnCords position() = 0;
    virtual bool isConvex() = 0;
    virtual float distance(Shape *s) = 0;
};


#endif