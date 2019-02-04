#include "TicTacToe.h"

void Introduction();
void Instruction();
bool DoOperation
	(char command, bool &firstIsHuman,
	bool &secondIsHuman, int &difficulty);
char GetCommand();

//tool functions
void ComputerMove(TicBoard &game, int &difficulty, Move &recommended);
void HumanMove(TicBoard &game, Move &gamer, int &x, int &y);

int main()
//	The Tic-Tac-Toe game
//	Uses:	The classes Stack, Board, and Move, 
//			together with function look_ahead, DoOperation, GetCommand.
{
	bool firstIsHuman = 1, secondIsHuman = 0;
	int AI = 9;				//defalut difficulty: 9
	Introduction();
	Instruction();
	while (DoOperation(GetCommand(), firstIsHuman, secondIsHuman, AI));
	return 0;
}

void Introduction()
{
	cout << "Welcome to The game Tic-Tac-Toe in DOS!\n"
		<< "You can use the the menu and the command to choose to play\n"
		<< "with computer or your pal.\n"
		<< "The defalut setting is one player(first) vs computer(second),\n"
		<< "and the difficulty is HARD(9).\n"
		<< "Have fun then!\n" << flush;
}

void Instruction()
{
	cout << "Command Menu:" << endl
		<< "[I]Set the AI  [S]Get start" << endl
		<< "[1]Set the player1 whether computer or human" << endl
		<< "[2]Set the player2 whether computer or human" << endl
		<< "[H]Help for Command Menu" << endl
		<< "[Q]Quit." << endl << endl;
}

char GetCommand()
//	Pre:	difficulty should be in 1 ~ 9.
//	Post:	if not valid, continue prompting user to input
//			else return the command.
{
	char ch;		//command
	cout << "Select command and press <Enter>: " << flush;
	cin >> ch;
	ch = tolower(ch);
	while (ch != 'i' && ch != 's' && ch != '1' && ch != '2'
		&& ch != 'h' && ch != 'q')
	{
		cout << "Please enter a valid command, or press [H] for help:"
			<< flush;
		cin >> ch;
		ch = tolower(ch);
	}
	return ch;
}

bool DoOperation
	(char command, bool &firstIsHuman,
	bool &secondIsHuman, int &difficulty)
//	Pre:	command is valid
//	Post:	do according to the command, and return false unless 
//			command is 'Q' or 'q'
{
	TicBoard game;			//The game board
	string player;			//For output
	Move gamer;				//Player's move
	Move recommended;		//AI's move
	switch (command)
	{
	case 'i':
		cout << "Please input the difficulty you want your computer"
			<< "opponent to be, which are:\n"
			<< "EASIEST: 1\n"
			<< "MEDIUM: 5\n"
			<< "HARD: 9\n"
			<< "or you can enter number between 1 and 9 according to"
			<< " this trend.\n"
			<< "So level? " << flush;
		int level;
		do
		{
			Cin(level);
			if (level > 9 || level < 1)
				cout << "Invalid input, please input again: " << flush;
		}	while (level > 9 || level < 1);
		difficulty = level;
		cout << "Now the difficulty has been changed to " << level << "."
			<< endl;
		break;
	
	case '1':
	case '2':
		switch (command)
		{
		case '1':	player = "first";	break;
		case '2':	player = "second";	break;
		}
		cout << "Please choose the identity for the " << player << " player,\n"
			<< "0 represents computer and 1 represents human: " << flush;
		int id;
		do
		{
			Cin(id);
			if (id != 0 && id != 1)
				cout << "Invalid input, please input again: " << flush;
		} while (id != 0 && id != 1);

		if (command == '1')
			if (id == 1)
			{
				firstIsHuman = true;
				cout << "Now the first player is human." << endl;
			}
			else
			{
				firstIsHuman = false;
				cout << "Now the first player is computer." << endl;
			}
		else
			if (id == 1)
			{
				secondIsHuman = true;
				cout << "Now the second player is human." << endl;
			}
			else
			{
				secondIsHuman = false;
				cout << "Now the second player is computer." << endl;
			}
		break;

	case 'h':	
		Instruction();
		break;

	case 's':
		int x, y;			//coordinate
		while (!game.Done())
		{
			if (firstIsHuman)
			{
				cout << "Player 1:" << endl;
				HumanMove(game, gamer, x, y);
			}
			else
			{
				cout << "Computer 1:" << endl;
				ComputerMove(game, difficulty, recommended);	
			}
			if (game.Done())	break;
			
			if (secondIsHuman)
			{
				cout << "Player 2:" << endl;
				HumanMove(game, gamer, x, y);
			}
			else
			{
				cout << "Computer 2:" << endl;
				ComputerMove(game, difficulty, recommended);
			}	
			if (game.Done())	break;
			difficulty--;
		}
		if (game.GetWinner() == 1)
			if (firstIsHuman)	cout << "Game over with Player1 wins!" << endl;
			else				cout << "Game over with Computer1 wins!" << endl;
		else if (game.GetWinner() == 2)
			if (secondIsHuman)	cout << "Game over with Player2 wins!" << endl;
			else				cout << "Game over with Computer2 wins!" << endl;
		else
			cout << "Game over with a draw." << endl;
		cout << endl;
		break;

	case 'q':
		cout << "Game exited.\n" << flush;
		return false;
	}
	return true;
}

void ComputerMove(TicBoard &game, int &difficulty, Move &recommended)
//	Post:	Computer finds ways and plays the recommanded way and print out.
{
	do
	{
		LookAhead(game, difficulty, recommended);
		if (!game.IsValid(recommended))
			difficulty += 1;			//keep finding
	}	while (!game.IsValid(recommended));
	game.Play(recommended);
	game.Print();
}

void HumanMove(TicBoard &game, Move &gamer, int &x, int &y)
{
	do
	{
		cout << "X:";	Cin(x);
		cout << "Y:";	Cin(y);
		gamer.row = x;
		gamer.col = y;
		if (!game.IsValid(gamer))
			cout << "Invalid step, please input again:" << endl;
	} while (!game.IsValid(gamer));
	game.Play(gamer);
	game.Print();
}