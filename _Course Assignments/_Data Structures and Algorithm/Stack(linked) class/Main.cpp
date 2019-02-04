//*******************************************************************
//	test version by Mr.Bao
//*******************************************************************
#include "Linked_Stack.h"
#include "Linked_Stack.cpp"

void main()
{
	Stack<double>numbers;
	int n;
	double item;
	cout<<"please input an integer n followed by n decimal numbers."<<endl;
	cin>>n;
	for(int i=0; i<n; i++)
	{   
		cin>>item;
		numbers.Push(item);
	}

    cout << endl << "Result: " << endl;
    while (!numbers.Empty()) 
	{
		numbers.Top(item);
		cout << item << " ";
		numbers.Pop();
	}
    cout << endl;


}
