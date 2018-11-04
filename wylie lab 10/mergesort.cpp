//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Name: Ernesto Valdez	
// Date: November 18, 2015
// Class: 2380.02
// Semester: Fall 2015
//
// Program Name: Lab 10
// File Name: MergeLL.cpp
// Program Description: mergesort.cpp file which has the implementation of the mergesort.h file
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
 

#include "mergesort.h"

//constructor
LinkedList::LinkedList()
{
	//should set head pointer
	Head = NULL;
}


//destructor
LinkedList::~LinkedList()
{
	//should call delete list
	DeleteList();
}

/*
This function adds a new node to the end of the single linked list. If it is the
first node, then head will still be NULL.

head -> [2|] -> [8|] -> [6|X]
*/

void LinkedList::Add(int newdata)
{
	//create a new node to hold the data with a terminal (NULL) next pointer
	Node* temp = new Node;
	temp->data = newdata;
	temp->next = NULL;

	//check whether head has been initialized (is NULL)
	//if not, make the new node head and set prev
	if (Head == NULL)
	{
		Head = temp;
	}
	else
	{
		//if head has been initialized
		//find the end of the chain with a pointer
		Node *cur = Head;
		while (cur->next != NULL)
			cur = cur->next;

		//add the new node on to the last node in the list
		//set pointer
		cur->next = temp;
	}
}


//This function walks through the list and prints the integer for each of the nodes
//We are using a copy of head, so changing it's value does not alter the
//variable in main
void LinkedList::PrintList()
{
	//walk through the list
	Node *cur = Head;
	while (cur != NULL)
	{
		//print the data for the current node
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}



//This function walks through the list and deletes each node
void LinkedList::DeleteList()
{
	//make sure the list has data
	if (Head != NULL)
	{
		//delete first node
		Node *next = Head->next;
		delete Head;
		//loop through list deleting each node
		while (next != NULL)
		{
			Head = next;
			next = Head->next;
			delete Head;
		}
		//set pointer to null
		Head = NULL;
	}
}


//Call mergesort passing the entire list
void LinkedList::Sort()
{
	MergeSort(Head);
}

//implement Merge sort for a single linked list implementation
void LinkedList::MergeSort(Node* &head)
{
	//base case
	if (Head->next==NULL)
	{
		// there is nothing to do there is only one node
	}
	else
	{
		//find the midway point to split in two
		Node* midpoint;
		Node * curr;
		// set both the pointers to Head
		midpoint = Head;
		curr = Head;
		// loop that goes the the list and makes one of the pointers basically stop at the middle
		while (midpoint!= NULL && curr->next->next != NULL)
		{
			curr = curr->next->next;
			midpoint = midpoint->next;
			
		}

		//add nullpointer to end of first (split them) (check special cases)
		Node * Tmid = midpoint;
		midpoint = midpoint->next;
		Tmid->next = NULL;
		Tmid = NULL;


		//call two sublists - these are now sorted
		MergeSort(Head);
		MergeSort(midpoint);


		//now the two sublists are sorted
		//loop through each and put them in the right order
		Node *newhead; //always points at the front of the new list
		Node *tail;    //always points at the back of the new list



		//set up the first node in the new list
		if (Head->data <= midpoint->data)
		{
			newhead = Head;
			tail = Head;
			Head = Head->next;
		}
		else 
		{
			newhead = midpoint;
			tail = midpoint;
			midpoint = midpoint->next;
		}
		//while we still have two lists, keep adding the next item to the end
		//of our new list, move the pointer, and set the tail 
		//attach the rest of the list that hasn't been processed to our combined list.
		//at the end you have a single sorted list
		while (Head!= NULL && midpoint!= NULL)
		{
			 if (Head->next == NULL) 
			{
				tail->next = midpoint;
				tail = midpoint;
				midpoint = midpoint->next;
			}
			else if (midpoint == NULL)
			{
					tail->next =Head;
					tail = Head;
					Head = Head->next;
			}
			
			else if (Head->data <= midpoint->data)// if the first list node is less than the second list node
			{
				// make the node the next node
				tail->next = Head;			// the tail of the new list points to the head
				tail = Head;				// the tail of the new list is now the head
				Head = Head->next;			// goes to the next node in the list for comparison
			}
			else if (midpoint->data <= Head->data) // if the second list node is less than the first list node
			{
				tail->next = midpoint;			// the end of the new list points to the mipoint
				tail = midpoint;				//the new tail is the midpoint node
				midpoint = midpoint->next;		//go to the next node in the second list
			}
		
			


			Head = newhead;
		}
	}

}