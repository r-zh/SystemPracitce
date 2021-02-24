#include "Polynomial.h"


Polynomial::Polynomial(int size_tmp)
{
	size = size_tmp ;
	this->ptr_array = new Element[size_tmp];
	
}

Polynomial::Polynomial ( Polynomial *pt)
{

	size = pt->getSize();
	this->ptr_array = pt->ptr_array ;
}

Polynomial ::Polynomial ( Polynomial & pt)
{
	size = pt.getSize();
	this->ptr_array = pt.ptr_array ;

}

Polynomial::~Polynomial(void)
{
	delete []ptr_array;
}

void Polynomial ::setArrayElementI( int expo, double coeff , int caseI)
{
	ptr_array[caseI].setparamteres( expo, coeff);
}

int Polynomial ::getSize()
{
	return size;

}

	
istream &operator>>( istream & input, Polynomial *formula)
{
	
	/*
		initially we want to get the input
		define a variable to get it
		get the input and put it in the defined variable
	*/
	char pt[1000] ;
	input.getline(pt,999);


	/*
		check the validity of the sentence:
		check that the enterd data is number or comma
		count the number of comma and put it in the defined variable 
	*/

	int no_comma =0;
	
	for( int i=0 ; i < cin.gcount() -1 ; i++)
	{
		if (pt[i] == ',') 
			no_comma++;
	    else if (   (pt[i] != '0') && (pt[i] != '1') && (pt[i] != '2') && (pt[i] != '3') && (pt[i] != '4') && (pt[i] != '5') && 
					(pt[i] != '6') && (pt[i] != '7') && (pt[i] != '8')  && (pt[i] != '9') && (pt [i] != ',') && (pt[i] != '.') && (pt[i] != '-') ) 
					
		{
							
						input.putback('N');
						return input;
					
		}
	
	}

		/*
		check the number of comma , it mus be odd and no_coma = 2*sizeofformula -1 
		*/
	if ( no_comma != ((formula->size*2) -1) )
	{
		input.putback('S');
		return input;
	}

	/*just to divided it */
	int counter = cin.gcount() -2;
	input.putback('\n');
	for (int i = counter ; i > -1 ; i--)
		input.putback(pt[i]);

	/*
		check the validity of data 
		here we want to get each element one by one 
		and checking it 
		if the coffeicient =0 or exponent less than zero 
		then return error 

	*/

	int exponent;
	double coefficient;
	char exp[6];
	char coeff[6];
	int *tabExposant = new int [formula->size];

	for (int i= 0 ; i <= formula->size -1 ; i++)
	{
		if (i != formula->size -1)

		{		
			input.get( coeff , 15 , ',');
			input.ignore();
			input.get( exp , 15 , ',');
			input.ignore();
			exponent = atoi(exp);
			coefficient = strtod(coeff,NULL);
			formula->ptr_array[i].setparamteres(exponent,coefficient);
			if (coefficient ==0 || exponent < 0) 
			{
			input.putback('I');
			return input ; 
			}
			tabExposant[i] = exponent;
		}

		else  
		{
			input.get( coeff , 15 , ',');
			input.ignore();
			input.getline( exp , 15 );
			exponent = atoi(exp);
			coefficient = strtod(coeff,NULL);
			formula->ptr_array[formula->size -1].setparamteres(exponent,coefficient);
			
		if (coefficient ==0 || exponent < 0) 
			{
			input.putback('I');
			return input ; 
			}
			tabExposant[formula->size -1] = exponent;
		}
	}

	/*
		here we want to order the formula 
		if there are two elements with same exponent , then error return 
	*/
	Element temp;
	for (int i = 0 ; i < formula->size ; i++)
	{
		for (int j = i+1 ; j <formula->size ; j++)
		{
			if ( formula->ptr_array[i].getExp() == formula->ptr_array[j].getExp() && i!=j) 
					
				{	
					input.putback('O');
			        return input;
				}

			else if ( formula->ptr_array[i].getExp() < formula->ptr_array[j].getExp() ) 
			{
				temp =  formula->ptr_array[i] ;
				formula->ptr_array[i] = formula->ptr_array[j];
				formula->ptr_array[j] = temp;
			}
		}
	}
			
	/*return the input */
	input.putback('A');
	return input;
}
	



ostream & operator<<(ostream & output, Polynomial* formula)
{
	
	/*
	in case that the result after addition or substraction equals zero 
	*/

	if( formula->getSize() == 0) 
	{
		output << "the result is zero " << endl;

	}
	else
	{
		
		for( int i=0 ; i<formula->size ; i++)
		{
			if (i ==0)
			{
				output << formula->ptr_array[0].getCoeff() <<"*x**" << formula->ptr_array[0].getExp();
			}
			else 
			{
				if( formula->ptr_array[i].getCoeff() > 0 ) 
					output << "+" << formula->ptr_array[i].getCoeff() ;
				else 
					output << formula->ptr_array[i].getCoeff();

				if (formula->ptr_array[i].getExp() > 0 )
					output <<"*x**" << formula->ptr_array[i].getExp();
			
			}
		}
	}
	return output;
}

Polynomial&  Polynomial ::operator=( const Polynomial &p1 )
{
	this->size = p1.size;
	this->ptr_array = p1.ptr_array;
	return *this;
}

Polynomial & Polynomial :: operator- ( const Polynomial& p2 )
{
	/*
		define one for combine two formulas and one for the result
		initilize each one by null 
		filling the first one with formula1 and formula2 
	*/
	Element **two_formula = new Element* [ this->size + p2.size ] ;
	Element **result = new Element* [ this->size + p2.size ] ;
	Element * tmp = NULL;
	for ( int i =0 ; i < this->size + p2.size  ; i++)
	{
		two_formula[i] = NULL;
		result[i] = NULL;
	}

	for( int i=0 ; i<this->size ; i++)
		two_formula [i] = & this->ptr_array[i];

	for( int i=0 ; i<p2.size ; i++)
	{
		two_formula [i + this->size] = new Element( p2.ptr_array[i] );
		two_formula [i + this->size]->setCoeff( -p2.ptr_array[i].getCoeff() ); 
	}

	/*****************************************finish block1************************************************************************************/

	
	
	/*
		adding the two formula ,  
		check wether there are two elements with same exponent , and sum thier coeffs, in case the result_coesff =0 it will be neglected 
		otherwise it will be added in the result array 
	*/

	int counter = 0 ;
	int esistance = 0 ; 

	for( int i = 0 ; i < this->size + p2.size ; i++)
	{
		
			esistance = 0;

		if (two_formula[i]!=NULL)
		{
			
			
		for( int j = i+1 ; j < this->size + p2.size ; j++)
		{   
			

			if (two_formula[j]!=NULL && two_formula[i]!=NULL)
			{
				

			if ( two_formula[i]->getExp() == two_formula[j]->getExp() )
			{
				
				esistance = 1 ; 

				int sum = two_formula[i]->getCoeff()+ two_formula[j]->getCoeff() ;
				if ((sum) != 0 )
				{
						

					for( int k = 0 ; k < this->size + p2.size ; k++)
					{	
						
						if( result[k] == NULL)
						{
							result[k] = new Element( two_formula[i]->getExp(), 
															 (two_formula[i]->getCoeff()+
															 two_formula[j]->getCoeff()) );
							counter ++;
							
							break;
						}
					}
				

				}

			two_formula[i]=two_formula[j]=NULL;			
			}
			}
			

		}
		if (esistance == 0) 
		{
			
				esistance = 1 ; 
			for( int k = 0 ; k < this->size + p2.size ; k++)
					{
						if( result[k] == NULL)
						{
							
	
							result[k] = new Element( two_formula[i]->getExp()  ,  two_formula[i]->getCoeff() );
							
							counter ++;
							break;
						}
					}
	
		}; 
		}
		
	}

	/*****************************************finish adding ************************************************************************************/

	/* 
		order the formula
	*/

	
	for (int i = 0 ; i < this->size + p2.size ; i++)
		if(result[i]==NULL)
			result[i] = new Element;


	for( int i = 0 ; i <this->size + p2.size ; i++)
	{
		for( int j = i+1 ; j <this->size + p2.size; j++)
		{
			if ( result[i]->getExp() < result[j]->getExp() )
			{
				tmp =  result[i] ;
				result[i] = result[j];
				result[j] = tmp;
			}
		}
	}
	
	/*****************************************finish ordering of the array ************************************************************************************/

	Polynomial* final_result = new Polynomial (counter);
	for (int i = 0 ; i < counter ; i++)
		final_result->ptr_array[i].setparamteres( result[i]->getExp() ,result[i]->getCoeff() );

	return *final_result;

	/*****************************************return the formula ************************************************************************************/


}

Polynomial& Polynomial::operator+ (const Polynomial& p2)
{
	
	/*
		define one for combine two formulas and one for the result
		initilize each one by null 
		filling the first one with formula1 and formula2 
	*/
	Element **two_formula = new Element* [ this->size + p2.size ] ;
	Element **result = new Element* [ this->size + p2.size ] ;
	Element * tmp = NULL;
	for ( int i =0 ; i < this->size + p2.size  ; i++)
	{
		two_formula[i] = NULL;
		result[i] = NULL;
	}

	for( int i=0 ; i<this->size ; i++)
		two_formula [i] = & this->ptr_array[i];

	for( int i=0 ; i<p2.size ; i++)
		two_formula [i + this->size] = & p2.ptr_array[i];

	/*****************************************finish block1************************************************************************************/

	
	
	/*
		adding the two formula ,  
		check wether there are two elements with same exponent , and sum thier coeffs, in case the result_coesff =0 it will be neglected 
		otherwise it will be added in the result array 
	*/

	int counter = 0 ;
	int esistance = 0 ; 

	for( int i = 0 ; i < this->size + p2.size ; i++)
	{
		
			esistance = 0;

		if (two_formula[i]!=NULL)
		{
			
			
		for( int j = i+1 ; j < this->size + p2.size ; j++)
		{   
			

			if (two_formula[j]!=NULL && two_formula[i]!=NULL)
			{
				

			if ( two_formula[i]->getExp() == two_formula[j]->getExp() )
			{
				
				esistance = 1 ; 

				int sum = two_formula[i]->getCoeff()+ two_formula[j]->getCoeff() ;
				if ((sum) != 0 )
				{
						

					for( int k = 0 ; k < this->size + p2.size ; k++)
					{	
						
						if( result[k] == NULL)
						{
							result[k] = new Element( two_formula[i]->getExp(), 
															 (two_formula[i]->getCoeff()+
															 two_formula[j]->getCoeff()) );
							counter ++;
							
							break;
						}
					}
				

				}

			two_formula[i]=two_formula[j]=NULL;			
			}
			}
			

		}
		if (esistance == 0) 
		{
			
				esistance = 1 ; 
			for( int k = 0 ; k < this->size + p2.size ; k++)
					{
						if( result[k] == NULL)
						{
							
	
							result[k] = new Element( two_formula[i]->getExp()  ,  two_formula[i]->getCoeff() );
							
							counter ++;
							break;
						}
					}
	
		}; 
		}
		
	}

	/*****************************************finish adding ************************************************************************************/

	/* 
		order the formula
	*/

	
	for (int i = 0 ; i < this->size + p2.size ; i++)
		if(result[i]==NULL)
			result[i] = new Element;


	for( int i = 0 ; i <this->size + p2.size ; i++)
	{
		for( int j = i+1 ; j <this->size + p2.size; j++)
		{
			if ( result[i]->getExp() < result[j]->getExp() )
			{
				tmp =  result[i] ;
				result[i] = result[j];
				result[j] = tmp;
			}
		}
	}
	
	/*****************************************finish ordering of the array ************************************************************************************/

	Polynomial* final_result = new Polynomial (counter);
	for (int i = 0 ; i < counter ; i++)
		final_result->ptr_array[i].setparamteres( result[i]->getExp() ,result[i]->getCoeff() );

	return *final_result;

	/*****************************************return the formula ************************************************************************************/



}