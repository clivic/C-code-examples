//*******************************************************************
//	Joserf
//*******************************************************************
#include "ChainList.h"

//Joserf functions
void IntroductionJ();
void InstructionsJ();
void Output(/* in */ int winner);
int Match(/* in */ ChainList total, /* in */ int round);

//Test functions

template <class Type>
void Cin(/* inout */ Type& input);

int main()
{
	do
	{	
	cout << "Please choose: Joserf game press <1>, test press <0>: " << flush;
	bool choice;
	Cin(choice);
	if (choice)
	{
		IntroductionJ();
		InstructionsJ();
		int m, n;
		Cin(m);
		Cin(n);
		ChainList people(m);
		Output(Match(m, n));
	}
	else
	{
		ChainList list(5);
		list.ReplaceItem(1, 2);
		list.ReplaceItem(2, 23);
		list.ReplaceItem(3, 15);
		list.ReplaceItem(4, 5);
		list.ReplaceItem(5, 9);
		
		//find 15
		int i = 0;
		for (; i < list.GetLen(); i++)
		{
			if (list.GetItem(i) == 15) break;
		}

		//delete 15
		list.Delete(i);

		//find 9
		for (i = 0; i < list.GetLen(); i++)
		{
			if (list.GetItem(i) == 9) break;
		}
		i -= 1;

		//insert 15
		list.Insert(i,15);
		
		list.Print();
		cout << "Test successfully!\n"
			<< endl;
	}

	cout << "Do you wanna continue? " << flush;
	} while (UserSayYes());
	return 0;
}

void IntroductionJ()
//	Post:	IntroductionJ.
{
	cout << "Joserf Game" << endl << endl;
}

void InstructionsJ()
//	Post:	Prompt user to enter total people and people in one round.
{
	cout << "Please input the data in this form:"
		<< "\"m\" \"n\".\n"
		<< "Which the m denotes total people, n denotes people in one round: " << flush;
}

void Output(/* in */ int winner)
{
	cout << "Then our winner is the person in the -- " << winner << " position!" << endl;
}

int Match(/* in */ ChainList total, /* in */ int round)
{
	while (total.GetLen() > 1)
	{
		total.GetItem_Change(round);
		total.Delete(1);
	}
	return total.GetItem(1);
}

template <class Type>
void Cin(/* inout */ Type& input)
//	Pre:	the object for cin should support "cin operation".
//	Post:	cin a number && IF cin breaks down,
//			prompt user to re-enter the object && clear the cin.	
//	Note:	for template, should include utility.cpp.
{
	cin >> input;
	//prevent the case of not number
	while (!cin)
	{
		cout << "Invalid input, please input again: " << flush;
		cin.clear();
		cin.sync();
		cin >> input;
	}
}