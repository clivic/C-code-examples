#include <iostream>

using namespace std;

int alpha = 3;
int beta = 20;

int main()
{
	 if (beta > 10)
	 {
	     int alpha = 5;		
         beta = beta + alpha;
	     cout << alpha << ' ' << beta << endl;
	 }
		  
	 cout << alpha << ' ' << beta << endl; 

	 return 0;
}

