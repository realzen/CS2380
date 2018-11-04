//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Program: Lab 11
// File: Tree.cpp
// Author: Ernesto Valdez
// Course: CSCI/CMPE 2380
// Description: This program works with the lab11.cpp (main)  and holds a constructor
//(which initializes a tree by making a root), destructor (which deletes the tree),
// insert(that finds the correct location  in the tree and inserts it in that place),
// Print(that prints the tree by using the other print function PrintFromNode()), DeleteTree
// (which deletes the tree in a post traversal order LRV(left,right,vertex)) and finaly the PrintFromNode 
//function (which prints the tree given the vertex in an in order traversal LVR(left,vertex,right))
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\ 


#include "Tree.h"


//constructor
Tree::Tree()
{
	Root = NULL;
}
//destructor
Tree::~Tree()
{
	DeleteTree(Root);
}
//add to the tree
void Tree::Insert(int newdata)
{
	//create a node and store the data
	//set left/right pointers to null
	Node * newLeaf = new Node;
	newLeaf->Data = newdata;
	newLeaf->Left = NULL;
	newLeaf->Right = NULL;

	//search tree for insertion point.  keep track of node which will be the parent
	//if root is null, make this root
	if (Root == NULL)
	{
		Root = newLeaf;

	}
	else
	{
		//create a cur and parent pointer
		Node * current = Root;
		Node * parent = current;
		while (current != NULL)
		{
			//while the current pointer isn't null, walk through the tree based on data
			parent = current;
			if (newLeaf->Data <= current->Data)
			{
				current = current->Left;

			}
			else
			{
				current = current->Right;

			}

		}
		//attach node to parent based on value
		if (newLeaf->Data < parent->Data)
		{
			parent->Left = newLeaf;
		}
		else
			parent->Right = newLeaf;

	}






}



//This function walks through the tree and prints the integer for each of the nodes
//an in-order traversal LVR
void Tree::PrintTree()
{
	PrintFromNode(Root);

}

//This function walks through the tree and deletes each node
//it should be a post-order traversal LRV
void Tree::DeleteTree(Node* vertex)
{
	if (vertex != NULL)
	{
		DeleteTree(vertex->Left);
		DeleteTree(vertex->Right);
		delete vertex;
	}

}
//This function walks through the tree and prints the integer for each of the nodes
//an in-order traversal LVR
void Tree::PrintFromNode(Node* vertex)
{
	if (vertex != NULL)
	{
		PrintFromNode(vertex->Left);
		cout << vertex->Data;
		PrintFromNode(vertex->Right);

	}
}
