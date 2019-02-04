#include<iostream>
#include"hehe.h"
using namespace std;
void Life::print()
/*
pre:
post:
*/
{
	int col;
	cout<<"\n the current Life configuration is:"<<endl;
	  for(col = 2;col<=maxcol+1;col++)
		  if(grid[col]==1) cout<<'*';
		  else cout<<'^';
		cout<<endl;
}

int Life::neighbor_count(int col)
/*
pre:
post:
*/
{
	int j;
	int count = 0;
	for(j = col - 2; j <= col + 2; j ++)
		count += grid[j];
	count -=grid[col];
	return count ;
}

void Life::update()
/*
pre:
post:
*/
{
	int col ;
	int new_grid[maxcol+4];
	for(col = 2; col <= maxcol + 1 ; col++)
		switch (neighbor_count(col)){
		case 4:
			new_grid[col] = grid[col];
			break;
		case 3:
			new_grid[col] = 1 - grid[col];
			break;
		case 2:
			new_grid[col] = 1;
			break;
		default:
			new_grid[col] = 0;
			break;
	}
	for (col = 2; col <= maxcol+1 ; col++)
		grid[col] = new_grid[col];
}

void Life::initialize()
/*
pre:
post:
*/
{
  int col;
    for (col = 0; col <= maxcol+3; col++)
		grid[col] = 0;
	cout<<"List the coordinates for living cells."<<endl;
	cout<<"Terminate the list with the special symbol -1"<<endl;
	cin >> col;

	while (col != -1){
		if (col >=1 && col <= maxcol)
			grid[col + 1] = 1;
		else
			cout<< "Column " << col << " is out of range." << endl;
		cin >> col ;
	}
}





  
	



			

