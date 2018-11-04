#pragma once
//*********************************************************************************
//Program:  BST.h
//Author:  Ernesto Valdez
//Class: CSCI/CMPE 2380
//Instructor: Tim Wylie
//Description:  This is the BST.h header file.... that has all the declarations and
// inplementations of the BST(binary  search tree)
//Date: 12/10/15
//*********************************************************************************

//compiler instructions
#ifndef _BST_H_
#define _BST_H_

//include fstream for our ostream parameter 
#include <fstream>
//include string for our string data type
#include <string>

using namespace std;


//*********************************************************************************
//Object:  struct Node
//Description:  This struct is the element in our binary tree.  It holds the info, 
//		and has left and right pointers to the other nodes in the tree.
//*********************************************************************************

template<class DataType>
struct Node
{
	DataType Info;
	Node<DataType> *Left, *Right;
};

//*********************************************************************************
//Object:  class BST
//Description:  This class creates our binary search tree using the Node struct.  It
//		contains all the functions to work with the elements in the tree.  It uses
//		one pointer called Root in order to get to every other element in the tree.
//*********************************************************************************

template<class DataType>
class BST
{
public:
	//constructor
	BST();
	//Copy Constructor to make exact copy of master tree.
	BST(const BST<DataType>&);
	//deconstructor
	~BST();
	//inserts a DataType into the tree
	bool Insert(DataType);
	//Print out tree in order to ostream passed to it.
	void InOrder(ostream&);
	//Delete by the value of the data in a node
	bool Delete(DataType);
	//Prune by if Attribute is in range
	void Prune(DataType, DataType);
	//returns true if tree is empty
	bool Empty();
	//Destroy the tree
	void Destroy();

private:
	//Does a preorder traversal to copy the tree
	void CopyTree(Node<DataType>*);
	//destroys the tree
	void DestroyTree(Node<DataType>*);
	//Iterative function to insert node
	void InsertNode(Node<DataType>*);
	//does a traversal in order and prints out tree
	void InOrderTraversal(Node<DataType>*, ostream&);
	//find a node by the value
	bool Find(DataType, Node<DataType>*&, Node<DataType>*&);
	//returns true if it is a leaf
	bool Leaf(Node<DataType>*);
	//returns true if it has two children
	bool TwoChildren(Node<DataType>*);
	//deletes a leaf
	void DeleteLeaf(Node<DataType>*, Node<DataType>*);
	//deletes a one child node
	void DeleteOneChild(Node<DataType>*, Node<DataType>*);
	//deletes a two child node
	void DeleteTwoChildren(Node<DataType>*);
	//deletes a node if he has an attribute value between a low and high value
	//does a post order traversal to prune tree by attribute
	void PostOrderPrune(DataType, DataType, Node<DataType>*, Node<DataType>*);
	//The root of the tree
	Node<DataType>* Root;
};




//*********************************************************************************
//Function:  BST()  Constructor
//Description:  This function is called whenever a BST object is created.  It sets
//		the Root to NULL so it is empty.
//*********************************************************************************
template<class DataType>
BST<DataType>::BST() :Root(NULL)
{}

//*********************************************************************************
//Function: BST(const BST & source)  Copy Constructor
//Description:  This function is called whenever a BST object is created given a
//		source BST.  The function makes an exact copy of the source tree.
//*********************************************************************************
template<class DataType>
BST<DataType>::BST(const BST<DataType> & source) :Root(NULL)
{
	CopyTree(source.Root);
}

//*********************************************************************************
//Function:  ~BST()  Deconstructor
//Description:  This function is called whenever a BST object is destroyed.  It 
//		destroys all the nodes in a tree to prevent a memory leak, and then it sets
//		the Root back to NULL;
//*********************************************************************************
template<class DataType>
BST<DataType>::~BST()
{
	DestroyTree(Root);
	Root = NULL;
}

//*********************************************************************************
//Function:  Insert
//Description:  This function takes a DataType object and inserts it into the tree
//		in the correct location based on its name.  It sets both of the new nodes 
//		pointers to NULL since it is inserted as a leaf.
//*********************************************************************************
template<class DataType>
bool BST<DataType>::Insert(DataType Original)
{
	Node<DataType>* P = new Node<DataType>;

	if (P == NULL)
		return false;

	P->Info = Original;
	P->Left = NULL;
	P->Right = NULL;


	InsertNode(P);
	return true;
}

//*********************************************************************************
//Function:  InOrder
//Description:  This function does an in order traversal and prints all of the 
//		objects out to the ostream specified in order from least to greatest.
//*********************************************************************************
template<class DataType>
void BST<DataType>::InOrder(ostream& fout)
{
	InOrderTraversal(Root, fout);
}

//*********************************************************************************
//Function:  Delete
//Description:  This function deletes a node in the tree based on a value.  
//      It first searches for the value in the tree and then deletes the node.
//*********************************************************************************

template<class DataType>
bool BST<DataType>::Delete(DataType Name)
{
	Node<DataType> * P=Root;
	Node<DataType> * Parent=NULL;
	
	if ((Find(Name, P, Parent)))
	{
		if (P->Left == NULL && P->Right == NULL)
			DeleteLeaf(P, Parent);
		else if (P->Left == NULL || P->Right == NULL)
		{
			DeleteOneChild(P, Parent);
		}
		else
			DeleteTwoChildren(P);

		return true;
	}
	
	return false;
}

//*********************************************************************************
//Function:  Prune
//Description:  This function Prunes a tree by cutting off all of the nodes that 
//		don't have the attribute specified.
//*********************************************************************************

template<class DataType>
void BST<DataType>::Prune(DataType LowValue, DataType HighValue)
{
	PostOrderPrune(LowValue, HighValue, Root, NULL);
}

//*********************************************************************************
//Function:  Empty()
//Description:  This function returns true if the tree is empty and false if it has
//		nodes.
//*********************************************************************************

template<class DataType>
bool BST<DataType>::Empty()
{
	if (Root == NULL)
	{
		return true;
	}
	
	return false;
	
}

//*********************************************************************************
//Function:  Destroy()
//Description:  This function destroys the tree and resets it to empty with a Root
//		equal to NULL.
//*********************************************************************************
template<class DataType>
void BST<DataType>::Destroy()
{
	DestroyTree(Root);
	Root = NULL;
}

//*********************************************************************************
//Function:  CopyTree
//Description:  This creates an exact copy of a tree by doing a recursive pre order
//		copy traversal.
//*********************************************************************************
template<class DataType>
void BST<DataType>::CopyTree(Node<DataType>* P)
{
	if (P != NULL)
	{
		Insert(P->Info);
		CopyTree(P->Left);
		CopyTree(P->Right);
	}
}

//*********************************************************************************
//Function:  DestroyTree
//Description:  This function actually destroys the tree by doing a recursive Post 
//		Order traversal and deleting the nodes from the bottom up.
//*********************************************************************************
template<class DataType>
void BST<DataType>::DestroyTree(Node<DataType>* P)
{
	if (P != NULL)
	{
		DestroyTree(P->Left);
		DestroyTree(P->Right);
		delete P;
	}
	P = NULL;
}

//*********************************************************************************
//Function:  InsertNode
//Description:  This function Iteratively finds the correct place in which to enter
//		a node and then inserts it there.
//*********************************************************************************
template<class DataType>
void BST<DataType>::InsertNode(Node<DataType>* P)
{
	//Check if this is the first node in the tree
	if (Root == NULL)
	{
		Root = P;
		return;
	}

	//create pointers to find where we insert the new node
	Node<DataType>* Cur = Root;
	Node<DataType>* Parent = NULL;

	//find the spot to insert P based on the data
	while (Cur != NULL)
	{
		Parent = Cur;
		if (P->Info <= Cur->Info)
			Cur = Cur->Left;
		else
			Cur = Cur->Right;
	}
	//attach P to the Parent pointer
	if (P->Info <= Parent->Info)
		Parent->Left = P;
	else
		Parent->Right = P;
}

//*********************************************************************************
//Function:  InOrderTraversal
//Description:  This function does an in order traversal recursively and prints out
//		all of the nodes in the tree with the ostream specified.
//*********************************************************************************
template<class DataType>
void BST<DataType>::InOrderTraversal(Node<DataType>* P, ostream& fout)
{
	if (P != NULL)
	{
		InOrderTraversal(P->Left, fout);
		fout << P->Info << " ";   //check name
		InOrderTraversal(P->Right, fout);
	}
}

//*********************************************************************************
//Function:  Find
//Description:  This function finds a node based on its value and changes the Pointer
//		P and its Parent pointer to point at that node.
//*********************************************************************************
template<class DataType>
bool BST<DataType>::Find(DataType Value, Node<DataType>*& P, Node<DataType>*& Parent)
{
	if (P == NULL)
	{
		return false;
	}
	else if(P->Info == Value)
	{
		return true;
	}
	else if (P->Info < Value)
	{
		Parent = P;
		P = P->Right;
		Find(Value, P, Parent);
	}
	else
	{
		Parent = P;
		P = P->Left;
		Find(Value, P, Parent);
	}
}


//*********************************************************************************
//Function:  Leaf
//Description:  This function returns true if the node is a leaf and false if it
//		is not.
//*********************************************************************************
template<class DataType>
bool BST<DataType>::Leaf(Node<DataType>* P)
{
	if(P->Left==NULL && P->Right==NULL)
	{ 
		return true;
	}

	return false;
}

//*********************************************************************************
//Function:  TwoChildren
//Description:  This function returns true if the node has two children and false
//		if it does not.
//*********************************************************************************
template<class DataType>
bool BST<DataType>::TwoChildren(Node<DataType>* P)
{
	if (P->Left == NULL || P->Right == NULL)
		return false;
	else
		return true;
}

//*********************************************************************************
//Function:  DeleteLeaf
//Description:  This function deletes a leaf.
//*********************************************************************************
template<class DataType>
void BST<DataType>::DeleteLeaf(Node<DataType>* P, Node<DataType>* Parent)
{
	if (Parent->Left->Info == P->Info)
	{
		Parent->Left = NULL;
	}
	else
		Parent->Right = NULL;

	delete P;
}

//*********************************************************************************
//Function:  DeleteOneChild
//Description:  This function deletes a node that only has one child
//*********************************************************************************
template<class DataType>
void BST<DataType>::DeleteOneChild(Node<DataType>* P, Node<DataType>* Parent)
{
	if (Parent == NULL)
	{
		
		if (P->Left == NULL)
		{
			Root = P->Right;
			
		}
		else
			Root = P->Left;

		delete P;
	}
	else if (Parent->Left == P)
	{
		if (P->Left == NULL)
		{
			Parent->Left = P->Right;
		}
		else
			Parent->Left = P->Left;
		
	}
	else
	{
		if (P->Left == NULL)
		{
			Parent->Right = P->Right;
		}
		else
			Parent->Right = P->Left;
	}
}
//*********************************************************************************
//Function:  DeleteTwoChildren
//Description:  This function deletes a node that has two children.  It finds its 
//		closest predecessor and replaces it where the node with two children had been.
//*********************************************************************************

template<class DataType>
void BST<DataType>::DeleteTwoChildren(Node<DataType>* P)
{
	Node<DataType> * tracker = P;
	Node<DataType>* Parent=P;
	tracker = tracker->Left;
	while (tracker->Right != NULL)
	{
		Parent = tracker;
		tracker = tracker->Right;
	}
	P->Info = tracker->Info;
	DeleteOneChild(tracker,Parent);
}



//*********************************************************************************
//Function:  PostOrderPrune
//Description:  This function Prunes the tree of all values in the range 
//		by doing a recursive Post Order traversal.
//*********************************************************************************
template<class DataType>
void BST<DataType>::PostOrderPrune(DataType LowValue, DataType HighValue, Node<DataType>* P, Node<DataType>* Parent)
{
	if (P == NULL)
	{
		// do nothing
	}

	else if (P->Info < LowValue)
	{
		PostOrderPrune(LowValue, HighValue, P->Right, P);
	}
	else if (P->Info > HighValue)
	{
		PostOrderPrune(LowValue, HighValue, P->Left, P);
	}
	else
	{
		Delete(P->Info);
		PostOrderPrune(LowValue, HighValue, Root, NULL);
	}
			

			
		
	
}


#endif