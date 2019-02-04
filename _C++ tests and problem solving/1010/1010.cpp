#include <iostream>
#include <cctype>
#include <iomanip>

using namespace std;

int main()
{
	char ch;
	cin.get(ch);

	while (cin)
	{
	
		int count(0);
		float sum(0);
		bool judge(1);
		while (ch != '\n')
		{
			if (ch == 'A')
			{
				sum += 4;
				count++;
			}
			else if (ch == 'B')
			{
			sum += 3;
			count++;
			}
			else if (ch == 'C')
			{
				sum += 2;
				count++;
			}
			else if (ch == 'D')
			{
				sum += 1;
				count++;
			}
			else if (ch == 'F')
			{
				sum += 0;
				count++;
			}
			else if (isupper(ch))
			{		
				judge = 0;
				cin.ignore(100, '\n');
				break;
			}
		
			cin.get(ch);
		}
	
		if (judge == 1)
		{
			cout << fixed << setprecision(2) << sum / float(count) << endl;
		}
		else 
		{
			cout << "Unknown" << endl;
		}
	
		cin.get(ch);
	}

	return 0;
}
