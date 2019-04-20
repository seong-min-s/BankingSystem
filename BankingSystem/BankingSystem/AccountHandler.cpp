#include "BankingSystem.h"//�Լ� �Ǵ� ��������
#include "AccountHandler.h"
#include "Account.h"
#include "HightCreditAccount.h"
#include "NormalAccount.h"
#include "AccountException.h"
AccountHandler::AccountHandler() :numberOfguest(0) {}

void AccountHandler::DepositAccount() throw (DepositException)
{
	int temp_number;
	double temp_money;
	std::cout << "��     ��" << std::endl;
	std::cout << "���� ��ȣ :(�̸� �ƴ�)" << std::endl;
	std::cin >> temp_number;
	while(1){
		try {
			std::cout << "�Ա� �ݾ� :" << std::endl;
			std::cin >> temp_money;
			if (temp_money < 0) {
				DepositException dex(temp_money);
				throw dex;
			}
			else
				break;
		}
		catch (DepositException &dexpr) {
			dexpr.What();
		}
	}
	//���¸� ã�� ����
	for (int i = 0; i < numberOfguest; i++)
	{
		if (acc_arr[i]->GetNumber()== temp_number)
		{
			acc_arr[i]->Deposit(temp_money);
			std::cout << "�Ա� �Ϸ�" << std::endl;
			break;
		}
	}
}
void AccountHandler::WithdrawMoney() throw (WithdrawException)
{
	int temp_number;
	int i;
	double temp_money;
	double default_balance;
	std::cout << "��     ��" << std::endl;
	std::cout << "���� ID :" << std::endl;
	std::cin >> temp_number;
	for (i = 0; i < numberOfguest; i++)
	{
		if (acc_arr[i]->GetNumber() == temp_number)
		{
			default_balance = acc_arr[i]->GetBalance();
			break;
		}
	}
	while (1) {
		try {
			std::cout << "��� �� :" << std::endl;
			std::cin >> temp_money;
			if (temp_money > default_balance) {
				throw WithdrawException(temp_money);
			}
			else {
				break;
			}
		}
		catch (AccountException &wexpr) {
			wexpr.What();
		}
	}
	acc_arr[numberOfguest-1]->Withdraw(temp_money);
	std::cout << "��� �Ϸ�" << std::endl;
}
void AccountHandler::Display() const
{
	for (int i = 0; i < numberOfguest; i++)
	{
		acc_arr[i]->ShowAllInfo();
		std::cout << std::endl;
	}
}
void AccountHandler::CreateAccount() {
	int number, balance, type, grade;
	char name[LEN_NAME];
	float interest;
	
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
		//account[numberOfguest++] = new Account(number, name, balance);
		acc_arr[numberOfguest++] = new Account(number, name, balance);
		break;
	case ACCOUNT_TYPE::NORMAL :
		std::cout << "������";
		std::cin >> interest;
		acc_arr[numberOfguest++] = new NormalAccount(number, name, balance, interest);
		break;
	case ACCOUNT_TYPE::HIGHCREDIT :
		std::cout << "������ : ";
		std::cin >> interest;
		std::cout << "�ſ��� : ";
		std::cin >> grade;
		acc_arr[numberOfguest++] = new HightCreditAccount(number, name, balance, interest,grade);
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
		delete acc_arr[i];
	}
}