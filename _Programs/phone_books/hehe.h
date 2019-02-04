const  int  maxcol = 60;

class Life{
public:
	void initialize();
    void print();
	void update();
private:
	int grid[maxcol+4];
	int neighbor_count(int col);
};

