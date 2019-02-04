//*******************************************************************
//	test for void function (pure void function)
//*******************************************************************
#include <iostream>

using namespace std;

class base
{
	int a;
public:
	void printbase(){cout<<"This is class base: printbase.\n";}
	virtual void vprint()=0; //pure void function
}; //abstract class

//*******************************************************************

class derived: public base
{
	int b;
public:
	void printbase(){cout<<"This is class derived: printbase.\n";} //overwrite base's method.
	void vprint(){cout<<"This is class derived: virtual function vprint.\n";}
	void others(){cout<<"Others of class derived.\n";}
};

//*******************************************************************

void main()
{
	//not allowed -- can't define an object of a class containg pure void function.
	//base b;
	base *p;
	derived d;
	
	//static compile
	d.printbase();
	d.vprint();
	p=&d;			//convert from derived * to base * 
	p->printbase();

	//dynamic compile
	p->vprint();
}
