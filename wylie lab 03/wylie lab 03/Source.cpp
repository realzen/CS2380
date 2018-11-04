//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Program: Lab 0218
// Author: Ernesto Valdez
// Course: CSCI/CMPE 2380
// Description: This program simulates a drive-through window...EXCITING!!!!
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\ 

#include <iostream>
#include <string>
//this class should use a dynamically allocated string array (string* order_list = new string[xxxx];) 
#include "DList.h"
using namespace std;


int main()
{
	DList order;
	string input;
	int input_num;
	char order_more;

	cout << "Welcome to the drive through, what do you want?" << endl;

	do {
		//get food item
		cout << "Item:";
		getline(cin, input);

		//get number of that item
		cout << "How many?:";
		cin >> input_num;

		//should dynamically add at least <input_num> number of cells onto the end of the array
		//those cells should have the value <input>
		order.Add(input, input_num);

		cout << endl << "Will there be anything else? (y/n): ";
		cin >> order_more;
		cin.ignore(2000, '\n');
		cin.clear();
	} while (order_more != 'n');

	//tell them how many things they ordered (the size of the array)
	cout << "Okay, you ordered " << order.GetNumberItems() << " items." << endl;
	cout << "I have the following:" << endl;
	//should loop through the array and print all the items
	// 3  Burgers
	// 2  Sodas
	// 4  French Fries
	order.PrintOrder();
	cout << "Thank you. Please drive around to the next window." << endl;


	return 0;
}



