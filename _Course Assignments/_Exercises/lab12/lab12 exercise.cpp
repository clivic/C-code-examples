// Program Reverse reads numbers into an array
// and prints them out in reverse order.   

#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 10;

//Program 1 
/*
int main ()
{
    int  numbers[MAX];
    ifstream  inData;
    int  value;
    int  index;

    inData.open("reverse.dat");
    for (index = 0; index < MAX; index++)
    {
        inData >> numbers[index];
    }
    
    for (index = MAX - 1; index >= 0; index--)
	{
		value = numbers[index];
		cout << value << endl;
	}
	inData.close();
	inData.clear();

    return 0;
}
*/

//Program 2
/*int main ()
{
    int  numbers[MAX];
    ifstream  inData;
	int max, min, total(0), average(0); 

    inData.open("reverse.dat");

	//reading 'n' finding max
	inData >> numbers[0];
	max = numbers[0]; 
	for (int i(1); i < MAX; i++)
    {
        inData >> numbers[i];
		if (numbers[i] > max)
			max = numbers[i]; 
	}

	//find min
	min = numbers[0];
	for (i = 1; i < MAX; i++)
	{
		if (numbers[i] < min)
			min = numbers[i]; 
	}

	//find average
	for (i = 0; i < MAX; i++)
	{
		total += numbers[i];
	}
	average = (int) (float(total) / MAX + 0.5);
	return 0;
}*/

// Program Reverse reads numbers into an array
// and prints them out in reverse order.   


int main ()
{
    int  numbers[MAX]; ifstream  inData;  int  value;  int  index;

    inData.open("reverse.dat");
    for (index = 0; index < MAX; index++)
    {
        // FILL IN Code to read value // FILL IN Code to store value into numbers
        inData>>value;
       numbers[MAX-index-1] = value;
    }
    
   //如果数组的下标出现问题，打印的结果如何呢？ 
   for (index = MAX; index >= 0; index--)
        // FILL IN Code to write numbers on the screen
       cout<<"numbers["<<index<<"] = "<<numbers[index]<<endl;
    return 0;
}
