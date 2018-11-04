#include<iostream>
#include<fstream>
#include<string>

using namespace std;
////\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//// Program:  Problem #1
//// Author: Ernesto Valdez
//// Date: 09/09/2015
//// Course: CSCI/CMPE 2380
//// Description: This program will prompt the user for an input file and will count the number of words in the file and 
////output it to the screen/
////\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//
//int main()
//{
//	//input file
//	ifstream infile;
//
//	// string for the name of the file the user will enter
//	string s;
//
//	// counter which will be used in the lopp to count the number of words are in the file
//	int count = 0; 
//
//	//prompts user for name of file and inputs string s variable
//	cout << "Enter the name of the file: ";
//	cin >> s;
//
//	//opens file
//	infile.open(s);
//
//
//	// loop that will read through the file and count the number of words
//	while (infile >> s)
//	{	
//		count++;
//	}
//
//	cout << "the number of words is:" << count << endl;
//
//	infile.close();
//
//	return 0;
//}
////\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//// Program:  Problem #2
//// Author: Ernesto Valdez
//// Date: 09/09/2015
//// Course: CSCI/CMPE 2380
//// Description: This program will prompt the user a name and will count the number of letters it has 
//// and outout it to the creen. The program also takes in any number of names and excludes spaces.
////\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

int main()
{
	string name;
	
	int count = 0;
	int numLetters[100];
	int  i = 0;
	char t;

	cout << "Enter your name :";
	
	
	t = cin.get();
	numLetters[i] = 0;
	count++;
	while (t != '\n')
	{

		if (t == ' ')
		{
			i++;
			numLetters[i] = 0;
			count++;
		}
		else
		{
			numLetters[i]++;
		}
			
		t = cin.get();
		
			
		
	}
	
	for (i = 0; i < count; i++)
	{
		cout << "name " << i + 1 << " has " << numLetters[i] << " letters." << endl;

	}
	return 0;
}

////\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//// Program:  Problem #3
//// Author: Ernesto Valdez
//// Date: 09/09/2015
//// Course: CSCI/CMPE 2380
//// Description: This program will prompt the user for an input file and will count the number of words in the file and 
////output it to the screen/
////\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

int main()
{


	// variable for the txt
	string text;
	// variable to keep track of the total
	int total = 0;
	// varible used as iterator
	int i = 0;

	cout << "input: ";
	getline(cin, text);
	for (i; i<text.length();i++)
	{

		switch (text[i])
		{

		case '+':
			total++;
	
			break;
		case '-':
			total--;
			
			break;
		case '*':
			total = total*total;
			
			break;
		default:
		
			break;

		}
	}
	
	cout << "total: " << total << endl;

	






	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	ofstream writeFile;
	string file;
	string text;
	int numTimes;

	
	cout << "Enter the file name: ";
	cin >> file;
	writeFile.open(file);
	cout << "Enter the word you wish to write: ";
	cin >> text;
	cout << "Enter the amout of times you want it written: ";
	cin >> numTimes;


	for (int i = 0; i < numTimes; i++)
	{
		cout << text << endl;;
		writeFile << text << endl;


	}

	writeFile.close();

	return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{

	ifstream infile;
	string name;
	string text;
	int count = 0;

	cout << "Enter the file name:";
	cin >> name;
	infile.open(name);


	
	while (getline(infile,text))
	{

		count++;

	}
	
	cout << "This was the string that was originally entered: " << text << endl;
	cout << "The string was entered this many times: " << count << endl;
	infile.close();





	return 0;
}