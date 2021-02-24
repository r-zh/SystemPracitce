
class Node
{

public:
	Node();
	Node(Node &);
	~Node();
	int ReturnElement();
	void SetElement(int);
	Node * ReturnNext();
	void SetNext(Node *);
private:
	int element;
	Node * next;
};