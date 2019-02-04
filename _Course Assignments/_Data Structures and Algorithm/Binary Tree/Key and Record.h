//*******************************************************************
//	Key and Record's specification for Micro dictionary
//	For this dictionary, the key is words string and the records 
//	contain details like chinese translations etc.
//*******************************************************************
#ifndef KEYRECORD
#define KEYRECORD
#include "List.h"
#include "String.h"

class Key
{
public:
	static int comparisons;		//for test
	Key(String s = "");			//constructor
	String GetKey() const;
	char KeyLetter(int position) const;
	void MakeBlank();			//for Hash Searching
protected:
	String key;
};

bool operator == (const Key &key1, const Key &key2);
bool operator > (const Key &key1, const Key &key2);
bool operator >= (const Key &key1, const Key &key2);
bool operator != (const Key &key1, const Key &key2);
bool operator < (const Key &key1, const Key &key2);
bool operator <= (const Key &key1, const Key &key2);

//*******************************************************************

class Record
{
public:
	//Record();
	Record(	int num = -1,
			Key key = (String)"", 
			int freq = 0, 
			String expl = "");
	operator Key();
	Key GetKey() const;
	int GetNum() const;
	int GetFreqency() const;
	String GetExplanation() const;
	void WriteNum(const int& number);
	void WriteWord(const Key& word);
	void WriteFrequency(const int& frequency);
	void WriteExplanation(const String& explanation);
	void WriteAll(const int& number,	const Key& word,
				  const int& frequency, const String& explanation);
private:
	int number;
	Key word;
	int frequency;
	String explanation;

};
#endif