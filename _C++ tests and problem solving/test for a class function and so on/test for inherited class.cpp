/**************************************************************************************************
This program(1) test the inheritances, including public, private, protected.
**************************************************************************************************/
#include <iostream>

using namespace std;

class baseClass 
{
private:
	int privData;
protected:
	int protData;
public:
	int publData;
};

//public inheritance
class publDrvClass : public baseClass 
{
public:
	void usebaseClaData() 
	{
		publData = 11;		//OK!
		protData = 12;   	//OK!
//		privData = 13;   	//ERROR!
	}
};

class claD21 : public publDrvClass 
{
public:
	void usebaseClaData() 
	{
		publData = 111;    	//OK!
		protData = 121;   	//OK!
//		privData = 131;   	//ERROR! 
	}
};

//protected inheritance
class protDrvClass : protected baseClass 
{
public:
	void usebaseClaData() 
	{
		publData = 21;		//OK!
		protData = 22;   	//OK!
//		privData = 23;   	//ERROR!
	}
};

class claD22 : public protDrvClass 
{
public:
	void usebaseClaData()
	{
		publData = 211;    	//OK!
		protData = 221;   	//OK!
//		privData = 231;   	//ERROR!
	}
};

//private inheritance
class privDrvClass : private baseClass 
{
public:
	void usebaseClaData() 
	{
		publData = 31;     	//OK!
		protData = 32;    	//OK!  
//		privData = 33;    	//ERROR! 
	}
};

class claD23 : public privDrvClass 
{
public:
	void usebaseClaData()
	{
//		publData = 311;    	//ERROR!
//		protData = 321;   	//ERROR!
//		privData = 331;   	//ERROR!
	}
};

//*************************************************************************************************
//Driver of this test
/*void main() 
{
	baseClass ob0;
	ob0.publData = 1;   	//OK! 
	ob0.protData = 2;   	//ERROR!
	ob0.privData = 3;   	//ERROR!
	claD21 d21;
	claD22 d22;
	claD23 d23;
	d21.publData = 4;    	//OK!
	d21.protData = 5;   	//ERROR!  
	d21.privData = 6;   	//ERROR! 
	d22.publData = 7;    	//ERROR! 
	d22.protData = 8;   	//ERROR!
	d22.privData = 9;   	//ERROR! 
	d23.publData = 7;    	//ERROR!
	d23.protData = 8;   	//ERROR! 
	d23.privData = 9;   	//ERROR!
}*/
