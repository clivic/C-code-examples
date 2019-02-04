#include <iostream>
#include <string>

using namespace std;

//specification
class AccountType
{
public:
	AccountType(int money);
	
	AccountType();

	void Set(string id, string n, int m);

	void Deposit(int money);  

	void Withdraw(int money);

	int getBalance();

	void WriteAccount();

private:
	string Id;
	string name;
	long balance;
};

//implementation
AccountType::AccountType(int money)
{
	balance = money;
}

AccountType::AccountType()
{	
	balance = 0;
}

void AccountType::Set(string id, string n, int m)
{
	Id = id;
	name = n;
	balance = m;
}

void AccountType::Deposit(int money)
{
	balance += money;
}

void AccountType::Withdraw(int money)
{
	balance -= money;
}

int AccountType::getBalance()
{
	return balance;
}

void AccountType::WriteAccount()
{
	cout << Id << ' ' << name << ' ' << balance;
}

//***********************************************

int main()
{
	string id;
	string name;
	int balance;
	int dMoney;
	int wMoney;
	cin >> id >> name >> balance;

	
	cin >> dMoney;
	cin >> wMoney;
	AccountType account(balance);
	account.Set(id, name, balance);
	account.Deposit(dMoney);
	account.Withdraw(wMoney);
	account.WriteAccount();
	
	return 0;
}

	



