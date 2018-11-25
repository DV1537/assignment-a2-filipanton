#include <iostream>
#include <fstream>
#include <cmath>
#include "shape.h"
#include "point.h"
#include "line.h"
#include "triangle.h"
#include "polygon.h"

void xArray(int &xArraySize, float input, int counterX, float *&arrX)
{
    if(counterX == xArraySize)
    {
        arrX[xArraySize -1] = input;
    }
    else
    {
        float *tempArray = new float[xArraySize+1]{0.0};
        for(int i = 0; i < xArraySize; i++)
        {
            tempArray[i] = arrX[i];
        }
        delete[] arrX;
        xArraySize++;
        arrX = new float[xArraySize];
        for(int x = 0; x < xArraySize; x++)
        {
            arrX[x] = tempArray[x];
        }
        arrX[xArraySize-1] = input;

    }
   
    
}

void yArray(int &yArraySize, float input, int counterY, float *&arrY)
{
    if(counterY == yArraySize)
    {
        arrY[yArraySize -1] = input;
    }
    else
    {
        float *tempArray = new float[yArraySize+1]{0.0};
        for(int i = 0; i < yArraySize; i++)
        {
            tempArray[i] = arrY[i];
        }
        delete[] arrY;
        yArraySize++;
        arrY = new float[yArraySize]{0.0};
        for(int x = 0; x < yArraySize; x++)
        {
            arrY[x] = tempArray[x];
        }
        arrY[yArraySize-1] = input;

    }
}

int main()
{
    float input = 0;
    int counter = 0;
    int counterX = 0;
    int counterY = 0;
    float *arrX = new float[1]{0.0};
    float *arrY = new float[1]{0.0};
    int xArraySize = 1;
    int yArraySize = 1;
    std::ifstream myReadFile;
    myReadFile.open("cords");
    while (myReadFile >> input)
    {
        input= round( input* 1000.0 ) / 1000.0;
        counter++;

        if(counter % 2 == 0)
        {
            counterY++;
            yArray(yArraySize, input, counterY, arrY);
        }
        else
        {
            counterX++;
            xArray(xArraySize, input, counterX, arrX);
        }

    }
    Polygon object(arrX, arrY, xArraySize);
    Shape *s = &object;
    std::cout << s->isConvex();
    getchar();
    return 0;
}