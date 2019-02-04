/**************************************************************************************************
This program tests for the use of pure virtual function.
**************************************************************************************************/

#include <iostream>

using namespace std;

class Base2
{
private:
	int a;
public:
	void printBase2()	{ cout << "This is class Base2: printBase2.\n"; }
	virtual void vprint() = 0; //���麯��(һ�����T���Z��" = 0")
}; //������

class Derived2 : public Base2
{
private:
	int b;
public:
	void printBase2()	{ cout << "This is class Derived2: printBase2.\n"; } //overwrite Base2's method.
	void vprint()		{ cout << "This is class Derived2: virtual function vprint.\n"; }
	void others()		{ cout << "Others of class Derived2.\n"; }
};

//*************************************************************************************************
//Driver of this test(using pointer)
void main()
{
	//not allowed ����˵��������Ķ���
	//Base2 b;
	Base2 *p; //OK
	Derived2 d;
	//static compile
	d.printBase2();

	d.vprint();
	p = &d; //convert from Derived2 * to Base2 * 
	p->printBase2();

	//dynamic compile
	p = &d;
	p->vprint();//for there're no objects of class type Base2, p couldn't point b,
				//and vprint is so binded to derived class perhaps.
}
