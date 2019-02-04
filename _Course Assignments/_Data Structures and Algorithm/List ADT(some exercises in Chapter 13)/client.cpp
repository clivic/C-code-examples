/**************************************************************************************************
This program is the client code.
**************************************************************************************************/

#include <iostream>
#include "list.h"

using namespace std;

int main()
{
	List list;
	DataType a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	list.InsertOnce(a);
	list.InsertOnce(b);
	list.InsertOnce(c);
	list.InsertOnce(d);
	list.InsertOnce(e);
	
	//output
	list.Reset();
	DataType outputTemp;
	int limit = list.Length();
	for (int i(0); i < limit - 1; i++)
	{
		outputTemp = list.Next();
		cout << outputTemp << ' ';
	}
		outputTemp = list.Next();
		cout << outputTemp;		//format
	cout << endl;
	
	DataType old1, new1, old2, new2;
	cin >> old1 >> new1 >> old2 >> new2;
	list.Replace(old1, new1);
	list.Replace(old2, new2);
	
	//output
	list.Reset();
	for (i = 0; i < limit - 1; i++)
	{
		outputTemp = list.Next();
		cout << outputTemp << ' ';
	}
		outputTemp = list.Next();
		cout << outputTemp;		//format
	cout << endl;

	return 0;
}

