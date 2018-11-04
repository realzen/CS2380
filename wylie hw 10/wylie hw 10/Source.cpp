//*********************************************************************************
//Program:  hw10main.cpp
//Author:   Ernesto Valdez
//Class: CSCI/CMPE 2380
//Instructor: Tim Wylie
//Description:  This is the main file that does ... several things.  it constructs
// a Binary search tree then propmts the user with a menu of options 
// which include printing the tree, deleting an item in the tree, pruning a tree, adding 
// to the tree , destrying the tree and finaly quit the console
// all of these options are calling the methods in the BST.h file
//Date: 12/10/15
//*********************************************************************************



#include<iostream>

#include "BST.h"
using namespace std;




//*******************************************************************************
//Main, prints menu and does tree operations
//*******************************************************************************
int main()
{
	BST<int> tree;
	int input;

	do
	{
		//menu
		cout << endl << "Menu Options" << endl;
		cout << "   (1) Print Tree" << endl;
		cout << "   (2) Delete Item" << endl;
		cout << "   (3) Prune Tree" << endl;
		cout << "   (4) Add Items" << endl;
		cout << "   (5) Destroy Tree" << endl;
		cout << "   (6) Quit" << endl;
		cout << "> ";

		cin >> input;
		while (!cin || input <= 0 || input > 6)
		{
			cin.clear();
			cin.ignore(2000, '\n');
			cout << "Not a legal option" << endl;
			cout << "> ";
			cin >> input;
		}
		//execute command
		switch (input)
		{
		case 1:
			//this just prints them in order
			tree.InOrder(cout);
			break;
		case 2:
			int val;
			cout << "Value: ";
			cin >> val;  //should check if valid int is entered
			tree.Delete(val);
			break;
		case 3:
			int low, high;
			cout << "Low Value: ";
			cin >> low;  //should check if valid int is entered
			cout << "High Value: ";
			cin >> high;  //should check if valid int is entered
			tree.Prune(low, high);
			break;
		case 4:
			int num, insert;
			cout << "How many values? ";
			cin >> num;
			for (int i = 0; i<num; i++)
			{
				cout << "Number " << i + 1 << ": ";
				cin >> insert;
				if (cin)
					tree.Insert(insert);
				else
					i--;
			}
			break;
		case 5:
		case 6:
			tree.Destroy();
			break;
		default:
			break;
		}
	} while (input != 6);

	return 0;
}
