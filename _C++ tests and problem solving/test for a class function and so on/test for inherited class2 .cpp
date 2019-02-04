/**************************************************************************************************
This program(2) test the inheritances, including public, private, protected.
**************************************************************************************************/
#include <iostream>

using namespace std;

class Father
{
protected:
	int a1;
private:
	int a2;
public:
	Father();
	void printFather();
	void printFather(Father & f);
};

//*************************************************************************************************

Father::Father()
{
	a1 = 1;
	a2 = 2;
}

void Father::printFather()
{
	cout << a1 << "   " << a2;
}

void Father::printFather(Father & f)
{
	cout << f.a1 << "   " << f.a2;
}

//*************************************************************************************************

class Child :public Father
{
protected:
	int b1;
private:
	int b2;
public:
	Child();
	void printChild();
	//void printFather(Father & f);		//不能訪問,當作外部命令
	void printChild(Child & c);
};

//*************************************************************************************************

Child::Child()
{
	b1 = 3;
	b2 = 4;
}

void Child::printChild()
{
	cout << "a1:" << a1 << "   ";
	//cout << "a2:" << a2 << "   ";		//a2访问失败，其权限为不可访问
	cout << "b1:" << b1 << "   ";
	cout << "b2:" << b2 << "   ";
}

void Child::printChild(Child & c)
{
	//在子类的实现中，允许通过子类对象访问保护成员
	cout << "a1:" << c.a1 << "   ";
	//cout << "a2:" << c.a2 << "   ";	//同理，通过对象访问也会失败
	cout << "b1:" << c.b1 << "   ";
	cout << "b2:" << c.b2 << "   ";
}

//*************************************************************************************************
//Driver of this test
/*void main()
{
	Father f1, f2;
	Child c1, c2;
	cout << endl << "Here is f1.printFather:" << endl;
	f1.printFather();
	cout << endl << "Here is f1.printFather(f2):" << endl;
	f1.printFather(f2);
	cout << endl << "Here is c1.printChild:" << endl;
	c1.printChild();
	cout << endl << "Here is c1.printChild(c2):" << endl;
	c1.printChild(c2);
	cout << endl << "Here is c1.printFather:" << endl;
	c1.printFather(f1);
	cout << endl << "Here is c1.printFather(f1):" << endl;
	c1.printFather(f1);
	cout << endl;
	//cout<<f1.a1;   cout<<f1.a2;
	//cout<<c1.a1;   cout<<c1.a2;
	//cout<<c1.b1;   cout<<c1.b2;
}*/

