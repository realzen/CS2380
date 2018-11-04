#include<iostream>
using namespace std;


// Calculator Class 
class Calculator
{
private:
	// variable to store the total
	double total;

public:
	// operator + 
	Calculator operator+(Calculator x)
	{
		Calculator t;
		t.total = total + x.total;
		return t;

	}

	// contructor for class
	Calculator()
	{
		total = 0;

	}
	// paramaterized constructor
	Calculator(double x)
	{

		total = x;

	}
	// method that displays the total
	double  display()
	{
		return total;
	}
	// method that adds to the total
	double add(double value)
	{
		total += value;
		return value;
	}
	//method that subtracts from the total
	double subtract(double value)
	{
		total -= value;
		return value;
	}
	// method that performs multiplication
	double multiply(double value)
	{
		total *= value;
		return value;
	}

	// method that performs division
	double divide(double value)
	{
		total /= value;
		return value;
	}
	// method that clears the total / resets calculator
	double clear()
	{
		total = 0;
		return total;
	}

};