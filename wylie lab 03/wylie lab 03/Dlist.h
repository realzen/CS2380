#pragma once
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Program: Lab 0218 Header
// Author: Ernesto Valdez
// Course: CSCI/CMPE 2380
// Description: This is the DList header file
// this program is the header file that works in conjunction with the cpp main
// file for the drive through wimdow program
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\ 

#include <iostream>
#include <string>

using namespace std;



#ifndef DLIST_H
#define DLIST_H


class DList
{
public:
	//should initialize any needed variables
	DList();
	//delete any dynamically allocated memory
	~DList();
	//adds item to back of item_list and the number to back of item_amounts
	void Add(string, int);
	//prints the order
	// #  Item
	void PrintOrder();
	//returns the number of items
	int GetNumberItems();
private:
	//the dynamically allocated item list
	string *item_list;
	//the dynamically allocated item amounts
	int *item_amounts;
	//the number of distinct items in the list
	int number_items;
};



#endif