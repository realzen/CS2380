//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Name: Ernesto Valdez
// Date: November 11, 2015
// Class: 2380.02
// Semester: Fall 2015
//
// Program Name: Lab 09
// File Name: lab09.cpp
// Program Description: program that asks the user for an input of type string and then sorts the
// string using Quicksort, a sorting algorith created by Tony Hoare which is an average O(n log N)
// and  worst case O(n^2), then outputs the sorted string. 
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
 

#include<iostream>
#include<string>

using namespace std;



//Here we use quicksort to sort the string of characters
//we sort the string in place without making any copies, so
//for a call to quicksort we pass in the low and high indices
//we sort to.
void QuickSort(string &input, int low, int high)
{
	//initial conditions
	int smallindex = low;
	int index = low;
	char pivot;

	//base case if only one element
	if (low > high)
	{
		cout << "there is only one element"<< endl;
	}

		
	else
	{
		//choose pivot as middle element
		pivot = input[((high - low) / 2) + low]; // makes the pivot equal the middle element


		//swap pivot with index
		swap(input[((high - low) / 2) + low], input[index]);
		//swap(pivot, input[index]);

		//execute quicksort loop
		for (int i = low; i <= high; i++)
		{
			if (input[smallindex]<pivot)
			{
				//swap(input[index], input[smallindex]);
				swap(pivot, input[smallindex]);
				low++;
			
			}
			else
			{
				input[index++];
			}
		}
		//swap pivot with smallindex
		swap(input[((high - low) / 2) + low], input[smallindex]);
		//swap(pivot, input[smallindex]);


		//recursively call each side
		QuickSort(input, low, smallindex - 1);
		QuickSort(input, smallindex + 1, high);
	}
}



//in main we just want to take in a string 
int main()
{
	string input;
	cout << "Please input a string:" << endl;

	//get the string
	getline(cin, input);

	//efficiently sort the list
	QuickSort(input, 0,  input.length()-1);
	//print the output
	cout << input << endl;

	return 0;
}