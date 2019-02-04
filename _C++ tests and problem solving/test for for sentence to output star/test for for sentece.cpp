/************************************************
This program is intended to output stars too,
while it uses for sentences.
And its original version(1.0.0) is:
print out RTtrangle madeup by star.dsw
************************************************/

//Comments: This is the old version of this program
//Version: 1.1.0
/*							//version using control

#include <iostream>

using namespace std;

int main()
{
	int line;				  //lines for stars
	cout << "Please input "
		 << "the number of "
		 << "lines we will "
		 << "output:" << endl;
	cin >> line;			  
	int i;					  //count for times
	int num(1);				  //stars every line
							  //contains
	for (i = 0; i < line; i++)
	{
		int count(1);
		while (count <= num)
		{
			cout << '*';
			count++;
		}
		num++;
		cout << endl;
	}
	return 0;
}

*/							//version using control

//***********************************************

//Comments: This is the new version of this program
//Version: 1.1.1
							//version using control

#include <iostream>

using namespace std;

int main()
{
	int line;				  //lines for stars
	cout << "Please input "
		 << "the number of "
		 << "lines we will "
		 << "output:" << endl;
	cin >> line;			  
	int i;					  //count for times
	int num(1);				  //stars every line
							  //contains
	for (i = 0; i < line; i++)
	{
		for (int count = 1;
			 count <= num;
			 count++)
			 {
				cout << '*';
			 }
		
		num++;
		cout << endl;
	}
	return 0;
}

  							//version using control