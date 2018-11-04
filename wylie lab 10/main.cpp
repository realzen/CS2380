//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//
// Name: Ernesto Valdez
// Date: November 18, 2015
// Class: 2380.02
// Semester: Fall 2015
//
// Program Name: Lab 10
// File Name: lab10.cpp
// Program Description: main program that works with the mergesort.h and mergesort.cpp
//
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
 

#include "mergesort.h"

int main()
{
	//initialize our pointer to NULL
	LinkedList LL;
	int input;
	cout << "Please input some numbers." << endl;
	//get positive numbers
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
			LL.Add(input);
	} while (input > 0);


	cout << "The numbers you entered are:" << endl;
	//this just prints them in order
	LL.PrintList();

	cout << "The numbers sorted:" << endl;
	//sort the list
	LL.Sort();
	//print the sorted list
	LL.PrintList();

	system("pause");
	return 0;
}
