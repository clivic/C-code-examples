#include <stack>
#include <iostream>

using namespace std;

void main()
{
	stack <int> s;
	int num;
	bool input = true;
	cout << "Please input integers in increasing sequence, "
		 << "and stop as soon as decreasing order.\n" << flush;
	cin >> num;
	s.push(num);

	while (input)
	{
		cin >> num;
		if (s.top() >= num)
			input = false;
		else
			s.push(num);
	}
	
	cout << endl << "Then the decending order is:\n" << flush;
	
	while(!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
	cout << endl;
}