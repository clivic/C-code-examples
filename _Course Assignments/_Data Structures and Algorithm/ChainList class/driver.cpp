////*************************************************************************************************
////	driver for test the chain list
////*************************************************************************************************
//
//#include"chainList.h"
//#include <iostream>
//
//using namespace std;
//
//void main()
//{
//	ChainList list(10);
//	cout << "1:\n";
//	list.Print();
//	//list.~ChainList();	//detructor is executed by system itself couldn't be explicitly called
//	
//	Node* p1 = new Node;
//	list.Replace(10, p1);
//	cout << "2:\n";
//	list.Print();
//
//	list.ReplaceItem(10, -1);
//	cout << "3:\n";
//	list.Print();
//
//	p1 = new Node;
//	p1->entry = 666;
//	list.Insert(6, p1);
//	cout << "4:\n";
//	cout << "if null: " << (bool)(p1 == NULL) << '\n';
//	list.Print();
//	cout << "length: " << list.GetLen() << '\n';
//
//	list.Delete(7);
//	cout << "5:\n";
//	list.Print();
//	cout << "length: " << list.GetLen() << '\n';
//
//	cout << "Addons:\n" 
//		 << list.GetAdr() << '\n' 
//		 << list.GetItem(3) << '\n'
//		 << list.GetMember(5).entry << '\n';
//}