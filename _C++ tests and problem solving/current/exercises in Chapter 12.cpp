#include <iostream>
#include <string>

using namespace std;

const int EACH_GROUP(5);
const int NUMBER_OF_SETS(3);

//No.2
typedef float DataSet[EACH_GROUP];

//Equal function's prototype
bool Equal(/* in */ const DataSet first, 
		   /* in */ const DataSet second);

void main()
{
	//No.2
	DataSet input, output, working;

	//No.3
	DataSet set[NUMBER_OF_SETS];

	//No.4
	for (int outer(0); outer < NUMBER_OF_SETS; outer++)
	{
		for (int inner(0); inner < EACH_GROUP; inner++)
		{
			set[outer][inner] = 0;
		}
	}

	//test for Equal function
	for (int i(0); i < EACH_GROUP; i++)
		input[i] = 1.0f;
	for (int j(0); j < EACH_GROUP; j++)
		output[i] = 2.0f;
	if (Equal(input, output))
		cout << "They're equal.\n";
	else
		cout << "They're inequal.\n";
}

//*************************************************************************************************

//No.5
bool Equal(/* in */ const DataSet first,		//not DataSet first[] please notice ! :)
		   /* in */ const DataSet second)
//No.6
{
	for (int count(0); count < EACH_GROUP; count++)
		if (!(first[count] == second[count]))
			return false;
	return true;
}
