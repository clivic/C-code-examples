/************************************************
To test the space of union and struct
************************************************/

#include <iostream>
#include <string>
#include "unions and structs.h"

using namespace std;

int main()
{
	cout<<"Person's size is :"
		<< sizeof(person) << endl;
	cout<<"string size is:" << sizeof(string)
		<< endl;
	cout<<"int size is:" <<sizeof(int)<<endl;

              cout<<"weightType's size  is :"
				  << sizeof(weightType)<<endl;
	cout<<"long size is:"<<sizeof(long)<<endl;
	cout<<"int size is:"<<sizeof(int)<<endl;
	cout<<"double size is:"<<sizeof(double)<<endl;
	return 0;
}

/*	Results:
	max member size -- union
	sum member size -- struct					*/
