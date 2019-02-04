//*******************************************************************
//	Test for passing by pointer
//*******************************************************************
#include <iostream>
using namespace std;

int CubeByPointer(int* numP)
{
	(*numP) =  (*numP) * (*numP) * (*numP);
	return *numP;
}

void main()
{
	int num = 5;
	//const int num = 5;			//can't convert from "const int*"
									//to "int*"
	//int *numPtr = &5;				//& can't be on constant
	int *numPtr = &num;
	int result = CubeByPointer(numPtr);
	printf("result: %d\n", result);
	printf("num:    %d\n", num);
}

//	Result:
//	int *numPtr can't be on named constant, or pure constant.
//	Then, it is like reference.