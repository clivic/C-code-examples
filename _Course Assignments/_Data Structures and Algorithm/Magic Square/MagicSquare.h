//*******************************************************************
//	The specification of class MagicSquare
//*******************************************************************
#ifndef MS
#define MS

const int LENTH = 50;
typedef int Grid[LENTH][LENTH];

class MagicSquare
{
public:
	void SetDefalut();
	void Read(
		/* in */ const Grid gridIn,
		/* in */ int size);
	void Generate();
	bool Judge(
		/* in */ const Grid gridIn,
		/* in */ int size);
	void Print();
	MagicSquare();

private:
	Grid grid;
	int sideLen;	//side length of the magic square
};
#endif
