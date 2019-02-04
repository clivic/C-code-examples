#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void main()
{
	string s("Rhodok and Swadia and Virgia");
	cout<<left<<setw(4)<<s.find_first_of("and")<<"are now in alliance.";
}
