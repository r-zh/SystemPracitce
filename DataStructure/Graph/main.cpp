//
//  main.cpp
//
//
//  
//

#include <iostream>
#include <fstream>
#include <ostream>
#include <iomanip>
#include <string>
#include "line.h"
#include "point.h"
#include "circle.h"
#include "triangle.h"
#include <exception>

using namespace std;
 int size = 0;

void writeTo(ofstream& oFile, Shape* s)
{
	
	if (typeid(*s) == typeid(Point))
	{
		Point* p = dynamic_cast<Point*>(s);
		if (p)
		{
			oFile<<"Point"<<" "<<p->getX()<< " " << p->getY()<<"\n";
			::size++;
		}
		cout << typeid(Point).name() << endl;
	}
	else if (typeid(*s) == typeid(Line))
	{
		Line* l = dynamic_cast<Line*>(s);
		if (l)
		{
			oFile << "Line" << " " << l->getP1().getX() << " " << l->getP1().getY() << " " <<l->getP2().getX()<<" " << l->getP2().getY() << "\n";
			::size++;
		}
		cout << typeid(Line).name() << endl;
	}
	else if (typeid(*s) == typeid(Triangle))
	{
		Triangle* t= dynamic_cast<Triangle*>(s);
		if (t)
		{
			oFile << "Triangle" << " " << t->getP1().getX() << " " << t->getP1().getY() << " " << t->getP2().getX() << " " << t->getP2().getY() << " " << t->getP3().getX() << " " << t->getP3().getY() << "\n";
			::size++;
		}
		cout << typeid(Triangle).name() << endl;
	}
	else if (typeid(*s) == typeid(Circle))
	{
		Circle*c = dynamic_cast<Circle*>(s);
		if (c)
		{
			oFile << "Circle" <<" "<<c->getP().getX() << " " << c->getP().getY() << " " << c->getR()<<"\n";
			::size++;
		}
		cout << typeid(Circle).name() << endl;
	}
	else
	{
		cout << "Data structure is invalid.\n";
	}
}


int main() {
	//----------------------CREATING DATA-----------------------------
	string fName = "data.txt";
	string type;
	int index = 0;
	double f1, f2, f3, f4, f5, f6;
	Point p1(4.0, 3.2);
	Point p2(9.3, 4.7);
	Line line(p1, p2);
	Point p3(5.8, 7.3);
	Triangle triangle(p1, p2, p3);
	Point p(2.5, 8.4);
	Circle c(p, 2.9);
	ofstream outExample;
	ifstream inExample;
	//-------------------WRITING TO FILE--------------------------
	try {
		
		outExample.open(fName);
		if (!outExample)
			throw "Could not open file";
	}
	catch (exception& le)
	{
		cout << "Exception occured: " << le.what() << endl;
		system("pause");
		exit(1);
	}
	catch (...)
	{
		cout << "Exception occured"<< endl;
		system("pause");
		exit(2);
	}
	writeTo(outExample, &p1);
	writeTo(outExample, &p2);
	writeTo(outExample, &line);
	writeTo(outExample, &p3); 
	writeTo(outExample, &triangle);
	writeTo(outExample, &p);
	writeTo(outExample, &c);
	outExample.close();
	// ---------------------READING FROM FILE -----------------------------
	try {

		inExample.open(fName);
		if (!inExample)
			throw "Could not open file";
	}
	catch (exception& le)
	{
		cout << "Exception occured: " << le.what() << endl;
		system("pause");
		exit(3);
	}
	catch (...)
	{
		
		cout << "Exception occured" << endl;
		system("pause");
		exit(4);
	}
	
	Shape** shapeArray = new Shape*[::size];
	while (!inExample.eof() && index < ::size) {

		inExample >> type;
		if (type == "Point")
		{//takes in f1,f2
			inExample >> f1 >> f2; 
			shapeArray[index++] = new Point(f1, f2);
		}
		else if (type == "Line")
		{ //takes in f1,f2,f3,f4
			inExample >> f1 >> f2 >> f3 >> f4;
			shapeArray[index++] = new Line(Point(f1, f2), Point(f3, f4));
		}
		else if (type == "Triangle")
		{ //takes in f1,f2,f3,f4,f5,f6
			inExample >> f1 >> f2 >> f3 >> f4 >> f5 >> f6;
			shapeArray[index++] = new Triangle(Point(f1, f2), Point(f3, f4), Point(f5, f6));
		}
		else if (type == "Circle")
		{//takes in f1,f2,f3(radius)
			inExample >> f1 >> f2 >> f3;
			shapeArray[index++] = new Circle(Point(f1, f2), f3);
		}
		else { //anything else
			index = ::size;
			cout << "The file structure is incorrect\n";
		}
	}

	for (int yeet = 0; yeet < ::size; yeet++) {
		shapeArray[yeet]->print();
	}
	
	cout << endl;
	inExample.close();
	delete[] shapeArray;

	system("pause");


	return 0;

}
