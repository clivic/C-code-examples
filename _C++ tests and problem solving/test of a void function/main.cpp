/*******************************************************************************************************************************************
This program is to test whether a void funtion's block could be put behind main function. And how the void function other than void main fun-
ction works.
********************************************************************************************************************************************/

#include <iostream>

using namespace std;

void  DisplayMessage ( int  n ) ;	        // declares function

int main(  )
{    
      DisplayMessage( 15 ) ;	            //function call
                                                             // separate statement
              
	  cout  <<  "Good Bye"  <<    endl ;	 
		 
        return 0 ;
}
                                                             // header and body here

void  DisplayMessage ( int  n ) 
{
	cout  <<  "I have liked math for "  
		<<  n  <<  " years"  << endl ;
}
//This proves that functions could be put behind the main function. While the declaration should be ahead of main function. 


