#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include <iostream>
#include <string>

class Polygon : public Shape
{
private:
    float *xCord;
    float *yCord;
    int arraySize;

public:
    Polygon(float *x, float *y,int arraySize);
    std::string getType();
    float area();
    float circumference();
    ReturnCords position();
    bool isConvex();
    float distance(Shape *s);
    
};


#endif