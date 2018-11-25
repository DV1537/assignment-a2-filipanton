#ifndef LINE_H
#define LINE_H
#include "shape.h"
#include <iostream>
#include <string>

class Line : public Shape
{
private:
    float *xCord;
    float *yCord;

public:
    Line(float *x, float *y);
    std::string getType();
    float area();
    float circumference();
    ReturnCords position();
    bool isConvex();
    float distance(Shape *s);
};


#endif