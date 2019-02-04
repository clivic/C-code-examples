/********************************************************************************************************************************************
This program is to test wheter we can use std::cout etc. to replace "using namespace std", though a bit complex.
********************************************************************************************************************************************/

#include <iostream>
#include <string>

void main()
{
	std::cout << "Happy Birthday!" << std::endl;

}
//The result turns out that it is valid.