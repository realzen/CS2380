#include"Stack.h"


int main()
{


	Stack st;
	if (!st.empty())
	{
		cout << " not empty" << endl;
	}
	else
	{
		cout << "empty"<<endl;
	}

	st.Push('x');
	st.Push('w');
	st.Push('T');
	st.print();
	st.pop();
	st.print();
		

	isPalin();

	

	system("pause");
	return 0;
}


