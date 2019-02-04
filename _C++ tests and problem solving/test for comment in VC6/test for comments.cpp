/************************************************
	test for comments in Visual C++ 6.0
************************************************/
#include <iostream>
using std::cout;

//	No.1
//	/* */s are in /* */

///* 
// *	we cant put /* */ in to /* */ 
// */		
// in VS2013, it has been explicit while compiling uha:)

//	No.2
//	to test if is available
/* 
* /* hello 
*/
//indeed it is also available in VC++ 6.0 despite VS2013

//	No.3
int main()
{
	//cout << "*/" << '\n';
	//cout << "/*" << '\n';
	cout << /* "*/" */;		//this statement is invalid
	//(that comment is considerred as sth. in "")
	return 0;
}
