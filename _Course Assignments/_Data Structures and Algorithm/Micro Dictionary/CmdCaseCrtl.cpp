//*******************************************************************
//	CmdCaseCrtl Class Implementation
//*******************************************************************
#include "CmdCaseCrtl.h"
#include "test_time_efficiency.h"
#include <iomanip>

CmdCaseCtrl::CmdCaseCtrl(bool isAccurate, bool isList, bool isfound)
//	Post:	Initialize the necessary states according to arguments.
{
	CmdCaseCtrl::found = isfound;
	CmdCaseCtrl::searchState = isAccurate;
	CmdCaseCtrl::storageState = isList;
}

void CmdCaseCtrl::SetList()
//	Post:	list operation.
{
	storageState = 1;
	cout << "Now on list operation.\n" << endl;
}

void CmdCaseCtrl::SetHash()
//	Post:	hash table operation.
{
	storageState = 0;
	cout << "Now on hash table operation.\n" << endl;
}

void CmdCaseCtrl::SetAcSearch()
//	Post:	Accurate Search.
{
	searchState = 1;
	cout << "Now accurate searching.\n" << endl;
}

void CmdCaseCtrl::SetFzSearch()
//	Post:	Fuzzy Search.
{
	searchState = 0;
	cout << "Now fuzzy searching.\n" << endl;
}

void CmdCaseCtrl::AcSearch(List<Record> &list)
//	Pre:	Word has been defined && list is not empty.
//	Post:	Compare the word exactly in every entry in the list.
//			If found output messages.
//			Else output "Not found.".
{
	if (SequentialSearch(list, word, position) == not_present)
		clog << "Not found." << endl;
	else
	{
		list.Retrieve(position, target);
		target.WriteFrequency(target.GetFreqency() + 1);
		list.Replace(position, target);			//add frequency
		cout << "Word: " << word << endl;
		cout << "Explanation: " << target.GetExplanation() << endl << endl;
	}
}

void CmdCaseCtrl::FzSearch(List<Record> &list)
//	Pre:	Word has been defined && list is not empty.
//	Post:	Find the word in every entry in the list as substring.
//			If found output messages.
//			Else output "Not found.".
{
	found = false;
	int size = list.Size();
	for (position = 0; position < size; position++)
	{
		list.Retrieve(position, target);
		fuzzyWord = ((Key)target).GetKey();
		if ((Strstr(fuzzyWord, word) >= 0))
		{
			target.WriteFrequency(target.GetFreqency() + 1);
			list.Replace(position, target);			//add frequency
			printf("Word found: %s\n", fuzzyWord);
			printf("Explanation: %s\n\n", target.GetExplanation());
			/*cout << "Word found: " << fuzzyWord << endl;
			cout << "Explanation: " << target.GetExplanation() << endl << endl;*/
			found = true;
		}
	}
	if (!found)	clog << "Not found.\n" << endl;
}

void CmdCaseCtrl::Search(List<Record> &list, HashTable &hash)
{
	cout << "Please input the word you wanna find: " << flush;
	cin.clear();
	cin.sync();
	Cin(word);
	if (storageState)	//list operation
	{
		if (searchState)	
			AcSearch(list);
		else				
			FzSearch(list);
	}
	else				//hash table operation
	{
		if (searchState)	
			AcSearch(hash);
		else			
			FzSearch(list, hash);
	}
}

void CmdCaseCtrl::AcSearch(HashTable &hash)
//	Pre:	Word has been defined && hash table is not empty.
//	Post:	Compare the word exactly in every entry in the hash table.
//			If found output messages.
//			Else output "Not found.".
{
	if (HashSearch(hash, word, dummy) == not_present)
		clog << "Not found." << endl;
	else
	{
		hash.Retrieve(((Key)dummy).GetKey(), target);
		target.WriteFrequency(target.GetFreqency() + 1);
		hash.Replace(word, target, dummy);		//add frequency
		cout << "Word: " << word << endl;
		cout << "Explanation: " << target.GetExplanation() << endl << endl;
	}
}

void CmdCaseCtrl::FzSearch(const List<Record> &list, HashTable &hash)
//	Pre:	Word has been defined && hash table is not empty.
//	Post:	Find the word in every entry in the hash table as substring.
//			If found output messages.
//			Else output "Not found.".
{
	found = false;
	for (int i = 0; i < list.Size(); i++)
	{
		list.Retrieve(i, dummy);
		hash.Retrieve(((Key)dummy).GetKey(), target);
		fuzzyWord = ((Key)target).GetKey();
		if ((Strstr(fuzzyWord, word) >= 0))
		{
			target.WriteFrequency(target.GetFreqency() + 1);
			hash.Replace(word, target, dummy);		//add frequency
			printf("Word found: %s\n", fuzzyWord);
			printf("Explanation: %s\n\n", target.GetExplanation());
			found = true;
		}
	}
	if (!found)	clog << "Not found.\n" << endl;
}

void CmdCaseCtrl::Print(const List<Record> &list, const HashTable &hash) const
{
	if (storageState)		//list operation
	{
		PrintVolcabulary(list);
		printf("\n");
	}
	else					//hash table operation
	{
		PrintVolcabulary(list, hash);
		printf("\n");
	}
}

void CmdCaseCtrl::AddNew(List<Record> &list, HashTable &hash)
{
	cout << "Please input the new word you want to append: " << flush;
	cin.clear();
	cin.sync();
	Cin(word);
	cout << "Then please input its Chinese meaning in this format:\n"
		<< "<word type>.<Chiniese meaning>;<Chiniese meaning>...<blank><word type>...\n"
		<< "Meaning: " << flush;
	Cin(epl);
	size = list.Size();
	target.WriteWord(word);
	target.WriteExplanation(epl);
	target.WriteNum(size + 1);
	target.WriteFrequency(0);
	list.Insert(size, target);
	hash.Insert(target);
	cout << "The word " << ((Key)target).GetKey()
		<< " \"" << target.GetExplanation() << "\" has been appended successfully!\n"
		<< endl;
}

void CmdCaseCtrl::DelNew(List<Record> &list, HashTable &hash)
{
	cout << "Please input the word£¨note that you can't delete core words) you want to delete: " << flush;
	cin.clear();
	cin.sync();
	Cin(word);
	SequentialSearch(list, word, position);
	list.Retrieve(position, target);
	if (position <= 4504 - 1)
		cout << "Sorry you can't delete core words.\n" << endl;
	else
	{
		cout << "Is it the word:\n"
			<< ((Key)target).GetKey() << ' '
			<< '\"' << target.GetExplanation() << "\"? " << flush;
		if (UserSayYes())	//can't delete core words
		{
			list.Remove(position, target);
			hash.Remove(target,dummy);
			cout << "Now it has been deleted." << endl;

		}
	}
}

void CmdCaseCtrl::Test(const List<Record> &list, const HashTable &hash)
{
	cout << "Please input the way you want to test,\n"
		<< "if 0, give time of searching all the words,\n"
		<< "else, give time of one search: " << flush;
	Cin(testState);

	if (testState)	TestOne(list, hash);
	else			TestAll(list, hash);
}

void CmdCaseCtrl::TestAll(const List<Record> &list, const HashTable &hash)
//	Post:	Output message about time of searching all the words.
{
	size = list.Size();
	TestAllBySeqSearch(list);
	TestAllByBinSearch(list);
	TestAllByHashSearch(list, hash);
	printf("\n");
}

void CmdCaseCtrl::TestOne(const List<Record> &list, const HashTable &hash)
//	Post:	Output message about time of searching one specific word.
{
	cout << "Please input the word you wanna find: " << flush;
	cin.clear();
	cin.sync();
	Cin(word);
	TestOneBySeqSearch(list);
	TestOneByBinSearch(list);
	TestOneByHashSearch(hash);
	if (result != success)	cout << "Not found.\n" << endl;
	else					cout << "found.\n" << endl;
}

void CmdCaseCtrl::TestAllBySeqSearch(const List<Record> &list)
//	Pre:	Should be used with TestAll Function.
//	Post:	Output message about time of sequential searching all the words.
{
	wholeTime = 0.0;
	QueryPerformanceFrequency(&frequ);
	for (int i = 0; i < size; i++)
	{
		list.Retrieve(i, target);
		word = ((Key)target).GetKey();

		//one time test
		QueryPerformanceCounter(&start);
		SequentialSearch(list, word, position);
		QueryPerformanceCounter(&over);
		wholeTime += (over.QuadPart - start.QuadPart) / (double)frequ.QuadPart;
	}
	cout << left << setw(25) << "Sequential Search time: " 
		 << fixed <<  wholeTime << "(s)." << endl;
}

void CmdCaseCtrl::TestAllByBinSearch(const List<Record> &list)
//	Pre:	Should be used with TestAll Function.
//	Post:	Output message about time of binary searching all the words.
{
	wholeTime = 0.0;
	QueryPerformanceFrequency(&frequ);
	for (int i = 0; i < size; i++)
	{
		list.Retrieve(i, target);
		word = ((Key)target).GetKey();

		//one time test
		QueryPerformanceCounter(&start);
		SequentialSearch(list, word, position);
		QueryPerformanceCounter(&over);
		wholeTime += (over.QuadPart - start.QuadPart) / (double)frequ.QuadPart;
	}
	cout << left << setw(25) << "Binary Search time: " 
		 << fixed << wholeTime << "(s)." << endl;
}

void CmdCaseCtrl::TestAllByHashSearch(const List<Record> &list, const HashTable &hash)
//	Pre:	Should be used with TestAll Function.
//	Post:	Output message about time of Hash searching all the words.
{
	wholeTime = 0.0;
	QueryPerformanceFrequency(&frequ);
	for (int i = 0; i < size; i++)
	{
		list.Retrieve(i, target);
		word = ((Key)target).GetKey();

		//one time test
		QueryPerformanceCounter(&start);
		HashSearch(hash, word, target);
		QueryPerformanceCounter(&over);
		wholeTime += (over.QuadPart - start.QuadPart) / (double)frequ.QuadPart;
	}
	cout << left << setw(25) << "Hash Search time: " << fixed << wholeTime << "(s).\n"
		 << "collide time:     " << hash.GetCollideTime() << endl;
}

void CmdCaseCtrl::TestOneBySeqSearch(const List<Record> &list)
//	Pre:	Should be used with TestOne Function.
//	Post:	Output message about time of sequential searching all the words.
{
	QueryPerformanceFrequency(&frequ);
	QueryPerformanceCounter(&start);
	result = SequentialSearch(list, word, position);
	QueryPerformanceCounter(&over);
	cout << left << setw(25) << "Sequential Search time: " << fixed
		 << (over.QuadPart - start.QuadPart) / (double)frequ.QuadPart << "(s)." << endl;
}

void CmdCaseCtrl::TestOneByBinSearch(const List<Record> &list)
//	Pre:	Should be used with TestOne Function.
//	Post:	Output message about time of binary searching all the words.
{
	QueryPerformanceFrequency(&frequ);
	QueryPerformanceCounter(&start);
	result = BinarySearch(list, word, position);
	QueryPerformanceCounter(&over);
	cout << left << setw(25) << "Binary Search time: " << fixed 
		 << (over.QuadPart - start.QuadPart) / (double)frequ.QuadPart << "(s)." << endl;
}

void CmdCaseCtrl::TestOneByHashSearch(const HashTable &hash)
//	Pre:	Should be used with TestOne Function.
//	Post:	Output message about time of Hash searching all the words.
{
	QueryPerformanceFrequency(&frequ);
	QueryPerformanceCounter(&start);
	result = HashSearch(hash, word, target);
	QueryPerformanceCounter(&over);
	cout << left << setw(25) << "Hash Search time: " << fixed
		 << (over.QuadPart - start.QuadPart) / (double)frequ.QuadPart << "(s).\n"
		 << "collide time:     " << hash.GetCollideTime() << endl;	//for Hash Search
}

void CmdCaseCtrl::UpdateState(bool &isAccurate, bool &isList) const
//	Post:	Write the state stored in the CmdCaseCtrl Class to the
//			parameters.
//	Uses:	function WriteOutSearchState and WriteOutStorageState.
{
	WriteOutSearchState(isAccurate);
	WriteOutStorageState(isList);
}

void CmdCaseCtrl::WriteOutSearchState(bool &isAccurate) const
//	Post:	Write the state stored in the CmdCaseCtrl Class to the
//			parameter.
{
	isAccurate = searchState;
}

void CmdCaseCtrl::WriteOutStorageState(bool &isList) const
//	Post:	Write the state stored in the CmdCaseCtrl Class to the
//			parameter.
{
	isList = storageState;
}

//*******************************************************************

Error_code SequentialSearch(const List<Record> &l, const Key &target, int &pos)
//	Post:	To search the list l for the target key. If found, pos is 
//			updated and return success, else return not_present, pos
//			becomes invalid -- equal to the size of list l.
{
	int size = l.Size();
	Record currentKey;
	for (pos = 0; pos < size; pos++)
	{
		l.Retrieve(pos, currentKey);
		if (target == currentKey)	return success;
	}
	return not_present;
}

Error_code BinarySearch(const List<Record> &l, const Key &target, int &pos)
//	Pre:	Must be ordered before using this function.
//	Post:	To search the list l for the target key. If found, pos is 
//			updated and return success, else return not_present, pos
//			becomes invalid -- equal to the size of list l.
{
	Record data;
	int bottom = 0, top = l.Size() - 1;
	while (bottom <= top)
	{
		pos = (bottom + top) / 2;
		l.Retrieve(pos, data);
		if (data == target)	return success;
		if (data < target)	bottom = pos + 1;
		else top = pos - 1;
	}
	return not_present;
}

Error_code HashSearch(const HashTable &h, const Key &target, Record &found)
//	Pre:	Must be Hash Table.
//	Post:	To search the Hash Table h for the target key. If found, pos is 
//			updated and return success, else return not_present, pos
//			becomes invalid -- equal to the size of Hash Table l.
{
	return h.Retrieve(target, found);
}

void PrintVolcabulary(const List<Record> &l)
//	Post:	all entries in the vocabulary  is printed, each per line.
//			IF list is empty, output error message"Vocabulary empty."
{
	if (l.Empty())	cerr << "Error: Vocabulary empty." << endl;
	else
	{
		Record temp;
		/*for (int i = 0; i < l.Size(); i++)
		{
		l.Retrieve(i, temp);
		cout << temp.GetNum() << ' ' << ((Key)temp).GetKey()
		<< ' ' << temp.GetFreqency() << ' ' << temp.GetExplanation() << endl;
		}*/
		for (int i = 0; i < l.Size(); i++)
		{
			l.Retrieve(i, temp);
			printf("%d %s ", temp.GetNum(), ((Key)temp).GetKey());
			printf("%d %s\n", temp.GetFreqency(), temp.GetExplanation());
		}
		cout << flush;
	}
}

void PrintVolcabulary(const List<Record> &l, const HashTable &h)
{
	Record rc, temp;
	for (int i = 0; i < l.Size(); i++)
	{
		l.Retrieve(i, rc);
		h.Retrieve(((Key)rc).GetKey(), temp);
		printf("%d %s ", temp.GetNum(), ((Key)temp).GetKey());
		printf("%d %s\n", temp.GetFreqency(), temp.GetExplanation());
	}
}