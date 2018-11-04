//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Name: Ernesto Valdez
// Date: 11/10/15
// Class: 2380
// Semester: Fall 2015
// Program Name: Hw 8 problem 3
// Program Description: This program takes in a number withing the range of 0-1000000000
// then outputs the binary equivalent of that number using the stack stl class
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

#include<iostream>
#include<stack>
using namespace std;


int main()
{
	long number;//variable of type long
	stack<int> prog;// initialize stack
	// ask the user for their input
	cout << " enter a number withing the range [0-1000000000] " << endl;
	do
	{
		cin >> number;
		
		
		
		while(!cin)
		{
			cin.clear();
			cout << " Please enter a number withing the range[0-1000000000]" << endl;
			cin >> number;
		}
				
			
		
		
		// loop that excutes aslong as the number is not 0
		while (number != 0)
		{
		if (number % 2 == 0)
		{
			prog.push(0);
		}
		else
		{
			prog.push(1);
		}
		//divide the number by 2
		number = number / 2;
		}
		
		
	}
while (number!=0);
// loop that executes until the stack is empty
// it displays the top of the stack onto the console
// then it pops it off
while (!prog.empty())
		{

			cout << prog.top();
		
			prog.pop();
		}
	system("pause");
	return 0;
}