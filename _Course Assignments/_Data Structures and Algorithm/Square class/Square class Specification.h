/**************************************************************************************************
Square class's Specification
This class stores square's length and width, and have the operations:
two constructions, set, calculating square, circumference.
**************************************************************************************************/

class Square
{
public:
	Square();
	/*	default, set the square's length == 0, width == 0 (a null square)
		Postcondition:	length == 0, width == 0.							*/

	Square(/* in */	double length,
		   /* in */ double width);
	/*	initialize the square's length, width 
		Postcondition:	len == length && wid == width.						*/

	void Write();
	/*	display the length and width.					
		Postcondition:	cout length and width								*/
	
	double CSquare();
	/*	calculating the square of the square.
		Postcondition:	return the value of len * wid in double type.		*/
	
	double CCircum();
	/*	calculating the circumference of the square.
		Postcondition:	return the value of 2*(len + wid) in double type.	*/

private:
	double len;
	double wid;
};



//#include "Square class Specification.h"