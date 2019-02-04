//#include "utility.h"
//
//void main()
////Purpose:	将十进制数N转换为16进制的数，其转换方法利用辗转相除法
////Pre:		Positive integers
////Post:		Corespoding hexidecimal numbers are output
////Uses:		The STL class stack and its methods, and utility package and its function UserSayYes()
//{
//	do
//	{
//
//		int n;
//		int r;
//		stack<int> numbers;  //  declares and initializes a stack of numbers
//		cout << "Please input an decimal integer: " << flush;
//		cin >> n;
//		r = 16;				 //	16進制
//
//		while (n)
//		{
//			numbers.push(n % r);
//			n = n / r;
//		}
//		cout << "Then the number in Hexidecimal is: " << flush;
//		while (!numbers.empty())
//		{
//			char ch;
//			switch (numbers.top())
//			{
//			case 0:		ch = '0';	break;
//			case 1:		ch = '1';	break;
//			case 2:		ch = '2';	break;
//			case 3:		ch = '3';	break;
//			case 4:		ch = '4';	break;
//			case 5:		ch = '5';	break;
//			case 6:		ch = '6';	break;
//			case 7:		ch = '7';	break;
//			case 8:		ch = '8';	break;
//			case 9:		ch = '9';	break;
//			case 10:	ch = 'A';	break;
//			case 11:	ch = 'B';	break;
//			case 12:	ch = 'C';	break;
//			case 13:	ch = 'D';	break;
//			case 14:	ch = 'E';	break;
//			case 15:	ch = 'F';	break;
//			}
//			cout << ch;
//			numbers.pop();
//		}
//		cout << endl;
//	} while (UserSayYes());
//}