/**************************************************************************************************
Timber Costs Calculation:
This program caculates the total cost of timbers purchased.
**************************************************************************************************/

#include <iostream>
#include <iomanip>				//for setprcision
#include <string>				//for print type of timber
using namespace std;

float Calculate(char, int, int, int, int); 
void OutPut(char, int, int, int, int, float);

int main()
{
	//variable declaration
	char ch;					//Timber's kind
	int num;					//number of pieces
	int width;					//inch
	int height;					//inch
	int len;					//foot
	static float sum(0);		//for the total money
	
	cout << "Enter item: ";
	cin >> ch;
	while (ch != 'T')
	{
		//each time money variable
		float current;

		//valid input protection
		while (ch != 'P' &&
			   ch != 'F' &&
			   ch != 'C' &&
			   ch != 'M' &&
			   ch != 'O')
		{
			cout << "Invalid input, please reinput them: ";
			cin >> ch;
		}

		cin >> num >> width >> height >> len;
		current = Calculate(ch, num, width, height, len);
		OutPut(ch, num, width, height, len, current);
		sum += current;
		cout << "Enter item: ";
		cin >> ch;
	}

	cout << "Total cost: $" << fixed << setprecision(2) << sum << endl;
	return 0;
}

//*************************************************************************************************

float Calculate(/* in */ char ch,
				/* in */ int num,
				/* in */ int width,
				/* in */ int height, 
				/* in */ int len)

/*	Calculate the money for a specific amount of timbers of one type bought
	Preconditions:	values are valid.
	Postconditions:	money is calculated.									*/
{	
	float money;
	float price;				//price for each type
	switch (ch)
	{
		case 'P':	price = 0.89;	break;
		case 'F':	price = 1.09;	break;
		case 'C':	price = 2.26;	break;
		case 'M':	price = 4.50;	break;
		case 'O':	price = 3.10;	break;
	}
	money = width / 12.0 * height * len * num * price;
	return money;
}

//*************************************************************************************************

void OutPut(/* in */ char ch,
 			 /* in */ int num,
			 /* in */ int width,
			 /* in */ int height, 
			 /* in */ int len,
			 /* in */ float money)
			 
/*	Output the information in a fomat.
	Preconditions:	values are valid.
	Postconditions: information is output.									*/
{
	string timber;				//type of timber
	switch (ch)
	{
		case 'P':	timber = "Pine";	break;
		case 'F':	timber = "Fir";		break;
		case 'C':	timber = "Cedar";	break;
		case 'M':	timber = "Maple";	break;
		case 'O':	timber = "Oak";		break;
	}
	cout << num << ' ' << width << '*' << height << '*' << len << ' ' << timber
		 << ", cost: $" << fixed << setprecision(2) << money << endl;
}


