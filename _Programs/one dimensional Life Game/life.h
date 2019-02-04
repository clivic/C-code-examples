//*******************************************************************
//	Specification of class Life
//*******************************************************************
#ifndef LIFE
#define LIFE
const int MAXCOL = 100;		//grid dimensions

class Life
{
public:
	void Initialize();
	void Print();
	void Update();
private:
	int grid[MAXCOL + 4];	//allows for 2 extra space
	int NeighborCount(int col);
};

#endif