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

NormalAccount::NormalAccount(int number, char *name, double money, float ratio) : Account(number, name, money), interest(ratio)
{ }
bool NormalAccount::Deposit(double money)
{
	return Account::Deposit(money)*Account::Deposit(GetDepositInterest(this->interest));
}
int  NormalAccount::GetDepositInterest(float interest)
{
	return Account::GetBalance()*interest;
}
void NormalAccount::ShowAllInfo()const {
	std::cout << "������� �Դϴ�." << std::endl;
	Account::ShowAllInfo();
}

HightCreditAccount::HightCreditAccount(int number, char *name, double money, float ratio, int special) : NormalAccount(number, name, money, ratio), specialRate(special) {}
bool HightCreditAccount::Deposit(double money)
{
	return NormalAccount::Deposit(money)*Account::Deposit(GetExtraInterest(grade / 100.0));
}
int HightCreditAccount::GetExtraInterest(float interest)
{
	return Account::GetBalance()*interest;
}
void HightCreditAccount::ShowAllInfo()const
{
	std::cout << "�ſ����" << "_��� :" << grade <<std::endl;
	Account::ShowAllInfo();
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
			account[i]->Deposit(temp_money);
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
			account[i]->Withdraw(temp_money);
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
	int number, balance, type, grade;
	char name[LEN_NAME];
	float interest;
	numberOfguest++;
	std::cout << "Enter your account number." << std::endl;
	std::cin >> number;

	std::cout << "Enter your account name." << std::endl;
	std::cin >> name;

	std::cout << "Enter your account BALANCE." << std::endl;
	std::cin >> balance;

	std::cout << "What kind of account do you want?" << std::endl;
	std::cout << "0-�����ڰ���, 1->���뿡�ݰ���, 2->�ſ�ŷڰ���" << std::endl;
	std::cin >> type;
	
	switch (type) {
	case ACCOUNT_TYPE::ONLY_DEPOSIT:
		account[numberOfguest] = new Account(number, name, balance);
		break;
	case ACCOUNT_TYPE::NORMAL :
		std::cout << "������";
		std::cin >> interest;
		account[numberOfguest] = new NormalAccount(number, name, balance, interest);
		break;
	case ACCOUNT_TYPE::HIGHCREDIT :
		std::cout << "������ : ";
		std::cin >> interest;
		std::cout << "�ſ��� : ";
		std::cin >> grade;
		account[numberOfguest] = new HightCreditAccount(number, name, balance, interest,grade);
		break;
	default :
			break;
	}
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