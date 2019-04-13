#include "Account.h"

Account::Account(int number, mystring name, double money) : accID(number), balance(money) {
	cusName = name;
}
Account::Account(const Account &copy) : accID(copy.accID), balance(copy.balance) {
	cusName = copy.cusName;
}
Account& Account::operator=(const Account& copy) {
	cusName = copy.cusName;
	this->accID = copy.accID;
	this->balance = copy.balance;
	return *this;
}
Account::~Account() {
	
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
mystring Account::GetName() const//이름을 얻는 과정에서 오류발생
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