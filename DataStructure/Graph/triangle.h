//
//  triangle.h
//
//

#ifndef triangle_h
#define triangle_h
#include "shape.h"
#include "point.h"

class Triangle: public Shape{
public:
    Triangle(){}
    
    Triangle(Point p1, Point p2, Point p3);
    
    Point getP1()
    {
        return p1;
    }
    Point getP2()
    {
        return p2;
    }
    Point getP3()
    {
        return p3;
    }
    void setP1(Point p)
    {
        p1 = p;
    }
    void setP2(Point p)
    {
        p2 = p;
    }
    void setP3(Point p)
    {
        p3 = p;
    }
    virtual void print() ;

private:
    Point p1;
    Point p2;
    Point p3;
};

#endif /* triangle_h */
