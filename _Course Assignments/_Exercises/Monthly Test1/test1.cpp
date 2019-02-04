#include <iostream>
#include <string>

using namespace std;

const string s1 = "I saw the big brown bear.";
const string s2 = "The big brown bear saw me.";
const string s3 = "Oh! What a frighting experience!";
void main()
{
	cout << s1<<"\n"<<s2<<"\n"<<s3<<"\n"<<endl<<endl;
	cout << s1<<"\n"<<s3<<"\n"<<s2<<"\n"<<endl<<endl;
	cout << s2<<"\n"<<s1<<"\n"<<s3<<"\n"<<endl<<endl;
	cout << s2<<"\n"<<s3<<"\n"<<s1<<"\n"<<endl<<endl;
	cout << s3<<"\n"<<s1<<"\n"<<s2<<"\n"<<endl<<endl;
	cout << s3<<"\n"<<s2<<"\n"<<s1<<"\n"<<endl<<endl;
}
	
