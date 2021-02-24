#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList L1,L2;
	L1.AppendNode(9);
	L1.AppendNode(8);
	L1.AppendNode(7);
	L1.AppendNode(6);
	L1.AppendNode(5);
	L1.AppendNode(4);
	L2.AppendNode(8);
	L2.AppendNode(6);
	cout << "Create null lists, append nodes: (L1, L2)\n";
	L1.Print();
	L2.Print();

	L1.InsertAtPosition(7,1);
	cout << "\nInsert value 1 at the end of the list of L1:\n";
	L1.Print();

	L1.RemoveValue(7);
	cout << "\nRemove an element from L1:\n";
	L1.Print();
	
	L1.InsertAtPosition(4,2);
	cout << "\nInsert value 2 at position 4 of L1:\n";
	L1.Print();

	L2.RemoveAtPosition(2);
	cout << "\nRemove 2nd element from L2:\n";
	L2.Print();


	L1.RemoveAtPosition(3);
	cout << "\nRemove the node at position 3 in L1:\n";
	L1.Print();

	cout << "\nReturn the value at position 5 of L1: \n" << L1.ReturnValueAtPosition(5) << endl;

	cout << "\nSearch a Value in L1";
	L1.Search(9);

	L1.AppendList(&L2);
	cout << "\nAppend L2 to L1:\n";
	L1.Print();

	LinkedList * L3 = L1.ReturnDifferences(&L2);
	cout << "\nValues of L1 not present in L2: (L3)\n";
	L3->Print();
	
	L1.RotateRight();
	cout << "\nRotate right of L1:\n";
	L1.Print();

	delete L3;

	return 0;
}

