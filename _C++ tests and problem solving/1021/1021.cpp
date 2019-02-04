#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;	
	while (getline(cin,str))
	{
		int index = 0;
		for (int i = 0; i < str.length(); i += 1)
		{
			int count = 0;
			if (str[i] == '(')
				index += 1;
			else if (str[i] == ')')
				index -= 1;
			else
				break;
		}
		cout << index << endl;
	}
	return 0;
}
