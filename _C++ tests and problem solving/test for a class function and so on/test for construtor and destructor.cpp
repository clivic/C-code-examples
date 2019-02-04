/**************************************************************************************************
This program tests the constructor and destructor and their calling sequence.
**************************************************************************************************/

#include "iostream"

using namespace std;



class base
{
public:
	base();
	~base();
};

base::base()
{
	cout << "base construction!" << endl;
}

base::~base()
{
	cout << "base destruction!" << endl;
}

//*************************************************************************************************

class self : public base
{
public:
	self();
	~self();
};

self::self()
{
	cout << "self construction!" << endl;
}

self::~self()
{
	cout << "self destruction!" << endl;
}

//*************************************************************************************************

class child : public self
{
public:
	child();
	~child();
};

child::child()
{
	cout << "child construction!" << endl;
}

child::~child()
{
	cout << "child destruction!" << endl;
}

//*************************************************************************************************
//Driver of this test
/*void main()
{
	child c;
}*/
