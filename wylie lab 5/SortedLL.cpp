//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Program: Lab 05
// Author:
// Course: CSCI/CMPE 2380
// Description: This is the implementation file for the linked list class
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\ 

#include "SortedLL.h"

//constructor
SortedLL::SortedLL()
{
	//should set head pointer
	Head = NULL; // sets the head to NULL
}


//destructor
SortedLL::~SortedLL()
{
	//should call delete list
	DeleteList();//deletes the linked list
}
/*
This function adds a new node to the end of the doubly linked list. If it is the
first node, then head will still be NULL.

Here we are using head directly, so that when we create a new node it stores
it in the variable being used in main.

head <=> [2|] <=> [8|] <=> [6|X]
*/

void SortedLL::Add(int newdata)
{
	//create a new node to hold the data with a terminal (NULL) next pointer
	Node * newnode = new Node;
	newnode->data = newdata;
	newnode->next = NULL;
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
		Node *temp = Head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		//add the new node on to the last node in the list
		//set pointers both forward and backwards

		temp->next = newnode;
		newnode->prev = temp;
		
	}
}

/*
This function adds a new node in the list where the
data is sorted from low to high.

*/
void SortedLL::SortedAdd(int newdata)
{
	//create a new node to hold the data with a terminal (NULL) next pointer
	Node * newnode = new Node;
	newnode->data = newdata;
	newnode->next = NULL;

	//check whether head has been initialized (is NULL)
	//if it is null, make the new node head and set prev
	if (Head == NULL)
	{
		Head = newnode;
		newnode->prev = NULL;
	}
	//else head is not null
	else
	{
		Node * temp = Head;
		while (temp->next != NULL && temp->data <= newnode->data)
		{
			temp = temp->next;
		}
		//find the spot to insert it

		//check for special cases
		//goes to the right
		
			if (Head->next == NULL || Head->data > newnode->data)
			{
				if (newnode->data > Head->data)
				{
					Head->next = newnode;
					newnode->prev = Head;
				}
				else
				{
					Head->prev = newnode;
					newnode->next = Head;
					Head = newnode;
				}
			}
			else if (temp->data < newnode->data)
			{
				temp->next = newnode;
				newnode->prev = temp;
			}
			else
			{
				newnode->next = temp;
				newnode -> prev = temp->prev;
				temp->prev->next = newnode;
				temp->prev = newnode;
			}
			/*if (newnode->data <= temp->data)
			{
				Node*curr = temp->prev;
				curr->next = newnode;
				newnode->prev = curr;
				newnode->next = temp;
				temp->prev = newnode;
			}
			else 
			{
				temp->next = newnode;
				newnode->prev = temp;
			}*/
		
		
		//else // goes to the left
		//{
		//	
		//	newnode->next = Head;
		//	Head->prev = newnode;
		//	Head = newnode;
		//}
	}
}
	


//This function walks through the list and prints the integer for each of the nodes
//We are using a copy of head, so changing it's value does not alter the
//variable in main
void SortedLL::PrintList()
{
	//walk through the list starting at head
	Node * temp = Head;
	while (temp != NULL)
	{
		//print the data for the current node
		cout << temp->data << endl;
		temp = temp->next;
	}


}



//This function walks through the list and deletes each node
void SortedLL::DeleteList()
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