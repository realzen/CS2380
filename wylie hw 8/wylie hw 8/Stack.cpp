//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Name: Ernesto Valdez
// Date: 11/10/15
// Class: 2380
// Semester: Fall 2015
// Program Name: Hw 8 problem 1 & 2
// Program Description: This is the Stack.cpp file which has the stack implementations
// for the Stack class given in problem #1 this .cpp file also has the implementation for the 
// the palindrome program (function) in problem #2 which asks the user for a string 
// and runs the test to check if its a palindrome using a stack, it inserts the string character by
// character , then makes 2 stacks  by diving the first stack for comparison. each times it pops one of
// the stacks it compares the values, if it finds one of the values does not equal the other
// then the function returns "it is not a palindrome. The bonus method is also implemented in this function
// that is that the code ignores spaces, spostrophes, commas ,etc.. and does not distinguish from capital 
// or lower case letters.
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

#include "Stack.h"
// constructor which initializes the
// head to null when you create a stack 
Stack::Stack()
{
	Head = NULL;
	
}
// destructor which deletes the stack class 
// with a while loop that goes through the
// whole stack until it reaches the end(ie:head->next==NULL)
Stack::~Stack()
{
	Node * Bomb = Head;
	while (Bomb != NULL)
	{
		Head = Head->next;
		delete Bomb;
		Bomb = Head;
	}
	delete Head;
}
// push method in the stack that pushes a character value
// onto the top of the stack, it creates a new node called "newnode"
// then initializes its next pointer to null, and sets its data to the char c being 
//added. it also checks if the head if null, if it is then in makes this node the head
// othewise its next pointer is set to point to the head and then since its a stack
// and it is being added to the top this node is then made into the new head
void Stack::Push(char c)
{
	Node * newnode = new Node;
	newnode->next = NULL;
	newnode->data = c;

	if (Head == NULL)
	{
		Head = newnode;
	}
	else
	{
		newnode->next = Head;
		Head = newnode;
	}
}
// method that takes the top element of the stack  and retruns that element
// by creating a temporary variable to store the data of the top item
// it checks if the stack is empty my checking if the head is null
// if it is, the function does nothing and exits, but if it is not then 
// it makes a disposable node called "waste" and sets it to the head
// after it sets the temp variable to store the heads data and sets the currect head
// to be the next element in the stack and finally it deletes the waste node which deletes the
// old head of the stack
char Stack::pop()
{
	char temp = 0;
	if (Head == NULL)
	{
		// there is nothing to pop
	}
	else
	{
		Node * waste = Head;
		temp = Head->data;
		Head = Head->next;
		delete waste;

	}
	return temp;
}
// this method returns true if the stack is empty or false if 
// it is not, it checks this my simply checking whether the head is null or
// not
bool Stack::empty()
{
	if (Head == NULL)
	{
		return true;
	}
	else
		return false;
}
// method that prints the elements of the stack
// starting from the head all the way until the current
// node is NULL (ie: the end of the stack)
void Stack::print()
{
	if (Head == NULL)
	{
		// its empty
	}
	else
	{
		Node * temp = Head;
		//iterative loop that goes through
		// the stack printing the node's data
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
		
	}
}

// program that returns true if it is a palindrome and false if its not
// this function aks the user for a string then pushes onto the stack character by character
// then pushes half of that stack onto another stack then it pops both of the stacks for 
// comparison, when comparing it will pop both the stacks one by one and if it finds a case
// where the popped values are not equal it will exit the loop and cout that it is not a palindrome
// else when the stacks become empty it will cout that they are a palindrome

void isPalin()
{
	// string variable to store the user input
	string userString;
	// variable to know the length of the string
	int count = 0;
	//asks the user for a string to compare
	cout << "input the string you would like to check if it is palindrome" << endl;
	cout << "->";

	//takes the string and stores it in the userString variable
	// uses the getline function to get everything
	getline(cin, userString);
	
	// crete two stacks S1 and S2
	Stack S1;
	Stack S2;
	
	// loop that pushes the string on the first Stack S1
	for (int i = 0; i < userString.length(); i++)
	{
		// using the isalpha checks for valid input
		// ie: commas,periods, quotation marks
	
		if (isalpha(userString[i]))
		{
			S1.Push(userString[i]);
			// increment the count 
			count++;
		}
		
	}
	
	// pop half of the first stack (S1) onto the second Stack (S2)
	// first check if its not empty becuase we dont want to get a empty stack error
	// since we already have the length of the string AKA the number of nodes of the S1 stack
	// we simply devide it by 2 to pop half of that stack onto the second Stack
	if (!S1.empty())
	{
		int i = 0;
		// executes the loop half the length of the stack so half the stack is pushed 
		// onto the second Stack
		while (i < count/2)
		{
			
			S2.Push(S1.pop());
			i++;
		}
		// if the string  has an odd number of elements  there will be an extra node on the
		// first stack so lets make sure to pop it off and disregard it
		if (count % 2 == 1)
		{
			
			S1.pop();
		}
		// now we have two stacks of the same size that are ready for 
		// the comparison palindrome test :)
	}

	// time to pop the values and compare them to check if the are equal
	// ie: if the are indeed a palindrome
	// loop that executes aslong as both the stacks are not empty
	while (!S1.empty() && !S2.empty())
	{
		
		//two character values for comparison
		char S1Check, S2Check;
		// make the variables equal to the first popped values
		S1Check = S1.pop();
		S2Check = S2.pop();
		
		// make char data to lower case to compare everything
		// in lower case using the tolower function
		// as used in the lab
		tolower(S1Check);
		tolower(S2Check);
		

		// checks when popping the values if they are not equal
		// if they are it will exit the loop and cout  that it is
		// NOT a palindrome

		if (S1Check != S2Check)
		{
			cout << " The String is NOT a palindrome" << endl;
			break;
		}
		// if the outputs are not 
		else
		{
			// if the stacks are empty and there was not a case
			// when they not equal then it is a palindrome
			if (S1.empty() && S2.empty())
			{
				cout << " The String IS a palindrome" << endl;
				break;
			}
		}
		
	}
}


		

	
	


