#include "dec.h"//함수 또는 변수정의

int AccountHandler::numberOfguest = -1;

void AccountHandler::DepositAccount()
{
	int temp_number;
	double temp_money;
	std::cout << "입     금" << std::endl;
	std::cout << "계좌 번호 :(이름 아님)" << std::endl;
	std::cin >> temp_number;
	std::cout << "입금 금액 :" << std::endl;
	std::cin >> temp_money;
	//계좌를 찾고 넣자
	for (int i = 0; i <= numberOfguest; i++)
	{
		if (account[i]->GetNumber()== temp_number)
		{
			account[i]->SetBalance(DEPOSIT, temp_money);
			std::cout << "입금 완료" << std::endl;
			break;
		}
	}
}
void AccountHandler::WithdrawMoney()
{
	int temp_number;
	double temp_money;
	std::cout << "입     금" << std::endl;
	std::cout << "계좌 ID :" << std::endl;
	std::cin >> temp_number;
	std::cout << "출금 액 :" << std::endl;
	std::cin >> temp_money;
	for (int i = 0; i <= numberOfguest; i++)
	{
		if (account[i]->GetNumber() == temp_number)
		{
			account[i]->SetBalance(WITHDRAW, temp_money);
			std::cout << "출금 완료" << std::endl;
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
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입    금" << std::endl;
	std::cout << "3. 출    금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}
AccountHandler::~AccountHandler() {
	for (int i = 0; i < AccountHandler::numberOfguest; i++) {
		delete[i]account;
	}
}