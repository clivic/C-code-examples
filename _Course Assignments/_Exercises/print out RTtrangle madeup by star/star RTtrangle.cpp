#include <iostream>

using namespace std;

void main()
{
	//Variable declaration
	int out(1), //number of rows
		in(1),  //number of stars in a row
		outLim; //how many rows
	bool state(1); //to control the input
	
	//Interactive input
	cout << "Please input the number of stars in each column and row below:" << endl
		 << "And notice there should be an interger in the range of 0 to 135." << endl;
	while (state)
	{
		cin >> outLim;
		state = 0; //to go ahead
		
		if (outLim <= 0)
		{
			cout << "The number of stars couldn't be below 0, please input it again:" << endl;
			state = 1; //couldn't let pass
		}
		else if (outLim > 135)
		{
			cout << "The number of stars is too large perhaps, so please input it again:"
				 << endl << "Range: 1 to 100." << endl;
			state = 1; //couldn't let pass
		}
	}

	//cout lines
	while (out <= outLim)
	{
		in = 1;
		while (in <= out)
		{
			cout << '*';
			in++;
		}
		cout << endl;
		out++;
	}
}
//for sentence by De ming Chu(only for 5 rows)	
/******************

  int main()
{
	int i, j;
	for (i = 1; i <= 5; i++)
	{
		for (j = i; j >0; j--)
			cout << '*';
		cout << endl;
	}
	return 0;
}
******************/


		