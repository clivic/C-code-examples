//******************************************************************
// AllTypeSize program
// This program can get the size of nearly all of integral and float data types 
// in the computer which executes the program
// and the output results are aligned
//******************************************************************

#include <iostream>
#include <climits>
#include <iomanip>		//for set width
using namespace std;

int main()
{
	cout << left;
	cout << setw(30) << "float type size is: "			<< sizeof(float)			<< endl;		//float type
    cout << setw(30) << "double type size is: "			<< sizeof(double)			<< endl;		//double type
    cout << setw(30) << "long double type size is: "	<< sizeof(long double)		<< endl;		//longdouble type
	cout << setw(30) << "char type size is: "			<< sizeof(char)				<< endl;		//char type
	cout << setw(30) << "short type size is: "			<< sizeof(short)			<< endl;		//short type
	cout << setw(30) << "int type size is: "			<< sizeof(int)				<< endl;		//int type
	cout << setw(30) << "long type size is: "			<< sizeof(long)				<< endl;		//long type	
	cout << setw(30) << "bool type size is: "			<< sizeof(bool)				<< endl;		//long type
	cout << setw(30) << "unsigned char type size is: "	<< sizeof(unsigned char)	<< endl;		//unsigned char type
	cout << setw(30) << "unsigned short type size is: "	<< sizeof(unsigned short)	<< endl;		//unsigned char type
	cout << setw(30) << "unsigned int type size is: "	<< sizeof(unsigned int)		<< endl;		//unsigned char type
	cout << setw(30) << "unsigned long type size is: "	<< sizeof(unsigned long)	<< endl;		//unsigned char type
	return 0;
} 
