#include <iostream>

using namespace std;

int main()
{
	int size;
	cin >> size;		//no greater than 30
	
	int mat[30][30];
	int row, col;
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
			cin >> mat[row][col];
	}

	int temp,			//current processor
		start(1);		//the start of column 
						//in each row
	for (row = 0; row < size; row++)
	{
		for (col = start; col < size; col++)
		{
			//exchange
			temp = mat[col][row];
			mat[col][row] = mat[row][col];
			mat[row][col] =temp;
		}
		start++;
	}
	
	//print and count
	int count(0);
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size - 1; col++)
		{
			cout << mat[row][col] << ' ';	
			if (mat[row][col] > 60)
				count++;
		}

		//to eliminate "type error"
		cout << mat[row][col];
		if (mat[row][col] > 60)
				count++;
		cout << endl;
	}
	cout << count << endl;

	return 0;
}

