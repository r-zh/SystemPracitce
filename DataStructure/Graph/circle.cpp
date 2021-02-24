//
//  circle.cpp
//
//

#include <stdio.h>
#include "circle.h"

Circle::Circle(Point P, double R)
{
    p = P;
    r = R;
}

void Circle::print() 
{
    std::cout<<"Center:"<<"("<<p.getX()<<","<<p.getY()<<")\n";
    std::cout<<"Radius:"<<r<<"\n";
}
