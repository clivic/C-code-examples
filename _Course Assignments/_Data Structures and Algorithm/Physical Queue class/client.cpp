//*******************************************************************
//	Test:	input and output
//*******************************************************************
#include "PQueue.h"
#include "PQueue.cpp"
int main()
{
	do
	{
		PQueue <int> q;
		cout << "Please input integers then press <Entry>, not integers to end:\n"
			<< flush;
		int n;
		while (cin >> n)
		{
			if (q.Append(n) == overflow) cout << "Queue full, losing numbers...\n"
				<< flush;
		}
		cout << "Then intergers you input are:\n" << flush;
		int item;
		while (!q.Empty())
		{
			if (q.ServeAndRetrieve(item) == underflow) cout << "Empty queue.\n"
				<< flush;
			cout << item << ' ';
		}
		cin.clear();
		cin.sync();
		cout << "Do you wanna continue ";
	} while (UserSayYes());
}