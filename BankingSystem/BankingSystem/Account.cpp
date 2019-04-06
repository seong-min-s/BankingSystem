#include "Account.h"
Account::Account(int number, char *name, double money) : accID(number), balance(money) {
	this->cusName = new char[strlen(name) + 1];//�����䱸���� : ��������� ���ڿ� �����͸� ���ϰ�, ���� �Ҵ��� ���·� �����ؾ� �Ѵ�.
	strcpy(this->cusName, name);
}
Account::Account(const Account &copy) : accID(copy.accID), balance(copy.balance) {
	this->cusName = new char[strlen(copy.cusName) + 1];
	strcpy(cusName, copy.cusName);
}
Account::~Account() {
	delete[]cusName;
}
bool Account::SetBalance(int COMMAND, double amount)
{
	if (amount < 0) {
		return false;
	}
	if (COMMAND == DEPOSIT)
	{
		this->balance += amount;
	}
	else if (COMMAND == WITHDRAW) {
		this->balance -= amount;
	}
	return true;
}
int Account::GetNumber() const
{
	return accID;
}
char* Account::GetName() const//�̸��� ��� �������� �����߻�
{
	return this->cusName;
}
double Account::GetBalance()const
{
	return this->balance;
}
void Account::ShowAllInfo() const
{
	std::cout << "��    �� : " << cusName << std::endl;
	std::cout << "���¹�ȣ : " << accID << std::endl;
	std::cout << "��    �� : " << balance << std::endl;
}