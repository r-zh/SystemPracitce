#pragma once
#ifndef ELEMENT_H
#define ELEMENT_H


class Element
{

	
private:
	int exponent;
	double coefficient;

public:
	Element(int=-1, double=1.0);
	~Element();

	/*set the coff and exp for each elment */
	void setparamteres ( int , double );

	/*update the coff */
	void setCoeff( double );

	/*get the exp*/
	int getExp();

	/*get the coff */
	double getCoeff();

};

#endif