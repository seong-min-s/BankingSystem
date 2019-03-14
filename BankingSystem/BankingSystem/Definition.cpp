#include "dec.h"//�Լ� �Ǵ� ��������

int AccountHandler::numberOfguest = -1;
Account::Account(int number, char *name, double money) : accID(number), balance(money) {
	this->cusName = new char[strlen(name) + 1];//�����䱸���� : ��������� ���ڿ� �����͸� ���ϰ�, ���� �Ҵ��� ���·� �����ؾ� �Ѵ�.
	strcpy(this->cusName, name);
}
Account::Account(const Account &copy) :accID(copy.accID), balance(copy.balance) {
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

void AccountHandler::DepositAccount()
{
	int temp_number;
	double temp_money;
	std::cout << "��     ��" << std::endl;
	std::cout << "���� ��ȣ :(�̸� �ƴ�)" << std::endl;
	std::cin >> temp_number;
	std::cout << "�Ա� �ݾ� :" << std::endl;
	std::cin >> temp_money;
	//���¸� ã�� ����
	for (int i = 0; i <= numberOfguest; i++)
	{
		if (account[i]->GetNumber()== temp_number)
		{
			account[i]->SetBalance(DEPOSIT, temp_money);
			std::cout << "�Ա� �Ϸ�" << std::endl;
			break;
		}
	}
}
void AccountHandler::WithdrawMoney()
{
	int temp_number;
	double temp_money;
	std::cout << "��     ��" << std::endl;
	std::cout << "���� ID :" << std::endl;
	std::cin >> temp_number;
	std::cout << "��� �� :" << std::endl;
	std::cin >> temp_money;
	for (int i = 0; i <= numberOfguest; i++)
	{
		if (account[i]->GetNumber() == temp_number)
		{
			account[i]->SetBalance(WITHDRAW, temp_money);
			std::cout << "��� �Ϸ�" << std::endl;
			break;
		}
	}
}
void AccountHandler::Display() const
{
	for (int i = 0; i <= numberOfguest; i++)
	{
		account[i]->ShowAllInfo();
		std::cout << std::endl;
	}
}
void AccountHandler::CreateAccount() {
	int number, balance;
	char name[LEN_NAME];
	numberOfguest++;
	std::cout << "Enter your account number." << std::endl;
	std::cin >> number;

	std::cout << "Enter your account name." << std::endl;
	std::cin >> name;

	std::cout << "Enter your account BALANCE." << std::endl;
	std::cin >> balance;
	account[numberOfguest] = new Account(number, name, balance);
}
void AccountHandler::ShowMenu() const
{
	std::cout << "-----MENU-----" << std::endl;
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. ��    ��" << std::endl;
	std::cout << "3. ��    ��" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. ���α׷� ����" << std::endl;
}
AccountHandler::~AccountHandler() {
	for (int i = 0; i < AccountHandler::numberOfguest; i++) {
		delete[i]account;
	}
}