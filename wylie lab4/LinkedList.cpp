//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Program: Lab 04
// Author: Ernesto Valdez
// Course: CSCI/CMPE 2380
// Description: This is the implementation file for the linked list class
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\ 

#include "LinkedList.h"

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
This function adds a new node to the end of the doubly linked list. If it is the
first node, then head will still be NULL.

Here we are using head directly, so that when we create a new node it stores
it in the variable being used in main.

head <=> [2|] <=> [8|] <=> [6|X]
*/

void LinkedList::Add(int newdata)
{
	//create a new node to hold the data with a terminal (NULL) next pointer
	
	Node * newnode = new Node;
	newnode->next = NULL;
	newnode->data = newdata;

	//check whether head has been initialized (is NULL)
	//if not, make the new node head and set prev
	if (Head == NULL)
	{
		Head = newnode;
		
		newnode->prev = NULL;
		
	}
	
	
		//if head has been initialized
		//find the end of the chain with a pointer
	
	else
	{
		//created a node named tail that points to the head
		Node * tail = new Node;
		tail = Head;
		// loop that iterates through the linked list and finds the last one
		while (tail->next!= NULL)
		{
			
			tail = tail->next;
		}

		//add the new node on to the last node in the list
		//set pointers both forward and backward
		
		newnode->prev = tail;
		tail->next = newnode;
	
		
		

	}
}


//This function walks through the list and prints the integer for each of the nodes
//We are using a copy of head, so changing it's value does not alter the
//variable in main
void LinkedList::PrintList()
{
	//walk through the list starting at head
	Node * curr = Head;
	while (curr != NULL)
	{
		//print the data for the current node
		cout << curr->data<<endl;
		curr = curr->next;
	}

	
	
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
