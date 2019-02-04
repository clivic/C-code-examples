/**************************************************************************************************
This program tests for friend function.
**************************************************************************************************/
#include <iostream>

using namespace std;

class Myclass
{
protected:
	int a1;
private:
	int a2;
public:
	Myclass();
	friend void printMyclass();				//��Ԫ��������������(���{�ò���class�Y������ݡ�
	friend void printMyclass(Myclass m);	//��Ԫ���������֮��Ҳ�S�ͺ����ˡ�
};

//*************************************************************************************************

Myclass::Myclass()
{
	a1 = 1;
	a2 = 2;
}

//void Myclass::printMyclass()				//��Ԫ��������class�ɆT����
void printMyclass()
{
	//cout << a1 << a2 << endl;				//����ֱ���@�Ӂ�
}

void printMyclass(Myclass m)
{
	cout << m.a1 << "   " << m.a2;			//�{��˽�Д���
}

//*************************************************************************************************
//Driver of this test
/*void main()
{
	Myclass m1, m2;
	//cout<<endl<<"Here is m1.printMyclass(m2):"<<endl;
	//m1.printMyclass(m2);					//߀����Ԫ��������class�ɆT����
	cout << endl << "Here is printMyclass(m2):" << endl;
	printMyclass(m2);
	cout << endl;
}*/

/*	���ԣ�
	��Ԫ��������class�Y������friend֮�ᾎ�g���J������class scope����ȫ�ֺ�����
	���䶨�x�t������ȫ�ֶ��x���Õrһ�㌢class��һ��׃������酢�������֮��
	�@�r�҂�����Բٿش�class������ģ��������ٿ���˽�Д�����
	�ʏ�ĳ�����v�@����ȫҲ�S��
*/