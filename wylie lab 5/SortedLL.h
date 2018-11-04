//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Program: Lab 05
// Author:
// Course: CSCI/CMPE 2380
// Description: This is the header file for the linked list class
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\ 


#include<iostream>
using namespace std;


//a basic node for a doubly linked list with data
struct Node
{
	int data;
	Node *next;
	Node *prev;
};

//a linked list class we will use
class SortedLL
{
public:
	SortedLL();
	~SortedLL();
	void Add(int);
	void SortedAdd(int);
	void PrintList();
private:
	void DeleteList();
	Node* Head;
};