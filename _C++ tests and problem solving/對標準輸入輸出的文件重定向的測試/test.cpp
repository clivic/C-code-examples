//*******************************************************************
//	���˜�ݔ��(cin)ݔ��(cout)���ļ��ض���Ĝyԇ
//	�҂���D:\Data.txt�d���ļ���ݔ����D:\Out.txt,
//	����exe�ļ������}�u��D����Ŀ��K������test.exe(���˷���ݔ��)
//	��cmd����D:\test.exe <D:\Data.txt >D:\Out.txt
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