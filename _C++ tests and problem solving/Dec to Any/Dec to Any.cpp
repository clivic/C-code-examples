#include "utility.h"
#include <stack>

void main()
//Purpose:	将十进制数N转换为r进制的数，其转换方法利用辗转相除法
//Pre:		Positive integers
//Post:		Corespoding hexidecimal numbers are output
//Uses:		The STL class stack and its methods, and utility package and its function UserSayYes()
{
	do
	{
		int n;
		int r;
		stack<int> numbers;  //  declares and initializes a stack of numbers
		cout << "Please input an decimal integer: " << flush;
		Cin(n);
		cout << "Then enter the calculator base(not exceeding 16): " << flush;
		Cin(r);

		while (r<1 || r>16)
		{
			cout << "Range error, please input the base again:" << flush;
			Cin(r);
		}
		
		cout << "Then the number in this base is: " << flush;
		
		if (r == 1)
			for (int i = 0; i < n; i++)
				cout << '0';

		else 
		{
			while (n)
			{
				numbers.push(n % r);
				n = n / r;
			}

			while (!numbers.empty())
			{
				char ch;
				/*switch (numbers.top())
				{
				case 0:		ch = '0';	break;
				case 1:		ch = '1';	break;
				case 2:		ch = '2';	break;
				case 3:		ch = '3';	break;
				case 4:		ch = '4';	break;
				case 5:		ch = '5';	break;
				case 6:		ch = '6';	break;
				case 7:		ch = '7';	break;
				case 8:		ch = '8';	break;
				case 9:		ch = '9';	break;
				case 10:	ch = 'A';	break;
				case 11:	ch = 'B';	break;
				case 12:	ch = 'C';	break;
				case 13:	ch = 'D';	break;
				case 14:	ch = 'E';	break;
				case 15:	ch = 'F';	break;
				}*/
				if (numbers.top() < 10) 	ch = numbers.top() + '0';
				else 						ch = numbers.top() + 'A' - 10;

				cout << ch;
				numbers.pop();
			}
		}
			cout << endl;
		cout << "Do you wanna continue? " << flush;
	} while (UserSayYes());
}