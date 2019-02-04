#include <iostream>

using namespace std;

void Rectangle(int wid, int hei);

int main()
{
	int width, height;
	cout << "Please input the width and height of"
		 << " the rectangle in one line: ";
	cin >> width >> height;
	Rectangle(width, height);
	return 0;
}

//***********************************************

void Rectangle(int wid, int hei)
{
	int countW(1);	//count width
	int countH(1);	//count height
	
	for (; countH <= hei; countH++)
	{
		if (countH == 1 || countH == hei)
		{
			for(countW = 1; countW <= wid; countW++)
				cout << '*';
		}				
		else
			for(countW = 1; countW <= wid; countW++)
			{
				if (countW == 1 || countW == wid)
					cout << '*';
				else
					cout << ' ';
			}
		cout << endl;	//next line
	}
}
