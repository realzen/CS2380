//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Name: Ernesto Valdez
// Date:11/10/15
// Class: 2380
// Semester: Fall 2015
// Program Name: Hw 8 problems 1&2
// Program Description: this is the Stack.h file which has all of the declarations for the 
// class stack and the declaration for the palindrome function
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

#include<iostream>
#include<string>


using namespace std;


class Stack
{
private:
	class Node {



	public:
		char data;
		Node * next;
	
	};
	Node * Head;

public:
	// constructor
	Stack();
	// destructor
	~Stack();
	 // adds C to the top of the stack
	void Push(char c);
	// removes from the top of the stack and returns it
	char pop();
	// returns true if the stack is empty and false if its not
	bool empty();
	// used for testing in main
	void print();

	
	
};

// function that returns if it is or it not a palindrome
void isPalin();



