/*******************************************************************************************************
This program is intended to calculate the volume of the corn, given the diametres and the heights of it.
*******************************************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

void main()
{
	//No.1
	
	double R,h,d,pai;
	pai=3.1415926535897897932384626;
	cout<<"No.1: "<<endl<<endl;
	cout<<"Please input the diametre of the corn: "<<endl;
	cin>>d;
	R=d/2;
	cout<<"Please input the height of the corn: "<<endl;
	cin>>h;
	cout<<"Then the volume of the corn is: "
		<<fixed<<setprecision(6)<<pai*pow(R,2)*h/3<<endl
		<<endl<<endl;


	//No.2
	
	int x1,x2,x3,x4;
	float xbar;
	cout<<"No.2: "<<endl<<endl;
	cout<<"Please input x1, x2, x3, x4 in order "
		<<"meanwhile remember they should be integers."
		<<endl;
	cin>>x1>>x2>>x3>>x4;
	xbar=(float(x1+x2+x3+x4))/4.0f;
	cout<<"Then the mean of four values is: "<<fixed
		<<setprecision(2)<<xbar<<endl;
	cout<<"And the standard deviation is: "
		<<sqrt((pow((float(x1)-xbar),2)+pow((float(x2)-xbar),2)
		  +pow((float(x3)-xbar),2)+pow((float(x4)-xbar),2))/3.0f)
		<<endl<<endl<<endl;
	

	//No.3

	double direct,approximation;
	direct=double(15*14*13*12*11*10*9*8*7*6*5*4*3*2*1);
	approximation=exp(-15.0)*pow(15.0,15.0)*sqrt(2.0*pai*15.0);
	cout<<"No.3: "<<endl<<endl;
	cout<<"The exact value of 15! is: "<<fixed<<setprecision(5)<<direct<<endl
		<<"The approximate value of 15! according to Stirling's formula is: "
		<<approximation<<endl<<endl<<endl;


	//No.4
	//(assuming) it requires us to output 18C3*15C3*12C3*9C3*6C3, then

	double c18,c15,c12,c09,c06,all;
	c18=18*17*16/3/2/1;
	c15=15*14*13/3/2/1;
	c12=12*11*10/3/2/1;
	c09=9*8*7/3/2/1;
	c06=6*5*4/3/2/1;
	all=c18*c15*c12*c09*c06;
	cout<<"No.4: "<<endl<<endl;
	cout<<"The required result may be: "<<all<<endl<<endl<<endl;
	//The expression isn't objective or proper can't be verified...sorry...


	//No.5
	//It begins with the name "John Jacob Schmidt".

	string first,last,middle,name;
	name="John Jacob Schmidt";
	first=name.substr(name.find("John"),4);
	middle=name.substr(name.find("Jacob"),5);
	last=name.substr(name.find("Schmidt"),7);
	cout<<"No.5: "<<endl<<endl;
	cout<<"First name: "<<first<<endl;
	cout<<"middle name: "<<middle<<endl;
	cout<<"last name: "<<last<<endl<<endl<<endl;

	//No.6
	cout<<"No.6: "<<endl<<endl;
	cout<<"First name: "<<first<<"\t"<<"\t"<<"length: "<<"4."<<endl;
	cout<<"middle name: "<<middle<<"\t"<<"\t"<<"length: "<<"5."<<endl;
	cout<<"last name: "<<last<<"\t"<<"\t"<<"length: "<<"7."<<endl<<endl<<endl;




}
