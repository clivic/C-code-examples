//	P182 E4 a)
#include "utility.h"

int AckermannR(int a, int b);
int AckermannI(int a, int b);
void Introduction();
void Instruction();

void main()
{
	int a, b;
	Introduction();
	do
	{
		Instruction();
		Cin(a);	Cin(b);
		cout << "The result is: "
			<< AckermannR(a, b) << endl;
		cout << "Do you wanna continue? " << flush;
	} while (UserSayYes());
}

void Introduction()
{
	cout << "AckermannR function used in recursion implementation." << endl;
}

void Instruction()
{
	cout << "Please input two numbers a, b:" << endl;
}

int AckermannR(int a, int b)
{
	if (a == 0)	return ++b;
	if (b == 0)	return AckermannR(a - 1, 1);
	return AckermannR(a - 1, AckermannR(a, b - 1));
}

