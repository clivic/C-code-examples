#include <iostream>
#include <string>
 
using namespace std;

void main()
{
	int num=10; 
	cout << num++ << ' ' << num <<"\n";// 10 10, it wont be 11 for "num" has not been involved in expression.
	cout << num++; cout << ' ' << num <<"\n";// 11 12, it has been finished in a sentence, so the value of num is plused.
	int num1=10;
	cout << ++num1 << ' ' << num1<<"\n" ;// 11 10
	cout << ++num1; cout << ' ' << num1 <<"\n";// 12 12
}