#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int height, width, area;
	ifstream fin;

	fin.open("measures.dat");
	if (!fin)
	{
		cout << "Can't open data." << endl;
		return 1;
	}
	fin >> height >> width;
	area = height * width;
	cout << "For the height of " << height << endl
		 << "And the width of " << width << endl
		 << "The area is " << area << endl;
	return 0;
}