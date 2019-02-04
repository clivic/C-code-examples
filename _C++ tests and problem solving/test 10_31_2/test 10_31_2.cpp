/************************************************
Problem B 10/31
************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
	int n(1);			//the current number
	int sum(0);			//initialize
	int max;			//the number input
	bool judge;			//judge if it is related to 7
	bool not;			//if not is true, skip while
	int i(0);			//10's power

	cin >> max;
	
	while (n <= max)
	{
		
		judge = false;
		i = 0;
		not = false;
		
		//judge whether could be divided by 7
		if (n % 7 == 0)	
		{
			judge = true;
			not = true;
		}
		
		//judge whether every digit is 7
		while ((pow(10, i) <= n) && not==0)
		{
							
			if ((n / int(pow(10, i))% 10 == 7))
			{
				judge = true;
				i++;
			}
			
			else 
				i++;
		}
		
		//sum
		if (!judge)
		{
			sum = sum + n * n;
			
		}
		n++;
	}
	cout << sum << endl;

				
	return 0;
}