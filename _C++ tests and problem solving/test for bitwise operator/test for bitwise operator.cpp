/**************************************************************************************************
This program tests for the use of bitwise operator.
**************************************************************************************************/

#include <iostream>

using namespace std;

int main()
{
	int a;								//for output

	//test for ~ operator	(* The complement in computer is a bit different from that in "numeric logic" course)
	cout << ~10 << endl;				//00000000 00000000 00000000 00001010	ten
										//11111111 11111111 11111111 11110101	result
										//because 
										//11111111 11111111 11111111 11111111	reprents for -1
										//so the result represents 11

	//test for & operator
	a = 10 & 2;							//00000000 00000000 00000000 00001010	ten
	cout << a << endl;					//00000000 00000000 00000000 00000010	two
										//00000000 00000000 00000000 00000010	result
	//*	please notice that cout << 10 & 2; or cout << a = (10 & 2) is invalid

	//test for | operator
	a = 10 | -7;						//00000000 00000000 00000000 00001010	ten
	cout << a << endl;					//11111111 11111111 11111111 11111001	minus seven
										//11111111 11111111 11111111 11111011	result
										//the first "1" doesn't change its sign! :)

	//test for ^ operator
	a = 2 ^ -19;						//00000000 00000000 00000000 00000010	two
	cout << a << endl;					//11111111 11111111 11111111 11101101	minus nighteen
										//11111111 11111111 11111111 11101111	result
										//10000000 00000000 00000000 00010001	original code for reslut(-17)
	
	//test for << operator:	it have almost the same effect of multipling 2 to the operated number
	//						when shifting one bit.
	a = 15 << 2;						//00000000 00000000 00000000 00001111	fifteen
	cout << a << endl;					//00000000 00000000 00000000 00111100	result

	//test for >> operator:	it have almost the same effect of dividing 2 to the operated number
	//						when shifting one bit. while it supplies 0 while positive, and 1 while negative.
	a = 60 >> 2;						//00000000 00000000 00000000 00111100	sixty
	cout << a << endl;					//00000000 00000000 00000000 00001111	result
	
	a = -60 >> 2;						//11111111 11111111 11111111 11000100	minus sixty
	cout << a << endl;					//11111111 11111111 11111111 11110001	result
										//10000000 00000000 00000000 00001111	original code for reslut(-15)
	
/*
	NOT AVAILABLE IN C++ PERHAPS PLEASE IGNORE IT BELOW...
	
	//test for >>> operator: it is almost identical to << except it only supplies 0 however positive or negative.
	a = -60 >>> 2;						//11111111 11111111 11111111 11000100	minus sixty
	cout << a << endl;					//00111111 11111111 11111111 11110001	result
																											*/
	return 0;					
}
