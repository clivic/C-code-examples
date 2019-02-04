//*******************************************************************
//	Test of String class
//*******************************************************************
#include "String.h"

//void main()
//{
//	char* strC = "Hello World!\0";
//	List <char> list;
//	for (int i = 0; i < 26; i++)
//		list.Insert(i, 'a' + i);
//	
//	String str1;					//NULL
//	String strHello(strC);			//cstr
//	String strAlphabet(list);		//list
//
//	cout << "str1: " << str1 << endl
//		<< "strHello: " << strHello << endl
//		<< "strAlphabet: " << strAlphabet << endl << endl;
//
//	cout << "Read in str1, please enter some characters:\n" << flush;
//	cin >> str1;
//	//str1 = ReadIn(cin);			//alternative cin
//	cout << "str1: " << str1 << endl;
//	//Write(str1);					//alternative cout
//	
//	cout << "Then let strHello == strAlphabet == str1." << endl;
//	strHello = strAlphabet = str1;
//	cout << "str1: " << str1 << endl
//		<< "strHello: " << strHello << endl
//		<< "strAlphabet: " << strAlphabet << endl
//		<< "They are identical." << endl << endl;
//
//	cout << "Restore them to defalut except str1." << endl;
//	strAlphabet.Clear();
//	strAlphabet = list;
//	strHello = strC;
//
//	bool yesOrNo;
//	cout << "For strAlphabet and strHello:\n";
//	cout << "== ? "; (strAlphabet == strHello) ? (yesOrNo = 1) : (yesOrNo = 0);	cout << yesOrNo << '\n';
//	cout << ">= ? "; (strAlphabet >= strHello) ? (yesOrNo = 1) : (yesOrNo = 0);	cout << yesOrNo << '\n';
//	cout << "<= ? "; (strAlphabet <= strHello) ? (yesOrNo = 1) : (yesOrNo = 0);	cout << yesOrNo << '\n';
//	cout << "!= ? "; (strAlphabet != strHello) ? (yesOrNo = 1) : (yesOrNo = 0);	cout << yesOrNo << '\n';
//	cout << "< ? "; (strAlphabet < strHello) ? (yesOrNo = 1) : (yesOrNo = 0);	cout << yesOrNo << '\n';
//	cout << "> ? "; (strAlphabet > strHello) ? (yesOrNo = 1) : (yesOrNo = 0);	cout << yesOrNo << endl;
//
//	cout << "str1 + strHello:\n"
//		<< str1 + strHello << endl << endl;
//
//	cout << "str1 += strHello:" << endl;
//	cout << *Strcat(str1, strHello) << endl << endl;
//	//cout << (str1 += strHello) << endl << endl;
//	
//	String substr;
//	cout << "str1: " << str1 << endl;
//	
//	do
//	{
//		cin.clear();
//		cin.sync();
//		cout << "Please input a string you wanna find in str1:" << endl;
//		cin >> substr;
//		//cout << "Found?\t"; (Strstr(str1, substr) >= 0) ? (yesOrNo = 1) : (yesOrNo = 0);	cout << yesOrNo << endl;
//		cout << "Found?\t"; (str1.Find(substr) >= 0) ? (yesOrNo = 1) : (yesOrNo = 0);	cout << yesOrNo << endl;
//		if (yesOrNo)
//			cout << "Pos:\t" << Strstr(str1, substr) << endl;
//		cout << "Do you wanna continue? " << flush;
//	} while (UserSayYes());
//	
//	
//	cout << "strHello now is assigned to str1:" << endl;
//	Strcpy(str1, strHello);
//	cout << str1 << endl << endl;
//
//	cout << "Test over." << endl;
//		 
//}

//void main()
//{
//	String s = "abc";
//	const char* newCh = s.c_str();
//	s = "def";
//	cout << newCh << endl;
//}

void main()
{
	//initialization
	char* strC = "Hello World!\0";
	List <char> list;
	for (int i = 0; i < 26; i++)
		list.Insert(i, 'a' + i);

	String str1;
	String strHello(strC);

	cout << "str1: " << str1 << endl
		<< "strHello: " << strHello << endl;

	//test for Strcpy
	Strcpy(str1, strHello);
	cout << "Copy strHello to str1:\n"
		<< "str1: " << str1 << endl;

	//test for Strncpy
	Strncpy(str1, strHello, 5);
	cout << "Copy the first 5 characters\n"
		<< "in strHello to str1:\n"
		<< "str1: " << str1 << endl;

	//test for Strstr
	bool yesOrNo;
	String substr;
	do
	{
		cin.clear();
		cin.sync();
		cout << "Please input a string you wanna find in str1:" << endl;
		cin >> substr;
		cout << "Found?\t"; (str1.Find(substr) >= 0) ? (yesOrNo = 1) : (yesOrNo = 0);
		cout << yesOrNo << endl;
		if (yesOrNo)
			cout << "Pos:\t" << Strstr(str1, substr) << endl;
		cout << "Do you wanna continue? " << flush;
	} while (UserSayYes());
	cout << str1 << endl << endl;
	cout << "Test over." << endl;
}

