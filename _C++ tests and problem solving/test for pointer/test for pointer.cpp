//*************************************************************************************************
//tests for the usage of pointer
//*************************************************************************************************

#include <iostream>
#include <cstring>
char *strCopy(char *to, char *from);
int S(char * s);

using namespace std;

//Module 1
void main()
{
	char  *ptr;
	ptr = new  char[5];

	//test if a cstring itself could represent an address
	//strCopy(ptr, "Bye");// 1. a literal string - it's considered the char array's address
	char str[] = "bye";
	strCopy(ptr, str);	  // 2. a cstring address
	ptr[1] = 'u';		  // a pointer can be subscripted
	cout << ptr[2];

	//test the deletion
	//delete ptr;			  // with out bracket
	delete[] ptr;			  // with bracket

	char* ptr1 = new char;
	*ptr1 = 'a';
	cout << *ptr1 << endl;
	delete[] ptr1;
	/*ptr = ptr1 = NULL;
	cout << endl << *ptr << endl;*/

	//test for variables defining the array size in dynamic array definition
	int a = 6;
	ptr = new char[a];
	strCopy(ptr, "Adios");
	cout << *ptr << endl;		// equals to *ptr[0] perhaps
	for (int i(0); i < 6; i++)
		cout << ptr[i];
	cout << endl;
	delete ptr;
	ptr = NULL;

	//test for pointers' comparision
	/*int* ptr2 = &a;
	bool cp = ptr > ptr2;		// comparision for different types, but not allowed*/

	//test for assign dynamic array values to another array
	a = 5;
	int *arr = new int[a];
	for (int i = 0; i < a; i++)
		arr[i] = i + 1;
	int arrNew[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	for (int i = 0; i < a; i++)
		arrNew[i] = arr[i];	
	for (int i = 0; i < 9; i++)	//cout
		cout << arrNew[i] << endl;

	//test for the availability of reference pointer
	//Char& *ptrR = ptr;			//not allowed
	char* &ptrR = ptr;				//ptrR represents ptr

	//test for result of the exercises in Chapter pointer
	//No.6
	char * s = "abcde";
	s += 2;   
	cout << s << endl;				//output "cde"

	//No.11
	char* k = "abcde";
	cout << S(k);
	


}

int S(char * s)
{
	char * p = s;
	while (*p)
	{
		p++;
	}
	return (p - s);
}