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
	friend void printMyclass();				//友元函数，但不好用(因爲調用不了class裏面的内容。
	friend void printMyclass(Myclass m);	//友元函数，相比之上也許就好用了。
};

//*************************************************************************************************

Myclass::Myclass()
{
	a1 = 1;
	a2 = 2;
}

//void Myclass::printMyclass()				//友元函數不算class成員函數
void printMyclass()
{
	//cout << a1 << a2 << endl;				//不能直接這樣來
}

void printMyclass(Myclass m)
{
	cout << m.a1 << "   " << m.a2;			//調用私有數據
}

//*************************************************************************************************
//Driver of this test
/*void main()
{
	Myclass m1, m2;
	//cout<<endl<<"Here is m1.printMyclass(m2):"<<endl;
	//m1.printMyclass(m2);					//還是友元函數不算class成員函數
	cout << endl << "Here is printMyclass(m2):" << endl;
	printMyclass(m2);
	cout << endl;
}*/

/*	所以：
	友元函數聲明在class裏而加了friend之後編譯器認爲不是class scope而是全局函數。
	而其定義則順理成章為全局定義，用時一般將class的一個變量導入為參數來操作之。
	這時我們便可以操控此class（傳入的），包括操控其私有數據。
	故從某方面講這不安全也許。
*/