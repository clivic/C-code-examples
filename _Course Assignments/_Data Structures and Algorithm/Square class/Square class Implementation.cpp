/**************************************************************************************************
Square class's Implementation
**************************************************************************************************/

#include "Square class Specification.h"
#include <iostream>

using namespace std;

/*	private datas:
	double len;
	double wid;			*/

//*************************************************************************************************

Square::Square()
/*	default, set the square's length == 0, width == 0 (a null square)
	Postcondition:	length == 0, width == 0.							*/
{
	len = 0, wid = 0;
}

//*************************************************************************************************

Square::Square(/* in */	double length,
			   /* in */ double width)
/*	initialize the square's length, width 
	Postcondition:	len == length && wid == width.						*/
{
	len = length;
	wid = width;
}

//*************************************************************************************************

void Square::Write()
/*	display the length and width.					
	Postcondition:	cout length and width								*/
{	
	cout << "length is: " << len << endl 
		 << "and width is: " << wid << endl;
}

//*************************************************************************************************

double Square::CSquare()
/*	calculating the square of the square.
	Postcondition:	return the value of len * wid in double type.		*/
{
	return (len * wid);
}

//*************************************************************************************************

double Square::CCircum()
/*	calculating the circumference of the square.
	Postcondition:	return the value of 2*(len + wid) in double type.	*/
{
	return (2 * (len + wid));
}


