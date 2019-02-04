//*******************************************************************
//	Key and Record's implementation for Micro dictionary
//*******************************************************************
#include "Key and Record.h"

int Key::comparisons = 0;

Key::Key(String s)
{
	key = s;
}

String Key::GetKey() const
//	Post:	return the key
{
	return key;
}

char Key::KeyLetter(int position) const
//	Post:	return the character in the key in the position.
{
	return key[position];
}

void Key::MakeBlank()
//	Post:	Clear the Key.
{
	key = "\0";
}

bool operator == (const Key &key1, const Key &key2)
//	Post:	if key1 == key2 return true, else return false.
{
	Key::comparisons++;
	return (key1.GetKey() == key2.GetKey());
}

bool operator > (const Key &key1, const Key &key2)
//	Post:	if key1 > key2 return true, else return false.
{
	Key::comparisons++;
	return (key1.GetKey() > key2.GetKey());
}

bool operator >= (const Key &key1, const Key &key2)
//	Post:	if key1 >= key2 return true, else return false.
{
	Key::comparisons++;
	return (key1.GetKey() >= key2.GetKey());
}

bool operator != (const Key &key1, const Key &key2)
//	Post:	if key1 != key2 return true, else return false.
{
	Key::comparisons++;
	return (key1.GetKey() != key2.GetKey());
}

bool operator < (const Key &key1, const Key &key2)
//	Post:	if key1 < key2 return true, else return false.
{
	Key::comparisons++;
	return (key1.GetKey() < key2.GetKey());
}

bool operator <= (const Key &key1, const Key &key2)
//	Post:	if key1 <= key2 return true, else return false.
{
	Key::comparisons++;
	return (key1.GetKey() <= key2.GetKey());
}

//*******************************************************************

//Record::Record()
////	Post:	initialize the Record class, make it empty with illegal 
////			number -1, empty word and explanation, and frequency 0.
//{
//	Key tmp;
//	WriteAll(-1, tmp, 0, "");
//}

Record::Record(int num, Key key, int freq, String expl)
//	Post:	initialize the Record class, according to the list.
//			If not given completely, default parameters are assigned.
{
	WriteAll(num, key, freq, expl);
}

Record::operator Key()
//	Post:	the Type Record is converted to Type Key, which is the 
//			key of the record.
{
	return word;
}

Key Record::GetKey() const
//	Post:	return the Key -- the word.
{
	return word;
}

int Record::GetNum() const
//	Post:	return the number of the word.
{
	return number;
}

int Record::GetFreqency() const
//	Post:	return the frequency of the number being searched.
{
	return frequency;
}

String Record::GetExplanation() const
//	Post:	return the explanation of the word.
{
	return explanation;
}

void Record::WriteNum(const int& number)
//	Post:	argument is written in the corresponding feature.
{
	this->number = number;
}

void Record::WriteWord(const Key& word)
//	Post:	argument is written in the corresponding feature.
{
	this->word = word;
}

void Record::WriteFrequency(const int& frequency)
//	Post:	argument is written in the corresponding feature.
{
	this->frequency = frequency;
}

void Record::WriteExplanation(const String& explanation)
//	Post:	argument is written in the corresponding feature.
{
	this->explanation = explanation;
}

void Record::WriteAll(const int& number, const Key& word,
					  const int& frequency, const String& explanation)
//	Post:	all argumens are written in the corresponding feature,
//			for convenience.
{
	WriteNum(number);
	WriteWord(word);
	WriteFrequency(frequency);
	WriteExplanation(explanation);
}