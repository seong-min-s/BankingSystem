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
	char *name;
	std::cout << "Enter your account number." << std::endl;
	std::cin >>number;

	std::cout << "Enter your account name." << std::endl;
	std::cin >>name;

	std::cout << "Enter your account name." << std::endl;
	std::cin >> balance;
	account[numberOfguest].InitAccount(number, name, balance);
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
		if (account[i].number == temp_number)
		{
			account[i].left += temp_money;
			break;
		}
	}
	account[temp_number].balance += temp_money;
	std::cout << "�Ա� �Ϸ�" << std::endl;
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
		if (account[i].number == temp_number)
		{
			account[i].left -= temp_money;
			break;
		}
	}
	std::cout << "��� �Ϸ�" << std::endl;
}
void Display()
{
	for (int i = 0; i <= numberOfguest; i++)
	{
		std::cout << "�̸� :" << account[i].name << std::endl;
		std::cout << "���� ��ȣ :" << account[i].number << std::endl;
		std::cout << "�ܾ� :" << guest[i].left << std::endl;
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