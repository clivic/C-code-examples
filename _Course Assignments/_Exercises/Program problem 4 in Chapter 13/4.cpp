/**************************************************************************************************
This program has been adapted to ACM. It doesn't read data from file but keyboard.
This format is relatively dumbed down (with much comments).
**************************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

typedef string DataType;

const int MAX_LENGTH = 100;

class List
{
public:

	List()
	{
	length = 0;
	}
	
	bool Isempty()
	{
	return (length == 0);
	}
	
	bool Isfull()
	{
	return (length == MAX_LENGTH);
	}	
	
	int  Length()
	{
	return length;
	}	
	
	void InsertOnce (/* in */	DataType item)
	{
		if (!Isfull() && !IsPresent(item))
		{
			data[length] = item;
			length++;
		}
	}

	void Delete		(/* in */	DataType item)
	{
		int i;
		for (i = 0; i < length; i++)
		{
			if (data[i] == item)
				break;
		}
	
		if (i < length)
		{
			data[i] = data[length - 1];
			length--;
		}
	}

	bool IsPresent	(/* in */	DataType item)
	{
		int i;
		for (i = 0; i < length; i++)
		{
			if (data[i] == item)
				break;
		}

		return (i < length);
	}
	
	void Print() const
	{
		int i;
		for (i = 0; i < length; i++)
		    cout << data[i] << endl;
	}

private:
	int length;
	int currentPos;
	DataType data[MAX_LENGTH];
};

//*************************************************************************************************

int main()
{
	int n;					//number of email
	string current;			//current string read in
	List list;
	
	//reading in
	cin >> n;
	for (int i(0); i < n; i++)
	{
		cin >> current;
		bool flag = false;	//flag judge @
		for (int i(0); i < current.length(); i++)
		{
			if (current[i] == '@')
			{
				flag = true;
				break;
			}
		}

		if (flag)
			list.InsertOnce(current);
	}
	
	//printing
	list.Print();

	return 0;
}
