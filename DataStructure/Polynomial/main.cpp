#include <iostream>
#include"Polynomial.h"

void check_cin()
{
	
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
}


bool definePolynom(Polynomial* & equation)
{
	int size=0;
	char testResult;

	
	while(size < 1)
	{
		cout<<" Please enter the Size of the formula  : " << endl;
		cout<<" ->";
		cin>>size;
		check_cin();
	}
	
	equation = new Polynomial(size);
	
	cout << "\n enter the formula using comma like coff,exp,coff,exp ........" << endl;
	cout <<"->";
	
	cin >> equation;
	cin >> testResult;
	if( testResult == 'S') 
		cout << " Wrong in the Formula , it doesn't meet the size of formula " << endl;
	else if ( testResult == 'N') 
		cout << " Wrong in the Formula  , the coff or expo is not number " << endl;
	else if (testResult == 'I')
		cout << " Wrong in the Formula  , invalid VALUE exponent or coefficient" << endl;
	else if(testResult == 'O')
		cout << " Wrong in the Formula , same exponent " << endl;

	if (testResult == 'S'||testResult == 'I'|| testResult == 'N'||testResult == 'O') 
	{
		delete equation;
		equation = NULL;
		return false;
	}
	return true;
}


int main()
{
	int choice=-1;
		
	Polynomial *formula = NULL;
	bool end = false ;
	
	while (!end)
	{
		system("cls");
		cout<<"--------------OPERATION ON POLYNOMEL Formula --------------" << endl;
		cout<<" 1) Creat a Polynomel Formula " << endl;
		cout<<" 2) Print the Polynomel Formula "<<endl;
		cout<<" 3) ADD to another polynomel formula " << endl;
		cout<<" 4) Subtract from another polunomel formula "<<endl;
		cout<<" 5) EXIT"<<endl;
		cout<<" Your choice? -> ";

		cin >> choice;
		check_cin();
		switch(choice)
		{
		case 1:
			if(definePolynom(formula))
				cout<<" the Formula is created Successfully"<<endl;
			else
				cout<<" Wrong in writing the formula "<<endl;
			break;

		case 2:
			if(!formula)
				cout<<" Please Enter the formula initially "<<endl;
			else
			cout << formula << endl;
			break;

		case 3:
			if(!formula)
				cout<<" Please Enter the formula initially"<<endl;
			else
			{
				cout << "First Polynom : \n" << endl;
				Polynomial* formula2=NULL;
				cout << formula << endl;
				cout << "\n Define the second Formula \n" << endl;
				bool result = definePolynom(formula2);
				if( result == true)
				{
					Polynomial formula3 = *formula + *formula2;
					cout << (&formula3) << endl;
				}
			}
			break;

		case 4:
			if(!formula)
				cout<<" Please Enter the formula initially"<<endl;
			else
			{	cout << "First Polynom : \n" << endl;
				cout << formula << endl;
				Polynomial* formula2 =NULL;
				cout << "\n Define the second polynom \n" << endl;
				bool result = definePolynom(formula2);

			if( result == true)
				{
					Polynomial formula3= *formula - *formula2;
					cout << &formula3 << endl;
				}
			}
			break;

		case 5:
			cout<<" Finishing !"<<endl;
			end=true;
			break;
		}
		system("pause");		
	}
	return 0;
}

