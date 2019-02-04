//*******************************************************************
//	convert Decimal numbers to Octal and Hexidecimal numbers
//	Note: Oct numbers are integers while Hex numbers are string 
//*******************************************************************
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int i = 0;

int ConvOct(int n)
{

	if (n / 8 == 0)
	{
		return (n % 8) * pow(10, i);
	}
	else
	{
		i += 1;
		return (n % 8) * pow(10, i - 1) + ConvOct(n / 8);

	}

}

//*******************************************************************

string ConvHex(int n)
{
	ostringstream sout;
	string str, strR;
	bool isminus = false;

	//deal with negative numbers
	if (n < 0)
	{
		n *= -1;
		isminus = true;
	}
	//convert
	while (n / 16 != 0)
	{
		if (n % 16 < 10)
			sout << (char)(n % 16 + '0');
		else if (n % 16 == 10)
			sout << 'a';
		else if (n % 16 == 11)
			sout << 'b';
		else if (n % 16 == 12)
			sout << 'c';
		else if (n % 16 == 13)
			sout << 'd';
		else if (n % 16 == 14)
			sout << 'e';
		else if (n % 16 == 15)
			sout << 'f';
		n /= 16;
	}
	if (n < 10)
		sout << (char)(n + '0');
	else if (n == 10)
		sout << 'a';
	else if (n == 11)
		sout << 'b';
	else if (n == 12)
		sout << 'c';
	else if (n == 13)
		sout << 'd';
	else if (n == 14)
		sout << 'e';
	else if (n == 15)
		sout << 'f';

	if (isminus == true)
		sout << '-';

	//reverse
	str = strR = sout.str();
	for (int i = strR.length() - 1; i >= 0; i--)
		str[strR.length() - 1 - i] = strR[i];
	return str;
}


int main()
{
	int n = 8;
	int num;
	for(int count = 0; count < n; count++)
	{
		cin >> num;
		cout << ConvOct(num) << ' ';
		i = 0;		//have to exist
		cout << ConvHex(num) << endl;
	}
	return 0;
}