//
//  line.cpp
// 
//

#include <stdio.h>
#include "line.h"

Line::Line(Point P1, Point P2)
{
    p1 = P1;
    p2 = P2;
}
void Line::print() 
{
    std::cout<<"Point 1:"<<"("<<getP1().getX()<<","<<getP1().getY()<<")\n";
    std::cout<<"Point 2:"<<"("<<getP2().getX()<<","<<getP2().getY()<<")\n";
}
