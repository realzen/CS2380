#include "AsciiArt.h"

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;



int main()
{

	// variables that will get user input and store it
	string fileName;
	int option;
	// prompts the user to choose what they want to do
	cout << "Please Choose an option:" << endl;
	cout << "(1) Create ASCII Art " << endl;
	cout << "(2) Create Instructions" << endl;
	cin >> option;

	// option to write art that will prompt the user for 
	// a file name and create an output file and rename it
	// then it will call the readInst function and output 
	// the image that was created.
	if (option == 1)
	{
		cout << ">" << option << endl;
		cout << " Enter the File Name:";
		cin >> fileName;
		cout << "Input: " << fileName << endl;
		readInst(fileName);
		string outFile = fileName.substr(0, fileName.find_last_of('.')) + "_art.txt";
		cout << "Output: " << outFile << endl;
	}
	// option to read art that will prompt the user to for a file
	// name and will create an output file with a new name
	// then call the readArt function and output it to the output file.
	else if (option == 2)
	{
		cout << ">" << option << endl;
		cout << "Enter the File Name: ";
		cin >> fileName;
		cout << "Input: " << fileName << endl;
		readArt(fileName);
		string outFile = fileName.substr(0, fileName.find_last_of('.')) + "_instr.txt";
		cout <<  "Output: " << outFile << endl;
		

	}
	// if the user doesnt choose one of the options is prompts this message
	else
		cout << "Invalid Answer...please try again...." << endl;


	return 0;
}