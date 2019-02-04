#include <fstream>

using namespace std;

void main()
{ 
	int a,b,c,d,e,f;
	char ch1;
	ifstream fin;
	ofstream fout;

	fin.open("data.txt");
	fout.open("result.out");

	fin >> a >> b >> c;
	fin.ignore(100,'\n');
	fin.get(ch1);
	fin >> d >> e >> f;
	fin.ignore(100,'\n');
	fin.ignore(100,'\n');
	fin >> a >> b;

	fout << a << '\t' << b << '\t'
		 << c << '\t' << d << '\t' 
		 << e << '\t' << f << '\t'
		 << ch1 << endl;
}
