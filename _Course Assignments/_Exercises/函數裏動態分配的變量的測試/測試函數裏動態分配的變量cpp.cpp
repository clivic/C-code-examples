//*************************************************************************************************
//	測試函數裏動態分配的變量是否在函數調用結束后依然存在和靜態分配不同
//	此處用全局函數的方法創建一個專門的單鏈表,功能同單鏈表類(ChainList class)相同。主要是想看一看
//	調用之後這個新建的空間還存在否，並與靜態的作個比較。
//*************************************************************************************************
#include <iostream>

using std::cout;
using std::endl;

typedef int type;

struct Node								//the containing of every member in a chain list
{
	type key;
	Node* next;
	Node(type item = 0);				//initialize the containing of key
};

Node::Node(type item)
{
	key = item;
}

void ChainList(
	type n,
	Node* &h)
{
	type i = 1;
	h = new Node(i);
	Node* ps = h;
	Node* pt = NULL;
	for (i += 1; i <= n; i++)
	{
		pt = new Node(i);
		ps->next = pt;
		ps = ps->next;
	}
	pt->next = NULL;
}

void Delete(
	type n,
	Node* &h)
{
	Node* ps = h;
	Node* pt = ps->next;
	h = NULL;
	for (int i = 1; i < n; i++)
	{
		delete ps;
		ps = pt;
		pt = pt->next;
	}
	delete ps;
	ps = pt;
}

int main()
{
	Node* h;
	ChainList(5, h);
	Delete(5, h);
	return 0;
}

//經過調試發現確實可以用，new 建立的空間確實似乎要手動刪除。而靜態的也許就不一樣了。
//更何況創鏈表也許還不能夠用靜態的呢因其需動態分配哈。