#include <stdio.h>
#include <iostream>
using  namespace std;

class Happy {
public:
	virtual void Happy1() {};
	virtual void Happy2() { int a = 0; };
	virtual void Happy3() {};
	virtual void Happy4() {};

};
void main() {
	Happy h1, h2;
	cout << &Happy::Happy1 << endl;
	cout <<  &Happy::Happy2<< endl;
}
//class Base
//{
//public:
//	Base() { cout << "b\n"; }
//	class Nest
//	{
//	public:
//		Nest() {
//			cout << "Nest\n";
//		}
//
//	};
//	Nest nest;
//};
//class Derive:public Base
//{
//public:
//	Derive() { cout << "d\n"; }
//	int ah() const { return 1; }
//};
//
//void main()
//{
//	/*char ch;
//	Derive obj;
//	cin >> ch;*/
//	char * str = new char[20];
//	delete[] str;
//}
//class X
//{
//	int myPrivate=5;
//	// Give OtherClass access
//	friend class A;
//};
//
//class A
//{
//	int test(X c) { c.myPrivate = 0; return c.myPrivate; } // allowed
//};
//
//class B :A{
//	void Happy()
//	{
//		X happy;
//		cout << A.test(happy);
//	}
//};