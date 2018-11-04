//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Program:  Homework 9
// Author: Ernesto Valdez
// Date: 09/25/2015
// Course: CSCI/CMPE 2380
// Description: Main program that includes the Move.h header file and has multiple variable declarations 
// mainly used to store variables while reading through the input file Specifically main reads through the file and creates an
// array with the given dimensions on the first line, then reads line by line inserting into the array and storing the entry gate 
// location into two variables (startRow and startCol) then calls the findAwayOut funtion to solve the maze and afterwards
// calls the Output function to write to the output file then deallocates the memory after calling the Output function and finally
// closes both the input and the output files.
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

#include"move.h"


int main()
{
	string Name; // variable to store the name of the file the user will input
	ifstream ifile; // the input file
	ofstream ofile; // the output file
	int rows=0; // row variable to store the given rows in the text file
	int columns=0; // columns variable to store the number of columns in the given text file
	int mazeNumber = 1; // maze number variable used to keep track of how many mazes there are
	int startRow; // variable to store the starting row given in the text file
	int startCol; // variable to store the starting column given by the text file
	bool wayOut; //  variable to check if there is a way out (ie: true or false)

	string mystring; // variable that helps store each line of the text file for copying onto the array

								
	cout << "Enter the name of the file:" << endl; // asks the user for the name of the file
	cin >> Name;									// then stores it in the variable Name

	ifile.open(Name); // opens the file using the variable Name
	ofile.open("Maze.out"); // opens the output file
	// printing to the output file
	ofile << "Solutions for the maze assignment\nErnesto Valdez" << endl; 
	// while loop to read through the file
	while (ifile >> rows >> columns)
	{
		// gets the rest of the first line(nothing)
		getline(ifile, mystring);
		//********************************PLEASE READ************************************************************
		// creating the maze array																				*
		// I was getting errors with a 2D array so i decided to use a 1D array that is coded and implemented as *
		// a 2D array, to access an index given row and column the algorithm is (column * row +column)			*
		//*******************************************************************************************************
		char * arr;
		arr = new char[rows*columns];

		// inserting in to the maze array
		for (int i = 0; i < rows; i++)
		{
			getline(ifile, mystring);

			for (int j = 0; j < columns; j++)
			{
				arr[columns*i + j] = mystring[j];
			}
		}

		// takes in the starting row and column  after reading the maze in
		ifile >> startRow >> startCol;
		// getline gets the rest of the line which is nothing
		getline(ifile, mystring);

		// loop for testing purposes 
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << arr[columns*i + j];
			}
			cout << endl;

		}
		// we call the fidnAwayOut function in the move.h file
		wayOut = findAWayOut(arr, rows, columns, startRow, startCol);

		// call the output function to write to the output file
		Output(ofile, arr, rows, columns, wayOut, mazeNumber);

		// to increment each time and keep track of the mazes we are doing
		mazeNumber++;

		// deallocating the array
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				
				arr[columns*i + j] = NULL;
				
			}
			

		}
		delete[] arr;
	}
	// close the  output file
	ofile.close();
	// close the input file
	ifile.close(); 
	system("pause");
	return 0; 
}