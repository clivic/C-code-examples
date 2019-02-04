//*******************************************************************
//	The Tic-Tac-Toe game implementation
//	It constains the specific implementation of the Board class.
//*******************************************************************
#include "TicTacToe.h"

Move::Move()
//	Post:	The Move is initialized to an illegal, default value.
{
	row = 3;
	col = 3;
}

Move::Move(int r, int c)
//	Post:	The Move is initialized to the given coordinates.
{
	row = r;
	col = c;
}

Move::Move(int a)
//	Post:	This is a dummy constructor for TicTacToe, row is assigned
//			to a. Besides, the constructor is only to conform Move's
//			specification.
{
	row = a;
}

//*******************************************************************

TicBoard::TicBoard()
//	Post:	The Board is initialized as empty.
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			squares[i][j] = 0;
	movesDone = 0;
}

int TicBoard::Done() const
//	Post:	Return true if the game is over; either because a player 
//			has already won or because all nine squares have been filled.
{
	return (movesDone == 9 || GetWinner() > 0);
}

void TicBoard::Play(Move tryIt)
//	Post: The Move try_it is played on the Board.
{
	squares[tryIt.row][tryIt.col] = movesDone % 2 + 1;
	movesDone++;
}

int TicBoard::Evaluate() const
//	Post:	Return either a value of 0 for a position where neither 
//			player has won, a positive value between 1 and 9 if the 
//			first player has won, or a negative value between -1 
//			and -9 if the second player has won. 
{
	int winner = GetWinner();
	if (winner == 1)		return 10 - movesDone;
	else if (winner == 2)	return -(10 - movesDone);
	else					return 0;
}

int TicBoard::GetLegalMoves(Stack<Move> &moves) const
//	Post:	The parameter Stack moves is set up to contain all possible
//			legal moves on the Board, and return the number of moves.
{
	int count = 0;
	moves.Clear();
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			if (squares[i][j] == 0) 
			{
				Move canPlay(i, j);
				moves.Push(canPlay);
				count++;
			}
	return count;
}

int TicBoard::WorstCase() const
//	Post:	return the worst defalut case each player want to see.
//			(the value is illegal for evaluation)
{
	if (movesDone % 2) return 10;	//for player 2
	else return -10;				//for player 1
}

int TicBoard::ChooseBetter(int value, int oldValue) const
//	Post:	return the better evaluation for each player.
{
	if (movesDone % 2) return value < oldValue;	// for second player 2
	else return value > oldValue;				// for first player 1
}

void TicBoard::Print() const
//	Post:	The board's configuration is printed out, 
//			as well as a blank line.
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << ' ' << squares[i][j];
		cout << ' ' << endl;
	}
	cout << endl;
}

void TicBoard::Instructions() const
//	Post:	Print the welcome message.
{
	cout << "Welcome to the Tic-Tac-Toe game!\n"
		<< "Now let's play -- "<< endl;
}

bool TicBoard::IsValid(Move tryIt) const
//	Post:	IF the human player has moved validly, return true,
//			ELSE return false.
{
	int i = tryIt.row;
	int j = tryIt.col;
	return squares[i][j] == 0;
}

int TicBoard::GetWinner() const
//	Post:	Return either a value of 0 for a position where neither 
//			player has won, a value of 1 if the first player has won,
//			or a value of 2 if the second player has won.
{
	int i;
	for (i = 0; i < 3; i++)
		if (squares[i][0] && squares[i][0] == squares[i][1] && squares[i][1] == squares[i][2])
			return squares[i][0];
	for (i = 0; i < 3; i++)
		if (squares[0][i] && squares[0][i] == squares[1][i] && squares[1][i] == squares[2][i])
			return squares[0][i];
	if (squares[0][0] && squares[0][0] == squares[1][1] && squares[1][1] == squares[2][2])
		return squares[0][0];
	if (squares[0][2] && squares[0][2] == squares[1][1] && squares[1][1] == squares[2][0])
		return squares[0][2];
	return 0;
}

//*************************************************************************************************
//	The Chess Game's LookAhead function's implementation
//*************************************************************************************************

int LookAhead(const TicBoard &game, int depth, Move &recommand)
//	Pre:	Board game represents a legal game position.
//	Post:	An evaluation of the game(to call the function Evaluate
//			indeed at last), based on looking ahead depth moves, 
//			is returned. And the best move that can be found for 
//			the mover is recorded as Move recommended.		
//	Uses:	The classes Stack, Board, and Move, together with function 
//			LookAhead recursively. 
{
	if (game.Done() || depth == 0)
		return game.Evaluate();
	Stack<Move> moves;
	game.GetLegalMoves(moves);
	int value, bestValue = game.WorstCase();	//initialization

	while (!moves.Empty())
	{
		Move tryIt, reply;
		moves.Top(tryIt);
		TicBoard newGame = game;	//!!this should be the class of derived class
		//user should modify this place
		newGame.Play(tryIt);
		value = LookAhead(newGame, depth - 1, reply);

		if (game.ChooseBetter(value, bestValue))
		{
			bestValue = value;
			recommand = tryIt;
		}
		moves.Pop();
	}
	return bestValue;
}
