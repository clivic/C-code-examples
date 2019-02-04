//*************************************************************************************************
//	driver for test the chain list
//*************************************************************************************************

#include"MobchList.h"
#include <iostream>

using namespace std;

void ModifyName(ChainList& m);
void ModifyNum(ChainList& m);
void Delete(ChainList& m);

int main()
{
	ChainList mobileBook;
	cout << "Addition:\n" << flush;
	do
	{
		mobileBook.Add();
		cout << "Do you wannna continue? ";
	} while (UserSayYes());
	cout << endl << endl;
	
	//***************************************************************

	cout << "Changing:\n" << flush;
	ModifyName(mobileBook);
	ModifyNum(mobileBook);
	cout << endl << endl;

	//***************************************************************

	cout << "Finding:\n" << flush;
	string name;
	do
	{
		cout << "Please input a name you want to find: " << flush;
		cin.sync();				//clear the cin buffer
		getline(cin,name);
		mobileBook.FindByName_Print(name);
		cout << "Do you wannna continue? ";
	} while (UserSayYes());

	string num;
	do
	{
		cout << "Please input a phone number you want to find: " << flush;
		cin.sync();				//clear the cin buffer
		getline(cin, num);
		mobileBook.FindByPhNum_Print(num);
		cout << "Do you wannna continue? ";
	} while (UserSayYes());
	cout << endl << endl;

	//***************************************************************

	cout << "Deletion:\n" << flush;
	Delete(mobileBook);
	cout << endl << endl;

	//***************************************************************
	
	cout << "Printing the remaining List:\n" << flush;
	mobileBook.Print();
	cout << endl;
}

void ModifyName(ChainList& m)
{
	do
	{
		cout << "Modify name, now we have " << m.GetLen() << " members,"
			<< " please input a position: " << flush;
		int pos;
		string newName;
		cin >> pos;
		cout << "The member is: " << endl;
		m.Print(pos);
		cout << "Do you wish to continue modifying name?" << flush;
		if (UserSayYes())
		{
			m.ModifyName(pos);
			cout << "The new name is: " << m.GetName(pos) << endl
				<< "Modified successfully!" << endl;
		}
		cout << "Do you wish to continue changing name?" << flush;
	} while (UserSayYes());
}

void ModifyNum(ChainList& m)
{
	do
	{
		cout << "Modify phone number, now we have " << m.GetLen() << " members,"
			<< " please input a position: " << flush;
		int pos;
		cin >> pos;
		cout << "The member is: " << endl;
		m.Print(pos);
		cout << "Do you wish to continue modifying phone number?" << flush;
		if (UserSayYes())
		{
			m.ModifyNum(pos);
			cout << "The new phone number is: " << m.GetPhNum(pos) << endl
				<< "Modified successfully!" << endl;
		}
		cout << "Do you wish to continue changing phone number?" << flush;
	} while (UserSayYes());
}

void Delete(ChainList& m)
{
	do
	{
		cout << "Delete entries, now we have " << m.GetLen() << " members,"
			<< " please input a position: " << flush;
		int pos;
		cin >> pos;
		cout << "The member is: " << endl;
		m.Print(pos);
		cout << "Do you wish to continue to delete this entry?" << flush;
		if (UserSayYes())
		{
			m.Delete(pos);
			cout << "Deleted successfully!" << endl;			
		}
		cout << "Do you wish to continue deleting?" << flush;
	} while (UserSayYes());
}