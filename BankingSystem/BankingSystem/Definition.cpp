#include "dec.h"//�Լ� �Ǵ� ��������

int numberOfguest = -1;
Account account[100];
bool Account::InitAccount(int number, char *name, double balance) {
	if (number < 0) {
		return false;
	}else {
		this->number = number;
	}
	if (balance < 0) {
		return false;
	}else {
		this->balance = balance;
	}
	return true;
}
void CreateAccount() {
	numberOfguest++;
	int number, balance;
	char name[LEN_NAME];//�����߻�
	std::cout << "Enter your account number." << std::endl;
	std::cin >>number;

	std::cout << "Enter your account name." << std::endl;
	std::cin >>name;

	std::cout << "Enter your account BALANCE." << std::endl;
	std::cin >> balance;
	account[numberOfguest].InitAccount(number, name, balance);
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
int Account::GetNumber()
{
	return this->number;
}
char* Account::GetName()
{
	return this->name;
}
double Account::GetBalance()
{
	return this->balance;
}
void DepositAccount()
{
	int temp_number;
	double temp_money;
	std::cout << "��     ��" << std::endl;
	std::cout << "���� ID :" << std::endl;
	std::cin >> temp_number;
	std::cout << "�Ա� �� :" << std::endl;
	std::cin >> temp_money;
	//���¸� ã�� ����
	for (int i = 0; i <= numberOfguest; i++)
	{
		if (account[i].GetNumber()== temp_number)
		{
			account[i].SetBalance(DEPOSIT, temp_money);
			std::cout << "�Ա� �Ϸ�" << std::endl;
			break;
		}
	}
}
void WithdrawMoney()
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
		if (account[i].GetNumber() == temp_number)
		{
			account[i].SetBalance(WITHDRAW, temp_money);
			std::cout << "��� �Ϸ�" << std::endl;
			break;
		}
	}
}
void Display()
{
	for (int i = 0; i <= numberOfguest; i++)
	{
		std::cout << "�̸� :" << account[i].GetName() << std::endl;
		std::cout << "���� ��ȣ :" << account[i].GetNumber() << std::endl;
		std::cout << "�ܾ� :" << account[i].GetBalance() << std::endl;
		std::cout << std::endl;
	}
}
void ShowMenu()
{
	std::cout << "-----MENU-----" << std::endl;
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. ��    ��" << std::endl;
	std::cout << "3. ��    ��" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. ���α׷� ����" << std::endl;
}
/*
�� �������� ����ü ����
typedef struct guest_info{
	int number;
	char name[20];
	int left;
}guest_info;
*/