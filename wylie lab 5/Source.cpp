//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Program: Lab 05
// Author:
// Course: CSCI/CMPE 2380
// Description: This program builds a doubly linked list from entered numbers
//      and sorts them as they are added.
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\ 

#include "SortedLL.h"

int main()
{
	//initialize our pointer to NULL
	SortedLL LL;
	int input;
	cout << "Please input some numbers." << endl;
	do
	{
		cout << "#";
		cin >> input;
		while (!cin)
		{
			cin.clear();
			cin.ignore(2000, '\n');
			cout << "Not a legal integer" << endl;
			cout << "#: ";
			cin >> input;
		}
		//if they're positive, add them to the linked list
		if (input > 0)
			LL.SortedAdd(input);
	} while (input > 0);


	cout << "The numbers you entered are:" << endl;
	//this just prints them in order
	LL.PrintList();
	//the list is deleted in the class


	return 0;
}