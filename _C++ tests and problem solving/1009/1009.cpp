#include <iostream>
#include <iomanip>		//set precision

using namespace std;

int main()
{
	double mP;			//monthlyPayment
	double sum(0);		//sum of payment
	double ave;			//average of payment

	for(int i(1); i <= 12; i++)
	{
		cin >> mP;
		sum += mP;
	}
	ave = sum / 12.0;
	cout << fixed << setprecision(2) 
		 << "гд" << ave << endl;
	return 0;
}

