#include<iostream>
using namespace std;

class Stack
{
private:
	class Node
	{
	public:
		
		Node * next=NULL;
		//put the pointer and data in here
	private:char data;
	};
	Node *Top;
public:
	//setup initial conditions
	Stack();
	//delete all dynamic memory, etc.
	~Stack();
	//add x to top of the stack
	void Push(char x);
	//remove the top item from the stack and return it
	char Pop();
	//return true if the stack is empty, otherwise return false
	bool empty();
};

Stack::Stack()
{
	//initialize the top to be null when you create a linked list
	Top = NULL;
	char data;
	Node * next;
	
}
Stack::~Stack()
{
	// iterates through the list and makes temp point to Top
	// then changes Top to the next node while temp deletes the node that head
	// was pointing to and temp points to head again ...so on and so on.. until the list
	// is deleted completely
	Node * temp = Top;
	while (temp = NULL)
	{
		Top = Top->next;
		delete temp;
		temp = Top;

	}


}
void Stack::Push(char x)
{
	data = x;
}

