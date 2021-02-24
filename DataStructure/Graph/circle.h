//
//  circle.h
//

#ifndef circle_h
#define circle_h
#include "shape.h"
#include "point.h"
class Circle: public Shape
{
public:
	Circle() {}
    Circle(Point , double );
    
    Point getP()
    {
        return p;
    }
    double getR()
    {
        return r;
    }
    void setP(Point P)
    {
        p = P;
    }
    void setR(double R)
    {
        r = R;
    }
   virtual void print() ;
private:
    Point p;
    double r;
};

#endif /* circle_h */
