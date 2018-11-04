//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Program:  Homework 9
// Author: Ernesto Valdez
// Date: 9/25/2015
// Course: CSCI/CMPE 2380
// Description: header file that works in conjuntion with the maze.cpp which holds the class
// "coord" (which is short for coordinates and was supposed to be Move but gave namespace errors)
// and also has the function  findAwayOut which finds a way out of the maze and returns true or false.
// the function takes a start coordinate given in the text file and checks its neighbors (ie: its surroundings)
// for legal places to move. each time it finds a legal space it pushes onto the stack and then pops it leaving a
// breadcrumb until it finds or doesnt find a way out. This file also has the function Output which write to the output file
// the solved maze and the number of the maze along with the answer to whether the maze was solved or not ( way out or no way out).
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

#include<iostream>
#include<string>
#include<fstream>
#include<stack>

using namespace std;
//************************************* PLEASE READ*******************************
// the move class renamed to coord because i was getting errors with the namespace
class coord
{
public:
	coord(); // default constructor
	coord(int, int); // parameterized constructor
	int row;
	int col;
	
};
// default constructor just in case but not needed
coord::coord()
{
	row = -1;
	col = -1;
}
// parametrized constructor thats takes 2 int's 
coord::coord(int r, int c)
{
	row = r;
	col = c;
}
// function that finds a way out of the maze used in the main and returns true or false if there is
// or is not a way out in the maze. takes paramaters arr the rows columns and the start coordinates
bool findAWayOut(char arr[], int rows, int columns, int startRow, int startCol)
{
	bool wayOut = false;// bool variable for checking
	stack <coord> path; //  create a stack called path
	coord start(startRow, startCol); // the start coodinates/indexes
	path.push(start);// push the start coordinates
	arr[columns*startRow + startCol] = '.'; // pops the breadcrumb at the entry gate

	// while loop that executes aslong as the stack in not empty ie: there are no more eligible neighbors
	while (!path.empty())
	{

		coord current = path.top();
		path.pop();
		// the left  neighbor
		if (current.col - 1 >= 0)
		{
			//  if the neighbor is a legal character then push to stack and replace with breadcrumb
			if (arr[columns*current.row+current.col - 1] == '+')
			{ 
				// creates neigbor with coordinates
				coord neighbor(current.row, current.col - 1);
				// pushes neighbor onto stack
				path.push(neighbor);
				 // changes it to a breadcrumb
				arr[columns*current.row+current.col - 1] = '.';
			}
			// incase the neighbor is an 'E'... do the same
			else if (arr[columns*current.row+current.col - 1] == 'E')
			{
				// creates neigbor with coordinates
				coord neighbor(current.row, current.col - 1);
				// pushes neighbor onto stack
				path.push(neighbor);
				// changes it to a breadcrumb
				arr[columns*current.row+current.col - 1] = '.';
				// if its am 'E' set wayout to true
				wayOut = true;					
			}

		}
		// the right neighbor
		if (current.col + 1 < columns)
		{
			//  if the neighbor is a legal character then 
			//push to stack and replace with breadcrumb
			if (arr[columns*current.row+current.col + 1] == '+')
			{
				coord neighbor(current.row, current.col + 1);
				path.push(neighbor);
				arr[columns*current.row+current.col + 1] = '.';
			}
			// incase the neighbor is an 'E'.. do the same
			else if (arr[columns*current.row+current.col + 1] == 'E')
			{
				coord neighbor(current.row, current.col + 1);
				path.push(neighbor);
				arr[columns*current.row + current.col + 1] = '.';
				wayOut = true; // sets wayout to true if its 'E'
			}
		}
		// the top neighbor
		if (current.row - 1 >= 0)
		{
			//  if the neighbor is a legal character then 
			//push to stack and replace with breadcrumb
			if (arr[columns*(current.row - 1) + current.col] == '+')
			{
				coord neighbor(current.row - 1, current.col);
				path.push(neighbor);
				arr[columns*(current.row - 1) + current.col] = '.'; 
			}
			// incase the neighbor is an 'E'..do the same
			else if (arr[columns*(current.row - 1) + current.col] == 'E')
			{
				coord neighbor(current.row - 1, current.col);
				path.push(neighbor);
				arr[columns*(current.row - 1) + current.col] = '.';
				wayOut = true;//set to true if its 'E'
			}
		}
		//the bottom neighbor
		if (current.row + 1 < rows)
		{
			//  if the neighbor is a legal character then push to stack and replace with breadcrumb
			if (arr[columns*(current.row + 1) + current.col] == '+')
			{
				coord neighbor(current.row + 1, current.col);
				path.push(neighbor);
				arr[columns*(current.row + 1) + current.col] = '.';
			}
			// incase the neighbor is an 'E'
			else if (arr[columns*(current.row + 1) + current.col] == 'E')
			{
				coord neighbor(current.row + 1, current.col);
				path.push(neighbor);
				arr[columns*(current.row + 1) + current.col] = '.';
				wayOut = true;
			}

		}

	}
	// if wayout is true then return true else return false
	if (wayOut)
		return true;
	else
		return false;

}
// output function that writes to the output file 
// takes  as paremeters the output file, the array , columns , the bool wayout variable and
//the the int maze varible(keeps track of mazes)
// writes  the maze number  then the whole maze and whether thre was a way out or not
void Output(ofstream &ofile, char arr[], int rows, int columns, bool wayOut, int mazeNumber)
{
	ofile << endl << endl << "Maze Number " << mazeNumber << endl << endl;
	// loop that prints the solved maze to the output file
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			ofile << arr[columns*i + j];
		}
		ofile << endl;

	}
	// couts "there is a way out  " if its true
	if (wayOut)
		ofile << "\nThere is a way out!\n"; 
	// couts "  thre is no way out " if its not true
	else
		ofile << "\nThere is not a way out!\n"; 

}
