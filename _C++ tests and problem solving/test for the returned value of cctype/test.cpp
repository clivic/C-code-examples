/************************************************
This program is to test what the non-zero value 
is which is the returned value of a cctype 
function.
************************************************/

#include <iostream>
#include <cctype>

main()		//function type is optional
{
	std::cout << islower('b') << '\n'	
								//suppose 'true'
			  << isupper('F') << '\n'	
								//suppose 'true'
			  << isdigit('3') << '\n'	
								//suppose 'true'
			  << isalnum('d') << '\n'	
								//suppose 'true'
			  << isalnum('9') << '\n'	
								//suppose 'true'
			  << isalpha('e') << '\n'	
								//suppose 'true'
			  << isalnum(0) << '\n'		
								//suppose 'flase'
			  << isspace('	') << std::endl;	
								//suppose 'true'
	return 0;
}

//The result is 2 1 4 2 4 2 0 8
//We change the char in the same type like
//replace "F" in "isupper()" by "E" etc.
//And the result is same.

//So perhaps:
//"1" represents upper char
//"2" represents lower char
//"4" represents num
//"8" represents space
//What a magical regularity it appears! :)