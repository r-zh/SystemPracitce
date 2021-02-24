//
//  triangle.cpp
//
//

#include <stdio.h>
#include "triangle.h"
Triangle::Triangle(Point P1, Point P2, Point P3)
{
    p1 = P1;
    p2 = P2;
    p3 = P3;
}

void Triangle::print() 
{
    std::cout<<"Point 1:"<<"("<<getP1().getX()<<","<<getP1().getY()<<")\n";
    std::cout<<"Point 2:"<<"("<<getP2().getX()<<","<<getP2().getY()<<")\n";
    std::cout<<"Point 3:"<<"("<<getP3().getX()<<","<<getP3().getY()<<")\n";
}
