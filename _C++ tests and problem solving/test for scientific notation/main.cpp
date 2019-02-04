/*******************************************************************************************************************************************
This program is intended to test if "scientific" is also a manipulator in c++ and if we can recover displaying in scientific notation after 
we use "fixed" manipulator and also what does "fixed" do before setprecision().
*******************************************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void main()
{
	double num=9.283;
	cout<<setprecision(2)<<num<<endl;
	cout<<fixed<<setprecision(2)<<num<<endl;
	cout<<scientific<<setprecision(3)<<num<<endl;
}
//Without a "fixed" manipulator it setprecisions from the head of a number.
//While with it ahead, it setprecisions from after the decimal point.
//"scientific" is also a manipulator in c++ and we of course can recover displaying in scientific notation
//