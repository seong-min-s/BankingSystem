#include "BankingSystem.h"
#include "Account.h"
Account::Account() {};
Account::Account(int number, char *name, double money) : accID(number), balance(money) {
	this->cusName = new char[strlen(name) + 1];//문제요구사항 : 멤버변수로 문자열 포인터를 지니고, 동적 할당의 형태로 구현해야 한다.
	strcpy(this->cusName, name);
}
Account::Account(const Account &copy) : accID(copy.accID), balance(copy.balance) {
	this->cusName = new char[strlen(copy.cusName) + 1];
	strcpy(cusName, copy.cusName);
}
Account& Account::operator=(const Account& copy) {
	delete []this->cusName;
	this->cusName = new char[strlen(copy.cusName) + 1];
	strcpy(cusName, copy.cusName);
	this->accID = copy.accID;
	this->balance = copy.balance;
	return *this;
}
Account::~Account() {
	delete []cusName;
}

bool Account::Deposit(double money)
{
	if (money < 0) {
		std::cout << "Not Accurate Money" << std::endl;
		return false;
	}
	else {
		this->balance += money;
		return true;
	}
}
bool Account::Withdraw(double money)
{
	if (money < 0) {
		std::cout << "There's no money left in your Account" << std::endl;
		return false;
	}
	else {
		this->balance -= money;
		return true;
	}
}
int Account::GetNumber() const
{
	return accID;
}
char* Account::GetName() const//이름을 얻는 과정에서 오류발생
{
	return this->cusName;
}
double Account::GetBalance()const
{
	return this->balance;
}
void Account::ShowAllInfo() const
{
	std::cout << "이    름 : " << cusName << std::endl;
	std::cout << "계좌번호 : " << accID << std::endl;
	std::cout << "잔    액 : " << balance << std::endl;
}