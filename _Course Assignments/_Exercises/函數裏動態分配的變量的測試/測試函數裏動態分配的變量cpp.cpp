//*************************************************************************************************
//	�yԇ�����Y�ӑB�����׃���Ƿ��ں����{�ýY������Ȼ���ں��o�B���䲻ͬ
//	��̎��ȫ�ֺ����ķ�������һ�����T�Ć�朱�,����ͬ��朱��(ChainList class)��ͬ����Ҫ���뿴һ��
//	�{��֮���@���½��Ŀ��g߀���ڷ񣬁K�c�o�B���������^��
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

//���^�{ԇ�l�F�_�������ã�new �����Ŀ��g�_���ƺ�Ҫ�քӄh�������o�B��Ҳ�S�Ͳ�һ���ˡ�
//���Λr��朱�Ҳ�S߀���܉����o�B����������ӑB�������