/***********************************************************************************************************************************************************************************
This program is to excecute some of the programming warm-up excercises in Chapter3.
***********************************************************************************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

const float fahrenheit = 72.0;//For No.12

void main()
{
	//No.1
	cout<<"No.1"<<endl<<endl;
	int hours,minutes,seconds;
	cout<<"Please input number of hours:"<<endl;
	cin>>hours;
	cout<<"Please input number of minutes:"<<endl;
	cin>>minutes;
	cout<<"Please input number of seconds:"<<endl;
	cin>>seconds;
	cout<<"The time sumed up is "
		<<hours*3600+minutes*60+seconds
		<<" seconds."<<endl<<endl<<endl;


	//No.2
	cout<<"No.2 "<<endl<<endl;
	int days;
	cout<<"Please input number of days:"<<endl;
	cin>>days;
	cout<<"The number of whole week is: "
		<<days/7<<endl;
	cout<<"The number of remaining days except for whole weeks is: "
		<<days%7<<endl<<endl<<endl;  //(We had better use constant to stand for DAY_OF_WEEK.) 


	//No.3
	cout<<"No.3 "<<endl<<endl;
	int dollars,quarters,dimes,nickles,pennies;
	double money;
	dollars=2; quarters=3; dimes=13; nickles=25; pennies=89;
	money=100*dollars+25*quarters+10*dimes+5*nickles+pennies;
	cout<<"We assume there are 2 dollars 3 quarters 13 dimes 25 nickles and 89 pennies."
		<<"\n"<<"Then the total pennies are:"<<endl
		<<money<<" pennies"<<endl<<endl<<endl;

	//No.4
	cout<<"No.4 "<<endl<<endl;
	cout<<"That's to say there's $"<<float(money)/100.0<<endl<<endl<<endl;


	//No.6
	cout<<"No.6 "<<endl<<"This is a maths section"<<endl<<endl;
	cout<<"Please input x,y,a,b,c,d in the order:"<<endl;
	cout<<"And please notice c,d,x,y don't =0 and y is in (-1,1)"<<endl;
	double x,y,a,b,c,d;
	cin>>x>>y>>a>>b>>c>>d;
	cout<<"so:"<<endl
		<<"3x+y= "<<3*x+y<<endl
		<<"a^2+2b+c= "<<pow(a,2)+2*b+c<<endl
		<<"((a+b)/(c-d))(x/y)= "<<((a+b)/(c-d))*(x/y)<<endl
		<<"((a^2+2b+c)/d)/(xy)= "<<(pow(a,2)+2*b+c)/(d*x*y)<<endl
		<<"sqrt(abs(a-b))= "<<sqrt(fabs(a-b))<<endl
		<<"x^(-cos(y))= "<<pow(x,-cos(y))<<endl<<endl<<endl;


	//No.7
	string sentense="Claude and Tommy and Carl and Nico";
	cout<<"No.7 "<<endl<<"This task is to find 3 \"and\"'s "
		<<"position in the sentense:"<<endl
		<<"\"Claude and Tommy and Carl and Nico\"."<<endl;
	string::size_type first,second,third;
	first=sentense.find("and");
	second=sentense.substr(first+1,sentense.length()-first-1).find("and")+first+1;
	third=sentense.substr(second+1,sentense.length()-second-1).find("and")+second+1;
	cout<<"The first is in "<<first<<" position."<<endl
		<<"The second is in "<<second<<" position."<<endl
		<<"The third is in "<<third<<" position."<<endl<<endl<<endl;


	//No.8
	cout<<"No.8 "<<endl<<"This task is to find the position of middle "
		<<"name in the name \"Clivic T. Ravel\""<<endl;
	string name="Clivic T. Ravel";
	string::size_type startOfMiddle;
	startOfMiddle=1+name.find(" ");
	cout<<"The position is: "<<startOfMiddle<<"."<<endl<<endl<<endl;


	//No.9
	cout<<"No.9 "<<endl;
	money=669.99;
	cout<<"There are $"<<endl
		<<setw(8+6)<<fixed<<setprecision(2)<<money
		<<"dollars."<<endl<<endl<<endl;


	//No.10
	cout<<"No.10"<<endl;
	float distance=312.75;
	cout<<"There are "<<endl
		<<setw(15+6)<<fixed<<setprecision(5)<<distance
		<<"kilometres."<<endl<<endl<<endl;


	//No.11
	cout<<"No.11"<<endl;
	cout<<"Maximum of integer is: "<<INT_MAX<<"\n"
		<<"Minimum of integer is: "<<INT_MIN<<"\n"
		<<endl<<endl<<endl;

	//No.12
	cout<<"No.12"<<endl;
	float celsius;
	celsius = (fahrenheit-32.0)*5.0/9.0;//Please remember C=(F-32)*5/9
	cout<< "72.0 fahrenheit = "
		<<fixed << setprecision(1) << celsius
		<<" Celsius."<<endl;

}

//Please notice! The fuction function.length() could only be applied on string type value.