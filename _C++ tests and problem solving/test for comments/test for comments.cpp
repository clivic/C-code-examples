/************************************************
	test for comments
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
//indeed it is available in VS2013

//	No.3
int main()
{
	cout << "*/" << '\n';
	//cout << "/*" << '\n';
	//cout << /* "*/" */;		//this statement is invalid
	//	//(that comment is considerred as sth. in "")
	cout << /*" */" /**/ "/*" */ << '\n';	//this statement is valid

	//	* Visual C++ is convenient in this ground perhaps:
	//	  It will remind you what is comment and what is code while coding
	return 0;
}
