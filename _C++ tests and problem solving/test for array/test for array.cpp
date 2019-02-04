/**************************************************************************************************
This program tests the use of array.
**************************************************************************************************/

#include <iostream>

using namespace std;

void print(const int a);		//for test 3.

void printArray(int arr[],
				int size);		//for test 4.

void main()
{
	//1.test for "int num[0] declaration on page 470.
	//	int num[0];
	
	/* Result: complier doesn't allow. */

	//2.test for difference between num[1] && num on page 470.
	int num[1], a(5);			//size constant couldn't be negative or zero.
	num[0] = 1;
	//num = 1;					//assignment to entire array is not allowed.
	cout << num[0] << endl;
	cout << num << endl;		//it's the array's first elements's memory position.
	
	/* Result: above, "num = 1" is not allowed. We should write "num[0] = 1".
			   and we indeed can cout the entire array, but it is a mess code uha :)			 */
	
	//3.test for "const int& a" on page 470
	//print(3);					//compiler coudln't allow when building
	
	//4.test for passing an element to a function
	int arr[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	cout << arr[10] << endl;
	//printArray(arr[10], 10);		//it doesn't allow, only the entire array passed is permitted.
	
	//5.test for two denmensional declaration
	int two[2][5] = {
						{1,2,3,4,5},{6,7,8,9,0}					
					};
	for (int i(0); i < 5; i++)
		cout << '#' << i + 1 << ' ' << two[0][i] << endl;
	
	for (int j(0); j < 5; j++)
		cout << '#' << j + 6 << ' ' << two[1][j] << endl;
	
	//6.test for const array declaration
	const int arr1[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1};
	//const int arr2[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};		//not allowed for the const 
																//automatic variables should be
																//fully initialized
	//const int arr3[11];										//also not allowed for const object
																//must be initialized if not extern
	
	//7.test for string aggregate I/O (perhaps c-string)
	char str1[]="hello";										//way of declaring c-string array
	cout << str1 << endl;										//not an adress uha!
	char str2[5] = {'h', 'e', 'l', 'l', 'o'};
	//cout << str2 << endl;										//pass an adress perhaps
	char zero[] = {48, 48, 48, 48, 48, 48};
	//cout << zero << endl;										//also pass an adress perhaps
	for (i = 0; i < 5; i++)
		cout << str2[i];										//seperated cout
	cout << endl;
	
	//8.test for two-dimensional array's call -- only use one dimension like below:
	//two[0] = 1;												//this is not considered an address
	cout << two[0] << endl;	
	cout << two[1] << endl;	
	/*Result: an adress begins from two[2][0] perhaps uha...									 */
}

//result: this equals to two[2][5] = {1,2,3,4,5,6,7,8,9,0}

//*************************************************************************************************

void print(const int& a)
{
	//a = 6;					//This is not allowed to change the const reference	para.	
	cout << a << endl;
}

//*************************************************************************************************

void printArray(int arr[], int size)
{	
	for (int i(0); i < size; i++)
		cout << '#' << i + 1 << ' ' << arr[i] << endl;
}

