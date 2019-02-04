#include "String.h"

String::String()
{
	entries = new char[1];
	entries[0] = '\0';
	length = 0;
}

String::String(const char *copy)
//	Pre:	The pointer copy references a C-string.
//	Post:	The String is initialized by the C-string copy.
{
	length = Strlen(copy);
	entries = new char[length + 1];
	for (int i = 0; i < length; i++) entries[i] = copy[i];
	entries[length] = '\0';
}

String::String(List<char> &copy)
//	Post:	The String is initialized by the character List copy.
{
	length = copy.Size();
	entries = new char[length + 1];
	for (int i = 0; i < length; i++) copy.Retrieve(i, entries[i]);
	entries[length] = '\0';
}

void String::Clear()
//	Post:	Reset the entries containing \0.
{
	delete[] entries;
	entries = new char[1];
	entries[0] = '\0';
	length = 0;
}

const char* String::c_str() const
{
	return (const char*)entries;
}

int String::GetLen() const
//	Post:	The function returns the length of the string, not including
//			the null byte¡®\0¡¯at the end of the string.
{
	return Strlen(entries);
}

char &String::operator[] (const int &n) const
//	Pre:	n should be in [0, length - 1].
//	Post:	Return the character in position n if n is in [0, length - 1],
//			else return '\0'.
{
	if (n < length && n >= 0)
		return entries[n];
	return entries[length];		//return '\0'
}

//safety guards
String::~String()
{
	delete[] entries;		//P120 knowledge on Data Structure book
}

String::String(const String &copy)
//	Post:	The String is initialized by the String copy.
{
	length = copy.length;
	entries = new char[length + 1];
	for (int i = 0; i < length; i++) entries[i] = copy.entries[i];
	entries[length] = '\0';
}

const String& String:: operator = (const String &copy)
//	Post:	The String is assinged to the String copy.
{
	if (this == &copy)	return copy;
	delete[] entries;
	length = copy.length;
	entries = new char[length + 1];
	for (int i = 0; i < length; i++) entries[i] = copy.entries[i];
	entries[length] = '\0';
	return *this;
}

//*******************************************************************
//cstring functions
char *Strcpy(char *to, const char *from)
//	Pre:	The string from has been initialized.
//	Post:	The function copies string from to string to, including¡®\0'.
//			It returns a pointer to the beginning of the string to.
{
	int i;
	for (i = 0; from[i] != '\0'; i++)
		to[i] = from[i];
	to[i] = '\0';
	return to;
}

char *Strncpy(char *to, const char *from, int n)
//	Pre:	The string from has been initialized.
//	Post:	The function copies the first n characters in string from 
//			to string to and returns a pointer to the beginning of the
//			string to.
{
	int i;
	for (i = 0; i < n; i++)
		to[i] = from[i];
	to[i] = '\0';
	return to;
}

int Strlen(const char *s)
//	Pre:	The string s has been initialized.
//	Post:	The function returns the length of the string s, not including
//			the null byte¡®\0¡¯at the end of the string s.
{
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}

char *Strcat(char *to, const char *from)
//	Pre:	The strings from and to have been initialized.
//	Post:	The function copies string from to the end of string to, including¡®\0'. 
//			It returns a pointer to the beginning of the string to.
{
	int lenTo = Strlen(to);
	int i;
	for (i = 0; from[i] != '\0'; i++)
		to[lenTo + i] = from[i];
	to[lenTo + i] = '\0';
	return to;
}

int Strcmp(const char *s1, const char *s2)
//	Pre:	The strings s1 and s2 have been initialized.
//	Post:	The function compares string s1 to string s2. 
//			It returns -1 if s1 < s2, 0 if s1 == s2, or 1 if s1 > s2.
{
	int i = 0;
	for (; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] > s2[i])	return 1;
		if (s1[i] < s2[i])	return -1;
	}
	return 0;
}

const char *Strstr(const char *&s1, const char *&s2)
//	Pre:	The strings s1 and s2 have been initialized.
//	Post:	The function returns a pointer to the first occurrence of the 
//			string s2 in the string s1, or it returns NULL if the string s2
//			is not present in s1.
{
	int len1 = Strlen(s1);
	int len2 = Strlen(s2);
	for (int i = 0; i <= len1 - len2; i++)
	{
		if (s1[i] == s2[0])
		{
			char *temp = new char[len2 + 1];
			Strncpy(temp, s1+i, len2);
			if (Strcmp(temp, s2) == 0)
			{
				delete[] temp;
				return s1 + i;
			}
		}
	}
	return NULL;
}

//*******************************************************************
//String Library functions
bool operator == (const String &first, const String &second)
//	Post:	IF the String first agrees with String second, return true.
//			Else Return false.
{
	return Strcmp(first.c_str(), second.c_str()) == 0;
}

bool operator > (const String &first, const String &second)
//	Post:	IF	the String first is greater than String second in 
//				lexicographic order, return true.
//			Else Return false.
{
	return Strcmp(first.c_str(), second.c_str()) > 0;
}

bool operator >= (const String &first, const String &second)
//	Post:	IF	the String first is greater than or equal to 
//				String second in lexicographic order, return true.
//			Else Return false.
{
	return Strcmp(first.c_str(), second.c_str()) >= 0;
}

bool operator < (const String &first, const String &second)
//	Post:	IF	the String first is less than String second in 
//				lexicographic order, return true.
//			Else Return false.
{
	return Strcmp(first.c_str(), second.c_str()) < 0;
}

bool operator <= (const String &first, const String &second)
//	Post:	IF	the String first is less than or equal to 
//				String second in lexicographic order, return true.
//			Else Return false.
{
	return Strcmp(first.c_str(), second.c_str()) <= 0;
}

bool operator != (const String &first, const String &second)
//	Post:	IF	the String first is not equal to String second 
//				in lexicographic order, return true.
//			Else Return false.
{
	return Strcmp(first.c_str(), second.c_str()) != 0;
}

String operator + (String s1, const String &s2)
//	Post:	The function is almost identical to the function Strcat,
//			but to return a String rather than an address, and doesn't 
//			modify both of the String s1 and s2.
{
	return *Strcat(s1, s2);
}

String operator += (String &s1, const String &s2)
//	Post:	The function is almost identical to the function Strcat 
//			and operator +, but it returns a String rather than an address.
{
	
	return *Strcat(s1, s2);
}

istream &operator >> (istream &input, String &str)
{
	str = ReadIn(input);
	return input;
}

ostream &operator << (ostream &output, const String &str)
{
	output << str.c_str() << flush;
	return output;
}

String ReadIn(istream &input)
//	Post:	Return a String read (as characters terminated by a newline or an end-of-file
//			character) from an istream parameter.
{
	List<char> temp;
	int size = 0;
	char c;
	while ((c = input.peek()) != EOF && (c = input.get()) != '\n')
		temp.Insert(size++, c);
	String answer(temp);
	return answer;
}

void Write(const String &s)
//	Post:	The String parameters is written to cout.
{
	cout << s.c_str() << flush;;
}

String* Strcpy(String &to, const String &from)
//	Post:	The function copies String from to the String to, and returns the 
//			address of String to.
{
	const char *cFrom = from.c_str();
	char *copy = new char[Strlen(cFrom) + 1];
	Strcpy(copy, cFrom);
	to.entries = copy;			//friend
	copy = NULL;
	return &to;
}

String* Strcat(String &addTo, const String &addOn)
//	Post:	The function concatenates String add_on onto the end of String add_to, 
//			and returns the address of String addTo.
{
	const char *cfirst = addTo.c_str();
	const char *csecond = addOn.c_str();
	char *copy = new char[Strlen(cfirst) + Strlen(csecond) + 1];
	Strcpy(copy, cfirst);
	Strcat(copy, csecond);
	addTo = copy;
	delete[] copy;
	return &addTo;
}

int Strstr(const String &text, const String &target)
//	Post:	The function returns a position(0 ~ Strlen(text)) of the 
//			head character of the first occurrence of the string target 
//			in the string text, or it returns -1 if the string target 
//			is not present in text.
{
	const char *ctext = text.c_str();
	const char *ctarget = target.c_str();
	const char *tmp = Strstr(ctext, ctarget);
	if (tmp == NULL)	return	-1;
	else return(tmp - ctext);
}

String Substr(const String &target, int n)
//	Post:	return the substring of the string target of length n.
{
	const char *ctarget = target.c_str();
	char *sub = new char[Strlen(ctarget)];
	return Strncpy(sub, ctarget, n);
}

int Strlen(const String& s) 
//	Post:	The function returns the length of the string s, not including
//			the null byte¡®\0¡¯at the end of the string s.
{
	return s.GetLen();
}
