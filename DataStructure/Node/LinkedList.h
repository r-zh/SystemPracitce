#include "Node.h"

class LinkedList
{

public:
	LinkedList();
	LinkedList(LinkedList &);
	~LinkedList();
	void AppendNode(int); 
	bool RemoveValue(int); 
	void InsertAtPosition(int,int);  
	bool RemoveAtPosition(int);  
	int ReturnValueAtPosition(int); 
	void Search(int);
	void AppendList(LinkedList *); 
	LinkedList * ReturnDifferences(LinkedList *); 
	void RotateRight(); 
	void Print(); 
	Node * ReturnHead();
	Node * ReturnTail();
private:
	Node * head,* tail;
};