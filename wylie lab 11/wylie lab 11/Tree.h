//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Program: Lab 11
// File: Tree.h
// Author:
// Course: CSCI/CMPE 2380
// Description: 
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\ 


#include<iostream>
using namespace std;


//a basic node for a tree vertex with data
struct Node
{
	int Data;
	Node *Left;
	Node *Right;
};

class Tree
{
public:
	//constructor
	Tree();
	//destructor
	~Tree();
	//add to the tree
	void Insert(int newdata);
	//This function walks through the tree and prints the integer for each of the nodes
	//an in-order traversal LVR
	void PrintTree();
private:
	//the root of the tree
	Node* Root;
	//This function walks through the tree and deletes each node
	//it should be a post-order traversal LRV
	void DeleteTree(Node* vertex);
	//This function walks through the tree and prints the integer for each of the nodes
	//an in-order traversal LVR
	void PrintFromNode(Node* vertex);

};
