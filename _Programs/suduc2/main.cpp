#include "suduc.h"
#include <windows.h>
#include <iostream>
#include <vector>
using namespace std;
SuduMatrix suduM;//实表
int			CalMaybe(SuduMatrix* sudum);
bool		CalAll(SuduMatrix* sudum);
bool		suc = false;

int main(int argc, char* argv[])
{
	cout<<"**********************************\n** Simple SudokuCalculator v1.0 **\n** Copyright (C) 2008, Zoo Games**\n** http://zooed.spaces.live.com/**\n**********************************"<<endl;
	char inputname[64];
	if(argc >= 2)
	{
		strcpy(inputname,argv[1]); 
	}
	else
	{
		cout<<endl;
		cout<<"This Programme Need A Pure Text File That Records a SudokuMatrix,as"<<endl;
		suduM.Print();
		cout<<"Please Input the Filename of SudokuMatrix:"<<endl;
		cin>>inputname;
	}
	fin.open(inputname);
	if(!fin) 
	{
		cout<<"Filename is not exist"<<endl;
		return 0;
	}
	char outputname[64];
	int inputnamelen = strlen(inputname);
	memcpy(outputname,inputname,inputnamelen);
	const char* outputnametail= "-output.txt";
	memcpy((char*)outputname+inputnamelen,outputnametail,12);
	fout.open(outputname);
	for(int i(0);i<9;++i)
	{
		for(int j(0);j<9;++j)
		{
			int c;
			fin>>c;
			suduM.n[i][j].SetNum(c);
		}
	}
	//fin.close();
	CalAll(&suduM);
	if(suc == false)
	{
		cout<<"This SudokuMatrix has No Solution!"<<endl;
		fout<<"This SudokuMatrix has No Solution!"<<endl;
	}
	suduM.Clear();
	fout<<flush; 
	fout.close();
	return 0;
}

int	CalMaybe(SuduMatrix* sudum)
// Post:	計算每個格子的可能取的值
{
	int i, j;
	//行列块表
	vector<short> hr[9];// 每一行有哪些數字
	vector<short> lr[9];// 每一列有哪些數字
	vector<short> kr[3][3];// 每一塊有哪些數字
	//可能表
	vector<int> xm;// 這兩個存空點坐標
	vector<int> ym;
	vector<int> xr;// 這兩點存滿點坐標
	vector<int> yr;
	//处理实表
	for(i=0;i<9;++i)
	{
		for (j = 0; j < 9; ++j)
		{
			bitset<16> flg(sudum->n[i][j].flag);
			if(flg.count() != 1)
			{
				xm.push_back(i);
				ym.push_back(j);
			}
			else
			{
				xr.push_back(i);
				yr.push_back(j);
				hr[i].push_back(sudum->n[i][j].flag);
				lr[j].push_back(sudum->n[i][j].flag);
				kr[(i/3)][(j/3)].push_back(sudum->n[i][j].flag);
			}
		}
	}
	
	int m;
	for(m=0; m < xr.size();++m)	// 處理所有滿點
	{
			int count(0);
			i = xr[m];
			j = yr[m];
			int re = 0;
			for(int h(0);h < hr[i].size();++h)// 檢查這個滿點所在的列有沒有這個數字
			{
				if(sudum->n[i][j].flag == hr[i][h])
					re++;
			}
			if(re>1) return 0;
			re =0;
			for(int l(0);l < lr[j].size();++l)
			{
				if(sudum->n[i][j].flag == lr[j][l])
					re++;
			}
			if(re>1) return 0;
			re=0;
			for(int k(0);k < kr[i/3][j/3].size();++k)
			{
				if(sudum->n[i][j].flag == kr[i/3][j/3][k])
					re++;
			}
			if(re>1) return 0;
	}
	//有可能值得话算出可能值
	for(i=0;i<xm.size();++i)
	{
		int x = xm[i];int y = ym[i];
		short flag = 0x01ff;
		for(int j(0);j<hr[x].size();++j)
		{
			flag &= ~hr[x][j];
		}
		for(j = 0;j<lr[y].size();++j)
		{
			flag &= ~lr[y][j];
		}
		for(j = 0;j<kr[x/3][y/3].size();++j)
		{
			flag &= ~kr[x/3][y/3][j];
		}
		if(flag == 0)
		{
			return 0;			
		}
		else
		{
			sudum->n[x][y].flag =flag;
		}
	}	
	return 1;
}
bool	CalAll(SuduMatrix* sudum)
{
	if(CalMaybe(sudum) == 0) return false;
	Seed s = sudum->GetSeed();	// 找最小可能性數目之點
	if(s.x == -1) return true;
	for(short j(0x0001);j<_9+1;j<<=1)
	{
		short x = sudum->n[s.x][s.y].flag & j;	// 這些可能性里包含j這個數字嗎?
		if(x == j)	// 如果包含那就填進去,照著這條路遞歸地走下去
		{
			SuduMatrix* sudumd = new SuduMatrix(*sudum);	// 為了遞歸,新建棋盤
			sudumd->n[s.x][s.y].flag = x;		// 照這個選擇填這個格子
			if(CalAll(sudumd))
			{
				if(!suc)
				{
					sudumd->Print();
					suc=true;
				}
				return true;
			}
			delete sudumd;
		}
	}
	return false;
}