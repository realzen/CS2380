//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Name: Ernesto Valdez
// Date: 11/10/15
// Class: 2380
// Semester: Fall 2015
// Program Name: HW 8 Problem 4
// Program Description: that asks the user for a  decimal number  and a base of their
// choosing and a digit. The program then finds the base representation of the decimal number
//and counts the number of digits the user chose that were present  in its base representation
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int decimalNum ; // variable to store the decimal number
	int newbase; // variable to store the base
	int digit; // variable to store the digit to count for
					// asking the user for their input.....
	cout << " enter a decimal number & a base  and the digit you wish to count in that base"
		<< endl;
	cout << " enter the dimal number:" << endl;
	cin >> decimalNum;
	cout << "enter the base you wish to use:" << endl;
	cin >> newbase;
	cout << "enter the digit you wish to count for:" << endl;
	cin >> digit;
	
	//initialize the stack
	// loop that executes aslong as the number is not zero
	stack<int> Count;
	while (decimalNum != 0)
	{
		//check if when you divide the number by the base you want it equals the digit 
		// you are counting for
		// if it does then push that digit onto the stack you made
		// if not then do nothing beacuse you only want those you are looking for
		if (decimalNum % newbase == digit)
		{
			Count.push(digit);
		}
		else
		{
			
		}
		// devide the number  by the base each time in order to change the
		// value of the decimal number in the while loop and exit
		decimalNum = decimalNum / newbase;
	}
	// use the size method in the STL stack class to cout the number
	// of times the number % base == digit
	cout << Count.size() << endl;
	system("pause");
	return 0;
}