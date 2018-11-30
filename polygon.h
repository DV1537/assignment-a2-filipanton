#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include <iostream>
#include <string>
#include <math.h>


class Polygon : public Shape
{
private:
    float *xCord;
    float *yCord;
    int arraySize;

public:
    Polygon(float *x, float *y,int arraySize);
    bool lineIntersect(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
    bool intersect();
    std::string getType();
    float area();
    float circumference();
    ReturnCords position();
    bool isConvex();
    float distance(Shape *s);
    
};


#endif