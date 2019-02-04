//*******************************************************************
//	數據格式說明: XXXX-XXXX-XXXX-XXXX
//	實際使用是後九位.故看X-XXXX-XXXX
//	每位1代表可能取該位,0則表示不能取該位.
//	而從右到左,第幾位就代表著數字幾.
//	例如:0-0000-0001就是數獨格子填1,並且只能取1.
//		 0-0000-0100就是填3,並且只能取3
//		 1-0111-1111就是指沒填,可以取除8以外的數字的空格子
//	故空格子初始化是1-1111-1111
//*******************************************************************
#define _1 0x0001
#define _2 0x0002
#define _3 0x0004
#define _4 0x0008
#define _5 0x0010
#define _6 0x0020
#define _7 0x0040
#define _8 0x0080
#define _9 0x0100

#include <iostream>
using namespace std;
#include <fstream>
#include <bitset>
ofstream fout;
ifstream fin;
//#define cout fout
struct Seed
{
	short x,y;
	int	count;
};
class NineNum
{
public:
	//数字标记
	short flag;
	NineNum():flag(0x01ff)
	{}
	void	SetNum(int i)
	{
		switch(i)
		{
		case 1: flag = _1;break;
		case 2: flag = _2;break;
		case 3: flag = _3;break;
		case 4: flag = _4;break;
		case 5: flag = _5;break;
		case 6: flag = _6;break;
		case 7: flag = _7;break;
		case 8: flag = _8;break;
		case 9: flag = _9;break;
		}
	}
	int		GetNum()
	{
		switch(flag)
		{
		case _1: return 1;
		case _2: return 2;
		case _3: return 3;
		case _4: return 4;
		case _5: return 5;
		case _6: return 6;
		case _7: return 7;
		case _8: return 8;
		case _9: return 9;
		}
		return 0;
	}
};
class SuduMatrix
{
public:
	NineNum n[9][9];
	void	Print()
	{
		for(int i(0);i<9;++i)
		{
			for(int j(0);j<9;++j)
			{
				cout<<' ';
				cout<<n[i][j].GetNum();
				fout<<' ';
				fout<<n[i][j].GetNum();
			}
			cout<<endl;
			fout<<endl;
		}
	}
	void PrintFlag()
	{
		for(int i(0);i<9;++i)
		{
			for(int j(0);j<9;++j)
			{
				cout<<' ';
				cout<<n[i][j].flag;
			}
			cout<<endl;
		}
	}
	Seed GetSeed()
	// Post:	搜尋可能性數目最少的空格子
	{
		//找到最小可能数
		Seed ret;		// 記載最少可能性數目的點
		ret.x=-1;
		ret.count =9;	// 先默認九種可能(就是都有可能)
		for(int i(0);i<9;++i)
		{
			for(int j(0);j<9;++j)
			{
				bitset<16> flg(n[i][j].flag);
				//确定数
				if(flg.count() == 1)
				{continue;}
				else if(flg.count() < ret.count)
				{
					ret.count = flg.count();
					ret.x=i;ret.y=j;
				}
			}
		}
		
		return ret;
	}
	void	Clear()
	{
		for(int i(0);i<9;++i)
		{
			for(int j(0);j<9;++j)
			{
				n[i][j].flag = 0x01ff;	//預設的1-1111-1111,即都有可能
			}
		}
	}
};


