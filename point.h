#ifndef POINT_H
#define POINT_H
#include "shape.h"
#include <iostream>
#include <string>

class Point : public Shape
{
private:
    float *xCord;
    float *yCord;

public:
    Point(float *x, float *y);
    std::string getType();
    float area();
    float circumference();
    ReturnCords position();
    bool isConvex();
    float distance(Shape *s);
};


#endif