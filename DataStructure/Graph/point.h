//
//  point.h
//
//

#ifndef point_h
#define point_h
#include "shape.h"
class Point: public Shape{

public:
    
    Point(double=0,double=0);
    
    double getX()
    {
        return x;
    }
    
    double getY()
    {
        return y;
    }
    
    void setX(double a)
    {
        x = a;
    }
    
    void setY(double a)
    {
        y = a;
    }
    virtual void print();

    
private:
    double x;
    double y;
};


#endif /* point_h */
