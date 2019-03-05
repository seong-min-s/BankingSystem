#include "dec.h"//�Լ� �Ǵ� ��������

void Account::CreateAccount(int number, char* name)
{
	strcpy(this->name, name);
	this->number = number;
}
int Account::GetAccountNumber()
{
	return this->number;
}
char* Account::GetAccountName()
{
	return this->name;
}
double Account::GetAccountBanlance() {
	return this->left;
}
bool Account::DepositAccount(int money) {
	if (money < 0) {
		return false;
	}else {
		this->left=+money;
	}
}
bool Account::WithdrawAccount(int money) {
	if (money < 0) {
		return false;
	}
	else {
		this->left=-money;
	}
}
void BankingSystem::CreateAccount() {
	int number;
	char name[20];
	numberOfAccount++;
	std::cout << "Enter your account number." << std::endl;
	std::cin >> number;
	std::cout << "Enter your account name." << std::endl;
	std::cin >> name;
	account[numberOfAccount].CreateAccount(number, name);
}
void BankingSystem::DepositAccount()
{
	int temp_number;
	double temp_money;
	std::cout << "��     ��" << std::endl;
	std::cout << "���� ID :" << std::endl;
	std::cin >> temp_number;
	std::cout << "�Ա� �� :" << std::endl;
	std::cin >> temp_money;
	//���¸� ã�� ����
	for (int i = 0; i <= numberOfAccount; i++)
	{
		if (account[i].GetAccountNumber() == temp_number)
		{
			if(account[i].DepositAccount(temp_money))
				break;
			else {
				std::cout << "error <deposit>" << std::endl;
			}
		}
	}
	std::cout << "�Ա� �Ϸ�" << std::endl;
}
void BankingSystem::WithdrawMoney()
{
	int temp_number;
	double temp_money;
	std::cout << "��     ��" << std::endl;
	std::cout << "���� ID :" << std::endl;
	std::cin >> temp_number;
	std::cout << "��� �� :" << std::endl;
	std::cin >> temp_money;
	for (int i = 0; i <= numberOfAccount; i++)
	{
		if (account[i].GetAccountNumber() == temp_number)
		{
			if (account[i].WithdrawAccount(temp_money))
				break;
			else {
				std::cout << "error <withdraw>" << std::endl;
			}
		}
	}
	std::cout << "��� �Ϸ�" << std::endl;
}
void BankingSystem::Display() 
{
	for (int i = 0; i <= numberOfAccount; i++)
	{
		std::cout << "�̸� :" << account[i].GetAccountName() << std::endl;
		std::cout << "���� ��ȣ :" << account[i].GetAccountNumber() << std::endl;
		std::cout << "�ܾ� :" << account[i].GetAccountBanlance()<< std::endl;
		std::cout << std::endl;
	}
}
void BankingSystem::ShowMenu()
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