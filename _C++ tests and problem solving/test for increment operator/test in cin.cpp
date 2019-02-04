/**************************************************************************************************
This program tests how the increment operator works in ostreams.
**************************************************************************************************/

#include <iostream>

using namespace std;

int main()
{
	int num(10); 
	cout << num++ << ' ' << num		  // 10 10	increments after this cout statement
		 << endl;
	cout << num++; cout << ' ' << num // 11 12	it's two statement, and diffrent result
		 << endl;
	num=10; 
	cout << ++num << ' ' << num		  // 11 10	how weird -- *Please see below explaination
		 << endl;
	cout << ++num; cout << ' ' << num // 12 12	preincrement
		 << endl;
	return 0;
}

/*	Explaination:	

  *In Visual C++, one expression doesn¡¯t support "updates". (especially in output stream)

   So in cout << ++num << ' ' << num; , even num has been increased 1, in the sentence 

   it would also be output the defalut value.											*/
