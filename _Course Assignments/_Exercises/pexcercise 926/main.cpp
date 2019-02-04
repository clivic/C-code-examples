#include <iostream>
#include <string>

using namespace std;


void main()
{
	int a,b,c,d;
	float f1,f2,f3,f4;
	a=-2;
	b=2;
	c=3;
	d=a*b+c%b;
	cout << a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<"\n";
	f1=f2+f3*f4;
	cout << f1<<"\t"<<f2<<"\t"<<f3<<"\t"<<f4<<"\t"<<"\n";
	f1=f2=f3=f4=5.0;
	f1=f2+f3+f4;
	cout << f1<<"\t"<<f2<<"\t"<<f3<<"\t"<<f4<<"\t"<<"\n";
}


