#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void main()
{
	string phrase;
	phrase="The cat and the mouse";
	string::size_type a ;
	a=phrase.find("rat");
	cout<<(a)<<endl;
	phrase="programming and solving in c++";
	cout<<phrase.substr(4,53)<<"\n";
	char ch='@';
	cout<<setw(3)<<'@'<<endl;

}
