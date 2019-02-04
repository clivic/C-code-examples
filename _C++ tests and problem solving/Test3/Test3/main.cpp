#include <iostream>

using namespace std;

int main()
{
	int *p, a = 10, b = 1;
	p = &a; a = *p + b;
	printf("%d", a);
}