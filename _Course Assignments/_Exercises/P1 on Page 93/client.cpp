//*******************************************************************
//	P1 on P93
//*******************************************************************
#include "D:\Visual C++ programs\Utility\Queue.cpp"

enum Out_put {NOCOLON, LLONG, RLONG, DIFFERENT, SAME};
void Introduction();
void Explanation();
void Read(
	/* out */ Queue <char>& a,
	/* out */ Queue <char>& b);
Out_put Compare(
	/* in */ Queue <char> a,
	/* in */ Queue <char> b);
void OutPut(/* in */ Out_put command);

int main()
//	Pre:	User enter two strings
//	Post:	situation is output
//	Uses:	class Queue and functions UserSayYes, Introductions,
//			Explanation, Read, Compare and Output.
{
	Queue <char> p, q;
	Introduction();
	Explanation();
	do
	{
		cin.clear();
		cin.sync();
		cout << "Please input the strings, seperated by \":\" "
			<< "and press <Enter> to continue:\n" << flush;
		Read(p, q);
		OutPut(Compare(p, q));
		cout << "Do you wanna continue? " << flush;
		p.Clear();
		q.Clear();
	} while (UserSayYes());
	return 0;
}

//*******************************************************************

void Introduction()
//	Pre:	none
//	Post:	introductions are output
{
	cout << "This is string compare program.\n" 
		<< "You enter two strings of letters seperated by colons,\n" 
		<< "And we give you an answer of comparing.\n"<< endl;
	cout << "Besides, each side should not contain more than "
		<< MAXQUEUE << " characters, if exceeded, that part will be"
		<< " ignored.\n" << endl;
}

void Explanation()
//	Pre:	none
//	Post:	explanations of the answer characters are output
{
	cout << "N: No colon on line.\n"
		<< "L: Left part(before semicolon) is longer than the right\n"
		<< "R: Right part(after semicolon) is longer than the left\n"
		<< "D: Left part has the same length as the right while different\n"
		<< "S: The left and right parts are exactly the same.\n" << endl;
}

void Read(
	/* out */ Queue <char>& a,
	/* out */ Queue <char>& b)
	//	Pre:	a, b should be empty queue
	//			&& it should be better not exceed the MAX of queue. 
	//	Post:	the left string user input is stored in queue a,
	//			the right is in queue b.
	//	Note:	if exceeded, that part will be ignored.
{
	char ch;
	cin.get(ch);
	bool isLeft = true;

	while (ch != '\n')
	{
		if (ch == ':')
			isLeft = false;

		else if (isLeft)
			a.Append(ch);
		else
			b.Append(ch);
		cin.get(ch);
	}
}

Out_put Compare(
	/* in */ Queue <char> a,
	/* in */ Queue <char> b)
	//	Pre:	queue a and b contains characters.
	//	Post:	return an output command.
{
	//	N
	if (b.Empty())	return NOCOLON;
	
	//	L
	//	R
	else if (a.Size() > b.Size())	return LLONG;
	else if (a.Size() < b.Size())	return RLONG;

	//	D
	//	S
	else
	{
		char chA, chB;
		bool same = true;
		for (int i = 0; i < a.Size() && same == true; i++)
		{
			a.ServeAndRetrieve(chA);
			b.ServeAndRetrieve(chB);
			same = (chA == chB);
		}
		if (same) return SAME;
		else	return DIFFERENT;
	}
}

void OutPut(/* in */ Out_put command)
//	Pre:	command is valid:	N, L, R, D, S
//	Post:	output a corresponding answer.
//	Note:	if command isn't valid, do nth.
{
	switch (command)
	{
	case NOCOLON:
		cout << "N" << endl;
		break;
	case LLONG:
		cout << "L" << endl;
		break;
	case RLONG:
		cout << "R" << endl;
		break;
	case DIFFERENT:
		cout << "D" << endl;
		break;
	case SAME:
		cout << "S" << endl;
		break;
	default:
		break;
	}
}