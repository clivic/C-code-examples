#include <iostream>
#include <cctype>

using namespace std;

float RunningAvg(float);

int main()
{
	float value;
	do
	{
		cin >> value;
		cout << "average: " 
			 << RunningAvg(value) << '\n';
	}while(value != -10000000);
		return 0;
}

//***********************************************

float RunningAvg(float value)
{
	static float sum(0);
	static float count(1);
	sum += value;
	float avg;
	avg = sum / count;
	count++;
	return avg;
}