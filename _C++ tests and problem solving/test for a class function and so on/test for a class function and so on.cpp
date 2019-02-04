/**************************************************************************************************
This program test the problems encountered in Chapter 14.
**************************************************************************************************/

#include <iostream>

using namespace std;

class Out
{
private:
	float dataA;
	float dataB;
public:
	Out();
	Out(float, float);
	void Set(float, float);
	void Print();
	float ShowA();
	float ShowB();
};

//*************************************************************************************************

Out::Out()
{
	cout << "Please input dataA:" << endl;
	cin >> dataA;
	cout << "Please input dataB:" << endl;
	cin >> dataB;
}

Out::Out(float a, float b)
{
	dataA = a;
	dataB = b;
}

void Out::Set(float a, float b)
{
	dataA = a;
	dataB = b;
}

void Out::Print()
{
	cout << "The dataA is:" << dataA << endl;
	cout << "The dataB is:" << dataB << endl;
	//cout << "We have " + dataA + " and " + dataB << endl;
	//the sentence above is improper.
}

float Out::ShowA()
{
	return dataA;
}

float Out::ShowB()
{
	return dataB;
}

//*************************************************************************************************
//Driver of this test
/*void main()
{
	Out x;
	Out y(2, 3);
	x.Print();
	y.Print();
}*/

//Result:
//	1.default constructor can be input.
//	2.embeded parentheses in parameter list are perhaps not allowed.
//	3.cout float with cstring couldn't use + perhaps.