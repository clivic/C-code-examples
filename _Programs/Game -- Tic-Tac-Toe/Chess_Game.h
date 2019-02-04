//*************************************************************************************************
//	The Chess Game specification
//	This is the general specification of the chess game(class Board, struct Move), also included in
//	utility package for it uses Linked_Stack.h. Besides, the useful function LookAhead has both
//	specification and Implementations. But it has not concrete implementations for it depends on
//	specific chess game. So does the other data members in class Board. So when using it, please 
//	derive this class to use it and write the implementations despite the possibly existing 
//	complexities. Especially, the implementation of LookAhead should be modified to the proper 
//	version to the derived class of Board.
//*************************************************************************************************
#ifndef CGAME
#define CGAME
#include "Linked_Stack.h"

//	The Move: a single game move
struct Move
{
	Move();
	Move(int a);		//one dimension grid
	Move(int r, int c);	//two dimension grid
	int row;
	int col;
};

//The Board: a single game position
class Board
{
public :
	//Board();
	virtual int Done() const = 0;
	virtual void Play(Move tryIt) = 0;
	virtual int Evaluate() const = 0;
	virtual int GetLegalMoves(Stack<Move> &moves) const = 0;
	virtual int WorstCase() const = 0;
	virtual int ChooseBetter(int value, int oldValue) const = 0;
	virtual void Print() const = 0;
	virtual void Instructions() const = 0;
	/*Additional methods, functions and data will depend
	on the game under consideration.*/
};

////	LookAhead function: very useful for AI to found stategy
//int LookAhead(const Board &game, int depth, Move &recommand)
////	Pre:	Board game represents a legal game position.
////	Post:	An evaluation of the game(to call the function Evaluate
////			indeed at last), based on looking ahead depth moves, 
////			is returned. And the best move that can be found for 
////			the mover is recorded as Move recommended.		
////	Uses:	The classes Stack, Board, and Move, together with function 
////			LookAhead recursively. 
//{
//	if (game.Done() || depth == 0)
//		return game.Evaluate();
//	Stack<Move> moves;
//	game.GetLegalMoves(moves);
//	int value, bestValue = game.WorstCase();	//initialization
//
//	while (!moves.Empty())
//	{
//		Move tryIt, reply;
//		moves.Top(tryIt);
//		Board newGame = game;	//!!this should be the class of derived class
//		//user should modify this place
//		newGame.Play(tryIt);
//		value = LookAhead(newGame, depth - 1, reply);
//
//		if (game.ChooseBetter(value, bestValue))
//		{
//			bestValue = value;
//			recommand = tryIt;
//		}
//		moves.Pop();
//	}
//	return bestValue;
//}

#endif