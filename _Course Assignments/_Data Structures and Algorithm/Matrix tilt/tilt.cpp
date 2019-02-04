#include <iostream>

using namespace std;

//substring process
typedef Matrix[30][30];				

void Process(/* inout */ Matrix,
			 /* in */    int);

int main()
{
	int size;
	cin >> size;		//no greater than 30
	
	Matrix mat;
	int row, col;
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
			cin >> mat[row][col];
	}

	Process(mat, size);
	
	//print and count
	int count(0);
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			cout << mat[row][col];	//no space
			if (mat[row][col] > 60)
				count++;
		}
		cout << endl;
	}
	cout << count;

	return 0;
}

//***********************************************
void Process(/* inout */ Matrix mat,
			 /* in */    int size)
{
	int row, col,
		temp,			//current processor
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
}