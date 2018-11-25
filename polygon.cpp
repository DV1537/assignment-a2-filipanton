#include <iostream>
#include <string>
#include <cmath>
#include "polygon.h"

Polygon::Polygon(float *x, float *y, int arraySize)
{
    xCord = x;
    yCord = y;
    this->arraySize = arraySize;
    
}

std::string Polygon::getType()
{
    return "polygon";
}

float Polygon::area()
{
  
    int area = 0;
    int j = arraySize -1;

    for(int i = 0; i < arraySize; i++)
    {
        area +=(xCord[j]+ xCord[i]) * (yCord[j]- yCord[i]);
        j = i;
    }
    return area/2.0;
}

float Polygon::circumference()
{
    float circumference = 0;
    int j = arraySize -1;
    float deltaX = 0;
    float deltaY = 0;
    float length = 0;

    for(int i = 0; i < arraySize; i ++)
    {

    
        deltaX = xCord[i] - xCord[j];
        deltaY = yCord[i] - yCord[j];
        length = sqrt(pow(deltaX, 2.0) + pow(deltaY, 2.0));
        circumference += length;
        j=i;

    }

    

    return circumference;
}

ReturnCords Polygon::position()
{
    float averageX = 0;
    float averageY = 0;
    for(int i = 0; i < arraySize; i++)
    {
        averageX += xCord[i]; 
        averageY += yCord[i];
    }
    averageX = averageX/arraySize;
    averageY = averageY/arraySize;
    ReturnCords mPosition(averageX, averageY);
    return mPosition;
}

bool Polygon::isConvex()
{
   
    bool checkIfPositive = false;
    bool checkIfNegative = false;
    
    bool isConvex = true;
    float dx1 = 0.0;
    float dy1 = 0.0;
    float dx2 = 0.0;
    float dy2 = 0.0;
    float zcrossproduct = 0.0;
    for(int x = 0; x < arraySize-2; x++)
    {
        dx1 = xCord[x+1]-xCord[x];
        dy1 = yCord[x+1]-yCord[x];
        dx2 = xCord[x+2]-xCord[x+1];
        dy2 = yCord[x+2]-yCord[x+1];
        zcrossproduct = dx1*dy2 - dy1*dx2;
        if(zcrossproduct < 0 &&  x == 0)
        {
            checkIfNegative = true;
        }
        if(zcrossproduct >= 0 &&  x == 0)
        {
            checkIfPositive = true;
        }
        if(checkIfPositive == true)
        {
            if(zcrossproduct <= 0)
            {
                isConvex = false;
                x = arraySize;
            }
        }
        if(checkIfNegative == true)
        {
            if(zcrossproduct >= 0)
            {
                isConvex = false;
                x = arraySize;
            }
        }
    }
        dx1 = xCord[arraySize-1]-xCord[0];
        dy1 = yCord[arraySize-1]-yCord[0];
        dx2 = xCord[arraySize-2]-xCord[arraySize-1];
        dy2 = yCord[arraySize-2]-yCord[arraySize-1];
        zcrossproduct = dx1*dy2 - dy1*dx2;
        if(checkIfPositive == true)
        {
            if(zcrossproduct <= 0)
            {
                isConvex = false;
                
            }
        }
        if(checkIfNegative == true)
        {
            if(zcrossproduct >= 0)
            {
                isConvex = false;
                
            }
        }
        dx1 = xCord[0]-xCord[1];
        dy1 = yCord[0]-yCord[1];
        dx2 = xCord[arraySize-1]-xCord[0];
        dy2 = yCord[arraySize-1]-yCord[0];
        zcrossproduct = dx1*dy2 - dy1*dx2;
        if(checkIfPositive == true)
        {
            if(zcrossproduct <= 0)
            {
                isConvex = false;
                
            }
        }
        if(checkIfNegative == true)
        {
            if(zcrossproduct >= 0)
            {
                isConvex = false;
                
            }
        }
        
    return isConvex;
}

float Polygon::distance(Shape *s)
{
    
    float deltaX = position().x - s->position().x;
    float deltaY = position().y - s->position().y;
    float distance = sqrt(pow(deltaX, 2.0) + pow(deltaY, 2.0));
    return distance;
}


