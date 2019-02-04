//*************************************************************************************************
//Driver for test
//*************************************************************************************************

#include <iostream>

using namespace std;

//function prototypes
char *strcat1(char *to, char *from);
char *strcpy(char *to, char *from);
void Swap(
	/* inout */ int* ptA,
	/* inout */ int* ptB);

int main()
{
	char s1[40];
	char s2[20];
	cin >> s1;
	cin >> s2;
	cout << strcat1(s1, s2) << endl; 

	int* p;
	int* q;
	int a = 5;
	int b = 9;
	p = &a;
	q = &b;
	cout << *p << endl;
	cout << *q << endl;
	Swap(p, q);
	cout << *p << endl;
	cout << *q << endl;


	return 0;
}
