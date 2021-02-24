#include "Element.h"

Element::Element(int exp , double coeff)
{
	this->exponent = exp;
	this->coefficient = coeff;
}

Element::~Element(void)
{
}

/*set the coff and exp for each elment */
void Element::setparamteres ( int expo , double coeff)
{
	this->exponent = expo;
	this->coefficient = coeff ;
}


	/*update the coff */
void Element::setCoeff( double coeff )
{
	this->coefficient = coeff;
}
	/*get the exp*/
int Element::getExp()
{
	return this->exponent;
}
	/*get the coff */
double Element::getCoeff()
{
	return this->coefficient;
}