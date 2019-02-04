//*******************************************************************
//		Towers of Hanoi Game
//*******************************************************************
#include "utility.h"

void Introduction();
void Instruction();
void Move(int num, int start, int finish, int temp);

int main()
//	Pre:	Using utility.h and utility.cpp.
//	Post:	Simulate the game of Towers of Hanoi.
{
	int disks;
	Introduction();
	Instruction();
	do
	{
		cout << "How many disks are there? " << flush;
		Cin(disks);
		cout << "\nThen the method is:" << endl;
		Move(disks, 1, 3, 2);
		cout << "Do you wanna continue?" << flush;
	} while (UserSayYes());
}

void Introduction()
{
	cout << "Welcome to Towers of Hanoi Game!" << endl << endl;
}

void Instruction()
{
	cout << "You are supposed to input the number of disks you wanna\n"
		<< "move, and this program will show you complete methods of\n"
		<< "moving them, while you're playing by yourself on a table\n"
		<< "beside, as a guide!\n"
		<< "Please notice the size is not suggested to exceed 30 for\n"
		<< "it needs a lot of time!\n" << endl;
}

void Move(int num, int start, int finish, int temp)
//	Pre:	There are at least num disks on the pole start,
//			The top disk(if any) on each of towers temp and
//			finish is larger than any of the disks to move.
//	Post:	The num disks have been moved to the pole finish
//			from the pole start, and the pole temp has returned
//			to its defalut status when called.
{
	if (num > 0)
	{
		Move(num - 1, start, temp, finish);
		cout << "Move disk " << num << " from "
			<< start << " to " << finish << '.' << endl;
		Move(num - 1, temp, finish, start);
	}
}