#include "dec.h"//함수 또는 변수정의

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
	std::cout << "입     금" << std::endl;
	std::cout << "계좌 ID :" << std::endl;
	std::cin >> temp_number;
	std::cout << "입금 액 :" << std::endl;
	std::cin >> temp_money;
	//계좌를 찾고 넣자
	for (int i = 0; i <= numberOfguest; i++)
	{
		if (account[i].number == temp_number)
		{
			account[i].left += temp_money;
			break;
		}
	}
	account[temp_number].balance += temp_money;
	std::cout << "입금 완료" << std::endl;
}
void WithdrawMoney()
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
		if (account[i].number == temp_number)
		{
			account[i].left -= temp_money;
			break;
		}
	}
	std::cout << "출금 완료" << std::endl;
}
void Display()
{
	for (int i = 0; i <= numberOfguest; i++)
	{
		std::cout << "이름 :" << account[i].name << std::endl;
		std::cout << "계좌 번호 :" << account[i].number << std::endl;
		std::cout << "잔액 :" << guest[i].left << std::endl;
		std::cout << std::endl;
	}
}
void ShowMenu()
{
	std::cout << "-----MENU-----" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입    금" << std::endl;
	std::cout << "3. 출    금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}
/*
고객 계좌정보 구조체 정보
typedef struct guest_info{
	int number;
	char name[20];
	int left;
}guest_info;
*/