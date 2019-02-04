/**************************************************************************************************
This program tests for multi-inheritance.
**************************************************************************************************/
#include <iostream>

using namespace std;

class A
{
public:
	void setA(int);
	void showA();
private:
	int a;
};

class B
{
public:
	void setB(int);
	void showB();
private:
	int b;
};

//multi-inheritance
class C : public A, private B
{
public:
	void setC(int, int, int);
	void showC();
private:
	int c;
};

void A::setA(int x)
{
	a = x;
}

void B::setB(int x)
{
	b = x;
}

void C::setC(int x, int y, int z)
{//�������Աֱ�ӷ��ʻ���Ĺ��г�Ա
	setA(x);	 //������a = x
	setB(y);	 //������b = y
	c = z;
}

//*************************************************************************************************
//Driver of this test
/*void main()
{
	C obj;
	obj.setA(5);
	obj.showA();
	obj.setC(6, 7, 9);
	obj.showC();
	//obj.setB(6); //Error
	//obj.showB(); //Error
	//obj.showB(); //Error
}*/

/*	Class C's feature:
	public:	
		void setA(int);
		void showA();
		void setC(int, int, int);
		void showC();
	private:
		void setB(int);
		void showB();
		int c;
	inaccessible:
		int a;
		int b;
		
*/

