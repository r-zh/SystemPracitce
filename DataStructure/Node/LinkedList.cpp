#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
	head = 0;
	tail = 0;
}

LinkedList::LinkedList(LinkedList & copy)
{
	if (!copy.ReturnHead())  
	{
		head = 0;
		tail = 0;
		return;
	}
	Node * newPtr = new Node(*copy.ReturnHead());
	Node * copyPtr = copy.ReturnHead();
	Node * prevPtr;
	head = newPtr;
	while (copyPtr != copy.ReturnTail())
	{
		prevPtr = newPtr;
		copyPtr = copyPtr->ReturnNext();  
		newPtr = new Node(*copyPtr);
		prevPtr->SetNext(newPtr);
	}
	tail = newPtr;
}

LinkedList::~LinkedList()
{
	if(!head)  
		return;  
	if(head == tail)
	{
		delete head;
		return;
	}
	Node * delPtr = head;
	Node * nextPtr = delPtr->ReturnNext();
	if(nextPtr->ReturnNext())  
		while(nextPtr->ReturnNext() != tail)  
		{
			delete delPtr;
			delPtr = nextPtr;
			nextPtr = nextPtr->ReturnNext();
		}
	delete delPtr;
	delete nextPtr;
}

void LinkedList::AppendNode(int e)
{
	Node * newNode = new Node;  
	newNode->SetElement(e);  
	if(tail)  
	{
		tail->SetNext(newNode);  
	}
	else  
	{
		head = newNode;
	}
	tail = newNode;  
}

bool LinkedList::RemoveValue(int e)
{
	if(!head)  
		return false;  
	Node * searchNode = head;
	Node * lastNode;
	bool FoundFlag = false;
	if(!searchNode->ReturnNext())  
	{
		if(searchNode->ReturnElement() == e)
		{
			delete searchNode;
			head = 0;
			tail = 0;
			return true;
		}
		else
			return false;
	}
	while(searchNode->ReturnNext())  
	{
		if(searchNode->ReturnElement() == e)
		{
			FoundFlag = true;
			break;
		}
		lastNode = searchNode;
		searchNode = searchNode->ReturnNext();
	}
	if(FoundFlag)  
	{		 
		if(searchNode == tail)  
		{
			tail = lastNode;
			lastNode->SetElement(0);
		}
		else if(searchNode == head)  
		{
			head = searchNode->ReturnNext();
		}
		else  
		{
			lastNode->SetNext(searchNode->ReturnNext());
		}
		delete searchNode;
		return true;
	}
	return false;  
}

void LinkedList::InsertAtPosition(int p, int e)
{
	if(!head)  
	{
		this->AppendNode(e);
		return;
	}

	p--;  
	if(p<0)  
		return;

	Node * searchNode = head;
	Node * lastNode;
	Node * newNode = new Node;
	newNode->SetElement(e);
	for(int i=0;i<p;i++)
	{
		if(searchNode != tail) 
		{
			lastNode = searchNode;
			searchNode = searchNode->ReturnNext();
		}
		else  
		{
			if(i>0)  
			{
				this->AppendNode(e);
				return;
			}
			break;
		}
	}
	if(searchNode == head)
	{
		head = newNode;
		newNode->SetNext(searchNode);
	}
	else  
	{
		newNode->SetNext(lastNode->ReturnNext());
		lastNode->SetNext(newNode);
	}
}

bool LinkedList::RemoveAtPosition(int p)
{
	if(!head)  
		return false;  
	p--;  
	if (p<0)  
		return false;
	Node * searchPtr = head;
	Node * prevPtr;
	for(int i=0;i<p;i++)
	{
		if(!searchPtr->ReturnNext())
			return false;
		prevPtr = searchPtr;
		searchPtr = searchPtr->ReturnNext();
	}
	if(tail == searchPtr)
	{
		tail = prevPtr;
		delete searchPtr;
	}
	else if (head == searchPtr)
	{
		head = searchPtr->ReturnNext();
		delete searchPtr;
	}
	else
	{
		prevPtr->SetNext(searchPtr->ReturnNext());
		delete searchPtr;
	}
	return true;
}

int LinkedList:: ReturnValueAtPosition(int p)
{
	if(!head)
		return NULL;

	Node * searchNode = head;
	p--;
	if(p<0)
		return NULL;
	for(int i=0;i<p;i++)
	{
		if(searchNode->ReturnNext() == 0)
			return NULL;
		searchNode = searchNode->ReturnNext();
	}
	return searchNode->ReturnElement();
}

void LinkedList::Search(int e)
{
	Node * searchNode = head;
	Node * lastNode;
	bool FoundFlag = false;

	while(searchNode->ReturnNext())  
	{
		if(searchNode->ReturnElement() == e)
		{
			FoundFlag = true;
			break;
		}
		lastNode = searchNode;
		searchNode = searchNode->ReturnNext();
	}
	if(FoundFlag == true)  
		cout<<"\nValue "<< e << " is found"<<endl;
	else
		cout<<"\nValue "<< e << " is not found"<<endl;
}

void LinkedList::AppendList(LinkedList * other)
{
	if(other->ReturnHead() == 0)  
		return;  
	Node * copyPtr = other->ReturnHead();
	Node * newPtr = new Node(*copyPtr);
	Node * prevPtr;
	if(!head)  
	{
		head = newPtr;
		prevPtr = newPtr;
	}
	else  
	{
		prevPtr = tail;
		prevPtr->SetNext(newPtr);
		prevPtr = prevPtr->ReturnNext();
	}
	while (copyPtr != other->ReturnTail())
	{
		copyPtr = copyPtr->ReturnNext();  
		newPtr = new Node(*copyPtr);
		prevPtr->SetNext(newPtr);
		prevPtr = prevPtr->ReturnNext();
	}
	tail = newPtr;
}

LinkedList * LinkedList::ReturnDifferences(LinkedList * other)
{
	LinkedList * differenceList = new LinkedList(*this);
	Node * otherPtr = other->ReturnHead();
	while(otherPtr != other->ReturnTail())
	{
		differenceList->RemoveValue(otherPtr->ReturnElement());
		otherPtr = otherPtr->ReturnNext();
	}
	differenceList->RemoveValue(otherPtr->ReturnElement());  
	return differenceList;
}

void LinkedList::RotateRight()
{
	if(!head || (tail == head))  
		return;  
	Node * secondlastNode = head;
	while(secondlastNode->ReturnNext() != tail)
		secondlastNode = secondlastNode->ReturnNext();
	secondlastNode->SetNext(0);
	tail->SetNext(head);
	head = tail;
	tail = secondlastNode;
}

void LinkedList::Print()
{
	if(!head)  
	{
		cout << "The linked list has no nodes.\n";
		return;
	}
	Node * currentNode = head;
	while(currentNode != tail)
	{
		cout << currentNode->ReturnElement() << " ";
		currentNode = currentNode->ReturnNext();
	}
	cout << currentNode->ReturnElement() << endl;
}

Node * LinkedList::ReturnHead()
{
	return head;
}

Node * LinkedList::ReturnTail()
{
	return tail;
}