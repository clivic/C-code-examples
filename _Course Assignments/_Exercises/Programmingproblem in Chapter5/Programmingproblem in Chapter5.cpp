#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

void main()
{
	//No.1 
	cout << "No.1" << endl << endl;
	cout << "This program is to inform of the CAO alphabet word corresponding to English letters."
		 << endl 
		 << "Please input the letter in english, and we will translate it into CAO." << endl;
	char letter;
	//Now its a test first. We will test 26 times.
	//Test has already be done successfully.
	/*int i(0);
	while (i<26)
	{*/
	cin >> letter;
	if (letter == 'a' || letter == 'A')
		cout << "You've input \"a\" or \"A\". And it is \"Alpha\"." << endl << endl; 
	else if (letter == 'b' || letter == 'B')
		cout << "You've input \"b\" or \"B\". And it is \"Bravo\"." << endl << endl; 
	else if (letter == 'c' || letter == 'C')
		cout << "You've input \"c\" or \"C\". And it is \"Charlie\"." << endl << endl; 
	else if (letter == 'd' || letter == 'D')
		cout << "You've input \"d\" or \"D\". And it is \"Delta\"." << endl << endl; 
	else if (letter == 'e' || letter == 'E')
		cout << "You've input \"e\" or \"E\". And it is \"Echo\"." << endl << endl; 
	else if (letter == 'f' || letter == 'F')
		cout << "You've input \"f\" or \"F\". And it is \"Foxtrot\"." << endl << endl; 
	else if (letter == 'g' || letter == 'G')
		cout << "You've input \"g\" or \"G\". And it is \"Golf\"." << endl << endl; 
	else if (letter == 'h' || letter == 'H')
		cout << "You've input \"h\" or \"H\". And it is \"Hotel\"." << endl << endl; 
	else if (letter == 'i' || letter == 'I')
		cout << "You've input \"i\" or \"I\". And it is \"India\"." << endl << endl; 
	else if (letter == 'j' || letter == 'J')
		cout << "You've input \"j\" or \"J\". And it is \"Juliet\"." << endl << endl; 
	else if (letter == 'k' || letter == 'K')
		cout << "You've input \"k\" or \"K\". And it is \"Kilo\"." << endl << endl; 
	else if (letter == 'l' || letter == 'L')
		cout << "You've input \"l\" or \"L\". And it is \"Lima\"." << endl << endl; 
	else if (letter == 'm' || letter == 'M')
		cout << "You've input \"m\" or \"M\". And it is \"Mike\"." << endl << endl; 
	else if (letter == 'n' || letter == 'N')
		cout << "You've input \"n\" or \"N\". And it is \"November\"." << endl << endl; 
	else if (letter == 'o' || letter == 'O')
		cout << "You've input \"o\" or \"O\". And it is \"Oscar\"." << endl << endl; 
	else if (letter == 'p' || letter == 'P')
		cout << "You've input \"p\" or \"P\". And it is \"Papa\"." << endl << endl; 
	else if (letter == 'q' || letter == 'Q')
		cout << "You've input \"q\" or \"Q\". And it is \"Quebec\"." << endl << endl; 
	else if (letter == 'r' || letter == 'R')
		cout << "You've input \"r\" or \"R\". And it is \"Romeo\"." << endl << endl; 
	else if (letter == 's' || letter == 'S')
		cout << "You've input \"s\" or \"S\". And it is \"Sierra\"." << endl << endl; 
	else if (letter == 't' || letter == 'T')
		cout << "You've input \"t\" or \"T\". And it is \"Tango\"." << endl << endl; 
	else if (letter == 'u' || letter == 'U')
		cout << "You've input \"u\" or \"U\". And it is \"Uniform\"." << endl << endl; 
	else if (letter == 'v' || letter == 'V')
		cout << "You've input \"v\" or \"V\". And it is \"Victor\"." << endl << endl; 
    else if (letter == 'w' || letter == 'W')
		cout << "You've input \"w\" or \"W\". And it is \"Whiskey\"." << endl << endl; 
	else if (letter == 'x' || letter == 'X')
		cout << "You've input \"x\" or \"X\". And it is \"X-ray\"." << endl << endl; 
	else if (letter == 'y' || letter == 'Y')
		cout << "You've input \"y\" or \"Y\". And it is \"Yankee\"." << endl << endl; 
	else if (letter == 'z' || letter == 'Z')
		cout << "You've input \"z\" or \"Z\". And it is \"Zulu\"." << endl << endl;
	else
		cout << "There are no code name for this character. May be it isn't an English letter."
			 << endl << endl << endl;
	/*i++;*/
	

	//No.2
	//This is the first edition.
	//version 1.0.0
	cout << "No.2" << endl << endl;
	cout << "This program is to let you know how you weigh on the planet or other named asters "
		 << "in solar system." << endl;
	cout << "Please input your weight of kilo first and then enter the exact name of the planet." << endl
		 << "Tips: there are 9 planets in solar system, and you can also input \"moon\"." << endl
		 << "And the first character should be capitalized." << endl;
	double weight;
	double mer(0.4155),
		   ven(0.8975),
		   ear(1.0000),
		   moo(0.1660),
		   mar(0.3507),
		   jup(2.5374),
		   sat(1.0677),
		   ura(0.8947),
		   nep(1.1794),
		   plu(0.0899);
	
	string name;
	cin >> weight >> name;
	
	if (name == "Mercury")
	{
		cout << "Your weight entered is " << weight << " kilograms, " << "and you weigh on the Mercury--" << endl
			 << mer * weight << " kilograms." << endl;
	}
	else if (name == "Venus")
	{
		cout << "Your weight entered is " << weight << " kilograms," << "and you weigh on the Venus--" << endl
			 << ven * weight << " kilograms." << endl;
	}
	else if (name == "Earth")
	{
		cout << "Your weight entered is " << weight << " kilograms," << "and you weigh on the Earth--" << endl
			 << ear * weight << " kilograms." << ", exactly your weight input hah!" << endl;
	}
	else if (name == "Moon")
	{
		cout << "Your weight entered is " << weight << " kilograms," << "and you weigh on the Moon--" << endl
			 << moo * weight << " kilograms." << endl;
	}
	else if (name == "Mars")
	{
		cout << "Your weight entered is " << weight << " kilograms," << "and you weigh on the Mars--" << endl
			 << mar * weight << " kilograms." << endl;
	}
	else if (name == "Jupiter")
	{
		cout << "Your weight entered is " << weight << " kilograms," << "and you weigh on the Jupiter--" << endl
			 << jup * weight << " kilograms." << endl;
	}
	else if (name == "Saturn")
	{
		cout << "Your weight entered is " << weight << " kilograms," << "and you weigh on the Saturn--" << endl
			 << sat * weight << " kilograms." << endl;
	}
	else if (name == "Uranus")
	{
		cout << "Your weight entered is " << weight << " kilograms," << "and you weigh on the Uranus--" << endl
			 << ura * weight << " kilograms." << endl;
	}
	else if (name == "Neptune")
	{
		cout << "Your weight entered is " << weight << " kilograms," << "and you weigh on the Neptune--" << endl
			 << plu * weight << " kilograms." << endl;
	}
	else if (name == "Pluto")
	{
		cout << "Your weight entered is " << weight << " kilograms," << "and you weigh on the Pluto--" << endl
			 << plu * weight << " kilograms." << endl;
	}
	else
		cout << "Perhaps the planet you've entered hasn't been detected in solar system hah..." << endl
		     << "Please enter the name again in the next running of this program." << endl;

	//No.3
	cout << endl << "No.3" << endl << endl;
	cout << "This program is to output the month name corresponding to the number." << endl
		 << "For example: 12 input and \"December\" yield." << endl;
	cout << "Then please input the number in the range of 1 to 12: " << endl;
	int num;
	string monthName;
	cin >> num;
	if (!(num > 12 || num < 1))
	{ 
		 if (num == 1)
			monthName = "January";
		 else if (num == 2)
			monthName = "February";
		 else if (num == 3)
			monthName = "March";
		 else if (num == 4)
			monthName = "April";
		 else if (num == 5)
			monthName = "May";
		 else if (num == 6)
			monthName = "June";
		 else if (num == 7)
			monthName = "July";
		 else if (num == 8)
			monthName = "August";
		 else if (num == 9)
			monthName = "September";
		 else if (num == 10)
			monthName = "October";
		 else if (num == 11)
			monthName = "November";
		 else if (num == 12)
			monthName = "December";
		cout << "Then your input number " << num << " corresponds to " << monthName << " ." << endl;
	}

	else
	{
		cout << "You haven't entered the proper number. Please reenter it when rerunning this program." << endl; 
	}

	//No.8
	//1). three numbers.
	double a, b, c, median;
	cout << endl << "No.8" << endl << endl;
	cout << "1). We compute the median of three numbers." << endl;
	cout << "Please input three real numbers." << endl;
	cin >> a >> b >> c;
	
	if (a > b)
		if (b > c)
			median = b;
		else if (a > c)
			median = c;
		else 
			median = a;

	else if (a > c)
			median = a;
		else if (c > b)
			median = b;
		else
			median = c;

	cout << "Then the median of " << a << ", " << b << ", and " << c << " is " << median << "." << endl << endl;

	/*The statement of if clause above could execute successively without braces.*/

	//2). five numbers.
	double d, e, tem; //temporary unit for identifier tem.
	//so called "bubble solution."
	cout << "2). Now we come to the median of five numbers." << endl;
	cout << "Please input five real numbers." << endl;
	cin >> a >> b >> c >> d >> e;
	
	//first bubble
	if (a > b)
	{
		tem = b;   b = a;	a = tem; //exchange position
	}
	if (b > c)
	{ 
		tem = c;   c = b;	b = tem;
	}
	if (c > d)
	{
		tem = d;   d = c;	c = tem;
	}
	if (d > e)
	{
		tem = e;   e = d;	d = tem;
	}
	
	//second bubble
	if (a > b)
	{
		tem = b;   b = a;	a = tem;
	}
	if (b > c)
	{ 
		tem = c;   c = b;	b = tem;
	}
	if (c > d)
	{
		tem = d;   d = c;	c = tem;
	}
	if (d > e)
	{
		tem = e;   e = d;	d = tem;
	}

	//third bubble
	if (a > b)
	{
		tem = b;   b = a;	a = tem;
	}
	if (b > c)
	{ 
		tem = c;   c = b;	b = tem;
	}
	if (c > d)
	{
		tem = d;   d = c;	c = tem;
	}
	if (d > e)
	{
		tem = e;   e = d;	d = tem;
	}

	//forth bubble
	if (a > b)
	{
		tem = b;   b = a;	a = tem;
	}
	if (b > c)
	{ 
		tem = c;   c = b;	b = tem;
	}
	if (d > e)
	{
		tem = e;   e = d;	d = tem;
	}
	
	median = c;
	cout << "Then the median of " << a << ", " << b << ", " << c << ", " << d << ", and " << e << " is " 
		 << median << "." << endl << endl;
}
