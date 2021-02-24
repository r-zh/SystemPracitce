//
//  line.h
//
//

#ifndef line_h
#define line_h
#include "point.h"
#include "shape.h"
class Line: public Shape {
public:
    Line(){};
    Line(Point p1, Point p2);
    
    Point getP1()
    {
        return p1;
    }
    Point getP2()
    {
        return p2;
    }
    void setP1(Point p)
    {
        p1 = p;
    }
    void setP2(Point p)
    {
        p2 = p;
    }
    virtual void print() ;
    
private:
    Point p1;
    Point p2;
};

#endif /* line_h */
