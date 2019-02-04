//*******************************************************************
//	對標準輸入(cin)輸出(cout)的文件重定向的測試
//	我們從D:\Data.txt載入文件，輸出到D:\Out.txt,
//	生成exe文件后將其複製至D槃根目錄下並改名為test.exe(爲了方便輸入)
//	用cmd打入D:\test.exe <D:\Data.txt >D:\Out.txt
//*******************************************************************
#include <iostream>

using namespace std;

int main()
{
	int num1, num2;
	cin >> num1 >> num2;
	cout << "Answer:" << num1 + num2 << endl;
	return 0;
}

//	Result:
//	Successful :)