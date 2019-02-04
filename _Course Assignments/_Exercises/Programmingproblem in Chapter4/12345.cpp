#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.1415926535897932384626;
const double MOONR = 1738.3;                //Moon's radius
void main()
{
	//No.1
	cout << "No.1" << endl << endl;
	cout << "please enter the name in \"last, first middle\" format" << endl;
	string name, firstMiddle, last;
	getline(cin, name);
	last = name.substr(0, name.find(","));
	firstMiddle = name.substr(name.find(",") + 2, name.length() - last.length() - 2);
	cout << "The format is: " << endl
		 << firstMiddle << " " << last << endl << endl << endl;
	

	//No.2
	cout << "No.2" << endl << endl;
	cout << "Please input 12 different temperatures, using whitespace to seperate them. " << endl 
		 << "And we will output the 12 temperatures, and the difference between the cur-" << endl
		 << "rent temperature and the one preceding it. And you will also see the avera-" << endl
		 << "ge temperature output on the screen." << endl;
	string temp;
	double a,b,c,d,e,f,g,h,i,j,k,l;
	cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
	
	ofstream fout;
	
	fout.open("tempdata.dat");

	fout << a << endl 
		 << b << " " << b-a << endl
		 << c << " " << c-b << endl
		 << d << " " << d-c << endl
		 << e << " " << e-d << endl
		 << f << " " << f-e << endl
		 << g << " " << g-f << endl
		 << h << " " << h-g << endl
		 << i << " " << i-h << endl
		 << j << " " << j-i << endl
		 << k << " " << k-j << endl
		 << l << " " << l-k << endl;
	cout << "The data is stored successfully! And the average temperature is: " << endl
         << (a+b+c+d+e+f+g+h+i+j+k+l)/12 << endl << endl << endl;
	fout.close();
	

	//No.3
	
	int x1,x2,x3,x4;
	float xbar;
	cout << "No.3 " << endl << endl;
    
	//interactive input
	cout << "Please input x1, x2, x3, x4 in order "					
		 << "meanwhile remember they should be integers."
		 << endl;
	cin >> x1 >> x2 >> x3 >> x4;
	xbar = (float(x1+x2+x3+x4)) / 4.0f;
	
	//echo printing
	cout << "For the input 4 integer values: " << endl
		 << a << ' ' << b << ' ' << c << ' ' << d << ' ';
	cout << "The mean of these values is: " << fixed
		 << setprecision(2) << xbar << endl;
	cout << "And the standard deviation is: "
		 << sqrt((pow((float(x1)-xbar), 2) + pow((float(x2)-xbar), 2)
		  + pow((float(x3)-xbar), 2) + pow((float(x4)-xbar), 2)) / 3.0f)
		 << endl << endl << endl;
	
	//No.4
	//This problem is to find the word behind each first three occured commas in a file 
	//whose name is input by users.

	ifstream fin;
	string str, fileName, first, second, third;

	cout << "No.4" << endl << endl;
	cout << "This problem is to find the word behind each first three occured commas in "
		 << endl << "a file whose name is input by users." << endl;
	cout << "Please enter the input data name:" << endl;
	cin >> fileName;
	fin.open(fileName.c_str());//convert to cstring
	
	fin.ignore(10000, ',');//using ignore to find words
	fin >> first;
	fin.ignore(10000, ',');
	fin >> second;
	fin.ignore(10000, ',');
	fin >> third;

	cout << "Then for the file \"" << fileName << "\" the words are:" << endl;
	cout << first << endl << second << endl << third << endl << endl << endl;

	/*The points should be nooticed: 
	1. fin.ignore(len,char) is a void function, and one of the fin's operation.
	2. the second argument in fin.ignore(len,char) is a CHAR TYPE!
	3. fstream/iostream class have get, ignore, and string class have substr, length, find, size... they all have periods before them
	4. the argument of s.find(str/char) could also be char type.
	5. get getline ignore fin.open fout.close are all void function.*/
	

	//No.5
    
	//Interactive input
	double sita, square; 
	cout << "No.5" << endl << endl;
	cout << "This program is to caculate the surface area of the percentage "
		 << "which input by user of the moon's face that appears illuminated."
		 << endl;
	cout << "Please input the percentage appears illuminated in the format:" 
		 << endl << "num% , eg. 56%" << endl;
	cin >> sita;
	cin.ignore(1, '\n');
	sita = sita / 100;
	square = 2 * pow(MOONR, 2) * sita * PI;

	//echo printing
	cout << "For the percentage printed, the surface area of that percentage "
		 << "is:" << endl 
		 << fixed << setprecision(3) << square << " kilometres." << endl
		 << "Thank you for your using!" << endl;
	}
