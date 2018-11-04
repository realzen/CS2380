//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\
//                                                                             
//Author: Ernesto Valdez                                                        
//Class: CSCI/CMPE 2380															
//Description: header file that  all methods declared in the StatList.h and works
//with the main cpp file 
//\\/\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

#include"StatsList.h"

//Default Constructor
StatsList::StatsList()
{
	


}
// returns the number at the given index of the array
ListType StatsList:: At(int i)
{
	
	return List[i];


}
// returns the number of items in the list
int StatsList::Length()
{
	 int count=0;
	for (int i = 0; i < Counter; i++)
	{
		if (List[i] != ' ')
			count++;
			

	}
	return count;

}
// finds the mean of the numbers of list
double StatsList::Mean()
{

	double total=0;
	double  mean=0;
	for (int i = 0; i < Counter; i++)
	{
		total += List[i];
	}
	 mean =total / Counter;

	return mean;

}

double StatsList::MeanNoHighLow()
{
	double total = 0;
	double mean = 0;
	double max=GetHigh();
	double min=GetLow();
	for (int i = 0; i < Counter; i++)
	{
		total += List[i];
	}
	mean = ((total - min) - max) /(Counter-2);
	return mean;
}
// prints the number of A's B's C's etc
void StatsList::PrintGradeCount()
{
	int countA = 0;
	int countB = 0;
	int countC = 0;
	int countD = 0;
	int countF = 0;
	int size = Counter;
	for (int i = 0; i < size; i++)
	{
		if (List[i] >= 90)
			countA++;
		else if (List[i] < 90 && List[i] >= 80)
			countB++;
		else if (List[i] < 80 && List[i] >= 70)
			countC++;
		else if (List[i] < 70 && List[i] >= 60)
			countD++;
		else
			countF++;
			
	}

	cout << "A:" << countA << endl;
	cout << "B:" << countB << endl;
	cout << "C:" << countC << endl;
	cout << "D:" << countD << endl;
	cout << "F:" << countF << endl;
}
// returns the highest grade
ListType StatsList::GetHigh()
{
	int size = Counter;
	double maxNum=List[0];
	for (int i = 0; i < size; i++)
	{
		
		if (List[i]>maxNum)
			maxNum = List[i];

	}
	return maxNum;

}
// returns the lowest grade
ListType StatsList::GetLow()
{
	int size = Counter;
	double minNum=List[0];
	for (int i = 0; i < size; i++)
	{
		if (List[i]<minNum)
			minNum = List[i];

	}
	return minNum;
}

// adds a new grade and returns true if was succesfull
bool StatsList::NewGrade(ListType ngrade)
{

	int size = Counter;
	if (size < MAXCELLS)
	{
		List[size++] = ngrade;
		
		Counter++;
		return true;

	}
	else
		return false;

}

//returns the number of grades in the given range
int StatsList::GradeCountRange(double start, double end)
{
	int i = 0;
	double total = 0;
	int size = Counter;
	for ( List[i] = start; i < end; i++)
	{
		
		total += List[i];
	}

	return total;
}