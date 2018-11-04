#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;


// this function will read the art file and output the instructions
// to a created outputfile
void readArt(string fileName)
{

	ifstream iFile;
	ofstream oFile;
	iFile.open(fileName);
	string outFile = fileName.substr(0, fileName.find_last_of('.')) + "_instr.txt";
	oFile.open(outFile);
	string s;
	int line = 1;
	// reads through the file line by line
	while (getline(iFile, s))
	{
		// iterator
		int i = 0;
		//index of parallel arrays
		int counter = 0;
		//array that holds the character
		char characters[100];
		//array that holds the count of that character
		int count[100];
		//checks if the character array is empty
		bool charactersEmpty = true; 
		while (i < s.length()+1)
		{	
			// checks if there is nothing in the arrays and places it
			// in the first index
			if (charactersEmpty) 
			{
				characters[0] = s[i];
				charactersEmpty = false;
				count[counter] = 1;
			}
			//if the current character in the line were looking at is equal
			//to our current working index then increase the count for that character
			else if (s[i] == characters[counter]) 
			{                                    
				count[counter]++;
			}
			//if the current character is different than the character in our working index
			//then increase the index and place the character there and set count to 1
			else if (s[i] != characters[counter]) 
			{                                     
				counter++;
				characters[counter] = s[i];
				count[counter] = 1;
			}
			i++;
		}
		 //writes the line were working with to the file 
		oFile << line << " - ";  
		oFile << count[0] << " ";
		//checks if the character is a space and write 'sp' instead
		if (characters[0] == ' ')
			oFile << "sp";
		else
			oFile << characters[0];
		for (int i = 1; i < counter; i++)
		{
			oFile << ", " << count[i] << " ";
			if (characters[i] == ' ')
				oFile << "sp";
			else
				oFile << characters[i];
		}
		oFile << endl;
		line++;
	}
	
	
	iFile.close();
	oFile.close();

}

//this function will read an instruction file and  output the image
//  it creates into an output file.
void readInst(string fileName)
{
	ifstream iFile;
	ofstream oFile;
	iFile.open(fileName);
	string outFile = fileName.substr(0, fileName.find_last_of('.')) + "_art.txt";
	oFile.open(outFile);
	char trash;
	int junk;
	string s;

	// function that reads through the file line by line
	while (getline(iFile, s))
	{
		// string stream declaration
		stringstream ss(s);
		ss >> junk;
		ss >> trash;
		int tempCount;
		char tempChar;
		// reads through the string stream(single line in file)  character by character
		// and checks if its a space by checking is the letter 
		// s is followed by a p and if it is, it prints out a ' '
		// (space)
		while (ss)
		{
			ss >> tempCount;
			ss >> tempChar;
			ss >> trash;
			if (trash == 'p')
			{
				tempChar = ' ';
				ss >> trash;
			}
			// for loop that prints out to the oFile 
			// depending on the number in the tempcount variable 
			// taken from the instructions
			for (int i = 0; i < tempCount; i++)
			{
				oFile << tempChar;
			}
		}

		oFile << endl;

	}
	
	




}
