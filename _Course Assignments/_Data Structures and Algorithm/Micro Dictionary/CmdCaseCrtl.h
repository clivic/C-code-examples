//*******************************************************************
//	Case control for client function DoCommand
//*******************************************************************
#ifndef CASECTRL
#define CASECTRL
#include "Hash Table.h"

class CmdCaseCtrl
{
public:
	CmdCaseCtrl(bool isAccurate = 1, bool isList = 1, bool isfound = false);
	void SetList();
	void SetHash();
	void SetAcSearch();
	void SetFzSearch();
	void Search(List<Record> &list, HashTable &hash);
	void Print(const List<Record> &list, const HashTable &hash) const;
	void AddNew(List<Record> &list, HashTable &hash);
	void DelNew(List<Record> &list, HashTable &hash);
	void Test(const List<Record> &list, const HashTable &hash);
	void UpdateState(bool &isAccurate, bool &isList) const;
		
protected:
	//Tools and Storage space for DoCommand function to use:
	bool found;			//whether the substring is found in fuzzy searching.
	bool testState;		//if 1, give time of one search; 
						//else, give time of searching all the words.
	String word, fuzzyWord, epl;
	int position, size;
	double wholeTime;	//for time test of searching all the words.
	Record	target, 
			dummy;		//for Hash Remove.
	Error_code result;
	bool searchState;
	bool storageState;

	//Tool functions:
	void AcSearch(List<Record> &list);
	void FzSearch(List<Record> &list);
	void AcSearch(HashTable &hash);
	void FzSearch(const List<Record> &list, HashTable &hash);
	void TestAll(const List<Record> &list, const HashTable &hash);
	void TestOne(const List<Record> &list, const HashTable &hash);
	void TestAllBySeqSearch(const List<Record> &list);
	void TestAllByBinSearch(const List<Record> &list);
	void TestAllByHashSearch(const List<Record> &list, const HashTable &hash);
	void TestOneBySeqSearch(const List<Record> &list);
	void TestOneByBinSearch(const List<Record> &list);
	void TestOneByHashSearch(const HashTable &hash);
	void WriteOutSearchState(bool &isAccurate) const;
	void WriteOutStorageState(bool &isList) const;
};

Error_code SequentialSearch(const List<Record> &l, const Key &target, int &pos);
Error_code BinarySearch(const List<Record> &l, const Key &target, int &pos);
Error_code HashSearch(const HashTable &h, const Key &target, Record &found);
void PrintVolcabulary(const List<Record> &l);
void PrintVolcabulary(const List<Record> &l, const HashTable &h);

#endif