#include<iostream>
#include<string>


using namespace std;

template<class DATATYPE>
struct Node
{public:
	DATATYPE data;
	Node<DATATYPE> *next;
	Node<DATATYPE> *prev;

	
	
};
template<class DATATYPE>
class LinkedList
{
private:
	//use a doubly linked-list based implementation
	//keep a head and tail pointer for efficiency
	Node<DATATYPE> *Head;
	Node<DATATYPE> *Tail;
	int Count = 0;

public:
	//setup initial conditions
	LinkedList();
	//delete all dynamic memory, etc.
	~LinkedList();
	//Equality operator to check if two lists are equal
	bool operator==(const LinkedList<DATATYPE>&);
	//Inequality operator to check if two lists are equal
	bool operator!=(const LinkedList<DATATYPE>&);
	//add x to front of list
	void addFront(DATATYPE);
	//add x to back of list
	void addBack(DATATYPE);
	//add x as the ith thing in the list
	//if there are less than i things, add it to the back
	void add(DATATYPE, int);
	//remove and return front item from list
	DATATYPE removeFront();
	//remove and return back item from list
	DATATYPE removeBack();
	//return value of back item (but don't remove it)
	DATATYPE getBack();
	//return value of front item (but don't remove it)
	DATATYPE getFront();
	//return how many items are in the list
	int length();
	//print all elements in the linked list
	void print();
	
	
	////////////////BONUS METHODS////////////////////////////////
	//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	// (10 points)\\
		// over loads the  stream insertion operator and calls the stream function
	
	friend ostream &operator <<(ostream & out, const LinkedList<DATATYPE>&G)
	{

		 Node<DATATYPE> * temp = G.Head;
				while (temp != NULL)
				{
					out << temp->data << endl;
					temp = temp->next;
				}
				return out;
	}

	//(20 points)\\
		// should compare the lengths of the Linked lists and check if its less than the other
	//bool operator <(const LinkedList<DATATYPE>&);
	// should compare the lengths of the Linked Lists and check if its greater than the other
	//bool operator >(const LinkedList<DATATYPE>&);
	// should compare the lengths of the Linked List and checks if its less than or equal to the other list
	//bool operator <=(const LinkedList<DATATYPE>&);
	// compares the Linked Lists and checks if its greater than or less than the other list
	//bool operator >=(const LinkedList<DATATYPE>&);

};



//constructor for the class
template<class DATATYPE>
LinkedList<DATATYPE>::LinkedList()
{
	Head = NULL;
	Tail = NULL;

}

template<class DATATYPE>
LinkedList<DATATYPE>::~LinkedList()
{
	Node<DATATYPE>*destroyer = Head;

	if (destroyer == NULL)
	{
		delete destroyer;
	}
	else
	{

		while (destroyer != NULL)
		{
			Head = Head->next;
			delete destroyer;
			destroyer = Head;
			Count--;
		}
		Head = NULL;
		Tail = NULL;
	}


}

template<class DATATYPE>
bool LinkedList<DATATYPE>::operator ==(const LinkedList<DATATYPE>&y)
{
	Node<DATATYPE> * temp = Head;
	Node<DATATYPE> * temp2 = y.Head;

	while (temp != NULL && temp2 != NULL)
	{
		if (temp->data != temp2->data)
		{

			return false;

		}
		temp = temp->next;
		temp2 = temp2->next;
	}
	if ((temp != NULL && temp2 == NULL) || (temp == NULL && temp2 != NULL))
	{
		return false;
	}
	else
		return true;
}

template<class DATATYPE>
bool LinkedList<DATATYPE>::operator!=(const LinkedList<DATATYPE>&y)
{
	Node<DATATYPE> * temp = Head;
	Node<DATATYPE> * temp2 = y.Head;

	while (temp != NULL && temp2 != NULL)
	{
		if (temp->data != temp2->data)
		{

			return true;

		}
		temp = temp->next;
		temp2 = temp2->next;
	}
	if ((temp != NULL && temp2 == NULL) || (temp == NULL && temp2 != NULL))
	{
		return true;
	}
	else
		return false;
}


template<class DATATYPE>
void LinkedList<DATATYPE>::addFront(DATATYPE x)
{
	Node<DATATYPE> *somenode = new Node<DATATYPE>;
	somenode->data = x;
	somenode->next = NULL;
	somenode->prev = NULL;

	if (Head == NULL)
	{
		Head = somenode;
		Tail = somenode;


	}
	else
	{
		somenode->next = Head;
		Head->prev = somenode;
		Head = somenode;
	}
	Count++;
}

template<class DATATYPE>
void LinkedList<DATATYPE>::addBack(DATATYPE x)
{
	Node<DATATYPE> * somenode = new Node<DATATYPE>;
	somenode->data = x;
	somenode->next = NULL;
	somenode->prev = NULL;

	if (Head == NULL)
	{
		Head = somenode;
		Tail = somenode;
	}
	else
	{
		Tail->next = somenode;
		somenode->prev = Tail;
		Tail = somenode;
	}
	Count++;
}

template<class DATATYPE>
void LinkedList<DATATYPE>::add(DATATYPE x, int y)
{
	Node<DATATYPE> * somenode = new Node<DATATYPE>;
	somenode->data = x;
	somenode->next = NULL;
	somenode->prev = NULL;
	if (y > Count)
	{
		if (Head == NULL || Tail == NULL)
		{
			Head = somenode;
			Tail = somenode;
		}
		else
		{
			// we add it to the back since there is not that many nodes
			Tail->next = somenode;
			somenode->prev = Tail;
			Tail = somenode;
		}
	}
	else
	{
		// find the position
		Node<DATATYPE> *curr = Head;
		Node<DATATYPE> * prevCurr = NULL;// will point to the node previous to curr
		int tempCount = 1;
		while (curr->next != NULL && tempCount < y)
		{
			tempCount++;
			prevCurr = curr;
			curr = curr->next;
		}
		// after that loop exits we will have the Nth position
		if (curr->prev == NULL)
		{
			somenode->next = Head;
			Head->prev = somenode;
			Head = somenode;
		}
		else
		{
			somenode->next = curr;
			curr->prev = somenode;
			prevCurr->next = somenode;
			somenode->prev = prevCurr;
		}
	}
	Count++;
}

template<class DATATYPE>
DATATYPE LinkedList<DATATYPE>::removeFront()
{
	// if its the only node
	if (Head->next == NULL)
	{
		int output = Head->data;
		delete Head;
		return output;
	}
	else
	{
		Node<DATATYPE> * temp = Head;
		int output = Head->data;
		Head = Head->next;
		Head->prev = NULL;
		delete temp;
		return output;
	}
	Count--;
}

template<class DATATYPE>
DATATYPE LinkedList<DATATYPE>::removeBack()
{
	// check if its the only the only node
	if (Tail->prev == NULL)
	{
		int output = Tail->data;
		delete Tail;
		return output;
	}
	else
	{
		Node<DATATYPE> * temp = Tail;
		int output = Tail->data;
		Tail = Tail->prev;
		Tail->next = NULL;
		delete temp;
		return output;
	}
	Count--;
}

template<class DATATYPE>
DATATYPE LinkedList<DATATYPE>::getBack()
{
	return Tail->data;
}

template<class DATATYPE>
DATATYPE LinkedList<DATATYPE>::getFront()
{
	return Head->data;
}

template<class DATATYPE>
int LinkedList<DATATYPE>::length()
{

	return Count;
}

template<class DATATYPE>
void LinkedList<DATATYPE>::print()
{
	if (Head == NULL)
	{
		cout << "There is nothing to print, check again......" << endl;
	}
	else
	{

		Node<DATATYPE> * temp = Head;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
}

//template<class DATATYPE>
//ostream  &operator << (ostream &out,LinkedList<DATATYPE>& G)
//{
//
//	
//
//		Node<DATATYPE> * temp = G.Head;
//		while (temp != NULL)
//		{
//			out << temp->data << endl;
//			temp = temp->next;
//		}
//		
//	
//	
//	
//	return out;
//}