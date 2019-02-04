//*******************************************************************
//	The Tic-Tac-Toe game specification
//	uses:	Chess_Game.h, meanwhile derived the Board class
//*******************************************************************
#ifndef TTT
#define TTT
#include "Chess_Game.h"
const int ROW = 3;
const int COL = 3;
class TicBoard : public Board
{
public:
	TicBoard();
	virtual int Done() const;
	virtual void Play(Move tryIt);
	virtual int Evaluate() const;
	virtual int GetLegalMoves(Stack<Move> &moves) const;
	virtual int WorstCase() const;
	virtual int ChooseBetter(int value, int oldValue) const;
	virtual void Print() const;
	virtual void Instructions() const;
	bool IsValid(Move tryIt) const;
	int GetWinner() const;
protected:
	int squares[ROW][COL];
	int movesDone;
};

//*******************************************************************

int LookAhead(const TicBoard &game, int depth, Move &recommand);

#endif