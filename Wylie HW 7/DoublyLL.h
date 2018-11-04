#include<iostream>
#include<string>


//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//
// Name: Ernesto Valdez
// Date: October 22, 2015
// Class: 2380
// Semester: Fall 2015
// Program Name: HW 07
// Program Description: Doubly Linked List which has a constructor , Destructor and methods add to the back
//  add to the front , remove from the back remove from the front , add to position i , gets the back item without removal
// gets the front without removal , gets the length of the list , prints the items in the list , aswell as the overloaded 
// operator ==, !=, <,>, <=,>=, and the extraction operator << to print the list, and a sort and find smallest methods
// find smallest is a helper method which finds the smallest node and returns its pointer, the sort method takes uses the find 
// smallest method and iterates through the list sorting it.
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

using namespace std;

template<class DATATYPE>
struct Node
{
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
	int Count=0;
	
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
	friend ostream  &operator <<(ostream  &out, const LinkedList<DATATYPE>&G)
	{
		if (G.Head == NULL)
		{
			out << "The list is empty dumbo" << endl;
		}
		else
		{

			Node<DATATYPE> * temp = G.Head;
			while (temp != NULL)
			{
				out << temp->data << endl;
				temp = temp->next;
			}

		}
		return out;
	}

	//(20 points)\\
	//should compare the lengths of the Linked lists and check if its less than the other
	bool operator <(const LinkedList<DATATYPE>&);
	// should compare the lengths of the Linked Lists and check if its greater than the other
	bool operator >(const LinkedList<DATATYPE>&);
	// should compare the lengths of the Linked List and checks if its less than or equal to the other list
	bool operator <=(const LinkedList<DATATYPE>&);
	// compares the Linked Lists and checks if its greater than or less than the other list
	bool operator >=(const LinkedList<DATATYPE>&);

	//(30 points)\\
	// method that sorts the linked list from small to big
	void sort();
	// Helper method t ohelp sort the list
	Node<DATATYPE> * findsmall(Node<DATATYPE> *);
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
/////////////////////////////////////////////////////////////
//////////////////BONUS METHODS/////////////////////////////

// THIS WAS GIVING ME TOO MUCH ERRORS SO I JUST DECLARED IT AN IMPLEMENTED INSIDE THE CLASS
// CAN YOU PLEASE EXPLAIN  WHY IT WASNT WORKING :)


 /*template< class DATATYPE>
  ostream &operator <<(ostream &out, LinkedList<DATATYPE> &G)
{
	
	if (G.Head == NULL)
	{
		out << "The list is empty dumbo" << endl;
	}
	else
	{

		Node<DATATYPE> * temp = G.Head;
		while (temp != NULL)
		{
			out << temp->data << endl;
			temp = temp->next;
		}
	
	}
	return out;
}*/


template<class DATATYPE>
bool LinkedList<DATATYPE>:: operator <( const LinkedList<DATATYPE>&y)
{
	int counter1=0;
	int counter2 = 0;
	Node<DATATYPE> * iterator1 = Head;
	Node<DATATYPE> * iterator2 = y.Head;
	while (iterator1 !=NULL)
	{
		counter1++;
		iterator1 = iterator1->next;
	}
	while (iterator2 != NULL)
	{
		counter2++;
		iterator2 = iterator2->next;
	}
	if (counter1 < counter2)
	{
		return true;
	}
	else
		return false;
}


template <class DATATYPE>
bool LinkedList<DATATYPE>::operator >(const LinkedList<DATATYPE>& y)
{
	int counter1 = 0;
	int counter2 = 0;
	Node<DATATYPE> * iterator1 = Head;
	Node<DATATYPE> * iterator2 = y.Head;
	while (iterator1 != NULL)
	{
		counter1++;
		iterator1 = iterator1->next;
	}
	while (iterator2 != NULL)
	{
		counter2++;
		iterator2 = iterator2->next;
	}
	if (counter1 > counter2)
	{
		return true;
	}
	else
		return false;
}


template<class DATATYPE>
bool LinkedList<DATATYPE>::operator <=(const LinkedList<DATATYPE>&y)
{
	int counter1 = 0;
	int counter2 = 0;
	Node<DATATYPE> * iterator1 = Head;
	Node<DATATYPE> * iterator2 = y.Head;
	while (iterator1 != NULL)
	{
		counter1++;
		iterator1 = iterator1->next;
	}
	while (iterator2 != NULL)
	{
		counter2++;
		iterator2 = iterator2->next;
	}
	if (counter1 <= counter2)
	{
		return true;
	}
	else
		return false;
}

// sorts the list by making a for loop whre i=Head and then loops through all the elements 
// and each time it finds the smallest and swaps in the Head
template<class DATATYPE>
bool LinkedList<DATATYPE>::operator >=(const LinkedList<DATATYPE>&y)
{
	for (int i=Node<DATATYPE>*)
}

template<class DATATYPE>
void LinkedList<DATATYPE> ::sort()
{
	
	for (Node<DATATYPE> * i= Head; i!= NULL; i = i->next)
	{
		Node<DATATYPE>*smallestNode = findsmall(i);
		swap(i->data, smallestNode->data);
	
	}
}
// just a helper method that finds the smallest node giving it the Head pointer
// which makes in easier to make a sorting method that sorts the list
template<class DATATYPE>
Node < DATATYPE> * LinkedList<DATATYPE>::findsmall(Node<DATATYPE> * y)
{		
	Node<DATATYPE> * smallest = y;
		while (y != NULL)
		{
		
			if (y->data < smallest->data)
			{ 
				 smallest = y;
				y = y->next;				
			}
			else
			{

				y = y->next;
			}
		}
	
		return smallest;
}