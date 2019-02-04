/**************************************************************************************************
This program tests for dynamic binding.
**************************************************************************************************/
#include <iostream>

using namespace std;

class Base
{
private:
	int a;
public:
	void printBase()	 { cout << "This is class Base: printBase.\n"; }
	virtual void vprint(){ cout << "This is class Base: virtual function vprint.\n"; }
};

class Derived : public Base
{
private:
	int b;
public:
	void printBase()	 { cout << "This is class Derived: printBase.\n"; }
	//overwrite Base's method.
	void vprint()		 { cout << "This is class Derived: virtual function vprint.\n"; }
	void others()		 { cout << "Others of class Derived.\n"; }
};

//*************************************************************************************************
//Driver of this test(using pointer)
/*void main()
{
	Base b, *p;
	Derived d;
	//static compile
	d.printBase();
	d.vprint();
	p = &b;				//point b
	p->printBase();		//equals b.printBase() perhaps
	p = &d;				//point d 
	p->printBase();		//without virtual direction, it could not execute d's printBase
						//for p is a Base class pointer.
	//p->others();		//not allowed, p is a Baseclass pointer.
	
	//dynamic compile
	p = &b;
	p->vprint();
	p = &d;
	p->vprint();
}*/

//This is another usage of virtual function appart from the book :)
//So up till now, two usages:
//	1.	global function which needs specific class parameters and then use class's virtual functions.
//	2.	pointer of a specific class