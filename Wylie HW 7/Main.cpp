#include"DoublyLL.h"

using namespace std;

int main()
{
	// declare a LinkedList
	LinkedList<int> first;
	//checking the addfront and add back methods
	//cout << "now checking the add front and add back methods..." << endl;
	//first.addFront(1);
	//first.addFront(2);
	//first.addFront(3);
	//first.addFront(4);
	//first.addFront(5);
	//first.addBack(10);
	//first.addBack(9);
	//first.addBack(8);
	//first.addBack(7);
	//first.addBack(6);
	//// print the length and the nodes 
	//cout <<"there are: "<< first.length()<<" nodes " << endl;
	//first.print();
	////check if the destructor works
	//first.~LinkedList();
	//cout << endl;
	//cout<<"after the destructor there are: " << first.length()<<" nodes " << endl;
	//first.print();
	//// check for special cases such as two consecutively similar nodes
	//cout << "checking for special cases...." << endl;
	//first.addFront(1);/////////////////
	//first.addFront(1);/////////////////
	//first.addFront(2);
	//first.addFront(3);
	//first.addFront(4);
	//first.addFront(5);
	//first.addBack(10);
	//first.addBack(9);
	//first.addBack(8);
	//first.addBack(7);
	//first.addBack(6);///////////////////////
	//first.addBack(6);///////////////////////
	//first.print();
	//cout << "there are: " << first.length() << " nodes " << endl;
	//first.~LinkedList();
	//cout << "after the destructor there are: " << first.length() << " nodes " << endl;
	//first.print();
	/////////////////////////////////////////////////////////////////////////////////////////////
	//// checking the remove Front and remove Back methods
	//cout << "now checking the remove front and remove back methods..." << endl;
	//first.addFront(1);
	//first.addFront(2);
	//first.addFront(3);
	//first.addFront(4);
	//first.addFront(5);
	//first.addBack(10);
	//first.addBack(9);
	//first.addBack(8);
	//first.addBack(7);
	//first.addBack(6);
	//cout << "printing nodes:" << endl;
	//first.print();
	//cout << "removing the front" << endl;
	//first.removeFront();
	//cout << "printing nodes:" << endl;
	//first.print();
	//cout << "removing the back" << endl;
	//first.removeBack();
	//cout << "printing nodes:" << endl;
	//first.print();
	//cout << "deleting nodes:" << endl;
	//first.~LinkedList();

	/////////////////////////////////////////////////////
	// checking the getBack and the getFront methods
	//cout << "now checking the get back and get front methods" << endl;
	//first.addFront(1);
	//first.addFront(2);
	//first.addFront(3);
	//first.addFront(4);
	//first.addFront(5);
	//first.addBack(10);
	//first.addBack(9);
	//first.addBack(8);
	//first.addBack(7);
	//first.addBack(6);
	//cout << "printing nodes:" << endl;
	//first.print();
	//cout << "getting the back node" << endl;
	//cout << first.getBack() << endl;
	//cout << "printing nodes:" << endl;
	//first.print();
	//cout << "getting the front node" << endl;
	//cout << first.getFront() << endl;
	//cout << "printing nodes" << endl;
	//first.print();
	//cout << "deleting nodes" << endl;
	//first.~LinkedList();
	//////////////////////////////////////////////////////////
	//cout << "now checking the add(DATATYPE x,int y) method" << endl;
	//cout << "here are the nodes:" << endl;
	//first.addFront(1);
	//first.addFront(2);
	//first.addFront(3);
	//first.addFront(4);
	//first.addFront(5);
	//first.addBack(10);
	//first.addBack(9);
	//first.addBack(8);
	//first.addBack(7);
	//first.addBack(6);
	//first.print();
	//cout << "adding to position 5 which holds data 1" << endl;
	//first.add(77, 5);
	//cout << "printing nodes" << endl;
	//first.print();
	//cout << "now adding to position 1 which holds data 5" << endl;
	//first.add(77, 1);
	//cout << "priting nodes" << endl;
	//first.print();
	//cout << "deleting nodes" << endl;
	//cout<< first.length() << endl;
	//first.~LinkedList();
	//
	//////////////////////////////////////////////////////////////////////////////////
	//cout << "now checking for other cases of add method" << endl;
	//cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	//cout << "using add method if there is nothing in the list" << endl;
	//cout << "adding 10 to position 10 on an empty list" << endl;
	//first.add(10, 10);
	//first.print();
	//cout << "length:" << first.length() << endl;
	//cout << "adding to  position more than count" << endl;
	//cout << "10 to position 10, 10 to pisition 20 and 20 to position 100" << endl;
	//first.add(10, 10);
	//first.add(10, 20);
	//first.add(20, 100);
	//first.print();
	//cout << "length: " << first.length() << endl;
	/////////////////////////////////////////////////////////////////
	//cout << "now checking the == operator" << endl;
	//cout << endl;
	//cout << "creating new list:A" << endl;
	//LinkedList <int> A;
	//A.addFront(1);
	//A.addFront(2);
	//A.addFront(3);
	//A.addFront(4);

	//A.print();
	//cout << " printing list A" << endl;
	//LinkedList <int> B;
	//cout << "creating list: B" << endl;
	//B.addFront(1);
	//B.addFront(2);
	//B.addFront(3);
	//B.addFront(4);
	//B.addFront(5);
	//cout << "printing list B" << endl;
	//B.print();
	//cout << endl;
	//cout << "checking if the lists are  equal or not equal" << endl;
	//if (A == B)
	//{
	//	cout << "the linked lists are equal" << endl;
	//}
	//else
	//{
	//	cout << "Not equal" << endl;
	//}
	//if (A != B)
	//{
	//	cout << "the linked lists are NOTTTTT equal" << endl;
	//}
	//else
	//{
	//	cout << "equal!!!!!" << endl;
	//}
	//cout << "checking the  extraction operator(<<) operator" << endl;
	//cout << "using list A" << endl;
	//cout << A;
	//cout << " checking the <> <= >= operators" << endl;
	//cout << "" << endl;
	//cout << "creating lists" << endl;
	//cout << "inserting into the lists" << endl;
	//LinkedList<int> one;
	//LinkedList<int> two;
	//one.addBack(5);
	//one.addBack(4);
	//one.addBack(3);
	//one.addBack(2);
	//
	//two.addBack(1);
	//two.addBack(2);
	//two.addBack(3);
	//two.addBack(4);
	//two.addBack(5);
	//cout << "printing both lists" << endl;
	//cout << "list one:" << endl;
	//one.print();
	//cout << endl;
	//cout << "list two" << endl; 
	//two.print();
	//if (one <two)
	//{
	//	cout << "true it is less than" << endl;
	//}
	//else
	//	cout << "false it is not less than"<<endl;

	//if (one>two)
	//{
	//	cout << "true it is greater than" << endl;
	//}
	//else
	//	cout << "false it is not greater than" << endl;
	//if (one <= two)
	//{
	//	cout << "true it is less than or equal to" << endl;
	//}
	//else
	//	cout << "false it is not less than or equal to" << endl;
	//if (one >= two)
	//{
	//	cout << "true it is greater than or equal to" << endl;
	//}
	//else
	//	cout << "false it is not greater than or equal to" << endl;
	cout << "creating list E:" << endl;
	LinkedList<int> E;
	
	E.addBack(5);
	E.addBack(10);
	E.addBack(3);
	E.addBack(25);
	E.addBack(1);

	cout << "printing list E:" << endl;
	E.print();
	cout << endl;
	cout << "sorting list E" << endl;
	E.sort();
	cout << "This is the sorted list:" << endl;
	E.print();


	system("pause");

	//return 0;
}