#include "Node.h"

Node::Node()
{
	element = 0;
	next = 0;
}

Node::Node(Node & copy)
{
	element = copy.ReturnElement();
	next = copy.ReturnNext();
}

Node::~Node()
{
}

int Node::ReturnElement()
{
	return element;
}

void Node::SetElement(int e)
{
	element = e;
}

Node * Node::ReturnNext()
{
	return next;
}

void Node::SetNext(Node * n)
{
	next = n;
}