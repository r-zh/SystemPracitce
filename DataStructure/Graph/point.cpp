//
//  point.cpp
//



#include <stdio.h>
#include "point.h"

Point::Point(double a, double b):x(a),y(b)
{}
void Point::print()
{
    std::cout<<"("<<x<<","<<y<<")\n";
    
}
