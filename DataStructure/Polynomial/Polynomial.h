#pragma once
#ifndef POLYNOMIAL
#define POLYNOMIAL

#include "Element.h"
#include <iostream>
#include <iomanip>
using namespace std;

class Polynomial
{
	private:
	int size; 
	Element * ptr_array; 



	friend istream &operator >>( istream &,Polynomial *);
	friend ostream &operator <<( ostream &,Polynomial *);

public:

	Polynomial (int=0); 
	Polynomial ( Polynomial *);
	Polynomial ( Polynomial &);
	~Polynomial();
	
	void setArrayElementI( int, double, int);
	
	int getSize();
	
	int getExposant();
	
	double getCoefficient();
	
	Polynomial & operator + ( const Polynomial& );
	
	Polynomial & operator - ( const Polynomial& );
	
	Polynomial & operator = ( const Polynomial& );


};

#endif