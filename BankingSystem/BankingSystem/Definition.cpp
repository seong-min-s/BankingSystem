#include "dec.h"//�Լ� �Ǵ� ��������

int numberOfguest = -1;
guest_info guest[100];
void CreateAccount() {
	numberOfguest++;
	std::cout << "Enter your account number." << std::endl;
	std::cin >> guest[numberOfguest].number;

	std::cout << "Enter your account name." << std::endl;
	std::cin >> guest[numberOfguest].name;

	guest[numberOfguest].left = 0;
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
		if (guest[i].number == temp_number)
		{
			guest[i].left += temp_money;
			break;
		}
	}
	guest[temp_number].left += temp_money;
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
		if (guest[i].number == temp_number)
		{
			guest[i].left -= temp_money;
			break;
		}
	}
	std::cout << "��� �Ϸ�" << std::endl;
}
void Display()
{
	for (int i = 0; i <= numberOfguest; i++)
	{
		std::cout << "�̸� :" << guest[i].name << std::endl;
		std::cout << "���� ��ȣ :" << guest[i].number << std::endl;
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