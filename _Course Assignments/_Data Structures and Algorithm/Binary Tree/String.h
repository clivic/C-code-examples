//*******************************************************************
//	String Class specification
//	Version: 1.0
//	General introduction:
//		It's a string class different from the STL and included in 
//		the Utility package. Till now it hasn't had as many methods
//		as the STL string class and has its methods capitalized in 
//		the first letter. As the STL methods in <string.h> are 
//		automatically added to any program in VS2013, so please 
//		don't be confused with the methods like strstr() and Strstr().
//	Note:	using "Utility"'s utility .h and .cpp
//*******************************************************************
#ifndef STRING
#define STRING
#include "List.h"

class String
{
public: // methods of the string ADT
	String();
	String(const char *copy);		//conversion from C-string
	String(List<char> &copy);		//conversion from List
	void Clear();
	const char *c_str() const;		//conversion to C-style string
	int GetLen() const;
	char &operator[] (const int &n) const;

	//safety guards
	~String();
	String(const String &copy);		//copy constructor
	const String& operator = (const String &copy);

	//friend function
	friend String* Strcpy(String &to, const String &from);
	
protected:
	char *entries;
	int length;
};

//cstring functions
char *Strcpy(char *to, const char *from);
char *Strncpy(char *to, const char *from, int n);
int Strlen(const char *s);
char *Strcat(char *to, const char *from);
int Strcmp(const char *s1, const char *s2);
const char *Strstr(const char *&s1, const char *&s2);

//String Library functions
bool operator == (const String &first, const String &second);
bool operator > (const String &first, const String &second);
bool operator < (const String &first, const String &second);
bool operator >= (const String &first, const String &second);
bool operator <= (const String &first, const String &second);
bool operator != (const String &first, const String &second);
String operator + (String s1, const String &s2);
String operator += (String &s1, const String &s2);

istream &operator >> (istream &input, String &str);
ostream &operator << (ostream &output, const String &str);
String ReadIn(istream &input);
void Write(const String &s);

String* Strcpy(String &to, const String &from);
String* Strcat(String &addTo, const String &addOn);
int Strstr(const String &text, const String &target);
String Substr(const String &target, int num);
int Strlen(const String& s);

#endif