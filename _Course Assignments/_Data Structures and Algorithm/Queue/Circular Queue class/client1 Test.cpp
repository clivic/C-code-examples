//*******************************************************************
//	Test1:	input and output
//*******************************************************************
#include "Queue.h"
#include "Queue.cpp"
//int main()
//{
//	do
//	{
//		Queue <int> q;
//		cout << "Please input integers then press <Entry>, not integers to end:\n"
//			<< flush;
//		int n;
//		while (cin >> n)
//		{
//			if (q.Append(n) == overflow) cout << "Queue full, losing numbers...\n"
//				<< flush;
//		}
//		cout << "Then intergers you input are:\n" << flush;
//		//	method 1
//		int item;
//		while (!q.Empty())
//		{
//			if (q.ServeAndRetrieve(item) == underflow) cout << "Empty queue.\n"
//				<< flush;
//			cout << item << ' ';
//		}
//
//		//	method 2
//		/*q.Print();
//		cin.clear();
//		cin.sync();
//		cout << "Do you wanna continue ";*/
//	} while (UserSayYes());
//}