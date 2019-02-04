//*******************************************************************
//	������ʽ�f��: XXXX-XXXX-XXXX-XXXX
//	���Hʹ�������λ.�ʿ�X-XXXX-XXXX
//	ÿλ1�������ȡԓλ,0�t��ʾ����ȡԓλ.
//	�����ҵ���,�ڎ�λ�ʹ��������֎�.
//	����:0-0000-0001���ǔ���������1,�K��ֻ��ȡ1.
//		 0-0000-0100������3,�K��ֻ��ȡ3
//		 1-0111-1111����ָ�]��,����ȡ��8����Ĕ��ֵĿո���
//	�ʿո��ӳ�ʼ����1-1111-1111
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
	//���ֱ��
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
	// Post:	�ь������Ԕ�Ŀ���ٵĿո���
	{
		//�ҵ���С������
		Seed ret;		// ӛ�d���ٿ����Ԕ�Ŀ���c
		ret.x=-1;
		ret.count =9;	// ��Ĭ�J�ŷN����(���Ƕ��п���)
		for(int i(0);i<9;++i)
		{
			for(int j(0);j<9;++j)
			{
				bitset<16> flg(n[i][j].flag);
				//ȷ����
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
				n[i][j].flag = 0x01ff;	//�A�O��1-1111-1111,�����п���
			}
		}
	}
};


