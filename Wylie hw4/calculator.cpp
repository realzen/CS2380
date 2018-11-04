//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
// Program:  Homework 4
// Author: Ernesto Valdez
// Date: 09/20/2015
// Course: CSCI/CMPE 2380
// Description: program that does all the fucntions of a calculator, such as addition, subtraction
// division, multiplication and clear.
//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

#include"calculator.h"
// main program whichs uses the Calculator class methods
int main()
{

	Calculator mycalc;
	mycalc.clear();
	mycalc.add(4.52);
	mycalc.add(3.789);
	mycalc.divide(2.6);
	mycalc.multiply(3.12);
	mycalc.subtract(2.678);
	cout << mycalc.display() << endl;       // prints out "7.2928"
	mycalc.clear();
	mycalc.add(5.0);
	cout << mycalc.display() << endl;       // prints out "5"


	//advanced stuff #1: add a constructor
	Calculator calc1;
	cout << calc1.display() << endl;  //prints out 0

	//advanced stuff #2: add a parameterized constructor
	Calculator calc2(5);
	cout << calc2.display() << endl; //prints out 5

	//advanced stuff #3: Define calculator addition (overload the '+' operator)
	Calculator calc3(7);
	calc1 = calc2 + calc3;
	cout << calc1.display() << endl;  //prints out 12

	return 0;
};



// Bonus(2)
//If you could be  Amzing at one skill what would you choose?

