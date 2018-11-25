#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"
#include <iostream>
#include <string>

class Triangle : public Shape
{
private:
    float *xCord;
    float *yCord;

public:
    Triangle(float *x, float *y);
    std::string getType();
    float area();
    float circumference();
    ReturnCords position();
    bool isConvex();
    float distance(Shape *s);
};


#endif