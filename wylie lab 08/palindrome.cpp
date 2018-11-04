//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//
// Name: Ernesto Valdez
// Date: November 6, 2015
// Class: 2380.02
// Semester: Fall 2015
//
// Program Name: Lab 08
// Program Description: program asks the user to input a word and checks if the word is a
// palindrome , meaning the word reads the same backwards and forwards. additionaly the program is able to
// ignore both withspace and punctuation and change uppercase characters to lower case.
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\


//input/output to the console
#include<iostream>
//the string class
#include<string> 
using namespace std;

/*
In this lab I use the ternary operator several times
It is a shorthand for an if/else statement that works like this
(condition) ? (if_true) : (if_false)
*/




/*
For a palindrome we want to consider only the first and last characters
at any given step.  Thus, we will only check if they match, and then
recursively check the smaller string without the first and last characters.

To do this we use the substr function.  The two arguments are:
pos - Start position of the character of the current word (0 based)
n - Length of the substring starting from the start position pos.

So for the string a = "hello", the call
a = a.substr(1,3) would set a to "ell"

*/


bool IsPalindrome(string str)
{
	// ternary operator form
	return (str.length() == 1) ? (true) :(str.substr(0, 1) == str.substr(str.length() - 1, 1)) ?
		(IsPalindrome(str.substr((0 + 1), str.length() - 2))) : (false);


	// base case that checks for the length if its odd number of characters
	// when it recursively check the back and front and reaches the middle it will return false 
	// cause its the last one
	/*if (str.length() == 1)
	{
		
		return true;
	}

	// recursive call
	else
	{
		// if the first and the last chars are the same call
		// the function again but on the substr of the word
		// which is 1 the next char in the front and 1 less in the back
		// and does this while its true and if the are not the same returns false
		if (str.substr(0, 1) == str.substr(str.length() - 1, 1))
		{
			return IsPalindrome(str.substr((0 + 1), str.length() - 2));
		}
		// returns false if the back and the front are not the same (not a palindrome)
		else
			return false;
	}*/
}



/*
We now want to modify the above function to ignore white space and punctuation.
This can be done simply by ignoring any character that is not a valid
letter.  We also want to make it lower case if it is an upper case letter.
We must ignore both at the front and back of the string.

The valid ranges for lower case letters are 97 - 122
Upper case characters are 65 - 90

- set the front and back character to their tolower representations
- if the front character isn't valid, recursively call and ignore it
- if the back character isn't valid, recursively call and ignore it
- base case for matching
- check the base case for length
- recursive call with substring


Try: A nut for a jar of tuna
*/

char tolower(char c)
{
	return (c >= 'A' && c <= 'Z') ? (char)((int)c + 32) : c;
}

bool islower(char c)
{
	return (c >= 'a' && c <= 'z') ? true : false;
}


bool IsPalindromeWS(string str)
{
	//base case to check the length
	if (str.length() == 1)
	{
		return true;
	}
	//recursive calls
	else
	{	
		// sets the front and back to its tolower representation
		str[0] = tolower(str[0]);
		str[str.length() - 1] = tolower(str[str.length() - 1]);

		// using the is alpha function in the  library to check the front if its  NOT alphabetic
		// if its not the it calls the function but ignoring the front char
		if (!isalpha(str[0]))
		{
			return IsPalindromeWS(str.substr(0 + 1, str.length() - 1));
		}
		// checks if the back is not alphabetic 
		// if its not then it calls the function ignoring the back
		else if (!isalpha(str[str.length()-1]))
		{
			return IsPalindromeWS(str.substr(0 , str.length() - 1));
		}
		// checks if the back and front are the same
		// if they are then it calls the function on the substring 
		// increasing the front by 1 and decresing the  back by 1
		else if (str.substr(0, 1) == str.substr(str.length() - 1, 1))
		{
			return IsPalindromeWS(str.substr((0 + 1), str.length() - 2));
		}
		// returns false if they are not equal (not a palindrome)
		else
			return false;
	}
}


int main()
{
	//get the input string
	string input_string;
	cout << "Please enter a string:";
	getline(cin, input_string);

	cout << "The input " << (IsPalindrome(input_string) ? "is" : "is not") << " a palindrome" << endl;


	cout << "The input " << (IsPalindromeWS(input_string) ? "is" : "is not") << " a palindrome with only letters" << endl;

	return 0;
}