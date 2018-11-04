//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Name: <Put your name here>
// Date: Novemeber 18, 2015
// Class: 2380.02
// Semester: Fall 2015
//
// Program Name: Lab 10
// File Name: MergeLL.h
// Program Description: <Fill out>
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
 

#include<iostream>
using namespace std;


//a basic node for a single linked list with data
struct Node
{
	int data;
	Node *next;
};

//a linked list class we will use
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void Add(int);
	void PrintList();
	void Sort();
private:
	void DeleteList();
	void MergeSort(Node*&);
	//Node* FindMiddle(Node*);
	//Node* MergeLists(Node*,Node*);
	Node* Head;
};
